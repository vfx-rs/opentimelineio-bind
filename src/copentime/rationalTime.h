#pragma once

#include "copentime/errorStatus.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct {
    double value;
    double rate;
} RationalTime;

typedef enum {
    OpenTime_IsDropFrameRate_InferFromRate = -1,
    OpenTime_IsDropFrameRate_ForceNo = 0,
    OpenTime_IsDropFrameRate_ForceYes = 1,
} OpenTime_IsDropFrameRate_;
typedef int OpenTime_IsDropFrameRate;

OTIO_API RationalTime RationalTime_create(double value, double rate);

OTIO_API bool RationalTime_is_invalid_time(RationalTime self);

OTIO_API double RationalTime_value(RationalTime self);

OTIO_API double RationalTime_rate(RationalTime self);

OTIO_API RationalTime RationalTime_rescaled_to(RationalTime self, double new_rate);

OTIO_API RationalTime RationalTime_rescaled_to_rational_time(
        RationalTime self, RationalTime rt);

OTIO_API double
RationalTime_value_rescaled_to_rate(RationalTime self, double new_rate);

OTIO_API double RationalTime_value_rescaled_to_rational_time(
        RationalTime self, RationalTime rt);

OTIO_API bool RationalTime_almost_equal(
        RationalTime self, RationalTime other, double delta);

OTIO_API RationalTime RationalTime_duration_from_start_end_time(
        RationalTime start_time, RationalTime end_time_exclusive);

OTIO_API bool RationalTime_is_valid_timecode_rate(double rate);

OTIO_API RationalTime RationalTime_from_frames(double frame, double rate);

OTIO_API RationalTime RationalTime_from_seconds(double seconds);

OTIO_API RationalTime RationalTime_from_timecode(
        const char *timecode, double rate, OpenTimeErrorStatus *error_status);

OTIO_API RationalTime RationalTime_from_time_string(
        const char *time_string, double rate, OpenTimeErrorStatus *error_status);

OTIO_API int RationalTime_to_frames(RationalTime self);

OTIO_API int RationalTime_to_frames_with_rate(RationalTime self, double rate);

OTIO_API double RationalTime_to_seconds(RationalTime self);

OTIO_API const char *RationalTime_to_timecode(
        RationalTime self,
        double rate,
        OpenTime_IsDropFrameRate drop_frame,
        OpenTimeErrorStatus *error_status);

OTIO_API const char *RationalTime_to_timecode_auto(
        RationalTime self, OpenTimeErrorStatus *error_status);

OTIO_API const char *RationalTime_to_time_string(RationalTime self);

OTIO_API RationalTime RationalTime_add(RationalTime lhs, RationalTime rhs);

OTIO_API RationalTime RationalTime_subtract(RationalTime lhs, RationalTime rhs);

OTIO_API RationalTime RationalTime_compare(RationalTime lhs, RationalTime rhs);

OTIO_API bool RationalTime_equal(RationalTime lhs, RationalTime rhs);

OTIO_API bool RationalTime_not_equal(RationalTime lhs, RationalTime rhs);
