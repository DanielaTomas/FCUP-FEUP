public class HumanClient implements Client {
    OrderingStrategy os;

    public HumanClient(ImpatientStrategy strategy) {
        os = strategy;
    }

    public HumanClient(SmartStrategy strategy) {
        os = strategy;
    }

    public void happyHourStarted(Bar bar) {
    }

    public void happyHourEnded(Bar bar) {

    }

    public void wants(StringDrink drink, StringRecipe recipe, StringBar bar) {
        os.wants(drink,recipe,bar);
    }
}
