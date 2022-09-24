use std::fmt::Error;

use opentimelineio_sys as sys;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum ErrorStatusOutcome {
    Ok,
    InvalidTimecodeRate,
    NonDropframeRate,
    InvalidteTimecodeString,
    InvalidTimeString,
    TimecodeRateMismatch,
    NegativeValue,
    InvalidRateForDropFrameTimecode,
}

impl std::fmt::Display for ErrorStatusOutcome {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let outcome = unsafe {
            // SAFETY: The OpenTimeErrorStatus_outcome_to_string doesn't make
            // use of the ErrorStatus type at all, so should be safe to null.
            let c_outcome =
                sys::OpenTimeErrorStatus_outcome_to_string(std::ptr::null_mut(), self.into());

            // TODO: Should this return an error, or just panic?
            assert!(!c_outcome.is_null());

            // TODO: Should this return a result or panic?
            let result = std::ffi::CStr::from_ptr(c_outcome)
                .to_str()
                .unwrap()
                .to_string();
            // SAFETY: The C code creates a copy of the pointer that we should
            // clean up. So, we create a copy of the string in Rust then free
            // the C pointer.
            libc::free(c_outcome as *mut libc::c_void);

            result
        };

        f.write_str(&outcome)
    }
}

impl std::convert::From<sys::OpenTime_ErrorStatus_Outcome_> for ErrorStatusOutcome {
    fn from(status: sys::OpenTime_ErrorStatus_Outcome_) -> Self {
        match status {
            sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_OK => Self::Ok,
            sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_RATE => Self::InvalidTimecodeRate,
            sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NON_DROPFRAME_RATE => Self::NonDropframeRate,
            sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_STRING => {
                Self::InvalidteTimecodeString
            }
            sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIME_STRING => Self::InvalidTimeString,
            sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_TIMECODE_RATE_MISMATCH => Self::TimecodeRateMismatch,
            sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NEGATIVE_VALUE => Self::NegativeValue,
            sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_RATE_FOR_DROP_FRAME_TIMECODE => {
                Self::InvalidRateForDropFrameTimecode
            },
            // TODO: Should this return a result or panic?
            _ => panic!()
        }
    }
}

impl std::convert::Into<sys::OpenTime_ErrorStatus_Outcome_> for ErrorStatusOutcome {
    fn into(self) -> sys::OpenTime_ErrorStatus_Outcome_ {
        match self {
            Self::Ok=> sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_OK,
            Self::InvalidTimecodeRate=> sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_RATE,
            Self::NonDropframeRate=> sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NON_DROPFRAME_RATE,
            Self::InvalidteTimecodeString=> sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_STRING,
            Self::InvalidTimeString=> sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIME_STRING,
            Self::TimecodeRateMismatch=> sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_TIMECODE_RATE_MISMATCH,
            Self::NegativeValue=> sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NEGATIVE_VALUE,
            Self::InvalidRateForDropFrameTimecode=> sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_RATE_FOR_DROP_FRAME_TIMECODE,
        }
    }
}

impl std::convert::Into<sys::OpenTime_ErrorStatus_Outcome> for ErrorStatusOutcome {
    fn into(self) -> sys::OpenTime_ErrorStatus_Outcome {
        <Self as std::convert::Into<sys::OpenTime_ErrorStatus_Outcome_>>::into(self)
            as sys::OpenTime_ErrorStatus_Outcome
    }
}

impl std::convert::Into<sys::OpenTime_ErrorStatus_Outcome_> for &ErrorStatusOutcome {
    fn into(self) -> sys::OpenTime_ErrorStatus_Outcome_ {
        let owned_self = self.to_owned();
        owned_self.into()
    }
}

impl std::convert::Into<sys::OpenTime_ErrorStatus_Outcome> for &ErrorStatusOutcome {
    fn into(self) -> sys::OpenTime_ErrorStatus_Outcome {
        <Self as std::convert::Into<sys::OpenTime_ErrorStatus_Outcome_>>::into(self)
            as sys::OpenTime_ErrorStatus_Outcome
    }
}

#[derive(Debug)]
pub struct ErrorStatus {
    inner: *mut sys::OpenTimeErrorStatus,
}

impl ErrorStatus {
    pub fn new() -> Self {
        let inner = unsafe { sys::OpenTimeErrorStatus_create() };

        // TODO: Should this return an error, or just panic?
        assert!(!inner.is_null());

        Self { inner }
    }

    pub fn with_outcome(outcome: ErrorStatusOutcome) -> Self {
        let inner = unsafe { sys::OpenTimeErrorStatus_create_with_outcome(outcome.into()) };

        // TODO: Should this return an error, or just panic?
        assert!(!inner.is_null());

        Self { inner }
    }

    pub fn with_outcome_and_details(outcome: ErrorStatusOutcome, details: &str) -> Self {
        let inner = unsafe {
            // TODO: Should this return a result or panic?
            let c_details = std::ffi::CString::new(details).unwrap();
            // SAFETY: c_details should be copied in the otio ErrorStatus, so it
            // should be safe to drop.
            sys::OpenTimeErrorStatus_create_with_outcome_and_details(
                outcome.into(),
                c_details.as_ptr(),
            )
        };

        assert!(!inner.is_null());

        Self { inner }
    }

    pub(crate) fn as_sys_ptr(&self) -> *const sys::OpenTimeErrorStatus {
        self.inner
    }

    pub(crate) fn as_mut_sys_ptr(&mut self) -> *mut sys::OpenTimeErrorStatus {
        self.inner
    }
}

impl Drop for ErrorStatus {
    fn drop(&mut self) {
        unsafe { sys::OpenTimeErrorStatus_destroy(self.inner) }
    }
}

impl std::fmt::Display for ErrorStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        // TODO: Cannot access error status info from C API.
        todo!()
    }
}

impl std::error::Error for ErrorStatus {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_error_status_outcome_display_success() {
        let result = ErrorStatusOutcome::Ok.to_string();
        assert_eq!(&result, "");
        let result = ErrorStatusOutcome::InvalidTimecodeRate.to_string();
        assert_eq!(&result, "invalid timecode rate");
    }

    #[test]
    fn test_error_status_outcome_from_ffi_success() {
        for (sys_value, api_value) in [
            (sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_OK, ErrorStatusOutcome::Ok),
            (sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_RATE, ErrorStatusOutcome::InvalidTimecodeRate),
            (sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NON_DROPFRAME_RATE, ErrorStatusOutcome::NonDropframeRate),
            (sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_STRING, ErrorStatusOutcome::InvalidteTimecodeString),
            (sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIME_STRING, ErrorStatusOutcome::InvalidTimeString),
            (sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_TIMECODE_RATE_MISMATCH, ErrorStatusOutcome::TimecodeRateMismatch),
            (sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NEGATIVE_VALUE, ErrorStatusOutcome::NegativeValue),
            (sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_RATE_FOR_DROP_FRAME_TIMECODE, ErrorStatusOutcome::InvalidRateForDropFrameTimecode),
            ] {
                let result = ErrorStatusOutcome::from(
                    sys_value,
                );

                assert_eq!(result, api_value);
            }
    }

    #[test]
    fn test_error_status_outcome_to_ffi_success() {
        for (api_value, sys_value) in [
            (ErrorStatusOutcome::Ok, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_OK),
            (ErrorStatusOutcome::InvalidTimecodeRate, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_RATE),
            (ErrorStatusOutcome::NonDropframeRate, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NON_DROPFRAME_RATE),
            (ErrorStatusOutcome::InvalidteTimecodeString, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_STRING),
            (ErrorStatusOutcome::InvalidTimeString, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIME_STRING),
            (ErrorStatusOutcome::TimecodeRateMismatch, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_TIMECODE_RATE_MISMATCH),
            (ErrorStatusOutcome::NegativeValue, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NEGATIVE_VALUE),
            (ErrorStatusOutcome::InvalidRateForDropFrameTimecode, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_RATE_FOR_DROP_FRAME_TIMECODE),
            ] {
                let result: sys::OpenTime_ErrorStatus_Outcome_ = api_value.into();

                assert_eq!(result, sys_value);
            }

        for (api_value, sys_value) in [
            (ErrorStatusOutcome::Ok, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_OK),
            (ErrorStatusOutcome::InvalidTimecodeRate, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_RATE),
            (ErrorStatusOutcome::NonDropframeRate, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NON_DROPFRAME_RATE),
            (ErrorStatusOutcome::InvalidteTimecodeString, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_STRING),
            (ErrorStatusOutcome::InvalidTimeString, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIME_STRING),
            (ErrorStatusOutcome::TimecodeRateMismatch, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_TIMECODE_RATE_MISMATCH),
            (ErrorStatusOutcome::NegativeValue, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NEGATIVE_VALUE),
            (ErrorStatusOutcome::InvalidRateForDropFrameTimecode, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_RATE_FOR_DROP_FRAME_TIMECODE),
            ] {
                let result: sys::OpenTime_ErrorStatus_Outcome = api_value.into();

                assert_eq!(result as u32, sys_value);
            }

        for (api_value, sys_value) in &[
            (ErrorStatusOutcome::Ok, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_OK),
            (ErrorStatusOutcome::InvalidTimecodeRate, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_RATE),
            (ErrorStatusOutcome::NonDropframeRate, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NON_DROPFRAME_RATE),
            (ErrorStatusOutcome::InvalidteTimecodeString, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_STRING),
            (ErrorStatusOutcome::InvalidTimeString, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIME_STRING),
            (ErrorStatusOutcome::TimecodeRateMismatch, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_TIMECODE_RATE_MISMATCH),
            (ErrorStatusOutcome::NegativeValue, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NEGATIVE_VALUE),
            (ErrorStatusOutcome::InvalidRateForDropFrameTimecode, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_RATE_FOR_DROP_FRAME_TIMECODE),
            ] {
                let result: sys::OpenTime_ErrorStatus_Outcome_ = api_value.into();

                assert_eq!(&result, sys_value);
            }

        for (api_value, sys_value) in &[
            (ErrorStatusOutcome::Ok, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_OK),
            (ErrorStatusOutcome::InvalidTimecodeRate, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_RATE),
            (ErrorStatusOutcome::NonDropframeRate, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NON_DROPFRAME_RATE),
            (ErrorStatusOutcome::InvalidteTimecodeString, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIMECODE_STRING),
            (ErrorStatusOutcome::InvalidTimeString, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_TIME_STRING),
            (ErrorStatusOutcome::TimecodeRateMismatch, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_TIMECODE_RATE_MISMATCH),
            (ErrorStatusOutcome::NegativeValue, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_NEGATIVE_VALUE),
            (ErrorStatusOutcome::InvalidRateForDropFrameTimecode, sys::OpenTime_ErrorStatus_Outcome__OpenTime_ErrorStatus_Outcome_INVALID_RATE_FOR_DROP_FRAME_TIMECODE),
            ] {
                let result: sys::OpenTime_ErrorStatus_Outcome = api_value.into();

                assert_eq!(&(result as u32), sys_value);
            }
    }

    #[test]
    fn test_error_status_new_success() {
        ErrorStatus::new();
    }

    #[test]
    fn test_error_status_with_outcome_success() {
        ErrorStatus::with_outcome(ErrorStatusOutcome::Ok);
    }

    #[test]
    fn test_error_status_with_outcome_and_details_success() {
        ErrorStatus::with_outcome_and_details(ErrorStatusOutcome::Ok, "test");
    }
}
