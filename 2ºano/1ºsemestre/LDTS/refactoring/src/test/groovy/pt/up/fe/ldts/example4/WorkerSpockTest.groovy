package pt.up.fe.ldts.example4

import spock.lang.Specification

import static org.junit.Assert.assertEquals
import static org.junit.Assert.assertEquals


class WorkerSpockTest extends Specification {

    def 'Worker'() {
        given:
            def worker = new Worker("John Doe", "+1 222-22222", "john", "secret")

        expect:
            worker.getName() == "John Doe"
            worker.getPhone() == "+1 222-22222"
            !worker.login("john", "wrong")
            worker.login("john", "secret")
    }

    def 'Supervisor'() {
        given:
            def supervisor = new Supervisor("John Doe", "+1 222-22222", "john", "secret")

            def minion1 = new Worker("Minion 1", "+1 123-12345", "minion1", "1234")
            def minion2 = new Worker("Minion 2", "+1 123-12345", "minion2", "1234")

        when:
            supervisor.addSupervisee(minion1);

        then:
            "John Doe" == supervisor.getName()
            "+1 222-22222" == supervisor.getPhone()
            !supervisor.login("john", "wrong")
            supervisor.login("john", "secret")
            supervisor.isSupervisee(minion1)
            !supervisor.isSupervisee(minion2)
    }

    def 'Client'() {
        given:
            def client = new Client("John Doe", "+1 222-22222");

        expect:
            "John Doe" == client.getName()
            "+1 222-22222" == client.getPhone()
    }
}
