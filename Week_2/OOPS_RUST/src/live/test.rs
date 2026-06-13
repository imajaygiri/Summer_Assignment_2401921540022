use crate::music::{playable::Playable, string::veena::Veena, wind::saxaphone::Saxaphone};

pub fn test() {
    let veena: Veena = Veena::new(String::from("This is veena"));
    let saxaphone: Saxaphone = Saxaphone::new(String::from("This is Saxaphone"));

    veena.play();
    saxaphone.play();

    let playables: Vec<Box<dyn Playable>> = vec![
        Box::new(Veena::new(String::from(
            "This is veena using traits/interface",
        ))),
        Box::new(Saxaphone::new(String::from(
            "This is Saxa suing traints/interface",
        ))),
    ];

    for p in playables.iter() {
        p.play();
    }
}
