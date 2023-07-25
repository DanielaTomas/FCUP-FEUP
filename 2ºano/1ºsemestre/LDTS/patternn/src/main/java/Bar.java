import java.util.ArrayList;
import java.util.List;

public abstract class Bar {
    private List<BarObserver> observers;
    private boolean b;

    Bar() {
        this.observers = new ArrayList<>();
    }

    public boolean isHappyHour(){
        return b;
    };

    public void startHappyHour() {
        b = true;
        notifyObservers();
    };

    public void endHappyHour() {
        b = false;
        notifyObservers();
    };

    public void addObserver(BarObserver observer) {
        observers.add(observer);
    }

    public void removeObserver(BarObserver observer) {
        observers.remove(observer);
    }

    public void notifyObservers() {
        for(BarObserver observer : observers)
            if(isHappyHour()) observer.happyHourStarted(this);
            else observer.happyHourEnded(this);
    }
}
