#pragma once

#include "rationalTime.h"
#include "timeRange.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct {
    RationalTime offset;
    double scale;
    double rate;
} TimeTransform;

OTIO_API TimeTransform TimeTransform_create();

OTIO_API TimeTransform
TimeTransform_create_with_offset_scale_rate(RationalTime offset, double scale, double rate);

OTIO_API RationalTime TimeTransform_offset(TimeTransform self);

OTIO_API double TimeTransform_scale(TimeTransform self);

OTIO_API double TimeTransform_rate(TimeTransform self);

OTIO_API TimeRange TimeTransform_applied_to_time_range(TimeTransform self, TimeRange other);

OTIO_API TimeTransform
TimeTransform_applied_to_time_transform(TimeTransform self, TimeTransform other);

OTIO_API RationalTime
TimeTransform_applied_to_rational_time(TimeTransform self, RationalTime other);

OTIO_API bool TimeTransform_equal(TimeTransform lhs, TimeTransform rhs);

OTIO_API bool TimeTransform_not_equal(TimeTransform lhs, TimeTransform rhs);
