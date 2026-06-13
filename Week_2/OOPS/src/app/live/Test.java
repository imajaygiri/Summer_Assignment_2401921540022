package live;

import music.Playable;
import music.string.Veena;
import music.wind.Saxophone;

public class Test {
    public static void testFxn() {
        Veena v = new Veena("Veena using class Veena");
        v.play();
        Saxophone s = new Saxophone("Saxophone using class Saxo");
        s.play();
        Playable v_playable = new Veena("Veena using interface");
        v_playable.play();
        Playable s_playable = new Saxophone("Sexa using interface");
        s_playable.play();

    }
}
