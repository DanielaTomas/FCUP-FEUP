import java.util.List;

public class StringTransformerGroup implements StringTransformer {
    private List<StringTransformer> transformers;

    StringTransformerGroup(List<StringTransformer> transformers) {
        this.transformers = transformers;
    }

    public void execute(StringDrink drink) {
        for (StringTransformer t : transformers) {
            t.execute(drink);
        }
    }

    public void undo(StringDrink drink) {
        for(StringTransformer t : transformers) {
            t.undo(drink);
        }
    }
}
