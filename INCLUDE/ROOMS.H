#ifndef ROOMS_H
#define ROOMS_H 1
#ifndef __DOS_DEF_
#include <dos.h>
#endif
#ifndef __GRAPHX_DEF_
#include <GRAPHICS.H>
#endif

/* skin, hair, eyes, jacket, jacketsecond, jean, shoe */
typedef struct Skin
{
    int skinColor, hairColor, eyesColor, jacketColor, jacketColorSecond, jeanColor, shoeColor;
} Skin;

typedef struct design_room
{
    int ceiling, walls, floor, table, computer, mattress;
    bool hasComputer;
} Room;

void RigobertoLopezPerez(int isDawn)
{
    /*------------------ Cielo --------------------------*/
    int sky[46] = {0, 118, 15, 99, 40, 85, 91, 95, 91, 114, 111, 117, 207, 73, 229, 63, 239, 65, 269, 116, 270, 294, 378, 294, 376, 115, 380, 63, 388, 60, 545, 110, 562, 106, 562, 85, 618, 74, 640, 82, 640, 0, 0, 0, 0, 118};

    /*----------- Fachada del edificio -----------------*/

    int pillarLeft[16] = {207, 73, 229, 63, 239, 65, 269, 116, 269, 293, 243, 300, 204, 295, 207, 73};

    int pillarRight[16] = {380, 63, 388, 60, 427, 74, 430, 287, 547, 284, 546, 297, 381, 300, 380, 63};

    int wallLeft[20] = {207, 74, 204, 295, 109, 288, 11, 295, 11, 109, 40, 85, 91, 96, 91, 115, 111, 118, 207, 74};

    int wallRight[36] = {427, 74, 545, 111, 562, 107, 562, 86, 618, 74, 640, 97, 640, 272, 626, 275, 620, 280, 610, 284, 605, 281, 595, 287, 584, 291, 561, 292, 546, 297, 547, 284, 430, 287, 427, 74};

    int sideLeft[14] = {40, 85, 15, 99, 0, 118, 0, 303, 11, 295, 11, 109, 40, 85};

    int sideRight[8] = {640, 97, 640, 83, 618, 74, 640, 97};

    int gardenCentral[24] = {302, 311, 285, 315, 277, 324, 277, 330, 287, 333, 381, 333, 403, 329, 407, 322, 399, 316, 381, 313, 319, 311, 302, 311};

    int gardenLeft[20] = {0, 303, 11, 295, 109, 288, 204, 295, 243, 300, 263, 309, 152, 338, 106, 357, 0, 357, 0, 303};

    int gardenRight[30] = {448, 312, 490, 310, 544, 298, 561, 292, 584, 291, 595, 287, 605, 281, 610, 284, 620, 280, 626, 275, 640, 272, 640, 352, 605, 346, 562, 346, 448, 312};

    int floor[34] = {0, 357, 106, 357, 152, 338, 263, 309, 243, 300, 269, 293, 377, 293, 381, 300, 544, 298, 490, 310, 448, 312, 562, 346, 605, 346, 640, 352, 640, 480, 0, 480, 0, 357};

    /*------ Detalles de la parte derecha ---------------*/

    int stripWallRight[22] = {640, 273, 637, 273, 632, 113, 602, 119, 607, 282, 606, 282, 598, 286, 592, 100, 633, 90, 640, 97, 640, 273};

    int stripBlueRight2[10] = {438, 244, 438, 253, 546, 257, 546, 249, 438, 244};

    int stripBlueRight3[10] = {437, 201, 437, 209, 545, 221, 545, 214, 437, 201};

    int stripBlueRight4[10] = {545, 186, 545, 178, 436, 158, 436, 166, 545, 186};

    int stripBlueRight5[10] = {436, 116, 436, 124, 544, 151, 544, 143, 436, 116};

    int stripGrayRight1[10] = {547, 270, 546, 263, 429, 260, 430, 269, 547, 270};

    int stripGrayRight2[10] = {429, 225, 429, 216, 546, 227, 546, 235, 429, 225};

    int stripGrayRight3[10] = {428, 173, 428, 182, 545, 200, 545, 192, 428, 173};

    int stripGrayRight4[10] = {545, 164, 545, 157, 427, 130, 426, 138, 545, 164};

    int stripGrayRight5[10] = {427, 87, 545, 122, 545, 129, 427, 96, 427, 87};

    int windowRight1[10] = {439, 286, 547, 284, 547, 270, 439, 268, 439, 286};

    int windowRight2[10] = {438, 244, 546, 249, 546, 235, 438, 227, 438, 244};

    int windowRight3[10] = {437, 183, 545, 200, 545, 214, 437, 201, 437, 183};

    int windowRight4[10] = {436, 141, 436, 158, 545, 178, 545, 164, 436, 141};

    int windowRight5[10] = {544, 143, 544, 129, 436, 99, 436, 116, 544, 143};

    int windowSideRight5[10] = {555, 128, 556, 151, 574, 149, 573, 124, 555, 128};

    int windowSideRight4[10] = {556, 158, 574, 155, 575, 184, 557, 186, 556, 158};

    int windowSideRight3[10] = {557, 193, 558, 222, 576, 221, 576, 191, 557, 193};

    int windowSideRight2[10] = {558, 229, 559, 249, 578, 248, 577, 228, 558, 229};

    int windowSideRight1[12] = {578, 271, 578, 291, 561, 292, 559, 293, 559, 271, 578, 271};

    /*---------------- Detalles de la parte izquierda ---------------------------------*/

    int stripGrayLeft[50] = {192, 80, 193, 95, 111, 129, 111, 136, 193, 103, 193, 135, 111, 162, 111, 169, 193, 144, 193, 177, 111, 196, 111, 202, 193, 186, 193, 219, 111, 229, 111, 236, 193, 228, 193, 261, 111, 262, 111, 269, 193, 269, 193, 294, 205, 296, 207, 74, 192, 80};

    int stripBlueLeft1[10] = {193, 280, 111, 279, 111, 289, 193, 294, 193, 289};

    int stripBlueLeft2[10] = {193, 253, 111, 257, 111, 250, 193, 245, 193, 253};

    int stripBlueLeft3[10] = {193, 210, 111, 224, 111, 217, 193, 203, 193, 210};

    int stripBlueLeft4[10] = {193, 168, 193, 160, 111, 182, 111, 189, 193, 168};

    int stripBlueLeft5[10] = {193, 127, 193, 119, 111, 149, 111, 156, 193, 127};

    int windowLeft1[10] = {193, 280, 111, 279, 111, 269, 193, 269, 193, 280};

    int windowLeft2[10] = {193, 245, 111, 250, 111, 236, 193, 228, 193, 245};

    int windowLeft3[10] = {193, 203, 111, 217, 111, 202, 193, 186, 193, 203};

    int windowLeft4[10] = {193, 160, 193, 144, 111, 169, 111, 182, 193, 160};

    int windowLeft5[10] = {193, 119, 193, 103, 111, 136, 111, 149, 193, 119};

    int stripWallLeft[20] = {11, 295, 11, 109, 21, 102, 63, 109, 61, 292, 50, 292, 53, 127, 23, 123, 21, 294, 11, 295};

    int windowSideLeft5[10] = {82, 131, 82, 155, 99, 157, 99, 134, 82, 131};

    int windowSideLeft4[10] = {99, 163, 99, 190, 81, 190, 82, 161, 99, 163};

    int windowSideLeft3[10] = {82, 194, 82, 219, 99, 218, 99, 194, 82, 194};

    int windowSideLeft2[10] = {99, 228, 82, 228, 82, 254, 99, 253, 99, 228};

    int windowSideLeft1[10] = {99, 289, 99, 265, 82, 266, 82, 290, 99, 289};

    /*--------------- Detalles del centro  ------------------------*/
    int platform1[14] = {270, 262, 290, 260, 363, 260, 378, 259, 378, 271, 270, 271, 270, 262};

    int platform2[20] = {270, 238, 289, 239, 324, 235, 362, 240, 378, 239, 377, 226, 323, 226, 290, 227, 270, 226, 270, 238};

    int platform3[20] = {270, 203, 290, 205, 323, 202, 377, 205, 377, 191, 360, 193, 323, 191, 290, 193, 270, 193, 270, 203};

    int platform4[22] = {270, 169, 291, 172, 323, 168, 361, 170, 377, 167, 377, 156, 359, 160, 324, 158, 288, 161, 270, 158, 270, 169};

    int platform5[22] = {270, 135, 269, 116, 289, 121, 322, 115, 359, 120, 376, 115, 377, 134, 360, 138, 323, 134, 288, 138, 270, 135};

    int wallCenter[10] = {376, 115, 377, 295, 381, 300, 380, 63, 376, 115};

    /*------------- Balcones de la parte derecha -------------------*/
    int balconyRight5[16] = {381, 80, 381, 81, 389, 79, 416, 86, 412, 109, 389, 103, 381, 105, 381, 89};

    int balconyRight4[14] = {381, 124, 390, 122, 412, 129, 412, 153, 390, 149, 381, 151, 381, 124};

    int balconyRight3[16] = {382, 174, 382, 195, 391, 195, 412, 197, 412, 173, 390, 169, 383, 170, 382, 174};

    int balconyRight2[12] = {383, 215, 390, 214, 412, 217, 412, 241, 383, 241, 383, 215};

    int balconyRight1[10] = {384, 300, 384, 262, 412, 262, 412, 300, 384, 300};

    /*------------ Balcones de la parte izquierda -----------------*/
    int balconyLeft5[18] = {212, 113, 229, 105, 239, 108, 242, 111, 242, 90, 239, 83, 229, 80, 212, 89, 212, 113};

    int balconyLeft4[18] = {212, 131, 229, 124, 239, 126, 242, 131, 242, 154, 239, 152, 229, 150, 212, 156, 212, 131};

    int balconyLeft3[18] = {211, 175, 211, 197, 227, 195, 239, 195, 242, 199, 242, 174, 239, 172, 229, 169, 211, 175};

    int balconyLeft2[16] = {242, 242, 242, 219, 239, 214, 229, 214, 211, 218, 211, 242, 239, 241, 242, 242};

    int balconyLeft1[14] = {243, 400, 211, 296, 211, 262, 226, 261, 239, 261, 242, 262, 243, 400};

    /*------------- Escaleras -----------------------------------------*/

    int stairs1[] = {362, 293, 343, 277, 329, 277, 322, 271, 309, 271, 326, 284, 340, 284, 352, 293, 362, 293};

    int stairs2[] = {360, 260, 337, 242, 320, 242, 311, 236, 304, 237, 316, 245, 330, 245, 350, 260, 360, 260};

    int stairs3[] = {303, 202, 316, 214, 332, 214, 346, 226, 356, 226, 337, 210, 320, 209, 311, 202, 303, 202};

    int stairs4[] = {354, 192, 344, 192, 331, 181, 314, 181, 303, 170, 310, 169, 317, 176, 334, 176, 354, 192};

    /*---------------Ventanas de los balcones -------------------------------*/

    int windowBalconyLeft1[10] = {220, 286, 235, 286, 235, 270, 220, 270, 220, 286};

    int windowBalconyLeft2[10] = {220, 241, 235, 242, 235, 226, 220, 226, 220, 241};

    int windowBalconyLeft3[10] = {220, 182, 219, 195, 235, 195, 235, 183, 220, 182};

    int windowBalconyLeft4[12] = {235, 151, 235, 139, 220, 139, 219, 153, 229, 150, 235, 151};

    int windowBalconyLeft5[12] = {219, 109, 220, 96, 235, 96, 235, 107, 229, 106, 219, 109};

    int windowBalconyRight5[10] = {389, 103, 405, 107, 405, 93, 389, 94, 389, 103};

    int windowBalconyRight4[10] = {389, 148, 389, 137, 405, 137, 405, 151, 389, 148};

    int windowBalconyRight3[10] = {405, 196, 406, 181, 390, 181, 390, 194, 405, 196};

    int windowBalconyRight2[10] = {391, 225, 406, 225, 406, 241, 391, 241, 391, 225};

    int windowBalconyRight1[10] = {391, 269, 391, 287, 408, 287, 408, 269, 391, 269};

    int i, j;

    /* Se establece el color del contorno */
    setcolor(DARKGRAY);

    /* Si la booleana amanecer (dawn) es cierta se pinta de negro el cielo la primera vez 
       Si es incierta entonces directamente el color mas claro */
    if (isDawn)
        setfillstyle(1, BLACK);
    else
        setfillstyle(1, LIGHTCYAN);

    fillpoly(23, sky);

    /* Se pinta el sol */
    setfillstyle(1, YELLOW);
    fillellipse(322, 0, 60, 60);

    /* Se pintan los pilares*/
    setfillstyle(7, BLUE);
    fillpoly(8, pillarLeft);
    fillpoly(8, pillarRight);

    /* Se pintan la fachada */
    setfillstyle(1, DARKGRAY);
    fillpoly(7, sideLeft);
    fillpoly(4, sideRight);

    /* Se pintan los pisos y balcones */
    setfillstyle(1, LIGHTGRAY);
    fillpoly(9, wallCenter);
    fillpoly(7, platform1);
    fillpoly(10, platform2);
    fillpoly(10, platform3);
    fillpoly(11, platform4);
    fillpoly(11, platform5);
    fillpoly(8, balconyRight5);
    fillpoly(7, balconyRight4);
    fillpoly(8, balconyRight3);
    fillpoly(6, balconyRight2);
    fillpoly(5, balconyRight1);
    fillpoly(9, balconyLeft5);
    fillpoly(9, balconyLeft4);
    fillpoly(9, balconyLeft3);
    fillpoly(8, balconyLeft2);
    fillpoly(7, balconyLeft1);

    /* Se pintan las paredes */
    setfillstyle(1, LIGHTGRAY);
    fillpoly(10, wallLeft);
    fillpoly(18, wallRight);

    /* Se pinta el suelo*/
    setfillstyle(9, DARKGRAY);
    fillpoly(17, floor);

    /* Se pinta los jardines */
    setfillstyle(1, GREEN);
    fillpoly(12, gardenCentral);
    fillpoly(10, gardenLeft);
    fillpoly(15, gardenRight);

    /* Se pinta los detalles del edificio*/
    setfillstyle(7, BLUE);
    fillpoly(5, stripBlueLeft1);
    fillpoly(5, stripBlueLeft2);
    fillpoly(5, stripBlueLeft3);
    fillpoly(5, stripBlueLeft4);
    fillpoly(5, stripBlueLeft5);
    fillpoly(5, stripBlueRight2);
    fillpoly(5, stripBlueRight3);
    fillpoly(5, stripBlueRight4);
    fillpoly(5, stripBlueRight5);

    setfillstyle(7, DARKGRAY);
    fillpoly(5, stripGrayRight1);
    fillpoly(5, stripGrayRight2);
    fillpoly(5, stripGrayRight3);
    fillpoly(5, stripGrayRight4);
    fillpoly(5, stripGrayRight5);
    fillpoly(25, stripGrayLeft);
    fillpoly(10, stripWallLeft);
    fillpoly(11, stripWallRight);

    /* Se dibujan las escaleras */
    setfillstyle(1, DARKGRAY);
    fillpoly(9, stairs1);
    fillpoly(9, stairs2);
    fillpoly(9, stairs3);
    fillpoly(9, stairs4);

    /* Se pintan las ventanas segun si se reproducira la animacion de amanecer
     Si la booleana es cierta se pintaran de amarillo, simulando luces encendidas
      sino de negro  simulando luces apagadas*/
    if (isDawn)
        setfillstyle(1, YELLOW);
    else
        setfillstyle(1, BLACK);
    fillpoly(5, windowLeft1);
    fillpoly(5, windowLeft2);
    fillpoly(5, windowLeft3);
    fillpoly(5, windowLeft4);
    fillpoly(5, windowLeft5);
    fillpoly(5, windowRight1);
    fillpoly(5, windowRight2);
    fillpoly(5, windowRight3);
    fillpoly(5, windowRight4);
    fillpoly(5, windowRight5);
    fillpoly(5, windowSideLeft1);
    fillpoly(5, windowSideLeft2);
    fillpoly(5, windowSideLeft3);
    fillpoly(5, windowSideLeft4);
    fillpoly(5, windowSideLeft5);
    fillpoly(5, windowSideRight1);
    fillpoly(5, windowSideRight2);
    fillpoly(5, windowSideRight3);
    fillpoly(5, windowSideRight4);
    fillpoly(5, windowSideRight5);
    fillpoly(5, windowBalconyLeft1);
    fillpoly(5, windowBalconyLeft2);
    fillpoly(5, windowBalconyLeft3);
    fillpoly(6, windowBalconyLeft4);
    fillpoly(6, windowBalconyLeft5);
    fillpoly(5, windowBalconyRight1);
    fillpoly(5, windowBalconyRight2);
    fillpoly(5, windowBalconyRight3);
    fillpoly(5, windowBalconyRight4);
    fillpoly(5, windowBalconyRight5);

    /*Si la booleana isDawn es cierta se procede a animar el sol*/
    if (isDawn)
    {
        j = 0;
        for (i = 0; i < 300; i += 10)
        {
            /* Se pinta el color de las ventanas segun la elevacion del sol*/
            if (i == 130)
            {
                setfillstyle(1, BLACK);
                fillpoly(5, windowLeft1);
                fillpoly(5, windowLeft2);
                fillpoly(5, windowLeft3);
                fillpoly(5, windowLeft4);
                fillpoly(5, windowLeft5);
                fillpoly(5, windowRight1);
                fillpoly(5, windowRight2);
                fillpoly(5, windowRight3);
                fillpoly(5, windowRight4);
                fillpoly(5, windowRight5);
                fillpoly(5, windowSideLeft1);
                fillpoly(5, windowSideLeft2);
                fillpoly(5, windowSideLeft3);
                fillpoly(5, windowSideLeft4);
                fillpoly(5, windowSideLeft5);
                fillpoly(5, windowSideRight1);
                fillpoly(5, windowSideRight2);
                fillpoly(5, windowSideRight3);
                fillpoly(5, windowSideRight4);
                fillpoly(5, windowSideRight5);
                fillpoly(5, windowBalconyLeft1);
                fillpoly(5, windowBalconyLeft2);
                fillpoly(5, windowBalconyLeft3);
                fillpoly(6, windowBalconyLeft4);
                fillpoly(6, windowBalconyLeft5);
                fillpoly(5, windowBalconyRight1);
                fillpoly(5, windowBalconyRight2);
                fillpoly(5, windowBalconyRight3);
                fillpoly(5, windowBalconyRight4);
                fillpoly(5, windowBalconyRight5);
            }

            /* Se pinta el color del cielo segun el parametro de i */
            if (i < 60)
                setfillstyle(1, BLACK);
            else if (i < 130)
                setfillstyle(1, BLUE);
            else if (i < 230)
                setfillstyle(1, LIGHTBLUE);
            else
                setfillstyle(1, LIGHTCYAN);

            fillpoly(23, sky);

            /* Se pinta el sol con tamano relativo a j y altura relativa a i*/
            setfillstyle(1, YELLOW);
            fillellipse(322, 288 - i, 0 + j, 0 + j);

            /*  Se pintan nuevamente las plataformas que son afectadas por el paso del sol*/
            setfillstyle(1, LIGHTGRAY);
            fillpoly(7, platform1);
            fillpoly(10, platform2);
            fillpoly(10, platform3);
            fillpoly(11, platform4);
            fillpoly(11, platform5);
            setfillstyle(1, DARKGRAY);
            fillpoly(9, stairs1);
            fillpoly(9, stairs2);
            fillpoly(9, stairs3);
            fillpoly(9, stairs4);
            j += 2;
            delay(300);
        }
    }
}

void BedRoom(Room *design)
{
    #pragma region Coordenadas
    /* Mediante arreglos se toman los muebles y medida del cuarto */
    int ceiling[12] = {0, 4, 165, 82, 461, 82, 566, 0, 0, 0, 0, 4};

    int wallLeft[10] = {0, 4, 0, 418, 160, 290, 165, 82, 0, 4};

    int wallCenter[10] = {160, 290, 165, 82, 461, 82, 461, 299, 160, 290};

    int wallRight[12] = {566, 0, 461, 82, 461, 299, 640, 400, 640, 0, 566, 0};

    int skirtingBoard[18] = {640, 400, 461, 299, 160, 290, 0, 418, 0, 429, 160, 301, 461, 311, 640, 412, 640, 400};

    int floor[14] = {0, 429, 160, 301, 461, 311, 640, 412, 640, 480, 0, 480, 0, 429};

    int table[34] = {613, 248, 461, 211, 386, 211, 386, 216, 389, 217, 389, 310, 422, 335, 490, 335, 490, 398, 503, 398, 503, 259, 594, 256, 594, 393, 604, 393, 604, 256, 614, 256, 613, 248};

    int tableDetails[40] = {613, 248, 498, 248, 386, 211, 386, 216, 496, 259, 498, 248, 496, 259, 594, 256, 594, 393, 604, 393, 604, 256, 594, 256, 614, 256, 503, 259, 503, 398, 490, 398, 490, 256, 490, 335, 422, 335, 425, 230};

    int bed[22] = {159, 200, 260, 197, 260, 307, 168, 413, 22, 413, 22, 344, 167, 346, 254, 264, 255, 248, 159, 248, 159, 200};

    int mattress[14] = {22, 344, 167, 346, 254, 264, 255, 248, 159, 248, 22, 321, 22, 344};

    int mattressDetails[10] = {22, 321, 167, 326, 167, 346, 167, 326, 255, 248};

    int mattressDetails1[4] = {52, 305, 62, 308};

    int mattressDetails2[4] = {68, 296, 82, 300};

    int mattressDetails3[4] = {102, 278, 169, 275};

    int mattressDetails4[4] = {120, 268, 147, 269};

    int mattressDetails5[4] = {131, 262, 202, 264};

    int computer[18] = {500, 242, 539, 239, 561, 203, 557, 199, 517, 197, 502, 225, 468, 227, 464, 230, 500, 242};

    int computerDetails[12] = {468, 227, 499, 237, 500, 242, 499, 237, 536, 235, 557, 199};
    #pragma endregion
    
    /*Se escogen los oclores para pintar cada uno de los muebles*/
    setcolor(BLACK);
    setfillstyle(1, design->ceiling);
    fillpoly(6, ceiling);

    setfillstyle(1, design->walls);
    fillpoly(5, wallLeft);
    fillpoly(5, wallCenter);
    fillpoly(6, wallRight);

    setfillstyle(1, WHITE);
    fillpoly(9, skirtingBoard);

    setfillstyle(1, design->floor);
    fillpoly(7, floor);

    drawpoly(6, ceiling);
    drawpoly(5, wallLeft);
    drawpoly(5, wallCenter);
    drawpoly(6, wallRight);
    drawpoly(9, skirtingBoard);
    drawpoly(7, floor);

    setcolor(design->table==BLACK ? DARKGRAY : BLACK);
    setfillstyle(1, design->table);
    fillpoly(17, table);
    fillpoly(11, bed);

    setfillstyle(1, design->mattress);
    fillpoly(7, mattress);

    
    drawpoly(7, mattress);
    drawpoly(17, table);
    drawpoly(20, tableDetails);
    drawpoly(11, bed);

    drawpoly(5, mattressDetails);
    drawpoly(2, mattressDetails1);
    drawpoly(2, mattressDetails2);
    drawpoly(2, mattressDetails3);
    drawpoly(2, mattressDetails4);
    drawpoly(2, mattressDetails5);

    if(design->hasComputer)
    {
        setfillstyle(1, design->computer);
        fillpoly(9, computer);
        drawpoly(6, computerDetails);
        drawpoly(9, computer);
        line(502, 225, 536, 235);
    }
}

void Avatar(int x, int y, Skin *skin)
{
    /*  Mediante arreglos se toman todos los puntos del avatar */
    int hair[80] = {38, 35, 38, 22, 41, 17, 47, 29, 46, 25, 52, 30, 51, 24, 52, 13, 57, 22, 59, 26, 59, 30, 60, 26, 60, 27, 59, 26, 62, 29, 61, 26, 64, 30, 65, 32, 66, 26, 66, 23, 68, 25, 67, 17, 71, 20, 68, 10, 69, 12, 63, 4, 58, 1, 52, 0, 46, 0, 36, 1, 40, 3, 35, 6, 32, 10, 27, 13, 33, 12, 27, 22, 32, 17, 32, 32, 35, 26, 38, 35};

    int face[56] = {34, 28, 35, 26, 38, 35, 38, 22, 41, 17, 47, 29, 46, 25, 52, 30, 51, 24, 52, 13, 57, 22, 59, 26, 59, 30, 60, 26, 60, 27, 59, 26, 62, 29, 61, 26, 64, 30, 62, 35, 61, 35, 59, 39, 50, 45, 43, 41, 40, 38, 38, 35, 37, 35, 34, 28};

    int faceDetails[18] = {62, 35, 61, 35, 59, 39, 50, 45, 43, 41, 40, 38, 38, 35, 37, 35, 34, 28};

    int eyebrowLeft[4] = {38, 22, 44, 22};

    int eyebrowRight[4] = {53, 23, 57, 22};

    int eyeLeft[20] = {44, 30, 46, 28, 47, 29, 45, 26, 43, 25, 40, 26, 39, 27, 40, 29, 42, 30, 44, 30};

    int eyeRight[18] = {56, 25, 58, 25, 59, 26, 59, 28, 58, 30, 55, 30, 54, 28, 54, 27, 56, 25};

    int pupilLeft[16] = {44, 25, 43, 25, 40, 24, 41, 28, 43, 30, 44, 30, 44, 29, 44, 25};

    int pupilRight[16] = {55, 26, 55, 29, 56, 30, 57, 30, 58, 28, 58, 25, 56, 25, 55, 26};

    int neck[20] = {44, 41, 44, 49, 42, 53, 48, 56, 53, 56, 59, 53, 56, 50, 56, 41, 50, 45, 44, 41};

    int jacket[102] = {68, 52, 75, 54, 80, 62, 83, 84, 84, 87, 84, 95, 87, 99, 87, 111, 90, 129, 90, 135, 91, 142, 89, 144, 84, 144, 83, 143, 81, 135, 77, 109, 75, 105, 73, 81, 71, 91, 71, 106, 75, 123, 75, 138, 74, 139, 55, 140, 47, 140, 26, 138, 24, 137, 24, 121, 29, 108, 30, 100, 28, 79, 25, 105, 23, 108, 23, 113, 25, 115, 22, 116, 20, 119, 19, 122, 20, 125, 23, 126, 23, 128, 20, 128, 15, 120, 13, 110, 13, 101, 16, 85, 19, 75, 23, 58, 26, 56, 31, 55, 68, 52};

    int jacketNeck[32] = {33, 57, 31, 52, 33, 47, 37, 43, 42, 40, 61, 43, 68, 49, 68, 55, 61, 58, 59, 61, 50, 92, 43, 64, 42, 60, 39, 58, 36, 57, 33, 57};

    int shirt[16] = {59, 53, 56, 68, 50, 92, 43, 64, 42, 53, 48, 56, 53, 56, 59, 53};

    int handLeft[16] = {26, 115, 25, 115, 22, 116, 20, 119, 19, 122, 20, 125, 23, 126, 24, 126};

    int handRight[30] = {91, 142, 92, 145, 92, 158, 87, 159, 82, 159, 80, 157, 80, 153, 81, 150, 82, 148, 84, 147, 84, 146, 83, 143, 84, 144, 89, 144, 91, 142};

    int handRightDetails[10] = {82, 159, 85, 155, 87, 155, 85, 155, 86, 152};

    int jean[82] = {24, 137, 25, 152, 27, 162, 29, 176, 30, 190, 30, 223, 32, 235, 33, 240, 34, 253, 34, 255, 31, 256, 31, 263, 43, 263, 46, 261, 46, 254, 44, 252, 45, 215, 45, 189, 46, 166, 47, 158, 50, 143, 60, 188, 60, 203, 69, 245, 69, 252, 67, 254, 69, 259, 69, 262, 75, 264, 78, 264, 81, 263, 81, 259, 83, 257, 80, 254, 75, 214, 74, 194, 74, 149, 73, 139, 55, 140, 47, 140, 24, 137};

    int shoeLeft[30] = {31, 262, 26, 268, 19, 272, 18, 275, 18, 279, 22, 282, 31, 280, 37, 275, 40, 275, 47, 272, 47, 264, 45, 261, 43, 263, 31, 263, 31, 262};

    int shoeRight[28] = {69, 262, 69, 273, 72, 275, 74, 280, 77, 283, 81, 284, 87, 284, 91, 281, 91, 276, 85, 270, 80, 263, 78, 264, 75, 264, 69, 262};

    int shoeLeftDetails[12] = {40, 263, 32, 269, 25, 273, 21, 273, 20, 272, 20, 271};

    int shoeLeftDetails2[18] = {18, 277, 20, 278, 24, 279, 27, 279, 30, 278, 37, 273, 39, 272, 40, 272, 47, 269};

    int shoeRightDetails[14] = {72, 263, 77, 274, 79, 276, 83, 277, 87, 277, 88, 276, 89, 275};

    int shoeRightDetails2[14] = {69, 269, 72, 273, 73, 277, 76, 280, 80, 282, 87, 282, 91, 279};

    int jacketDetails1[26] = {23, 57, 26, 78, 30, 75, 37, 81, 43, 66, 42, 60, 39, 58, 36, 57, 33, 57, 32, 54, 31, 55, 26, 55, 23, 57};

    int jacketDetails2[30] = {56, 69, 60, 67, 61, 84, 64, 82, 64, 91, 72, 81, 74, 71, 77, 57, 75, 54, 68, 53, 68, 55, 65, 56, 61, 58, 59, 61, 56, 69};

    int jacketDetails3[6] = {40, 73, 47, 95, 47, 140};

    int jacketDetails4[4] = {50, 92, 50, 140};

    int jacketDetails5[6] = {60, 74, 54, 98, 53, 140};

    int jacketDetails6[22] = {25, 70, 30, 69, 34, 70, 34, 104, 32, 110, 28, 109, 32, 110, 34, 111, 36, 113, 38, 117, 39, 123};

    int jacketDetails7[14] = {60, 70, 67, 70, 74, 71, 67, 70, 67, 110, 71, 118, 75, 124};

    int jeanDetails[14] = {61, 147, 50, 141, 71, 145, 50, 141, 33, 147, 50, 141, 41, 151};

    int mouth[4] = {52, 39, 46, 39};

    int i;

    /*Dichos ciclos suman la cantidad en x & en y a cada una de las coordenadas de todas las matrices para dibujarlo 
     en distintas partes de la pantalla */
    setlinestyle(0, 0, NORM_WIDTH);
    for (i = 0; i < 102; i++)
    {
        if (i < 80)
            hair[i] += i % 2 == 0 ? x : y;
        if (i < 56)
            face[i] += i % 2 == 0 ? x : y;
        if (i < 18)
        {
            eyeRight[i] += i % 2 == 0 ? x : y;
            faceDetails[i] += i % 2 == 0 ? x : y;
        }
        if (i < 4)
        {
            eyebrowLeft[i] += i % 2 == 0 ? x : y;
            eyebrowRight[i] += i % 2 == 0 ? x : y;
            jacketDetails4[i] += i % 2 == 0 ? x : y;
            mouth[i] += i % 2 == 0 ? x : y;
        }
        if (i < 20)
        {
            eyeLeft[i] += i % 2 == 0 ? x : y;
            neck[i] += i % 2 == 0 ? x : y;
        }
        if (i < 16)
        {
            pupilLeft[i] += i % 2 == 0 ? x : y;
            pupilRight[i] += i % 2 == 0 ? x : y;
            shirt[i] += i % 2 == 0 ? x : y;
            handLeft[i] += i % 2 == 0 ? x : y;
        }
        if (i < 32)
        {
            jacketNeck[i] += i % 2 == 0 ? x : y;
        }
        if (i < 30)
        {
            handRight[i] += i % 2 == 0 ? x : y;
            shoeLeft[i] += i % 2 == 0 ? x : y;
            jacketDetails2[i] += i % 2 == 0 ? x : y;
        }
        if (i < 10)
            handRightDetails[i] += i % 2 == 0 ? x : y;

        if (i < 82)
            jean[i] += i % 2 == 0 ? x : y;

        if (i < 28)
            shoeRight[i] += i % 2 == 0 ? x : y;

        if (i < 12)
            shoeLeftDetails[i] += i % 2 == 0 ? x : y;
        if (i < 18)
            shoeLeftDetails2[i] += i % 2 == 0 ? x : y;

        if (i < 14)
        {
            shoeRightDetails[i] += i % 2 == 0 ? x : y;
            shoeRightDetails2[i] += i % 2 == 0 ? x : y;
        }
        if (i < 26)
            jacketDetails1[i] += i % 2 == 0 ? x : y;
        if (i < 6)
        {
            jacketDetails3[i] += i % 2 == 0 ? x : y;
            jacketDetails5[i] += i % 2 == 0 ? x : y;
        }
        if (i < 22)
            jacketDetails6[i] += i % 2 == 0 ? x : y;
        if (i < 14)
        {
            jacketDetails7[i] += i % 2 == 0 ? x : y;
            jeanDetails[i] += i % 2 == 0 ? x : y;
        }
        jacket[i] += i % 2 == 0 ? x : y;
    }
    /* Se escoge el color de cada parte y se pinta*/

    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, skin->jeanColor);
    fillpoly(41, jean);
    setfillstyle(SOLID_FILL, skin->jacketColor);
    fillpoly(51, jacket);
    fillpoly(16, jacketNeck);
    setfillstyle(SOLID_FILL, skin->hairColor);
    fillpoly(40, hair);
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(9, faceDetails);
    setfillstyle(SOLID_FILL, skin->shoeColor);
    fillpoly(15, shoeLeft);
    fillpoly(14, shoeRight);

    setfillstyle(1, skin->skinColor);
    fillpoly(28, face);
    fillpoly(10, neck);
    fillpoly(8, handLeft);
    fillpoly(15, handRight);
    fillpoly(5, handRightDetails);

    setfillstyle(1, LIGHTGRAY);
    fillpoly(2, eyebrowLeft);
    fillpoly(2, eyebrowRight);

    drawpoly(6, shoeLeftDetails);
    drawpoly(9, shoeLeftDetails2);
    drawpoly(7, shoeRightDetails);
    drawpoly(7, shoeRightDetails2);

    drawpoly(3, jacketDetails3);
    drawpoly(2, jacketDetails4);
    drawpoly(3, jacketDetails5);
    drawpoly(11, jacketDetails6);
    drawpoly(7, jacketDetails7);

    drawpoly(7, jeanDetails);

    setfillstyle(1, BLACK);
    fillpoly(8, shirt);

    setfillstyle(1, skin->jacketColorSecond);
    fillpoly(13, jacketDetails1);
    fillpoly(15, jacketDetails2);

    setfillstyle(1, WHITE);
    fillpoly(10, eyeLeft);
    fillpoly(9, eyeRight);

    setfillstyle(1, skin->eyesColor);
    fillpoly(8, pupilLeft);
    fillpoly(8, pupilRight);

    setcolor(RED);
    drawpoly(2, mouth);
}

void ShowMessageDialog(int y1, int y2)
{
    /* Esta funcion pinta un recuadro blanco en la parte inferior de la pantalla para ofrecer un texto agradable al usuario */

    setfillstyle(SOLID_FILL, WHITE);
    setcolor(BLACK);

    setlinestyle(0, 0, THICK_WIDTH);
    bar(14,y1,624,y2);
    rectangle(14,y1,624,y2);
    setlinestyle(0, 0, NORM_WIDTH);
}

#endif