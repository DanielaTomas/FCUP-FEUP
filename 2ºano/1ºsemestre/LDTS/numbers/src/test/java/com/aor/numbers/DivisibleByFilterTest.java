package com.aor.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.util.Arrays;
import java.util.List;

public class DivisibleByFilterTest {

    @Test
    void acceptDivideBy2() {
        DivisibleByFilter filter = new DivisibleByFilter(2);
        List<Integer> divisible = Arrays.asList(0, 2, 4, 50, 1002, 20024);
        List<Integer> notDivisible = Arrays.asList(1, 3, 5, 51, 1003, 20025);

        for (int n : divisible)
            Assertions.assertTrue(filter.accept(n));

        for (int n : notDivisible)
            Assertions.assertFalse(filter.accept(n));

    }

    @Test
    void acceptDivideBy3() {
        DivisibleByFilter filter = new DivisibleByFilter(3);
        List<Integer> divisible = Arrays.asList(0, 3, 6, 90, 1023, 20016);
        List<Integer> notDivisible = Arrays.asList(1, 2, 4, 50, 1003, 20015);

        for (int n : divisible)
            Assertions.assertTrue(filter.accept(n));

        for (int n : notDivisible)
            Assertions.assertFalse(filter.accept(n));

    }
}
