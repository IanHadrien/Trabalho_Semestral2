#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

struct dado{
    char MacroRegiao[101];
    char MicroRegiao[101];
    char Nome[201];
    char Inscricao[21];
    char Nascimento[21];
    double LPor, LIng, Mat, Atu, ConhBas, MatF, CBan, CInf, Ven, ConhEsp, Pontos,
            ClassAC, ClassPcd, ClassPPP;
    char Situacao[101];
    double Redacao;

};
typedef struct dado Dados;

void heapsort(Dados *vet, int n);
void peneira(Dados *vet, int raiz, int fundo);

#endif // HEAPSORT_H_INCLUDED
