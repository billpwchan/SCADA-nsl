package com.thales.scadasoft.hearts.user;

/******************************************************************************/
/*  FILE  : Tables.java                                                       */
/*----------------------------------------------------------------------------*/
/*  COMPANY  : THALES SECURITY SOLUTIONS & SERVICES                           */
/*  CREATION DATE : 25 févr. 2011                                             */
/*  LANGUAGE  : JAVA                                                          */
/*............................................................................*/
/*  Copyright © T3S 1996-2011.                                                */
/*  All rights reserved.                                                      */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/******************************************************************************/

import com.thales.scadasoft.hearts.user.model.CB_ARCHIVE;
import com.thales.scadasoft.hearts.user.model.EVENTLIST;


/**
 * 
 */
@SuppressWarnings("rawtypes")
public class Tables {
	
	/**
	 * 
	 */
	final static public Class[] __CLASS_LIST__ = {
		EVENTLIST.class,
		CB_ARCHIVE.class,
	};
	
	/**
	 * 
	 */
	final static public Object[][] __ARCHIVE_LIST__ = {
		{ "EventListHis", 2 },
		{ "CB_ARCHIVE"  , 3 },
	};

}
