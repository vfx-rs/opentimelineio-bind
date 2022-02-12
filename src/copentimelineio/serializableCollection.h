#pragma once

#include "anyDictionary.h"
#include "errorStatus.h"
#include "serializableObjectRetainerVector.h"
#include "serializableObjectVector.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct SerializableCollection SerializableCollection;

OTIO_API SerializableCollection*               SerializableCollection_create(
                  const char*               name,
                  SerializableObjectVector* children,
                  AnyDictionary*            metadata);
OTIO_API SerializableObjectRetainerVector*
     SerializableCollection_children(SerializableCollection* self);
OTIO_API void SerializableCollection_set_children(
    SerializableCollection* self, SerializableObjectVector* children);
OTIO_API void SerializableCollection_clear_children(SerializableCollection* self);
OTIO_API void SerializableCollection_insert_child(
    SerializableCollection* self, int index, OTIOSerializableObject* child);
OTIO_API bool SerializableCollection_set_child(
    SerializableCollection* self,
    int                     index,
    OTIOSerializableObject*     child,
    OTIOErrorStatus*        error_status);
OTIO_API bool SerializableCollection_remove_child(
    SerializableCollection* self, int index, OTIOErrorStatus* error_status);
OTIO_API const char* SerializableCollection_name(SerializableCollection* self);
OTIO_API void        SerializableCollection_set_name(
           SerializableCollection* self, const char* name);
OTIO_API AnyDictionary*
      SerializableCollection_metadata(SerializableCollection* self);
OTIO_API bool SerializableCollection_to_json_file(
    SerializableCollection* self,
    const char*             file_name,
    OTIOErrorStatus*        error_status,
    int                     indent);
OTIO_API const char* SerializableCollection_to_json_string(
    SerializableCollection* self,
    OTIOErrorStatus*        error_status,
    int                     indent);
OTIO_API bool SerializableCollection_is_equivalent_to(
    SerializableCollection* self, OTIOSerializableObject* other);
OTIO_API SerializableCollection* SerializableCollection_clone(
    SerializableCollection* self, OTIOErrorStatus* error_status);
OTIO_API const char*
    SerializableCollection_schema_name(SerializableCollection* self);
OTIO_API int SerializableCollection_schema_version(SerializableCollection* self);
