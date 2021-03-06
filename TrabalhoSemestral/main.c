#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bolha.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "Dados.h"
#include "Interface.h"

Dados Dados_Total[40500];
Dados Dados_Q[40500];
Dados Dados_B[40500];

void DesenharPrincipal(){
    textcoloreback(WHITE, CYAN);
    system("cls");
    gotoxy(45, 5);
    textcoloreback(WHITE, LIGHT_GREEN);
    printf("ORDENACAO - HEAPSORT");

    textcoloreback(WHITE, BLUE);
}

int main(){
    Dados D;

    char Linha[2000];
    char Palavra[101];
    char *p, *pos;
    int Cont = 0;
    int bytes;
    int Campo;
    int i= 0;
    int retorno, Func1;

    FILE *fpE;
    fpE = fopen("C:\\ProjetoFaculdade\\arquivo.csv", "r");
    FuncaoAbrirArquivos(fpE);

    DesenharPrincipal();

    while(fscanf(fpE, " %[^\n]", Linha) != EOF){
        if(strncmp(Linha, "\"MACRORR", 8) == 0){
            p = strtok(Linha," ");
            D.Nome[0] = 0;
            Campo = 0;
            while(p!= NULL){
                strcpy(Palavra, p);
                    //printf("Palavra %s\n", Palavra);
                    if(Campo == 0 && isdigit(Palavra[0])){
                        strcpy(D.MacroRegiao, Palavra);
                        Campo++;
                    }
                    else if(Campo == 1 && isdigit(Palavra[0])){
                        strcpy(D.MicroRegiao, Palavra);
                        Campo++;
                    }
                    else if(Campo == 2){
                        if(!isdigit(Palavra[0])){
                            strcat(D.Nome, Palavra);
                            strcat(D.Nome, " ");
                        }
                        else{
                            Campo++;
                            strcpy(D.Inscricao, Palavra);
                            Campo++;
                        }
                    }
                    else if(Campo == 4 && isdigit(Palavra[0])){
                        strcpy(D.Nascimento, Palavra);
                        Campo++;
                    }
                    else if(Campo == 5 && isdigit(Palavra[0])){
                        pos = strchr(Palavra, ',');
                        *pos = '.';
                        D.LPor = atof(Palavra);
                        Campo++;
                    }
                    else if(Campo == 6 && isdigit(Palavra[0])){
                        pos = strchr(Palavra, ',');
                        *pos = '.';
                        D.LIng = atof(Palavra);
                        Campo++;
                    }
                    else if(Campo == 7 && isdigit(Palavra[0])){
                        pos = strchr(Palavra, ',');
                        *pos = '.';
                        D.Mat = atof(Palavra);
                        Campo++;
                    }
                    else if(Campo == 8 && isdigit(Palavra[0])){
                        pos = strchr(Palavra, ',');
                        *pos = '.';
                        D.Atu = atof(Palavra);
                        Campo++;
                    }
                    else if(Campo == 9 && isdigit(Palavra[0])){
                        pos = strchr(Palavra, ',');
                        *pos = '.';
                        D.ConhBas = atof(Palavra);
                        Campo++;
                    }
                    else if(Campo == 10 && isdigit(Palavra[0])){
                        pos = strchr(Palavra, ',');
                        *pos = '.';
                        D.MatF = atof(Palavra);
                        Campo++;
                    }
                    else if(Campo == 11 && isdigit(Palavra[0])){
                        pos = strchr(Palavra, ',');
                        *pos = '.';
                        D.CBan = atof(Palavra);
                        Campo++;
                    }
                    else if(Campo == 12 && isdigit(Palavra[0])){
                        pos = strchr(Palavra, ',');
                        *pos = '.';
                        D.CInf = atof(Palavra);
                        Campo++;
                    }
                    else if(Campo == 13 && isdigit(Palavra[0])){
                        pos = strchr(Palavra, ',');
                        *pos = '.';
                        D.Ven = atof(Palavra);
                        Campo++;
                    }
                    else if(Campo == 14 && isdigit(Palavra[0])){
                        pos = strchr(Palavra, ',');
                        *pos = '.';
                        D.ConhEsp = atof(Palavra);
                        Campo++;
                    }
                    else if(Campo == 15 && isdigit(Palavra[0])){
                        pos = strchr(Palavra, ',');
                        *pos = '.';
                        D.Pontos = atof(Palavra);
                        Campo++;
                    }

                    p = strtok(NULL, " ");
            }

            Dados_Total[Cont] = D;
            Dados_Q[Cont] = D;
            Dados_B[Cont] = D;

            Cont++;
        }
        //if(Cont == 5) break;
    }
    printf("\n%d", Cont);

    // Fun??o Grafica

    while(1){

        retorno = MenuPrincipal();

        if(retorno == 0){
            Func1 = OrdenarValores();
            // Fun??o de Ordena??o
            heapsort(Dados_Total, Func1);

            CaixaDados();

            for (int i = 0; i < Func1; i++) {
                    gotoxy(3, 23+i); printf("%s", Dados_Total[i].Nome);
                    gotoxy(36, 23+i); printf("%s", Dados_Total[i].Inscricao);
                    gotoxy(48, 23+i); printf("%.1lf", Dados_Total[i].LPor);
                    gotoxy(54, 23+i); printf("%.1lf", Dados_Total[i].LIng);
                    gotoxy(59, 23+i); printf("%.1lf", Dados_Total[i].Mat);
                    gotoxy(64, 23+i); printf("%.1lf", Dados_Total[i].Atu);
                    gotoxy(69, 23+i); printf("%.1lf", Dados_Total[i].ConhBas);
                    gotoxy(75, 23+i); printf("%.1lf", Dados_Total[i].MatF);
                    gotoxy(82, 23+i); printf("%.1lf", Dados_Total[i].CBan);
                    gotoxy(89, 23+i); printf("%.1lf", Dados_Total[i].Ven);
                    gotoxy(94, 23+i); printf("%.1lf", Dados_Total[i].ConhEsp);
                    gotoxy(100, 23+i); printf("%.1lf", Dados_Total[i].Pontos);
            }
        }

        if(retorno == 1){

            TotalTrocasBolha();
            Quick(Dados_Q, 0, 40255);
            ImprimirTotal();

            getch();
        }

        if(retorno == 2){
            TotalTrocasBolha();
            bubble_sort(Dados_B);
            getch();
        }

        if(retorno < 0)break;
    }

    return 0;
}
