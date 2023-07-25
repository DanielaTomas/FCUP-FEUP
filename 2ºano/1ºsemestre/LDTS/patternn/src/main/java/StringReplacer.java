public class StringReplacer implements StringTransformer {
    private char ch1, ch2;

    StringReplacer(char ch1, char ch2) {
        this.ch1 = ch1;
        this.ch2 = ch2;
    }

    public void execute(StringDrink drink) {
        drink.setText(drink.getText().replace(ch1,ch2));
    }

    public void undo(StringDrink drink) {
        drink.setText(drink.getText().replace(ch2,ch1));
    }
}
