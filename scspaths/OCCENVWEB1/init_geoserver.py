import os, sys
import traceback
import argparse

# we need a Catalog the data_dir
from geoserver.catalog import *

# fh = logging.FileHandler('spam.log')
# fh.setLevel(logging.DEBUG)

# formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
# fh.setFormatter(formatter)

# logger.setLevel(logging.DEBUG)
# logger.addHandler(fh)

# geoserver.support.logger.setLevel(logging.DEBUG)
# geoserver.support.logger.addHandler(fh)

def mergeBBox(bbox1, bbox2):
    if bbox2 == None:
        return bbox1
        
    xmin1, xmax1, ymin1, ymax1, crs = bbox1
    
    if bbox1[4] == bbox2[4]:
        # xmin
        if bbox2[0] < xmin1:
            xmin1 = bbox2[0]
        # xmax
        if bbox2[1] > xmax1:
            xmax1 = bbox2[1]
        # ymin
        if bbox2[2] < ymin1:
            ymin1 = bbox2[2]
        # ymax
        if bbox2[3] > ymax1:
            ymax1 = bbox2[3]   
    
    return (xmin1, xmax1, ymin1, ymax1, crs)

    
    
def loadStyle(cat, styleFolder):
    # get list of style
    print "======================================================================="
    print " Checking style"
    print ""
    for path,_,files in os.walk(styleFolder):
        for fn in files:
            filename = os.path.join(path,fn).replace('\\','/')
            extension = fn[-4:]
            sldname = fn[0:-4]
            
            if extension == ".sld":
                print "   check", sldname,
                st = cat.get_style(sldname)
                if st == None:
                    print "    CREATE."
                    with open(filename) as f:
                        cat.create_style(sldname, f.read(), overwrite=True)
                else:
                    print " EXISTS."
                

def getWorkspace(cat, wksName):
    print "======================================================================="
    print " Checking workspace"
    print ""
    # get workspace
    wksList = cat.get_workspaces()

    # look for storename wks
    currentWks = None
    for wks in wksList:
        if wks.name == wksName:
            currentWks = wks
            break
            
    if currentWks == None:
        print "    ", wksName, "does not exists, create it."
        cat.create_workspace(wksName, wksName)
        currentWks = cat.get_workspace(wksName)
        cat.set_default_workspace(wksName)
    else:
        print "    ", wksName, " exists."
    print ""
    
    return currentWks

    
def getDataStore(cat, storeName, storePath, wksName, encoding="UTF-8"):
    # check if store exists
    st = None
    try:
        st = cat.get_store(storeName, workspace=wksName)
    except:
        pass
    
    print "   check", storeName,
    if st == None:
        print "    CREATE."
        dirpath = os.path.join(os.getcwd(),storePath).replace('\\','/')
        st = cat.create_datastore(storeName, workspace=wksName)
        st.type = "Directory of spatial files (shapefiles)"
        st.description = "auto import"
        st.enabled = True
        st.connection_parameters.update(
                    fstype="shape", filetype="shapefile", url="file://"+dirpath, createspatialindex ="true", charset = encoding)
        st.connection_parameters["create spatial index"] = "true" 
        st.connection_parameters["cache and reuse memory maps"] = "true" 
        cat.save(st)
        st = cat.get_store(storeName, workspace=wksName)
    else:
        print " EXISTS."
        
    return st

def publishLayer(cat, store,defStyle, natCRS):
    print "      publishing new resources"
    print ""
    aniActiveObjStyle = cat.get_style("ani_active")
    
    # get unpublished resources (available = true !!!)
    for r in store.get_resources(available=True):
        print "            publish", r,
        
        try:
            # call publish to create the feature
            _ = cat.publish_featuretype(r, store, native_crs=natCRS)
            # get layer to access sld
            layer = cat.get_layer(r)
            if defStyle != None:
                if r[-3:] == 'obj':
                    layer.default_style = aniActiveObjStyle
                else:
                    layer.default_style = defStyle
            else:
                stname = r[r.rindex('_')+1:]
                layer.default_style = cat.get_style('hyp_' + stname)
            
            print "style", layer.default_style
            
            cat.save(layer)
        except:
            traceback.print_exc()
            pass

def publishSynopticLayer(cat, store, defStyle, natCRS, prefix):
    print "      publishing new resources"
    print ""
    aniActiveObjStyle = cat.get_style("ani_active")
    
    if len(prefix) > 0:
        prefix = prefix + '_'
        
    # get unpublished resources (available = true !!!)
    for r in store.get_resources(available=True):
        print "            publish", r,
        
        try:
            # call publish to create the feature
            _ = cat.publish_featuretype(prefix + r, store, native_crs=natCRS, nativeName=r)
            # get layer to access sld and set new name
            layer = cat.get_layer(prefix + r)
            
            if defStyle != None:
                if r[-3:] == 'obj':
                    layer.default_style = aniActiveObjStyle
                else:
                    layer.default_style = defStyle
            else:
                stname = r[r.rindex('_')+1:]
                layer.default_style = cat.get_style('hyp_' + stname)
            
            print "style", layer.default_style
            
            cat.save(layer)
        except:
            traceback.print_exc()
            pass

def isShapeDir(dirname):
    for f in  os.listdir(dirname):
        if len(f) > 4 and f[-4:] == '.shp':
            return True
        
    return False

def loadSynoptic(cat, rootfolder, defStyle, encoding):
    
    for item in os.listdir(rootfolder):
        fname = os.path.join(rootfolder, item)
        if os.path.isdir(fname):
            workspace = item
            # first level dir is a workspace
            wks = getWorkspace(cat, workspace)

            loadSynopticFeatures(cat, fname, wks, '', defStyle, encoding)

def createLayerGroup(cat, st, workspace):
    print "       ======================================================================="
    print "       Checking Layer Groups"
    print ""
    layerList = st.get_resources(available=False)
    layerDic = {}
    layerGroupNameList = []
    bboxDict = {}
    for l in layerList:
        layerDic[l.name] = l
        print l.name
        if l.name[-3:] == "pll":
            layerGroupNameList.append(l.name[0:-3])
        bboxDict[l.name] = l.native_bbox
            
    for ln in layerGroupNameList:
        wkcat = Catalog(cat.service_url + "/workspaces/" + workspace)
        wkcat.username = cat.username
        wkcat.password = cat.password
        lg = wkcat.get_layergroup(ln)
        if lg == None:
            
            try:
                if ln+"plg" in layerDic:
                    print "               add layer group", ln
                    bbox1 = bboxDict[ln+"pll"]
                    bbox2 = bboxDict[ln+"plg"]
                    bbox = mergeBBox(bbox1, bbox2)
                    lg = wkcat.create_layergroup(ln, layers=[ln+"plg", ln+"pll"], bounds=bbox)
                    wkcat.save(lg)
                else:
                    print "               no polygon layer for", ln
            except:
                traceback.print_exc()
                pass
                
def loadSynopticFeatures(cat, rootfolder, wks, curname, defStyle, encoding):
    
    # load local feature
    if isShapeDir(rootfolder):
        # this is a directory that contains shapes
        st = getDataStore(cat, curname, rootfolder, wks, encoding)
        print "      ========================================================="
        print "      listing published resources"
        print ""
        print "            ",
        for r in st.get_resources(available=False):
            print r.name,
        print
        
        # we use this crs because it seems to work with metaconf
        # the real crs does not really matter because it is a synoptic
        publishSynopticLayer(cat, st, defStyle, "EPSG:23030", curname)
        # create layergroup
        createLayerGroup(cat, st, wks.name)
                                          
    # load subfolder
    if len(curname) > 0:
        curname = curname + '_'
    for item in os.listdir(rootfolder):
        fname = os.path.join(rootfolder, item)
        if os.path.isdir(fname):
            loadSynopticFeatures(cat, fname, wks, curname + item, defStyle, encoding)

def loadSynoptic2(cat, rootfolder, workspace, defStyle):
   
    # get workspace
    _ = getWorkspace(cat, workspace)
    
    # create datastore for shape directory
    print "======================================================================="
    print " Checking shape store"
    print ""
    for path,dirs,_ in os.walk(rootfolder):
        for d in dirs:
            if isShapeDir(path + "/" + d):
                sn = path[len(rootfolder)+1:] + '_' + d
                sn = sn.replace("\\", "_").replace("/", "_")
                # this is a directory that contains shapes
                st = getDataStore(cat, sn, path + "/" + d, workspace)
                
                print "      ========================================================="
                print "      listing published resources"
                print ""
                print "            ",
                for r in st.get_resources(available=False):
                    print r.name,
                print
                
                # we use this crs because it seems to work with metaconf
                # the real crs does not really matter because it is a synoptic
                
                publishLayer(cat, st, defStyle, "EPSG:23030")
                
                # create layergroup
                print "       ======================================================================="
                print "       Checking Layer Groups"
                print ""
                layerList = st.get_resources(available=False)
                layerDic = {}
                layerGroupNameList = []
                bboxDict = {}
                for l in layerList:
                    layerDic[l.name] = l
                    print l.name
                    if l.name[-3:] == "pll":
                        layerGroupNameList.append(l.name[0:-3])
                    bboxDict[l.name] = l.native_bbox
                        
                for ln in layerGroupNameList:
                    wkcat = Catalog("http://localhost:8180/geoserver/rest/workspaces/" + workspace)
                    wkcat.username = "admin"
                    wkcat.password = "geoserver"
                    lg = wkcat.get_layergroup(ln)
                    if lg == None:
                        
                        try:
                            if ln+"plg" in layerDic:
                                print "               add layer group", ln
                                bbox1 = bboxDict[ln+"pll"]
                                bbox2 = bboxDict[ln+"plg"]
                                bbox = mergeBBox(bbox1, bbox2)
                                lg = wkcat.create_layergroup(ln, layers=[ln+"plg", ln+"pll"], bounds=bbox)
                                wkcat.save(lg)
                            else:
                                print "               no polygon layer for", ln
                        except:
                            traceback.print_exc()
                            pass

def loadAutocadSynoptic(cat, rootfolder, storename):
   
    # get workspace with same name as store
    _ = getWorkspace(cat, storename)

    # create datastore for shape directory
    print "======================================================================="
    print " Checking shape store"
    print ""
    for path,dirs,_ in os.walk(rootfolder):
        for d in dirs:
            extension = d[-4:]
            if extension == ".shp":
                dirname = d[0:-4]
                # this is a directory that contains shapes
                st = getDataStore(cat, dirname, path + "/" + d, storename)

                print "      ========================================================="
                print "      listing published resources"
                print ""
                print "            ",
                for r in st.get_resources(available=False):
                    print r.name,
                print
                
                # we use this crs because it seems to work with metaconf
                # the real crs does not really matter because it is a synoptic
                publishLayer(cat, st, None, "EPSG:23030")
            
                       
def loadMap(cat, rootfolder):                       
    # create datastore for shape directory of maps
    print "======================================================================="
    print " Checking shape store"
    print ""
    for path,dirs,_ in os.walk(rootfolder):
        for d in dirs:
            extension = d[-4:]
            if extension == ".shp":
                dirname = d[0:-4]
                # this is a directory that contains shapes
                wks = cat.get_workspace(dirname)
                if wks == None:
                    wks = cat.create_workspace(dirname, dirname)
                
                # check if store exists
                st = None
                try:
                    st = cat.get_store(dirname, workspace=wks)
                except:
                    pass
                
                print "   check", dirname,
                if st == None:
                    print "    CREATE."
                    dirpath = os.path.join(os.getcwd(),path,d).replace('\\','/')
                    st = cat.create_datastore(dirname, workspace=wks)
                    st.type = "Directory of spatial files (shapefiles)"
                    st.description = "auto import"
                    st.enabled = True
                    st.connection_parameters.update(
                                fstype="shape", filetype="shapefile", url="file://"+dirpath, charset ="UTF-8")
                    st.connection_parameters["create spatial index"] = "true" 
                    st.connection_parameters["cache and reuse memory maps"] = "true" 
                    cat.save(st)
                    st = cat.get_store(dirname, workspace=wks)
                else:
                    print " EXISTS."
                
                print "      ========================================================="
                print "      listing published resources"
                print ""
                print "            ",
                for r in st.get_resources(available=False):
                    print r.name,
                print
                
                print "      publishing new resources"
                print ""
                # get unpublished resources (available = true !!!)
                for r in st.get_resources(available=True):
                    print "            publish", r
                    #  EPSG:23030 coordinate system does not work outside europe (use EPSG:900913)
                    feature = cat.publish_featuretype(r, st, native_crs="EPSG:4326", srs="EPSG:4326")
                    # feature.projection_policy = "REPROJECT_TO_DECLARED"
                    feature.projection_policy = "FORCE_DECLARED"
                    cat.save(feature)
                    
                    # set hyp style if exists
                    s = cat.get_style("hyp_"+r)
                    if s != None:
                        l = cat.get_layer(dirname+":"+r)
                        l.default_style = s  
                        cat.save(l)
                
                # map natural, waterways, roads, places
                wkcat = Catalog("http://localhost:8180/geoserver/rest/workspaces/" + dirname)
                wkcat.username = "admin"
                wkcat.password = "geoserver"
                
                lg = wkcat.get_layergroup(dirname + "_background")
                if lg == None:
                    print "               add layer group", dirname, "_background"
                    bbox = None
                    for r in cat.get_resources(store=st):
                        
                        bbox = mergeBBox(r.native_bbox, bbox) 
                        print bbox
                            
                    layerList = []
                    l = cat.get_layer(dirname+":sea")
                    if l != None:
                        layerList.append(dirname+":sea")
                    layerList.extend([dirname+":natural", dirname+":waterways", dirname+":roads"])
                    l = cat.get_layer(dirname+":places_zn")
                    if l != None:
                        layerList.append(dirname+":places_zn")
                    else:
                        layerList.append(dirname+":places")

                    xmin1, xmax1, ymin1, ymax1, _ = bbox
                    lg = wkcat.create_layergroup(dirname+"_background", layers=layerList, bounds=(xmin1, xmax1, ymin1, ymax1, "EPSG:4326"))
                    
                    wkcat.save(lg)
            
def main(gs_url, gs_user, gs_pwd, datadir, encoding):
    cat = Catalog(gs_url)
    cat.username = gs_user
    cat.password = gs_pwd
        
    loadStyle(cat, datadir + "/styles")
    aniStyle = cat.get_style("ani_line")
 
    loadSynoptic(cat, datadir + "/ani", aniStyle, encoding)
    loadAutocadSynoptic(cat, datadir + "/hv", "hv")
    loadMap(cat, datadir + "/map")
    

#--------------------------------------------------------------------------------------
# create logger
g_logger = logging.getLogger('load_gs')
g_logger.setLevel(logging.DEBUG)
# create console handler
ch = logging.StreamHandler(sys.stdout)
ch.setLevel(logging.INFO)
# create formatter and add it to the handlers
formatter = logging.Formatter('%(asctime)s - %(name)s[%(levelname)s] %(message)s')
ch.setFormatter(formatter)
# add the handlers to the logger
g_logger.addHandler(ch)

g_logLevelMap = { 'error' : logging.ERROR, 'warn' : logging.WARN, 'info' : logging.INFO, 'debug' : logging.DEBUG}
g_logStack = []
def logStart(msg):
    sd = datetime.datetime.today()
    prefix = '    ' * len(g_logStack)
        
    g_logStack.append((sd, msg))
    
    g_logger.info(">%s%s", prefix, msg)

def logEnd():
    ed = datetime.datetime.today()
    sd, msg = g_logStack.pop()
    prefix = '    ' * len(g_logStack)
    g_logger.info("<%s%s FOR: %s\n", prefix, str(ed - sd), msg)
#--------------------------------------------------------------------------------------
  

if __name__ == "__main__":
    # create option parser
    parser = argparse.ArgumentParser()
    parser.add_argument("-d", "--datadir", dest="rootdir",
                      help="root folder of geoserver data (default init_data)", default="init_data")
    parser.add_argument("-u", "--user", dest="gs_username",
                      help="geoserver user name (default 'admin')", default="admin")
    parser.add_argument("-p", "--password", dest="gs_password",
                      help="password of geoserver user (default 'geoserver')", default="geoserver")
    parser.add_argument("-e", "--encoding", dest="encoding",
                      help="geoserver encoding format for shapefile stores", default="UTF-8")
    parser.add_argument("-w", "--gsurl", dest="gs_url",
                      help="geoserver root url (default 'http://localhost:8180/geoserver/rest')", default="http://localhost:8180/geoserver/rest")
    parser.add_argument("-l", "--logLevel", dest="logLevel",
                      help="Application log level [error,warn,info,debug] (default 'info') ", default="info")
         
    options = parser.parse_args()
    
    # set log level
    if options.logLevel in g_logLevelMap:
        g_logger.setLevel(g_logLevelMap[options.logLevel])
        for h in g_logger.handlers:
            h.setLevel(g_logLevelMap[options.logLevel])
    else:
        g_logger.error("Unknown loglevel (%s), info will be used" % (options.logLevel))
        
    # run loader
    main(options.gs_url, options.gs_username, options.gs_password, options.rootdir, options.encoding)
    