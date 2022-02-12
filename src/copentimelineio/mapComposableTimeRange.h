#pragma once

#include "composable.h"
#include "copentime/timeRange.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

struct MapComposableTimeRangeIterator;
typedef struct MapComposableTimeRangeIterator
        MapComposableTimeRangeIterator;
struct MapComposableTimeRange;
typedef struct MapComposableTimeRange MapComposableTimeRange;

OTIO_API MapComposableTimeRange *MapComposableTimeRange_create();

OTIO_API void MapComposableTimeRange_destroy(MapComposableTimeRange *self);

OTIO_API void MapComposableTimeRange_clear(MapComposableTimeRange *self);

OTIO_API MapComposableTimeRangeIterator *
MapComposableTimeRange_begin(MapComposableTimeRange *self);

OTIO_API MapComposableTimeRangeIterator *
MapComposableTimeRange_end(MapComposableTimeRange *self);

OTIO_API void MapComposableTimeRange_swap(
        MapComposableTimeRange *self, MapComposableTimeRange *other);

OTIO_API MapComposableTimeRangeIterator *MapComposableTimeRange_erase(
        MapComposableTimeRange *self, MapComposableTimeRangeIterator *pos);

OTIO_API MapComposableTimeRangeIterator *MapComposableTimeRange_erase_range(
        MapComposableTimeRange *self,
        MapComposableTimeRangeIterator *first,
        MapComposableTimeRangeIterator *last);

OTIO_API int MapComposableTimeRange_erase_key(
        MapComposableTimeRange *self, Composable *key);

OTIO_API int MapComposableTimeRange_size(MapComposableTimeRange *self);

OTIO_API int MapComposableTimeRange_max_size(MapComposableTimeRange *self);

OTIO_API bool MapComposableTimeRange_empty(MapComposableTimeRange *self);

OTIO_API MapComposableTimeRangeIterator *
MapComposableTimeRange_find(MapComposableTimeRange *self, Composable *key);

OTIO_API MapComposableTimeRangeIterator *MapComposableTimeRange_insert(
        MapComposableTimeRange *self, Composable *key, TimeRange anyObj);

OTIO_API void MapComposableTimeRangeIterator_advance(
        MapComposableTimeRangeIterator *iter, int dist);

OTIO_API MapComposableTimeRangeIterator *MapComposableTimeRangeIterator_next(
        MapComposableTimeRangeIterator *iter, int dist);

OTIO_API MapComposableTimeRangeIterator *MapComposableTimeRangeIterator_prev(
        MapComposableTimeRangeIterator *iter, int dist);

OTIO_API TimeRange
MapComposableTimeRangeIterator_value(MapComposableTimeRangeIterator *iter);

OTIO_API bool MapComposableTimeRangeIterator_equal(
        MapComposableTimeRangeIterator *lhs,
        MapComposableTimeRangeIterator *rhs);

OTIO_API bool MapComposableTimeRangeIterator_not_equal(
        MapComposableTimeRangeIterator *lhs,
        MapComposableTimeRangeIterator *rhs);

OTIO_API void MapComposableTimeRangeIterator_destroy(
        MapComposableTimeRangeIterator *self);
