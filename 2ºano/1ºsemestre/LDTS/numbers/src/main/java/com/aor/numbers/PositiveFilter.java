package com.aor.numbers;

public class PositiveFilter implements GenericListFilter {

    public boolean accept(Integer number) {
        return number > 0;
    }
}
