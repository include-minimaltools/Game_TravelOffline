#ifndef GTOOLS_H
#define GTOOLS_H 1
/*************************************/
/* Definir las librerias necesarias  */
/* el funcionamiento correcto de la  */
/* libreria                          */
/*************************************/
#pragma region Includes
#include <MOUSE.H>
#ifndef strcmpi(s1,s2)
    #include <string.h>
#endif
#ifndef __GRAPHX_DEF_
    #include <GRAPHICS.H>
#endif
#ifndef __OLDCONIO__
    #include <conio.h>
#endif
#ifndef __DOS_DEF_
    #include <dos.h>
#endif
#ifndef __STDLIB
    #include <stdlib.h>
#endif
#ifndef STDBOOL_H
    #include <stdbool.h>
#endif
#pragma endregion

/*************************************/
/*Definir strings como tipos de datos*/
/*************************************/
typedef char *string;

/*************************************/
/*      Caracteres restringidos      */
/*************************************/
enum allowed_characters
{
    Alls,
    OnlyNumbers,
    OnlyLetters,
    LettersAndSymbols,
    NumbersAndSymbols
};

/*************************************/
/*  Variables globales para la       */
/*  configuracion del get_string     */
/*************************************/
int allowed_characters;
int MaxStrLn = 80;
int MinStrLn = 2;
int blink = 500;

/*************************************/
/*  Obtiene un string ingresado por  */
/*  el usuario e imprime un mensaje  */
/*  al momento de pedirlo            */
/*************************************/
void get_string(int x, int y, string result)
{
    int letter = 0;
    int i, j;
    int font = getcolor();
    int background = getpixel(x+2,y+2);
    char temp_string[80] = {'\0'};
    char cursor[81] = {'\0'};

    while (letter < MaxStrLn)
    {
        for(i = 0; !kbhit(); i = i==0?1:0)
        {
            for(j = 0; j < letter; j++)
                cursor[j] = ' ';

            if(i == 0)
                cursor[letter] = 0;
            else
            {
                cursor[letter] = 179;
                cursor[letter + 1] = 0;
            }

            setcolor(font);
            outtextxy(x, y, cursor);

            for(j = 0; j < blink; j++)
                if(!kbhit())
                    delay(10);
                else
                    break;
                    
            setcolor(background);
            outtextxy(x, y, cursor);
        }
        setcolor(font);
        temp_string[letter] = getch();

        if ((allowed_characters == LettersAndSymbols || allowed_characters == NumbersAndSymbols || allowed_characters == Alls) && letter < MaxStrLn - 1 && ((temp_string[letter] >= 33 && temp_string[letter] <= 47) || (temp_string[letter] >= 58 && temp_string[letter] <= 64) || (temp_string[letter] >= 91 && temp_string[letter] <= 96) || (temp_string[letter] >= 123 && temp_string[letter] <= 126)))
        {
            mocultar();
            outtextxy(x, y, temp_string);
            mver();
            letter++;
        }
        else if ((allowed_characters == OnlyNumbers || allowed_characters == Alls) && letter < MaxStrLn - 1 && temp_string[letter] >= 48 && temp_string[letter] <= 57)
        {
            mocultar();
            outtextxy(x, y, temp_string);
            mver();
            letter++;
        }
        else if ((allowed_characters == OnlyLetters || allowed_characters == LettersAndSymbols || allowed_characters == Alls) && letter < MaxStrLn - 1 && ((temp_string[letter] >= 65 && temp_string[letter] <= 90) || (temp_string[letter] >= 97 && temp_string[letter] <= 122) || (temp_string[letter] >= 48 && temp_string[letter] <= 57)))
        {
            mocultar();
            outtextxy(x, y, temp_string);
            mver();
            letter++;
        }
        else if (temp_string[letter] == 32)
        {
            mocultar();
            outtextxy(x, y, temp_string);
            mver();
            letter++;
        }
        else if (temp_string[letter] == 8 && letter > 0)
        {
            setcolor(background);
            mocultar();
            outtextxy(x, y, temp_string);
            mver();
            temp_string[letter] = '\0';
            temp_string[letter - 1] = '\0';
            setcolor(font);
            mocultar();
            outtextxy(x, y, temp_string);
            mver();
            letter--;
        }
        else if (temp_string[letter] == 13 && letter >= MinStrLn)
        {
            temp_string[letter] = '\0';
            break;
        }
    }
    strcpy(result, temp_string);
}
#endif
