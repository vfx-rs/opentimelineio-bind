#pragma once

#include "anyDictionary.h"
#include "composition.h"
#include "copentime/timeRange.h"
#include "effectRetainerVector.h"
#include "errorStatus.h"
#include "item.h"
#include "markerRetainerVector.h"
#include "mediaReference.h"
#include "copentime/optionalOpenTime.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct Clip Clip;

OTIO_API Clip *Clip_create(
        const char *name,
        MediaReference *media_reference,
        OptionalTimeRange source_range,
        AnyDictionary *metadata);
OTIO_API void Clip_set_media_reference(Clip *self, MediaReference *media_reference);
OTIO_API MediaReference *Clip_media_reference(Clip *self);
OTIO_API TimeRange Clip_available_range(Clip *self, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange Clip_source_range(Clip *self);
OTIO_API void Clip_set_source_range(Clip *self, OptionalTimeRange source_range);
OTIO_API EffectRetainerVector *Clip_effects(Clip *self);
OTIO_API MarkerRetainerVector *Clip_markers(Clip *self);
OTIO_API RationalTime Clip_duration(Clip *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Clip_trimmed_range(Clip *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Clip_visible_range(Clip *self, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange Clip_trimmed_range_in_parent(Clip *self,
                                           OTIOErrorStatus *error_status);
OTIO_API TimeRange Clip_range_in_parent(Clip *self, OTIOErrorStatus *error_status);
OTIO_API RationalTime Clip_transformed_time(
        Clip *self,
        RationalTime time,
        Item *to_item,
        OTIOErrorStatus *error_status);
OTIO_API TimeRange Clip_transformed_time_range(
        Clip *self,
        TimeRange time_range,
        Item *to_item,
        OTIOErrorStatus *error_status);
OTIO_API bool Clip_visible(Clip *self);
OTIO_API bool Clip_overlapping(Clip *self);
OTIO_API Composition *Clip_parent(Clip *self);
OTIO_API const char *Clip_name(Clip *self);
OTIO_API AnyDictionary *Clip_metadata(Clip *self);
OTIO_API void Clip_set_name(Clip *self, const char *name);
OTIO_API bool Clip_to_json_file(
        Clip *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);
OTIO_API const char *
Clip_to_json_string(Clip *self, OTIOErrorStatus *error_status, int indent);
OTIO_API bool Clip_is_equivalent_to(Clip *self, OTIOSerializableObject *other);
OTIO_API Clip *Clip_clone(Clip *self, OTIOErrorStatus *error_status);
OTIO_API const char *Clip_schema_name(Clip *self);
OTIO_API int Clip_schema_version(Clip *self);
