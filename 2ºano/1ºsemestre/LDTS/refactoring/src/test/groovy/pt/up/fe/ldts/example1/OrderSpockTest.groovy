package pt.up.fe.ldts.example1


import spock.lang.Specification

class OrderSpockTest extends Specification {

    def 'Is Elegible For Free Delivery (Small)'() {
        given:
            def order = new Order()
            order.add(new Product("Lollipop", 5), 10)

        when:
            def result = order.isElegibleForFreeDelivery()

        then:
            result == false
    }

    def 'Is Elegible For Free Delivery (Large)'() {
        given:
            def order = new Order()
            order.add(new Product("Playstation 4", 400), 2)
            order.add(new Product("Red Dead Redemption 2", 50), 1)

        when:
            def result = order.isElegibleForFreeDelivery()

        then:
            result == true
    }


    def 'Print Order'() {
        given:
        def order = new Order()
        order.add(new Product("Playstation 4", 400), 2);
        order.add(new Product("Red Dead Redemption 2", 50), 1);

        when:
        def result = order.printOrder()

        then:
        result == "Playstation 4(x2): 800.0\n" +
                "Red Dead Redemption 2(x1): 50.0\n" +
                "Total: 850.0"
    }
}
