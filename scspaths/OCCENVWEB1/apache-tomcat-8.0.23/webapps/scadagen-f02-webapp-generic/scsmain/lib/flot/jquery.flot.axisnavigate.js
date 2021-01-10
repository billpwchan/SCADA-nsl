/* =============================================================================
 THALES COMMUNICATIONS & SECURITY

 Copyright (c) THALES 2015 All rights reserved.
 This file and the information it contains are property of THALES COMMUNICATIONS &
 SECURITY and confidential. They shall not be reproduced nor disclosed to any
 person except to those having a need to know them without prior written
 consent of COMMUNICATIONS & SECURITY .
*/
/**
 * Plugin based on axisLabels plugin. Plugin need jquery.flot.navigate.js
 * 
 * The plugin supports these options:
 * 
 *      axisNavigate: { 
 *          enable: false, 
 *          backgroundColor: "#f00", 
 *          opacity: 0.125
 *      }
 */
(function ($) {
    // default plugin options
    var options = { 
        axisNavigate : {
            enable : false,
            backgroundColor : "#f00",
            opacity : 0.125
        }
    };

    function init(plot) {
        plot.hooks.processOptions.push(function (plot, options) {

            if (!options.axisNavigate.enable) {
                return;
            }

            var initialized = false;

            // Check which wheel event is supported. Don't use both as it would fire each event 
            // in browsers where both events are supported.
            var wheelEvent = isEventSupported('mousewheel') ? 'mousewheel' : 'wheel';

            // This is kind of a hack. There are no hooks in Flot between
            // the creation and measuring of the ticks (setTicks, measureTickLabels
            // in setupGrid() ) and the drawing of the ticks and plot box
            // (insertAxisLabels in setupGrid() ).
            //
            // Therefore, we use a trick where we run the draw routine twice:
            // the first time to get the tick measurements, so that we can change
            // them, and then have it draw it again.
            var secondPass = false;

            plot.hooks.draw.push(function (plot, ctx) {

                if(initialized)
                    return;

                var hasAxisLabels = false;
                if (!secondPass) {
                    // MEASURE AND SET OPTIONS
                    $.each(plot.getAxes(), function (axisName, axis) {
                        var opts = axis.options // Flot 0.7
                            || plot.getOptions()[axisName]; // Flot 0.6

                        if (!opts || !axis.show)
                            return;

                        hasAxisLabels = true;
                     });

                    // If there are axis labels, re-draw with new label widths and heights.
                    if (hasAxisLabels) {
                        secondPass = true;
                        plot.setupGrid();
                        plot.draw();
                    }
                } else {
                    secondPass = false;

                    // DRAW
                    $.each(plot.getAxes(), function (axisName, axis) {
                        var opts = axis.options // Flot 0.7
                            || plot.getOptions()[axisName]; // Flot 0.6
                        if (!opts || !axis.show)
                            return;

                        var box = axis.box;
                        $("<div id='target" + axisName + "' class='axisTarget' style='position:absolute; left:"
                                + box.left + "px; top:" + box.top + "px; width:" + box.width + "px; height:" + box.height + "px'></div>")
                                .data("axis.direction", axis.direction)
                                .data("axis.n", axis.n)
                                .css({
                                    backgroundColor : options.axisNavigate.backgroundColor,
                                    opacity : 0,
                                    cursor : "pointer"
                                })
                                .appendTo(plot.getPlaceholder())
                                .hover(
                                    function () { $("#target" + axisName).css({ opacity : options.axisNavigate.opacity })},
                                    function () { $("#target" + axisName).css({ opacity : 0 })})
                                .mousedown(function (e) { onDragStart(e); })
                                .drag(function (e) { onDrag(e); })
                                .mouseup(function (e) { onDragEnd(e); })
                                .on(wheelEvent, function (e) {
                                    var oEvent = e.originalEvent;
                                    var delta = oEvent.deltaY || oEvent.wheelDelta;
                                    onMouseWheel(e,delta);
                                });
                        initialized = true;
                    });
                }
            });
        });

        var prevCursor;
        var prevPageX = 0, prevPageY = 0;
        var panTimeout = null;

        function onDrag(e) {
            var frameRate = plot.getOptions().pan.frameRate;
            if (panTimeout || !frameRate)
                return;

            var l,t;
            if(e.target.id.indexOf("targety")===0) {
                l = 0;
                t = prevPageY - e.pageY;
            }
            else if (e.target.id.indexOf("targetx") === 0) {
                l = prevPageX - e.pageX;
                t = 0;
            }

            panTimeout = setTimeout(function () {
                plot.pan({ left: l, top: t });
                prevPageX = e.pageX;
                prevPageY = e.pageY;

                panTimeout = null;
            }, 1 / frameRate * 1000);
        }

        function onDragStart(e) {
            if (e.which != 1)  // only accept left-click
                return false;
            var c = plot.getPlaceholder().css('cursor');
            if (c)
                prevCursor = c;

            plot.getPlaceholder().css('cursor', plot.getOptions().pan.cursor);
            prevPageX = e.pageX;
            prevPageY = e.pageY;
        }

        function onDragEnd(e) {
            if (panTimeout) {
                clearTimeout(panTimeout);
                panTimeout = null;
            }
            

            var l, t;
            if (e.target.id.indexOf("targety") === 0) {
                l = 0;
                t = prevPageY - e.pageY;
            } else if (e.target.id.indexOf("targetx") === 0) {
                l = prevPageX - e.pageX;
                t = 0;
            }

            plot.getPlaceholder().css('cursor', prevCursor);
            plot.pan({ left: l, top: t });
        }
 
        var prevZoomRange = null;
        function onZoomClick(e, zoomOut) {
            var c = plot.offset();
            c.left = e.pageX - c.left;
            c.top = e.pageY - c.top;

            if (e.target.id.indexOf("targety") === 0) {
                for (var i = 0; i < plot.getXAxes().length; i++) {
                    prevZoomRange = plot.getXAxes()[i].options.zoomRange;
                    plot.getXAxes()[i].options.zoomRange = false;
                }
            } else if (e.target.id.indexOf("targetx") === 0) {
                for (var i = 0; i < plot.getYAxes().length; i++) {
                    prevZoomRange = plot.getYAxes()[i].options.zoomRange;
                    plot.getYAxes()[i].options.zoomRange = false;
                }
            }

            if (zoomOut)
                plot.zoomOut({ center: c });
            else
                plot.zoom({ center: c });

            if (e.target.id.indexOf("targety") === 0) {
                for (var i = 0; i < plot.getXAxes().length; i++)
                    plot.getXAxes()[i].options.zoomRange = prevZoomRange;
            } else if (e.target.id.indexOf("targetx") === 0) {
                for (var i = 0; i < plot.getYAxes().length; i++)
                    plot.getYAxes()[i].options.zoomRange = prevZoomRange;
            }
        }

        function onMouseWheel(e, delta) {
            e.preventDefault();
            onZoomClick(e, delta < 0);
            return false;
        }

        // This function checks if the specified event is supported by the browser.
        // Source: http://perfectionkills.com/detecting-event-support-without-browser-sniffing
        function isEventSupported(eventName) {
            var el = document.createElement('div');
            eventName = 'on' + eventName;
            var isSupported = (eventName in el);
            if (!isSupported) {
                el.setAttribute(eventName, 'return;');
                isSupported = typeof el[eventName] == 'function';
            }
            el = null;
            return isSupported;
        }
    }

    $.plot.plugins.push({
        init: init,
        options: options,
        name: 'axisNavigate',
        version: '0.1'
    });
})(jQuery);
