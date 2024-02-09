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

    int i;

    void draw() {

        txSetColor(color_obv);
        txSetFillColor(color_zal);
        txRectangle(x, y, x + w, y + h);
        txSetColor(RGB(253, 251, 179));

        if (i == 1) {txSelectFont("Comic Sans MS", 85);
        txDrawText(x, y, x + w, y + h, text);}
    }

};

int main()
    {
    txCreateWindow (1200, 800);

    int i = 0;

    string PAGE = "menu";

    GG kub = {100, 100, 15, 50, 50};
    dom House = {750, 300, 300, 300, 800, 490, 80, 110};
    Button BmenuStart = {300, 300, 600, 100, "ÑÒÀÐÒ", TX_BLACK, TX_LIGHTCYAN, 1};
    Button BmenuHelp = {300, 450, 600, 100, "ÍÀÑÒÐÎÉÊÈ", TX_BLACK, TX_LIGHTCYAN, 1};
    Button BmenuExit = {300, 600, 600, 100, "ÂÛÕÎÄ", TX_BLACK, TX_LIGHTCYAN, 1};

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
            && txMouseY() < BmenuStart.y + BmenuStart.h) {PAGE = "game";}

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
            txDrawText(0, -45 , 1200 - 45, 800, "Íàñòðîéêè èãðû åù¸ íå äîáàâèëè =(");
            txDrawText(0, 45 , 1200 + 45, 800, "GitHab àâòîðà: fykeek");

        }

        if(PAGE == "game") {

            House.draw();

            kub.down();

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

            if (kub.x + kub.w <= House.xDoor + House.wDoor && kub.y + kub.h <= House.yDoor + House.hDoor &&
            kub.y >= House.yDoor && kub.x >= House.xDoor && GetAsyncKeyState(VK_LBUTTON)) {

                break;

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

        txEnd();
        txSleep(10);
    }

    txDisableAutoPause();
    txTextCursor (false);
    return 0;
}

