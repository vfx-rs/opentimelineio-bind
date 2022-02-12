#pragma once

#include "marker.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif
typedef struct MarkerRetainerVectorIterator MarkerRetainerVectorIterator;
typedef struct MarkerRetainerVector MarkerRetainerVector;

OTIO_API MarkerRetainerVector *MarkerRetainerVector_create();

OTIO_API void MarkerRetainerVector_destroy(MarkerRetainerVector *self);

OTIO_API MarkerRetainerVectorIterator *
MarkerRetainerVector_begin(MarkerRetainerVector *self);

OTIO_API MarkerRetainerVectorIterator *
MarkerRetainerVector_end(MarkerRetainerVector *self);

OTIO_API int MarkerRetainerVector_size(MarkerRetainerVector *self);

OTIO_API int MarkerRetainerVector_max_size(MarkerRetainerVector *self);

OTIO_API int MarkerRetainerVector_capacity(MarkerRetainerVector *self);

OTIO_API void MarkerRetainerVector_resize(MarkerRetainerVector *self, int n);

OTIO_API bool MarkerRetainerVector_empty(MarkerRetainerVector *self);

OTIO_API void MarkerRetainerVector_shrink_to_fit(MarkerRetainerVector *self);

OTIO_API void MarkerRetainerVector_reserve(MarkerRetainerVector *self, int n);

OTIO_API void MarkerRetainerVector_swap(
        MarkerRetainerVector *self, MarkerRetainerVector *other);

OTIO_API RetainerMarker *
MarkerRetainerVector_at(MarkerRetainerVector *self, int pos);

OTIO_API void MarkerRetainerVector_push_back(
        MarkerRetainerVector *self, RetainerMarker *value);

OTIO_API void MarkerRetainerVector_pop_back(MarkerRetainerVector *self);

OTIO_API MarkerRetainerVectorIterator *MarkerRetainerVector_insert(
        MarkerRetainerVector *self,
        MarkerRetainerVectorIterator *pos,
        RetainerMarker *val);

OTIO_API void MarkerRetainerVector_clear(MarkerRetainerVector *self);

OTIO_API MarkerRetainerVectorIterator *MarkerRetainerVector_erase(
        MarkerRetainerVector *self, MarkerRetainerVectorIterator *pos);

OTIO_API MarkerRetainerVectorIterator *MarkerRetainerVector_erase_range(
        MarkerRetainerVector *self,
        MarkerRetainerVectorIterator *first,
        MarkerRetainerVectorIterator *last);

OTIO_API void MarkerRetainerVectorIterator_advance(
        MarkerRetainerVectorIterator *iter, int dist);

OTIO_API MarkerRetainerVectorIterator *MarkerRetainerVectorIterator_next(
        MarkerRetainerVectorIterator *iter, int dist);

OTIO_API MarkerRetainerVectorIterator *MarkerRetainerVectorIterator_prev(
        MarkerRetainerVectorIterator *iter, int dist);

OTIO_API RetainerMarker *
MarkerRetainerVectorIterator_value(MarkerRetainerVectorIterator *iter);

OTIO_API bool MarkerRetainerVectorIterator_equal(
        MarkerRetainerVectorIterator *lhs, MarkerRetainerVectorIterator *rhs);

OTIO_API bool MarkerRetainerVectorIterator_not_equal(
        MarkerRetainerVectorIterator *lhs, MarkerRetainerVectorIterator *rhs);

OTIO_API void
MarkerRetainerVectorIterator_destroy(MarkerRetainerVectorIterator *self);
