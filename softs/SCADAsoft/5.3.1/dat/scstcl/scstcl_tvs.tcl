################################################################################
#
# Namespace   : ScsTvs
# Description : Tcl API to send the commands to the subsytem 
#               "TVS" through the daccom "HBA"
#
################################################################################
#
# Author       : Vincent CHAU
# Creation     : 2012-06-14
# Modification :
#
################################################################################

namespace eval ScsTvs {
    
################################################################################
#
# Procedure   : init
# Returns     :
# Description : Initialize the component
#
################################################################################

    proc init {} {
        ScsCtl::init
    }
   
################################################################################
#
# Procedure   : end
# Returns     :
# Description : end the component
#
################################################################################

    proc end {} {
        ScsCtl::end
    }

################################################################################
#
# Procedure   : send
# Returns     :
# Description : common send command procedure
#
################################################################################

    proc send { CommandName CommandPoint Value CallbackProcedure } {
        global env SCSCTL_SIOV SCSCTL_BYPASS SCSCTL_SEND_ANYWAY
        
        ScsCtl::sendCommand $env(SCSSRVENVNAME) $CommandPoint \
            $SCSCTL_SIOV $Value $SCSCTL_BYPASS $SCSCTL_BYPASS $SCSCTL_SEND_ANYWAY $CallbackProcedure
            
        if { [ScsStatus::isValid] == False } {
            set err [ScsStatus::getText]
            error "proc send -- $CommandName -- $Value -- Error: $err ... \[Ko!\]"
        }
    }
   
################################################################################
#
# Procedure         : switchSingleCamera
# CommandPoint      : The absolute path, or the alias of the command point 
#                     in the dbserver. The command must be a "sio".
#                     Example : <alias>SITE_1VMSDMM001sioCom
# DMMLocation       : An integer value between 1 and 16 representing
#                     the position of the stream in the DMM layout.
# CameraId          : The shared identifier of the camera equipment
#                     between "SCS" and "TVS". Example : CAM001
# CallbackProcedure : The callback procedure to call once the command executed.
#                     CallbackProcedure="" means no callback.
# Returns           : none
# Description       : switch a single camera stream on a virtual monitor of
#                     a digital multiple monitor (DMM)
#
################################################################################

    proc switchSingleCamera { CommandPoint DMMLocation CameraId CallbackProcedure } {
        global env
        
        set Value ""
        append Value "objectIdList"
        append Value ";"
        append Value "$env(SCSENV)"
        append Value ";"
        append Value "CommandName"
        append Value ";"
        append Value "CommandCommutation"
        append Value ";"
        append Value "username"
        append Value ";"
        append Value "$env(USERNAME)"
        append Value ";"
        append Value "EqptId"
        append Value ";"
        append Value "$env(SCSENV)"
        append Value ";"
        append Value "DMMLoc"
        append Value ";"
        append Value "$DMMLocation"
        append Value ";"
        append Value "TypeCycle"
        append Value ";"
        append Value "0"
        append Value ";"
        append Value "IdCameraCycle"
        append Value ";"
        append Value "$CameraId"
        append Value "\0"
        
        if [ catch { ScsTvs::send switchSingleCamera $CommandPoint $Value $CallbackProcedure } ex ] {
            puts $ex
        }
    }
    
################################################################################
#
# Procedure         : switchPredefinedSequence
# CommandPoint      : The absolute path, or the alias of the command point 
#                     in the dbserver. The command must be a "sio".
#                     Example : <alias>SITE_1VMSDMM001sioCom
# DMMLocation       : An integer value between 1 and 16 representing
#                     the position of the stream in the DMM layout.
# SequenceId        : The shared sequence identifier
#                     between "SCS" and "TVS". Example : CYCLE-1
# CallbackProcedure : The callback procedure to call once the command executed.
#                     CallbackProcedure="" means no callback.
# Returns           : none
# Description       : switch a predefined cameras sequence (configured in "TVS") on a virtual 
#                     monitor of a digital multiple monitor (DMM)
#
################################################################################

    proc switchPredefinedSequence { CommandPoint DMMLocation SequenceId CallbackProcedure } {
        global env
        
        set Value ""
        append Value "objectIdList"
        append Value ";"
        append Value "$env(SCSENV)"
        append Value ";"
        append Value "CommandName"
        append Value ";"
        append Value "CommandCommutation"
        append Value ";"
        append Value "username"
        append Value ";"
        append Value "$env(USERNAME)"
        append Value ";"
        append Value "EqptId"
        append Value ";"
        append Value "$env(SCSENV)"
        append Value ";"
        append Value "DMMLoc"
        append Value ";"
        append Value "$DMMLocation"
        append Value ";"
        append Value "TypeCycle"
        append Value ";"
        append Value "2"
        append Value ";"
        append Value "IdCameraCycle"
        append Value ";"
        append Value "$SequenceId"
        append Value "\0"
        
        if [ catch { ScsTvs::send switchPredefinedSequence $CommandPoint $Value $CallbackProcedure } ex ] {
            puts $ex
        }
    }
    
################################################################################
#
# Procedure         : switchOnTheFlySequence
# CommandPoint      : The absolute path, or the alias of the command point 
#                     in the dbserver. The command must be a "sio".
#                     Example : <alias>SITE_1VMSDMM001sioCom
# DMMLocation       : An integer value between 1 and 16 representing
#                     the position of the stream in the DMM layout.
# CameraIdList      : The list of shared camera identifier
#                     between "SCS" and "TVS". The different cameras identifiers
#                     shall be separated by the character ','.
#                     Example : CAM001,CAM002,CAM003
# CallbackProcedure : The callback procedure to call once the command executed.
#                     CallbackProcedure="" means no callback.
# Returns           : none
# Description       : switch a sequence of cameras on the fly on a virtual 
#                     monitor of a digital multiple monitor (DMM)
#
################################################################################

    proc switchOnTheFlySequence { CommandPoint DMMLocation CameraIdList CallbackProcedure } {
        global env
        
        set Value ""
        append Value "objectIdList"
        append Value ";"
        append Value "$env(SCSENV)"
        append Value ";"
        append Value "CommandName"
        append Value ";"
        append Value "CommandCommutation"
        append Value ";"
        append Value "username"
        append Value ";"
        append Value "$env(USERNAME)"
        append Value ";"
        append Value "EqptId"
        append Value ";"
        append Value "$env(SCSENV)"
        append Value ";"
        append Value "DMMLoc"
        append Value ";"
        append Value "$DMMLocation"
        append Value ";"
        append Value "TypeCycle"
        append Value ";"
        append Value "1"
        append Value ";"
        append Value "IdCameraCycle"
        append Value ";"
        append Value "$CameraIdList"
        append Value "\0"
        
        if [ catch { ScsTvs::send switchOnTheFlySequence $CommandPoint $Value $CallbackProcedure } ex ] {
            puts $ex
        }
    }
   
################################################################################
#
# Procedure         : switchRecordedStream
# CommandPoint      : The absolute path, or the alias of the command point 
#                     in the dbserver. The command must be a "sio".
#                     Example : <alias>SITE_1VMSDMM001sioCom
# DMMLocation       : An integer value between 1 and 16 representing
#                     the position of the stream in the DMM layout.
# CameraId          : The shared identifier of the camera equipment
#                     between "SCS" and "TVS". Example : CAM001
# StartDateTime     : Start date time of the stream in second since 1970.
# Duration          : Duration of the stream in second, can be negative.
# CallbackProcedure : The callback procedure to call once the command executed.
#                     CallbackProcedure="" means no callback.
# Returns           : none
# Description       : switch a recorded stream on a stream player
#
################################################################################

    proc switchRecordedStream { CommandPoint DMMLocation CameraId StartDateTime Duration CallbackProcedure } {
        global env
        
        set Value ""
        append Value "objectIdList"
        append Value ";"
        append Value "$env(SCSENV)"
        append Value ";"
        append Value "CommandName"
        append Value ";"
        append Value "CommandCommutation"
        append Value ";"
        append Value "username"
        append Value ";"
        append Value "$env(USERNAME)"
        append Value ";"
        append Value "EqptId"
        append Value ";"
        append Value "$env(SCSENV)"
        append Value ";"
        append Value "DMMLoc"
        append Value ";"
        append Value "$DMMLocation"
        append Value ";"
        append Value "TypeCycle"
        append Value ";"
        append Value "3"
        append Value ";"
        append Value "IdCameraCycle"
        append Value ";"
        append Value "$CameraId"
        append Value ";"
        append Value "StartDateTime"
        append Value ";"
        append Value "$StartDateTime"
        append Value ";"
        append Value "Duration"
        append Value ";"
        append Value "$Duration"
        append Value "\0"
        
        if [ catch { ScsTvs::send switchRecordedStream $CommandPoint $Value $CallbackProcedure } ex ] {
            puts $ex
        }
    }
    
################################################################################
#
# Procedure         : switchClip
# CommandPoint      : The absolute path, or the alias of the command point 
#                     in the dbserver. The command must be a "sio".
#                     Example : <alias>SITE_1VMSDMM001sioCom
# DMMLocation       : An integer value between 1 and 16 representing
#                     the position of the stream in the DMM layout.
# EventId           : TThe identifier of the clip when creating the clip.
#                     Example : EVENT_1
# CallbackProcedure : The callback procedure to call once the command executed.
#                     CallbackProcedure="" means no callback.
# Description       : switch a clip on the video player.
#
################################################################################

    proc switchClip { CommandPoint DMMLocation EventId CallbackProcedure } {
        global env
        
        set Value ""
        append Value "objectIdList"
        append Value ";"
        append Value "$env(SCSENV)"
        append Value ";"
        append Value "CommandName"
        append Value ";"
        append Value "CommandCommutation"
        append Value ";"
        append Value "username"
        append Value ";"
        append Value "$env(USERNAME)"
        append Value ";"
        append Value "EqptId"
        append Value ";"
        append Value "$env(SCSENV)"
        append Value ";"
        append Value "DMMLoc"
        append Value ";"
        append Value "$DMMLocation"
        append Value ";"
        append Value "TypeCycle"
        append Value ";"
        append Value "4"
        append Value ";"
        append Value "IdCameraCycle"
        append Value ";"
        append Value "$EventId"
        append Value "\0"
        
        if [ catch { ScsTvs::send switchClip $CommandPoint $Value $CallbackProcedure } ex ] {
            puts $ex
        }
    }
    
################################################################################
#
# Procedure         : moveCamera
# CommandPoint      : The absolute path, or the alias of the command point 
#                     in the dbserver. The command must be a "sio".
#                     Example : <alias>SITE_1VMSDMM001sioCom
# CameraList        : The list of cameras to move on the same preset 
#                     separated by the character ','.
#                     Example : CAM001,CAM002                     
# PresetId          : The preset identifier as configured in "TVS" subsystem.
# CallbackProcedure : The callback procedure to call once the command executed.
#                     CallbackProcedure="" means no callback.
# Description       : Move one, or several cameras on a predefined preset.
#
################################################################################

    proc moveCamera { CommandPoint CameraList PresetId CallbackProcedure } {
        global env
        
        set Value ""
        append Value "objectIdList"
        append Value ";"
        append Value "$CameraList"
        append Value ";"
        append Value "CommandName"
        append Value ";"
        append Value "CommandPreset"
        append Value ";"
        append Value "ProfileName"
        append Value ";"
        append Value "$env(PROFILE)"
        append Value ";"
        append Value "username"
        append Value ";"
        append Value "$env(USERNAME)"
        append Value ";"
        append Value "PresetName"
        append Value ";"
        append Value "$PresetId"
        append Value ";"
        append Value "action"
        append Value ";"
        append Value "call"
        append Value "\0"
        
        if [ catch { ScsTvs::send moveCamera $CommandPoint $Value $CallbackProcedure } ex ] {
            puts $ex
        }
    }
    
################################################################################
#
# Procedure         : recordStream
# CommandPoint      : The absolute path, or the alias of the command point 
#                     in the dbserver. The command must be a "sio".
#                     Example : <alias>SITE_1VMSDMM001sioCom
# CameraList        : The list of cameras for recording
#                     separated by the character ','.
#                     Example : CAM001,CAM002                     
# EventId           : The event identifier associated to the record in order to 
#                     retrieve it further.
# StartDateTime     : Start date time of the stream in second since 1970.
# Duration          : Duration of the stream in second, can be negative.
# CallbackProcedure : The callback procedure to call once the command executed.
#                     CallbackProcedure="" means no callback.
# Description       : Request one, or several cameras to record during a given duration.
#
################################################################################

    proc recordStream { CommandPoint CameraList EventId StartDateTime Duration CallbackProcedure } {
        global env
        
        set Value ""
        append Value "objectIdList"
        append Value ";"
        append Value "$CameraList"
        append Value ";"
        append Value "CommandName"
        append Value ";"
        append Value "CommandCreateRecording"
        append Value ";"
        append Value "ProfileName"
        append Value ";"
        append Value "$env(PROFILE)"
        append Value ";"
        append Value "username"
        append Value ";"
        append Value "$env(USERNAME)"
        append Value ";"
        append Value "EventId"
        append Value ";"
        append Value "$EventId"
        append Value ";"
        append Value "StartDateTime"
        append Value ";"
        append Value "$StartDateTime"
        append Value ";"
        append Value "Duration"
        append Value ";"
        append Value "$Duration"
        append Value "\0"
        
        if [ catch { ScsTvs::send recordStream $CommandPoint $Value $CallbackProcedure } ex ] {
            puts $ex
        }
    }
    
###############################################################################
#
# Procedure         : activatePOI
# EquipmentPoint    : The equipment point associated to the point of interest (poi)
#                   : Example : <alias>SITE_1B002R001DO002
# CommandPoint      : The absolute path, or the alias of the command point 
#                     in the dbserver. The command must be a "sio".
#                     Example : <alias>SITE_1VMSDMM001sioCom
# DMMLocation       : An integer value between 1 and 16 representing
#                     the position of the stream in the DMM layout.
# CallbackProcedure : he callback procedure to call once the command executed.
#                     CallbackProcedure="" means no callback.
# Description       : 1- Read the attribute 'poi' of the equipment point,
#                     2- Read the attributes 'preset_list' and 'video_source_list'
#                        of the 'poi',
#                     3- Send 'moveCamera' commands depending on the value found in
#                        the attribute 'preset_list',
#                     4- Send 'switch' commands depending on the value found in
#                        the attribute 'video_source_list'.
#
################################################################################

    proc activatePOI { EquipmentPoint CommandPoint DMMLocation CallbackProcedure } {
        global env
        
        set db_point $EquipmentPoint
        append db_point ".poi"
        
        if [ catch { set poi [ScsDbm::read $env(SCSSRVENVNAME) $db_point] } ex ] {
            puts "proc activatePOI -- ScsDbm::read -- Error : $ex"
        }
        set poi [ lindex $poi 1 ]
    
        set poi_preset_list $poi
        append poi_preset_list ".preset_list"
        if [ catch { set preset_list [ScsDbm::read $env(SCSSRVENVNAME) $poi_preset_list] } ex ] {
           puts "proc activatePOI -- ScsDbm::read -- Error : $ex"
        }
    
        set preset_list [ lindex $preset_list 1   ]
        set preset_list [ lindex $preset_list 0   ]
        set preset_list [ lindex $preset_list 0   ]
        set preset_list [ split  $preset_list ";" ]
    
        set i 0
        while { $i<[llength $preset_list] } {
            set next [expr $i+1]
            set camera_list [lindex $preset_list $i]
            set preset_id [lindex $preset_list $next]
            if [ catch { ScsTvs::moveCamera $CommandPoint $camera_list $preset_id $CallbackProcedure } ex ] {
                puts "proc activatePOI -- ScsTvs::moveCamera -- Error : $ex"
                break
            }
            incr i +2
        }

        # Set 1 second tempo. before to send the next command ( i.e. a switch command )
        # because we send two commands on the same command point at the same time, 
        # and we need th return of the first command before to send the second one.
        after 1000
    
        set poi_video_source_list $poi
        append poi_video_source_list ".video_source_list"
    
        if [ catch { set poi_video_source_list [ScsDbm::read $env(SCSSRVENVNAME) $poi_video_source_list] } ex ] {
           puts "proc activatePOI -- ScsDbm::read -- Error : $ex"
        }
        
        set poi_video_source_list [ lindex $poi_video_source_list 1   ]
        set poi_video_source_list [ lindex $poi_video_source_list 0   ]
        set poi_video_source_list [ lindex $poi_video_source_list 0   ]
        set poi_video_source_list [ split  $poi_video_source_list ";" ]
    
        set i 0
        while { $i<[llength $poi_video_source_list] } {
            set next [expr $i+1]
            set procedure [lindex $poi_video_source_list $i]
            set video_source_id [lindex $poi_video_source_list $next]
            if [ catch { $procedure $CommandPoint $DMMLocation $video_source_id $CallbackProcedure } ex ] {
                puts "proc activatePOI -- $procedure -- Error : $ex"
                break
            }
            incr DMMLocation +1
            incr i +2
        }
    }

}

















