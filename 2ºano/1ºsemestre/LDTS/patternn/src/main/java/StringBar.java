public class StringBar extends Bar {
    public void order(StringDrink drink, StringRecipe recipe) {
        recipe.mix(drink);
    }
}
