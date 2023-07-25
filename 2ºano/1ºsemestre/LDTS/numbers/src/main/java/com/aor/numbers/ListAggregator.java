package com.aor.numbers;

import java.util.List;

/**
 * A utility class that aggregates list of numbers
 * into a single integer using various functions.
 */
public class ListAggregator {
    GenericListDeduplicator d;
    public ListAggregator(GenericListDeduplicator d2) {
        this.d = d2;
    }
    /**
     * Sums all numbers in a list.
     * @return The sum of all the values in the list.
     */

    public Integer sum(List<Integer> list) {
        int sum = 0;

        for (Integer number : list)
            sum += number;

        return sum;
    }

    /**
     * Calculates the maximum value in a list.
     * @return The maximum value in the list.
     */
    public Integer max(List<Integer> list) {
        int max = Integer.MIN_VALUE;

        for (Integer number : list)
            if (number > max)
                max = number;

        return max;
    }

    /**
     * Calculates the minimum value in a list.
     * @return The minimum value in the list.
     */
    public Integer min(List<Integer> list) {
        int min = Integer.MAX_VALUE;

        for (Integer number : list)
            if (number < min)
                min = number;

        return min;
    }

    /**
     * Counts the number of distinct numbers in a list.
     * @return The number of distinct numbers.
     */
    public int distinct(List<Integer> list) {
        //ListDeduplicator deduplicator = new ListDeduplicator();
        List<Integer> distinct = d.deduplicate(list);

        return distinct.size();
    }
}