# tag for documentation begin ## end empty line (javaDoc)
####################################################################
##
#  @author       THALES Security Solutions & Services
#
# @brief          Alarm filterpanel
#
# @version       1.0

####################################################################
##
#
#
#  Name  of file      : HSCS_Alarm_Filter.tcl   
#
# Content:  
#                according the application information the DATA FILTER KEYS must be changed if it is necessary
#              
#
#

####################################################################


##
#criticities filter gadgets
variable _CRITICITIES_FILTER_KEYS_GADGET    [list Cr_Major Cr_Minor Cr_Medium  Cr_Other]
##
#acknowledge filter gadgets
variable _ACKNOWLEDGE_FILTER_GADGET         [list Cr_Acknowledge Cr_NotAcknowledge]
##
#lstations filter gadgets
variable _STATION_FILTER_GADGET             [list StationAll Stations]
##
#functions filter gadgets
variable _FUNCTION_FILTER_GADGET            [list FunctionAll Functions]
##
#equipments types filter gadgets
variable _TYPE_FILTER_GADGET                [list EquipmentTypesAll EquipmentTypes]
##
#start time filter gadgets
variable _START_TIME_FILTER_GADGET          [list Start_Year Start_Month Start_Day Start_Hour Start_Minute]
##
#end time filter gadgets
variable _END_TIME_FILTER_GADGET            [list End_Year End_Month End_Day End_Hour End_Minute]
##
# filter gadgets
variable _TEXT_FILTER_GADGET                [list FilterText]

##
#mapping between the gadgets and the values of the criticities associated at the gadgets
array set _CRITICITIES_GADGET_VALUE_MAP [list Cr_Major $::HSCSAlarm::_SEVERITY1 \
                                                                                Cr_Medium $::HSCSAlarm::_SEVERITY2 \
                                                                                Cr_Minor $::HSCSAlarm::_SEVERITY3 \
                                                                                Cr_Other $::HSCSAlarm::_SEVERITY0 ]
             
##
#minimum year for date
variable _MIN_YEAR 2010

##
#Allow to remove the alphabetically sort on the list of stations name. 
#In fact some application wants to display the station sorting by their reference and not alphabetically
variable _NO_ALPHA_SORT_STATION 0
##
#Allow to remove the alphabetically sort on the list of functions name. 
#In fact some application wants to display the function sorting by their reference and not alphabetically
variable _NO_ALPHA_SORT_FUNCTION 0
##
#Allow to remove the alphabetically sort on the list of equipments name. 
#In fact some application wants to display the equipment sorting by their reference and not alphabetically
variable _NO_ALPHA_SORT_EQUIPMENT 0
                           

#-------------------------------------------------------------------
# DoOnInit
##
#  call by OnInit

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  0

#-------------------------------------------------------------------
proc DoOnInit { } {

    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    ::HSCSPanel::show
    
    return 0
    
}

#-------------------------------------------------------------------
# updateFilter
##
#  internal used call by updateSpecific or after a profile changed,
#it updates the filter with the default value and update the gadget 
# with it

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc updateFilter { }  {
                                   
    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN   
    
    initializeFilter
    
    updatePanel 
 
    # Update the panel's gadgets for initialize values
    updateGadgetsFromFilter
 
    # Apply the default filter
    ScsVisu::After 1 applyFilter
    
    noUserModification
    
}

#-------------------------------------------------------------------
# updatePrintButton
##
#  internal used call by updateSpecific, it update the state 
#of print button according the rights of the current profile

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc updatePrintButton { }  {
                                   
    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN   
    
    set right 0
    if {[info exists ::HSCSProfile::_ACTION_PROFILE(CONTROL)] && \
         [info exists ::HSCSCST::_FUNCTION_ALLOWED(PanelPrint)]} {
        set function $::HSCSCST::_FUNCTION_ALLOWED(PanelPrint)
        set mask $::HSCSProfile::_ACTION_PROFILE(CONTROL)
        
        if {0 != [string compare $::HSCSCST::_CURRENT_STATION_NAME ""]} {
            set listOfLocation [array get ::HSCSAlarm::_LOCATION_MAP]
            set currentStation "&$::HSCSCST::_CURRENT_STATION_NAME"
            set geoCatValueIndex [lsearch $listOfLocation $currentStation]
            if {$geoCatValueIndex != -1} {
                #the location is known
                if {0 != [::HSCSProfile::isFunctionAllowedForCurProfileAtLocation  $currentStation $function $mask ]} {
                    set right 1
                }
            } else {
                if {0 != [::HSCSProfile::isFunctionAllowedForCurProfile $function $mask ]} {
                    set right 1
                }
            }
        } else {
            if {0 != [::HSCSProfile::isFunctionAllowedForCurProfile $function $mask ]} {
                set right 1
            }
        }
    }
    
    ScsSet.Btn_Print.Sensitive $right
    
}

#-------------------------------------------------------------------
#updateSpecificUser
##
# permits to initiallize specific treatments.
#This procedure is called by updateSpecific to permit at the user to 
#add his own treatments.

#-------------------------------------------------------------------
##
# @param[in]  screenNumber the number of the current screenNumber
# @param[in] pageTag tag of the current page
# @param[in] associatedList the Scslist
# @param[in] associatedGadgetListPath the path to the gadget which contains 
#                                                      the ScsList
# @param[in] defaultCriticityFilter a list which defines the default state 
#                                                 for criticities filters 
#                                                (ex: [list Cr_Major 1 Cr_Medium 1 Cr_Minor 1 Cr_Other 0]).
#                                                If it is not defined all criticities are selected by default
# @param[in] defaultFunctionFilter a list which defines the 
#                                                 functional category selected by default. It be used for 
#                                                 buttons of HSCS_Frontal_Alarm_Synthesis
# @param[out]  -
# @return  0

#-------------------------------------------------------------------
proc updateSpecificUser { screenNumber\
                                     pageTag \
                                     associatedList\
                                     associatedGadgetListPath\
                                     {defaultCriticityFilter ""}\
                                     {defaultFunctionFilter ""} } {

    HSCSTrace::io $::HSCSTrace::_FRONTAL_DOMAIN
    
}

#-------------------------------------------------------------------
# updateSpecific
##
#  call by the page at the page creation,
# permits to initiallize specific treatments.

#-------------------------------------------------------------------
##
# @param[in] screenNumber the number of the current screenNumber
# @param[in] pageTag tag of the current page
# @param[in] associatedList the Scslist
# @param[in] associatedGadgetListPath the path to the gadget which contains 
#                                                      the ScsList
# @param[in] defaultCriticityFilter a list which defines the default state 
#                                                 for criticities filters 
#                                                (ex: [list Cr_Major 1 Cr_Medium 1 Cr_Minor 1 Cr_Other 0]).
#                                                If it is not defined all criticities are selected by default
# @param[in] defaultFunctionFilter a list which defines the 
#                                                 functional category selected by default. It be used for 
#                                                 buttons of HSCS_Frontal_Alarm_Synthesis
# @param[out]  -
# @return  0

#-------------------------------------------------------------------
proc updateSpecific { screenNumber\
                               pageTag \
                               associatedList\
                               associatedGadgetListPath\
                               {defaultCriticityFilter ""}\
                               {defaultFunctionFilter ""} }  {
                                   
    ::HSCSTrace::in $::HSCSTrace::_PANEL_DOMAIN
    
    variable _page               $pageTag
    variable _screen             $screenNumber

    variable _associatedList
    set _associatedList $associatedList
    
    variable _associatedGadgetListPath
    set _associatedGadgetListPath $associatedGadgetListPath

    #variables for filters
    #an element of this array for each element of the filter
    variable _filter
    array set _filter [list]

    #to initialize the filter with defaults value when the reset button is selected
    variable _defaultFilter
    array set _defaultFilter [list]
    
    variable _defaultCriticityFilter 
    set _defaultCriticityFilter $defaultCriticityFilter
    variable _defaultFunctionFilter
    set _defaultFunctionFilter $defaultFunctionFilter
 
    updateStationFunctionEquipmentType
    
    updateSpecificUser $screenNumber \
                              $pageTag \
                              $associatedList \
                              $associatedGadgetListPath \
                              $defaultCriticityFilter \
                              $defaultFunctionFilter
                              
    updateFilter
    
    #update the state of the print button accordint the current profile
    updatePrintButton

    ::HSCSTrace::out $::HSCSTrace::_PANEL_DOMAIN
    
    return 0
    
}

#-------------------------------------------------------------------
# updateNewPage
##
#  call each time a layout page of the function notebook is opened

#-------------------------------------------------------------------
##
# @param[in] screenNumber the number of the current screenNumber
# @param[in] pageTag tag of the current page
# @param[out]  -
# @return  0

#-------------------------------------------------------------------
proc updateNewPage { screenNumber\
                                     pageTag} {
                                     
    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    return 0
    
}

#-------------------------------------------------------------------
# updateOldPage
##
#  call each time a layout page of the function notebook is closed

#-------------------------------------------------------------------
##
# @param[in] screenNumber the number of the current screenNumber
# @param[in] pageTag tag of the current page
# @param[out]  -
# @return  0

#-------------------------------------------------------------------
proc updateOldPage { screenNumber\
                                    pageTag} {

    ::HSCSTrace::io $::HSCSTrace::_FRONTAL_DOMAIN
    
    return 0
    
}

#-------------------------------------------------------------------
# updatesAfterChangeProfile
##
#  call each time the current profile is modified (not a the
#initialization step of application). Update the panel according 
#the new profile

#-------------------------------------------------------------------
##
# @param[in]  operator new operator
# @param[in]   profile new profile
# @param[out]  -
# @return  0

#-------------------------------------------------------------------
proc updatesAfterChangeProfile { operator \
                                                      profile } {

    ::HSCSTrace::io $::HSCSTrace::_FRONTAL_DOMAIN
    
    #initialize the filter with default value and apply the filter
    updateFilter
    
    #update the state of the print button accordint the current profile
    updatePrintButton
    
    return 0
    
}

#-------------------------------------------------------------------
# updateStationFunctionEquipmentType
##
#  initialize lists of station,functional category and equipment type

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc updateStationFunctionEquipmentType {  } {

    ::HSCSTrace::in $::HSCSTrace::_PANEL_DOMAIN
    
    #update the stations list
    variable _stationsName
    set _stationsName [list]
    set tempId [array names ::HSCSAlarm::_LOCATION_MAP]
    set tempId [lsort -integer -increasing $tempId]
    
    #update the list with all possible location 
    #except the error location if it exists
    foreach id $tempId {
        if {0 == [string compare $::HSCSAlarm::_DEFAULT_ALARM_ID ""] || \
              0 !=  [string compare $id $::HSCSAlarm::_DEFAULT_ALARM_ID]} {
            set loc $::HSCSAlarm::_LOCATION_MAP($id)
            lappend _stationsName $loc
        }
    }
    
    variable _NO_ALPHA_SORT_STATION
    if {$_NO_ALPHA_SORT_STATION == 0} {
        #sort the name of stations
        set _stationsName [lsort -dictionary $_stationsName]
    }

    #update the functions list
    variable _functionsName
    set _functionsName [list]
    set tempId [array names ::HSCSAlarm::_FUNCAT_MAP]
    set tempId [lsort -integer -increasing $tempId]
    
    foreach  id $tempId {
        set func $::HSCSAlarm::_FUNCAT_MAP($id)
        lappend _functionsName $func
    }
    
    variable _NO_ALPHA_SORT_FUNCTION
    if {$_NO_ALPHA_SORT_FUNCTION == 0} {
        #sort the name of functions
        set _functionsName [lsort -dictionary $_functionsName]
    }
    
    #update the equipmentType  list
    variable _equipmentTypesName
    set _equipmentTypesName [list]
    set tempType [array names ::HSCSAlarm::_EQUIPMENT_TYPE_MAP]
    set tempType [lsort -integer -increasing $tempType]
    
    foreach  type $tempType {
        set typeLabel $::HSCSAlarm::_EQUIPMENT_TYPE_MAP($type)
        lappend _equipmentTypesName $typeLabel
    }
    
    variable _NO_ALPHA_SORT_EQUIPMENT
    if {$_NO_ALPHA_SORT_EQUIPMENT == 0} {
        #sort the type of equipment
        set _equipmentTypesName [lsort -dictionary $_equipmentTypesName]
    }
    
    ::HSCSTrace::out $::HSCSTrace::_PANEL_DOMAIN

}

#-------------------------------------------------------------------
# initializeFilterUser
##
# initialize the filters, the array which describe the filter with user values.
#This procedure is called by initializeFilter to permit at the user to 
#add his own treatments.

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc  initializeFilterUser { } {

    HSCSTrace::io $::HSCSTrace::_FRONTAL_DOMAIN
    
}

#-------------------------------------------------------------------
# initializeFilter
##
#  initialize the filters, the array which describe the filter

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc initializeFilter { } {
             
    ::HSCSTrace::in $::HSCSTrace::_PANEL_DOMAIN
    
    variable _defaultCriticityFilter 
    variable _defaultFunctionFilter
    
    variable _filter

    # Override filters entries with parameters
    variable _defaultFilter
    
    # Initialize filter's start & end dates
    set now [ScsVisu::GetTime]
    
    #2 digits
    set _filter(Start_Year) [clock format $now -format %Y]
    set _filter(Start_Month) [clock format $now -format %m]
    set _filter(Start_Day) [clock format $now -format %d]
    set _filter(Start_Hour) 00
    set _filter(Start_Minute) 00
    
    #2 digits
    set _filter(End_Year) [clock format $now -format %Y]
    set _filter(End_Month) [clock format $now -format %m]
    set _filter(End_Day) [clock format $now -format %d]
    set _filter(End_Hour) 23
    set _filter(End_Minute) 59

    #filter on dates
    variable _START_TIME_FILTER_GADGET
    variable _END_TIME_FILTER_GADGET
    set dataFilterKeys [concat $_START_TIME_FILTER_GADGET $_END_TIME_FILTER_GADGET]
    foreach { key } $dataFilterKeys  {
        set _defaultFilter($key) $_filter($key)
    }

    #filter on alarm state
    set _filter(Cr_Acknowledge) 1
    set _defaultFilter(Cr_Acknowledge) $_filter(Cr_Acknowledge)
    set _filter(Cr_NotAcknowledge) 1
    set _defaultFilter(Cr_NotAcknowledge) $_filter(Cr_NotAcknowledge)

    #filter on criticities 
    variable _CRITICITIES_FILTER_KEYS_GADGET
    if {0 == [string compare $_defaultCriticityFilter ""]} {
        set nb 0
    } else {
        set nb [llength $_defaultCriticityFilter]
    }
    
    if {0 != $nb && 0 == [expr $nb % 2]} {
    
        foreach {gadget value} $_defaultCriticityFilter {
            if {-1 != [lsearch $_CRITICITIES_FILTER_KEYS_GADGET $gadget] } {
                #find the gadget in the list of possible gadgets
                set _defaultFilter($gadget) $value
                set _filter($gadget) $value
            }
        }
    } else {
    
        foreach criticity $_CRITICITIES_FILTER_KEYS_GADGET {
            set _defaultFilter($criticity) 1
            set _filter($criticity) 1
        }
    }

    #filter on functional category 
    variable _functionsName
    if {0 == [string compare $_defaultFunctionFilter ""]} {
        set nb 0
    } else {
        set nb [llength $_defaultFunctionFilter]
    }
    if {0 !=  $nb} {
        foreach functionName $_defaultFunctionFilter {
            if {-1 != [lsearch _functionsName $functionsName] } {
                #find the function in the list of possible functions
                set _defaultFilter($functionsName) 1
                set _filter($functionsName) 1
            }   
        }
    }
    
    #filter on free text
    variable _TEXT_FILTER_KEY_GADGET
    set _filter(FilterText) ""
    set _defaultFilter(FilterText) $_filter(FilterText)
    
    #user treatments
    initializeFilterUser

    ::HSCSTrace::out $::HSCSTrace::_PANEL_DOMAIN
}

#-------------------------------------------------------------------
# updatePanelUser
##
# initialize some user gadget of the panel, 
#This procedure is called by updatePanel to permit at the user to 
#add his own treatments.

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc updatePanelUser { } {

    HSCSTrace::io $::HSCSTrace::_FRONTAL_DOMAIN
    
}

#-------------------------------------------------------------------
# updatePanel
##
# initialize some gadget of the panel

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc updatePanel {  } {
   
    ::HSCSTrace::in $::HSCSTrace::_PANEL_DOMAIN
    
    #update  BtnNoFilter button state according the current profile
    set visible 0
    if {[info exists ::HSCSProfile::_ACTION_PROFILE(CONTROL)] && \
         [info exists ::HSCSCST::_FUNCTION_ALLOWED(BtnNoFilter)]} {
        set function $::HSCSCST::_FUNCTION_ALLOWED(BtnNoFilter)
        set mask $::HSCSProfile::_ACTION_PROFILE(CONTROL)
        set visible [::HSCSProfile::isFunctionAllowedForCurProfile $function $mask ]
    }
    ScsSet NoFilter.Visible $visible
    ScsSet NoFilter.State 0
    
    #update date filter buttons
    #LKO : 01/02/11 PCR 4500
    ScsSet Start_NoFilter.State 1
    # END PCR 4500
    OnStart_NoFilter 0
    ScsSet End_NoFilter.State 1
    OnEnd_NoFilter 0
    
    #Temporary hide the stations and fonctions list & frame - Manage the "Evenements" toggle.
    ScsSet StationAll.State 1
    ScsSet Stations.Visible 0
    ScsSet EquipmentTypesAll.State 1
    ScsSet EquipmentTypes.Visible 0
    variable _defaultFunctionFilter
    ScsSet FunctionAll.State 1
    if {0 != [string compare $_defaultFunctionFilter ""]} {
        ScsSet Functions.Visible 1
    } else {
        ScsSet Functions.Visible 0
    }
    
    #update alarm state
    ScsSet Cr_Acknowledge.State 0
    ScsSet Cr_NotAcknowledge.State 0
    
    #update the stations list
    variable _stationsName
    ScsSetStringList Stations $_stationsName
 
    #update the functions list
    variable _functionsName
    ScsSetStringList Functions $_functionsName
 
    #update the equipment types  list
    variable _equipmentTypesName
    ScsSetStringList EquipmentTypes $_equipmentTypesName
    
    #user treatments
    updatePanelUser
    
   ::HSCSTrace::out $::HSCSTrace::_PANEL_DOMAIN
   
}

#-------------------------------------------------------------------
# updateGadgetsFromFilterUser
##
#initialize the gadgets, from the filter values (user gadget)
#This procedure is called by updateGadgetsFromFilter to permit at the user to 
#add his own treatments.

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc updateGadgetsFromFilterUser { } {

    HSCSTrace::io $::HSCSTrace::_FRONTAL_DOMAIN
    
}

#-------------------------------------------------------------------
# updateGadgetsFromFilter
##
#initialize the gadgets, from the filter values

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc updateGadgetsFromFilter { } {
     
    ::HSCSTrace::out $::HSCSTrace::_PANEL_DOMAIN

    variable _filter
    
    # Criticities
    variable _CRITICITIES_FILTER_KEYS_GADGET
    foreach criticity $_CRITICITIES_FILTER_KEYS_GADGET {
        ScsSet $criticity $_filter($criticity)
    }   
    
    ScsSet Cr_Acknowledge.State $_filter(Cr_Acknowledge)
    ScsSet Cr_NotAcknowledge.State $_filter(Cr_NotAcknowledge)
    
    # Stations list
    set stationsDisplayed [ScsGet Stations.Visible]
    if { $stationsDisplayed != 0 } {
        variable _stationsName
        ScsSetStringList Stations $_stationsName
        
        foreach station $_stationsName {
            if {[info exists _filter($station)]} {
                ScsSet Stations.Select $_filter($station)
            }
        }
    }
    
    # Functions list
    set functionsDisplayed [ScsGet Functions.Visible]
    if { $functionsDisplayed != 0 } {
        variable _functionsName
        ScsSetStringList Functions $_functionsName
        
        foreach function $_functionsName {
            if {[info exists _filter($function)]} {
                ScsSet Functions.Select $_filter($function)
            }
        }
    }
    
    # equipment list
    set equipmentTypesDisplayed [ScsGet EquipmentTypes.Visible]
    if { $equipmentTypesDisplayed != 0 } {
        variable _equipmentTypesName
        ScsSetStringList EquipmentTypes $_equipmentTypesName
        
        foreach equipmentType $_equipmentTypesName {
            if {[info exists _filter($equipmentType)]} {
                ScsSet EquipmentTypes.Select $_filter($equipmentType)
            }
        }
    }
    
    #to keep the old value for validity test
    variable _oldStartDay
    variable _oldEndDay
    set _oldStartDay $_filter(Start_Day)
    set _oldEndDay $_filter(End_Day)
    
    # Start/Ends dates fields
    
    ScsSet Start_Day.Value $_filter(Start_Day)
    ScsSet Start_Hour.Value $_filter(Start_Hour)
    ScsSet Start_Minute.Value $_filter(Start_Minute)
    ScsSet Start_Month.Value $_filter(Start_Month)
    ScsSet Start_Year.Value $_filter(Start_Year)
    
    ScsSet End_Day.Value $_filter(End_Day)
    ScsSet End_Hour.Value $_filter(End_Hour)
    ScsSet End_Minute.Value $_filter(End_Minute)
    ScsSet End_Month.Value $_filter(End_Month)
    ScsSet End_Year.Value $_filter(End_Year)
    
    
    #Text
    ScsSet  FilterText.Label $_filter(FilterText)
    
    # Warning messages
    OnSelCriticity 0
    
    #user treatments
    updateGadgetsFromFilterUser 
    
    ::HSCSTrace::out $::HSCSTrace::_PANEL_DOMAIN
    
}

#-------------------------------------------------------------------
# addFirstDigit
##
#add digit 0 at the beginning of the value if the length 
#of the value is 1

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  new value

#-------------------------------------------------------------------
proc addFirstDigit { value} {

    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    set newValue $value
    
    if { [string length $newValue] == 1} {
        set newValue "0$newValue"
    }
    
    return $newValue
    
 }

#-------------------------------------------------------------------
# checkParameters
##
#Check if useful DATES are valid

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc checkParameters { } {
    
    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    set message ""
    
    variable _MIN_YEAR
     
    #for the text between beginDate and endDate
    set beginDate 0
    if {0 == [ScsGet Start_NoFilter.State]} {
        set dB [ScsGet Start_Day.Value]
        set dB [addFirstDigit $dB]
        set mB [ScsGet Start_Month.Value]
        set mB [addFirstDigit $mB]
        set yB [ScsGet Start_Year.Value]
        set hB [ScsGet Start_Hour.Value]
        set hB [addFirstDigit $hB]
        set nB [ScsGet Start_Minute.Value]
        set nB [addFirstDigit $nB]
        set check [format "%s/%s/%s %s:%s:00" $mB $dB $yB $hB $nB]
        if { $yB < $_MIN_YEAR || [catch {clock scan $check} err] } {
            set message "[::HSCSLanguage::getDbMessage "&msg::invalidBeginDate"]"
        } else {
            set beginDate "$yB$mB$dB$hB$nB"
        }
    } 
    
    #for the text between beginDate and endDate
    set endDate [expr $beginDate + 1]
    if { 0 == [string compare $message ""]  && \
          0 == [ScsGet End_NoFilter.State]}   {
        set dE [ScsGet End_Day.Value]
        set dE [addFirstDigit $dE]
        set mE [ScsGet End_Month.Value]
        set mE [addFirstDigit $mE]
        set yE [ScsGet End_Year.Value]
        set hE [ScsGet End_Hour.Value]
        set hE [addFirstDigit $hE]
        set nE [ScsGet End_Minute.Value]
        set nE [addFirstDigit $nE]

        set check [format "%s/%s/%s %s:%s:00" $mE $dE $yE $hE $nE]
        if { $yE < $_MIN_YEAR || [catch {clock scan $check} err] } {
            set message "[::HSCSLanguage::getDbMessage "&msg::invalidEndDate"]"
        } else {
            set endDate "$yE$mE$dE$hE$nE"
        }
    }
    
    if { 0 == [string compare $message ""] } {
        #test the coherence between the two dates
        #verify the two dates only if 
        if {[expr $endDate <= $beginDate]} {
            set message "[::HSCSLanguage::getDbMessage "&msg::incoherenceBeginEndDate"]"
        }
    }
    
    return $message
}

#-------------------------------------------------------------------
# updateFilterFromGadgetsUser
##
# initialize the filters, the array which describe the filter 
#from the gadgets (user gadgets)
#This procedure is called by updateFilterFromGadgets to permit at the user to 
#add his own treatments.

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc updateFilterFromGadgetsUser { } {

    HSCSTrace::io $::HSCSTrace::_FRONTAL_DOMAIN
    
}

#-------------------------------------------------------------------
# updateFilterFromGadgets
##
#initialize the filters, the array which describe the filter 
#from the gadgets

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc updateFilterFromGadgets {} {

    ::HSCSTrace::in $::HSCSTrace::_PANEL_DOMAIN

    variable _filter
    
    # Criticities
    variable _CRITICITIES_FILTER_KEYS_GADGET
    foreach criticity $_CRITICITIES_FILTER_KEYS_GADGET {
        set _filter($criticity) [ScsGet $criticity.State]
    }
    
    #state 
    set _filter(Cr_Acknowledge) [ScsGet Cr_Acknowledge.State]
    set _filter(Cr_NotAcknowledge) [ScsGet Cr_NotAcknowledge.State]
    
    # Stations
   set selectStationsList [ScsGet Stations.MultiSelect]
    variable _stationsName
    
    foreach station $_stationsName {
        #suppress the old selected station in the filter
        if { [info exists _filter($station)]} {
            unset _filter($station)
        }
        #add the station in the filter if the station is selecetd
        if {-1 != [lsearch $selectStationsList $station]} {
            set _filter($station) 1
        }
    }
    
    # Functions
   set selectFunctionsList [ScsGet Functions.MultiSelect]
    variable _functionsName
    
    foreach function $_functionsName {
        #suppress the old selected station in the filter
        if { [info exists _filter($function)]} {
            unset _filter($function)
        }
        #add the station in the filter if the station is selecetd
        if {-1 != [lsearch $selectFunctionsList $function]} {
            set _filter($function) 1
        }
    }
    
    # equipments
   set selectEquipmentTypesList [ScsGet EquipmentTypes.MultiSelect]
    variable _equipmentTypesName
    
    foreach equipmentType $_equipmentTypesName {
        #suppress the old selected station in the filter
        if { [info exists _filter($equipmentType)]} {
            unset _filter($equipmentType)
        }
        #add the station in the filter if the station is selecetd
        if {-1 != [lsearch $selectEquipmentTypesList $equipmentType]} {
            set _filter($equipmentType) 1
        }
    }
    
    # Dates
    if {[ScsGet Start_NoFilter.State] == 0} {
        set _filter(Start_Year)   [ScsGet Start_Year.Value]
        set _filter(Start_Month)  [ScsGet Start_Month.Value]
        set _filter(Start_Month) [addFirstDigit $_filter(Start_Month)]
        set _filter(Start_Day)     [ScsGet Start_Day.Value]
        set _filter(Start_Day) [addFirstDigit $_filter(Start_Day)]
        set _filter(Start_Hour)   [ScsGet Start_Hour.Value]
        set _filter(Start_Hour) [addFirstDigit $_filter(Start_Hour)]
        set _filter(Start_Minute) [ScsGet Start_Minute.Value]
        set _filter(Start_Minute) [addFirstDigit $_filter(Start_Minute)]
    }
    
    if {[ScsGet End_NoFilter.State] == 0} {
        set _filter(End_Year)  [ScsGet End_Year.Value]
        set _filter(End_Month) [ScsGet End_Month.Value]
        set _filter(End_Month) [addFirstDigit $_filter(End_Month)]
        set _filter(End_Day)   [ScsGet End_Day.Value]
        set _filter(End_Day) [addFirstDigit $_filter(End_Day)]
        set _filter(End_Hour)  [ScsGet End_Hour.Value]
        set _filter(End_Hour) [addFirstDigit $_filter(End_Hour)]
        set _filter(End_Minute) [ScsGet End_Minute.Value]
        set _filter(End_Minute) [addFirstDigit $_filter(End_Minute)]
    }
    
    #filter text
    set _filter(FilterText) [ScsGet FilterText.Label]
    
    # Save the current tab's filter
    variable _currentFilter
    array set _currentFilter [array get _filter]
    
    #user treatments
    updateFilterFromGadgetsUser 
   
    ::HSCSTrace::out $::HSCSTrace::_PANEL_DOMAIN
    
}

#-------------------------------------------------------------------
# criticityToCode
##
# return the value associated at a criticity

#-------------------------------------------------------------------
##
# @param[in] - criticity integer that represents the critical level of alarm
# @param[out]  -
# @return  - string describing the critical level

#-------------------------------------------------------------------
proc criticityToCode { criticity } {
    
    variable _CRITICITIES_GADGET_VALUE_MAP
    return $_CRITICITIES_GADGET_VALUE_MAP($criticity)
    
}

#-------------------------------------------------------------------
# stationToCode
##
#return the geographical category associated at a station

#-------------------------------------------------------------------
##
# @param[in] station the station short name
# @param[out]  -
# @return  - Geographical Category

#-------------------------------------------------------------------
proc stationToCode { station } {
    
    #list where odd elements are the gorgraphical cat and the even elements are the station
    #geoCat1 station1 geoCat2 station2 ...
    set geoCatStationList [array get ::HSCSAlarm::_LOCATION_MAP]
    
    set index [lsearch $geoCatStationList $station]
    return [lindex $geoCatStationList [incr index  -1]]
            
}

#-------------------------------------------------------------------
# functionToCode
##
# return the functional category associated at a function

#-------------------------------------------------------------------
##
# @param[in] function the function short name
# @param[out]  -
# @return  - Functional Category

#-------------------------------------------------------------------
proc functionToCode { function } {
    
    #list where odd elements are the functional cat and the even elements are the function
    #geoCat1 station1 geoCat2 station2 ...
    set funcCatFunctionList  [array get ::HSCSAlarm::_FUNCAT_MAP]
    
    set index [lsearch $funcCatFunctionList $function]
    return [lindex $funcCatFunctionList [incr index  -1]]
            
}

#-------------------------------------------------------------------
# equipmentTypeToCode
##
# return the equipment type id associated at an equipment type

#-------------------------------------------------------------------
##
# @param[in] equipmentTypeLabel the label of the equipment type
# @param[out]  -
# @return  - integer represting the Equipment type

#-------------------------------------------------------------------
proc equipmentTypeToCode { equipmentTypeLabel } {
    
    #list where odd elements are the equipment type and the even elements are 
    #the equipment type label
    #type1 label1 type2 label2 ...
    set equipmentList  [array get ::HSCSAlarm::_EQUIPMENT_TYPE_MAP]
    
    set index [lsearch $equipmentList $equipmentTypeLabel]
    return [lindex $equipmentList [incr index  -1]]
            
}

#-------------------------------------------------------------------
# generateSeverityFilter
##
#generate the severity part of the filter

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc generateSeverityFilter {} {

    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    variable _filter
    variable _constraints
    
    # Criticities constraints
    variable _CRITICITIES_FILTER_KEYS_GADGET
    #severity == -1 when no severity is selected, because there a no alarms with such severity 
    set criticityconstraints [list "Severity == -1"]
    foreach criticity $_CRITICITIES_FILTER_KEYS_GADGET {
        if {[info exists _filter($criticity)]} {
            set state $_filter($criticity)
            if { $state == 1 } {
                set codes [criticityToCode $criticity]
                foreach code $codes {
                    lappend criticityconstraints "Severity == $code"
                }
            }
        }
    }
    if { [ llength $criticityconstraints] > 0 } {
        lappend _constraints "([join $criticityconstraints " OR "])"
    }
    
}

#-------------------------------------------------------------------
# generateStateFilter
##
#generate the state part of the filter

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc generateStateFilter {} {

    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    variable _filter
    variable _constraints
    
    set stateconstraints [list ]
    if {[info exists _filter(Cr_Acknowledge)]} {
        set state $_filter(Cr_Acknowledge)
        if { $state == 1 } {
            lappend stateconstraints "AcknowledgeRequired == 0"
        }
    }
    if {[info exists _filter(Cr_NotAcknowledge)]} {
        set state $_filter(Cr_NotAcknowledge)
        if { $state == 1 } {
            lappend stateconstraints "AcknowledgeRequired == 1"
        }
    }
    if { [ llength $stateconstraints] > 0 } {
        lappend _constraints "([join $stateconstraints " OR "])"
    }
    
}

#-------------------------------------------------------------------
# generateStationFilter
##
#generate the station part of the filter

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc generateStationFilter {} {

    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    variable _filter
    variable _constraints
    
    # station constraints
    variable _stationsName
    set stationsConstraints [list ]
    foreach station $_stationsName {
        if {[info exists _filter($station)]} {
            set state $_filter($station)
            if { $state == 1 } {
                set stationCode [stationToCode $station]
                lappend stationsConstraints "GeographicalCategory == $stationCode"
            }
        }
    }
    if { [ llength $stationsConstraints] > 0 } {
        lappend _constraints "([join $stationsConstraints " OR "])"
    }
}

#-------------------------------------------------------------------
# generateFunctionFilter
##
#generate the function part of the filter

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc generateFunctionFilter {} {

    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    variable _filter
    variable _constraints
    
    variable _functionsName
    set functionsConstraints [list ]
    foreach function $_functionsName {
        if {[info exists _filter($function)]} {
            set state $_filter($function)
            if { $state == 1 } {
                set functionCode [functionToCode $function]
                lappend functionsConstraints "FunctionalCategory == $functionCode"
            }
        }
    }
    if { [ llength $functionsConstraints] > 0 } {
        lappend _constraints "([join $functionsConstraints " OR "])"
    }

}

#-------------------------------------------------------------------
# generateTypeFilter
##
#generate the equipment type part of the filter

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc generateTypeFilter {} {

    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    variable _filter
    variable _constraints
    
    variable _equipmentTypesName
    set typeConstraints [list ]
    foreach typeLabel $_equipmentTypesName {
        if {[info exists _filter($typeLabel)]} {
            set state $_filter($typeLabel)
            if { $state == 1 } {
                set type [equipmentTypeToCode $typeLabel]
                lappend typeConstraints "EquipmentType == $type"
            }
        }
    }
    if { [ llength $typeConstraints] > 0 } {
        lappend _constraints "([join $typeConstraints " OR "])"
    }
    
}

#-------------------------------------------------------------------
# generateTimeFilter
##
#generate the time part of the filter

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc generateTimeFilter {} {

    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    variable _filter
    variable _constraints
    
    set szTempFilter ""
    if {[ScsGet Start_NoFilter.State] == 0} {
        set startDate "//"
        set startDate "[addFirstDigit $_filter(Start_Year)]-[addFirstDigit $_filter(Start_Month)]-[addFirstDigit $_filter(Start_Day)]"
        set startTime "[addFirstDigit $_filter(Start_Hour)]:[addFirstDigit $_filter(Start_Minute)]"
        
        set szTempFilter "AcquisitionDate >= [clock scan "$startDate $startTime"] "
    }
    
    if {[ScsGet End_NoFilter.State] == 0} {
        set endDate "[addFirstDigit $_filter(End_Year)]-[addFirstDigit $_filter(End_Month)]-[addFirstDigit $_filter(End_Day)]"
        set endTime  "[addFirstDigit $_filter(End_Hour)]:[addFirstDigit $_filter(End_Minute)]"

        if {0 != [string compare $szTempFilter ""]} {
            set szTempFilter "${szTempFilter} AND AcquisitionDate <= [clock scan "$endDate $endTime"]"
        } else {
            set szTempFilter "AcquisitionDate <= [clock scan "$endDate $endTime"]"
        }
    }
    
    if { 0 != [string compare $szTempFilter ""] } {
        lappend _constraints "($szTempFilter)"
    }
    
}

#-------------------------------------------------------------------
# generateTextFilter
##
#generate the free text part of the filter

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc generateTextFilter {} {

    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    variable _filter
    variable _constraints
    
    if {0 != [string compare $_filter(FilterText) ""]} {
        set szText $_filter(FilterText) 
        set szTempFilter "(Text LIKE \"\.\*${szText}\.\*\")"
        
        lappend _constraints "($szTempFilter)"
    }
    
}

#-------------------------------------------------------------------
# generateFilterUser
##
# generate the user filter according the state of gadget, 
#This procedure is called by generateFilter to permit at the user to 
#add his own treatments.

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc generateFilterUser { } {

    HSCSTrace::io $::HSCSTrace::_FRONTAL_DOMAIN
    
}

#-------------------------------------------------------------------
# generateFilter
##
#  generate the filter according the state of gadgets

#-------------------------------------------------------------------
##
# @param[in]  -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc generateFilter {} {
    
    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    variable _constraints
    
    generateSeverityFilter
    generateStateFilter
    generateStationFilter
    generateFunctionFilter
    generateTypeFilter
    generateTimeFilter
    generateTextFilter
    
    #user treatments
    generateFilterUser
    
    set _constraints [join $_constraints " AND "]
    
}

# Replaces the special characters "&" et "?" in the filter, without
# changing the encoding of the string ([string map] does change the encoding).
# "&" is removed and "?" is replaced by "X".

proc replace_special_characters {s} {
    set result ""
    set s_length [string length $s]

    for {set i 0} {$i < $s_length} {incr i} {
        set c [string index $s $i]
        switch $c {
            "&" {
                # Do nothing.
            }
            "?" {
                append result "X"
            }
            default {
                append result $c
            }
        }
    }

    return $result
}


#-------------------------------------------------------------------
# applyFilter
##
#apply the filter on the ScsList

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc applyFilter {} {
    
    ::HSCSTrace::in $::HSCSTrace::_PANEL_DOMAIN
    
    set cr 0
    variable _associatedList
    variable _filter
    variable _page
    variable _constraints
    set _constraints ""
    
    if {[ScsGet NoFilter.State] == 0} {
        
        if { [set message [checkParameters]] != "" } {
            set param [list $message]
            set dialog "::HSCSPanel::errorBoxSubDialogFromCurrent $param"
            ScsVisu::After 0 $dialog $Scs::CurrentGraphicPath
            set cr 1
        } else {
            # Update the current filter
            updateFilterFromGadgets

            # Create the constraints list
            generateFilter
        }
    }
   
    if {$cr == 0} {
        set _constraints [replace_special_characters $_constraints]
        ScsList::SetClientFilter "$_constraints" $_associatedList [::HSCSPanel::pageZoneOfCurrentPage $_page]
    }
    
    ::HSCSTrace::out $::HSCSTrace::_PANEL_DOMAIN
    
}

#-------------------------------------------------------------------
# userModification
##
#update the senstive parameter of the apply button. 
#The buttons become sensitive after a user action in the 
#filter parameters.

#-------------------------------------------------------------------
##
# @param[in] -
#
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc userModification {  } {

    ScsSet Btn_Apply.Sensitive 1
    
}

#-------------------------------------------------------------------
# noUserModification
##
#update the senstive parameter of the apply button. 
#The buttons become unsensitive after the record of a user action 
#in the filter parameters.

#-------------------------------------------------------------------
##
# @param[in] -
#
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc noUserModification {  } {

    ScsSet Btn_Apply.Sensitive 0
    
}

#-------------------------------------------------------------------
# OnSelCriticity
##
#callback of criticity toggle

#-------------------------------------------------------------------
##
# @param[in] applyFlag 1 if the callback is called by a user 
#action or directly by the panel. In the first case the button apply,
#reset can become selectable
#
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnSelCriticity { {applyFlag 1}} {
    variable _CRITICITIES_FILTER_KEYS_GADGET
    
    set i 0
    foreach criticity $_CRITICITIES_FILTER_KEYS_GADGET {
        if {[ScsGet $criticity.State] == 0} {
            incr i
        }
    }
    if {$i == [llength $_CRITICITIES_FILTER_KEYS_GADGET]} {
        ScsSet NoCriticalityMessage.Visible 1
    } else {
        ScsSet NoCriticalityMessage.Visible 0
    }
    
    if {$applyFlag == 1} {
       userModification
    }
    
}

#-------------------------------------------------------------------
# OnStationAll
##
#callback of station toogle

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnStationAll {} {
    variable _stationsName
    
    if {[ScsGet StationAll.State] == 0} {
        foreach station $_stationsName {
            if {[info exists _filter($station)]} {
                ScsSet Stations.Select $_filter($station)
            } else {
                #in case of the element is yet selected
                ScsSet Stations.Deselect $station
            }
        }
        ScsSet Stations.Visible 1
    } else {
        foreach station $_stationsName {
            #in case of the element is yet selected
            ScsSet Stations.Deselect $station
        }
        ScsSet Stations.Visible 0
    }
    
    userModification
    
}

#-------------------------------------------------------------------
# OnFunctionAll
##
#callback of function toogle

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnFunctionAll {} {
    variable _functionsName
    
    if {[ScsGet FunctionAll.State] == 0} {
        foreach function $_functionsName {
            if {[info exists _filter($function)]} {
                ScsSet Functions.Select $_filter($function)
            } else {
                #in case of the element is yet selected
                ScsSet Functions.Deselect $function
            }
        }
        ScsSet Functions.Visible 1
    } else {
        foreach function $_functionsName {
            #in case of the element is yet selected
            ScsSet Functions.Deselect $function
        }
        ScsSet Functions.Visible 0
    }
    
    userModification
    
}


#-------------------------------------------------------------------
# OnEquipmentTypesAll
##
#callback of station toogle

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnEquipmentTypesAll {} {
    variable _equipmentTypesName

    if {[ScsGet EquipmentTypesAll.State] == 0} {
        foreach type $_equipmentTypesName {
            if {[info exists _filter($type)]} {
                ScsSet EquipmentTypes.Select $_filter($type)
            } else {
                #in case of the element is yet selected
                ScsSet EquipmentTypes.Deselect $type
            }
        }
        ScsSet EquipmentTypes.Visible 1
    } else {
        foreach type $_equipmentTypesName {
            #in case of the element is yet selected
            ScsSet EquipmentTypes.Deselect $type
        }
        ScsSet EquipmentTypes.Visible 0
    }
    
    userModification
    
}

#-------------------------------------------------------------------
# OnBtn_Reset
##
#callback of the Btn_Reset button. It reinitialize the gadget 
#with the default values (the one used at the initialization of the panel)

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnBtn_Reset {} {

   ::HSCSTrace::in $::HSCSTrace::_PANEL_DOMAIN
    
    #unselect NoFilter
    ScsSet NoFilter.State 0
    
    #used _defaultFilter and not procedure initializeFilter because 
    #the calculate are yet made for _defaultFilter
    variable _defaultFilter
    variable _filter
    array set _filter [array get _defaultFilter]
    
    updatePanel
    
    # Update the panel's gadgets for initialize values
    updateGadgetsFromFilter

    applyFilter

    userModification

    ::HSCSTrace::out $::HSCSTrace::_PANEL_DOMAIN
}

#-------------------------------------------------------------------
# OnBtn_Apply
##
#callback of the Btn_Apply button

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnBtn_Apply {} {

    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    applyFilter
    
    noUserModification
    
}

#-------------------------------------------------------------------
# OnBtn_Print
##
#callback of the Btn_Print button

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnBtn_Print {  } { 

    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    ::HSCSPanel::mouseBusy

    #graphic path of the current page
    variable _page
    set pageGP [::HSCSPanel::pageZoneOfCurrentPage $_page]
    
    variable _associatedGadgetListPath
    
    # can't dump an empty list
    if { [List::GetInternalIndex ${_associatedGadgetListPath} 1] > -1 } {

        variable _associatedList
        set tagMessage "&title::Print${_associatedList}"
        set title  [::HSCSLanguage::getDbMessage $tagMessage]
        set OkCb       "[namespace current]::confirmPrint"
        set cancelCb   "[namespace current]::cancelPrint"
        set params     [list $title $OkCb $cancelCb [list $_associatedList $_associatedGadgetListPath]]
        
        set oldGP $Scs::CurrentGraphicPath
        set Scs::CurrentGraphicPath [::HSCSPanel::pageZoneOfCurrentPage $_page]
        ::HSCSPanel::subDialog  $HSCSPanel::_PRINT_LIST_PANEL $params
        set Scs::CurrentGraphicPath $oldGP
        
    } else {

        set message  [::HSCSLanguage::getDbMessage "&msg::PrintEmptyList"]
        ::HSCSPanel::warningBoxSubDialogFromParent $Scs::CurrentGraphicPath $message
    }

   ::HSCSPanel::mouseNormal
    
}

#-------------------------------------------------------------------
# cancelPrint
##
#Print cancel callback.This callback is called 
#by the selection of the cancel button

#-------------------------------------------------------------------
##
# @param[in] printer current printer name
# @param[in] currentList name of display list
# @param[in] listPath graphic path of the gadget which contains the 
#                  display list
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc cancelPrint { printer  \
                              currentList \
                              listPath } {
    # Nothing to be done
}

#-------------------------------------------------------------------
# confirmPrint
##
#Print confirmation callback.This callback is called 
#by the selection of the confirm button

#-------------------------------------------------------------------
##
# @param[in] printer current printer name
# @param[in] currentList name of display list
# @param[in] listPath graphic path of the gadget which contains the 
#                  display list
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc confirmPrint { printer  \
                                currentList \
                                listPath } {
 
    # Send command to related printer
    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN

    set dumpDirectory ""
    
    #find the name of the dump file
    set currentTime [ScsVisu::GetTime]
	set currentDate [clock format $currentTime -format %y%m%d%H%M%S]
    set dumpDirectory "$::HSCSCST::_PRINT_SAVE_PATH/"
    
    regsub -all {\\} $dumpDirectory / dumpDirectory
    regsub -all {&} $dumpDirectory "" dumpDirectory
    
    # if folder is type of the file, delete it 
	if { [file isfile $dumpDirectory] } {
		file delete -force $dumpDirectory
	}
	# If folder not exists, create it
	if { ![file exists $dumpDirectory] } {
		file mkdir $dumpDirectory
	}	
    
    regsub -all {&} $currentList "" currentList
    set dumpFile "${currentList}${currentDate}.dump"
    
    #define the column format of the dump
    set colFeatures [list]
    lappend colFeatures {AcquisitionDate 19} 
    lappend colFeatures {Location 4} 
    lappend colFeatures {System 3}  
    lappend colFeatures {Severity 3}  
    lappend colFeatures {Equipment 45} 
    lappend colFeatures {Text 100} 
    lappend colFeatures {Acknowledge 1} 
    lappend colFeatures {ProcFlag 1}
    
    #keep the printer information for the callback calls at the end of the dump DumpList action
    #8 = number of ::HSCSCST::_CSV_SEPARATOR for a line
    set sizeOfLine [expr 19 + 4 + 3 + 3 + 45 + 100 + 1 + 1 + 8]
    set headerFileName [createHeaderOfPrintFile $currentTime $dumpDirectory $currentList $colFeatures $sizeOfLine]
    #used by the dump callback to display information box
    set parentGP [::HSCSPanel::getParentGraphicPath $Scs::CurrentGraphicPath]
    #the column severity (column 3) is used to update color of printed lines
    set infoForColor 3
    ::HSCSPrinter::registerPrinterArgs ${dumpDirectory}/${dumpFile} [list $printer $headerFileName $parentGP $infoForColor]
    
    List::DumpList $listPath \
                            $dumpDirectory \
                            $dumpFile \
                            $::HSCSCST::_PRINT_SIZE_LIMIT\
                            $colFeatures\
                            0 0 0\
                            $::HSCSCST::_CSV_SEPARATOR
    
}

#-------------------------------------------------------------------
# createHeaderOfPrintFile
##
#prepare the header file, intended to print Alarm/Event list. 
#This header is added at the dump file which contains all
#current alarm of the display list

#-------------------------------------------------------------------
##
# @param[in] currentTime current time in seconds
# @param[in] dumpDirectory name of the folder that contains the file 
#used for the print
# @param[in] name of the list to print
# @param[in] colFeatures size and name of column to print (in print order)
# @param[in] sizeOfLine size of one line
# @param[out]  -
# @return  the name of the file which contains the header or "" 
#                in case of error

#-------------------------------------------------------------------
proc createHeaderOfPrintFile { currentTime\
                                                  dumpDirectory\
                                                  listName\
                                                  colFeatures\
                                                  sizeOfLine} {
                                                  
    ::HSCSTrace::io $::HSCSTrace::_PANEL_DOMAIN
    
    #header file
    set currentDate [clock format $currentTime -format "%y%m%d%H%M%S"]
    set currentDateForDisplay [clock format $currentTime -format "%y/%m/%d %H:%M:%S"]
    set fileName "$dumpDirectory/Header${listName}${currentDate}.txt"
    
	if {[catch {set fileID [open $fileName w]} errText]} {
        set errorMsg  [::HSCSLanguage::getDbMessage &msg::ErrorAccesFile]
        set errorMsg [format $errorMsg ${fileName}:$errText]
	   ::HSSCSPanel::warningBoxSubDialogFromCurrent $errorMsg
       set fileName ""
	} else {
        set title $listName
        set error [ catch {HSCSLanguage::getDbMessage "&msg::${listName}"} title]
        if  {0 != $error || 0 == [string compare $title ""]} {
            set title $listName
        } 
        
        #size of display line
        set displaySize $sizeOfLine
        set displayMiddle [expr $displaySize  / 2]
        
        puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}[string repeat # $displaySize]"
        #THALES = 8 characeres
        set middle [expr $displayMiddle + 3]
        #-1 for the first #
        set other [expr $displaySize - $middle -1]
        puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}#[format %${middle}s THALES][format %${other}s #]"
		puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}#[format %[expr $displaySize -1]s #]"
        
        #project name
        if {[info exists HSCSPrinter::_PROJECT_NAME]} {
        
            set projectName "$HSCSPrinter::_PROJECT_NAME[::HSCSLine::getLine]"
            set middle [expr $displayMiddle + [expr [string length $projectName] / 2]]
            #-1 for the first #
            set other [expr $displaySize - $middle -1]
            puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}#[format %${middle}s $projectName][format %${other}s #]"
        }
		puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}#[format %[expr $displaySize -1]s #]"
		puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}#[format %[expr $displaySize -1]s #]"
        
        #title of list to print
		set titleSize [string length $title]
        set middle [expr $displayMiddle + [expr $titleSize/ 2]]
        #-1 for the first #
        set other [expr $displaySize - $middle -1]
        set formatTitle "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}#[format %${middle}s $title][format %${other}s #]"
        puts $fileID $formatTitle
		puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}#[format %[expr $displaySize -1]s #]"
		puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}[string repeat # $displaySize]"
		puts $fileID ""	 
        
		# Compute and formatting Date
        set formatInfo "%-32s : %-50s"
        set formatDate [format $formatInfo [HSCSLanguage::getDbMessage "&msg::PrintDate"] $currentDateForDisplay]
	    puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT} $formatDate"	
		
        #Display operator name, location of the computer 
        set operatorProfile "[::HSCSProfile::getCurrentOperator]/[::HSCSProfile::getCurrentProfile]"
        set operatorProfileText [format $formatInfo [HSCSLanguage::getDbMessage "&msg::OperatorProfileName"] $operatorProfile]
        
        set computerLocation  [HSCSLanguage::getDbMessage "&msg::UnknownLocation"]
        if {[info exists ::HSCSCST::_LOCATION_LIST] } {
            if {0 == [string compare $::HSCSCST::_LOCATION_LIST($::HSCSCST::_CURRENT_LOCATION) "OCC"]} {
                #OCC location
                set computerLocation [HSCSLanguage::getDbMessage "&msg::OCCName"]
            } else {
                if {0 != [string compare $::HSCSCST::_CURRENT_STATION_NAME ""]} {
                    set currentStationTag "&$::HSCSCST::_CURRENT_STATION_NAME"
                    set computerLocation [HSCSLanguage::getDbMessage $currentStationTag]
                } 
            } 
        } 
        set computerLocationText   [format $formatInfo [HSCSLanguage::getDbMessage "&msg::ComputerLocation"] $computerLocation]
                            
        puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT} $operatorProfileText"  
		puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT} $computerLocationText"      
        
        puts $fileID ""	                                                 
		
        #details on filter
        puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}#[string repeat - [expr $displaySize - 2]]#"
        variable _filter
        if {0 == [array size _filter]} {
            set currentFilter [HSCSLanguage::getDbMessage "&msg::NoneF"]
        } else {
            set currentFilter ""
            foreach {name value} [array get _filter] {
                set name [HSCSLanguage::getDbMessage "&$name"]
                lappend currentFilter "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}   $name $value"
            }
            set currentFilter [join $currentFilter "\n"]
        }
        puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT} [HSCSLanguage::getDbMessage &msg::FilterDetail]"
        puts $fileID "$currentFilter"                                                   
        puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}#[string repeat - [expr $displaySize - 2]]#"
         
        puts $fileID ""	 
		
        puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}[string repeat # $displaySize]"
        
        #name and size of column
        set formatColName ""
        set colName [list]
        foreach col $colFeatures {
            set colSize [expr [lindex $col 1]  + [string length $::HSCSCST::_CSV_SEPARATOR]]
            set formatColName  "${formatColName}%-${colSize}s"
            
            set newColNameTag [lindex $col 0]
            set newColName  [HSCSLanguage::getDbMessage "&msg::Print${newColNameTag}"]
            if {0 == [string compare $newColName ""]} {
                set newColName  $newColNameTag
            }
            if {0 != [string compare $colName ""]} {
                set colName "$colName $newColName"
            } else {
                set colName "$newColName"
            }
        }
        
        set colText "format \"$formatColName\" $colName"
        set colText [eval $colText]
        puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}$colText"
		puts $fileID "${::HSCSPrinter::_PRINTER_TAG_DEFAULT}[string repeat # $displaySize]"
        
        close $fileID
    }
    
    return $fileName
}

#-------------------------------------------------------------------
# OnNoFilter
##
#callback of NoFilter button. This button permits to suppress
#all client filter.This is not the same thing that to allow all 
#possible values

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnNoFilter {} {

    variable _CRITICITIES_FILTER_KEYS_GADGET
    variable _ACKNOWLEDGE_FILTER_GADGET
    variable _STATION_FILTER_GADGET
    variable _FUNCTION_FILTER_GADGET
    variable _TYPE_FILTER_GADGET
    variable _START_TIME_FILTER_GADGET
    variable _END_TIME_FILTER_GADGET
    variable _TEXT_FILTER_GADGET

    set iNoFilter [ScsGet NoFilter.State]
    if { $iNoFilter == 1 } {
        set iGadgetState 0
    } else {
        set iGadgetState 1
    }
    
    set lstAllGadgets [concat $_CRITICITIES_FILTER_KEYS_GADGET \
                                              $_ACKNOWLEDGE_FILTER_GADGET \
                                              $_STATION_FILTER_GADGET \
                                              $_FUNCTION_FILTER_GADGET \
                                              $_TYPE_FILTER_GADGET \
                                              $_START_TIME_FILTER_GADGET \
                                              $_END_TIME_FILTER_GADGET \
                                              $_TEXT_FILTER_GADGET]

    foreach gadget $lstAllGadgets {
        ScsSet $gadget.Sensitive $iGadgetState
    }
    
    userModification 
    
}

#-------------------------------------------------------------------
# OnChangeState
##
#callback of acknowledge buttons, it is used to update the state 
#of reset and apply button after an user action

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnChangeState {} {

    userModification
    
}

#-------------------------------------------------------------------
# OnStationsFunctionEquipment
##
#callback of stations, functions or equipments list
#it is used to update the state 
#of reset and apply button after an user action

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnStationsFunctionEquipment {} {

    userModification
    
}

#-------------------------------------------------------------------
# OnStart_NoFilter
##
#callback of button which permits to inhibite the filter on 
#start date

#-------------------------------------------------------------------
##
# @param[in] applyFlag 1 if the callback is called by a user 
#action or directly by the panel. In the first case the button apply,
#reset can become selectable
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnStart_NoFilter { {applyFlag 1}} {

    variable _START_TIME_FILTER_GADGET

    set iNoFilter [ScsGet Start_NoFilter.State]
    if { $iNoFilter == 1 } {
        set iGadgetState 0
    } else {
        set iGadgetState 1
    }
    
    foreach gadget $_START_TIME_FILTER_GADGET {
        ScsSet $gadget.Sensitive $iGadgetState
    }
    
    if {$applyFlag == 1} {
       userModification
    } 
    
}

#-------------------------------------------------------------------
# OnEnd_NoFilter
##
#callback of button which permits to inhibite the filter on 
#end date

#-------------------------------------------------------------------
##
# @param[in] applyFlag 1 if the callback is called by a user 
#action or directly by the panel. In the first case the button apply,
#reset can become selectable
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnEnd_NoFilter { {applyFlag 1}} {

    variable _END_TIME_FILTER_GADGET

    set iNoFilter [ScsGet End_NoFilter.State]
    if { $iNoFilter == 1 } {
        set iGadgetState 0
    } else {
        set iGadgetState 1
    }
    
    foreach gadget $_END_TIME_FILTER_GADGET {
        ScsSet $gadget.Sensitive $iGadgetState
    }
    
    if {$applyFlag == 1} {
       userModification
    } 
    
}

#-------------------------------------------------------------------
# OnBtn_Start_Today
##
#callback of Start_Today button. This button permits to update 
#the start data of filter with the date of today

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnBtn_Start_Today {} {

    set now [ScsVisu::GetTime]
    
    #2 digits
    ScsSet Start_Year.Value  [clock format $now -format %Y]
    ScsSet Start_Month.Value  [clock format $now -format %m]
    ScsSet Start_Day.Value  [clock format $now -format %d]
    ScsSet Start_Hour.Value 00
    ScsSet Start_Minute.Value  00
    
    userModification
    
}

#-------------------------------------------------------------------
# OnBtn_End_Today
##
#callback of End_Today button. This button permits to update 
#the end data of filter with the date of today

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnBtn_End_Today {} {

    set now [ScsVisu::GetTime]
    
    #2 digits
    ScsSet End_Year.Value [clock format $now -format %Y]
    ScsSet End_Month.Value [clock format $now -format %m]
    ScsSet End_Day.Value [clock format $now -format %d]
    ScsSet End_Hour.Value 23
    ScsSet End_Minute.Value 59
    
    userModification
    
}

#-------------------------------------------------------------------
# OnChangeStartYearMonth
##
#callback of start date fields (year and month) it is used to update 
#the state of reset and apply button after an user action

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnChangeStartYearMonth {} {

    variable _oldStartDay

    set year [ScsGet Start_Year.Value]
    set month [ScsGet Start_Month.Value]
    set day [ScsGet Start_Day.Value]
    
    set newDayValue [onChangeYearMonth $year $month $day _oldStartDay]

    if {0 != [string compare $newDayValue ""]} {
        ScsSet Start_Day.Value $newDayValue
    }
    
}

#-------------------------------------------------------------------
# OnChangeEndYearMonth
##
#callback of end date fields (year and month) it is used to update 
#the state of reset and apply button after an user action

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnChangeEndYearMonth {} {

    variable _oldEndDay

    set year [ScsGet End_Year.Value]
    set month [ScsGet End_Month.Value]
    set day [ScsGet End_Day.Value]
    
    set newDayValue [onChangeYearMonth $year $month $day _oldEndDay]

    if {0 != [string compare $newDayValue ""]} {
        ScsSet End_Day.Value $newDayValue
    }
    
}

#-------------------------------------------------------------------
# onChangeYearMonth
##
#treatments of date fields it is used to update the state  of 
#date fields (year and month) it is used to update the state 
#of reset and apply button after an user action.It is called by
# the year and month gadgets callbacks.

#-------------------------------------------------------------------
##
# @param[in] year : current year to test
# @param[in] month : current month to test
# @param[in] day : current day to test
# @param[in]  oldDay : previous value of the day field
# @param[out]  oldDay : current value of the day field
# @return  the value of day if it changes ,"" otherwise

#-------------------------------------------------------------------
proc onChangeYearMonth { year \
                                              month\
                                              day \
                                              oldDay } {

    set newDayValue ""
    
    upvar $oldDay oldDayValue
    
    set check [format "%s/%s/%s 00:00:00" $month $day $year]
    
    if {[catch {clock scan $check} err]} {
        set okFlag 0
        while {!$okFlag} {
            set day [expr $day - 1] 
            
            if {[expr $day < 1]} {
                #impossible manage by the spin box, only possible with a month without day
                set day 31
            }
            
            set check [format "%s/%s/%s 00:00:00" $month $day $year]
            if {![catch {clock scan $check} err]} {
                set okFlag 1
            }
        } 
        
        set newDayValue $day
        set oldDayValue $day
            
    } 
    
    userModification
    
    return $newDayValue
    
}

#-------------------------------------------------------------------
# OnChangeStartDay
##
#callback of start day date field it is used to update the state 
#of reset and apply button after an user action

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnChangeStartDay {} {

    variable _oldStartDay
    
    set year [ScsGet Start_Year.Value]
    set month [ScsGet Start_Month.Value]
    set day [ScsGet Start_Day.Value]
    
    set newDayValue [onChangeDay $year $month $day _oldStartDay]
    
    if {0 != [string compare $newDayValue ""]} {
        ScsSet Start_Day.Value $newDayValue
    }
    
}

#-------------------------------------------------------------------
# OnChangeEndDay
##
#callback of start day date field it is used to update the state 
#of reset and apply button after an user action

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnChangeEndDay {} {

    variable _oldEndDay
    
    set year [ScsGet End_Year.Value]
    set month [ScsGet End_Month.Value]
    set day [ScsGet End_Day.Value]
    
    set newDayValue [onChangeDay $year $month $day _oldEndDay]
    
    if {0 != [string compare $newDayValue ""]} {
        ScsSet End_Day.Value $newDayValue
    }
    
}

#-------------------------------------------------------------------
# onChangeDay
##
#treatments of day date field it is used to update the state 
#of reset and apply button after an user action. It is called by
# the day gadget callbacks.

#-------------------------------------------------------------------
##
# @param[in] year : current year to test
# @param[in] month : current month to test
# @param[in] day : current day to test
# @param[in]  oldDay : previous value of the day field
# @param[out]  oldDay : current value of the day field
# @return  the value of day if it changes ,"" otherwise

#-------------------------------------------------------------------
proc onChangeDay {year \
                                 month\
                                 day \
                                 oldDay} {

    set newDayValue ""
    
    upvar $oldDay oldDayValue
    
    set check [format "%s/%s/%s 00:00:00" $month $day $year]
    
    if {[catch {clock scan $check} err]} {
        if {[expr $oldDayValue + 1] ==  $day} {
            #increase action
            set operation +1
        } else {
            #decrease action
            set operation -1
        }
        
        set okFlag 0
        while {!$okFlag} {
            set day [expr $day $operation]
            if {[expr $day > 31]} {
                set day 1
            } elseif {[expr $day < 1]} {
                #impossible manage by the spin box, only possible with a month without day
                set day 31
            }
            
            set check [format "%s/%s/%s 00:00:00" $month $day $year]
            if {![catch {clock scan $check} err]} {
                set okFlag 1
            }
        } 
        
        set newDayValue $day
    }
    #update the oldDay out parameter
    set oldDayValue $day
    
    userModification
    
    return $newDayValue
    
}

#-------------------------------------------------------------------
# OnChangeHour
##
#callback of hour fields it is used to update the state 
#of reset and apply button after an user action

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnChangeHour {} {

    userModification
    
}

#-------------------------------------------------------------------
# OnChangeFilterText
##
#callback of free text it is used to update the state 
#callback of free text it is used to update the state 
#of reset and apply button after an user action

#-------------------------------------------------------------------
##
# @param[in] -
# @param[out]  -
# @return  -

#-------------------------------------------------------------------
proc OnChangeFilterText {} {

    userModification
    
}


#-------------------------------------------------------------------
# call the user panel if it exist
#-------------------------------------------------------------------
 ::HSCSInitUserPanel::sourceUserPanel Alarm/HUSER_Alarm_Filter.tcl [namespace current]
