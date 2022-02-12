#pragma once

#include "anyDictionary.h"
#include "composition.h"
#include "copentime/optionalOpenTime.h"
#include "errorStatus.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

extern const char *TransitionType_SMPTE_Dissolve;
extern const char *TransitionType_Custom;

typedef struct Transition Transition;

OTIO_API Transition *Transition_create(
        const char *name,
        const char *transition_type,
        OptionalRationalTime in_offset,
        OptionalRationalTime out_offset,
        AnyDictionary *metadata);
OTIO_API bool Transition_overlapping(Transition *self);
OTIO_API const char *Transition_transition_type(Transition *self);
OTIO_API void Transition_set_transition_type(
        Transition *self, const char *transition_type);
OTIO_API RationalTime Transition_in_offset(Transition *self);
OTIO_API void Transition_set_in_offset(Transition *self, RationalTime in_offset);
OTIO_API RationalTime Transition_out_offset(Transition *self);
OTIO_API void Transition_set_out_offset(Transition *self, RationalTime out_offset);
OTIO_API RationalTime
Transition_duration(Transition *self, OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange
Transition_range_in_parent(Transition *self,
                           OTIOErrorStatus *error_status);
OTIO_API OptionalTimeRange Transition_trimmed_range_in_parent(
        Transition *self,
        OTIOErrorStatus *error_status);
OTIO_API const char *Transition_name(Transition *self);
OTIO_API AnyDictionary *Transition_metadata(Transition *self);
OTIO_API Composition *Transition_parent(Transition *self);
OTIO_API bool Transition_visible(Transition *self);
OTIO_API void Transition_set_name(Transition *self, const char *name);
OTIO_API bool Transition_to_json_file(
        Transition *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);
OTIO_API const char *Transition_to_json_string(
        Transition *self, OTIOErrorStatus *error_status, int indent);
OTIO_API bool
Transition_is_equivalent_to(Transition *self, OTIOSerializableObject *other);
OTIO_API Transition *
Transition_clone(Transition *self, OTIOErrorStatus *error_status);
OTIO_API const char *Transition_schema_name(Transition *self);
OTIO_API int Transition_schema_version(Transition *self);
