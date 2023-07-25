package com.aor.numbers;

public class DivisibleByFilter implements GenericListFilter {
    Integer i;

    public DivisibleByFilter(Integer i) {
        this.i = i;
    }

    public boolean accept(Integer number) {
        return (number % i) == 0;
    }
}
