package pt.up.fe.ldts.example6

import spock.lang.Specification
import java.text.SimpleDateFormat

class TreeSpockTest extends Specification {
    def tree
    def date

    def setup() {
        def sdf = new SimpleDateFormat("dd-M-yyyy hh:mm:ss")
        date = sdf.parse("31-08-2002 10:20:56")
        tree = new Tree(date, "41.177772696363114", "-8.59843522310257", "FEUP")
    }

    def 'Tree Creation'() {
        expect:
            tree.plantedAt == date
            tree.locationLatitude == "41.177772696363114"
            tree.locationLongitude == "-8.59843522310257"
            tree.locationName == "FEUP"
    }

    def 'Tree Set Location'() {
        given:
            tree.setLocation("loclat", "loclon", "locname")

        expect:
            tree.plantedAt == date
            tree.locationLatitude == "loclat"
            tree.locationLongitude == "loclon"
            tree.locationName == "locname"
    }

    def 'Tree to String'() {
        when:
            def result = tree.toString()

        then:
            result == "Tree planted at Sat Aug 31 10:20:56 WEST 2002 in location 41.177772696363114,-8.59843522310257 (FEUP)"
    }

    def 'Add Appraisal'() {
        when:
            def sdf = new SimpleDateFormat("dd-M-yyyy hh:mm:ss")
            def appraisalDate = sdf.parse("31-08-2002 10:20:56")

        then:
            tree.getAppraisals().size() == 0

        and:
            tree.addAppraisal(appraisalDate)

        then:
            tree.getAppraisals().size() == 1
    }

    def 'Next Appraisal Overdue'() {
        given:
            def calendar = Calendar.getInstance()
            calendar.setTime(new Date())
            calendar.add(Calendar.MONTH, -6)

        when:
            def appraisalDate = calendar.getTime()

        then:
            !tree.isNextAppraisalOverdue()

        and:
            tree.addAppraisal(appraisalDate)

        then:
            tree.isNextAppraisalOverdue()
    }

    def 'Next Appraisal Not Overdue'() {
        given:
            def calendar = Calendar.getInstance()
            calendar.setTime(new Date());
            calendar.add(Calendar.MONTH, -1);

        when:
            def appraisalDate = calendar.getTime()

        then:
            !tree.isNextAppraisalOverdue()

        and:
            tree.addAppraisal(appraisalDate)

        then:
            !tree.isNextAppraisalOverdue()
    }
}
