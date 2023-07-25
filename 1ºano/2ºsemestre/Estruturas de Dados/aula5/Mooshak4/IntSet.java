public interface IntSet {
    public boolean contains(int x);       // Retorna true se x esta no conjunto
    public boolean add(int x);            // Adiciona x ao conjunto (devolve true se conseguir)
    public boolean remove(int x);         // Remove x do conjunto (devolve true se conseguir)
    public int     size();                // Retorna o numero de elementos do conjunto
    public void    clear();               // Limpa o conjunto (torna-o vazio)
    public boolean equals(IntSet s);      // Retorna true se ambos os conjuntos sao iguais
    public IntSet intersection(IntSet s); // devolve um novo conjunto: a intersecao de ambos
}
