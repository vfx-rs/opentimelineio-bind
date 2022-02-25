#pragma once

#include "rationalTime.h"
#include "timeRange.h"
#include "timeTransform.h"
#include <opentime/rationalTime.h>
#include <opentime/timeRange.h>
#include <opentime/timeTransform.h>

inline RationalTime CppRationalTime_to_CRationalTime(opentime::RationalTime rationalTime) {
    return RationalTime_create(rationalTime.value(), rationalTime.rate());
}

inline opentime::RationalTime CRationalTime_to_CppRationalTime(RationalTime rationalTime) {
    return opentime::RationalTime(rationalTime.value, rationalTime.rate);
}

inline TimeRange CppTimeRange_to_CTimeRange(opentime::TimeRange timeRange) {
    RationalTime startTime = CppRationalTime_to_CRationalTime(timeRange.start_time());
    RationalTime duration = CppRationalTime_to_CRationalTime(timeRange.duration());
    return TimeRange_create_with_start_time_and_duration(startTime, duration);
}

inline opentime::TimeRange CTimeRange_to_CppTimeRange(TimeRange timeRange) {
    opentime::RationalTime startTime = CRationalTime_to_CppRationalTime(timeRange.start_time);
    opentime::RationalTime duration = CRationalTime_to_CppRationalTime(timeRange.duration);
    return opentime::TimeRange(startTime, duration);
}

inline TimeTransform CppTimeTransform_to_CTimeTransform(opentime::TimeTransform timeTransform) {
    RationalTime offset = CppRationalTime_to_CRationalTime(timeTransform.offset());
    return TimeTransform_create_with_offset_scale_rate(offset, timeTransform.scale(), timeTransform.rate());
}

inline opentime::TimeTransform CTimeTransform_to_CppTimeTransform(TimeTransform timeTransform) {
    opentime::RationalTime offset = CRationalTime_to_CppRationalTime(timeTransform.offset);
    return opentime::TimeTransform(offset, timeTransform.scale, timeTransform.rate);
}
