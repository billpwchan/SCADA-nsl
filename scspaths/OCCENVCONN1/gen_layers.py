import sys, math
import re

eqtypeDico = { 'DO': 'secSymbol', 'CA': 'camSymbol', 'FD' : 'fireSymbol', 'SP': 'sprinklerSymbol', 'ID': 'motionSymbol' }

def LayerHeader(fout, isGeo, layername):
    fout.write('<?xml version="1.0" encoding="UTF-8"?>\n')
    fout.write('<p:layerConfiguration xmlns:p="http://www.thalesgroup.com/hv/mwt/conf/situationview/layer"\n')
    fout.write('                      xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"\n')
    fout.write('                      xsi:schemaLocation="http://www.thalesgroup.com/hv/mwt/conf/situationview/layer mwt-situationview-layer-config.xsd ">\n')
    fout.write('\n')
    fout.write('    <p:' )
    if isGeo == 1:
        fout.write('geoLayer')
    else:
        fout.write('nonGeoLayer')
    fout.write(' id="' + layername + '">\n')

def LayerFooter(fout, isGeo):
    fout.write('    </p:')
    if isGeo == 1:
        fout.write('geoLayer')
    else:
        fout.write('nonGeoLayer')
    fout.write('>\n')
    fout.write('</p:layerConfiguration>\n')

def LayerBody(fout, isGeo, eqplist):
    for eptype in eqplist:
        for bid in range(1, 11):
            bldid = "%02d" % (bid)
            for i in range(1, 21):
                name = eptype + bldid + "%03d" % (i)
                fout.write('        <p:entityLayerEntry id="' + name +'" symbolId="' + eqtypeDico[eptype] + '"  />\n')               
                

def writeLayer(layername, isGeo, eqplist):
    layerfile = open(layername + ".xml",'w')
    LayerHeader(layerfile, isGeo, layername)
    LayerBody(layerfile, isGeo, eqplist)
    LayerFooter(layerfile, isGeo)
    layerfile.close()

writeLayer("geo_velizy_cctv_layer", 1, ['CA'])
writeLayer("geo_velizy_fire_layer", 1, ['FD', 'SP'])
writeLayer("geo_velizy_access_layer", 1, ['DO', 'ID'])
