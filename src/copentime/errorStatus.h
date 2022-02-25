#pragma once

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct OpenTimeErrorStatus OpenTimeErrorStatus;
typedef struct ErrorStatus ErrorStatus;

typedef enum
{
    OpenTime_ErrorStatus_Outcome_OK                                   = 0,
    OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_RATE                = 1,
    OpenTime_ErrorStatus_Outcome_NON_DROPFRAME_RATE                   = 2,
    OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_STRING              = 3,
    OpenTime_ErrorStatus_Outcome_INVALID_TIME_STRING                  = 4,
    OpenTime_ErrorStatus_Outcome_TIMECODE_RATE_MISMATCH               = 5,
    OpenTime_ErrorStatus_Outcome_NEGATIVE_VALUE                       = 6,
    OpenTime_ErrorStatus_Outcome_INVALID_RATE_FOR_DROP_FRAME_TIMECODE = 7,
} OpenTime_ErrorStatus_Outcome_;

typedef int OpenTime_ErrorStatus_Outcome;
OTIO_API OpenTimeErrorStatus* OpenTimeErrorStatus_create();
OTIO_API OpenTimeErrorStatus* OpenTimeErrorStatus_create_with_outcome(
             OpenTime_ErrorStatus_Outcome in_outcome);
OTIO_API OpenTimeErrorStatus* OpenTimeErrorStatus_create_with_outcome_and_details(
             OpenTime_ErrorStatus_Outcome in_outcome, const char* in_details);
OTIO_API const char* OpenTimeErrorStatus_outcome_to_string(
             OpenTimeErrorStatus* self, OpenTime_ErrorStatus_Outcome var1);
OTIO_API void OpenTimeErrorStatus_destroy(OpenTimeErrorStatus* self);
