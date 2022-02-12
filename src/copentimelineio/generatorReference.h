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

typedef struct GeneratorReference GeneratorReference;

OTIO_API GeneratorReference *GeneratorReference_create(
        const char *name,
        const char *generator_kind,
        OptionalTimeRange available_range,
        AnyDictionary *parameters,
        AnyDictionary *metadata);
OTIO_API const char *GeneratorReference_generator_kind(GeneratorReference *self);
OTIO_API void GeneratorReference_set_generator_kind(
        GeneratorReference *self, const char *generator_kind);
OTIO_API AnyDictionary *GeneratorReference_parameters(GeneratorReference *self);
OTIO_API OptionalTimeRange GeneratorReference_available_range(GeneratorReference *self);
OTIO_API void GeneratorReference_set_available_range(
        GeneratorReference *self, OptionalTimeRange available_range);
OTIO_API bool GeneratorReference_is_missing_reference(GeneratorReference *self);
OTIO_API const char *GeneratorReference_name(GeneratorReference *self);
OTIO_API void
GeneratorReference_set_name(GeneratorReference *self, const char *name);
OTIO_API AnyDictionary *GeneratorReference_metadata(GeneratorReference *self);
OTIO_API bool GeneratorReference_to_json_file(
        GeneratorReference *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);
OTIO_API const char *GeneratorReference_to_json_string(
        GeneratorReference *self, OTIOErrorStatus *error_status, int indent);
OTIO_API bool GeneratorReference_is_equivalent_to(
        GeneratorReference *self, OTIOSerializableObject *other);
OTIO_API GeneratorReference *GeneratorReference_clone(
        GeneratorReference *self, OTIOErrorStatus *error_status);
OTIO_API const char *GeneratorReference_schema_name(GeneratorReference *self);
OTIO_API int GeneratorReference_schema_version(GeneratorReference *self);
