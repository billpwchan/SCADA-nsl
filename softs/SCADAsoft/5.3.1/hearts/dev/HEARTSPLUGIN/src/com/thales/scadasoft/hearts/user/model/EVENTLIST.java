package com.thales.scadasoft.hearts.user.model;

/******************************************************************************/
/*  FILE  : EVENTLIST.java                                                    */
/*----------------------------------------------------------------------------*/
/*  COMPANY  : THALES SECURITY SOLUTIONS & SERVICES                           */
/*  CREATION DATE : 4 févr. 2011                                              */
/*  LANGUAGE  : JAVA                                                          */
/*............................................................................*/
/*  Copyright © T3S 1996-2011.                                                */
/*  All rights reserved.                                                      */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/******************************************************************************/

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Table;
import org.hibernate.annotations.Index;

import com.thales.scadasoft.hearts.core.model.DefaultPersistentObject;

/** 
 * Example : How to fix an index on several columns
 * @org.hibernate.annotations.Table( appliesTo = "EVENTLIST", 
 *		indexes   = {@Index(name="idx_eventlist_1", columnNames={"SCSTime","SCSTimeMicro"})} )
 */

@Entity
@Table( name = "EVENTLIST" )
public class EVENTLIST extends DefaultPersistentObject {

	/**
	 * Example : How to fix an index on a column
	 * @Index( name = "EVENTLIST_IDX_Severity" )
	 */
	private int AlarmId;

	/**
	 * 
	 */
	private long AutoId;

	/**
	 * 
	 */
	private int UserID;

	/**
	 * 
	 */
	private String EquipmentName;

	/**
	 * 
	 */
	private String Value;

	/**
	 * 
	 */
	private int ValueState;

	/**
	 * 
	 */
	private int AcknowledgeRequired;

	/**
	 * 
	 */
	@Index( name = "EVENTLIST_IDX_Severity" )
	private int Severity;

	/**
	 * 
	 */
	private int Shelve;

	/**
	 * 
	 */
	private int Hidden;

	/**
	 * 
	 */
	@Column( length = 512 ) 
	private String Message;
	
	/**
	 * 
	 */
	@Column( length = 512 )
	private String Message_br_BR;
	
	/**
	 * 
	 */
	@Column( length = 512 )
	private String Message_fr_FR;

	/**
	 * 
	 */
	private int Theme;

	/**
	 * 
	 */
	private Date EquipmentDate;

	/**
	 * 
	 */
	private long EquipmentDateMicro;

	/**
	 * 
	 */
	private Date AcquisitionDate;
	
	/**
	 * 
	 */
	private long AcquisitionDateMicro;

	/**
	 * 
	 */
	private int FunctionalCategory;

	/**
	 * 
	 */
	private int GeographicalCategory;

	/**
	 * 
	 */
	private String AckAutomatonPointer;

	/**
	 * 
	 */
	private String Environment;

	/**
	 * 
	 */
	private String User1;

	/**
	 * 
	 */
	private String User2;

	/**
	 * 
	 */
	private String DssEventType;
	
	/**
	 * 
	 */
	public EVENTLIST() {
	}

	/**
	 * 
	 */
	public String getAckAutomatonPointer() {
		return AckAutomatonPointer;
	}

	/**
	 * 
	 */
	public void setAckAutomatonPointer( String ackAutomatonPointer ) {
		AckAutomatonPointer = ackAutomatonPointer;
	}

	/**
	 * 
	 */
	public int getAcknowledgeRequired() {
		return AcknowledgeRequired;
	}
	
	/**
	 * 
	 */
	public void setAcknowledgeRequired( int acknowledgeRequired ) {
		AcknowledgeRequired = acknowledgeRequired;
	}

	/**
	 * 
	 */
	public Date getAcquisitionDate() {
		return AcquisitionDate;
	}

	/**
	 * 
	 */
	public void setAcquisitionDate( Date acquisitionDate ) {
		AcquisitionDate = acquisitionDate;
	}

	/**
	 * 
	 */
	public int getAlarmId() {
		return AlarmId;
	}

	/**
	 * 
	 */
	public void setAlarmId( int alarmId ) {
		AlarmId = alarmId;
	}

	/**
	 * 
	 */
	public long getAutoId() {
		return AutoId;
	}

	/**
	 * 
	 */
	public void setAutoId( long autoId ) {
		AutoId = autoId;
	}

	/**
	 * 
	 */
	public String getDssEventType() {
		return DssEventType;
	}

	/**
	 * 
	 */
	public void setDssEventType( String dssEventType ) {
		DssEventType = dssEventType;
	}

	/**
	 * 
	 */
	public String getEnvironment() {
		return Environment;
	}

	/**
	 * 
	 */
	public void setEnvironment( String environment ) {
		Environment = environment;
	}

	/**
	 * 
	 */
	public Date getEquipmentDate() {
		return EquipmentDate;
	}

	/**
	 * 
	 */
	public void setEquipmentDate( Date equipmentDate ) {
		EquipmentDate = equipmentDate;
	}

	/**
	 * 
	 */
	public String getEquipmentName() {
		return EquipmentName;
	}

	/**
	 * 
	 */
	public void setEquipmentName( String equipmentName ) {
		EquipmentName = equipmentName;
	}

	/**
	 * 
	 */
	public int getFunctionalCategory() {
		return FunctionalCategory;
	}

	/**
	 * 
	 */
	public void setFunctionalCategory( int functionalCategory ) {
		FunctionalCategory = functionalCategory;
	}

	/**
	 * 
	 */
	public int getGeographicalCategory() {
		return GeographicalCategory;
	}

	/**
	 * 
	 */
	public void setGeographicalCategory( int geographicalCategory ) {
		GeographicalCategory = geographicalCategory;
	}

	/**
	 * 
	 */
	public int getHidden() {
		return Hidden;
	}

	/**
	 * 
	 */
	public void setHidden( int hidden ) {
		Hidden = hidden;
	}

	/**
	 * 
	 */
	public String getMessage() {
		return Message;
	}

	/**
	 * 
	 */
	public void setMessage( String message ) {
		Message = message;
	}
	
	/**
	 * 
	 */
	public String getMessage_br_BR() {
		return Message_br_BR;
	}

	/**
	 * 
	 */
	public void setMessage_br_BR( String message_br_BR ) {
		Message_br_BR = message_br_BR;
	}
	
	/**
	 * 
	 */
	public String getMessage_fr_FR() {
		return Message_fr_FR;
	}

	/**
	 * 
	 */
	public void setMessage_fr_FR( String message_fr_FR ) {
		Message_fr_FR = message_fr_FR;
	}

	/**
	 * 
	 */
	public int getSeverity() {
		return Severity;
	}

	/**
	 * 
	 */
	public void setSeverity( int severity ) {
		Severity = severity;
	}

	/**
	 * 
	 */
	public int getShelve() {
		return Shelve;
	}

	/**
	 * 
	 */
	public void setShelve( int shelve ) {
		Shelve = shelve;
	}

	/**
	 * 
	 */
	public int getTheme() {
		return Theme;
	}

	/**
	 * 
	 */
	public void setTheme( int theme ) {
		Theme = theme;
	}

	/**
	 * 
	 */
	public String getUser1() {
		return User1;
	}

	/**
	 * 
	 */
	public void setUser1( String user1 ) {
		User1 = user1;
	}

	/**
	 * 
	 */
	public String getUser2() {
		return User2;
	}

	/**
	 * 
	 */
	public void setUser2( String user2 ) {
		User2 = user2;
	}

	/**
	 * 
	 */
	public int getUserID() {
		return UserID;
	}

	/**
	 * 
	 */
	public void setUserID( int userID ) {
		UserID = userID;
	}

	/**
	 * 
	 */
	public String getValue() {
		return Value;
	}

	/**
	 * 
	 */
	public void setValue( String value ) {
		Value = value;
	}

	/**
	 * 
	 */
	public int getValueState() {
		return ValueState;
	}

	/**
	 * 
	 */
	public void setValueState( int valueState ) {
		ValueState = valueState;
	}
	
	/**
	 * 
	 */
	public long getEquipmentDateMicro() {
		return EquipmentDateMicro;
	}

	/**
	 * 
	 */
	public void setEquipmentDateMicro( long equipmentDateMicro ) {
		EquipmentDateMicro = equipmentDateMicro;
	}

	/**
	 * 
	 */
	public long getAcquisitionDateMicro() {
		return AcquisitionDateMicro;
	}

	/**
	 * 
	 */
	public void setAcquisitionDateMicro( long acquisitionDateMicro ) {
		AcquisitionDateMicro = acquisitionDateMicro;
	}
	
	/**
	 * 
	 */
	@Override
	public String toString() {
		String mes = "EVENTLIST - (";
		mes += super.toString();
		mes += "AlarmId=" + AlarmId + ",";
		mes += "AutoId=" + AutoId + ",";
		mes += "UserID=" + UserID + ",";
		mes += "EquipmentName=" + EquipmentName + ",";
		mes += "Value=" + Value + ",";
		mes += "ValueState=" + ValueState + ",";
		mes += "AcknowledgeRequired=" + AcknowledgeRequired + ",";
		mes += "Severity=" + Severity + ",";
		mes += "Shelve=" + Shelve + ",";
		mes += "Hidden=" + Hidden + ",";
		mes += "Message=" + Message + ",";
		mes += "Theme=" + Theme + ",";
		mes += "EquipmentDate=" + EquipmentDate + ",";
		mes += "EquipmentDateMicro=" + EquipmentDateMicro + ",";
		mes += "AcquisitionDate=" + AcquisitionDate + ",";
		mes += "AcquisitionDateMicro=" + AcquisitionDateMicro + ",";
		mes += "FunctionalCategory=" + FunctionalCategory + ",";
		mes += "GeographicalCategory=" + GeographicalCategory + ",";
		mes += "AckAutomatonPointer=" + AckAutomatonPointer + ",";
		mes += "Environment=" + Environment + ",";
		mes += "User1=" + User1 + ",";
		mes += "User2=" + User2 + ",";
		mes += "DssEventType=" + DssEventType;
		mes += ")";
		return mes;
	}

}
