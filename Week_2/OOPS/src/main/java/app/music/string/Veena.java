package music.string;

import music.Playable;

public class Veena implements Playable {
    String args;

    public Veena(String args) {
        this.args = args;
    }

    @Override
    public void play() {

        System.out.println(this.args);
    }
}
