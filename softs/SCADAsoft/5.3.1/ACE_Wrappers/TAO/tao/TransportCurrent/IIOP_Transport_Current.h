// -*- C++ -*-
// $Id: IIOP_Transport_Current.h 14 2007-02-01 15:49:12Z mitza $


#include "tao/TransportCurrent/TCC.h"
#include "tao/TransportCurrent/TC_IIOPC.h"
#include "tao/TransportCurrent/IIOP_Current_Loader.h"

#if defined (TAO_AS_STATIC_LIBS)

// Only do this for static builds. It causes a circular dependency for
// dynamic builds.
static int tao_iiop_transport_current_initializer_called =
  TAO::Transport::IIOP::current_static_initializer ();

#endif /* TAO_AS_STATIC_LIBS */

