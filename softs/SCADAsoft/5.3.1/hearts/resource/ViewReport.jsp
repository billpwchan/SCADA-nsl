<%--
  ~ Copyright (C) 2005 - 2011 Jaspersoft Corporation. All rights reserved.
  ~ http://www.jaspersoft.com.
  ~
  ~ Unless you have purchased  a commercial license agreement from Jaspersoft,
  ~ the following license terms  apply:
  ~
  ~ This program is free software: you can redistribute it and/or  modify
  ~ it under the terms of the GNU Affero General Public License  as
  ~ published by the Free Software Foundation, either version 3 of  the
  ~ License, or (at your option) any later version.
  ~
  ~ This program is distributed in the hope that it will be useful,
  ~ but WITHOUT ANY WARRANTY; without even the implied warranty of
  ~ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  ~ GNU Affero  General Public License for more details.
  ~
  ~ You should have received a copy of the GNU Affero General Public  License
  ~ along with this program. If not, see <http://www.gnu.org/licenses/>.
  --%>

<%@ taglib prefix="t" uri="http://tiles.apache.org/tags-tiles" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core_rt" %>
<%@ taglib prefix="spring" uri="http://www.springframework.org/tags" %>
<%@ taglib prefix="js" uri="/WEB-INF/jasperserver.tld" %>


<c:choose>
    <c:when test="${reportControlsLayout == 1 or (reportControlsLayout == 2 and not needsInput)}">
        <c:set var="bodyClass" value="oneColumn"/>
    </c:when>
    <c:when test="${reportControlsLayout == 2 and needsInput}">
        <c:set var="bodyClass" value="controlPage"/>
        <%--<c:set var="bodyClass" value="twoColumn"/>--%>
    </c:when>
    <c:when test="${reportControlsLayout == 3 or reportControlsLayout == 4}">
        <c:set var="bodyClass" value="twoColumn"/>
    </c:when>
</c:choose>



<t:insertTemplate template="/WEB-INF/jsp/modules/templates/page.jsp">
    <t:putAttribute name="pageTitle" value="${reportUnitObject.label}"/>
    <t:putAttribute name="bodyID" value="reportViewer"/>
    <t:putAttribute name="bodyClass" value="${bodyClass}"/>
    <%--<t:putAttribute name="pageClass" value="${bodyClass}"/>--%>
    <t:putAttribute name="headerContent">
        <script type="text/javascript" language="JavaScript" src="${pageContext.request.contextPath}/scripts/utils.cookie.js"></script>
        <script type="text/javascript" language="JavaScript" src="${pageContext.request.contextPath}/scripts/controls.base.js"></script>
        <script type="text/javascript" language="JavaScript" src="${pageContext.request.contextPath}/scripts/controls.report.js"></script>
        <script type="text/javascript" language="JavaScript" src="${pageContext.request.contextPath}/scripts/report.view.base.js"></script>
        <script type="text/javascript" language="JavaScript" src="${pageContext.request.contextPath}/scripts/report.view.runtime.js"></script>
        <script type="text/javascript" language="JavaScript" src="${pageContext.request.contextPath}/scripts/cascade.cascade.js"></script>
        <script type="text/javascript" language="JavaScript" src="${pageContext.request.contextPath}/dwr/interface/RemoteCascadeDirector.js"> </script>
        <script type="text/javascript" language="JavaScript" src="${pageContext.request.contextPath}/dwr/engine.js"> </script>
        <script type="text/javascript" language="JavaScript" src="${pageContext.request.contextPath}/dwr/util.js"> </script>
        <%@ include file="ViewReportState.jsp" %>
    </t:putAttribute>

    <t:putAttribute name="bodyContent" >

        <t:insertTemplate template="/WEB-INF/jsp/modules/templates/container.jsp">
            <t:putAttribute name="containerClass" value="column decorated primary showingToolBar"/>
            <t:putAttribute name="containerTitle"><spring:message code="report.view.containerTitle"/></t:putAttribute>

            <!-- ========== TOOLBAR =========== -->
            <t:putAttribute name="headerContent">
                <div class="toolbar">
                    <ul class="list buttonSet">
                        <li class="leaf"><button id="back" class="button capsule up first"><span class="wrap"><spring:message code="button.back"/><span class="icon"></span></span></button></li>
                        <li id="controls" class="leaf ${hasInputControls and (reportControlsLayout == 1 or reportControlsLayout == 2)? "" : "hidden"}"><button id="ICDialog" class="button capsule up middle"><span class="wrap"><spring:message code="button.controls"/><span class="icon"></span></span></button></li>
                        <li class="leaf"><button id="export" class="button capsule mutton up last" disabled="disabled"><span class="wrap"><spring:message code="button.export"/><span class="icon"></span><span class="indicator"></span></span></button></li>
                    </ul>
                </div>

            </t:putAttribute>


            <!-- ========== REPORT CONTAINER =========== -->
            <t:putAttribute name="bodyContent">

                <t:insertTemplate template="/WEB-INF/jsp/modules/templates/#nothingToDisplay.jsp">
                    <t:putAttribute name="bodyContent">
                        <p class="message"><spring:message code="report.view.needInput.warning"/></p>
                    </t:putAttribute>
                </t:insertTemplate>

                <t:insertTemplate template="/WEB-INF/jsp/modules/templates/#nothingToDisplay.jsp">
                    <t:putAttribute name="containerID" value="emptyReportID" />
                    <t:putAttribute name="bodyContent">
                        <p class="message"><b>${reportUnitObject.label}</b></p>
                        <p class="message"><spring:message code="jasper.report.view.empty"/></p>
                    </t:putAttribute>
                </t:insertTemplate>
                
                <center>
                    <div id="reportContainer">&nbsp;</div>
                </center>
            </t:putAttribute>
            
            <!-- ========== PAGINATION =========== -->
            <t:putAttribute name="footerContent">
                <div class="control paging centered_horz" id="pagination">
                    <button id="page_first" type="submit" class="button action square move toLeft up" disabled="disabled"><span class="wrap"><span class="icon"></span></span></button>
                    <button id="page_prev" type="submit" class="button action square move left up" disabled="disabled"><span class="wrap"><span class="icon"></span></span></button>
                    <label class="control input text inline" for="page_current" title="current page">
                        <span class="wrap"><spring:message code="jasper.report.view.page.intro"/></span>
                        <input class="" id="page_current" type="text" name="currentPage" value=""/>
                        <span class="wrap" id="page_total">&nbsp;</span>
                    </label>
                    <button id="page_next" type="submit" class="button action square move right up" disabled="disabled"><span class="wrap"><span class="icon"></span></span></button>
                    <button id="page_last" type="submit" class="button action square move toRight up" disabled="disabled"><span class="wrap"><span class="icon"></span></span></button>
                </div>
                <div id="checkErrorsRow" class="">
                    <span class="message warning"><spring:message code="jasper.report.view.error.invalid.pagenumber"/></span>
                </div>
            </t:putAttribute>
        </t:insertTemplate>


    <!-- ========== INPUT CONTROLS ON-PAGE FORM =========== -->
    <c:if test="${hasInputControls and reportControlsLayout != 1}">
        <form class="column secondary decorated sizeable <c:if test="${not empty requestScope.reportOptionsList}">showingSubHeader</c:if>" id="inputControlsForm"  action="<c:url value="flow.html"/>" method="post" role="navigation">
            <div class="sizer horizontal"></div>
            <button class="button minimize" type="button"></button>
            <t:insertTemplate template="/WEB-INF/jsp/modules/templates/utility_cosmetic.jsp"/>
            <div class="content">
                <div class="header ">
                    <div class="title"><h1><spring:message code="button.controls"/></h1></div>
                    <c:if test="${isPro}">
                        <div class="sub header ${not empty requestScope.reportOptionsList ? '' : 'hidden'}">
                            <label id="savedValuesSelector" class="control select inline" for="savedValues" title="Select saved values">
                                <span class="wrap"><spring:message code="report.options.select.label"/></span>
                                <select id="savedValues"  name="reportOptionsURI">
                                    <option selected="selected" value=""><spring:message code="report.options.select.empty.label"/></option>
                                    <c:forEach items="${requestScope.reportOptionsList}" var="option">
                                    <option value="${option.URIString}"
                                        <c:if test="${option.URIString == requestScope.reportOptionsURI}">selected="selected"</c:if>>
                                        <c:out value="${option.label}"/>
                                    </option>
                                    </c:forEach>
                                </select>
                            </label>
                        </div>
                    </c:if>
                </div>

                <div class="body ">

                  
                    <ul class="list inputControls" id="inputControlsContainer">
                        <js:parametersForm reportName="${requestScope.reportUnit}" renderJsp="${controlsDisplayForm}" />
                    </ul>
                </div>
                <div class="footer ">
                    <button id="apply" class="button action primary up"><span class="wrap"><spring:message code="button.apply" javaScriptEscape="true"/><span class="icon"></span></span></button>
                    <button id="reset" class="button action up"><span class="wrap"><spring:message code="button.reset" javaScriptEscape="true"/><span class="icon"></span></button>
                    <c:if test="${reportControlsLayout == 2}">
                      <button id="cancel" class="button action up"><span class="wrap"><spring:message code="button.cancel" javaScriptEscape="true"/><span class="icon"></span></span></button>
                    </c:if>
                    <c:if test="${isPro}">
                        <button id="save" class="button action up"><span class="wrap"><spring:message code="button.save" javaScriptEscape="true"/><span class="icon"></span></span></button>
                    </c:if>
                </div>
            </div>
        </form>
    </c:if>

        <!-- ========== INPUT CONTROLS DIALOG =========== -->
        <c:if test="${hasInputControls and reportControlsLayout == 1}">
            <t:insertTemplate template="/WEB-INF/jsp/modules/templates/#inputControls.jsp">
                <t:putAttribute name="containerTitle"><spring:message code="button.controls"/></t:putAttribute>
                <t:putAttribute name="containerClass" value="sizeable hidden ${not empty requestScope.reportOptionsList ? 'showingSubHeader' : ''}"/>
                <t:putAttribute name="hasReportOptions" value="false"/>
                <t:putAttribute name="bodyContent">
                    <ul class="list inputControls">
                        <form class="" id="inputControlsForm"  action="<c:url value="flow.html"/>" method="post">
                            <js:parametersForm reportName="${requestScope.reportUnit}" renderJsp="${controlsDisplayForm}" />
                        </form>
                    </ul>
                </t:putAttribute>
            </t:insertTemplate>
        </c:if>


        <!-- ========== SAVE REPORT OPTIONS DIALOG =========== -->
        <c:if test="${isPro}">
            <t:insertTemplate template="/WEB-INF/jsp/modules/templates/#saveValues.jsp">
                <t:putAttribute name="containerClass" value="hidden"/>
            </t:insertTemplate>
        </c:if>

        <%-- This form is used for submit actions --%>
        <form id="exportActionForm" action="<c:url value="flow.html"/>" method="post">
            <input type="hidden" name="_flowExecutionKey" value=""/>
            <input type="hidden" name="_eventId" value=""/>
            <input type="hidden" name="output"/>
        </form>


    </t:putAttribute>

</t:insertTemplate>
