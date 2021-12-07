#include <locale.h>
#include "Interface.h"

void textcolor (int iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void textbackground (int iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}

void tipocursor (int cursor)
{
    HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CURSOR;

    BOOL result;

    CURSOR.dwSize = 1;
    if(cursor == 0)
        CURSOR.bVisible = FALSE;
    else
        CURSOR.bVisible = TRUE;
    result=SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}

void textcoloreback (int letras, int fundo){/*para mudar a cor de fundo mude o background*/
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    letras + (fundo << 4));
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void Borda(int x, int y, int largura, int altura){
    // EsqSup DirSup EsqInf DirInf LHoriz LVertical
    char C[] = "\xda\xbf\xc0\xd9\xc4\xb3";
    int i, j;
    gotoxy(x, y); printf("%c", C[0]);
    for(i = 0; i < largura; i++) printf("%c", C[4]);
    printf("%c", C[1]);
    for(j = 0; j < altura; j++){
        gotoxy(x, y+j+1); printf("%c", C[5]);
        for(i = 0; i < largura; i++) printf(" ");
        printf("%c", C[5]);
    }
    gotoxy(x, y+altura); printf("%c", C[2]);
    for(i = 0; i < largura; i++) printf("%c", C[4]);
    printf("%c", C[3]);
}

int MenuPrincipal(){
    Borda(30, 6, 45, 8); // EsqSup DirSup EsqInf DirInf LHoriz LVertical
    // Primeira Opção
    Borda(31, 11, 11, 2);
    gotoxy(32, 12);
    printf("ORDENAR - 0");
    // Segunda Opção
    Borda(47, 11, 13, 2);
    gotoxy(48, 12);
    printf("QUICKSORT - 1");
    // Terceira Opção
    Borda(65, 11, 9, 2);
    gotoxy(66, 12);
    printf("BOLHA - 2");

    int Valor;
    gotoxy(45, 8);
    printf("OP%c%cO DESEJADA: ", 128, 143);
    Borda(60, 7, 3, 2);
    gotoxy(62, 8);
    scanf("%d", &Valor);

    return Valor;
}

int OrdenarValores(){
    Borda(30, 6, 45, 8); // EsqSup DirSup EsqInf DirInf LHoriz LVertical

    int Num;
    gotoxy(38, 10);
    printf("VALORES PARA ORDENAR: ", 128, 143);
    Borda(60, 9, 6, 2);
    gotoxy(61, 10);
    scanf("%d", &Num);

    return Num;
}

void CaixaDados(){

    Borda(2, 20, 103, 2);

    gotoxy(3, 21);printf("NOME");
    gotoxy(36, 21);printf("|INSCRICAO");
    gotoxy(47, 21);printf("|POR");
    gotoxy(53, 21);printf("|ING");
    gotoxy(58, 21);printf("|MAT");
    gotoxy(63, 21);printf("|ATU");
    gotoxy(68, 21);printf("|C.Bs");
    gotoxy(74, 21);printf("|MAT.F"); //C.BA C.IN VEN C.EP P
    gotoxy(81, 21);printf("|C.Ba");
    gotoxy(88, 21);printf("|VEN");
    gotoxy(93, 21);printf("|C.EP");
    gotoxy(99, 21);printf("|PONTOS");


}


