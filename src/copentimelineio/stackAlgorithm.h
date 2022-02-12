#pragma once

#include "errorStatus.h"
#include "stack.h"
#include "track.h"
#include "trackVector.h"

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

OTIO_API Track *flatten_stack(Stack *in_stack, OTIOErrorStatus *error_status);

OTIO_API Track *flatten_stack_track_vector(
        TrackVector *tracks, OTIOErrorStatus *error_status);
