#pragma once

#include "marker.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif
typedef struct MarkerVectorIterator MarkerVectorIterator;
typedef struct MarkerVector MarkerVector;

OTIO_API MarkerVector *MarkerVector_create();

OTIO_API void MarkerVector_destroy(MarkerVector *self);

OTIO_API MarkerVectorIterator *MarkerVector_begin(MarkerVector *self);

OTIO_API MarkerVectorIterator *MarkerVector_end(MarkerVector *self);

OTIO_API int MarkerVector_size(MarkerVector *self);

OTIO_API int MarkerVector_max_size(MarkerVector *self);

OTIO_API int MarkerVector_capacity(MarkerVector *self);

OTIO_API void MarkerVector_resize(MarkerVector *self, int n);

OTIO_API bool MarkerVector_empty(MarkerVector *self);

OTIO_API void MarkerVector_shrink_to_fit(MarkerVector *self);

OTIO_API void MarkerVector_reserve(MarkerVector *self, int n);

OTIO_API void MarkerVector_swap(MarkerVector *self, MarkerVector *other);

OTIO_API Marker *MarkerVector_at(MarkerVector *self, int pos);

OTIO_API void MarkerVector_push_back(MarkerVector *self, Marker *value);

OTIO_API void MarkerVector_pop_back(MarkerVector *self);

OTIO_API MarkerVectorIterator *MarkerVector_insert(
        MarkerVector *self, MarkerVectorIterator *pos, Marker *val);

OTIO_API void MarkerVector_clear(MarkerVector *self);

OTIO_API MarkerVectorIterator *
MarkerVector_erase(MarkerVector *self, MarkerVectorIterator *pos);

OTIO_API MarkerVectorIterator *MarkerVector_erase_range(
        MarkerVector *self,
        MarkerVectorIterator *first,
        MarkerVectorIterator *last);

OTIO_API void MarkerVectorIterator_advance(MarkerVectorIterator *iter, int dist);

OTIO_API MarkerVectorIterator *
MarkerVectorIterator_next(MarkerVectorIterator *iter, int dist);

OTIO_API MarkerVectorIterator *
MarkerVectorIterator_prev(MarkerVectorIterator *iter, int dist);

OTIO_API Marker *MarkerVectorIterator_value(MarkerVectorIterator *iter);

OTIO_API bool MarkerVectorIterator_equal(
        MarkerVectorIterator *lhs, MarkerVectorIterator *rhs);

OTIO_API bool MarkerVectorIterator_not_equal(
        MarkerVectorIterator *lhs, MarkerVectorIterator *rhs);

OTIO_API void MarkerVectorIterator_destroy(MarkerVectorIterator *self);
