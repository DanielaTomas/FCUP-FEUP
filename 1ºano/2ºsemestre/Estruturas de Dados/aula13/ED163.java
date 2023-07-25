import java.util.Arrays;
import java.util.Scanner;

class Team implements Comparable<Team> {
   String name;
   int points, goalavarage;

   Team(String n, int p, int v, int e, int d, int m, int s) {
      name = n;
      goalavarage = (m-s);
      for(int i = 0; i < v; i++)
        p += 3;
      for(int i = 0; i < e; i++)
        p += 1;
      points = p;
   }
   public int compareTo(Team t) {
      if(points < t.points) return 1;
      else if(points > t.points) return -1;
      else if(goalavarage < t.goalavarage) return 1;
      else if(goalavarage > t.goalavarage) return -1;
      return name.compareTo(t.name);
   }
   public String toString() {
      return name + " " + points + " " + goalavarage;
   }
}
class ED163 {
   public static void main(String[] args) {
      // Inicializar array v
      Scanner in = new Scanner(System.in);
      int n = in.nextInt();
      Team[] v = new Team[n];
      in.nextLine();
      for(int i = 0; i < n; i++)
       v[i] = new Team(in.next(),0,in.nextInt(),in.nextInt(),in.nextInt(),in.nextInt(),in.nextInt());

      Arrays.sort(v);
      for(int i = 0; i < n; i++)
        System.out.println(v[i]);
   }
}
