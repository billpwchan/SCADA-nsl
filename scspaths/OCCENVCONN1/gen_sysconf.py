import sys, math
import re

baList = {'OCCENVCONN': ['01', '02', '03', '04', '05'], 'SCADA2' : ['06', '07', '08', '09', '10']}
eqtypeDico = { 'DO': 'DoorType', 'CA': 'CamType', 'FD' : 'FireDetType', 'SP': 'SprinklerType', 'ID': 'MotionDetType' }
eqtypeGroup = { 'DO': 'ACCESS', 'CA': 'CCTV', 'FD' : 'FIRE', 'SP': 'FIRE', 'ID': 'ACCESS' }
eqtypeLabelDico = { 'DO': 'Door', 'CA': 'Camera', 'FD' : 'Smoke Det', 'SP': 'Sprinkler', 'ID': 'Motion Det' }
buildingList = { 'building1' : '01', }
# entitiesPerSubsystemAllocation.xml

def EPASHeader(fout):
    fout.write('<?xml version="1.0" encoding="UTF-8"?>\n')
    fout.write('<p:configuration \n')
    fout.write('xmlns:p="http://www.thalesgroup.com/hv/data-v1/system/configuration" \n')
    fout.write('xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" \n')
    fout.write('xsi:schemaLocation="http://www.thalesgroup.com/hv/data-v1/system/configuration hypervisor_system_configuration.xsd ">\n')
    fout.write('\n')
    fout.write('    <p:mapping runtimeMode="OPERATIONAL" xsi:type="p:idToIdMapType">\n')

def EPSBody(fout):
    
    for ba in baList.keys():
        fout.write('        <p:entry key="' + ba + '" role="DEFAULT" xsi:type="p:idToIdEntryType">\n')
        for bid in baList[ba]:
            for eptype in eqtypeDico.keys():
                for i in range(1, 101):
                    fout.write('            <p:value>' + eptype + bid + "%03d" % (i) + '</p:value>\n')
        
        fout.write('        </p:entry>\n')


def EPASFooter(fout):
    fout.write('    </p:mapping>\n')
    fout.write('</p:configuration>\n')

def writeEPS(filename):
    epsfile = open(filename,'w')
    EPASHeader(epsfile)
    EPSBody(epsfile)
    EPASFooter(epsfile)
    epsfile.close()

# entitiesPerAreaAllocation.xml

def EPABody(fout):

    for bid in range(1, 11):
        bname = "building%d" % (bid)
        bldid = "%02d" % (bid)
        fout.write('        <p:entry key="' + bname + '" role="DEFAULT" xsi:type="p:idToIdEntryType">\n')
        for eptype in eqtypeDico.keys():
            for i in range(1, 101):
                fout.write('            <p:value>' + eptype + bldid + "%03d" % (i) + '</p:value>\n')
        
        fout.write('        </p:entry>\n')


    
def writeEPA(filename):
    epafile = open(filename,'w')
    EPASHeader(epafile)
    EPABody(epafile)
    EPASFooter(epafile)
    epafile.close()

# equipments.xml
def EQPHeader(fout):
    # fout.write('<?xml version="1.0" encoding="UTF-8"?>\n')
    # fout.write('<!-- Definition of all the equipments defined in the system -->\n')
    # fout.write('<hv-conf:entitiesConfiguration  \n')
    # fout.write('  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"\n')
    # fout.write('  xmlns:hv-conf="http://www.thalesgroup.com/hv/data-v1/entity/configuration"\n')
    # fout.write('  xmlns:scs-eqpt="http://www.thalesgroup.com/scadasoft/sample/data/equipment/configuration"\n')
    # fout.write('\n')
    fout.write('ELEMENT_NAME;ID;hvx;hvy\n')

def EQPBody(fout):
    gpsxorig = 2.20
    gpsyorig = 48.78617
    gpsxdelta = 0.001
    gpsydelta = 0.001
    nbPerLine = 225
    
    index = 0
    for eptype in eqtypeDico.keys():
        for bid in range(1, 11):
            bldid = "%02d" % (bid)
            gpsx = gpsxorig + (index % nbPerLine) * gpsxdelta
            gpsy = gpsyorig + (index / nbPerLine) * gpsydelta
            index = index + 1
            fout.write(";:R:A:SITE1:B%03d;%f;%f\n" % (bid, gpsx, gpsy))
            
            gpsx = gpsxorig + (index % nbPerLine) * gpsxdelta
            gpsy = gpsyorig + (index / nbPerLine) * gpsydelta
            index = index + 1
            fout.write(";:R:A:SITE1:B%03d:F000;%f;%f\n" % (bid, gpsx, gpsy))
                
            gpsx = gpsxorig + (index % nbPerLine) * gpsxdelta
            gpsy = gpsyorig + (index / nbPerLine) * gpsydelta
            index = index + 1
            fout.write(";:R:A:SITE1:B%03d:F000:SYSTEM:RT%03d;%f;%f\n" % (bid, bid, gpsx, gpsy))
            
            gpsx = gpsxorig + (index % nbPerLine) * gpsxdelta
            gpsy = gpsyorig + (index / nbPerLine) * gpsydelta
            index = index + 1
            fout.write(";:R:A:SITE1:B%03d:F000:SYSTEM:RT%02dA;%f;%f\n" % (bid, bid, gpsx, gpsy))
            gpsx = gpsxorig + (index % nbPerLine) * gpsxdelta
            gpsy = gpsyorig + (index / nbPerLine) * gpsydelta
            index = index + 1
            fout.write(";:R:A:SITE1:B%03d:F000:SYSTEM:RT%02dB;%f;%f\n" % (bid, bid, gpsx, gpsy))
            
            eqpnum = 1
            
            for fid in range(1, 11):
                gpsx = gpsxorig + (index % nbPerLine) * gpsxdelta
                gpsy = gpsyorig + (index / nbPerLine) * gpsydelta
                index = index + 1
                fout.write(";:R:A:SITE1:B%03d:F%03d;%f;%f\n" % (bid, fid, gpsx, gpsy))
                
                for i in range(1, 11):
                    gpsx = gpsxorig + (index % nbPerLine) * gpsxdelta
                    gpsy = gpsyorig + (index / nbPerLine) * gpsydelta
                    index = index + 1
                    fout.write(";:R:A:SITE1:B%03d:F%03d:ACCESS:DO%03d;%f;%f\n" % (bid, fid, eqpnum, gpsx, gpsy))
                    
                    gpsx = gpsxorig + (index % nbPerLine) * gpsxdelta
                    gpsy = gpsyorig + (index / nbPerLine) * gpsydelta
                    index = index + 1
                    fout.write(";:R:A:SITE1:B%03d:F%03d:ACCESS:ID%03d;%f;%f\n" % (bid, fid, eqpnum, gpsx, gpsy))
                    
                    gpsx = gpsxorig + (index % nbPerLine) * gpsxdelta
                    gpsy = gpsyorig + (index / nbPerLine) * gpsydelta
                    index = index + 1
                    fout.write(";:R:A:SITE1:B%03d:F%03d:CCTV:CA%03d;%f;%f\n" % (bid, fid, eqpnum, gpsx, gpsy))
                    
                    gpsx = gpsxorig + (index % nbPerLine) * gpsxdelta
                    gpsy = gpsyorig + (index / nbPerLine) * gpsydelta
                    index = index + 1
                    fout.write(";:R:A:SITE1:B%03d:F%03d:FIRE:FD%03d;%f;%f\n" % (bid, fid, eqpnum, gpsx, gpsy))
                    
                    gpsx = gpsxorig + (index % nbPerLine) * gpsxdelta
                    gpsy = gpsyorig + (index / nbPerLine) * gpsydelta
                    index = index + 1
                    fout.write(";:R:A:SITE1:B%03d:F%03d:FIRE:SP%03d;%f;%f\n" % (bid, fid, eqpnum, gpsx, gpsy))
                    eqpnum = eqpnum + 1
                    

def EQPFooter(fout):
    pass
    # fout.write('</hv-conf:entitiesConfiguration>\n')

def writeEqpInst(filename):
    epqfile = open(filename,'w')
    EQPHeader(epqfile)
    EQPBody(epqfile)
    EQPFooter(epqfile)
    epqfile.close()

    
# <instance hv="SP01001" scs=":SITE1:B001:F001:FIRE:SP001"/>
def writeMapping(filename):
    mapfile = open(filename,'w')

    for eptype in eqtypeDico.keys():
        for bid in range(1, 6):
            bldid = "%02d" % (bid)
            for i in range(1, 101):
                fid = ((i-1) / 10) + 1
                shortname = eptype + bldid + "%03d" % (i)
                name = ":SITE1:B%03d:F%03d:%s:%s%03d" % (bid, fid, eqtypeGroup[eptype], eptype, i)
                mapfile.write('<instance hv="' + shortname + '" scs="' + name + '"/>\n')
                
    mapfile.close()
                
# gen dictionary entry
#
# entityName_DO01001: Door 01 001
# alarmListBanner_eqptId_DO01001: Door 01 001
# scsalarmList_eqptId_DO01001: Door 01 001
# scseventList_eqptId_DO01001: Door 01 001
# 
# From SCSADDRESS  generate  shortname for HV id  (DO01002)
#                  generate for dico EqpTypeName EqpNumber (Door 01002)
def writeHMIDico(filename):
    dicofile = open(filename,'w')

    for eptype in eqtypeDico.keys():
        for bid in range(1, 11):
            bldid = "%02d" % (bid)
            for i in range(1, 101):
                fid = ((i-1) / 10) + 1
                shortname = eptype + bldid + "%03d" % (i)
                label = "%s B%d %d" % (eqtypeLabelDico[eptype], bid, i)
                dicofile.write('entityName_' + shortname + ': ' + label + '\n')
                dicofile.write('alarmListBanner_sourceID_' + shortname + ': ' + label + '\n')
                dicofile.write('scsalarmList_sourceID_' + shortname + ': ' + label + '\n')
                dicofile.write('scseventList_sourceID_' + shortname + ': ' + label + '\n')
                
    dicofile.close()
           
#writeEPS("entitiesPerSubsystemAllocation.xml")
#writeEPA("entitiesPerAreaAllocation.xml")
writeEqpInst("eqp_pos.csv")
# writeMapping("4scs2hv.txt")
# writeHMIDico("4dico.txt")