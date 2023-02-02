#include "libgame.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>

void gotoxy(int x, int y)  // funcion que posiciona el cursos en la coordenada (x,y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void OcultaCursor()
{
    CONSOLE_CURSOR_INFO cci = {100, FALSE}; // El segundo miembro de la estructura indica si se muestra el cursor o no.

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Color(int color){
	static HANDLE hConsole;
    hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hConsole, color | (0 * 0x10 + 0x100) );
}

void pintar_marco()       // funcion que pinta los limites del escenario
{
     // Lineas horizontals
     for(int i=2; i < 78; i++){
        gotoxy (i, 3); printf ("%c", 205);
        gotoxy(i, 23); printf ("%c", 205);
     }
     //Lineas verticales
     for(int v=4; v < 23; v++){
        gotoxy (2,v);  printf ("%c", 186);
        gotoxy(77,v);  printf ("%c", 186);
     }
     // Esquinas
     gotoxy  (2,3);    printf ("%c", 201);
     gotoxy (2,23);    printf ("%c", 200);
     gotoxy (77,3);    printf ("%c", 187);
     gotoxy(77,23);    printf ("%c", 188);
}

void pausa(int x){
    Sleep(x);

}

void pausa(){
    getch();
}


                                                                                                                                                                                                                                                                                                                                                                                                                                  void inicia_libgame(){char inicio[50][100] ={"                  AAA        AAAAAAAA    AAAAAA                       ","                  AAA           AA       AA   AA                      ","                  AAA           AA       AAAAAA                       ","                  AAAAAAA       AA       AA   AA                      ","                  AAAAAAA    AAAAAAAA    AAAAAA                       ","                                                                      ","                                                                      ","                                                                      ","       AAAAAAAAA      AAAAAA       AAAA  AAAA      AAAAAAAAAAA        ","       AAAAAAAAA     AAA    A    AAAAAAAAAAAAAA    AAAAAAAAAAA        ","       AA     AA     AAA    A   AAA  AAAAA   AAA   AAA                ","       AA            AAA    A   AAA   AAA    AAA   AAAAAAAA           ","       AA   AAAAAA   AAAAAAAA   AAA   AAA    AAA   AAAAAAAA           ","       AA        A   AAA    A   AAA   AAA    AAA   AAA                ","       AAAAAAAAA A   AAA    A   AAA   AAA    AAA   AAAAAAAAAAA        ","       AAAAAAAAA     AAA    A   AAA   AAA    AAA   AAAAAAAAAAA        ","                                                                      ",};for(int i = 0 ; i< 17 ; i++){for(int j = 0 ; j < 71 ; j++){if(inicio[i][j] == 'A'){gotoxy(j+5,i+5); printf("*");}}}getch();for(int i = 0 ; i< 17 ; i++){for(int j = 0 ; j < 71 ; j++){if(inicio[i][j] == 'A'){gotoxy(j+5,i+5); printf(" ");}}}}
