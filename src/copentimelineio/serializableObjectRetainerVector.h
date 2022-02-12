#pragma once

#include "serializableObject.h"

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif
typedef struct SerializableObjectRetainerVectorIterator
        SerializableObjectRetainerVectorIterator;
typedef struct SerializableObjectRetainerVector
        SerializableObjectRetainerVector;

OTIO_API SerializableObjectRetainerVector *SerializableObjectRetainerVector_create();

OTIO_API void SerializableObjectRetainerVector_destroy(
        SerializableObjectRetainerVector *self);

OTIO_API SerializableObjectRetainerVectorIterator *
SerializableObjectRetainerVector_begin(
        SerializableObjectRetainerVector *self);

OTIO_API SerializableObjectRetainerVectorIterator *
SerializableObjectRetainerVector_end(
        SerializableObjectRetainerVector *self);

OTIO_API int SerializableObjectRetainerVector_size(
        SerializableObjectRetainerVector *self);

OTIO_API int SerializableObjectRetainerVector_max_size(
        SerializableObjectRetainerVector *self);

OTIO_API int SerializableObjectRetainerVector_capacity(
        SerializableObjectRetainerVector *self);

OTIO_API void SerializableObjectRetainerVector_resize(
        SerializableObjectRetainerVector *self, int n);

OTIO_API bool SerializableObjectRetainerVector_empty(
        SerializableObjectRetainerVector *self);

OTIO_API void SerializableObjectRetainerVector_shrink_to_fit(
        SerializableObjectRetainerVector *self);

OTIO_API void SerializableObjectRetainerVector_reserve(
        SerializableObjectRetainerVector *self, int n);

OTIO_API void SerializableObjectRetainerVector_swap(
        SerializableObjectRetainerVector *self,
        SerializableObjectRetainerVector *other);

OTIO_API RetainerSerializableObject *SerializableObjectRetainerVector_at(
        SerializableObjectRetainerVector *self, int pos);

OTIO_API void SerializableObjectRetainerVector_push_back(
        SerializableObjectRetainerVector *self,
        RetainerSerializableObject *value);

OTIO_API void SerializableObjectRetainerVector_pop_back(
        SerializableObjectRetainerVector *self);

OTIO_API SerializableObjectRetainerVectorIterator *
SerializableObjectRetainerVector_insert(
        SerializableObjectRetainerVector *self,
        SerializableObjectRetainerVectorIterator *pos,
        RetainerSerializableObject *val);

OTIO_API void SerializableObjectRetainerVector_clear(
        SerializableObjectRetainerVector *self);

OTIO_API SerializableObjectRetainerVectorIterator *
SerializableObjectRetainerVector_erase(
        SerializableObjectRetainerVector *self,
        SerializableObjectRetainerVectorIterator *pos);

OTIO_API SerializableObjectRetainerVectorIterator *
SerializableObjectRetainerVector_erase_range(
        SerializableObjectRetainerVector *self,
        SerializableObjectRetainerVectorIterator *first,
        SerializableObjectRetainerVectorIterator *last);

OTIO_API void SerializableObjectRetainerVectorIterator_advance(
        SerializableObjectRetainerVectorIterator *iter, int dist);

OTIO_API SerializableObjectRetainerVectorIterator *
SerializableObjectRetainerVectorIterator_next(
        SerializableObjectRetainerVectorIterator *iter, int dist);

OTIO_API SerializableObjectRetainerVectorIterator *
SerializableObjectRetainerVectorIterator_prev(
        SerializableObjectRetainerVectorIterator *iter, int dist);

OTIO_API RetainerSerializableObject *SerializableObjectRetainerVectorIterator_value(
        SerializableObjectRetainerVectorIterator *iter);

OTIO_API bool SerializableObjectRetainerVectorIterator_equal(
        SerializableObjectRetainerVectorIterator *lhs,
        SerializableObjectRetainerVectorIterator *rhs);

OTIO_API bool SerializableObjectRetainerVectorIterator_not_equal(
        SerializableObjectRetainerVectorIterator *lhs,
        SerializableObjectRetainerVectorIterator *rhs);

OTIO_API void SerializableObjectRetainerVectorIterator_destroy(
        SerializableObjectRetainerVectorIterator *self);
