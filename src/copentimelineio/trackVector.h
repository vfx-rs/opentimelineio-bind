#pragma once

#include "track.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct TrackVectorIterator TrackVectorIterator;
typedef struct TrackVector TrackVector;

OTIO_API TrackVector *TrackVector_create();

OTIO_API void TrackVector_destroy(TrackVector *self);

OTIO_API TrackVectorIterator *TrackVector_begin(TrackVector *self);

OTIO_API TrackVectorIterator *TrackVector_end(TrackVector *self);

OTIO_API int TrackVector_size(TrackVector *self);

OTIO_API int TrackVector_max_size(TrackVector *self);

OTIO_API int TrackVector_capacity(TrackVector *self);

OTIO_API void TrackVector_resize(TrackVector *self, int n);

OTIO_API bool TrackVector_empty(TrackVector *self);

OTIO_API void TrackVector_shrink_to_fit(TrackVector *self);

OTIO_API void TrackVector_reserve(TrackVector *self, int n);

OTIO_API void TrackVector_swap(TrackVector *self, TrackVector *other);

OTIO_API Track *TrackVector_at(TrackVector *self, int pos);

OTIO_API void TrackVector_push_back(TrackVector *self, Track *value);

OTIO_API void TrackVector_pop_back(TrackVector *self);

OTIO_API TrackVectorIterator *
TrackVector_insert(TrackVector *self, TrackVectorIterator *pos, Track *val);

OTIO_API void TrackVector_clear(TrackVector *self);

OTIO_API TrackVectorIterator *
TrackVector_erase(TrackVector *self, TrackVectorIterator *pos);

OTIO_API TrackVectorIterator *TrackVector_erase_range(
        TrackVector *self,
        TrackVectorIterator *first,
        TrackVectorIterator *last);

OTIO_API void TrackVectorIterator_advance(TrackVectorIterator *iter, int dist);

OTIO_API TrackVectorIterator *
TrackVectorIterator_next(TrackVectorIterator *iter, int dist);

OTIO_API TrackVectorIterator *
TrackVectorIterator_prev(TrackVectorIterator *iter, int dist);

OTIO_API Track *TrackVectorIterator_value(TrackVectorIterator *iter);

OTIO_API bool TrackVectorIterator_equal(
        TrackVectorIterator *lhs, TrackVectorIterator *rhs);

OTIO_API bool TrackVectorIterator_not_equal(
        TrackVectorIterator *lhs, TrackVectorIterator *rhs);

OTIO_API void TrackVectorIterator_destroy(TrackVectorIterator *self);
