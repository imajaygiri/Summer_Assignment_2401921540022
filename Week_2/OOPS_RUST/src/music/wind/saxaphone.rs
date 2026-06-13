use crate::music::playable::Playable;

pub struct Saxaphone {
    args: String,
}

impl Saxaphone {
    pub fn new(args: String) -> Self {
        Self { args }
    }
}

impl Playable for Saxaphone {
    fn play(&self) {
        println!("{}", self.args);
    }
}
