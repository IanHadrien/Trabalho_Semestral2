#include "HeapSort.h"

int con = 0;

void heapsort(Dados *vet, int n) {
	int i;
	Dados tmp;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1);
		//con++;
	}
	//printf("\n Total de passos: %d \n", con);
}

void peneira(Dados *vet, int raiz, int fundo) {
	int pronto, filhoMax;
	Dados tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2].Pontos > vet[raiz * 2 + 1].Pontos) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz].Pontos < vet[filhoMax].Pontos) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
		con++;
    }
	else {
      pronto = 1;
	}
  }
}
