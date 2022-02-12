#pragma once

#include "composable.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif
typedef struct ComposableRetainerVectorIterator
        ComposableRetainerVectorIterator;
typedef struct ComposableRetainerVector ComposableRetainerVector;

OTIO_API ComposableRetainerVector *ComposableRetainerVector_create();

OTIO_API void ComposableRetainerVector_destroy(ComposableRetainerVector *self);

OTIO_API ComposableRetainerVectorIterator *
ComposableRetainerVector_begin(ComposableRetainerVector *self);

OTIO_API ComposableRetainerVectorIterator *
ComposableRetainerVector_end(ComposableRetainerVector *self);

OTIO_API int ComposableRetainerVector_size(ComposableRetainerVector *self);

OTIO_API int ComposableRetainerVector_max_size(ComposableRetainerVector *self);

OTIO_API int ComposableRetainerVector_capacity(ComposableRetainerVector *self);

OTIO_API void ComposableRetainerVector_resize(ComposableRetainerVector *self, int n);

OTIO_API bool ComposableRetainerVector_empty(ComposableRetainerVector *self);

OTIO_API void ComposableRetainerVector_shrink_to_fit(ComposableRetainerVector *self);

OTIO_API void
ComposableRetainerVector_reserve(ComposableRetainerVector *self, int n);

OTIO_API void ComposableRetainerVector_swap(
        ComposableRetainerVector *self, ComposableRetainerVector *other);

OTIO_API RetainerComposable *
ComposableRetainerVector_at(ComposableRetainerVector *self, int pos);

OTIO_API void ComposableRetainerVector_push_back(
        ComposableRetainerVector *self, RetainerComposable *value);

OTIO_API void ComposableRetainerVector_pop_back(ComposableRetainerVector *self);

OTIO_API ComposableRetainerVectorIterator *ComposableRetainerVector_insert(
        ComposableRetainerVector *self,
        ComposableRetainerVectorIterator *pos,
        RetainerComposable *val);

OTIO_API void ComposableRetainerVector_clear(ComposableRetainerVector *self);

OTIO_API ComposableRetainerVectorIterator *ComposableRetainerVector_erase(
        ComposableRetainerVector *self, ComposableRetainerVectorIterator *pos);

OTIO_API ComposableRetainerVectorIterator *ComposableRetainerVector_erase_range(
        ComposableRetainerVector *self,
        ComposableRetainerVectorIterator *first,
        ComposableRetainerVectorIterator *last);

OTIO_API void ComposableRetainerVectorIterator_advance(
        ComposableRetainerVectorIterator *iter, int dist);

OTIO_API ComposableRetainerVectorIterator *ComposableRetainerVectorIterator_next(
        ComposableRetainerVectorIterator *iter, int dist);

OTIO_API ComposableRetainerVectorIterator *ComposableRetainerVectorIterator_prev(
        ComposableRetainerVectorIterator *iter, int dist);

OTIO_API RetainerComposable *ComposableRetainerVectorIterator_value(
        ComposableRetainerVectorIterator *iter);

OTIO_API bool ComposableRetainerVectorIterator_equal(
        ComposableRetainerVectorIterator *lhs,
        ComposableRetainerVectorIterator *rhs);

OTIO_API bool ComposableRetainerVectorIterator_not_equal(
        ComposableRetainerVectorIterator *lhs,
        ComposableRetainerVectorIterator *rhs);

OTIO_API void ComposableRetainerVectorIterator_destroy(
        ComposableRetainerVectorIterator *self);
