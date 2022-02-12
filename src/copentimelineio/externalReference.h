#pragma once

#include "copentime/timeRange.h"
#include "copentime/optionalOpenTime.h"
#include "anyDictionary.h"
#include "errorStatus.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct ExternalReference ExternalReference;

OTIO_API ExternalReference *ExternalReference_create(
        const char *target_url,
        OptionalTimeRange available_range,
        AnyDictionary *metadata);

OTIO_API const char *ExternalReference_target_url(ExternalReference *self);

OTIO_API void ExternalReference_set_target_url(
        ExternalReference *self, const char *target_url);

OTIO_API OptionalTimeRange ExternalReference_available_range(ExternalReference *self);

OTIO_API void ExternalReference_set_available_range(
        ExternalReference *self, OptionalTimeRange available_range);

OTIO_API bool ExternalReference_is_missing_reference(ExternalReference *self);

OTIO_API const char *ExternalReference_name(ExternalReference *self);

OTIO_API void ExternalReference_set_name(ExternalReference *self, const char *name);

OTIO_API AnyDictionary *ExternalReference_metadata(ExternalReference *self);

OTIO_API bool ExternalReference_to_json_file(
        ExternalReference *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);

OTIO_API const char *ExternalReference_to_json_string(
        ExternalReference *self, OTIOErrorStatus *error_status, int indent);

OTIO_API bool ExternalReference_is_equivalent_to(
        ExternalReference *self, OTIOSerializableObject *other);

OTIO_API ExternalReference *ExternalReference_clone(
        ExternalReference *self, OTIOErrorStatus *error_status);

OTIO_API const char *ExternalReference_schema_name(ExternalReference *self);

OTIO_API int ExternalReference_schema_version(ExternalReference *self);
