#pragma once

#include "effect.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif
typedef struct EffectVectorIterator EffectVectorIterator;
typedef struct EffectVector EffectVector;

OTIO_API EffectVector *EffectVector_create();

OTIO_API void EffectVector_destroy(EffectVector *self);

OTIO_API EffectVectorIterator *EffectVector_begin(EffectVector *self);

OTIO_API EffectVectorIterator *EffectVector_end(EffectVector *self);

OTIO_API int EffectVector_size(EffectVector *self);

OTIO_API int EffectVector_max_size(EffectVector *self);

OTIO_API int EffectVector_capacity(EffectVector *self);

OTIO_API void EffectVector_resize(EffectVector *self, int n);

OTIO_API bool EffectVector_empty(EffectVector *self);

OTIO_API void EffectVector_shrink_to_fit(EffectVector *self);

OTIO_API void EffectVector_reserve(EffectVector *self, int n);

OTIO_API void EffectVector_swap(EffectVector *self, EffectVector *other);

OTIO_API Effect *EffectVector_at(EffectVector *self, int pos);

OTIO_API void EffectVector_push_back(EffectVector *self, Effect *value);

OTIO_API void EffectVector_pop_back(EffectVector *self);

OTIO_API EffectVectorIterator *EffectVector_insert(
        EffectVector *self, EffectVectorIterator *pos, Effect *val);

OTIO_API void EffectVector_clear(EffectVector *self);

OTIO_API EffectVectorIterator *
EffectVector_erase(EffectVector *self, EffectVectorIterator *pos);

OTIO_API EffectVectorIterator *EffectVector_erase_range(
        EffectVector *self,
        EffectVectorIterator *first,
        EffectVectorIterator *last);

OTIO_API void EffectVectorIterator_advance(EffectVectorIterator *iter, int dist);

OTIO_API EffectVectorIterator *
EffectVectorIterator_next(EffectVectorIterator *iter, int dist);

OTIO_API EffectVectorIterator *
EffectVectorIterator_prev(EffectVectorIterator *iter, int dist);

OTIO_API Effect *EffectVectorIterator_value(EffectVectorIterator *iter);

OTIO_API bool EffectVectorIterator_equal(
        EffectVectorIterator *lhs, EffectVectorIterator *rhs);

OTIO_API bool EffectVectorIterator_not_equal(
        EffectVectorIterator *lhs, EffectVectorIterator *rhs);

OTIO_API void EffectVectorIterator_destroy(EffectVectorIterator *self);
