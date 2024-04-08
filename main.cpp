#include "TXLib.h"

struct GG {

    int x;
    int y;
    int v;
    int w;
    int h;

    void up() {
        txSetColor(RGB(244, 203, 77));
        txSetFillColor(RGB(244, 203, 77));
        txRectangle(x, y, x + w, y + h);
    }

    void left() {
        txSetColor(RGB(244, 203, 77));
        txSetFillColor(RGB(244, 203, 77));
        txRectangle(x, y, x + w, y + h);

        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txRectangle(x + 10, y + 10, x + 20, y + 20);

        txSetColor(TX_BLACK);
        txSetFillColor(TX_BLACK);
        txRectangle(x + 10, y + 15, x + 15, y + 20);
    }

    void down() {
        txSetColor(RGB(244, 203, 77));
        txSetFillColor(RGB(244, 203, 77));
        txRectangle(x, y, x + w, y + h);

        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txRectangle(x + 10, y + 10, x + 20, y + 20);
        txRectangle(x + 30, y + 10, x + 40, y + 20);

        txSetColor(TX_BLACK);
        txSetFillColor(TX_BLACK);
        txRectangle(x + 15, y + 15, x + 20, y + 20);
        txRectangle(x + 30, y + 15, x + 35, y + 20);
    }

    void right() {
        txSetColor(RGB(244, 203, 77));
        txSetFillColor(RGB(244, 203, 77));
        txRectangle(x, y, x + w, y + h);

        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txRectangle(x + 30, y + 10, x + 40, y + 20);

        txSetColor(TX_BLACK);
        txSetFillColor(TX_BLACK);
        txRectangle(x + 35, y  + 15, x + 40, y + 20);
    }


};

struct dom {

    int x;
    int y;
    int w;
    int h;

    int xDoor;
    int yDoor;
    int wDoor;
    int hDoor;

    void draw () {
        txSetColor(RGB(252, 250, 158));
        txSetFillColor(RGB(252, 250, 158));
        txRectangle(x, y, x + w, y + h);

        txSetColor(RGB(185, 122, 87));
        txSetFillColor(RGB(185, 122, 87));
        txRectangle(xDoor, yDoor, xDoor + wDoor, yDoor + hDoor); //800, 500, 80, 100

        txSetColor(RGB(255, 0, 0));
        txSetFillColor(RGB(255, 0, 0));
        POINT kr[3] = {{x, y}, {x + (h/2), y - (w * 2/3)}, {x + h, y}};
        txPolygon(kr, 3);

        txSetColor(RGB(0, 0, 255));
        txSetFillColor(RGB(0, 0, 255));
        txRectangle(xDoor + 40 + wDoor, yDoor, xDoor + 120 + wDoor, yDoor + 80);
        txRectangle(xDoor, yDoor - 120, xDoor + wDoor, yDoor - 40);
        txRectangle(xDoor + 40 + wDoor, yDoor - 120, xDoor + 120 + wDoor, yDoor - 40);

    }

};

struct Button {

    int x;
    int y;
    int w;
    int h;

    const char* text;

    COLORREF color_obv;
    COLORREF color_zal;

    int obv;

    int i;

    int z;

    void draw() {

        txSetColor(color_obv, obv);
        txSetFillColor(color_zal);
        txRectangle(x, y, x + w, y + h);

        if (i == 1) {

        txSetColor(RGB(253, 251, 179));
        txSelectFont("Comic Sans MS", z);
        txDrawText(x, y, x + w, y + h, text);

        }

        if (i == 2) {

            txSetColor(TX_WHITE);
            txSetFillColor(TX_WHITE);
            txRectangle(x + 12, y + 12, x + 47, y + 19);
            txRectangle(x + 12, y + 26, x + 47, y + 33);
            txRectangle(x + 12, y + 40, x + 47, y + 47);
        }
    }

};

void Room(int n) {

    txSetColor(RGB(185, 122, 87));
    txSetFillColor(RGB(185, 122, 87));
    txRectangle(596, 0, 604, 800);

    txRectangle(210, 200, 390, 210);
    txRectangle(225, 210, 232, 260);
    txRectangle(375, 210, 367, 260);

    txRectangle(1200 - 240, 260, 1200, 250);

    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);
    txRectangle(1200 - 240, 0, 1200, 250);

    txSetColor(RGB(253, 251, 179));
    txSetFillColor(RGB(253, 251, 179));
    txRectangle(1200 - 240 + 6, 6, 1200 - 240 + 117, 56);
    txRectangle(1200 - 240 + 123, 6, 1200 - 240 + 234, 56);


    if (n == 1) {

        txSetColor(TX_BLACK);
        txSetFillColor(TX_BLACK);
        txRectangle(604, 0, 1200, 800);

    }

}

void comp (int b) {

    txSetColor(RGB(227, 220, 213));
    txSetFillColor(RGB(227, 220, 213));
    txRectangle(337, 127, 380, 200);

    txSetColor(RGB(0, 78, 155));
    txSetFillColor(RGB(0, 78, 155));
    txRectangle(342, 132, 349, 139);
    txRectangle(342, 144, 375, 151);
    txRectangle(342, 158, 375, 195);

    txSetColor(TX_DARKGREY);
    txSetFillColor(TX_DARKGREY);

    if (b == 1) {
        txSetColor(TX_LIGHTGREEN);
        txSetFillColor(TX_LIGHTGREEN);
    }

    txRectangle(354, 132, 361, 139);
}

void mon () {

    txSetColor(TX_DARKGREY);
    txSetFillColor(TX_DARKGREY);
    txRectangle(242, 192, 307, 200);  //37 91    64
    txRectangle(271, 192, 277, 180);
    txRectangle(242, 127, 307, 180);

    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    txRectangle(247, 132, 302, 175);

}

dom House = {750, 300, 300, 300, 800, 490, 80, 110};

GG kub = {100, 100, 15, 50, 50};

int Phisik() {

    if (GetAsyncKeyState('W')) {
            kub.up();
            kub.y -= kub.v;
    }

    else if (GetAsyncKeyState('A')) {
        kub.left();
        kub.x -= kub.v;
    }

    else if (GetAsyncKeyState('S')) {
        kub.down();
        kub.y += kub.v;
    }

    else if (GetAsyncKeyState('D')) {
        kub.right();
        kub.x += kub.v;
    }


    if (kub.y < 0) {
        kub.y = 0;
    }

    if (kub.y > 800 - kub.h) {
        kub.y = 800 - kub.h;
    }

    if (kub.x < 0) {
        kub.x = 0;
    }

    if (kub.x + kub.w > 1200) {
        kub.x = 1200 - kub.w;
    }
}

int main() {

    txCreateWindow (1200, 800);

    int i = 0;

    int ONk = 0;

    string PAGE = "menu";
    string SaveCadr = "G_Cadr1";

    Button BmenuStart = {300, 300, 600, 100, "ÑÒÀÐÒ", TX_BLACK, TX_LIGHTCYAN, 5, 1, 85};
    Button BmenuHelp = {300, 450, 600, 100, "ÍÀÑÒÐÎÉÊÈ", TX_BLACK, TX_LIGHTCYAN, 5, 1, 85};
    Button BmenuExit = {300, 600, 600, 100, "ÂÛÕÎÄ", TX_BLACK, TX_LIGHTCYAN, 5, 1, 85};

    Button BgameM = {20, 20, 59, 59, "", TX_WHITE, TX_BLUE, 8, 2, 85};

    Button BmenuResume = {300, 275, 600, 100, "ÏÐÎÄÎËÆÈÒÜ", TX_BLACK, TX_LIGHTCYAN, 5, 1, 85};
    Button BmenuMenu = {300, 425 , 600, 100, "ÂÛÉÒÈ", TX_BLACK, TX_LIGHTCYAN, 5, 1, 85};

    Button BOnKomp = {342, 132, 7, 7, "", RGB(0, 78, 155), RGB(0, 78, 155), 1, 1, 85};



    while (PAGE != "exit") {

        txSetFillColor(TX_GREY);
        txClear();
        txBegin();

        if(PAGE == "menu") {

            BmenuStart.draw();
            BmenuHelp.draw();
            BmenuExit.draw();


            if(txMouseButtons() == 1 && txMouseX() > BmenuStart.x &&
            txMouseX() < BmenuStart.x + BmenuStart.w && txMouseY() > BmenuStart.y
            && txMouseY() < BmenuStart.y + BmenuStart.h) {PAGE = SaveCadr;}

           if(txMouseButtons() == 1 && txMouseX() > BmenuHelp.x &&
            txMouseX() < BmenuHelp.x + BmenuHelp.w && txMouseY() > BmenuHelp.y
            && txMouseY() < BmenuHelp.y + BmenuHelp.h) {PAGE = "help";}

            if(txMouseButtons() == 1 && txMouseX() > BmenuExit.x &&
            txMouseX() < BmenuExit.x + BmenuExit.w && txMouseY() > BmenuExit.y
            && txMouseY() < BmenuExit.y + BmenuExit.h) {PAGE = "exit";}
        }

        if (PAGE == "help") {

            txSetColor(RGB(253, 251, 179));
            txSelectFont("Comic Sans MS", 85);
            txDrawText(0, -95 , 1200, 800 - 95, "Íàñòðîéêè èãðû åù¸ íå äîáàâèëè =(");
            txDrawText(0, 0, 1200, 800, "GitHab àâòîðà: fykeek");

            txSelectFont("Comic Sans MS", 45);
            txSetColor(TX_WHITE);
            txDrawText(0, 95, 1200, 895, "ESC - Âûéòè");

            if  (GetAsyncKeyState(VK_ESCAPE)) {PAGE = "menu";}
        }

        if (PAGE == "RMenu") {

            BmenuResume.draw();
            BmenuMenu.draw();

            if (txMouseButtons() == 1 && txMouseX() > BmenuResume.x &&
            txMouseX() < BmenuResume.x + BmenuResume.w && txMouseY() > BmenuResume.y
            && txMouseY() < BmenuResume.y + BmenuResume.h) {PAGE = SaveCadr;}

            if(txMouseButtons() == 1 && txMouseX() > BmenuMenu.x &&
            txMouseX() < BmenuMenu.x + BmenuMenu.w && txMouseY() > BmenuMenu.y
            && txMouseY() < BmenuMenu.y + BmenuMenu.h) {PAGE = "menu";}

        }

        if(PAGE == "G_Cadr1") {

            House.draw();

            kub.down();

            BgameM.draw();

            if(txMouseButtons() == 1 && txMouseX() > BgameM.x &&
            txMouseX() < BgameM.x + BgameM.w && txMouseY() > BgameM.y
            && txMouseY() < BgameM.y + BgameM.h) {PAGE = "RMenu";}

            Phisik();

            if (kub.x + kub.w <= House.xDoor + House.wDoor && kub.y + kub.h <= House.yDoor + House.hDoor &&
            kub.y >= House.yDoor && kub.x >= House.xDoor && GetAsyncKeyState(VK_LBUTTON))
            {PAGE = "G_Cadr2"; SaveCadr = "G_Cadr2"; kub.x = 200; kub.y = 800 - kub.h;}

        }

        if(PAGE == "G_Cadr2") {

            kub.down();

            Phisik();

            BgameM.draw();

            Room(0);

            comp(ONk);

            mon();

            if(txMouseButtons() == 1 && txMouseX() > BOnKomp.x &&
            txMouseX() < BOnKomp.x + BOnKomp.w && txMouseY() > BOnKomp.y
            && txMouseY() < BOnKomp.y + BOnKomp.h) {ONk = 1;}

            if(txMouseButtons() == 1 && txMouseX() > BgameM.x &&
            txMouseX() < BgameM.x + BgameM.w && txMouseY() > BgameM.y
            && txMouseY() < BgameM.y + BgameM.h) {PAGE = "RMenu";}

        }

        txEnd();
        txSleep(10);
    }

    txDisableAutoPause();
    txTextCursor (false);
    return 0;
}

