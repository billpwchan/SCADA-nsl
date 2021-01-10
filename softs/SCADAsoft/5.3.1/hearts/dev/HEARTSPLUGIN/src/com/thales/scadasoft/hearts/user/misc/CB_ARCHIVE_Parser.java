package com.thales.scadasoft.hearts.user.misc;

/******************************************************************************/
/*  FILE  : CB_ARCHIVE_Parser.java                                            */
/*----------------------------------------------------------------------------*/
/*  COMPANY  : THALES SECURITY SOLUTIONS & SERVICES                           */
/*  CREATION DATE : 25 févr. 2011                                             */
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

import com.thales.scadasoft.hearts.user.model.CB_ARCHIVE;

/**
 * 
 */
public class CB_ARCHIVE_Parser extends AbstractParser {
	
	/**
	 * 
	 */
	final static private String __TYPE__ = "CB_ARCHIVE";
	
	/**
	 * 
	 */
	final static private int __NUMBER_OF_FIRST_SKIPPED_FIELDS__ = 2;
	
	/**
	 * 
	 */
	public CB_ARCHIVE_Parser( DBMHelper dbmHelper ) {
		super( dbmHelper );
		factory = new CB_ARCHIVE_Factory();
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
		
		CB_ARCHIVE pojo = null;
		synchronized( factory ) {
			pojo = (CB_ARCHIVE)factory.create();
		}
		
		String brokenLine = "";
		int valInt        = 0;
		long valLong      = 0;
		float valFloat    = 0.0f;
		String valString  = "";
		Date valDate      = null;
		
		try {
			while( scanner.hasNext() ) {
				brokenLine = "";
				for( int i=0; i<__NUMBER_OF_FIRST_SKIPPED_FIELDS__; i++ ) {
					valString = scanner.next();
					brokenLine += Keys.__BLANK__ + valString;
				}
				
				Logger.USER_PARSER.debug( "setSCSTime" );
				valDate = scanner.nextDate();
				pojo.setSCSTime( valDate );
				brokenLine += Keys.__BLANK__ + valDate;
				
				Logger.USER_PARSER.debug( "setSCSTimeMicro" );
				valLong = scanner.nextLong();
				pojo.setSCSTimeMicro( valLong );
				brokenLine += Keys.__BLANK__ + valLong;
				
				Logger.USER_PARSER.debug( "setName" );
				valString = scanner.nextString();
				pojo.setName( valString );
				brokenLine += Keys.__BLANK__ + valString;
				
				Logger.USER_PARSER.debug( "setValueType" );
				valInt = scanner.nextInt();
				pojo.setValueType( valInt );
				brokenLine += Keys.__BLANK__ + valInt;
				
				Logger.USER_PARSER.debug( "setValue" );
				valString = scanner.nextString();
				pojo.setValue( valString );
				brokenLine += Keys.__BLANK__ + valString;
				
				Logger.USER_PARSER.debug( "setQuality" );
				valInt = scanner.nextInt();
				pojo.setQuality( valInt );
				brokenLine += Keys.__BLANK__ + valInt;
				
				Logger.USER_PARSER.debug( "setTimestamp" );
				valDate = scanner.nextDate();
				pojo.setTimestamp( valDate );
				brokenLine += Keys.__BLANK__ + valDate;
				
				Logger.USER_PARSER.debug( "setTimestampMicro" );
				valLong = scanner.nextLong();
				pojo.setTimestampMicro( valLong );
				brokenLine += Keys.__BLANK__ + valLong;
					
				break;
			}

			listObjects.add( pojo );
			Logger.USER_PARSER.debug( "Create POJO instanceof CB_ARCHIVE - {}", pojo );
			
		} catch( Exception e ) {
			throw new ParserErrorLineException( brokenLine, e );
		} finally {
			scanner.close();
			scanner = null;
		}
	}

}
