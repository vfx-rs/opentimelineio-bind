#pragma once

#include "copentime/timeRange.h"
#include "copentime/optionalOpenTime.h"
#include "anyDictionary.h"
#include "errorStatus.h"

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

OTIO_API const char *MarkerColor_pink;
OTIO_API const char *MarkerColor_red;
OTIO_API const char *MarkerColor_orange;
OTIO_API const char *MarkerColor_yellow;
OTIO_API const char *MarkerColor_green;
OTIO_API const char *MarkerColor_cyan;
OTIO_API const char *MarkerColor_blue;
OTIO_API const char *MarkerColor_purple;
OTIO_API const char *MarkerColor_magenta;
OTIO_API const char *MarkerColor_black;
OTIO_API const char *MarkerColor_white;
typedef struct RetainerMarker RetainerMarker;
typedef struct Marker Marker;

OTIO_API RetainerMarker *RetainerMarker_create(Marker *obj);
OTIO_API Marker *RetainerMarker_take_value(RetainerMarker *self);
OTIO_API Marker *RetainerMarker_value(RetainerMarker *self);
OTIO_API void RetainerMarker_managed_destroy(RetainerMarker *self);

OTIO_API Marker *Marker_create(
        const char *name,
        OptionalTimeRange marked_range,
        const char *color,
        AnyDictionary *metadata);
OTIO_API const char *Marker_color(Marker *self);
OTIO_API void Marker_set_color(Marker *self, const char *color);
OTIO_API TimeRange Marker_marked_range(Marker *self);
OTIO_API void Marker_set_marked_range(Marker *self, TimeRange marked_range);
OTIO_API const char *Marker_name(Marker *self);
OTIO_API void Marker_set_name(Marker *self, const char *name);
OTIO_API AnyDictionary *Marker_metadata(Marker *self);
OTIO_API bool Marker_to_json_file(
        Marker *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);
OTIO_API const char *Marker_to_json_string(
        Marker *self, OTIOErrorStatus *error_status, int indent);
OTIO_API bool Marker_is_equivalent_to(Marker *self, OTIOSerializableObject *other);
OTIO_API Marker *Marker_clone(Marker *self, OTIOErrorStatus *error_status);
OTIO_API const char *Marker_schema_name(Marker *self);
OTIO_API int Marker_schema_version(Marker *self);
