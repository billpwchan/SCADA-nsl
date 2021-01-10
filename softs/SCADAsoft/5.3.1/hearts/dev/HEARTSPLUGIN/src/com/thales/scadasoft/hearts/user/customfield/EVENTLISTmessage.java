package com.thales.scadasoft.hearts.user.customfield;

/******************************************************************************/
/*  FILE  : EVENTLISTmessage.java                                             */
/*----------------------------------------------------------------------------*/
/*  COMPANY  : THALES SECURITY SOLUTIONS & SERVICES                           */
/*  CREATION DATE : 1 févr. 2011                                              */
/*  LANGUAGE  : JAVA                                                          */
/*............................................................................*/
/*  Copyright © T3S 1996-2011.                                                */
/*  All rights reserved.                                                      */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/******************************************************************************/

import org.hibernate.Session;

import com.thales.scadasoft.hearts.core.model.ICustomField;
import com.thales.scadasoft.hearts.core.model.PersistentObject;
import com.thales.scadasoft.hearts.core.util.DBMHelper;
import com.thales.scadasoft.hearts.user.model.EVENTLIST;

/**
 * 
 */
public class EVENTLISTmessage implements ICustomField {
	
	/**
	 * 
	 */
	final static private String __BR__ = "br_BR";
	
	/**
	 * 
	 */
	final static private String __FR__ = "fr_FR"; 

	/**
	 * 
	 */
	@Override
	public void process( PersistentObject po, 
			String value, Session session, DBMHelper dbmHelper ) {
		EVENTLIST ev = (EVENTLIST)po;
		ev.setMessage( value );
		
		String[] values = value.split( "\\|" );
		if( values.length == 2 ) {
			String message = null;
			String key = values[0];
			String val = values[1];
			
			message = dbmHelper.getMessage(key, __BR__) + 
				" : " + dbmHelper.getMessage(val, __BR__);
			ev.setMessage_br_BR( message );
			
			message = dbmHelper.getMessage(key, __FR__) + 
				" : " + dbmHelper.getMessage(val, __FR__);
			ev.setMessage_fr_FR( message );
		}
	}

}
