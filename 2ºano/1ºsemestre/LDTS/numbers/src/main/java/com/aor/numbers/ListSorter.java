package com.aor.numbers;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * An utility class to sort list of numbers.
 */
public class ListSorter implements GenericListSorter {
    /**
     * Really stupid way to sort a list.
     * @return A sorted version of the list.
     */
    public List<Integer> sort(List<Integer> list) {
        List<Integer> sorted = new ArrayList<>();
        for(Integer number : list)
            sorted.add(number);

        for(int i = 0; i < sorted.size() - 1; i++)
            for(int j = i + 1; j < sorted.size(); j++)
                if(sorted.get(i) > sorted.get(j))
                    Collections.swap(sorted, i, j);

        return sorted;
    }
}
