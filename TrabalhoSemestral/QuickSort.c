#include "QuickSort.h"
#include "HeapSort.h"

int Cont = 0;

void Quick(Dados vetor[], int inicio, int fim){

   int i, j, meio;
   Dados aux, pivo;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo.Pontos = vetor[meio].Pontos;

   do{
      while (vetor[i].Pontos < pivo.Pontos) i = i + 1;
      while (vetor[j].Pontos > pivo.Pontos) j = j - 1;

      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
         Cont++;
      }
   }while(j > i);

   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);
}

void ImprimirTotal(){

    gotoxy(55, 12); printf("QUICKSORT: ");
    gotoxy(67, 12); printf("%d", Cont);

}


