#pragma once

#include "anyDictionary.h"
#include "copentime/optionalOpenTime.h"
#include "errorStatus.h"
#include "stack.h"
#include "trackVector.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct Timeline Timeline;

OTIO_API Timeline *Timeline_create(
        const char *name,
        OptionalRationalTime global_start_time,
        AnyDictionary *metadata);
OTIO_API Stack *Timeline_tracks(Timeline *self);
OTIO_API void Timeline_set_tracks(Timeline *self, Stack *stack);
OTIO_API OptionalRationalTime Timeline_global_start_time(Timeline *self);
OTIO_API void Timeline_set_global_start_time(
        Timeline *self, OptionalRationalTime global_start_time);
OTIO_API RationalTime
Timeline_duration(Timeline *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Timeline_range_of_child(
        Timeline *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API TrackVector *Timeline_audio_tracks(Timeline *self);
OTIO_API TrackVector *Timeline_video_tracks(Timeline *self);
OTIO_API const char *Timeline_name(Timeline *self);
OTIO_API void Timeline_set_name(Timeline *self, const char *name);
OTIO_API AnyDictionary *Timeline_metadata(Timeline *self);
OTIO_API bool Timeline_to_json_file(
        Timeline *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);
OTIO_API const char *Timeline_to_json_string(
        Timeline *self, OTIOErrorStatus *error_status, int indent);
OTIO_API bool Timeline_is_equivalent_to(Timeline *self, OTIOSerializableObject *other);
OTIO_API Timeline *Timeline_clone(Timeline *self, OTIOErrorStatus *error_status);
OTIO_API bool Timeline_is_unknown_schema(Timeline *self);
OTIO_API const char *Timeline_schema_name(Timeline *self);
OTIO_API int Timeline_schema_version(Timeline *self);
