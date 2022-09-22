use super::rational_time::RationalTime;
use super::time_range::TimeRange;
use opentimelineio_sys as sys;

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum OptionalRationalTime {
    Valid(RationalTime),
    Invalid,
}

impl std::convert::From<sys::OptionalRationalTime> for OptionalRationalTime {
    fn from(optional_rational_time: sys::OptionalRationalTime) -> Self {
        if optional_rational_time.valid {
            Self::Valid(optional_rational_time.value.into())
        } else {
            Self::Invalid
        }
    }
}

impl std::convert::Into<sys::OptionalRationalTime> for OptionalRationalTime {
    fn into(self) -> sys::OptionalRationalTime {
        match self {
            Self::Valid(rational_time) => unsafe {
                sys::OptionalRationalTime_create(rational_time.into())
            },
            // SAFETY: The create_null's value field is unset, so accessing that
            // is undefined.
            Self::Invalid => unsafe { sys::OptionalRationalTime_create_null() },
        }
    }
}

impl std::default::Default for OptionalRationalTime {
    fn default() -> Self {
        Self::Invalid
    }
}

impl OptionalRationalTime {
    pub fn new(rational_time: RationalTime) -> Self {
        unsafe { sys::OptionalRationalTime_create(rational_time.into()) }.into()
    }

    pub fn is_valid(&self) -> bool {
        match self {
            Self::Valid(_) => true,
            Self::Invalid => false,
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum OptionalTimeRange {
    Valid(TimeRange),
    Invalid,
}

impl std::convert::From<sys::OptionalTimeRange> for OptionalTimeRange {
    fn from(optional_time_range: sys::OptionalTimeRange) -> Self {
        if optional_time_range.valid {
            Self::Valid(optional_time_range.value.into())
        } else {
            Self::Invalid
        }
    }
}

impl std::convert::Into<sys::OptionalTimeRange> for OptionalTimeRange {
    fn into(self) -> sys::OptionalTimeRange {
        match self {
            Self::Valid(time_range) => sys::OptionalTimeRange {
                value: time_range.into(),
                valid: true,
            },
            Self::Invalid => unsafe { sys::OptionalTimeRange_create_null() },
        }
    }
}

impl std::default::Default for OptionalTimeRange {
    fn default() -> Self {
        Self::Invalid
    }
}

impl OptionalTimeRange {
    pub fn new(time_range: TimeRange) -> Self {
        unsafe { sys::OptionalTimeRange_create(time_range.into()) }.into()
    }

    pub fn is_valid(&self) -> bool {
        match self {
            Self::Valid(_) => true,
            Self::Invalid => false,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_optional_rational_time_new_success() {
        let optional_rational_time = OptionalRationalTime::new(RationalTime::new(0.0, 1.0));
        assert_eq!(
            optional_rational_time,
            OptionalRationalTime::Valid(RationalTime::new(0.0, 1.0))
        );
        assert!(optional_rational_time.is_valid());

        let optional_rational_time = OptionalRationalTime::default();
        assert_eq!(optional_rational_time, OptionalRationalTime::Invalid);
        assert!(!optional_rational_time.is_valid());
    }

    #[test]
    fn test_optional_rational_time_into_sys() {
        let optional_rational_time = OptionalRationalTime::new(RationalTime::new(0.0, 1.0));
        let sys_optional_rational_time: sys::OptionalRationalTime = optional_rational_time.into();

        assert_eq!(sys_optional_rational_time.value.value, 0.0);
        assert_eq!(sys_optional_rational_time.value.rate, 1.0);
        assert_eq!(sys_optional_rational_time.valid, true);

        let optional_rational_time = OptionalRationalTime::default();
        let sys_optional_rational_time: sys::OptionalRationalTime = optional_rational_time.into();

        assert_eq!(sys_optional_rational_time.valid, false);
    }

    #[test]
    fn test_optional_rational_time_from_invalid() {
        let sys_optional_rational_time = unsafe { sys::OptionalRationalTime_create_null() };
        let optional_rational_time: OptionalRationalTime = sys_optional_rational_time.into();

        assert_eq!(optional_rational_time, OptionalRationalTime::Invalid);
    }

    #[test]
    fn test_optional_time_range_new_success() {
        let optional_time_range = OptionalTimeRange::new(TimeRange::new(
            RationalTime::new(0.0, 1.0),
            RationalTime::new(1.0, 1.0),
        ));
        assert_eq!(
            optional_time_range,
            OptionalTimeRange::Valid(TimeRange::new(
                RationalTime::new(0.0, 1.0),
                RationalTime::new(1.0, 1.0),
            ))
        );
        assert!(optional_time_range.is_valid());

        let optional_time_range = OptionalTimeRange::default();
        assert_eq!(optional_time_range, OptionalTimeRange::Invalid);
        assert!(!optional_time_range.is_valid());
    }

    #[test]
    fn test_optional_time_range_into_sys() {
        let optional_time_range = OptionalTimeRange::new(TimeRange::new(
            RationalTime::new(0.0, 1.0),
            RationalTime::new(1.0, 1.0),
        ));
        let sys_optional_time_range: sys::OptionalTimeRange = optional_time_range.into();
        assert_eq!(sys_optional_time_range.value.start_time.value, 0.0);
        assert_eq!(sys_optional_time_range.value.start_time.rate, 1.0);
        assert_eq!(sys_optional_time_range.value.duration.value, 1.0);
        assert_eq!(sys_optional_time_range.value.duration.rate, 1.0);
        assert_eq!(sys_optional_time_range.valid, true);

        let optional_time_range = OptionalTimeRange::default();
        let sys_optional_time_range: sys::OptionalTimeRange = optional_time_range.into();
        assert_eq!(sys_optional_time_range.valid, false);
    }

    #[test]
    fn test_optional_time_range_from_invalid() {
        let sys_optional_time_range = unsafe { sys::OptionalTimeRange_create_null() };
        let optional_time_range: OptionalTimeRange = sys_optional_time_range.into();

        assert_eq!(optional_time_range, OptionalTimeRange::Invalid);
    }
}
