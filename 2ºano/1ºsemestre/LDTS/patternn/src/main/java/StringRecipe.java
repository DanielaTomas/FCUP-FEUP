import java.util.List;

public class StringRecipe {
    List<StringTransformer> transformers;

    StringRecipe(List<StringTransformer> transformers) {
        this.transformers = transformers;
    }

    public void mix(StringDrink drink) {
        for (StringTransformer t : transformers) {
            t.execute(drink);
        }
    }
}
