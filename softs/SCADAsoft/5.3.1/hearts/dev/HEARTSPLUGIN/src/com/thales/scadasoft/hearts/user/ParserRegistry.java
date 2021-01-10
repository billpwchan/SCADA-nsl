package com.thales.scadasoft.hearts.user;

/******************************************************************************/
/*  FILE  : ParserRegistry.java                                               */
/*----------------------------------------------------------------------------*/
/*  COMPANY  : THALES SECURITY SOLUTIONS & SERVICES                           */
/*  CREATION DATE : 1 févr. 2011                                              */
/*  LANGUAGE  : JAVA                                                          */
/*............................................................................*/
/*  Copyright © T3S 1996-2011.                                                */
/*  All rights reserved.                                                      */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/******************************************************************************/

import java.util.HashMap;
import java.util.Map;
import java.util.Observer;

import com.thales.scadasoft.hearts.core.exception.ParserNotFoundException;
import com.thales.scadasoft.hearts.core.model.AbstractParser;
import com.thales.scadasoft.hearts.core.model.IParser;
import com.thales.scadasoft.hearts.core.util.DBMHelper;
import com.thales.scadasoft.hearts.user.misc.CB_ARCHIVE_Parser;
import com.thales.scadasoft.hearts.user.misc.EVENTLIST_Parser;

/**
 * 
 */
public class ParserRegistry {

	/**
	 * 
	 */
	private Observer reportGenerationObserver;
	
	/**
	 * 
	 */
	private Map<String, IParser> parsers = null;
	
	/**
	 * 
	 */
	public ParserRegistry( DBMHelper dbmHelper, 
			Observer reportGenerationObserver ) {
		this.reportGenerationObserver = reportGenerationObserver;
		parsers = new HashMap<String, IParser>();
		registerAll( dbmHelper );
	}
	
	/**
	 *
	 */
	private void registerAll( DBMHelper dbmHelper ) {
		AbstractParser parser = new EVENTLIST_Parser( dbmHelper );
		parser.addObserver( reportGenerationObserver );
		register( "EventListHis", parser );
		
		parser = new CB_ARCHIVE_Parser( dbmHelper );
		parser.addObserver( reportGenerationObserver );
		register( "CB_ARCHIVE", parser );
		
		// ...
		// ...
	}
	
	/**
	 * 
	 */
	public IParser getParser( String type ) 
					throws ParserNotFoundException {
		if( parsers.containsKey(type) ) {
			return parsers.get( type );
		} else {
			throw new ParserNotFoundException( type );
		}
	}
	
	/**
	 * 
	 */
	private void register( String type, IParser parser ) {
		parsers.put( type, parser );
	}
	
}
