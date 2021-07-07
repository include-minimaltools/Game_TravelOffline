/* ver alfa 3 */
#ifndef MUNDI_H
#define MUNDI_H 1
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
#ifndef MOUSE_H
    #include <MOUSE.H>
#endif
#ifndef __STDIO_DEF_
#include <stdio.h>
#endif

typedef struct airline
{
    int position[2], color, init, period, orientation;
    bool fillairplane;
    void *raster;
} airline;

enum routes
{
    US_ES,
    ES_US,
    ES_BR,
    BR_ES,
    US_BR,
    BR_US,
    US_NIC,
    NIC_US,
    NIC_BR,
    BR_NIC,
    NIC_AR,
    AR_NIC,
    AR_BR,
    BR_AR
};

void set_airline(airline *airline, int route);
void animation_mundi(int init, int end);
void airplane(int x, int y, int orientation);
void mundi(void);
bool next_pixel(int i);

int mundi_xpos = 83;
airline tours[2];

void *airplaneRaster;

enum airplane_orientation
{
    UP,
    LEFT,
    DOWN,
    RIGHT
};

void init_mundi(void)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        tours[i].period = 0;
        tours[i].raster = malloc(imagesize(0, 0, 25, 25));
    }
}

void set_airline(airline* tour, int route)
{
    int Paths[7][7] = {/* Es-usa */ {257, 124, 30, 145, 151, 83, LIGHTBLUE}, /* Es-Br */ {723, 246, 142, 183, 428, 268, LIGHTCYAN}, /* US-BR */ {175, 269, 0, 113, 121, 205, LIGHTGRAY}, /* US-NIC */ {98, 130, 300, 60, 62, 61, LIGHTGREEN}, /* NIC-BR */ {194, 292, 11, 124, 103, 135, LIGHTMAGENTA}, /* NIC-AR */ {140, 338, 350, 95, 90, 157, LIGHTRED}, /* AR-BR */ {283, 404, 78, 160, 57, 141, YELLOW}};

    int routes[14][4] =
    {
        /* US_ES */ {138, 73, RIGHT, LIGHTBLUE},
        /* ES_US */ {387, 82, LEFT, LIGHTBLUE},
        /* ES_BR */ {385, 82, LEFT, LIGHTCYAN},
        /* BR_ES */ {295, 235, RIGHT, LIGHTCYAN},
        /* US_BR */ {138, 75, RIGHT, LIGHTGRAY},
        /* BR_US */ {296, 265, LEFT, LIGHTGRAY},
        /* US_NIC */ {131, 79, RIGHT, LIGHTGREEN},
        /* NIC_US */ {130, 183, RIGHT, LIGHTGREEN},
        /* NIC_BR */ {136, 180, RIGHT, LIGHTMAGENTA},
        /* BR_NIC */ {295, 265, LEFT, LIGHTMAGENTA},
        /* NIC_AR */ {134, 181, RIGHT, LIGHTRED},
        /* AR_NIC */ {229, 347, LEFT, LIGHTRED},
        /* AR_BR */ {230, 354, RIGHT, YELLOW},
        /* BR_AR */ {295, 267, LEFT, YELLOW}
    };

    int line = route - 1;

    tour->position[0] = routes[route][0] + mundi_xpos;
    tour->position[1] = routes[route][1];
    tour->orientation = routes[route][2];
    tour->color = routes[route][3];

    if(line % 2 == 0)
        line = route / 2;
    else
        line = (route+1) / 2;

    setcolor(Paths[line][6]);
    ellipse(Paths[line][0] + mundi_xpos, Paths[line][1], Paths[line][2], Paths[line][3], Paths[line][4], Paths[line][5]);
}

void animation_mundi(int init, int end)
{
    int i;
    bool recursive = false;

    for (i = init; i < end; i++)
        if (tours[i].period % 1 == 0 && tours[i].period > tours[i].init)
            tours[i].fillairplane = true;
        else
            tours[i].fillairplane = false;
    for (i = init; i < end; i++)
        if (tours[i].fillairplane)
            getimage(tours[i].position[0] - 12, tours[i].position[1] - 12, tours[i].position[0] + 13, tours[i].position[1] + 13, tours[i].raster);

    for (i = init; i < end; i++)
        if (tours[i].fillairplane)
            airplane(tours[i].position[0] - 12, tours[i].position[1] - 12, tours[i].orientation);

    delay(1500);

    for (i = init; i < end; i++)
        if (tours[i].fillairplane)
            putimage(tours[i].position[0] - 12, tours[i].position[1] - 12, tours[i].raster, COPY_PUT);

    for (i = init; i < end; i++)
        if (next_pixel(i))
            recursive = true;
    
    if (recursive && mclick()==0)
        animation_mundi(init, end);
}

bool next_pixel(int i)
{
    int j, k;
    
    for (j = tours[i].orientation == LEFT ? -1 : 1; tours[i].orientation == LEFT ? j <= 1 : j >= -1; j += tours[i].orientation == LEFT ? 1 : -1)
        for (k = -1; k <= 1; k++)
            if (getpixel(tours[i].position[0] + j, tours[i].position[1] + k) == tours[i].color)
            {
                putpixel(tours[i].position[0], tours[i].position[1], WHITE);
                if (j < 0)
                    tours[i].orientation = LEFT;
                else if (j > 0)
                    tours[i].orientation = RIGHT;
                else if (k > 0)
                    tours[i].orientation = DOWN;
                else if (k < 0)
                    tours[i].orientation = UP;

                tours[i].position[0] += j;
                tours[i].position[1] += k;
                tours[i].period++;
                return true;
            }

    return false;
}

void airplane(int x, int y, int orientation)
{
    int airplane[4][17][2] = {
        {{11, 1}, {12, 0}, {13, 0}, {14, 1}, {14, 8}, {25, 14}, {25, 16}, {14, 13}, {14, 21}, {17, 24}, {8, 24}, {11, 21}, {11, 13}, {0, 16}, {0, 14}, {11, 8}, {11, 1}} /* UP   */,
        {{0, 12}, {1, 11}, {8, 11}, {14, 0}, {16, 0}, {13, 11}, {21, 11}, {24, 8}, {24, 17}, {21, 14}, {13, 14}, {16, 25}, {14, 25}, {8, 14}, {1, 14}, {0, 13}, {0, 12}} /* LEFT */,
        {{12, 24}, {11, 23}, {11, 16}, {0, 10}, {0, 8}, {11, 11}, {11, 3}, {8, 0}, {17, 0}, {14, 3}, {14, 11}, {25, 8}, {25, 10}, {14, 16}, {14, 23}, {13, 24}, {12, 24}} /* DOWN */,
        {{24, 13}, {23, 14}, {16, 14}, {10, 25}, {8, 25}, {11, 14}, {3, 14}, {0, 17}, {0, 8}, {3, 11}, {11, 11}, {8, 0}, {10, 0}, {16, 11}, {23, 11}, {24, 12}, {24, 13}} /* RIGHT */};

    int turbine[4][2][4] = {
        {{17, 8, 19, 11}, {6, 8, 8, 11}} /* UP */,
        {{8, 6, 11, 8}, {8, 17, 11, 19}} /* LEFT */,
        {{6, 13, 8, 16}, {17, 13, 19, 16}} /* DOWN */,
        {{13, 6, 16, 8}, {13, 17, 16, 19}} /* RIGHT */};

    int i;

    for (i = 0; i < 17; i++)
    {
        airplane[orientation][i][0] += x;
        airplane[orientation][i][1] += y;
    }

    setfillstyle(SOLID_FILL, BLACK);
    setcolor(BLACK);
    fillpoly(17, *airplane[orientation]);
    for (i = 0; i < 2; i++)
        bar(turbine[orientation][i][0] + x, turbine[orientation][i][1] + y, turbine[orientation][i][2] + x, turbine[orientation][i][3] + y);
}

void mundi(void)
{
    int America[308][2] = {{113, 34}, {109, 40}, {97, 51}, {97, 57}, {95, 60}, {93, 59}, {71, 84}, {65, 99}, {66, 103}, {68, 106}, {65, 115}, {65, 119}, {67, 124}, {61, 126}, {67, 132}, {65, 137}, {67, 144}, {70, 144}, {70, 121}, {68, 116}, {71, 112}, {72, 115}, {71, 124}, {74, 126}, {73, 128}, {74, 131}, {73, 134}, {78, 143}, {78, 151}, {76, 156}, {77, 160}, {92, 170}, {97, 173}, {102, 173}, {106, 171}, {109, 172}, {111, 177}, {114, 179}, {127, 183}, {128, 182}, {130, 185}, {134, 190}, {133, 194}, {134, 197}, {137, 197}, {141, 199}, {141, 203}, {147, 203}, {152, 207}, {154, 207}, {154, 203}, {157, 201}, {160, 201}, {162, 203}, {160, 204}, {163, 210}, {164, 222}, {158, 227}, {157, 230}, {152, 236}, {151, 248}, {155, 248}, {155, 250}, {151, 253}, {150, 256}, {150, 261}, {153, 265}, {160, 273}, {162, 278}, {166, 284}, {171, 292}, {171, 296}, {177, 301}, {183, 304}, {189, 307}, {194, 311}, {196, 316}, {196, 324}, {195, 328}, {195, 344}, {194, 350}, {194, 354}, {194, 358}, {195, 363}, {195, 368}, {193, 377}, {193, 384}, {193, 388}, {192, 391}, {192, 395}, {193, 399}, {196, 400}, {196, 404}, {195, 407}, {193, 411}, {196, 414}, {198, 419}, {202, 426}, {207, 428}, {212, 432}, {216, 433}, {223, 432}, {217, 427}, {214, 423}, {214, 420}, {217, 415}, {220, 411}, {215, 409}, {215, 407}, {223, 401}, {223, 396}, {223, 396}, {220, 395}, {220, 392}, {227, 393}, {230, 384}, {241, 385}, {247, 380}, {247, 377}, {246, 375}, {243, 370}, {248, 373}, {256, 372}, {261, 367}, {266, 358}, {268, 357}, {269, 360}, {278, 348}, {279, 339}, {284, 334}, {290, 333}, {291, 330}, {302, 330}, {308, 325}, {308, 321}, {313, 316}, {313, 312}, {319, 301}, {319, 290}, {322, 290}, {335, 272}, {337, 267}, {334, 259}, {332, 257}, {329, 259}, {318, 248}, {309, 248}, {299, 245}, {292, 240}, {279, 238}, {271, 240}, {277, 233}, {277, 229}, {273, 227}, {272, 220}, {263, 212}, {252, 212}, {248, 213}, {241, 205}, {235, 201}, {231, 201}, {232, 197}, {227, 196}, {226, 193}, {220, 193}, {216, 196}, {209, 192}, {205, 193}, {200, 191}, {196, 187}, {193, 191}, {188, 192}, {189, 189}, {192, 187}, {189, 186}, {186, 187}, {182, 189}, {176, 190}, {173, 194}, {171, 198}, {167, 202}, {164, 199}, {160, 197}, {156, 198}, {153, 200}, {149, 200}, {146, 197}, {142, 192}, {142, 185}, {146, 177}, {146, 173}, {141, 171}, {136, 171}, {132, 172}, {127, 172}, {129, 166}, {129, 162}, {131, 162}, {133, 159}, {133, 156}, {136, 153}, {136, 149}, {125, 150}, {123, 154}, {121, 158}, {117, 162}, {112, 161}, {108, 162}, {103, 158}, {101, 151}, {102, 142}, {105, 136}, {107, 134}, {108, 127}, {113, 123}, {118, 121}, {121, 120}, {127, 120}, {130, 122}, {133, 122}, {136, 117}, {144, 118}, {148, 120}, {152, 118}, {154, 121}, {155, 129}, {156, 133}, {160, 135}, {163, 132}, {163, 125}, {162, 114}, {166, 109}, {173, 106}, {182, 99}, {183, 93}, {187, 90}, {193, 81}, {203, 81}, {204, 73}, {209, 72}, {215, 69}, {221, 69}, {217, 73}, {220, 74}, {225, 71}, {231, 70}, {232, 68}, {229, 67}, {224, 66}, {222, 62}, {224, 57}, {224, 54}, {236, 54}, {240, 51}, {243, 51}, {246, 47}, {241, 44}, {239, 42}, {232, 41}, {231, 37}, {226, 32}, {219, 36}, {215, 32}, {217, 29}, {210, 27}, {202, 27}, {199, 32}, {197, 35}, {198, 38}, {195, 40}, {191, 43}, {189, 47}, {189, 51}, {183, 51}, {183, 46}, {185, 43}, {179, 41}, {173, 38}, {168, 37}, {167, 33}, {174, 27}, {181, 24}, {190, 22}, {196, 20}, {200, 20}, {207, 14}, {210, 14}, {214, 16}, {214, 18}, {210, 22}, {221, 27}, {224, 25}, {227, 24}, {224, 20}, {230, 20}, {234, 19}, {222, 12}, {215, 11}, {209, 10}, {204, 11}, {200, 10}, {195, 12}, {189, 8}, {186, 14}, {189, 15}, {183, 11}, {179, 9}, {179, 6}};

    int Greenland[25][2] = {{212, 1}, {214, 4}, {221, 5}, {226, 4}, {229, 6}, {238, 6}, {241, 9}, {242, 13}, {245, 15}, {247, 20}, {249, 22}, {255, 27}, {261, 30}, {265, 29}, {268, 30}, {270, 28}, {270, 24}, {273, 21}, {285, 13}, {283, 12}, {279, 11}, {276, 8}, {273, 6}, {268, 5}, {265, 1}};

    int Antarctica[26][2] = {{159, 462}, {179, 465}, {194, 465}, {202, 463}, {217, 463}, {226, 461}, {224, 456}, {232, 451}, {234, 451}, {232, 454}, {229, 456}, {234, 461}, {236, 465}, {232, 466}, {222, 470}, {230, 472}, {245, 471}, {255, 471}, {260, 467}, {275, 466}, {275, 465}, {279, 465}, {290, 462}, {299, 461}, {309, 460}, {319, 459}};

    int Africa[51][2] = {{436, 114}, {429, 108}, {424, 106}, {421, 102}, {418, 96}, {413, 94}, {405, 94}, {402, 98}, {400, 99}, {392, 98}, {393, 102}, {391, 106}, {391, 113}, {394, 117}, {393, 122}, {390, 126}, {388, 132}, {388, 139}, {386, 146}, {387, 152}, {390, 156}, {392, 161}, {392, 168}, {392, 175}, {395, 184}, {400, 191}, {405, 199}, {407, 205}, {413, 209}, {423, 219}, {428, 206}, {433, 215}, {437, 217}, {443, 211}, {448, 210}, {451, 218}, {457, 219}, {458, 223}, {458, 232}, {457, 237}, {458, 243}, {460, 257}, {461, 275}, {458, 287}, {454, 298}, {450, 311}, {448, 327}, {439, 349}, {434, 359}, {428, 370}, {428, 373}};

    int Europe[29][2] = {{318, 15}, {337, 26}, {350, 35}, {353, 35}, {361, 40}, {361, 43}, {365, 43}, {365, 48}, {369, 52}, {369, 57}, {367, 60}, {371, 62}, {383, 72}, {371, 72}, {370, 75}, {373, 80}, {377, 85}, {381, 94}, {388, 95}, {391, 97}, {395, 95}, {397, 93}, {397, 89}, {395, 84}, {392, 75}, {395, 73}, {395, 71}, {411, 84}, {414, 83}};

    int Green_Points[5][2] = {{215, 470}, {235, 237}, {423, 180}, {380, 80}, {260, 15}};

    int i = 0;

    setfillstyle(SOLID_FILL, BLACK);
    bar(0, 0, getmaxx(), getmaxy());

    setfillstyle(SOLID_FILL, WHITE);
    for (i = 0; i < 1000; i++)
        putpixel(rand() % 640, rand() % 480, WHITE);

    for (i = 0; i < 250; i++)
        fillellipse(rand() % 640, rand() % 480, 1, 1);

    for (i = 0; i < 308; i++)
    {
        America[i][0] += mundi_xpos;
        if (i < 51)
        {
            Africa[i][0] += mundi_xpos;
            if (i < 29)
            {
                Europe[i][0] += mundi_xpos;
                if (i < 26)
                {
                    Antarctica[i][0] += mundi_xpos;
                    if (i < 25)
                        Greenland[i][0] += mundi_xpos;
                }
            }
        }
    }

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLUE);
    fillellipse(235 + mundi_xpos, 237, 234, 237);
    drawpoly(308, *America);
    drawpoly(25, *Greenland);
    drawpoly(26, *Antarctica);
    drawpoly(51, *Africa);
    drawpoly(29, *Europe);

    setfillstyle(SOLID_FILL, WHITE);
    floodfill(Green_Points[0][0] + mundi_xpos, Green_Points[0][1], BLACK);
    setfillstyle(SOLID_FILL, GREEN);
    for (i = 1; i < 5; i++)
        floodfill(Green_Points[i][0] + mundi_xpos, Green_Points[i][1], BLACK);

}
#endif
