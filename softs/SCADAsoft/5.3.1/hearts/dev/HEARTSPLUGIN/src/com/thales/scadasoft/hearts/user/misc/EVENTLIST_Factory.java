package com.thales.scadasoft.hearts.user.misc;

/******************************************************************************/
/*  FILE  : EVENTLIST_Factory.java                                            */
/*----------------------------------------------------------------------------*/
/*  COMPANY  : THALES SECURITY SOLUTIONS & SERVICES                           */
/*  CREATION DATE : 1 févr. 2011                                              */
/*  LANGUAGE  : JAVA                                                          */
/*............................................................................*/
/*  Copyright © T3S 1996-2011.                                                */
/*  All rights reserved.                                                      */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/******************************************************************************/

import com.thales.scadasoft.hearts.core.model.PersistentObject;
import com.thales.scadasoft.hearts.core.model.PersistentObjectFactory;
import com.thales.scadasoft.hearts.user.model.EVENTLIST;


/**
 * 
 */
public class EVENTLIST_Factory extends PersistentObjectFactory {

	/**
	 * 
	 */
	public EVENTLIST_Factory() {
	}

	/**
	 * 
	 */
	@Override
	protected PersistentObject newInstance() {
		return new EVENTLIST();
	}

}
