package pt.up.fe.ldts.example4;

import java.util.HashSet;
import java.util.Set;

public class Supervisor extends Worker {
    Set<Worker> supervisee;
    
    public Supervisor(String name, String phone, String username, String password) {
        super(name, phone, username, password);
        supervisee = new HashSet<>();
    }
    
    public void addSupervisee(Worker worker) {
        supervisee.add(worker);
    }

    public boolean isSupervisee(Worker worker) {
        return supervisee.contains(worker);
    }
}
