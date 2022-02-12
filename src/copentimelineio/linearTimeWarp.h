#pragma once

#include "anyDictionary.h"
#include "errorStatus.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct LinearTimeWarp LinearTimeWarp;

OTIO_API LinearTimeWarp *LinearTimeWarp_create(
        const char *name,
        const char *effect_name,
        double time_scalar,
        AnyDictionary *metadata);

OTIO_API double LinearTimeWarp_time_scalar(LinearTimeWarp *self);

OTIO_API void
LinearTimeWarp_set_time_scalar(LinearTimeWarp *self, double time_scalar);

OTIO_API const char *LinearTimeWarp_effect_name(LinearTimeWarp *self);

OTIO_API void LinearTimeWarp_set_effect_name(
        LinearTimeWarp *self, const char *effect_name);

OTIO_API const char *LinearTimeWarp_name(LinearTimeWarp *self);

OTIO_API void LinearTimeWarp_set_name(LinearTimeWarp *self, const char *name);

OTIO_API AnyDictionary *LinearTimeWarp_metadata(LinearTimeWarp *self);

OTIO_API bool LinearTimeWarp_to_json_file(
        LinearTimeWarp *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);

OTIO_API const char *LinearTimeWarp_to_json_string(
        LinearTimeWarp *self, OTIOErrorStatus *error_status, int indent);

OTIO_API bool LinearTimeWarp_is_equivalent_to(
        LinearTimeWarp *self, OTIOSerializableObject *other);

OTIO_API LinearTimeWarp *
LinearTimeWarp_clone(LinearTimeWarp *self, OTIOErrorStatus *error_status);

OTIO_API const char *LinearTimeWarp_schema_name(LinearTimeWarp *self);

OTIO_API int LinearTimeWarp_schema_version(LinearTimeWarp *self);
