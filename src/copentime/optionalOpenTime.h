#pragma once

#include "rationalTime.h"
#include "timeRange.h"
#include "timeTransform.h"

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct {
    RationalTime value;
    bool valid;
} OptionalRationalTime;

OTIO_API OptionalRationalTime OptionalRationalTime_create(RationalTime rationalTime);

OTIO_API OptionalRationalTime OptionalRationalTime_create_null();

OTIO_API bool OptionalRationalTime_valid(OptionalRationalTime optionalRationalTime);

OTIO_API RationalTime OptionalRationalTime_value(OptionalRationalTime optionalRationalTime);

typedef struct {
    TimeRange value;
    bool valid;
} OptionalTimeRange;

OTIO_API OptionalTimeRange OptionalTimeRange_create(TimeRange timeRange);

OTIO_API OptionalTimeRange OptionalTimeRange_create_null();

OTIO_API bool OptionalTimeRange_valid(OptionalTimeRange optionalTimeRange);

OTIO_API TimeRange OptionalTimeRange_value(OptionalTimeRange optionalTimeRange);
