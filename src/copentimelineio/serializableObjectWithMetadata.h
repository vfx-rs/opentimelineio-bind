#pragma once

#include "anyDictionary.h"
#include "errorStatus.h"
#include "serializableObject.h"

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

struct SerializableObjectWithMetadata;
typedef struct SerializableObjectWithMetadata
                                SerializableObjectWithMetadata;
OTIO_API SerializableObjectWithMetadata*
SerializableObjectWithMetadata_create(const char* name, AnyDictionary* metadata);
OTIO_API const char*
SerializableObjectWithMetadata_name(SerializableObjectWithMetadata* self);
OTIO_API void
SerializableObjectWithMetadata_set_name(SerializableObjectWithMetadata* self, const char* name);
OTIO_API AnyDictionary*
SerializableObjectWithMetadata_metadata(SerializableObjectWithMetadata* self);
OTIO_API bool
SerializableObjectWithMetadata_to_json_file(
    SerializableObjectWithMetadata* self,
    const char*                     file_name,
    OTIOErrorStatus*                error_status,
    int                             indent);
OTIO_API const char*
SerializableObjectWithMetadata_to_json_string(
    SerializableObjectWithMetadata* self,
    OTIOErrorStatus*                error_status,
    int                             indent);
OTIO_API bool
SerializableObjectWithMetadata_is_equivalent_to(
    SerializableObjectWithMetadata* self, OTIOSerializableObject* other);
OTIO_API SerializableObjectWithMetadata*
SerializableObjectWithMetadata_clone(
    SerializableObjectWithMetadata* self, OTIOErrorStatus* error_status);
OTIO_API bool
SerializableObjectWithMetadata_is_unknown_schema(SerializableObjectWithMetadata* self);
OTIO_API const char*
SerializableObjectWithMetadata_schema_name(SerializableObjectWithMetadata* self);
OTIO_API int
SerializableObjectWithMetadata_schema_version(SerializableObjectWithMetadata* self);
