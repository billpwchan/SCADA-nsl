#
#
# ---- Time Zone Procedures
#
#

namespace eval TimeZone {}

proc TimeZone::CreateTimeZone { pZoneName pFileName pTzOffset pAltOffset} {
	Scs_CreateTimeZone $pZoneName $pFileName $pTzOffset $pAltOffset
}

proc TimeZone::SetTimeZone { pZoneName } {
	Scs_ApplyTimeZone $pZoneName
}

proc TimeZone::SaveDSTRules { pZoneName } {
	Scs_SaveFileTimeZone $pZoneName
}

proc TimeZone::StartDST { pZoneName } {
	Scs_StartDSTTimeZone $pZoneName
}

proc TimeZone::EndDST { pZoneName } {
	Scs_EndDSTTimeZone $pZoneName
}
