package pt.up.fe.ldts.example4;

public class Client extends Worker {

    public Client(String name, String phone) {
        super(name, phone, null, null);
    }

    @Override
    public boolean login(String username, String password) {
        return false;
    }
}
