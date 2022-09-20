use super::error_status::{ErrorStatus, ErrorStatusOutcome};
use opentimelineio_sys as sys;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum IsDropFrameRate {
    InferFrameRate,
    ForceNo,
    ForceYes,
}

impl std::convert::From<sys::OpenTime_IsDropFrameRate_> for IsDropFrameRate {
    fn from(value: sys::OpenTime_IsDropFrameRate_) -> Self {
        match value {
            sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_InferFromRate => {
                Self::InferFrameRate
            }
            sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_ForceNo => Self::ForceNo,
            sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_ForceYes => Self::ForceYes,
            // TODO: Should this panic or return a result?
            _ => panic!(),
        }
    }
}

impl std::convert::Into<sys::OpenTime_IsDropFrameRate_> for IsDropFrameRate {
    fn into(self) -> sys::OpenTime_IsDropFrameRate_ {
        match self {
            Self::InferFrameRate => {
                sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_InferFromRate
            }
            Self::ForceNo => sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_ForceNo,
            Self::ForceYes => sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_ForceYes,
        }
    }
}

#[derive(Debug, Copy, Clone)]
pub struct RationalTime {
    pub value: f64,
    pub rate: f64,
}

impl std::convert::From<sys::RationalTime> for RationalTime {
    fn from(value: sys::RationalTime) -> Self {
        Self {
            value: value.value,
            rate: value.rate,
        }
    }
}

impl std::convert::Into<sys::RationalTime> for RationalTime {
    fn into(self) -> sys::RationalTime {
        sys::RationalTime {
            value: self.value,
            rate: self.rate,
        }
    }
}

// TODO: Most of the unsafe APIs can be replaced with native Rust. The only real
// exceptions would be string -> RationalTime -> string conversions.
impl RationalTime {
    pub fn new(value: f64, rate: f64) -> Self {
        // May be sufficient to just to `Self { value, rate }` here and skip the
        // C API.
        let inner = unsafe { sys::RationalTime_create(value, rate) };

        Self {
            value: inner.value,
            rate: inner.rate,
        }
    }

    pub fn is_invalid_time(self) -> bool {
        unsafe { sys::RationalTime_is_invalid_time(self.into()) }
    }

    pub fn rescaled_to(self, new_rate: f64) -> Self {
        Self::from(unsafe { sys::RationalTime_rescaled_to(self.into(), new_rate) })
    }

    pub fn rescaled_to_rational_time(self, rt: Self) -> Self {
        Self::from(unsafe { sys::RationalTime_rescaled_to_rational_time(self.into(), rt.into()) })
    }

    pub fn value_rescaled_to_rate(self, new_rate: f64) -> f64 {
        unsafe { sys::RationalTime_value_rescaled_to_rate(self.into(), new_rate) }
    }

    pub fn value_rescaled_to_rational_time(self, rt: Self) -> f64 {
        unsafe { sys::RationalTime_value_rescaled_to_rational_time(self.into(), rt.into()) }
    }

    pub fn almost_equal(self, other: Self, delta: f64) -> bool {
        unsafe { sys::RationalTime_almost_equal(self.into(), other.into(), delta) }
    }

    pub fn duration_from_start_end_time(self, end_time_exclusive: Self) -> Self {
        Self::from(unsafe {
            sys::RationalTime_duration_from_start_end_time(self.into(), end_time_exclusive.into())
        })
    }

    pub fn is_valid_timecode_rate(rate: f64) -> bool {
        unsafe { sys::RationalTime_is_valid_timecode_rate(rate) }
    }

    pub fn from_frames(frame: f64, rate: f64) -> Self {
        Self::from(unsafe { sys::RationalTime_from_frames(frame, rate) })
    }

    pub fn from_seconds(seconds: f64) -> Self {
        Self::from(unsafe { sys::RationalTime_from_seconds(seconds) })
    }

    pub fn from_timecode(timecode: &str, rate: f64) -> Result<Self, ErrorStatus> {
        let c_timecode = match std::ffi::CString::new(timecode) {
            Ok(t) => t,
            Err(err) => {
                return Err(ErrorStatus::with_outcome_and_details(
                    ErrorStatusOutcome::InvalidteTimecodeString,
                    &err.to_string(),
                ))
            }
        };

        unsafe {
            let mut error_status = ErrorStatus::new();
            let ptr = error_status.as_mut_sys_ptr();
            let result = sys::RationalTime_from_timecode(c_timecode.as_ptr(), rate, ptr);

            // TODO: Cannot access error status result.
            todo!();

            Ok(Self::from(result))
        }
    }

    pub fn from_time_string(time_string: &str, rate: f64) -> Result<Self, ErrorStatus> {
        let c_time = match std::ffi::CString::new(time_string) {
            Ok(t) => t,
            Err(err) => {
                return Err(ErrorStatus::with_outcome_and_details(
                    ErrorStatusOutcome::InvalidteTimecodeString,
                    &err.to_string(),
                ))
            }
        };

        unsafe {
            let mut error_status = ErrorStatus::new();
            let ptr = error_status.as_mut_sys_ptr();
            // TODO: This can panic in the C layer.
            let result = sys::RationalTime_from_time_string(c_time.as_ptr(), rate, ptr);

            // TODO: Cannot access error status result.
            todo!();

            Ok(Self::from(result))
        }
    }

    pub fn to_frames(self) -> i32 {
        unsafe { sys::RationalTime_to_frames(self.into()) }
    }

    pub fn to_frames_with_rate(self, rate: f64) -> i32 {
        unsafe { sys::RationalTime_to_frames_with_rate(self.into(), rate) }
    }

    pub fn to_seconds(self) -> f64 {
        unsafe { sys::RationalTime_to_seconds(self.into()) }
    }

    pub fn to_timecode(
        self,
        rate: f64,
        drop_frame: IsDropFrameRate,
    ) -> Result<String, ErrorStatus> {
        unsafe {
            let mut error_status = ErrorStatus::new();
            let ptr = error_status.as_mut_sys_ptr();
            let c_timecode =
                sys::RationalTime_to_timecode(self.into(), rate, drop_frame.into(), ptr);

            // TODO: Cannot access error status result.
            todo!();

            match std::ffi::CStr::from_ptr(c_timecode).to_str() {
                Ok(timecode) => {
                    let timecode = timecode.to_string();
                    // SAFETY: The C code creates a copy of the pointer that we
                    // should clean up. So, we create a copy of the string in
                    // Rust then free the C pointer.
                    libc::free(c_timecode as *mut libc::c_void);
                    Ok(timecode)
                }
                Err(err) => Err(ErrorStatus::with_outcome_and_details(
                    ErrorStatusOutcome::InvalidTimeString,
                    &err.to_string(),
                )),
            }
        }
    }

    pub fn to_timecode_auto(self) -> Result<String, ErrorStatus> {
        unsafe {
            let mut error_status = ErrorStatus::new();
            let ptr = error_status.as_mut_sys_ptr();
            let c_timecode = sys::RationalTime_to_timecode_auto(self.into(), ptr);

            // TODO: Cannot access error status result.
            todo!();

            match std::ffi::CStr::from_ptr(c_timecode).to_str() {
                Ok(timecode) => {
                    let timecode = timecode.to_string();
                    // SAFETY: The C code creates a copy of the pointer that we
                    // should clean up. So, we create a copy of the string in
                    // Rust then free the C pointer.
                    libc::free(c_timecode as *mut libc::c_void);
                    Ok(timecode)
                }
                Err(err) => Err(ErrorStatus::with_outcome_and_details(
                    ErrorStatusOutcome::InvalidTimeString,
                    &err.to_string(),
                )),
            }
        }
    }

    pub fn to_time_string(self) -> String {
        unsafe {
            let c_time = sys::RationalTime_to_time_string(self.into());

            // TODO: Should this return a result or panic?
            let result = std::ffi::CStr::from_ptr(c_time)
                .to_str()
                .unwrap()
                .to_string();
            // SAFETY: The C code creates a copy of the pointer that we should
            // clean up. So, we create a copy of the string in Rust then free
            // the C pointer.
            libc::free(c_time as *mut libc::c_void);

            result
        }
    }
}

impl std::ops::Add for RationalTime {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        Self::Output::from(unsafe { sys::RationalTime_add(self.into(), rhs.into()) })
    }
}

impl std::ops::Sub for RationalTime {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        Self::Output::from(unsafe { sys::RationalTime_subtract(self.into(), rhs.into()) })
    }
}

impl std::cmp::PartialEq for RationalTime {
    fn eq(&self, other: &Self) -> bool {
        unsafe { sys::RationalTime_equal(self.to_owned().into(), other.to_owned().into()) }
    }

    fn ne(&self, other: &Self) -> bool {
        unsafe { sys::RationalTime_not_equal(self.to_owned().into(), other.to_owned().into()) }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_is_drop_frame_rate_from_sys_success() {
        assert_eq!(
            IsDropFrameRate::from(
                sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_InferFromRate
            ),
            IsDropFrameRate::InferFrameRate
        );
        assert_eq!(
            IsDropFrameRate::from(sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_ForceNo),
            IsDropFrameRate::ForceNo
        );
        assert_eq!(
            IsDropFrameRate::from(sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_ForceYes),
            IsDropFrameRate::ForceYes
        );
    }

    #[test]
    fn test_is_drop_frame_rate_into_sys_success() {
        assert_eq!(
            sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_InferFromRate,
            IsDropFrameRate::InferFrameRate.into()
        );
        assert_eq!(
            sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_ForceNo,
            IsDropFrameRate::ForceNo.into()
        );
        assert_eq!(
            sys::OpenTime_IsDropFrameRate__OpenTime_IsDropFrameRate_ForceYes,
            IsDropFrameRate::ForceYes.into()
        );
    }

    #[test]
    fn test_rational_time_from_sys_success() {
        assert_eq!(
            RationalTime::from(sys::RationalTime {
                value: 1.0,
                rate: 1.0
            }),
            RationalTime::new(1.0, 1.0)
        )
    }

    #[test]
    fn test_rational_time_into_sys_success() {
        assert!(unsafe {
            sys::RationalTime_equal(
                sys::RationalTime {
                    value: 1.0,
                    rate: 1.0,
                },
                RationalTime::new(1.0, 1.0).into(),
            )
        })
    }

    #[test]
    fn test_rational_time_is_invalid_time_success() {
        assert!(!RationalTime::new(1.0, 1.0).is_invalid_time());
        assert!(RationalTime::new(1.0, 0.0).is_invalid_time());
    }

    #[test]
    fn test_rational_time_rescaled_to_success() {
        let old_time = RationalTime::new(1.0, 24.0);
        let new_time = old_time.rescaled_to(48.0);

        assert_eq!(new_time.value, 2.0);
    }

    #[test]
    fn test_rational_time_rescaled_to_rational_time_success() {
        let old_time = RationalTime::new(1.0, 24.0);
        let new_time = old_time.rescaled_to_rational_time(RationalTime::new(1.0, 48.0));

        assert_eq!(new_time.value, 2.0);
    }

    #[test]
    fn test_rational_time_value_rescaled_to_rate_success() {
        let old_time = RationalTime::new(1.0, 24.0);
        let new_time = old_time.value_rescaled_to_rate(48.0);

        assert_eq!(new_time, 2.0);
    }

    #[test]
    fn test_rational_time_value_rescaled_to_rational_time_success() {
        let old_time = RationalTime::new(1.0, 24.0);
        let new_time = old_time.value_rescaled_to_rational_time(RationalTime::new(1.0, 48.0));

        assert_eq!(new_time, 2.0);
    }

    #[test]
    fn test_rational_time_almost_equal() {
        let a = RationalTime::new(1.0, 1.0);
        let b = RationalTime::new(1.0, 1.0);

        assert!(a.almost_equal(b, 0.1));

        let a = RationalTime::new(1.0, 1.0);
        let b = RationalTime::new(2.0, 1.0);

        assert!(!a.almost_equal(b, 0.1));
    }

    #[test]
    fn test_rational_time_from_start_end_time_success() {
        let a = RationalTime::new(1.0, 1.0);
        let b = RationalTime::new(2.0, 1.0);
        let result = a.duration_from_start_end_time(b);

        assert_eq!(result.value, 1.0);
    }

    #[test]
    fn test_rational_time_is_valid_timecode_rate() {
        assert!(RationalTime::is_valid_timecode_rate(1.0));
        assert!(!RationalTime::is_valid_timecode_rate(0.0));
    }

    #[test]
    fn test_rational_time_from_frames_success() {
        assert_eq!(
            RationalTime::new(1.0, 24.0),
            RationalTime::from_frames(1.0, 24.0)
        );
    }

    #[test]
    fn test_rational_time_from_seconds() {
        assert_eq!(RationalTime::new(1.0, 1.0), RationalTime::from_seconds(1.0));
    }

    #[test]
    #[should_panic]
    fn test_rational_time_from_timecode_success() {
        assert_eq!(
            RationalTime::from_timecode("00:00:00:01", 24.0).unwrap(),
            RationalTime::new(1.0, 1.0)
        );
    }

    #[test]
    #[should_panic]
    fn test_rational_time_from_time_string_success() {
        let a = RationalTime::from_time_string("00:00:00.041667", 24.0).unwrap();
        let b = RationalTime::new(1.0, 1.0);

        assert_eq!(a, b);
    }

    #[test]
    fn test_rational_time_to_frames_success() {
        assert_eq!(RationalTime::new(1.0, 24.0).to_frames(), 1);
    }

    #[test]
    fn test_rational_time_to_frames_with_rate_success() {
        assert_eq!(RationalTime::new(1.0, 24.0).to_frames_with_rate(24.0), 1);
    }

    #[test]
    fn test_rational_time_to_seconds_success() {
        assert_eq!(RationalTime::new(24.0, 24.0).to_seconds(), 1.0);
    }

    #[test]
    #[should_panic]
    fn test_rational_time_to_timecode_success() {
        assert_eq!(
            &RationalTime::new(1.0, 1.0)
                .to_timecode(1.0, IsDropFrameRate::ForceNo)
                .unwrap(),
            "00:00:00:01"
        );
    }

    #[test]
    #[should_panic]
    fn test_rational_time_to_timecode_auto_success() {
        assert_eq!(
            &RationalTime::new(1.0, 1.0).to_timecode_auto().unwrap(),
            "00:00:00:01"
        );
    }

    #[test]
    fn test_rational_time_to_time_string_success() {
        assert_eq!(&RationalTime::new(1.0, 1.0).to_time_string(), "00:00:01.0");
    }

    #[test]
    fn test_rational_time_add_success() {
        let a = RationalTime::new(1.0, 1.0);
        let b = RationalTime::new(1.0, 1.0);

        assert_eq!(a + b, RationalTime::new(2.0, 1.0));
    }

    #[test]
    fn test_rational_time_subtract_success() {
        let a = RationalTime::new(1.0, 1.0);
        let b = RationalTime::new(1.0, 1.0);

        assert_eq!(a - b, RationalTime::new(0.0, 1.0));
    }

    #[test]
    fn test_rational_time_partial_eq_success() {
        let a = RationalTime::new(1.0, 1.0);
        let b = RationalTime::new(1.0, 1.0);

        assert!(a == b);

        let a = RationalTime::new(1.0, 1.0);
        let b = RationalTime::new(2.0, 1.0);

        assert!(a != b);
    }
}
