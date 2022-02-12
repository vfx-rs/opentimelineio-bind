#pragma once

#include "copentime/timeRange.h"
#include "errorStatus.h"
#include "track.h"

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

OTIO_API Track *track_trimmed_to_range(
        Track *in_track, TimeRange trim_range, OTIOErrorStatus *error_status);