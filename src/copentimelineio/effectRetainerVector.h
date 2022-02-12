#pragma once

#include "effect.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct EffectRetainerVectorIterator EffectRetainerVectorIterator;
typedef struct EffectRetainerVector EffectRetainerVector;

OTIO_API EffectRetainerVector *EffectRetainerVector_create();

OTIO_API void EffectRetainerVector_destroy(EffectRetainerVector *self);

OTIO_API EffectRetainerVectorIterator *
EffectRetainerVector_begin(EffectRetainerVector *self);

OTIO_API EffectRetainerVectorIterator *
EffectRetainerVector_end(EffectRetainerVector *self);

OTIO_API int EffectRetainerVector_size(EffectRetainerVector *self);

OTIO_API int EffectRetainerVector_max_size(EffectRetainerVector *self);

OTIO_API int EffectRetainerVector_capacity(EffectRetainerVector *self);

OTIO_API void EffectRetainerVector_resize(EffectRetainerVector *self, int n);

OTIO_API bool EffectRetainerVector_empty(EffectRetainerVector *self);

OTIO_API void EffectRetainerVector_shrink_to_fit(EffectRetainerVector *self);

OTIO_API void EffectRetainerVector_reserve(EffectRetainerVector *self, int n);

OTIO_API void EffectRetainerVector_swap(
        EffectRetainerVector *self, EffectRetainerVector *other);

OTIO_API RetainerEffect *
EffectRetainerVector_at(EffectRetainerVector *self, int pos);

OTIO_API void EffectRetainerVector_push_back(
        EffectRetainerVector *self, RetainerEffect *value);

OTIO_API void EffectRetainerVector_pop_back(EffectRetainerVector *self);

OTIO_API EffectRetainerVectorIterator *EffectRetainerVector_insert(
        EffectRetainerVector *self,
        EffectRetainerVectorIterator *pos,
        RetainerEffect *val);

OTIO_API void EffectRetainerVector_clear(EffectRetainerVector *self);

OTIO_API EffectRetainerVectorIterator *EffectRetainerVector_erase(
        EffectRetainerVector *self, EffectRetainerVectorIterator *pos);

OTIO_API EffectRetainerVectorIterator *EffectRetainerVector_erase_range(
        EffectRetainerVector *self,
        EffectRetainerVectorIterator *first,
        EffectRetainerVectorIterator *last);

OTIO_API void EffectRetainerVectorIterator_advance(
        EffectRetainerVectorIterator *iter, int dist);

OTIO_API EffectRetainerVectorIterator *EffectRetainerVectorIterator_next(
        EffectRetainerVectorIterator *iter, int dist);

OTIO_API EffectRetainerVectorIterator *EffectRetainerVectorIterator_prev(
        EffectRetainerVectorIterator *iter, int dist);

OTIO_API RetainerEffect *
EffectRetainerVectorIterator_value(EffectRetainerVectorIterator *iter);

OTIO_API bool EffectRetainerVectorIterator_equal(
        EffectRetainerVectorIterator *lhs, EffectRetainerVectorIterator *rhs);

OTIO_API bool EffectRetainerVectorIterator_not_equal(
        EffectRetainerVectorIterator *lhs, EffectRetainerVectorIterator *rhs);

OTIO_API void
EffectRetainerVectorIterator_destroy(EffectRetainerVectorIterator *self);
