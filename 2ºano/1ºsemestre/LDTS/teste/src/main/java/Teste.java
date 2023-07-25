import com.googlecode.lanterna.*;
import com.googlecode.lanterna.graphics.AbstractTextGraphics;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.googlecode.lanterna.screen.Screen;
import com.googlecode.lanterna.screen.TerminalScreen;
import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;
import com.googlecode.lanterna.terminal.swing.AWTTerminalFontConfiguration;
import com.googlecode.lanterna.terminal.swing.AWTTerminalFrame;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.IOException;
import java.net.URISyntaxException;
import java.net.URL;

public class Teste {
    public static void main(String[] args) throws IOException, FontFormatException, URISyntaxException {
        new Teste().run();
    }

    private void run() throws IOException, FontFormatException, URISyntaxException {
        URL resource = getClass().getClassLoader().getResource("square.ttf");
        File fontFile = new File(resource.toURI());
        Font font =  Font.createFont(Font.TRUETYPE_FONT, fontFile);

        GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
        ge.registerFont(font);

        DefaultTerminalFactory factory = new DefaultTerminalFactory();

        Font loadedFont = font.deriveFont(Font.PLAIN, 25);
        AWTTerminalFontConfiguration fontConfig = AWTTerminalFontConfiguration.newInstance(loadedFont);
        factory.setTerminalEmulatorFontConfiguration(fontConfig);
        factory.setForceAWTOverSwing(true);
        factory.setInitialTerminalSize(new TerminalSize(60, 30));

        Terminal terminal = factory.createTerminal();
        ((AWTTerminalFrame)terminal).addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                e.getWindow().dispose();
            }
        });

        Screen screen = new TerminalScreen(terminal);
        screen.setCursorPosition(null);   // we don't need a cursor
        screen.startScreen();             // screens must be started
        screen.doResizeIfNecessary();     // resize screen if necessary
        TextGraphics graphics = screen.newTextGraphics();

        //graphics.setBackgroundColor(TextColor.Factory.fromString("#EEE8AA"));
        //graphics.fillRectangle(new TerminalPosition(0, 0), new TerminalSize(40, 20), ' ');

/*frente
        graphics.enableModifiers(SGR.BOLD);
        graphics.setForegroundColor(TextColor.Factory.fromString("#DAA520"));
        graphics.putString(new TerminalPosition(10, 10), "1");
        graphics.setForegroundColor(TextColor.Factory.fromString("#FFDEAD"));
        graphics.putString(new TerminalPosition(10, 11), "2");
        //graphics.putString(new TerminalPosition(10, 11), "5");
        graphics.setForegroundColor(TextColor.Factory.fromString("#A0522D"));
        graphics.putString(new TerminalPosition(10, 12), "3");
        graphics.setForegroundColor(TextColor.Factory.fromString("#CD853F"));
        graphics.putString(new TerminalPosition(10, 13), "4"); */

/*tras
        graphics.setForegroundColor(TextColor.Factory.fromString("#DAA520"));
        graphics.putString(new TerminalPosition(12, 10), "1");
        graphics.setForegroundColor(TextColor.Factory.fromString("#FFDEAD"));
        graphics.putString(new TerminalPosition(12, 11), "5");
        graphics.setForegroundColor(TextColor.Factory.fromString("#A0522D"));
        graphics.putString(new TerminalPosition(12, 12), "3");
        graphics.setForegroundColor(TextColor.Factory.fromString("#CD853F"));
        graphics.putString(new TerminalPosition(12, 13), "4");
        //screen.setCharacter(10, 10, TextCharacter.fromCharacter('1')[0]);
        //screen.setCharacter(10, 11, TextCharacter.fromCharacter('2')[0]); */

/*lado direito
        graphics.setForegroundColor(TextColor.Factory.fromString("#DAA520"));
        graphics.putString(new TerminalPosition(14, 10), "6");
        graphics.setForegroundColor(TextColor.Factory.fromString("#FFDEAD"));
        graphics.putString(new TerminalPosition(14, 11), "7");
        graphics.setForegroundColor(TextColor.Factory.fromString("#A0522D"));
        graphics.putString(new TerminalPosition(14, 12), "8");
        graphics.setForegroundColor(TextColor.Factory.fromString("#CD853F"));
        graphics.putString(new TerminalPosition(14, 13), "9");
        screen.refresh();*/

/*lado esquerdo
        graphics.setForegroundColor(TextColor.Factory.fromString("#DAA520"));
        graphics.putString(new TerminalPosition(16, 10), "6");
        graphics.setForegroundColor(TextColor.Factory.fromString("#FFDEAD"));
        graphics.putString(new TerminalPosition(16, 11), "A");
        graphics.setForegroundColor(TextColor.Factory.fromString("#A0522D"));
        graphics.putString(new TerminalPosition(16, 12), "8");
        graphics.setForegroundColor(TextColor.Factory.fromString("#CD853F"));
        graphics.putString(new TerminalPosition(16, 13), "B");*/



        graphics.setForegroundColor(TextColor.Factory.fromString("#FFFFF0"));
        graphics.putString(new TerminalPosition(10, 10), "@");

        screen.refresh();
    }
}
