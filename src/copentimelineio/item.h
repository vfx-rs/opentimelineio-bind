#pragma once

#include "anyDictionary.h"
#include "composition.h"
#include "copentime/rationalTime.h"
#include "copentime/timeRange.h"
#include "copentime/optionalOpenTime.h"
#include "effectRetainerVector.h"
#include "effectVector.h"
#include "errorStatus.h"
#include "markerRetainerVector.h"
#include "markerVector.h"

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct Item Item;
typedef struct Effect Effect;
typedef struct Marker Marker;

OTIO_API Item *
Item_create(
        const char *name,
        OptionalTimeRange source_range,
        AnyDictionary *metadata,
        EffectVector *effects,
        MarkerVector *markers);
OTIO_API bool Item_visible(Item *self);
OTIO_API bool Item_overlapping(Item *self);
OTIO_API OptionalTimeRange Item_source_range(Item *self);
OTIO_API void Item_set_source_range(Item *self, OptionalTimeRange source_range);
OTIO_API EffectRetainerVector *Item_effects(Item *self);
OTIO_API MarkerRetainerVector *Item_markers(Item *self);
OTIO_API RationalTime Item_duration(Item *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Item_available_range(Item *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Item_trimmed_range(Item *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Item_visible_range(Item *self, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange Item_trimmed_range_in_parent(Item *self,
                                           OTIOErrorStatus *error_status);
OTIO_API TimeRange Item_range_in_parent(Item *self, OTIOErrorStatus *error_status);
OTIO_API RationalTime Item_transformed_time(
        Item *self,
        RationalTime time,
        Item *to_item,
        OTIOErrorStatus *error_status);
OTIO_API TimeRange Item_transformed_time_range(
        Item *self,
        TimeRange time_range,
        Item *to_item,
        OTIOErrorStatus *error_status);
OTIO_API Composition *Item_parent(Item *self);
OTIO_API const char *Item_name(Item *self);
OTIO_API AnyDictionary *Item_metadata(Item *self);
OTIO_API void Item_set_name(Item *self, const char *name);
OTIO_API bool Item_to_json_file(
        Item *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);
OTIO_API const char *
Item_to_json_string(Item *self, OTIOErrorStatus *error_status, int indent);
OTIO_API bool Item_is_equivalent_to(Item *self, OTIOSerializableObject *other);
OTIO_API Item *Item_clone(Item *self, OTIOErrorStatus *error_status);
OTIO_API const char *Item_schema_name(Item *self);
OTIO_API int Item_schema_version(Item *self);
