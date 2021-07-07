/* LIBRERIA DE DIBUJOS GRAFICOS EN TURBO C 2.0 *
 * Creada por HSC.MinimalTools                 *
 * Desarrolladores:                            *
 * > Marcel Emmanuel Diaz Largaespada          *
 * > Gabriel Alejandro Ortiz Amador            *
 * > Luis Miguel Pineda Joseph                 *
 * > Engel Gabriel Reyes Moreno                *
 * > Obed Isai Rios Solano                     *
 *                                             *
 * ----------- Version Beta 1.0  ------------  *
 *                                             *
 * Acerca de la libreria:                      *
 * Airports.h trae precargado ciertos objetos  *
 * con desplazamiento para los distintos       *
 * aereopuertos. Así como funciones de Airports*
 * las cuales dibujaran por completo un        *
 * aereopuerto con cierto diseno, recibiendo   *
 * como parametro si es de noche o no          */

#ifndef AIRPORTS_H
#define AIRPORTS_H 1

#ifndef MUNDI_H
#include <c:\\tc20\\include\\mundi.h>
#endif

#pragma region Includes
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
#ifndef ROOMS_H
#include <c:\\tc20\\include\\rooms.h>
#endif

#pragma endregion

#pragma region ENUMS
enum Mode
{
    Night,
    Day
};

enum Mode_2
{
    DAY,
    NIGHT
};


#pragma endregion

#pragma region AIRPORT_1
void draw_airport_base(int x, int y, int Type){

    int i=0, j=0;

    /*Edificio*/
    setcolor(Type == Night ? DARKGRAY : BROWN);
    line(11+156+x,6-5+y,30+156+x,120-5+y);
    line(11+156+x,6-5+y,320+156+x,6-5+y);
    line(320+156+x,6-5+y,300+156+x,120-5+y);
    line(30+156+x,120-5+y,300+156+x,120-5+y);

    line(23+156+x,18-5+y,42+156+x,120-5+y);
    line(308+156+x,18-5+y,288+156+x,120-5+y);

    line(23+156+x,18-5+y,308+156+x,18-5+y);

    for(i = 0; i < 84; i+=42)
        line(65+i+156+x,18-5+y,84+i+156+x,120-5+y);

    for(i = 0; i < 84; i+=42)
		line(266-i+156+x,18-5+y,246-i+156+x,120-5+y);

    line(166+156+x,18-5+y,166+156+x,120-5+y);

    for(i = 0; i < 25; i+=5)
    {
        if(i<20)
            line(26+156+x+i,32-5+y+(i*4),305+156+x-i,32-5+y+(i*4));
        else if(i>=20)
            line(26+156+x+i-4,32-5+y+(i*4),305+156+x-i+4,32-5+y+(i*4));
    }

    setfillstyle(1,BLUE);
    floodfill(46+156+x,3+y,Type == Night ? DARKGRAY : BROWN);

    setfillstyle(1,Type == Night ? YELLOW : CYAN); 

    for(i=0; i<6; i++)
        for(j=0; j<5; j++)
            floodfill(46+156+x+(i*47),27-5+y+(j*20),Type == Night ? DARKGRAY : BROWN);


    for(i=0; i<=7; i++){
        setfillstyle(1,Type == Night ? DARKGRAY : BLUE);
        if(i<2)
            bar(268+x+(i*11),314-265+y,268+4+x+(i*11),314-250+40+y);
        if(i>5)
            bar(268+x+(i*11),314-265+y,268+4+x+(i*11),314-250+40+y);
        if(i>=2 && i<=5)
            bar(268+x+(i*11),314-265-9+y,268+4+x+(i*11),314-250+40+y);  
    }

    for(i=0; i<=7; i++){
		setfillstyle(1,Type == Night ? DARKGRAY : BLUE);
        if(i<2)
            bar(268-180+x+(i*11),314-265+y,268+4-180+x+(i*11),314-250+40+y);
        if(i>5)
            bar(268-180+x+(i*11),314-265+y,268+4-180+x+(i*11),314-250+40+y);
        if(i>=2 && i<=5)
            bar(268-180+x+(i*11),314-265-9+y,268+4-180+x+(i*11),314-250+40+y);  
    }

    /*Primer Arco - Izquierda*/
    setcolor(Type == Night ? RED : GREEN);
    arc(106-45+65+x,60+19+y,0,180,54);
    arc(106-45+65+x,60+19+y,0,180,40);
    line(146-45+65+x,60+19+y,159-45+65+x,60+19+y);

	setfillstyle(1,Type == Night ? RED : GREEN);
    bar(52-45+65+x,60+y+19,66-45+65+x,90+42+y);
    
    /*Segundo Arco - Medio*/
    setcolor(15);
    arc(198-45+65+x,60+19+y,180,360,52);
    arc(198-45+65+x,60+19+y,180,360,38);
    line(146-45+65+x,61+19+y,159-45+65+x,61+19+y);
    line(237-45+65+x,61+19+y,251-45+65+x,61+19+y);

    /*Tercer Arco - Derecha*/

    setcolor(Type == Night ? BROWN : LIGHTCYAN);
    arc(290-45+65+x,60+19+y,0,180,54);
    arc(290-45+65+x,60+19+y,0,180,40);
    line(237-45+65+x,60+19+y,251-45+65+x,60+19+y);

    setfillstyle(1,Type == Night ? BROWN : LIGHTCYAN);
    bar(330-45+65+x,60+19+y,344-45+65+x,90+19+y);
    
    setfillstyle(1,Type == Night ? RED : GREEN);
    floodfill(54-45+65+x,58+19+y,Type == Night ? RED : GREEN);

	setfillstyle(1,WHITE);
    floodfill(148-45+65+x,62+19+y,15);

    setfillstyle(1,Type == Night ? BROWN : LIGHTCYAN);
    floodfill(332-45+65+x,58+19+y,Type == Night ? BROWN : LIGHTCYAN);
    
    /*Base del aeropuerto*/
    
    setfillstyle(1,Type == Night ? BLUE : DARKGRAY);
    bar(0+x,300-180+y,549+x,356-182+y);
    bar(552+x,278-180+y,562+x,286-182+y);
    
    line(425+x,292-180+y,425+x,355-182+y);

    setfillstyle(1,Type == Night ? CYAN : RED);
    bar(88+x,281-180+y,444+x,292-180+y);
    bar(549+x,282-180+y,565+x,290-182+y);

    setfillstyle(1,Type == Night ? LIGHTGRAY : LIGHTGREEN);
    bar(88+x,292-180+y,424+x,300-180+y);
    bar(425+x,300-180+y,549+x,318-180+y);
    bar(553+x,290-180+y,561+x,346-182+y);

    setfillstyle(1,Type == Night ? BROWN : MAGENTA);
	bar(549+x,300-180+y,565+x,356-182+y);
    bar(555+x,275-180+y,559+x,280-182+y);

    setfillstyle(1,Type == Night ? RED : GREEN);
    bar(565+x,300-180+y,639+x,356-182+y);

    setfillstyle(1,Type == Night ? CYAN : RED);
    bar(10+x,318-180+y,24+x,356-182+y);

    setfillstyle(1,Type == Night ? DARKGRAY : LIGHTMAGENTA);
    bar(40+x,318-180+y,43+x,356-182+y);

    for(i=0; i<=7; i++){
        setfillstyle(1,Type == Night ? RED : BLUE);
        if(i<2)
            bar(268+x+(i*11),314-265+92+y,268+4+x+(i*11),314-250+40+70+y);
        if(i>5)
            bar(268+x+(i*11),314-265+92+y,268+4+x+(i*11),314-250+40+70+y);
        if(i>=2 && i<=5)
            bar(268+x+(i*11),314-265+92-9+y,268+4+x+(i*11),314-250+40+70+y);  
    }

    setcolor(Type == Night ? LIGHTBLUE : GREEN);
    arc(106+20+184+x,79+245-149+y,0,180,54);
    arc(106+20+184+x,79+245-149+y,0,180,40);

    line(52+20+184+x,79+245-149+y,66+20+184+x,79+245-149+y);
    line(146+20+184+x,79+245-149+y,160+20+184+x,79+245-149+y);

    setfillstyle(1,Type == Night ? LIGHTBLUE : GREEN);
    floodfill(55+20+184+x,77+245-149+y,Type == Night ? LIGHTBLUE : GREEN);

    for(i=0; i<20; i++){ 

        if(i>1){
            setfillstyle(1,Type == Night ? CYAN : BLUE);
            bar(2+x+(i*8),302-180+y,2+(i*8)+x+2,302-180+12+y);
        }

        if(i<=1){ 
            setfillstyle(1,Type == Night ? LIGHTGRAY : DARKGRAY);
            bar(57+x+(i*61),335-181+y,57+10+x+(i*61),335-181+20+y);

            setfillstyle(1,LIGHTGREEN);
            bar(135+x+(i*25),325-181+y,135+5+x+(i*25),325-181+30+y);

            setfillstyle(1,Type == Night ? CYAN : RED);
            bar(90+x+(i*14),335-180+y,90+6+x+(i*14),335-180+15+y);
            bar(386+x+(i*14),300-180+y,386+6+x+(i*14),300-180+15+y);
        }

        if(i<=2){
            setfillstyle(1,Type == Night ? RED : LIGHTBLUE);
            bar(438+x+(i*40),320-182+y,438+14+x+(i*40),320-182+36+y);
        }

        if(i<=3){
            setfillstyle(1,Type == Night ? CYAN : BLUE);
            bar(196+x+(i*12),300-180+y,196+6+x+(i*12),300-180+15+y);

            setfillstyle(1,Type == Night ? LIGHTRED : RED);
            bar(172+x+(i*12),340-185+y,172+6+x+(i*12),340-185+15+y);

            setfillstyle(1,Type == Night ? BROWN : YELLOW);
            bar(18+x,300-180+y,164+18+x,318-180+y);

            setfillstyle(1,Type == Night ? LIGHTBLUE : CYAN);
            bar(0+x,300-180+y,16+0+x,318-180+y);
        }

    }
    
}

void draw_lamp(int x, int y, int Type){
    int i=0;
    int Lamp[18*2]={2,10,  12,0,  20,10,  16,22,  20,28
                       ,14,28,  14,140,  22,140,  22,146,  0,146,  0,140
                       ,8,140,  8,28,  3,28,  5,22,  2,10,  12,0,  20,10};
    
    for(i = 0; i<36; i+=2)
        if(i%2 == 0)
        {
            Lamp[i] += x;
            Lamp[i+1] +=y;
        }

    setcolor(15);

    drawpoly(18,Lamp);

    line(2+x,10+y,10+x,19+y);
    line(10+x,19+y,20+x,10+y);
    line(8+x,30+y,14+x,38+y);

    setfillstyle(1,Type == Night ? YELLOW : LIGHTGRAY);
    floodfill(3+x,10+y,15);

    setfillstyle(1,Type == Night ? BROWN : DARKGRAY);
    floodfill(4+x,13+y,15);

    setfillstyle(1,Type == Night ? LIGHTGRAY : BROWN);
    floodfill(10+x,50+y,15);
}

void draw_tower(int x, int y, int Type){

    int i = 0;
	int Forma1[10*2] = {18,54,  29,95,  91,95,  103,55,  114,54,  114,49,  7,49,  7,54,  18,54};
    int Forma2[24*2] = {18,54,  26,54,  32,78,  35,78,  29,54,  42,54,  44,78,  48,78,  46,54,  58,54,  58,78,  62,78,
                        62,54,  75,54,  75,78,  77,78,  78,54,  92,54,  86,78,  90,78,  97,54,  103,54,  95,78,  103,54};

    /*Base*/
    setfillstyle(1,Type == Night ? LIGHTGRAY : DARKGRAY);
    bar(39 + x,141 + y,82 + x,267 + y);

    #pragma region ventanas
    bar(24 + x,104 + y,98 + x,141 + y);
    setfillstyle(1,Type == Night ? DARKGRAY : GREEN);
    bar(30 + x,112 + y,32 + x,130 + y);
    bar(42 + x,112 + y,44 + x,130 + y);
    bar(54 + x,112 + y,56 + x,130 + y);
    bar(66 + x,112 + y,68 + x,130 + y);
    bar(78 + x,112 + y,80 + x,130 + y);
    bar(90 + x,112 + y,92 + x,130 + y);

    /*Parte Arriba de las ventanas*/
    bar(39 + x,97 + y,82 + x,104 + y);

    for(i = 0; i<20; i+=2)
        if(i%2 == 0)
        {
            Forma1[i] += x;
            Forma1[i+1] += y;
        }

    for(i = 0; i<48; i+=2)
        if(i%2 == 0)
        {
            Forma2[i] += x;
            Forma2[i+1] +=y;
        }
    #pragma endregion
    
    setcolor(15);
    drawpoly(9,Forma1);
    drawpoly(24,Forma2);

    setfillstyle(1,Type == Night ? LIGHTGRAY : BLUE);
    floodfill(26+x,65+y,15);

    setfillstyle(1,Type == Night ? BROWN : LIGHTGRAY);
    floodfill(20+x,53+y,15);
    line(24+x,78+y,92+x,78+y);
    
    setfillstyle(1,CYAN);
    bar(30+x,43+y,92+x,48+y);
    bar(70+x,5+y,73+x,43+y);
    bar(55+x,26+y,67+x,30+y);
    bar(59+x,30+y,63+x,43+y);

    if(Type == Night)
    {
        do{
            setfillstyle(1,RED);
            circle(44+x,32+y,9);
            floodfill(44+x,32+y,15);
            delay(400);
            setfillstyle(1,YELLOW);
            circle(44+x,32+y,9);
            floodfill(44+x,32+y,15);
            delay(400);
        }while(!kbhit());
    }else{
        setfillstyle(1,BROWN);
        circle(44+x,32+y,9);
        floodfill(44+x,32+y,15);
    }
            
        

}

void Airport1(int x, int y, int Type){
    int i = 0;

    setlinestyle(0, 0, NORM_WIDTH);

    if(Type == Night){
        for(i=0;i<2000;i++)
            putpixel(rand()%640,rand()%300,WHITE);

        setfillstyle(1,DARKGRAY);    
        bar(0,300,640,480);
    }else{
        setfillstyle(1,LIGHTBLUE);
        bar(0,0,640,300);
        setfillstyle(1,LIGHTGRAY);
        bar(0,300,640,480);
    }

    draw_airport_base(x,149+y,Type);
    draw_lamp(570+x,177+y,Type);
    draw_lamp(594+x,177+y,Type);
    draw_lamp(618+x,177+y,Type);
    draw_tower(7+x,1+y,Type);
}
#pragma endregion

#pragma region AIRPORT_2
void airport_base(int x, int y, int Type){

    int i=0;

    int FirstWindows[16*2] = {0,254-92, 14,248-92, 32,241-92, 51,235-92, 72,229-92, 94,222-92, 119,214-92, 147,207-92, 178,200-92, 211,192-92,
                              250,183-92, 291,172-92, 340,161-92, 388,152-92, 442,142-92, 639,10};

    int SecondWindows[12*2] = {639,10, 639,152, 442,160, 340,162, 292,166, 251,169, 211,174, 179,179, 74,198, 15,207, 1,212, 0,254-92};

    int ThirdWindows[7*2] = {639,190, 501,192, 441,193, 341,195, 211,200, 52,225, 1,232};

    int FourthWindows[7*2] = {639,380, 501,354, 387,322+20, 250,293+20, 96,276+20, 52,272+20, 1,272+20};

    int LinePosX[18] = {15,34,51,74,96,120,148,178,213,252,293,342,390,442,502,506,570,574};

    int LinePosY[18*2] = {158,207,150,203,144,201,138,197,130,193,124,187,116,184,109,180,101
                        ,174,92,170,80,165,71,162,62,162,49,159,37,159,35,159,25,155,23,155};

    int LinePosY2[18*2] = {229,291,226,291,224,291,223,292,219,294,213,300,209,304,204,307,
                         199,308,198,312,196,322,234,330,193,341,193,346,191,353,191,354,191,367,191,240};

    for(i = 0; i<32; i+=2)
    {
        if(i%2 == 0)
        {
            FirstWindows[i] += x;
            FirstWindows[i+1] +=y;
        }

        if(i<24){
            SecondWindows[i] += x;
            SecondWindows[i+1] += y;
        }
           
    }

    for(i = 0; i<36; i+=2){
        if(i%2 == 0)
        {
            LinePosY[i] += y;
            LinePosY[i+1] += y;

            LinePosY2[i] += y;
            LinePosY2[i+1] += y;
        }

        if(i<18){
            LinePosX[i] += x;
            LinePosX[i+1] +=x;
        }
            
    }

    for(i = 0; i<14; i+=2){
        if(i%2 ==0)
        {
            ThirdWindows[i] += x;
            ThirdWindows[i+1] += y;

            FourthWindows[i] += x;
            FourthWindows[i+1] += y;
        }
    }

    setcolor(Type == Night ? DARKGRAY : BROWN);
    drawpoly(16,FirstWindows);
    drawpoly(12,SecondWindows);
    drawpoly(7,ThirdWindows);
    drawpoly(7,FourthWindows);

    for(i = 0; i<18; i++)
        line(LinePosX[i],LinePosY[i*2],LinePosX[i],LinePosY[(i*2)+1]);         

    for(i = 0; i<18; i++){
        if(i<17)
            line(LinePosX[i],LinePosY2[i*2],LinePosX[i],LinePosY2[(i*2)+1]);
        else
            line(LinePosX[i]+8,LinePosY2[i*2],LinePosX[i]+8,LinePosY2[(i*2)+1]);
    }

    line(574+8+x,260+y,574+8+x,369+y);
    line(574+8+x,240+y,639+x,240+y);
    line(574+8+x,260+y,639+x,260+y);
    line(293+x,234+y,390+x,234+y);
       
    for(i = 0; i<22; i++){
        setfillstyle(1,Type == Night ? YELLOW : BLUE);
        if(i<9)
            floodfill(10+(i*15)+x,176+y,Type == Night ? DARKGRAY : BROWN);
        else if(i<18)
			floodfill(10+(i*18)+x,130+y,Type == Night ? DARKGRAY : BROWN);
        else
            floodfill(10+(i*27)+x,130+y,Type == Night ? DARKGRAY : BROWN);
    }
       
    for(i = 0; i<20; i++){
        setfillstyle(1,Type == Night ? YELLOW : BLUE);
        if(i<9)
            floodfill(10+(i*15)+x,276+y,Type == Night ? DARKGRAY : BROWN);
        else if(i<18)
			floodfill(10+(i*16)+x,276+y,Type == Night ? DARKGRAY : BROWN);
        else
            floodfill(10+(i*27)+x,276+y,Type == Night ? DARKGRAY : BROWN);
    }

 
    setfillstyle(1,Type == Night ? LIGHTGRAY : DARKGRAY);
    floodfill(504+x,39+y,Type == Night ? DARKGRAY : BROWN);
    floodfill(572+x,39+y,Type == Night ? DARKGRAY : BROWN);

    floodfill(504+x,222+y,Type == Night ? DARKGRAY : BROWN);
    floodfill(572+x,222+y,Type == Night ? DARKGRAY : BROWN);

    setfillstyle(1,Type == Night ? WHITE : LIGHTGRAY);
    floodfill(616+x,217+y,Type == Night ? DARKGRAY : BROWN);
    floodfill(616+x,304+y,Type == Night ? DARKGRAY : BROWN);

    setfillstyle(1,Type == Night ? WHITE : LIGHTGRAY);
    floodfill(319+x,272+y,Type == Night ? DARKGRAY : BROWN);

    setfillstyle(1,Type == Night ? LIGHTGRAY : CYAN);
    floodfill(345+x,208+y,Type == Night ? DARKGRAY : BROWN);

    setfillstyle(1,Type == Night ? LIGHTBLUE : BROWN);
    floodfill(306+x,186+y,Type == Night ? DARKGRAY : BROWN);

    if(Type == Night){
        setcolor(RED);
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		outtextxy(306+x,202+y,"CLOSED");
    }else{
        setcolor(RED);
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		outtextxy(310+x,201+y,"OPEN");
    }

    setcolor(Type == Night ? DARKGRAY : BROWN);
	line(0+x,350+y,420+x,479+y);

    setfillstyle(1,Type == Night ? DARKGRAY : GREEN);
    floodfill(20+x,354+y,Type == Night ? DARKGRAY : BROWN);
}

void Airport2(int x, int y, int Type){

    int i=0;

    setlinestyle(0, 0, NORM_WIDTH);
    if(Type == Night){
        for(i=0;i<2000;i++)
            putpixel(rand()%640,rand()%280,rand()%16);

        setfillstyle(1,LIGHTGRAY);    
        bar(0,280,640,480);
    }else{
        setfillstyle(1,LIGHTBLUE);    
        bar(0,0,640,280);
        setfillstyle(1,LIGHTGREEN);    
        bar(0,280,640,480);
    }         
    airport_base(x,y,Type);
}
#pragma endregion

#pragma region AIRPORT_3
/**********************
 * Ancho 72 Alto 102  *
 **********************/
void draw_tree(int x, int y)
{
    int i;
    int leafs[4][4] = {
        {13, 31, 12, 12},
        {20, 57, 12, 12},
        {37, 26, 25, 25},
        {51, 50, 17, 17}};
    int stick[6][5] = {
        /* IZQUIERDA */
        {38, 59, 180, 270, 10},
        {25, 57, 180, 300, 10},
        {37, 23, 180, 280, 10},
        {24, 20, 230, 300, 10},
        /* DERECHA */
        {42, 46, 260, 360, 10},
        {54, 44, 250, 360, 10}};

    setcolor(BLACK);
    for (i = 0; i < 4; i++)
    {
        setfillstyle(SOLID_FILL, i < 2 ? LIGHTGREEN : GREEN);
        fillellipse(leafs[i][0] + x, leafs[i][1] + y, leafs[i][2], leafs[i][3]);
    }

    setcolor(BROWN);
    for (i = 0; i < 6; i++)
        arc(stick[i][0] + x, stick[i][1] + y, stick[i][2], stick[i][3], stick[i][4]);

    line(39 + x, 18 + y, 39 + x, 96 + y);
}

void highway(void)
{
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(0, (getmaxy() / 4) + 40, getmaxx(), getmaxy());
}

void highwayline(int y)
{
    setlinestyle(DASHED_LINE, THICK_WIDTH, 3);
    setcolor(WHITE);
    line(0, 0 + y, 640, 0 + y);
}

/**********************
* DAY  PARA DIA       *
* NIGHT PARA NOCHE    *
**********************/
void Airport3(int x, int y, int time)
{

    int i = 0;
    int airport[] = {25, 130, 441, 130, 25, 122, 441, 122, 25, 144, 441, 144, 25, 152, 441, 152, 71, 60, 71, 108, 118, 60, 118, 101, 10, 120, 10, 130, 10, 130, 27, 130, 464, 120, 464, 130, 464, 130, 440, 130, 24, 120, 24, 152, 71, 108, 71, 152, 118, 101, 118, 152, 162, 95, 162, 152, 302, 95, 302, 152, 348, 101, 348, 152, 395, 111, 395, 152, 441, 122, 441, 152, 25, 120, 68, 108, 68, 108, 115, 101, 115, 101, 159, 95, 159, 95, 299, 95, 299, 95, 345, 101, 345, 101, 392, 111, 392, 111, 440, 122, 10, 120, 25, 113, 25, 113, 66, 97, 66, 97, 115, 85, 115, 85, 161, 79, 161, 79, 197, 76, 197, 76, 238, 76, 238, 76, 277, 76, 277, 76, 322, 82, 322, 82, 365, 91, 365, 91, 403, 101, 403, 101, 464, 120, 244, 85, 96, 97, 59, 107, 89, 76};
    int flood[] = {45, 148, 45, 137, 48, 123, 80, 123, 120, 123, 160, 123, 300, 123, 310, 123, 350, 123, 94, 114, 96, 137, 98, 148, 139, 148, 139, 139, 139, 110, 223, 106, 224, 137, 227, 148, 328, 148, 316, 138, 314, 106, 368, 116, 359, 137, 368, 148, 411, 148, 413, 140, 423, 123, 410, 118, 49, 120, 93, 122};
    int againpaint[] = {10, 120, 25, 113, 25, 113, 66, 97, 66, 97, 115, 85, 115, 85, 161, 79, 161, 79, 197, 76, 197, 76, 238, 76, 238, 76, 277, 76, 277, 76, 322, 82, 322, 82, 365, 91, 365, 91, 403, 101, 403, 101, 464, 120, 71, 60, 71, 108, 118, 60, 118, 101, 10, 120, 10, 130, 10, 130, 27, 130, 464, 120, 464, 130, 464, 130, 440, 130, 25, 120, 68, 108, 68, 108, 115, 101, 115, 101, 159, 95, 159, 95, 299, 95, 299, 95, 345, 101, 345, 101, 392, 111, 392, 111, 440, 122, 56, 19, 67, 53, 53, 16, 138, 22};

    setlinestyle(0, 0, NORM_WIDTH);

    /*segun el  parametro se pintara de dia o de noche */
    setfillstyle(SOLID_FILL, time == DAY ? LIGHTCYAN : BLACK);
    bar(0, 0, getmaxx(), (getmaxy() / 4) + 40);

    setfillstyle(SOLID_FILL,WHITE);
    if(time == NIGHT)
        for(i = 0; i < 1500; i++)
        {
            putpixel(rand()%640,rand()%300,WHITE);
            fillellipse(rand()%640,rand()%300,1,1);
        }
    
    highway();
    highwayline(300);
    highwayline(350);
    /*elipse de color naranja */
    setfillstyle(SOLID_FILL, BROWN);
    setcolor(BROWN);
    ellipse((getmaxx() / 2) - 80 + x, (getmaxy() / 4) + 40, 0, 360, getmaxx() / 2 + x, getmaxy() / 14);
    fillellipse((getmaxx() / 2) - 80 + x, (getmaxy() / 4) + 40, getmaxx() / 2 + x, getmaxy() / 14);

    #pragma region drawtower
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(60 + x, 10 + y, 125 + x, 16 + y);
    bar(53 + x, 16 + y, 138 + x, 22 + y);
    setcolor(LIGHTGRAY);

    setlinestyle(SOLID_LINE, THICK_WIDTH, 1);
    line(56 + x, 19 + y, 67 + x, 53 + y);
    line(132 + x, 19 + y, 122 + x, 53 + y);
    bar(60 + x, 51 + y, 133 + x, 59 + y);
    setfillstyle(SOLID_FILL, time == DAY ? BLUE : YELLOW);
    floodfill(94 + x, 34 + y, LIGHTGRAY);
    #pragma endregion

    setcolor(LIGHTGRAY);
    for (i = 0; i < 152;)
    {
        if (i < 144)
        {

            setcolor(LIGHTGRAY);
            line(airport[i] + x, airport[i + 1] + y, airport[i + 2] + x, airport[i + 3] + y);
            i += 4;
        }
        if (i > 143)
        {
            setfillstyle(SOLID_FILL, DARKGRAY);
            floodfill(airport[i] + x, airport[i + 1] + y, LIGHTGRAY);
            i += 2;
        }
    }
    /*evalua si es de dia o de noche para asi rellenas las time*/
    setfillstyle(SOLID_FILL, time == DAY ? BLUE : YELLOW);

    /*rellenas las time según lo evaluado arriba*/
    for (i = 0; i < 61; i += 2)
    {
        floodfill(flood[i] + x, flood[i + 1] + y, LIGHTGRAY);
    }

    /*VUELVE A TRAZAR LAS LINEAS DEL TECHO SUPERIOR*/
    setcolor(DARKGRAY);
    for (i = 0; i < 94; i += 4)
    {
        line(againpaint[i] + x, againpaint[i + 1] + y, againpaint[i + 2] + x, againpaint[i + 3] + y);
    }
    draw_tree(10, 102);
    draw_tree(500, 102);

}

#pragma endregion

#pragma region AIRPORT_4
void tower(int x, int y)
{
    int pillar[5][2] = {{35,75},{63,75},{66,221},{31,221},{35,75}};
    int i, j;
    int retainers[5][5][2] = {
        {{64,118},{74,118},{74,124},{64,124},{64,118}},
        {{64,124},{73,124},{68,127},{64,127},{64,124}},
        {{33,124},{34,118},{23,118},{24,124},{33,124}},
        {{33,124},{33,127},{29,127},{25,124},{33,124}}};

    int cable[4][4] = {{66,118,78,73},{88,70,73,118},{31,118,19,73},{9,70,24,118}};

    /* la 0 y 1 son las grandes */
    int cabin_ellipses[4][6] = {{49,61,180,360,49,14},{49,48,0,180,49,14},{49,61,180,360,49,6},{49,48,180,360,49,6}};
    
    /* la 0 y 1 son las laterales */
    int cabin_line[10][4] = {{98,48,98,61},{0,48,0,61},{4,51,4,64},{15,53,15,66},{26,54,26,67},{38,55,38,68},{51,55,51,68},{63,55,63,68},{78,54,78,66},{90,52,90,65}};

    int top[2][9][2] = {
        {{73,14},{71,17},{71,21},{69,22},{69,28},{68,28},{68,30},{69,30},{69,35}},
        {{27,35},{27,30},{28,30},{28,28},{27,28},{27,22},{25,21},{25,17},{22,14}}};

    int top_ellipses[2][6] = {{48,17,180,360,22,4},{48,14,0,180,25,6}};


    for(i = 0; i < 9; i++)
    {
        if(i < 5)
        {
            pillar[i][0] += x;
            pillar[i][1] += y;

            for(j = 0; j < 5; j++)
            {
                retainers[j][i][0] += x;
                retainers[j][i][1] += y;
            }
        }

        for(j = 0; j < 2; j++)
        {
            top[j][i][0] += x;
            top[j][i][1] += y;
        }
        
        
    }
        

    setlinestyle(SOLID_LINE,1,1);
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    fillpoly(5,*pillar);
    drawpoly(5,*pillar);

    for(i = 0; i < 5; i++)
    {
        fillpoly(5,*retainers[i]);
        drawpoly(5,*retainers[i]);
    }
        
    setlinestyle(SOLID_LINE,1,3);
    line(34+x,9+y,34+x,0+y);
    line(63+x,9+y,63+x,0+y);
    for(i = 0; i < 4; i++)
        line(cable[i][0] + x, cable[i][1] + y, cable[i][2] + x, cable[i][3] + y);
    
   
    setlinestyle(SOLID_LINE,1,1);
    for(i = 0; i < 2; i++)
        ellipse(cabin_ellipses[i][0] + x, cabin_ellipses[i][1] + y, cabin_ellipses[i][2],cabin_ellipses[i][3],cabin_ellipses[i][4],cabin_ellipses[i][5]);
    
    for(i = 0; i < 2; i++)
        line(cabin_line[i][0] + x, cabin_line[i][1] + y,cabin_line[i][2] + x,cabin_line[i][3] + y);

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill(1 + x,55 + y,DARKGRAY);

    for(i = 2; i < 4; i++)
        ellipse(cabin_ellipses[i][0] + x,cabin_ellipses[i][1] + y,cabin_ellipses[i][2],cabin_ellipses[i][3],cabin_ellipses[i][4],cabin_ellipses[i][5]);
    
    setfillstyle(SOLID_FILL,getpixel(0,0)!=LIGHTBLUE?YELLOW:LIGHTBLUE);
    floodfill(1 + x,55 + y,DARKGRAY);

    for(i = 2; i < 10; i++)
        line(cabin_line[i][0] + x,cabin_line[i][1] + y,cabin_line[i][2] + x,cabin_line[i][3] + y);

    for(i = 0; i < 2; i++)
        drawpoly(9,*top[i]);

    for(i = 1; i < 2; i++)
        ellipse(top_ellipses[i][0] + x,top_ellipses[i][1] + y,top_ellipses[i][2],top_ellipses[i][3],top_ellipses[i][4],top_ellipses[i][5]);

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill(48 + x,17 + y,DARKGRAY);
    floodfill(48 + x,29 + y,DARKGRAY);

}

void edifice(int x, int y)
{
    int wall[12][2] = {{0,16},{18,16},{18,5},{98,3},{98,12},{233,9},{233,2},{243,1},{304,0},{304,64},{0,69},{0,16}};

    int details[12][4] = {{0,47,23,47},{23,47,23,73},{18,47,18,16},{29,5,30,69},{42,4,42,69},{98,12,98,46},{98,46,76,46},{76,46,77,68},{98,43,241,40},{233,8,241,8},{241,8,241,40},{243,1,244,65}};

    int windows[2][10] = {{167,41,167,57,106,59,106,43,167,41},{241,40,194,41,194,56,241,54,241,40}};
    int i, j;

    for(i = 0; i < 12; i++)
    {
        wall[i][0] += x;
        wall[i][1] += y;

        if(i < 10) for(j = 0; j < 2; j ++)
            windows[j][i] += i%2==0 ? x : y;

    }    

    setcolor(BLACK);

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    fillpoly(12,*wall);
    drawpoly(12,*wall);
    
    setfillstyle(SOLID_FILL,getpixel(0,0)!=LIGHTBLUE?YELLOW:LIGHTBLUE);
    fillpoly(5,windows[0]);
    fillpoly(5,windows[1]);

    bar(178 + x,51 + y,185 + x,66 + y);

    setcolor(BLACK);
    for(i = 0 ; i < 12; i++)
        line(details[i][0] + x, details[i][1] + y, details[i][2] + x, details[i][3] + y);
}

void Airport4(bool isNight)
{
    int sky[5][2] = {{0,0},{640,0},{640,370},{0,390},{0,0}};
    int floor[5][2] = {{640,350},{0,370},{0,480},{640,480},{640,350}};
    int i;

    setlinestyle(0, 0, NORM_WIDTH);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,isNight ? BLACK : LIGHTBLUE);
    fillpoly(5,*sky);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    if(isNight)
        for(i = 0; i < 500; i++)
        {
            fillellipse(rand()%640,rand()%400,i%2,i%2);
            putpixel(rand()%640,rand()%400,WHITE);
        }

    setfillstyle(SOLID_FILL,isNight ? DARKGRAY : LIGHTGRAY);
    fillpoly(5,*floor);

    tower(187,105);
    edifice(0,315);

    setcolor(WHITE);
    setlinestyle(DOTTED_LINE,0,3);
    line(0,432,640,412);
    setlinestyle(SOLID_LINE,0,3);
}
#pragma endregion

#pragma region AIRPORT_5
void draw_backbuilding(int x, int y, bool isNight)
{
    int i, ii, xpos = x, ypos = y, xmargin = 5, ymargin = 3, win_width = 3, win_height = 5;
    /*Drawing building's base*/
    setfillstyle(1, WHITE);
    bar(x, y, x+49, y+63);

    /*Drawing windows*/
    for (ii = 1; ii<= 5; ii++)
    {
        setfillstyle(SOLID_FILL, isNight?BLACK:CYAN);
        bar(xpos+xmargin, ypos+ymargin, xpos+xmargin+41, ypos+ymargin+7); /*Background for windows*/
        setfillstyle(SOLID_FILL, isNight?YELLOW:LIGHTBLUE);
        for(i = 1; i<= 10; i++)
        {
            bar(xpos+xmargin+1, ypos+ymargin+1, xpos+xmargin+3, ypos+ymargin+6);
			xpos += win_width+1;
        }
        ypos += win_height+ymargin+3;
        xpos = x;
    }

}

void draw_frontbuilding(int x, int y, bool isNight)
{
    int i, ii, xpos = x, ypos = y, xmargin = 3, ymargin = 3, win_width = 7, win_height = 11;
    
    /*Drawing building base*/
    setfillstyle(SOLID_FILL, WHITE);
    bar(x, y, x+454, y+33);

    /*Drawing windows (7*11)*/
    for (ii = 1; ii<= 2; ii++) /*Amount of rows*/
    {
        setfillstyle(SOLID_FILL, isNight?BLACK:CYAN);
        bar(xpos+xmargin, ypos+ymargin, xpos+xmargin+448, ypos+ymargin+11); /*Background for windows*/
        setfillstyle(SOLID_FILL, isNight?YELLOW:LIGHTBLUE);
        for(i = 1; i<= 56; i++) /*Amount of windows*/
        {
            bar(xpos+xmargin+1, ypos+ymargin+1, xpos+xmargin+7, ypos+ymargin+11);
			xpos += win_width+1;
        }
        ypos += win_height+ymargin+1;
        xpos = x;
    }

}

void draw_thirdbuilding(int x, int y, bool isNight)
{
    int i, ii, xpos = x, ypos = y, xmargin = 4, ymargin = 3, win_width = 5, win_height = 4;
    /*Drawing building's base (63*50)*/
    setfillstyle(1, WHITE);
    bar(x, y, x+64, y+62);

    /*Drawing windows*/
    for (ii = 1; ii<= 6; ii++)
    {
        setfillstyle(SOLID_FILL, isNight?BLACK:CYAN);
        bar(xpos+xmargin, ypos+ymargin, xpos+xmargin+53, ypos+ymargin+4); /*Background for windows*/
        setfillstyle(SOLID_FILL, isNight?YELLOW:LIGHTBLUE);
        for(i = 1; i<= 10; i++)
        {
            bar(xpos+xmargin, ypos+ymargin, xpos+xmargin+4, ypos+ymargin+4);
			xpos += win_width+1;
        }
        ypos += win_height+ymargin+2;
        xpos = x;
    }

}

void draw_elipseStructure(int x, int y, bool isNight)
{
    /*Main ellipse(86,75)*/
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x, y, 86, 75);

    /*Inner ellipse (68,67)*/
    setfillstyle(SOLID_FILL, isNight?YELLOW:LIGHTBLUE);
    fillellipse(x, y, 68, 67);

    /*Drawing pilars*/
    setfillstyle(SOLID_FILL, WHITE);
    bar(x+11, y-66, x+14, y);
    bar(x+32, y-66, x+32+3, y);
    bar(x+53, y-43, x+53+3, y);
    bar(x-9, y-66, x-12, y);
    bar(x-30, y-66, x-30-3, y);
    bar(x-53, y-43, x-53-3, y);
}

void draw_tower_2(int x, int y, bool isNight)
{
    int i = 0;
    int tower[] = {0, 56, 36, 56, 36, 59, 34, 59, 34, 85, 36, 85, 36, 88, 32, 88, 32, 93, 30, 101, 25, 113, 27, 170, 28, 215, 9, 215, 10, 170, 12, 113, 7, 101, 5, 93, 5, 89, 0, 88, 0, 85, 3, 85, 3, 59, 0, 59, 0, 56};
    int aerial[] = {19, 25, 22, 31, 22, 55, 15, 55, 15, 31, 19, 25};

    /*Fixing polygons' positions*/
        /*Command tower*/
    for (i = 0; i < 50; i++)
    {
        if (i%2 == 0)
        {
            tower[i] += x;
        }
        else
        {
            tower[i] += y;
        }
    }
        /*Aerial*/
    for (i = 0; i < 12; i++)
    {
        if (i%2 == 0)
        {
            aerial[i] += x;
        }
        else
        {
            aerial[i] += y;
        }
    }

    /*Drawing structures*/
        /*Tower*/
    fillpoly(25, tower);

        /*Aerial*/
    setcolor(LIGHTGRAY);
    drawpoly(6, aerial);
    line(x+19, y+25, x+19, y+2);
    line(x+16, y+32, x+21, y+32);
    line(x+16, y+32, x+21, y+44);
    line(x+21, y+32, x+16, y+44);
    line(x+16, y+44, x+21, y+44);
    line(x+16, y+44, x+21, y+55);
    line(x+21, y+44, x+16, y+55);

    /*Windows*/
    setfillstyle(SOLID_FILL, isNight?YELLOW:LIGHTBLUE);
    bar(x+3, y+62, x+32+2, y+62+5);
    bar(x+3, y+72, x+32+2, y+72+5);
    bar(x+3, y+79, x+32+2, y+79+5);
        /*Circular windows*/
    fillellipse(x+19,y+143,3,3);
    fillellipse(x+19,y+152,3,3);
    fillellipse(x+19,y+160,3,3);
    fillellipse(x+19,y+169,3,3);
    fillellipse(x+19,y+177,3,3);
    fillellipse(x+19,y+185,3,3);


    
}

void draw_pavement(int x, int y)
{
    int i = 0, xpos = x, ypos = y, margin = 11;
    /*Floor*/
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(x, y, x+640, y+109);

    /*Yellow line*/
    setfillstyle(SOLID_FILL, YELLOW);
    bar(x, y+13, x+640, y+13+2);

    /*White lines*/
    for (i = 1; i <= 22; i++)
    {
        setfillstyle(SOLID_FILL, WHITE);
        bar(xpos+margin, ypos+24, xpos+margin+19, ypos+24+2);
        bar(xpos+margin, ypos+64, xpos+margin+19, ypos+64+2);
        xpos += margin+19;
    }
}

void draw_grass(int x, int y)
{
    /*Grass*/
    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(x, y, x+640, y+18);

    /*Shadow*/
    setfillstyle(SOLID_FILL, GREEN);
    bar(x, y, x+640, y+5);
}

void Airport5(bool isNight)
{
    int i;
    setcolor(WHITE);
    setlinestyle(0, 0, NORM_WIDTH);
    setfillstyle(SOLID_FILL,isNight?BLACK:CYAN);
    bar(0,0,getmaxx(),getmaxy());
    
    setfillstyle(SOLID_FILL,WHITE);
    if(isNight)
        for(i = 0; i < 500; i++)
        {
            fillellipse(rand()%640,rand()%400,i%2,i%2);
            putpixel(rand()%640,rand()%400,WHITE);
        }
    
    draw_grass(0,353);
    draw_backbuilding(89,275,isNight);
    draw_thirdbuilding(435,302,isNight);
    draw_frontbuilding(0,337,isNight);
	draw_elipseStructure(223,370,isNight);
    draw_tower_2(279, 124,isNight);
    draw_pavement(0, 371);
}

#pragma endregion

#pragma region LOBBY

void chairleft(int x, int y);
void chairmeddle(int x, int y);
void chairRight(int x, int y);
void table(int y);
void Screen(int x, int y, int position);
void environment(int y);
void tv(int x, int y);
void windows(void);

void Planta(int x, int y)
{
	int i = 0;

    int Maceta[] = {20-17,405-287,20-17,449-284,20-17,451-285,27-17,451-285,28-17,454-285,81-17,454-285,82-17,451-285,90-17,451-285,92-17,449-285,92-17,405-285,89-17,404-285,89-17,402-285,86-17,405-285,86-17,406-285,86-17,408-285,82-17,408-285,86-17,401-285,86-17,400-285,84-17,399-285,84-17,397-285,82-17,396-285,82-17,388-285,80-17,398-285,72-17,398-285,80-17,386-285,29-17,386-285,27-17,388-285,27-17,396-285,25-17,397-285,25-17,399-285,23-17,400-285,23-17,401-285,20-17,402-285,20-17,404-285,23-17,405-285,23-17,406-285,25-17,408-285,30-17,408-285,29-17,398-285,37-17,398-285};

    setlinestyle(0, 0, NORM_WIDTH);
    setfillstyle(1,DARKGRAY);
    bar(34+x,36+y,37+x,100+y);

     for(i = 0; i<80; i+=2)
        if(i%2 == 0)
        {
            Maceta[i] += x;
            Maceta[i+1] +=y;
        }

    setfillstyle(1,BROWN);
    fillpoly(40,Maceta);

    /*Hojas*/
    setcolor(YELLOW);
    setfillstyle(1,YELLOW);
    ellipse(35+x,15+y,0,360,12,15);
    floodfill(33+x,15+y,YELLOW);
    ellipse(20+x,20+y,0,360,14,13);
    floodfill(20+x,20+y,YELLOW);
    ellipse(15+x,35+y,0,360,15,10);
    floodfill(20+x,35+y,YELLOW);
    ellipse(21+x,50+y,0,360,14,13);
    floodfill(21+x,50+y,YELLOW);
    ellipse(37+x,53+y,0,360,12,16);
    floodfill(40+x,50+y,YELLOW);
    ellipse(53+x,50+y,0,360,14,13);
    floodfill(53+x,50+y,YELLOW);
    ellipse(57+x,35+y,0,360,15,10);
    floodfill(53+x,35+y,YELLOW);
    ellipse(53+x,20+y,0,360,14,13);
    floodfill(53+x,20+y,YELLOW);

    /*Centro y tallo de la planta*/
    setcolor(LIGHTGRAY);
    circle(37+x,36+y,15);
    setfillstyle(1,BROWN);
    floodfill(37+x,36+y,LIGHTGRAY);
}

void Reloj(int x, int y){

    /*Marco*/
    setlinestyle(0, 0, NORM_WIDTH);
    setcolor(DARKGRAY);
    circle(25+x,25+y,22);
    setfillstyle(1,DARKGRAY);
    floodfill(25+x,25+y,DARKGRAY);

    setcolor(WHITE);
    circle(25+x,25+y,17);
    setfillstyle(1,WHITE);
    floodfill(25+x,25+y,WHITE);
    circle(25+x,25+y,2);

    setcolor(DARKGRAY);
    
    /*Agujas*/
    line(25+x,25+y,18+x,17+y);
    line(25+x,25+y,30+x,19+y);

    /*Numeros*/
    line(25+x,9+y,25+x,11+y);
    line(25+x,39+y,25+x,41+y);

    line(9+x,25+y,11+x,25+y);
    line(39+x,25+y,41+x,25+y);
}

void RecepcionCompleta(int x, int y){
    setlinestyle(0, 0, NORM_WIDTH);
    setcolor(WHITE);
    rectangle(0+x,0+y,640+x,480+y);

    /*Mesa de recpcion*/
    line(0+x,262+y,331+x,235+y);
    line(0+x,278+y,362+x,238+y);
    line(331+x,235+y,362+x,238+y);
    line(362+x,238+y,337+x,330+y);
    line(0+x,425+y,337+x,330+y);
    line(285+x,0+y,285+x,238+y);

    setfillstyle(1,BLUE);
    floodfill(2+x,2+y,WHITE);

    setfillstyle(1,RED);
    floodfill(2+x,264+y,WHITE);

    setfillstyle(1,LIGHTGRAY);
    floodfill(2+x,340+y,WHITE);

    /*Adornos*/
	setfillstyle(1,DARKGRAY);
    bar(67+x,0+y,69+x,28+y);
    bar(118+x,0+y,120+x,64+y);
    bar(168+x,0+y,170+x,40+y);
    setfillstyle(1,LIGHTGRAY);
    bar(62+x,28+y,76+x,102+y);
    bar(112+x,64+y,126+x,138+y);
    bar(162+x,40+y,176+x,110+y);

    /*Ascensor*/
    line(349+x,288+y,434+x,302+y);
    line(434+x,302+y,434+x,38+y);
    line(434+x,38+y,581+x,27+y);
    line(581+x,27+y,581+x,327+y);
    line(581+x,327+y,640+x,340+y);
    line(434+x,302+y,449+x,295+y);

    setfillstyle(1,LIGHTBLUE);
    floodfill(350+x,2+y,WHITE);

    setfillstyle(1,CYAN);
    bar(591+x,148+y,604+x,176+y);

    setfillstyle(1,BROWN);
    bar(594+x,151+y,601+x,159+y);
    bar(594+x,166+y,601+x,174+y);

    setfillstyle(1,DARKGRAY);
    setcolor(WHITE);
    line(450+x,46+y,513+x,42+y);
    line(513+x,41+y,512+x,306+y);
    line(512+x,306+y,449+x,295+y);
    line(449+x,295+y,450+x,46+y);
    floodfill(452+x,48+y,WHITE);

    setfillstyle(1,LIGHTGRAY);
    line(513+x,42+y,581+x,35+y);
    line(513+x,305+y,580+x,316+y);
    floodfill(515+x,44+y,WHITE);

    setfillstyle(1,BLACK);
    floodfill(436+x,297+y,WHITE);

    /*Piso*/
    setfillstyle(1,LIGHTGREEN);
    floodfill(384+x,312+y,WHITE);

    /*Demas Objetos*/
    Planta(0+x,310+y);
    Reloj(325+x,60+y);
}

void chairleft(int x, int y)
{
    int i;
    int chair[90] = {49, 33, 77, 33, 76, 65, 69, 65, 67, 95, 83, 95, 83, 107, 53, 107, 53, 121, 50, 121, 51, 128, 48, 128, 48, 141, 51, 141, 50, 147, 79, 147, 85, 156, 87, 163, 74, 163, 74, 156, 50, 156, 50, 163, 39, 163, 39, 156, 13, 156, 13, 163, 2, 163, 4, 154, 9, 146, 39, 146, 39, 141, 42, 141, 42, 128, 40, 128, 40, 121, 38, 121, 37, 108, 5, 108, 4, 95, 55, 95, 56, 81, 56, 65, 48, 65, 48, 62, 49, 33};
    int cushiondown[14] = {10, 82, 5, 90, 5, 95, 83, 96, 83, 87, 78, 82, 10, 82};
    int cushionup[] = {48, 62, 37, 62, 32, 57, 33, 9, 38, 2, 86, 2, 92, 8, 89, 56, 84, 62, 76, 62, 77, 33, 49, 33, 48, 62};

    for (i = 0; i < 90; i++)
    {
        if (i % 2 == 0)
            chair[i] += x;
        else if (i % 2 != 0)
            chair[i] += y;
        if (i < 14 && i % 2 == 0)
            cushiondown[i] += x;
        else if (i < 14 && i % 2 != 0)
            cushiondown[i] += y;
        if (i < 26 && i % 2 == 0)
            cushionup[i] += x;
        else if (i < 26 && i % 2 != 0)
            cushionup[i] += y;
    }
    setfillstyle(SOLID_FILL, BLUE);
    fillpoly(13, cushionup);
    fillpoly(7, cushiondown);
    setfillstyle(SOLID_FILL, DARKGRAY);
    fillpoly(45, chair);
}

void chairmeddle(int x, int y)
{
    int i;
    int chair[104] = {28, 33, 61, 33, 61, 65, 52, 65, 52, 98, 83, 98, 83, 108, 53, 108, 53, 121, 51, 121, 51, 122, 49, 122, 49, 128, 48, 128, 48, 142, 50, 142, 50, 146, 79, 146, 84, 153, 87, 159, 87, 164, 75, 164, 75, 156, 49, 155, 49, 164, 38, 164,
                      38, 155, 13, 155, 13, 164, 2, 164, 2, 159, 5, 151, 9, 146, 40, 146, 40, 142, 42, 142, 42, 128, 40, 128, 40, 122, 38, 122, 38, 121, 36, 121, 36, 108, 6, 108, 5, 108, 5, 98, 38, 98, 38, 65, 29, 65, 28, 33};
    int cushiondown[14] = {11, 81, 5, 90, 5, 98, 83, 98, 83, 89, 77, 82, 11, 81};
    int cushionup[26] = {29, 65, 21, 65, 15, 53, 15, 10, 21, 2, 69, 2, 74, 11, 74, 53, 69, 62, 61, 65, 61, 33, 28, 33, 29, 65};

    for (i = 0; i < 104; i++)
    {
        if (i % 2 == 0)
            chair[i] += x;
        else
            chair[i] += y;
        if (i < 14 && i % 2 == 0)
            cushiondown[i] += x;
        else if (i < 14 && i % 2 != 0)
            cushiondown[i] += y;
        if (i < 26 && i % 2 == 0)
            cushionup[i] += x;
        else if (i < 26 && i % 2 != 0)
            cushionup[i] += y;
    }

    setfillstyle(SOLID_FILL, BLUE);
    fillpoly(7, cushiondown);
    fillpoly(13, cushionup);

    setfillstyle(SOLID_FILL, DARKGRAY);
    fillpoly(50, chair);
}

void chairRight(int x, int y)
{ /*                     1,     2,        3,       4      5       6         7        9        10       11       12       13      14      15       17      18     19     20             21      22      23      24      25      26       28       29      30*/
    int chair[94] = {6, 164, 9, 153, 14, 146, 42, 146, 42, 141, 45, 121, 45, 128, 43, 128, 43, 120, 40, 120, 40, 108, 10, 108, 10, 97, 26, 97, 23, 65, 17, 65, 15, 59, /*x*/ 14, 32, 42, 32, 45, 37, 45, 65, 37, 65, 39, 97, 87, 97, 87, 109, 56, 108,
                     56, 108, 56, 120, 53, 120, 53, 128, 52, 128, 52, 141, 54, 141, 54, 146, 84, 146, 84, 146, 89, 153, 91, 164, 79, 164, 79, 156, 55, 156, 55, 164, 43, 164, 43, 156, 18, 156, 18, 164, 6, 164};
    /*                    31     32      33       34         35      36       38       39       40      41        42       43       44       45      46         47      48       49        50     51       52      */
    int cushiondown[14] = {10, 97, 10, 88, 15, 81, 82, 81, 87, 88, 87, 97, 10, 97};
    int cushionup[30] = {14, 30, 15, 57, 16, 61, 9, 60, 4, 52, 1, 6, 6, 1, 55, 1, 60, 6, 63, 53, 58, 60, 45, 60, 45, 36, 42, 30, 14, 30};
    int i;

    for (i = 0; i < 94; i++)
    {
        if (i % 2 == 0)
            chair[i] += x;
        else
            chair[i] += y;
        if (i < 14 && i % 2 == 0)
            cushiondown[i] += x;
        else if (i < 14 && i % 2 != 0)
            cushiondown[i] += y;
        if (i < 30 && i % 2 == 0)
            cushionup[i] += x;
        else if (i < 30 && i % 2 != 0)
            cushionup[i] += y;
    }

    setfillstyle(SOLID_FILL, BLUE);
    fillpoly(7, cushiondown);
    fillpoly(15, cushionup);
    setfillstyle(SOLID_FILL, DARKGRAY);
    fillpoly(46, chair);
}

void table(int y)
{

    setfillstyle(SOLID_FILL, BROWN);
    bar(0, 0 + y, getmaxx(), 17 + y);
}

/*
en "y" siempre tiene que ir 99 menos que la funcion table
*/
void Screen(int x, int y, int position)
{
    int i;
    int frame[18] = {1, 5, 4, 89, 25, 89, 25, 97, 54, 97, 54, 89, 74, 89, 71, 5, 1, 5};
    int screen[10] = {10, 12, 12, 84, 69, 84, 66, 12, 10, 12};
    int frameright[18] = {4, 2, 0, 84, 17, 83, 11, 98, 63, 98, 70, 86, 74, 86, 79, 2, 4, 2};
    int screenright[10] = {8, 7, 72, 7, 68, 80, 5, 80, 8, 7};
    int drawscreen[30] = {34, 11, 26, 21, 26, 33, 14, 33, 13, 38, 14, 43, 24, 43, 25, 65, /*x*/ 34, 64, 34, 44, 63, 43, 64, 39, 62, 34, 36, 34, 34, 11};
    for (i = 0; i < 30; i++)
    {
        if (i < 18 && i % 2 == 0)
            frame[i] += x;
        if (i < 18 && i % 2 != 0)
            frame[i] += y;
        if (i < 10 && i % 2 == 0)
        {
            screen[i] += x;
            screenright[i] += x;
        }
        if (i < 10 && i % 2 != 0)
        {
            screen[i] += y;
            screenright[i] += y;
        }
        if (i < 18 && i % 2 == 0)
            frameright[i] += x;
        if (i < 18 && i % 2 != 0)
            frameright[i] += y;
        if (i % 2 == 0)
            drawscreen[i] += x;
        if (i % 2 != 0)
            drawscreen[i] += y;
    }

    if (position == LEFT)
    {
        setfillstyle(SOLID_FILL, DARKGRAY);
        fillpoly(9, frame);
        setfillstyle(SOLID_FILL, WHITE);
        fillpoly(5, screen);
        setcolor(BLACK);
        for (i = 0; i < 50; i += 5)
            line(14 + x, 21 + y + i, 63 + x, 21 + y + i);
    }
    else
    {
        setfillstyle(SOLID_FILL, DARKGRAY);
        fillpoly(9, frameright);
        setfillstyle(SOLID_FILL, WHITE);
        fillpoly(5, screenright);
        setfillstyle(SOLID_FILL, BLACK);
        drawpoly(15, drawscreen);
    }
}

void environment(int y)
{
    windows();
    Screen(getmaxx() / 3 + 20, 0 + y, LEFT);
    Screen(getmaxx() / 3 + 240, 0 + y, RIGHT);
    Screen(30, 0 + y, LEFT);
    table(99 + y);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 367, getmaxx(), getmaxy());

    chairleft(30, 40 + y);
    chairmeddle(getmaxx() / 3 + 30, 40 + y);
    chairRight(getmaxx() / 3 + 230, 40 + y);
}

void windows()
{
    int i;
    int Windows[20] = {106, 0, 106, 437, 230, 0, 230, 347, 408, 0, 408, 437, 0, 122, 640, 122, 0, 250, 640, 250};
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, 640, 437);
    setcolor(BLACK);
    for (i = 0; i < 20; i += 4)
    {
        line(Windows[i], Windows[i + 1], Windows[i + 2], Windows[i + 3]);
    }
}
#pragma endregion
#endif