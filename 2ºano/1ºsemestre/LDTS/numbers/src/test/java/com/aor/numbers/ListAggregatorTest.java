package com.aor.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.util.Arrays;
import java.util.List;

public class ListAggregatorTest {

   /* static class ListDeduplicatorTest implements GenericListDeduplicator {
        public List<Integer> deduplicate(List<Integer> l) {
            return Arrays.asList(1, 2, 4);
        }
    } */

    @Test
    public void sum() {
        List<Integer> list = helper();

        ListAggregator aggregator = new ListAggregator(new ListDeduplicator(new ListSorter()));
        int sum = aggregator.sum(list);

        Assertions.assertEquals(9, sum);
    }

    @Test
    public void max() {
        List<Integer> list = helper();

        ListAggregator aggregator = new ListAggregator(new ListDeduplicator(new ListSorter()));
        int max = aggregator.max(list);

        Assertions.assertEquals(4, max);
    }

    @Test
    public void min() {
        List<Integer> list = helper();

        ListAggregator aggregator = new ListAggregator(new ListDeduplicator(new ListSorter()));
        int min = aggregator.min(list);

        Assertions.assertEquals(1, min);
    }

    @Test
    public void distinct() {
        List<Integer> list = helper();
        //GenericListDeduplicator d = new ListDeduplicatorTest();
        GenericListDeduplicator d = Mockito.mock(GenericListDeduplicator.class);
        Mockito.when(d.deduplicate(Mockito.anyList())).thenReturn(Arrays.asList(1, 2, 4));
        ListAggregator aggregator = new ListAggregator(d);
        int distinct = aggregator.distinct(list);
        Assertions.assertEquals(3, distinct);
    }

    @Test
    public void max_bug_7263() {
        List<Integer> list = helper();
        ListAggregator aggregator = new ListAggregator(new ListDeduplicator(new ListSorter()));
        int max = aggregator.max(list);
        if(max != 4) {
            System.out.print("Bug report #7263.\nCreated a list with values ");
            for(int i = 0; i < list.size(); i++) {
                if(i < list.size()-1)  System.out.print(list.get(i) + ", " );
                else {
                    System.out.print("and " + list.get(i) + "." );
                }
            }
            System.out.println("\nTried to calculate the maximum of these values but got " + max + " instead of 4.");
        }
    }

  /*  @Test
    public void distinct_bug_8726() {
        List<Integer> list = helper();
        ListAggregator aggregator = new ListAggregator(new ListDeduplicator(new ListSorter()));
        int distinct = aggregator.distinct(list);
        if(distinct != 3) {
            System.out.print("Bug report #8726.\nCreated a list with values ");
            for(int i = 0; i < list.size(); i++) {
                if(i < list.size()-1)  System.out.print(list.get(i) + ", " );
                else {
                    System.out.print("and " + list.get(i) + "." );
                }
            }
            System.out.println("\nTried to calculate the number of distinct numbers but got " + distinct + " instead of 3.");
        }
    } */

    @Test
    public void distinct_bug_8726() {
        List<Integer> list = helper();
        GenericListDeduplicator d = Mockito.mock(GenericListDeduplicator.class);
        Mockito.when(d.deduplicate(Mockito.anyList())).thenReturn(Arrays.asList(1, 2, 4));
        ListAggregator aggregator = new ListAggregator(d);
        int distinct = aggregator.distinct(list);
        Assertions.assertEquals(3, distinct);
    }

    private List<Integer> helper() {
        return Arrays.asList(1,2,4,2);
    }
}
