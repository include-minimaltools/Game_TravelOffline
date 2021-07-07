#ifndef AIRPLANE_H
#define AIRPLANE_H 1
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

int period = 0;
int position[2] = {639,254};

int endposition[2] = {0,0};
void* avion;

void Avion(int x, int y, int Inclinacion);
void takeOff(void);
void landing(void);
void motion(bool onlyHorizontal);

void takeOff(void)
{
    avion = malloc(imagesize(0,0,183,110));
    position[0] = 639;
    position[1] = 439;
    setlinestyle(SOLID_LINE,SOLID_FILL,1);
    setcolor(LIGHTRED);
    ellipse(724,-53,180,270,933,493);
    motion(true);
    free(avion);
}

void landing(void)
{
    avion = malloc(imagesize(0,0,183,110));
    position[0] = 639;
    position[1] = 254;
    setlinestyle(SOLID_LINE,SOLID_FILL,1);
    setcolor(LIGHTRED);
    ellipse(-91,-53,270,325,933,493);
    motion(false);
    Avion(endposition[0],endposition[1],1);
    free(avion);
}

void motion(bool onlyHorizontal)
{
    int j, k;

    for(j = -1; j <= 1; j++)
        for (k = -1; k <= 1; k++)
            if (getpixel(position[0] + j,position[1] + k) == LIGHTRED)
            {
                if(period%10==0 && position[0] < 540 && position[0] > 100)
                {
                    endposition[0] = position[0] - 91;
                    endposition[1] = position[1] - 55;
                    getimage(position[0] - 91, position[1] - 55,position[0] + 92, position[1] + 55,avion);
                    if(!onlyHorizontal)
                        Avion(position[0] - 91,position[1] - 55,position[1] < 340 ? 3 : position[1] < 400 ? 2 : 1);
                    else
                        Avion(position[0] - 91,position[1] - 55,1);
                    delay(1750);
                    putimage(position[0] - 91, position[1] - 55, avion, COPY_PUT);
                }
                putpixel(position[0],position[1],DARKGRAY);
                position[0] += j;
                position[1] += k;
                period++;
                motion(onlyHorizontal);
            }
}
/* 164x88 */
void Avion(int x, int y, int Inclinacion){

    int i = 0;
    int AvionBase1[52] = {47,50, 99,48, 138,41, 161,47, 144,30, 152,2, 140,3, 122,22, 83,23, 90,11, 79,11, 51,24 
                        ,83,22, 51,24, 29,24, 15,28, 10,36, 1,43, 10,53, 47,50, 47,50, 71,61, 95,69, 114,76, 132,74, 99,48};
    
    int AvionBase2[44] = {61,73, 106,84, 135,93, 157,86, 118,65, 158,49, 172,52, 181,48, 162,34, 168,3, 155,7
                       ,137,31, 94,40, 100,25, 91,24, 58,45, 94,40, 24,52, 16,64, 8,75, 21,82, 61,73};

    int AvionBase3[46] = {48,89, 76,88, 96,85, 122,85, 136,76, 98,65, 128,43, 139,43, 149,38, 129,29, 126,1, 115,6
                        ,105,35, 69,49, 73,36 ,63,40, 39,64, 70,49, 13,76, 7,88, 3,100, 16,103, 97,66};


    switch(Inclinacion){
        case 1: 
            for(i = 0; i < 52; i++)
                AvionBase1[i] += i%2 == 0 ? x : y;

            setfillstyle(1,DARKGRAY);
            setcolor(LIGHTGRAY);
            fillpoly(26,AvionBase1);
            line(138+x,41+y,125+x,33+y);
            line(125+x,33+y,144+x,30+y);
            ellipse(18+x,31+y,0,110,6,4);
            ellipse(18+x,31+y,210,360,6,4);

            setfillstyle(1,LIGHTGRAY);
            floodfill(19+x,31+y,LIGHTGRAY);
            bar(34+x,28+y,44+x,44+y);

            for(i = 0; i < 4; i++)
				fillellipse(56+x+(i*16),32+y,3,3);

            break;
        case 2:
            for(i = 0; i < 44; i++)
                AvionBase2[i] += i%2 == 0 ? x : y;

            setfillstyle(1,DARKGRAY);
            setcolor(LIGHTGRAY);
            fillpoly(22,AvionBase2);
            line(158+x,50+y,142+x,42+y);
            line(142+x,42+y,162+x,33+y);
            ellipse(27+x,58+y,0,360,7,4);

            setfillstyle(1,LIGHTGRAY);
            floodfill(27+x,58+y,LIGHTGRAY);

            line(41+x,52+y,51+x,50+y);
            line(51+x,50+y,55+x,66+y);
            line(55+x,66+y,43+x,69+y);
            line(43+x,69+y,42+x,51+y);
            floodfill(43+x,54+y,LIGHTGRAY);

            for(i = 0; i < 4; i++)
                fillellipse(66+x+(i*16),53+y-(i*3),3,3);

            break;
        case 3:
            for(i = 0; i < 46; i++)
                AvionBase3[i] += i%2 == 0 ? x : y;

            setfillstyle(1,DARKGRAY);
            setcolor(LIGHTGRAY);
            fillpoly(23,AvionBase3);
            line(129+x,42+y,112+x,40+y);
            line(112+x,40+y,129+x,29+y);
            ellipse(15+x,84+y,0,360,7,4);

            setfillstyle(1,LIGHTGRAY);
            floodfill(15+x,84+y,LIGHTGRAY);
            
            line(26+x,75+y,35+x,70+y);
            line(35+x,70+y,42+x,83+y);
            line(42+x,83+y,31+x,89+y);
            line(31+x,89+y,26+x,75+y);
            floodfill(28+x,78+y,LIGHTGRAY);

            for(i = 0; i < 4; i++)
                fillellipse(49+x+(i*16),68+y-(i*7),3,3);
                
            break;
        default:
            break;
    }
    
}
#endif
