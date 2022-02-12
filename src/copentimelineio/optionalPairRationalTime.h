#pragma once

#include "copentime/optionalOpenTime.h"

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

struct OptionalPairRationalTime;
typedef struct OptionalPairRationalTime OptionalPairRationalTime;

OTIO_API OptionalPairRationalTime *
OptionalPairRationalTime_create(OptionalRationalTime first, OptionalRationalTime second);

OTIO_API OptionalRationalTime
OptionalPairRationalTime_first(OptionalPairRationalTime *self);

OTIO_API OptionalRationalTime
OptionalPairRationalTime_second(OptionalPairRationalTime *self);

OTIO_API void OptionalPairRationalTime_destroy(OptionalPairRationalTime *self);
