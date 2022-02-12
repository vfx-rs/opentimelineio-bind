#pragma once

#include "anyDictionary.h"
#include "composable.h"
#include "composableRetainerVector.h"
#include "composableVector.h"
#include "copentime/timeRange.h"
#include "effectRetainerVector.h"
#include "errorStatus.h"
#include "item.h"
#include "mapComposableTimeRange.h"
#include "markerRetainerVector.h"
#include "optionalPairRationalTime.h"
#include "retainerPairComposable.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct Track Track;

typedef enum {
    OTIO_Track_NeighbourGapPolicy_never = 0,
    OTIO_Track_NeighbourGapPolicy_around_transitions = 1,
} OTIO_Track_NeighbourGapPolicy_;
typedef int OTIO_Track_NeighbourGapPolicy;

OTIO_API const char *TrackKind_Video;
OTIO_API const char *TrackKind_Audio;

OTIO_API Track *Track_create(
        const char *name,
        OptionalTimeRange source_range,
        const char *kind,
        AnyDictionary *metadata);
OTIO_API const char *Track_kind(Track *self);
OTIO_API void Track_set_kind(Track *self, const char *kind);
OTIO_API TimeRange Track_range_of_child_at_index(
        Track *self, int index, OTIOErrorStatus *error_status);
OTIO_API TimeRange Track_trimmed_range_of_child_at_index(
        Track *self, int index, OTIOErrorStatus *error_status);
OTIO_API TimeRange
Track_available_range(Track *self, OTIOErrorStatus *error_status);
OTIO_API OptionalPairRationalTime *Track_handles_of_child(
        Track *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API RetainerPairComposable *Track_neighbors_of(
        Track *self,
        Composable *item,
        OTIOErrorStatus *error_status,
        OTIO_Track_NeighbourGapPolicy insert_gap);
OTIO_API ComposableVector *Track_each_clip(Track *self);
OTIO_API MapComposableTimeRange *
Track_range_of_all_children(Track *self, OTIOErrorStatus *error_status);

OTIO_API const char *Track_composition_kind(Track *self);
OTIO_API ComposableRetainerVector *Track_children(Track *self);
OTIO_API void Track_clear_children(Track *self);
OTIO_API bool Track_set_children(
        Track *self, ComposableVector *children, OTIOErrorStatus *error_status);
OTIO_API bool Track_insert_child(
        Track *self,
        int index,
        Composable *child,
        OTIOErrorStatus *error_status);
OTIO_API bool Track_set_child(
        Track *self,
        int index,
        Composable *child,
        OTIOErrorStatus *error_status);
OTIO_API bool
Track_remove_child(Track *self, int index, OTIOErrorStatus *error_status);
OTIO_API bool Track_append_child(
        Track *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API bool Track_is_parent_of(Track *self, Composable *other);
OTIO_API TimeRange Track_range_of_child(
        Track *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange Track_trimmed_range_of_child(
        Track *self, Composable *child, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange Track_trim_child_range(Track *self, TimeRange child_range);
OTIO_API bool Track_has_child(Track *self, Composable *child);
OTIO_API bool Track_visible(Track *self);
OTIO_API bool Track_overlapping(Track *self);
OTIO_API OptionalTimeRange Track_source_range(Track *self);
OTIO_API void Track_set_source_range(Track *self, OptionalTimeRange source_range);
OTIO_API EffectRetainerVector *Track_effects(Track *self);
OTIO_API MarkerRetainerVector *Track_markers(Track *self);
OTIO_API RationalTime Track_duration(Track *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange
Track_available_range(Track *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Track_trimmed_range(Track *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange Track_visible_range(Track *self, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange
Track_trimmed_range_in_parent(Track *self, OTIOErrorStatus *error_status);
OTIO_API TimeRange
Track_range_in_parent(Track *self, OTIOErrorStatus *error_status);
OTIO_API RationalTime Track_transformed_time(
        Track *self,
        RationalTime time,
        Item *to_item,
        OTIOErrorStatus *error_status);
OTIO_API TimeRange Track_transformed_time_range(
        Track *self,
        TimeRange time_range,
        Item *to_item,
        OTIOErrorStatus *error_status);
OTIO_API Composition *Track_parent(Track *self);
OTIO_API const char *Track_name(Track *self);
OTIO_API AnyDictionary *Track_metadata(Track *self);
OTIO_API void Track_set_name(Track *self, const char *name);
OTIO_API bool Track_to_json_file(
        Track *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);
OTIO_API const char *Track_to_json_string(
        Track *self, OTIOErrorStatus *error_status, int indent);
OTIO_API bool Track_is_equivalent_to(Track *self, OTIOSerializableObject *other);
OTIO_API Track *Track_clone(Track *self, OTIOErrorStatus *error_status);
OTIO_API const char *Track_schema_name(Track *self);
OTIO_API int Track_schema_version(Track *self);
