package com.aor.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

public class PositiveFilterTest {

    @Test
    void accept() {
        PositiveFilter filter = new PositiveFilter();
        List<Integer> positives = Arrays.asList(1, 2, 3, 50, 1000, 20021);
        List<Integer> notPositives = Arrays.asList(0, -1, -2, -3, -50, -1000, -20021);

        for (int n : positives)
            Assertions.assertTrue(filter.accept(n));

        for (int n : notPositives)
            Assertions.assertFalse(filter.accept(n));
    }

}
