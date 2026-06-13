package music.wind;

import music.Playable;

public class Saxophone implements Playable {
    String args;

    public Saxophone(String args) {
        this.args = args;
    }

    @Override
    public void play() {
        System.out.println(args);
    }
}
