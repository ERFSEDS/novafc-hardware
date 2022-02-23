use std::time::Instant;

use crate::TimeSource;

pub struct StdTimeSource {
    start_time: Instant,
}

impl StdTimeSource {
    pub fn new() -> Self {
        Self {
            start_time: Instant::now(),
        }
    }
}

impl TimeSource for StdTimeSource {
    fn get_time(&self) -> f32 {
        self.start_time.elapsed().as_secs_f32()
    }
}
