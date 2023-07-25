package com.aor.numbers;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ListFilterer {
    GenericListFilter filter;

    public ListFilterer(GenericListFilter filter) {
      this.filter = filter;
    }

    public List<Integer> filter(List<Integer> list) {
        List<Integer> f = new ArrayList<>();
        for(int l : list)
            if(filter.accept(l)) f.add(l);
        return f;
    }
}
