package com.thales.scadasoft.hearts.user.misc;

/******************************************************************************/
/*  FILE  : CB_ARCHIVE_Factory.java                                           */
/*----------------------------------------------------------------------------*/
/*  COMPANY  : THALES SECURITY SOLUTIONS & SERVICES                           */
/*  CREATION DATE : 25 févr. 2011                                             */
/*  LANGUAGE  : JAVA                                                          */
/*............................................................................*/
/*  Copyright © T3S 1996-2011.                                                */
/*  All rights reserved.                                                      */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/******************************************************************************/

import com.thales.scadasoft.hearts.core.model.PersistentObject;
import com.thales.scadasoft.hearts.core.model.PersistentObjectFactory;
import com.thales.scadasoft.hearts.user.model.CB_ARCHIVE;

/**
 * 
 */
public class CB_ARCHIVE_Factory extends PersistentObjectFactory {

	/**
	 * 
	 */
	public CB_ARCHIVE_Factory() {
	}

	/**
	 * 
	 */
	@Override
	protected PersistentObject newInstance() {
		return new CB_ARCHIVE();
	}

}
