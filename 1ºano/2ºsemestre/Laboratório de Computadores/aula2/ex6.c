#include <stdio.h>
void decompor(int total_seg, int *horas, int *mins, int *segs);
int main() {
 int total_seg,horas,mins,segs;
 scanf("%d",&total_seg);
 decompor(total_seg, &horas, &mins, &segs);
 printf("%d %d %d\n",horas,mins,segs);
 return 0;
}


void decompor(int total_seg, int *horas, int *mins, int *segs) {
 *horas = (total_seg/60)/60;
 *mins = (total_seg/60)%60;
 *segs = (total_seg)%60;
 /*
 60segs -> 1min
 1h -> 60 min
 1min -> 60segs
 */
}
