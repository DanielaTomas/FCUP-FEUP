public class StringInverter implements StringTransformer {

    public void execute(StringDrink drink) {
        StringBuilder s = new StringBuilder(drink.getText());
        drink.setText(s.reverse().toString());
    }

    public void undo(StringDrink drink) {
        execute(drink);
    }
}
