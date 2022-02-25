#pragma once

#include "rationalTime.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct {
    RationalTime start_time;
    RationalTime duration;
} TimeRange;

OTIO_API TimeRange TimeRange_create();

OTIO_API TimeRange TimeRange_create_with_start_time(RationalTime start_time);

OTIO_API TimeRange TimeRange_create_with_duration(RationalTime duration);

OTIO_API TimeRange TimeRange_create_with_start_time_and_duration(
        RationalTime start_time, RationalTime duration);

OTIO_API RationalTime TimeRange_start_time(TimeRange self);

OTIO_API RationalTime TimeRange_duration(TimeRange self);

OTIO_API RationalTime TimeRange_end_time_inclusive(TimeRange self);

OTIO_API RationalTime TimeRange_end_time_exclusive(TimeRange self);

OTIO_API TimeRange
TimeRange_duration_extended_by(TimeRange self, RationalTime other);

OTIO_API TimeRange TimeRange_extended_by(TimeRange self, TimeRange other);

OTIO_API RationalTime
TimeRange_clamped_with_rational_time(TimeRange self, RationalTime other);

OTIO_API TimeRange
TimeRange_clamped_with_time_range(TimeRange self, TimeRange other);

OTIO_API bool
TimeRange_contains_rational_time(TimeRange self, RationalTime other);

OTIO_API bool TimeRange_contains_time_range(TimeRange self, TimeRange other);

OTIO_API bool
TimeRange_overlaps_rational_time(TimeRange self, RationalTime other);

OTIO_API bool TimeRange_overlaps_time_range(TimeRange self, TimeRange other);

OTIO_API bool TimeRange_equal(TimeRange lhs, TimeRange rhs);

OTIO_API bool TimeRange_not_equal(TimeRange lhs, TimeRange rhs);

OTIO_API TimeRange TimeRange_range_from_start_end_time(
        RationalTime start_time, RationalTime end_time_exclusive);
