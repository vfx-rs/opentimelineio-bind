use super::rational_time::RationalTime;
use super::time_range::TimeRange;
use opentimelineio_sys as sys;

#[derive(Debug, Copy, Clone)]
pub struct TimeTransform {
    pub offset: RationalTime,
    pub scale: f64,
    pub rate: f64,
}

impl std::convert::From<sys::TimeTransform> for TimeTransform {
    fn from(time_transform: sys::TimeTransform) -> Self {
        Self {
            offset: time_transform.offset.into(),
            scale: time_transform.scale,
            rate: time_transform.rate,
        }
    }
}

impl std::convert::Into<sys::TimeTransform> for TimeTransform {
    fn into(self) -> sys::TimeTransform {
        sys::TimeTransform {
            offset: self.offset.into(),
            scale: self.scale,
            rate: self.rate,
        }
    }
}

impl std::default::Default for TimeTransform {
    fn default() -> Self {
        unsafe { sys::TimeTransform_create() }.into()
    }
}

impl std::cmp::PartialEq for TimeTransform {
    fn eq(&self, other: &Self) -> bool {
        unsafe { sys::TimeTransform_equal(self.to_owned().into(), other.to_owned().into()) }
    }

    fn ne(&self, other: &Self) -> bool {
        unsafe { sys::TimeTransform_not_equal(self.to_owned().into(), other.to_owned().into()) }
    }
}

impl TimeTransform {
    pub fn new(offset: RationalTime, scale: f64, rate: f64) -> Self {
        unsafe { sys::TimeTransform_create_with_offset_scale_rate(offset.into(), scale, rate) }
            .into()
    }

    pub fn applied_to_rational_time(&self, other: RationalTime) -> RationalTime {
        unsafe { sys::TimeTransform_applied_to_rational_time(self.to_owned().into(), other.into()) }
            .into()
    }

    pub fn applied_to_time_range(&self, other: TimeRange) -> TimeRange {
        unsafe { sys::TimeTransform_applied_to_time_range(self.to_owned().into(), other.into()) }
            .into()
    }

    pub fn applied_to_time_transform(&self, other: Self) -> Self {
        unsafe {
            sys::TimeTransform_applied_to_time_transform(self.to_owned().into(), other.into())
        }
        .into()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_time_transform_new_success() {
        let time_transform = TimeTransform::new(RationalTime::new(2.0, 1.0), 2.0, 3.0);
        assert_eq!(time_transform.offset, RationalTime::new(2.0, 1.0));
        assert_eq!(time_transform.scale, 2.0);
        assert_eq!(time_transform.rate, 3.0);
    }

    #[test]
    fn test_time_transform_default_success() {
        let time_transform = TimeTransform::default();
        assert_eq!(time_transform.offset, RationalTime::new(0.0, 1.0));
        assert_eq!(time_transform.scale, 1.0);
        assert_eq!(time_transform.rate, -1.0);
    }

    #[test]
    fn test_time_transform_applied_to_rational_time_success() {
        let time_transform = TimeTransform::new(RationalTime::new(2.0, 1.0), 2.0, 3.0);
        let result = time_transform.applied_to_rational_time(RationalTime::new(0.0, 1.0));

        assert_eq!(result, RationalTime::new(6.0, 3.0));
    }

    #[test]
    fn test_time_transform_applied_to_time_range_success() {
        let time_transform = TimeTransform::new(RationalTime::new(2.0, 1.0), 2.0, 3.0);
        let result = time_transform.applied_to_time_range(TimeRange::new(
            RationalTime::new(0.0, 1.0),
            RationalTime::new(1.0, 1.0),
        ));

        assert_eq!(
            result,
            TimeRange::new(RationalTime::new(6.0, 3.0), RationalTime::new(6.0, 3.0))
        );
    }

    #[test]
    fn test_time_transform_applied_to_time_transform_success() {
        let time_transform = TimeTransform::new(RationalTime::new(2.0, 1.0), 2.0, 3.0);
        let result = time_transform.applied_to_time_transform(TimeTransform::new(
            RationalTime::new(2.0, 1.0),
            2.0,
            3.0,
        ));

        assert_eq!(
            result,
            TimeTransform::new(RationalTime::new(4.0, 1.0), 4.0, 3.0)
        );
    }
}
