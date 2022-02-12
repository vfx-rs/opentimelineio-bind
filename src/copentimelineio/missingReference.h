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

struct MissingReference;
typedef struct MissingReference MissingReference;

OTIO_API MissingReference *MissingReference_create(
        const char *name, OptionalTimeRange available_range, AnyDictionary *metadata);

OTIO_API bool MissingReference_is_missing_reference(MissingReference *self);

OTIO_API OptionalTimeRange MissingReference_available_range(MissingReference *self);

OTIO_API void MissingReference_set_available_range(
        MissingReference *self, OptionalTimeRange available_range);

OTIO_API const char *MissingReference_name(MissingReference *self);

OTIO_API void MissingReference_set_name(MissingReference *self, const char *name);

OTIO_API AnyDictionary *MissingReference_metadata(MissingReference *self);

OTIO_API bool MissingReference_to_json_file(
        MissingReference *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);

OTIO_API const char *MissingReference_to_json_string(
        MissingReference *self, OTIOErrorStatus *error_status, int indent);

OTIO_API bool MissingReference_is_equivalent_to(
        MissingReference *self, OTIOSerializableObject *other);

OTIO_API MissingReference *MissingReference_clone(
        MissingReference *self, OTIOErrorStatus *error_status);

OTIO_API const char *MissingReference_schema_name(MissingReference *self);

OTIO_API int MissingReference_schema_version(MissingReference *self);