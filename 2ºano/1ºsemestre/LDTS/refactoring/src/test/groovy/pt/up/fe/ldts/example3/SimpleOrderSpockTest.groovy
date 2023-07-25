package pt.up.fe.ldts.example3

import spock.lang.Specification

class SimpleOrderSpockTest extends Specification {

    def 'Fixed Discount'() {
        given:
            def order = new SimpleOrder(100)

        when:
            order.setDiscount(new Discount(10))

        then:
            90 == order.getTotal()
    }

    def 'Percentage Discount'() {
        given:
            def order = new SimpleOrder(100)

        when:
            order.setDiscount(new Discount(0.2))

        then:
            80 == order.getTotal()
    }

    def 'No Discount'() {
        given:
            def order = new SimpleOrder(100)

        expect:
            100 == order.getTotal()
    }
}
