public class StringCaseChanger implements StringTransformer {

    public void execute(StringDrink drink) {
        StringBuilder str = new StringBuilder(drink.getText());
        for(int i = 0; i < str.length(); i++) {
            if(Character.isLowerCase(str.charAt(i))) {
                str.setCharAt(i,Character.toUpperCase(str.charAt(i)));
            }
            else {
                str.setCharAt(i,Character.toLowerCase(str.charAt(i)));
            }
        }
        drink.setText(str.toString());
    }

    public void undo(StringDrink drink) {
       execute(drink);
    }
}
