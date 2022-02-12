#pragma once

#include "serializableObject.h"

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct SerializableObjectVectorIterator SerializableObjectVectorIterator;
typedef struct SerializableObjectVector SerializableObjectVector;

OTIO_API SerializableObjectVector*               SerializableObjectVector_create();
OTIO_API void SerializableObjectVector_destroy(SerializableObjectVector* self);
OTIO_API SerializableObjectVectorIterator*
    SerializableObjectVector_begin(SerializableObjectVector* self);
OTIO_API SerializableObjectVectorIterator*
     SerializableObjectVector_end(SerializableObjectVector* self);
OTIO_API int  SerializableObjectVector_size(SerializableObjectVector* self);
OTIO_API int  SerializableObjectVector_max_size(SerializableObjectVector* self);
OTIO_API int  SerializableObjectVector_capacity(SerializableObjectVector* self);
OTIO_API void SerializableObjectVector_resize(SerializableObjectVector* self, int n);
OTIO_API bool SerializableObjectVector_empty(SerializableObjectVector* self);
OTIO_API void SerializableObjectVector_shrink_to_fit(SerializableObjectVector* self);
OTIO_API void
     SerializableObjectVector_reserve(SerializableObjectVector* self, int n);
OTIO_API void SerializableObjectVector_swap(
    SerializableObjectVector* self, SerializableObjectVector* other);
OTIO_API OTIOSerializableObject*
     SerializableObjectVector_at(SerializableObjectVector* self, int pos);
OTIO_API void SerializableObjectVector_push_back(
    SerializableObjectVector* self, OTIOSerializableObject* value);
OTIO_API void SerializableObjectVector_pop_back(SerializableObjectVector* self);
OTIO_API SerializableObjectVectorIterator* SerializableObjectVector_insert(
    SerializableObjectVector*         self,
    SerializableObjectVectorIterator* pos,
    OTIOSerializableObject*               val);
OTIO_API void SerializableObjectVector_clear(SerializableObjectVector* self);
OTIO_API SerializableObjectVectorIterator* SerializableObjectVector_erase(
    SerializableObjectVector* self, SerializableObjectVectorIterator* pos);
OTIO_API SerializableObjectVectorIterator* SerializableObjectVector_erase_range(
    SerializableObjectVector*         self,
    SerializableObjectVectorIterator* first,
    SerializableObjectVectorIterator* last);
OTIO_API void SerializableObjectVectorIterator_advance(
    SerializableObjectVectorIterator* iter, int dist);
OTIO_API SerializableObjectVectorIterator* SerializableObjectVectorIterator_next(
    SerializableObjectVectorIterator* iter, int dist);
OTIO_API SerializableObjectVectorIterator* SerializableObjectVectorIterator_prev(
    SerializableObjectVectorIterator* iter, int dist);
OTIO_API OTIOSerializableObject* SerializableObjectVectorIterator_value(
    SerializableObjectVectorIterator* iter);
OTIO_API bool SerializableObjectVectorIterator_equal(
    SerializableObjectVectorIterator* lhs,
    SerializableObjectVectorIterator* rhs);
OTIO_API bool SerializableObjectVectorIterator_not_equal(
    SerializableObjectVectorIterator* lhs,
    SerializableObjectVectorIterator* rhs);
OTIO_API void SerializableObjectVectorIterator_destroy(
    SerializableObjectVectorIterator* self);
