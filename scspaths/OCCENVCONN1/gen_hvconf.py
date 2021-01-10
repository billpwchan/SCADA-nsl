import sys, math
import re

# gen line for scs2hv.xml
# <instance hv="door_3052" scs=":SITE1:B001:F001:ACCESS:DO002"/>
#
# gen dictionary entry
#
# entityName_door_3051: Door 3051
# alarmListBanner_eqptId_door_3051: Door 3051
# scsalarmList_eqptId_door_3051: Door 3051
# scseventList_eqptId_door_3051: Door 3051
# 
# From SCSADDRESS  generate  shortname for HV id  (DO01002) B01DO001
#                  generate for dico EqpTypeName EqpNumber (Door 01002)

def genShortname(building, eqpid):
    eqtype = eqpid[0:2]
    bid = building[2:4]
    eqnum = eqpid[2:]
    return 'B' + bid + eqtype + eqnum

eqtypeDico = { 'DO': 'Door', 'CA': 'Camera', 'FD' : 'Smoke Detector', 'SP': 'Sprinkler', 'ID': 'Motion Detector' }

def genDiconame(building, eqpid):
    eqtype = eqpid[0:2]
    bid = building[2:4]
    eqnum = eqpid[2:]
    
    et = eqtypeDico.get(eqtype, None)
    if et == None:
        return None
        
    return eqtypeDico.get(eqtype, '--------------------Eqp---------------------') + ' B' + bid + ' ' + eqnum

def genEntry(scspath):
    l = scspath.split(':')
    if len(l) == 6:
        return (l[2], l[5])
        
    return (None, None)

def genSCS2HVFileData(fout, scsid, hvid, diconame):
    fout.write('<instance hv="' + hvid + '" scs="' + scsid + '"/>\n')
    
def genDicoFileData(fout, scsid, hvid, diconame):
    if diconame != None:
        fout.write(hvid + ': ' + diconame + '\n')
        fout.write('entityName_' + hvid + ': ' + diconame + '\n')
        # fout.write('alarmListBanner_eqptId_' + hvid + ': ' + diconame + '\n')
        # fout.write('scsalarmList_eqptId_' + hvid + ': ' + diconame + '\n')
        # fout.write('scseventList_eqptId_' + hvid + ': ' + diconame + '\n')
 
def readSCSInstanceFile(filename):
    # fscs2hv = open("4scs2hv.txt",'w')
    fdico = open("4dico.txt",'w')
    
    with open(filename) as f:
        for line in f:
            # each line is :SITE1:B001:F001:ACCESS:DO010
            
            s = re.search(":[:a-zA-Z0-9]+",line.strip())
            if s != None:
                scsid = s.group()
                print scsid
                (b, e) = genEntry(scsid)
                if b != None and e != None:
                    shortname = genShortname(b, e)
                    diconame = genDiconame(b, e)
                    # genSCS2HVFileData(fscs2hv, scsid, shortname, diconame)
                    genDicoFileData(fdico, scsid, shortname, diconame)

# readSCSInstanceFile("id.txt")
readSCSInstanceFile("scs2hv.xml")