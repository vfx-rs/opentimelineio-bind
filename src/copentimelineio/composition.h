#pragma once

#include "anyDictionary.h"
#include "composable.h"
#include "composableRetainerVector.h"
#include "composableVector.h"
#include "copentime/timeRange.h"
#include "effectRetainerVector.h"
#include "effectVector.h"
#include "errorStatus.h"
#include "item.h"
#include "mapComposableTimeRange.h"
#include "markerRetainerVector.h"
#include "markerVector.h"
#include "optionalPairRationalTime.h"
#include "copentime/optionalOpenTime.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct Composition Composition;
typedef struct Item Item;

OTIO_API Composition *Composition_create(
        const char *name,
        OptionalTimeRange source_range,
        AnyDictionary *metadata,
        EffectVector *effects,
        MarkerVector *markers);
OTIO_API const char *Composition_composition_kind(Composition *self);
OTIO_API ComposableRetainerVector *Composition_children(Composition *self);
OTIO_API void Composition_clear_children(Composition *self);
OTIO_API bool Composition_set_children(
        Composition *self,
        ComposableVector *children,
        OTIOErrorStatus *error_status);
OTIO_API bool Composition_insert_child(
        Composition *self,
        int index,
        Composable *child,
        OTIOErrorStatus *error_status);
OTIO_API bool Composition_set_child(
        Composition *self,
        int index,
        Composable *child,
        OTIOErrorStatus *error_status);
OTIO_API bool Composition_remove_child(
        Composition *self, int index, OTIOErrorStatus *error_status);
OTIO_API bool Composition_append_child(
        Composition *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API bool Composition_is_parent_of(Composition *self, Composable *other);
OTIO_API OptionalPairRationalTime *Composition_handles_of_child(
        Composition *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API TimeRange Composition_range_of_child_at_index(
        Composition *self, int index, OTIOErrorStatus *error_status);
OTIO_API TimeRange Composition_trimmed_range_of_child_at_index(
        Composition *self, int index, OTIOErrorStatus *error_status);
OTIO_API TimeRange Composition_range_of_child(
        Composition *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange Composition_trimmed_range_of_child(
        Composition *self,
        Composable *child,
        OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange Composition_trim_child_range(Composition *self,
                                           TimeRange child_range);
OTIO_API bool Composition_has_child(Composition *self, Composable *child);

OTIO_API MapComposableTimeRange *Composition_range_of_all_children(
        Composition *self, OTIOErrorStatus *error_status);

OTIO_API bool Composition_visible(Composition *self);
OTIO_API bool Composition_overlapping(Composition *self);
OTIO_API OptionalTimeRange Composition_source_range(Composition *self);
OTIO_API void Composition_set_source_range(Composition *self, OptionalTimeRange source_range);
OTIO_API EffectRetainerVector *Composition_effects(Composition *self);
OTIO_API MarkerRetainerVector *Composition_markers(Composition *self);
OTIO_API RationalTime
Composition_duration(Composition *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Composition_available_range(
        Composition *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange
Composition_trimmed_range(Composition *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange
Composition_visible_range(Composition *self, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange Composition_trimmed_range_in_parent(
        Composition *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Composition_range_in_parent(
        Composition *self, OTIOErrorStatus *error_status);
OTIO_API RationalTime Composition_transformed_time(
        Composition *self,
        RationalTime time,
        Item *to_item,
        OTIOErrorStatus *error_status);
OTIO_API TimeRange Composition_transformed_time_range(
        Composition *self,
        TimeRange time_range,
        Item *to_item,
        OTIOErrorStatus *error_status);
OTIO_API Composition *Composition_parent(Composition *self);
OTIO_API const char *Composition_name(Composition *self);
OTIO_API AnyDictionary *Composition_metadata(Composition *self);
OTIO_API void Composition_set_name(Composition *self, const char *name);
OTIO_API bool Composition_to_json_file(
        Composition *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);
OTIO_API const char *Composition_to_json_string(
        Composition *self, OTIOErrorStatus *error_status, int indent);
OTIO_API bool
Composition_is_equivalent_to(Composition *self, OTIOSerializableObject *other);
OTIO_API Composition *
Composition_clone(Composition *self, OTIOErrorStatus *error_status);
OTIO_API const char *Composition_schema_name(Composition *self);
OTIO_API int Composition_schema_version(Composition *self);
