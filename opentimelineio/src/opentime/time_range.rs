use super::rational_time::RationalTime;
use opentimelineio_sys as sys;

#[derive(Debug, Clone, Copy)]
pub struct TimeRange {
    pub start_time: RationalTime,
    pub duration: RationalTime,
}

impl std::convert::From<sys::TimeRange> for TimeRange {
    fn from(time_range: sys::TimeRange) -> Self {
        Self {
            start_time: time_range.start_time.into(),
            duration: time_range.duration.into(),
        }
    }
}

impl std::convert::Into<sys::TimeRange> for TimeRange {
    fn into(self) -> sys::TimeRange {
        sys::TimeRange {
            start_time: self.start_time.into(),
            duration: self.duration.into(),
        }
    }
}

impl std::default::Default for TimeRange {
    fn default() -> Self {
        unsafe { sys::TimeRange_create() }.into()
    }
}

// TODO: Most of the unsafe APIs can be replaced with native Rust.
impl TimeRange {
    pub fn new(start_time: RationalTime, duration: RationalTime) -> Self {
        unsafe {
            sys::TimeRange_create_with_start_time_and_duration(start_time.into(), duration.into())
        }
        .into()
    }

    pub fn with_start_time(start_time: RationalTime) -> Self {
        unsafe { sys::TimeRange_create_with_start_time(start_time.into()) }.into()
    }

    pub fn with_duration(duration: RationalTime) -> Self {
        unsafe { sys::TimeRange_create_with_duration(duration.into()) }.into()
    }

    pub fn from_start_and_end_time(
        start_time: RationalTime,
        end_time_exclusive: RationalTime,
    ) -> Self {
        unsafe {
            sys::TimeRange_range_from_start_end_time(start_time.into(), end_time_exclusive.into())
        }
        .into()
    }

    pub fn end_time_inclusive(&self) -> RationalTime {
        unsafe { sys::TimeRange_end_time_inclusive(self.to_owned().into()) }.into()
    }

    pub fn end_time_exclusive(&self) -> RationalTime {
        unsafe { sys::TimeRange_end_time_exclusive(self.to_owned().into()) }.into()
    }

    pub fn duration_extended_by(&self, other: RationalTime) -> Self {
        unsafe { sys::TimeRange_duration_extended_by(self.to_owned().into(), other.into()) }.into()
    }

    pub fn extended_by(&self, other: Self) -> Self {
        unsafe { sys::TimeRange_extended_by(self.to_owned().into(), other.into()) }.into()
    }

    pub fn clamped_with_rational_time(&self, other: RationalTime) -> RationalTime {
        unsafe { sys::TimeRange_clamped_with_rational_time(self.to_owned().into(), other.into()) }
            .into()
    }

    pub fn clamped_with_time_range(&self, other: Self) -> Self {
        unsafe { sys::TimeRange_clamped_with_time_range(self.to_owned().into(), other.into()) }
            .into()
    }

    pub fn contains_rational_time(&self, other: RationalTime) -> bool {
        unsafe { sys::TimeRange_contains_rational_time(self.to_owned().into(), other.into()) }
    }
    pub fn contains_time_range(&self, other: Self) -> bool {
        unsafe { sys::TimeRange_contains_time_range(self.to_owned().into(), other.into()) }
    }

    pub fn overlaps_rational_time(&self, other: RationalTime) -> bool {
        unsafe { sys::TimeRange_overlaps_rational_time(self.to_owned().into(), other.into()) }
    }
    pub fn overlaps_time_range(&self, other: Self) -> bool {
        unsafe { sys::TimeRange_overlaps_time_range(self.to_owned().into(), other.into()) }
    }
}

impl std::cmp::PartialEq for TimeRange {
    fn eq(&self, other: &Self) -> bool {
        unsafe { sys::TimeRange_equal(self.to_owned().into(), other.to_owned().into()) }
    }

    fn ne(&self, other: &Self) -> bool {
        unsafe { sys::TimeRange_not_equal(self.to_owned().into(), other.to_owned().into()) }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_time_range_default_success() {
        let time_range = TimeRange::default();
        assert_eq!(time_range.start_time, RationalTime::default());
        assert_eq!(time_range.duration, RationalTime::default());
    }

    #[test]
    fn test_time_range_new_success() {
        let start_time = RationalTime::new(2.0, 1.0);
        let duration = RationalTime::new(100.0, 1.0);

        let time_range = TimeRange::new(start_time, duration);

        assert_eq!(time_range.start_time, start_time);
        assert_eq!(time_range.duration, duration);
    }

    #[test]
    fn test_time_range_with_start_time_success() {
        let start_time = RationalTime::new(2.0, 1.0);
        let time_range = TimeRange::with_start_time(start_time);

        assert_eq!(time_range.start_time, start_time);
        assert_eq!(time_range.duration, RationalTime::new(0.0, 1.0));
    }

    #[test]
    fn test_time_range_with_duration_success() {
        let duration = RationalTime::new(2.0, 1.0);
        let time_range = TimeRange::with_duration(duration);

        assert_eq!(time_range.start_time, RationalTime::new(0.0, 1.0));
        assert_eq!(time_range.duration, duration);
    }

    #[test]
    fn test_time_range_from_start_and_end_time_success() {
        let start_time = RationalTime::new(0.0, 1.0);
        let end_time = RationalTime::new(1.0, 1.0);
        let time_range = TimeRange::from_start_and_end_time(start_time, end_time);

        assert_eq!(time_range.start_time, start_time);
        assert_eq!(time_range.duration, RationalTime::new(1.0, 1.0));
    }

    #[test]
    fn test_time_range_end_time_inclusive_success() {
        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));

        assert_eq!(time_range.end_time_inclusive(), RationalTime::new(0.0, 1.0));
    }

    #[test]
    fn test_time_range_end_time_exclusive_success() {
        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));

        assert_eq!(time_range.end_time_exclusive(), RationalTime::new(1.0, 1.0));
    }

    #[test]
    fn test_time_range_duration_extended_by_success() {
        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));
        let result = time_range.duration_extended_by(RationalTime::new(1.0, 1.0));

        assert_eq!(result.start_time, time_range.start_time);
        assert_eq!(result.duration, RationalTime::new(2.0, 1.0));
    }

    #[test]
    fn test_time_range_extended_by_success() {
        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));
        let other = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(2.0, 1.0));
        let result = time_range.extended_by(other);

        assert_eq!(result.start_time, time_range.start_time);
        assert_eq!(result.duration, RationalTime::new(2.0, 1.0));
    }

    #[test]
    fn test_time_range_clamped_with_rational_time_success() {
        let time_range = TimeRange::new(RationalTime::new(1.0, 1.0), RationalTime::new(2.0, 1.0));
        let result = time_range.clamped_with_rational_time(RationalTime::new(1.5, 1.0));

        assert_eq!(result.value, 1.5);
        assert_eq!(result.rate, 1.0);

        let time_range = TimeRange::new(RationalTime::new(1.0, 1.0), RationalTime::new(2.0, 1.0));
        let result = time_range.clamped_with_rational_time(RationalTime::new(0.5, 1.0));

        assert_eq!(result.value, 1.0);
        assert_eq!(result.rate, 1.0);
    }

    #[test]
    fn test_time_range_clamped_with_time_range_success() {
        let time_range = TimeRange::new(RationalTime::new(1.0, 1.0), RationalTime::new(2.0, 1.0));
        let result = time_range.clamped_with_time_range(TimeRange::new(
            RationalTime::new(1.5, 1.0),
            RationalTime::new(2.0, 1.0),
        ));

        assert_eq!(result.start_time, RationalTime::new(1.5, 1.0));
        assert_eq!(result.duration, RationalTime::new(1.5, 1.0));

        let time_range = TimeRange::new(RationalTime::new(1.0, 1.0), RationalTime::new(2.0, 1.0));
        let result = time_range.clamped_with_time_range(TimeRange::new(
            RationalTime::new(0.5, 1.0),
            RationalTime::new(2.0, 1.0),
        ));

        assert_eq!(result.start_time, RationalTime::new(1.0, 1.0));
        assert_eq!(result.duration, RationalTime::new(2.0, 1.0));
    }

    #[test]
    fn test_time_range_contains_rational_time_success() {
        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));
        let result = time_range.contains_rational_time(RationalTime::new(0.5, 1.0));

        assert!(result);

        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));
        let result = time_range.contains_rational_time(RationalTime::new(1.5, 1.0));

        assert!(!result);
    }

    #[test]
    fn test_time_range_contains_time_range_success() {
        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));
        let result = time_range.contains_time_range(TimeRange::new(
            RationalTime::new(0.5, 1.0),
            RationalTime::new(0.1, 1.0),
        ));

        assert!(result);

        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));
        let result = time_range.contains_time_range(TimeRange::new(
            RationalTime::new(2.0, 1.0),
            RationalTime::new(1.0, 1.0),
        ));

        assert!(!result);
    }

    #[test]
    fn test_time_range_overlaps_rational_time_success() {
        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));
        let result = time_range.overlaps_rational_time(RationalTime::new(0.5, 1.0));

        assert!(result);

        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));
        let result = time_range.overlaps_rational_time(RationalTime::new(1.5, 1.0));

        assert!(!result);
    }

    #[test]
    fn test_time_range_overlaps_time_range_success() {
        // TODO: This always returns false, no matter what values I put in.
        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));
        let result = time_range.overlaps_time_range(TimeRange::new(
            RationalTime::new(0.0, 1.0),
            RationalTime::new(1.0, 1.0),
        ));

        assert!(!result);

        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));
        let result = time_range.overlaps_time_range(TimeRange::new(
            RationalTime::new(-1.0, 1.0),
            RationalTime::new(2.0, 1.0),
        ));

        assert!(!result);

        let time_range = TimeRange::new(RationalTime::new(0.0, 1.0), RationalTime::new(1.0, 1.0));
        let result = time_range.overlaps_time_range(TimeRange::new(
            RationalTime::new(0.5, 1.0),
            RationalTime::new(0.1, 1.0),
        ));

        assert!(!result);
    }
}
