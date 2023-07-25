import java.util.*;
class Bombeiro {
  public String nome;
  public int eventos;
  public int minutos;
  public int inicio;
  public int chegada;

  Bombeiro(String n, int e, int m, int i, int c){
	 nome = n;
	 eventos = e;
	 minutos = m;
	 inicio = i;
   chegada = c;
  }
}
class Fila { //criar filas
  public MyQueue<Bombeiro> fila;

  Fila() {
   fila = new LinkedListQueue<Bombeiro>();
  }
}
class ED095 {
  private static int bombeiros;
  private static Fila Evento[]; //fila com bombeiros no evento
  private static Fila livres; //fila com bombeiros livres

  private static void lista(int n){
	 System.out.println("Listagem de Bombeiros");
	 for(int i = 0; i < n; i++){
	    Bombeiro b = livres.fila.dequeue(); //bombeiro retirado da fila
	    livres.fila.enqueue(b); //voltar a adicionar bombeiro à fila
	    System.out.println(b.nome + " " + b.eventos + " " + b.minutos);
	 }
  }
  private static void inicializar() {
	 Evento = new Fila[501];
	 for (int i = 0; i < 501;i++)
	    Evento[i] = new Fila();
	 livres = new Fila();
  }
  public static void main(String[] args){
	 Scanner in = new Scanner(System.in);
	 int flag = in.nextInt();
	 bombeiros = in.nextInt();

	 inicializar();
   for(int i = 0; i < bombeiros; i++) {
	    String nome = in.next(); //ler nome do bombeiro
	    Bombeiro a = new Bombeiro(nome, 0, 0, 0, 0);
	    livres.fila.enqueue(a); //adicionar bombeiro à fila
	 }
	 if(flag == 2) System.out.println("Bombeiros Destacados");
	 String n = in.next();
   int cont = 0;
	 while(!(n.equals("FIM"))) {
	   int indice = in.nextInt();
     if(n.equals("PARTIDA")) {
	   	cont++;
		  int b = in.nextInt();
	  	int inicio = in.nextInt();
	  	if(flag == 2) {
		    System.out.println("EVENTO " + indice);
		    if(livres.fila.isEmpty()) System.out.println("Nenhum"); //nenhum bombeiro está livre -> a fila está vazia
	  	}
	  	for(int i = 0; i < b && !(livres.fila.isEmpty()); i++) {
		    Bombeiro a = livres.fila.dequeue(); //a = bombeiro retirado da fila
		    a.eventos++; //+1 evento em que o bombeiro participou
	      a.inicio = inicio; //hora de partida
	      Evento[indice].fila.enqueue(a); //adicionar bombeiro à fila de eventos
		    if(flag == 2) System.out.println(a.nome);
		  }
	   }
     else if(n.equals("CHEGADA")) {
	   	int chegada = in.nextInt();
	  	while(!(Evento[indice].fila.isEmpty())) {
		    Bombeiro a = Evento[indice].fila.dequeue(); //bombeiro retirado do evento
		    a.chegada = chegada; //hora que o bombeiro chegadou do evento
	      a.minutos += (a.chegada - a.inicio); //numero de minutos em que esteve no evento
	      livres.fila.enqueue(a); //adicionar à fila
	  	}
	   }
	   in.nextLine();
	   n = in.next(); //ler tipo do evento
	}
  if(flag == 1) System.out.println("Ocorreram " + cont + " eventos");
  else if(flag == 3) lista(bombeiros);
  }
}
