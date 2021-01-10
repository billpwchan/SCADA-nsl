package com.thales.scadasoft.hearts.user.misc;

/******************************************************************************/
/*  FILE  : EVENTLIST_Parser.java                                             */
/*----------------------------------------------------------------------------*/
/*  COMPANY  : THALES SECURITY SOLUTIONS & SERVICES                           */
/*  CREATION DATE : 1 févr. 2011                                              */
/*  LANGUAGE  : JAVA                                                          */
/*............................................................................*/
/*  Copyright © T3S 1996-2011.                                                */
/*  All rights reserved.                                                      */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/******************************************************************************/

import java.util.Collection;
import java.util.Date;

import org.hibernate.Session;

import com.thales.scadasoft.hearts.core.exception.ParserErrorLineException;
import com.thales.scadasoft.hearts.core.model.AbstractParser;
import com.thales.scadasoft.hearts.core.model.PersistentObject;
import com.thales.scadasoft.hearts.core.util.DBMHelper;
import com.thales.scadasoft.hearts.core.util.ExtendScanner;
import com.thales.scadasoft.hearts.core.util.Keys;
import com.thales.scadasoft.hearts.core.util.Logger;
import com.thales.scadasoft.hearts.user.customfield.EVENTLISTmessage;
import com.thales.scadasoft.hearts.user.model.EVENTLIST;

/**
 * 
 */
public class EVENTLIST_Parser extends AbstractParser {
	
	/**
	 * 
	 */
	final static private String __TYPE__ = "EVENTLIST";
	
	/**
	 * 
	 */
	final static private int __NUMBER_OF_FIRST_SKIPPED_FIELDS__ = 2;
	
	/**
	 * 
	 */
	public EVENTLIST_Parser( DBMHelper dbmHelper ) {
		super( dbmHelper );
		factory = new EVENTLIST_Factory();
	}
	
	/**
	 * 
	 */
	@Override
	public String getType() {
		return __TYPE__;
	}

	/**
	 * 
	 */
	@SuppressWarnings("unused")
	protected void processLine( String aLine, Collection<PersistentObject> listObjects,
			Session session ) throws ParserErrorLineException {
		ExtendScanner scanner = new ExtendScanner( aLine );
		
		EVENTLIST pojo = null;
		synchronized( factory ) {
			pojo = (EVENTLIST)factory.create();
		}
		
		String brokenLine = "";
		int valInt        = 0;
		long valLong      = 0;
		float valFloat    = 0.0f;
		String valString  = "";
		Date valDate      = null;
		EVENTLISTmessage custom1 = new EVENTLISTmessage();
		
		try {
			while( scanner.hasNext() ) {
				brokenLine = "";
				for( int i=0; i<__NUMBER_OF_FIRST_SKIPPED_FIELDS__; i++ ) {
					valString = scanner.next();
					brokenLine += Keys.__BLANK__ + valString;
				}
				
				Logger.USER_PARSER.debug( "setAlarmId" );
				valInt = scanner.nextInt();
				pojo.setAlarmId( valInt );
				brokenLine += Keys.__BLANK__ + valInt;
				
				Logger.USER_PARSER.debug( "setAutoId" );
				valLong = scanner.nextLong();
				pojo.setAutoId( valLong );
				brokenLine += Keys.__BLANK__ + valLong;
				
				Logger.USER_PARSER.debug( "setUserID" );
				valInt = scanner.nextInt();
				pojo.setUserID( valInt );
				brokenLine += Keys.__BLANK__ + valInt;
				
				Logger.USER_PARSER.debug( "setEquipmentName" );
				valString = scanner.nextString();
				pojo.setEquipmentName( valString );
				brokenLine += Keys.__BLANK__ + valString;
				
				Logger.USER_PARSER.debug( "setValue" );
				valString = scanner.nextString();
				pojo.setValue( valString );
				brokenLine += Keys.__BLANK__ + valString;
				
				Logger.USER_PARSER.debug( "setValueState" );
				valInt = scanner.nextInt();
				pojo.setValueState( valInt );
				brokenLine += Keys.__BLANK__ + valInt;
				
				Logger.USER_PARSER.debug( "setAcknowledgeRequired" );
				valInt = scanner.nextInt();
				pojo.setAcknowledgeRequired( valInt );
				brokenLine += Keys.__BLANK__ + valInt;
				
				Logger.USER_PARSER.debug( "setSeverity" );
				valInt = scanner.nextInt();
				pojo.setSeverity( valInt );
				brokenLine += Keys.__BLANK__ + valInt;
				
				Logger.USER_PARSER.debug( "setShelve" );
				valInt = scanner.nextInt();
				pojo.setShelve( valInt );
				brokenLine += Keys.__BLANK__ + valInt;
				
				Logger.USER_PARSER.debug( "setHidden" );
				valInt = scanner.nextInt();
				pojo.setHidden( valInt );
				brokenLine += " " + valInt;
				
				Logger.USER_PARSER.debug( "CustomField - EVENTLISTmessage" );
				custom1.process( pojo, scanner.nextString(), session, dbmHelper );
				brokenLine += Keys.__BLANK__ + pojo.getMessage();
				
				Logger.USER_PARSER.debug( "setTheme" );
				valInt = scanner.nextInt();
				pojo.setTheme( valInt );
				brokenLine += Keys.__BLANK__ + valInt;
				
				Logger.USER_PARSER.debug( "setEquipmentDate" );
				valDate = scanner.nextDate();
				pojo.setEquipmentDate( valDate );
				brokenLine += Keys.__BLANK__ + valDate;
				
				Logger.USER_PARSER.debug( "setEquipmentDateMicro" );
				valLong = scanner.nextLong();
				pojo.setEquipmentDateMicro( valLong );
				brokenLine += Keys.__BLANK__ + valLong;
				
				Logger.USER_PARSER.debug( "setAcquisitionDate" );
				valDate = scanner.nextDate();
				pojo.setAcquisitionDate( valDate );
				brokenLine += Keys.__BLANK__ + valDate;
				
				Logger.USER_PARSER.debug( "setAcquisitionDateMicro" );
				valLong = scanner.nextLong();
				pojo.setAcquisitionDateMicro( valLong );
				brokenLine += Keys.__BLANK__ + valLong;
				
				Logger.USER_PARSER.debug( "setSCSTime" );
				valDate = scanner.nextDate();
				pojo.setSCSTime( valDate );
				brokenLine += Keys.__BLANK__ + valDate;
				
				Logger.USER_PARSER.debug( "setSCSTimeMicro" );
				valLong = scanner.nextLong();
				pojo.setSCSTimeMicro( valLong );
				brokenLine += Keys.__BLANK__ + valLong;
				
				Logger.USER_PARSER.debug( "setFunctionalCategory" );
				valInt = scanner.nextInt();
				pojo.setFunctionalCategory( valInt );
				brokenLine += Keys.__BLANK__ + valInt;
				
				Logger.USER_PARSER.debug( "setGeographicalCategory" );
				valInt = scanner.nextInt();
				pojo.setGeographicalCategory( valInt );
				brokenLine += Keys.__BLANK__ + valInt;
				
				Logger.USER_PARSER.debug( "setAckAutomatonPointer" );
				valString = scanner.nextString();
				pojo.setAckAutomatonPointer( valString );
				brokenLine += Keys.__BLANK__ + valString;
				
				Logger.USER_PARSER.debug( "setEnvironment" );
				valString = scanner.nextString();
				pojo.setEnvironment( valString );
				brokenLine += Keys.__BLANK__ + valString;
				
				Logger.USER_PARSER.debug( "setUser1" );
				valString = scanner.nextString();
				pojo.setUser1( valString );
				brokenLine += Keys.__BLANK__ + valString;
				
				Logger.USER_PARSER.debug( "setUser2" );
				valString = scanner.nextString();
				pojo.setUser2( valString );
				brokenLine += Keys.__BLANK__ + valString;
				
				Logger.USER_PARSER.debug( "setDssEventType" );
				valString = scanner.nextString();
				pojo.setDssEventType( valString );
				brokenLine += Keys.__BLANK__ + valString;
				
				break;
			}

			listObjects.add( pojo );
			Logger.USER_PARSER.debug( "Create POJO instanceof EVENTLIST - {}", pojo );
			
		} catch( Exception e ) {
			throw new ParserErrorLineException( brokenLine, e );
		} finally {
			scanner.close();
			scanner = null;
		}
	}

}
