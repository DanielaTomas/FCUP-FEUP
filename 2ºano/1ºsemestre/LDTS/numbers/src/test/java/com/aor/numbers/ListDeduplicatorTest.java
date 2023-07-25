package com.aor.numbers;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

public class ListDeduplicatorTest {

    static class ListSorterTest implements GenericListSorter {
        public List<Integer> sort(List<Integer> l) {
            return Arrays.asList(1, 2, 2, 4);
        }
    }

    @Test
    public void deduplicate() {
        List<Integer> list = helper();
        List<Integer> expected = Arrays.asList(1,2,4);
        ListDeduplicator deduplicator = new ListDeduplicator(new ListSorterTest());
        List<Integer> distinct = deduplicator.deduplicate(list);
        Assertions.assertEquals(expected, distinct);
    }

    private List<Integer> helper() {
        return Arrays.asList(1, 2, 4, 2);
    }

}
