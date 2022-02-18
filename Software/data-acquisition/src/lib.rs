#![cfg_attr(not(feature = "std"), no_std)]

use std::time::SystemTime;

use nova_software_common::{CheckObject, ObjectState};

pub trait TimeSource {
    fn get_time(&self) -> f32;
}

mod time_std;
pub use time_std::*;

pub struct DataWorkspace {
    altitude: DataObject,
    pyro1: DataObject,
    pyro2: DataObject,
    pyro3: DataObject,
}

impl DataWorkspace {
    pub fn new() -> Self {
        let now = SystemTime::now();

        let altitude = DataObject::DurationBased(DurationBased::new(
            ObjectState::Flag(false),
            ObjectState::Flag(true),
            20.0,
            now,
        ));

        let pyro1 = DataObject::DurationBased(DurationBased::new(
            ObjectState::Flag(false),
            ObjectState::Flag(true),
            2.0,
            now,
        ));
        let pyro2 = DataObject::DurationBased(DurationBased::new(
            ObjectState::Flag(false),
            ObjectState::Flag(true),
            2.0,
            now,
        ));
        let pyro3 = DataObject::DurationBased(DurationBased::new(
            ObjectState::Flag(false),
            ObjectState::Flag(true),
            2.0,
            now,
        ));

        Self {
            altitude,
            pyro1,
            pyro2,
            pyro3,
        }
    }

    pub fn get_object(&self, object: CheckObject) -> ObjectState {
        let object = match object {
            CheckObject::Altitude => &self.altitude,
            CheckObject::Pyro1Continuity => &self.pyro1,
            CheckObject::Pyro2Continuity => &self.pyro2,
            CheckObject::Pyro3Continuity => &self.pyro3,
        };

        object.read()
    }
}

/// A struct that stores a GPIO pin that can be read at any time
struct Gpio {
    pin: u16,
}

impl Gpio {
    fn new(pin: u16) -> Self {
        Self { pin }
    }

    fn read(&self) -> ObjectState {
        unimplemented!();
    }
}

/// Represents any source of an ObjectState
enum DataObject {
    Gpio(Gpio),
    DurationBased(DurationBased),
}

impl DataObject {
    fn read(&self) -> ObjectState {
        match self {
            Self::Gpio(gpio) => gpio.read(),
            Self::DurationBased(db) => db.read(),
        }
    }
}

// Just for testing, allowing us to simulate some events
struct DurationBased {
    pub before: ObjectState,
    pub after: ObjectState,
    pub time: f32,
    pub start: SystemTime,
}

impl DurationBased {
    pub fn new(before: ObjectState, after: ObjectState, time: f32, start: SystemTime) -> Self {
        Self {
            before,
            after,
            time,
            start,
        }
    }

    fn read(&self) -> ObjectState {
        let elapsed = self.start.elapsed().unwrap().as_secs_f32();

        if elapsed > self.time {
            self.after
        } else {
            self.before
        }
    }
}
