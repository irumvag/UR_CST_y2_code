import java.applet.Applet;
import java.applet.AudioClip;
import java.net.URL;

public class SoundPlayer {
    public static void playSound(String filename) {
        try {
            URL soundURL = SoundPlayer.class.getResource(filename);
            AudioClip clip = Applet.newAudioClip(soundURL);
            clip.play();
        } catch (Exception e) {
            System.out.println("Sound file not found: " + filename);
        }
    }
}
