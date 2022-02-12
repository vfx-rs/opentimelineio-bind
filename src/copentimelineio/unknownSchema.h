#pragma once

#include "errorStatus.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct UnknownSchema UnknownSchema;

OTIO_API UnknownSchema *UnknownSchema_create(
        const char *original_schema_name, int original_schema_version);

OTIO_API const char *UnknownSchema_original_schema_name(UnknownSchema *self);

OTIO_API int UnknownSchema_original_schema_version(UnknownSchema *self);

OTIO_API bool UnknownSchema_is_unknown_schema(UnknownSchema *self);

OTIO_API bool UnknownSchema_to_json_file(
        UnknownSchema *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);

OTIO_API const char *UnknownSchema_to_json_string(
        UnknownSchema *self, OTIOErrorStatus *error_status, int indent);

OTIO_API bool UnknownSchema_is_equivalent_to(
        UnknownSchema *self, OTIOSerializableObject *other);

OTIO_API UnknownSchema *
UnknownSchema_clone(UnknownSchema *self, OTIOErrorStatus *error_status);

OTIO_API const char *UnknownSchema_schema_name(UnknownSchema *self);

OTIO_API int UnknownSchema_schema_version(UnknownSchema *self);
