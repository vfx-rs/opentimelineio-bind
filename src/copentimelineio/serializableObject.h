#pragma once

#include "errorStatus.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct RetainerSerializableObject RetainerSerializableObject;
typedef struct OTIOSerializableObject OTIOSerializableObject;
typedef struct OTIOErrorStatus OTIOErrorStatus;

OTIO_API RetainerSerializableObject*
    RetainerSerializableObject_create(OTIOSerializableObject* obj);
OTIO_API OTIOSerializableObject*
    RetainerSerializableObject_take_value(RetainerSerializableObject* self);
OTIO_API OTIOSerializableObject*
     RetainerSerializableObject_value(RetainerSerializableObject* self);
OTIO_API void RetainerSerializableObject_managed_destroy(
    RetainerSerializableObject* self);
OTIO_API OTIOSerializableObject* SerializableObject_create();
OTIO_API bool SerializableObject_to_json_file(
    OTIOSerializableObject* self,
    const char*         file_name,
    OTIOErrorStatus*    error_status,
    int                 indent);
OTIO_API const char* SerializableObject_to_json_string(
    OTIOSerializableObject* self, OTIOErrorStatus* error_status, int indent);
OTIO_API OTIOSerializableObject* SerializableObject_from_json_file(
    const char* file_name, OTIOErrorStatus* error_status);
OTIO_API OTIOSerializableObject* SerializableObject_from_json_string(
    const char* input, OTIOErrorStatus* error_status);
OTIO_API bool SerializableObject_is_equivalent_to(
    OTIOSerializableObject* self, OTIOSerializableObject* other);
OTIO_API OTIOSerializableObject* SerializableObject_clone(
    OTIOSerializableObject* self, OTIOErrorStatus* error_status);
/*AnyDictionary* SerializableObject_dynamic_fields(OTIOSerializableObject* self);*/
OTIO_API bool        SerializableObject_is_unknown_schema(OTIOSerializableObject* self);
OTIO_API const char* SerializableObject_schema_name(OTIOSerializableObject* self);
OTIO_API int         SerializableObject_schema_version(OTIOSerializableObject* self);

#define OTIO_RETAIN(X) RetainerSerializableObject* X##_r = RetainerSerializableObject_create((OTIOSerializableObject*) (X))
#define OTIO_RELEASE(X) if (X##_r) { RetainerSerializableObject_managed_destroy(X##_r); X##_r = NULL; }
