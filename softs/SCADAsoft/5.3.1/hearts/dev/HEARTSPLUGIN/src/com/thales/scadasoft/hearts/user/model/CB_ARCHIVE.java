package com.thales.scadasoft.hearts.user.model;

/******************************************************************************/
/*  FILE  : CB_ARCHIVE.java                                                   */
/*----------------------------------------------------------------------------*/
/*  COMPANY  : THALES SECURITY SOLUTIONS & SERVICES                           */
/*  CREATION DATE : 25 févr. 2011                                             */
/*  LANGUAGE  : JAVA                                                          */
/*............................................................................*/
/*  Copyright © T3S 1996-2011.                                                */
/*  All rights reserved.                                                      */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/******************************************************************************/

import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Table;

import com.thales.scadasoft.hearts.core.model.DefaultPersistentObject;

/**
 * 
 */
@Entity
@Table( name = "CB_ARCHIVE" )
public class CB_ARCHIVE extends DefaultPersistentObject {

	/**
	 * 
	 */
	private String Name;
	
	/**
	 * 
	 */
	private int ValueType;
	
	/**
	 * 
	 */
	private String Value;
	
	/**
	 * 
	 */
	private int Quality;
	
	/**
	 * 
	 */
	private Date Timestamp;
	
	/**
	 * 
	 */
	private long TimestampMicro;

	/**
	 * 
	 */
	public CB_ARCHIVE() {
	}
	
	/**
	 * 
	 */
	public String getName() {
		return Name;
	}

	/**
	 * 
	 */
	public void setName( String name ) {
		Name = name;
	}

	/**
	 * 
	 */
	public int getValueType() {
		return ValueType;
	}

	/**
	 * 
	 */
	public void setValueType( int valueType ) {
		ValueType = valueType;
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
	public int getQuality() {
		return Quality;
	}

	/**
	 * 
	 */
	public void setQuality( int quality ) {
		Quality = quality;
	}

	/**
	 * 
	 */
	public Date getTimestamp() {
		return Timestamp;
	}

	/**
	 * 
	 */
	public void setTimestamp( Date timestamp ) {
		Timestamp = timestamp;
	}
	
	/**
	 * 
	 */
	public long getTimestampMicro() {
		return TimestampMicro;
	}

	/**
	 * 
	 */
	public void setTimestampMicro( long timestampMicro ) {
		TimestampMicro = timestampMicro;
	}

	/**
	 * 
	 */
	@Override
	public String toString() {
		String mes = "CB_ARCHIVE - (";
		mes += super.toString();
		mes += "Name=" + Name + ",";
		mes += "ValueType=" + ValueType + ",";
		mes += "Value=" + Value + ",";
		mes += "Quality=" + Quality + ",";
		mes += "Timestamp=" + Timestamp + ",";
		mes += "TimestampMicro=" + TimestampMicro;
		mes += ")";
		return mes;
	}

}
