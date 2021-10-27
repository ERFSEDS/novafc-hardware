#![no_std]

pub trait Value {
    fn get_value(&self) -> f32;
}

impl<Pin> Value for Pin
where
    Pin: embedded_hal::digital::v2::InputPin,
{
    // Our implementation of Value for InputPin is just to return 1.0 if high, 0.0 if low
    fn get_value(&self) -> f32 {
        if let Ok(value) = self.is_high() {
            if value {
                1.0
            } else {
                0.0
            }
        } else {
            0.0
        }
    }
}

pub struct DataWorkspace<P>
where
    P: embedded_hal::digital::v2::InputPin,
{
    pyro_continuity: P,
}

impl<P> DataWorkspace<P>
where
    P: embedded_hal::digital::v2::InputPin,
{
    pub fn new(pyro_continuity: P) -> Self {
        Self { pyro_continuity }
    }

    pub fn value_by_string(&self, string: &str) -> f32 {
        match string {
            "PyroContinuity" => self.pyro_continuity.get_value(),
            _ => panic!("Invalid value name: {}", string),
        }
    }
}
