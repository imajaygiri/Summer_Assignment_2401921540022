use crate::music::playable::Playable;

pub struct Veena {
    args: String,
}

impl Veena {
    pub fn new(args: String) -> Self {
        Self { args }
    }
}

impl Playable for Veena {
    fn play(&self) {
        println!("{}", self.args);
    }
}
