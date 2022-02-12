#pragma once

#include "anyDictionary.h"
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

typedef struct Stack Stack;

OTIO_API Stack *Stack_create(
        const char *name,
        OptionalTimeRange source_range,
        AnyDictionary *metadata,
        EffectVector *effects,
        MarkerVector *markers);
OTIO_API TimeRange Stack_range_of_child_at_index(
        Stack *self, int index, OTIOErrorStatus *error_status);
OTIO_API TimeRange Stack_trimmed_range_of_child_at_index(
        Stack *self, int index, OTIOErrorStatus *error_status);
OTIO_API TimeRange
Stack_available_range(Stack *self, OTIOErrorStatus *error_status);
OTIO_API MapComposableTimeRange *
Stack_range_of_all_children(Stack *self, OTIOErrorStatus *error_status);

OTIO_API const char *Stack_composition_kind(Stack *self);
OTIO_API ComposableRetainerVector *Stack_children(Stack *self);
OTIO_API void Stack_clear_children(Stack *self);
OTIO_API bool Stack_set_children(
        Stack *self, ComposableVector *children, OTIOErrorStatus *error_status);
OTIO_API bool Stack_insert_child(
        Stack *self,
        int index,
        Composable *child,
        OTIOErrorStatus *error_status);
OTIO_API bool Stack_set_child(
        Stack *self,
        int index,
        Composable *child,
        OTIOErrorStatus *error_status);
OTIO_API bool
Stack_remove_child(Stack *self, int index, OTIOErrorStatus *error_status);
OTIO_API bool Stack_append_child(
        Stack *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API bool Stack_is_parent_of(Stack *self, Composable *other);
OTIO_API OptionalPairRationalTime *Stack_handles_of_child(
        Stack *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API TimeRange Stack_range_of_child(
        Stack *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange Stack_trimmed_range_of_child(
        Stack *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange Stack_trim_child_range(Stack *self, TimeRange child_range);
OTIO_API bool Stack_has_child(Stack *self, Composable *child);

OTIO_API bool Stack_visible(Stack *self);
OTIO_API bool Stack_overlapping(Stack *self);
OTIO_API OptionalTimeRange Stack_source_range(Stack *self);
OTIO_API void Stack_set_source_range(Stack *self, OptionalTimeRange source_range);
OTIO_API EffectRetainerVector *Stack_effects(Stack *self);
OTIO_API MarkerRetainerVector *Stack_markers(Stack *self);
OTIO_API RationalTime Stack_duration(Stack *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Stack_trimmed_range(Stack *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Stack_visible_range(Stack *self, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange
Stack_trimmed_range_in_parent(Stack *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange
Stack_range_in_parent(Stack *self, OTIOErrorStatus *error_status);
OTIO_API RationalTime Stack_transformed_time(
        Stack *self,
        RationalTime time,
        Item *to_item,
        OTIOErrorStatus *error_status);
OTIO_API TimeRange Stack_transformed_time_range(
        Stack *self,
        TimeRange time_range,
        Item *to_item,
        OTIOErrorStatus *error_status);
OTIO_API Composition *Stack_parent(Stack *self);
OTIO_API const char *Stack_name(Stack *self);
OTIO_API AnyDictionary *Stack_metadata(Stack *self);
OTIO_API void Stack_set_name(Stack *self, const char *name);
OTIO_API bool Stack_to_json_file(
        Stack *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);
OTIO_API const char *Stack_to_json_string(
        Stack *self, OTIOErrorStatus *error_status, int indent);
OTIO_API bool Stack_is_equivalent_to(Stack *self, OTIOSerializableObject *other);
OTIO_API Stack *Stack_clone(Stack *self, OTIOErrorStatus *error_status);
OTIO_API const char *Stack_schema_name(Stack *self);
OTIO_API int Stack_schema_version(Stack *self);
