#ifndef FLAGS_H
#define FLAGS_H 1
#ifndef __GRAPHX_DEF_
    #include <GRAPHICS.H>
#endif
#ifndef __OLDCONIO__
    #include <conio.h>
#endif
#ifndef __DOS_DEF_
    #include <dos.h>
#endif

enum Nations
{
    Nicaragua,
    Brazil,
    Spain,
    Argentina,
    USA
};

/* Funcion que dibuja la bandera de brazil */
void BrazilFlag(int x, int y){
    
    /*Fondo de la bandera*/
    setfillstyle(1,GREEN);
    bar(0+x,0+y,60+x,30+y);

    /*Dibujamos el escudo de la bandera*/
    setfillstyle(1,YELLOW);
    setcolor(YELLOW);
    line(5+x,13+y,30+x,6+y);
    line(5+x,13+y,30+x,23+y);
    line(30+x,6+y,56+x,13+y);
    line(30+x,23+y,56+x,13+y);
    floodfill(30+x,14+y,YELLOW);

    setfillstyle(1,BLUE);
    fillellipse(30+x,14+y,8,6);
}

/* Funcion que dibuja la bandera de Argentina */
void ArgentinaFlag(int x, int y){

    /*Franjas de la bandera*/
    setfillstyle(1,LIGHTBLUE);
    bar(0+x,0+y,60+x,10+y);
    bar(0+x,20+y,60+x,30+y);

    setfillstyle(1,WHITE);
    bar(0+x,10+y,60+x,20+y);

    /*Dibujamos el escudo de la bandera*/
    setfillstyle(1,YELLOW);
    fillellipse(30+x,15+y,5,5);
}

/* Funcion que dibuja la bandera de Nicaragua */
void NicaraguaFlag(int x, int y){

    /*Coordenadas del triangulo de la bandera de Nicaragua*/
    int Triangulo[] = {27,17, 30,13, 32,17, 27,17};
    int i = 0;

    /*Franjas de la bandera*/
    setfillstyle(1,BLUE);
    bar(0+x,0+y,60+x,10+y);
    bar(0+x,20+y,60+x,30+y);

    setfillstyle(1,WHITE);
    bar(0+x,10+y,60+x,20+y);

    /*Dibujamos el escudo de la bandera*/
    setcolor(BROWN);
    circle(30+x,15+y,5);

    /*Sumamos x , y a las coordenas iniciales del triangulo*/
    for(i = 0; i < 8; i++)
        Triangulo[i] += i%2 == 0 ? x : y;

    /*Dibujamos el triangulo*/
    setfillstyle(1,BLUE);
    fillpoly(4,Triangulo);
}

/* Funcion que dibuja la bandera de Estados Unidos */
void USAFlag(int x, int y){

    int i = 0;
    
    /*Franjas de la bandera*/
    setfillstyle(1,WHITE);
    bar(0+x,0+y,60+x,30+y);

    setfillstyle(1,RED);
    for(i = 0; i < 5; i++)
        bar(0+x,0+y+(i*6.5),60+x,3+y+(i != 4 ? i*6.5 : i * 6.8));

    setfillstyle(1,BLUE);
    bar(0+x,0+y,27+x,17+y);

    /*Dibujamos las estrellas de la bandera*/
    for(i = 0; i < 250; i+= 2)
        putpixel(rand()%27+x,rand()%17+y,WHITE);
}

/* Funcion que dibuja la bandera de Espania */
void SpainFlag(int x, int y){

    /*Franjas de la bandera*/
    setfillstyle(1,YELLOW);
    bar(0+x,8+y,60+x,22+y);

    setfillstyle(1,RED);
    bar(0+x,0+y,60+x,8+y);
    bar(0+x,22+y,60+x,30+y);

    /*Dibujamos el escudo de la bandera*/
    setfillstyle(1,BLUE);
    bar(16+x,11+y,24+x,13+y);
    bar(13+x,13+y,27+x,15+y);
    bar(16+x,15+y,24+x,17+y);
}

void draw_flag(int flag, int x, int y)
{
    switch (flag)
    {
        case Brazil:
            BrazilFlag(x,y);
            break;
        case Spain:
            SpainFlag(x,y);
            break;
        case Argentina:
            ArgentinaFlag(x,y);
            break;
        case USA:
            USAFlag(x,y);
            break;
        case Nicaragua:
        default:
            NicaraguaFlag(x,y);
            break;
    }
}
#endif