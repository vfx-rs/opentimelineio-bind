#pragma once

#include "any.h"
#include "anyDictionary.h"
#include "anyVector.h"
#include "copentime/rationalTime.h"
#include "copentime/timeRange.h"
#include "copentime/timeTransform.h"
#include "serializableObject.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

OTIO_API Any *create_safely_typed_any_bool(bool boolValue);
OTIO_API Any *create_safely_typed_any_int(int intValue);
OTIO_API Any *create_safely_typed_any_int64(int64_t int64Value);
OTIO_API Any *create_safely_typed_any_double(double doubleValue);
OTIO_API Any *create_safely_typed_any_string(const char *stringValue);
OTIO_API Any *create_safely_typed_any_rational_time(RationalTime rationalTimeValue);
OTIO_API Any *create_safely_typed_any_time_range(TimeRange timeRangeValue);
OTIO_API Any *
create_safely_typed_any_time_transform(TimeTransform timeTransformValue);
OTIO_API Any *create_safely_typed_any_any_vector(AnyVector *anyVectorValue);
OTIO_API Any *
create_safely_typed_any_any_dictionary(AnyDictionary *anyDictionaryValue);
OTIO_API Any *create_safely_typed_any_serializable_object(
        OTIOSerializableObject *serializableObjectValue);

OTIO_API bool safely_cast_bool_any(Any *a);
OTIO_API int safely_cast_int_any(Any *a);
OTIO_API int64_t safely_cast_int64_any(Any *a);
OTIO_API double safely_cast_double_any(Any *a);
OTIO_API const char *safely_cast_string_any(Any *a);
OTIO_API RationalTime safely_cast_rational_time_any(Any *a);
OTIO_API TimeRange safely_cast_time_range_any(Any *a);
OTIO_API TimeTransform safely_cast_time_transform_any(Any *a);
OTIO_API OTIOSerializableObject *safely_cast_retainer_any(Any *a);

OTIO_API AnyDictionary *safely_cast_any_dictionary_any(Any *a);
OTIO_API AnyVector *safely_cast_any_vector_any(Any *a);
