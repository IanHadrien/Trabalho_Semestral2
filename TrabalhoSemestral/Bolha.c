#include "Bolha.h"
#include "Interface.h"
#define MAX 40255

void TotalTrocasBolha(){

    Borda(30, 6, 45, 8); // EsqSup DirSup EsqInf DirInf LHoriz LVertical
    gotoxy(32, 12);
    printf("HEAPSORT: 574567");
    gotoxy(55, 12);
    printf("BOLHA: ");

    gotoxy(40, 8);
    printf("TOTAL DE TROCAS REALIZADA ", 128, 143);

}

void bubble_sort(Dados *a)
{
 int i, j, Cont = 0;;
 Dados tmp;

  for(i = 0; i < MAX; i++)
  {
   for(j = i+1; j < MAX; j++)
   {
    if(a[j].Pontos < a[i].Pontos)
    {
     tmp = a[i];
     a[i] = a[j];
     a[j] = tmp;
     Cont++;
    }
  }
 }
gotoxy(62, 12); printf("%d", Cont);
//printf("Valores Ordenas: %d", Cont);
}
