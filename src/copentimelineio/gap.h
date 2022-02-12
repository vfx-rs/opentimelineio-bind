#pragma once

#include "anyDictionary.h"
#include "composition.h"
#include "copentime/rationalTime.h"
#include "copentime/timeRange.h"
#include "effectRetainerVector.h"
#include "effectVector.h"
#include "item.h"
#include "markerRetainerVector.h"
#include "markerVector.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct Gap Gap;

OTIO_API Gap *Gap_create_with_source_range(
        OptionalTimeRange source_range,
        const char *name,
        EffectVector *effects,
        MarkerVector *markers,
        AnyDictionary *metadata);

OTIO_API Gap *Gap_create_with_duration(
        OptionalRationalTime duration,
        const char *name,
        EffectVector *effects,
        MarkerVector *markers,
        AnyDictionary *metadata);

OTIO_API bool Gap_visible(Gap *self);

OTIO_API bool Gap_overlapping(Gap *self);

OTIO_API OptionalTimeRange Gap_source_range(Gap *self);

OTIO_API void Gap_set_source_range(Gap *self, OptionalTimeRange source_range);

OTIO_API EffectRetainerVector *Gap_effects(Gap *self);

OTIO_API MarkerRetainerVector *Gap_markers(Gap *self);

OTIO_API RationalTime Gap_duration(Gap *self, OTIOErrorStatus *error_status);

OTIO_API TimeRange Gap_available_range(Gap *self, OTIOErrorStatus *error_status);

OTIO_API TimeRange Gap_trimmed_range(Gap *self, OTIOErrorStatus *error_status);

OTIO_API TimeRange Gap_visible_range(Gap *self, OTIOErrorStatus *error_status);

OTIO_API OptionalTimeRange Gap_trimmed_range_in_parent(Gap *self,
                                                       OTIOErrorStatus *error_status);

OTIO_API TimeRange Gap_range_in_parent(Gap *self, OTIOErrorStatus *error_status);

OTIO_API RationalTime Gap_transformed_time(
        Gap *self,
        RationalTime time,
        Item *to_item,
        OTIOErrorStatus *error_status);

OTIO_API TimeRange Gap_transformed_time_range(
        Gap *self,
        TimeRange time_range,
        Item *to_item,
        OTIOErrorStatus *error_status);

OTIO_API Composition *Gap_parent(Gap *self);

OTIO_API const char *Gap_name(Gap *self);

OTIO_API AnyDictionary *Gap_metadata(Gap *self);

OTIO_API void Gap_set_name(Gap *self, const char *name);

OTIO_API bool Gap_to_json_file(
        Gap *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);

OTIO_API const char *
Gap_to_json_string(Gap *self, OTIOErrorStatus *error_status, int indent);

OTIO_API bool Gap_is_equivalent_to(Gap *self, OTIOSerializableObject *other);

OTIO_API Gap *Gap_clone(Gap *self, OTIOErrorStatus *error_status);

OTIO_API const char *Gap_schema_name(Gap *self);

OTIO_API int Gap_schema_version(Gap *self);
