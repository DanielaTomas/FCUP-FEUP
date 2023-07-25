package pt.up.fe.ldts.example2

import spock.lang.Specification
import static spock.util.matcher.HamcrestMatchers.closeTo

class ShapeSpockTest extends Specification {

    def 'Get Area Circle'() {
        given:
            def circle = new Shape(5, 5, 10)

        when:
            def result = circle.getArea()

        then:
            result closeTo(314.16 , 0.01)
    }

    def 'Get Area Rectangle'() {
        given:
            def rectangle = new Shape(5, 5, 10, 20)

        when:
            def result = rectangle.getArea()

        then:
            200 == result
    }

    def 'Get Perimeter Circle'() {
        given:
            def circle = new Shape(5, 5, 10)

        when:
            def result = circle.getPerimeter()

        then:
            result closeTo(62.83, 0.01)
    }

    def 'Get Perimeter Rectangle'() {
        given:
            def rectangle = new Shape(5, 5, 10, 20)

        when:
            def result = rectangle.getPerimeter()

        then:
            60 == result
    }

    def 'Draw Circle'() {
        given:
            def graphics = Mock(GraphicFramework.class)
            def circle = new Shape(5, 5, 10)

        when:
            circle.draw(graphics)

        then:
            1 * graphics.drawCircle(5, 5, 10)
    }

    def 'Draw Rectangle'() {
        given:
        def graphics = Mock(GraphicFramework.class)
        def rectangle = new Shape(5, 5, 10, 20);

        when:
        rectangle.draw(graphics)

        then:
        1 * graphics.drawLine(5, 5, 15, 5)
        1 * graphics.drawLine(15, 5, 15, 25)
        1 * graphics.drawLine(15, 25, 5, 25)
        1 * graphics.drawLine(5, 25, 5, 5)

    }
}
