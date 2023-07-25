public class TestED248 {
    public static void main(String[] args) {
	int n = 1000000;
	IntSet s = new BooleanArrayIntSet(n); // Criar array de booleanos para numeros no intervalo [1,n]
	boolean tmp;

	System.out.println("Adicionando todos os numeros entre 1 e " + n + "...");
	for (int i=1; i<=n; i++) {
	    tmp = s.add(i);
 }
	System.out.println("Adicionando novamente todos os numeros entre 1 e " + n + "...");
	for (int i=1; i<=n; i++)
	    tmp = s.add(i);

	System.out.println("Verificando se todos os numeros entre 1 e " + n + " existem...");
	for (int i=1; i<=n; i++)
	    tmp = s.contains(i);

	System.out.println("Removendo todos os numeros entre 1 e " + n + "...");
	for (int i=1; i<=n; i++)
	    tmp = s.remove(i);
    }
}
