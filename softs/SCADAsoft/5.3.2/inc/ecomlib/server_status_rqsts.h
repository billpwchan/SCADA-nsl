/** @file server_status_rqsts.h */

#ifndef _SCS_ecomlib_SERVER_STATUS_RQSTS_H_
#define _SCS_ecomlib_SERVER_STATUS_RQSTS_H_

#include "ecomlib/physicallinkrqst.h"

namespace ecomlib
{
    class ECOMLIBIF_EXPORT GoOnlineRqst : public PhysicalLinkRqst
    {
    public:
        GoOnlineRqst() { }
        virtual ~GoOnlineRqst() { }
        void accept(PhysicalLinkRqstVisitorIF& visitor);

    private:
        GoOnlineRqst(const GoOnlineRqst&);
        GoOnlineRqst& operator=(const GoOnlineRqst&);
    };

    class ECOMLIBIF_EXPORT GoStandbyRqst : public PhysicalLinkRqst
    {
    public:
        GoStandbyRqst() { }
        virtual ~GoStandbyRqst() { }
        void accept(PhysicalLinkRqstVisitorIF& visitor);

    private:
        GoStandbyRqst(const GoStandbyRqst&);
        GoStandbyRqst& operator=(const GoStandbyRqst&);
    };
}

#endif // _SCS_ecomlib_SERVER_STATUS_RQSTS_H_
