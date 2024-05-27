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

struct plot {

    int x;
    int y;
    int w;
    int h;
    int v;

    void draw() {

        txSetColor(RGB(205, 135, 25));
        txSetFillColor(RGB(205, 135, 25));
        POINT kor[4] ={{x, y}, {x + w, y}, {x + w - h, y + h}, {x, y + h}};
        txPolygon(kor, 4);

        txSetColor(RGB(165, 107, 20));
        txSetFillColor(RGB(165, 107, 20));
        txRectangle(x + (w / 2) - 3, y, x + (w / 2) + 3, y - (h * 3/2));

        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        POINT flag[3] = {{x + (w / 2) + 3, y - (h * 3/2)}, {x + (w / 2) + 3, y - (h * 3/4)}, {x + (w / 2) + 3 + h, y - h}};
        txPolygon(flag, 3);
    }

    void ph() {

        if (GetAsyncKeyState('W')) {

            y -= v;
        }

        else if (GetAsyncKeyState('S')) {

            y += v;
        }

        if (y <= 56 + 65 + (h * 3/2)) {                //178 + 65, 56 + 65, 1023 - 65, 745 - 65

            y = 56 + 65 + (h * 3/2);

        }

        if (y >= 745 - 65 - h) {                //178 + 65, 56 + 65, 1023 - 65, 745 - 65

            y = 745 - 65 - h;

        }

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
    COLORREF color_text;

    int obv;

    int i;

    int z;

    void draw() {

        txSetColor(color_obv, obv);
        txSetFillColor(color_zal);
        txRectangle(x, y, x + w, y + h);

        if (i == 1) {

        txSetColor(color_text);
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

struct pepad {

    int w;
    int h;
    int x;
    int y;
    int v;

    void draw() {

        txSetColor(RGB (255, 255, 0));
        txSetFillColor(RGB (255, 255, 0));
        txRectangle(x, y, x + w, y + h);

    }

};

void bed() {

    txSetColor(RGB(185, 122, 87));
    txSetFillColor(RGB(185, 122, 87));
    txRectangle(1200 - 240, 260, 1200, 250);

    txSetColor(RGB(253, 251, 179));
    txSetFillColor(RGB(253, 251, 179));
    txRectangle(1200 - 240, 0, 1200, 250);

    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);
    txRectangle(1200 - 240 + 6, 6, 1200 - 240 + 117, 56);
    txRectangle(1200 - 240 + 123, 6, 1200 - 240 + 234, 56);

    }

void Room(int n) {

    txSetColor(RGB(185, 122, 87));
    txSetFillColor(RGB(185, 122, 87));
    txRectangle(596, 0, 604, 800);

    txRectangle(210, 200, 390, 210);
    txRectangle(225, 210, 232, 260);
    txRectangle(375, 210, 367, 260);

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
    txRectangle(242, 127, 307, 180); //65 53  | *13

    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    txRectangle(247, 132, 302, 175);

}

void mon2 () {

    txSetColor(TX_DARKGREY);
    txSetFillColor(TX_DARKGREY);
    txRectangle(178, 56, 1023, 745);//845 689
    txRectangle(561, 745, 639, 801);

    txSetColor(TX_LIGHTCYAN);
    txSetFillColor(TX_LIGHTCYAN);
    txRectangle(178 + 65, 56 + 65, 1023 - 65, 745 - 65);

}

void ig() {

    txSetColor(TX_GREY);
    txSetFillColor(TX_GREY);
    txRectangle(0, 0, 1200, 56);
    txRectangle(0, 0, 178, 800);
    txRectangle(0, 800, 1200, 745);
    txRectangle(1200, 0, 1023, 800);

    txSetColor(TX_DARKGREY);
    txSetFillColor(TX_DARKGREY);
    txRectangle(178, 56, 1023, 56 + 65);
    txRectangle(178, 56, 178 + 65, 745);
    txRectangle(178, 745, 1023, 745 - 65);
    txRectangle(1023, 56, 1023 - 65, 745);

}

void dialog(const char* a) {

    txSetColor(RGB(183, 129, 15), 5);
    txSetFillColor(RGB(241, 185, 90));
    txRectangle(800, 0, 1200, 300);
    txSetColor(TX_WHITE);
    txSelectFont("Comic Sans MS", 30);
    txDrawText(800, 0, 1200, 300, a);

}

void chel() {

    txSetColor(RGB(244, 203, 77));
    txSetFillColor(RGB(244, 203, 77));
    txRectangle(300, 100, 900, 700);

    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);
    txRectangle(420, 220, 540, 340);
    txRectangle(660, 220, 780, 340);

    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    txRectangle(480, 280, 540, 340);
    txRectangle(660, 280, 720, 340);
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

string PAGE = "menu";

Button BgameM = {20, 20, 59, 59, "", TX_WHITE, TX_BLUE, RGB(253, 251, 179), 8, 2, 85};

int Rmenu() {

    BgameM.draw();

    if(txMouseButtons() == 1 && txMouseX() > BgameM.x &&
    txMouseX() < BgameM.x + BgameM.w && txMouseY() > BgameM.y
    && txMouseY() < BgameM.y + BgameM.h) {PAGE = "RMenu";}

}

int main() {

    txCreateWindow (1200, 800);

    int i = 0;

    int ONk = 0;

    int vrem = 0;

    string SaveCadr = "G_Cadr1";

    pepad prep[10];

    Button BmenuStart = {300, 300, 600, 100, "�����", TX_BLACK, TX_LIGHTCYAN, RGB(253, 251, 179), 5, 1, 85};
    Button BmenuHelp = {300, 450, 600, 100, "������", TX_BLACK, TX_LIGHTCYAN, RGB(253, 251, 179), 5, 1, 85};
    Button BmenuExit = {300, 600, 600, 100, "�����", TX_BLACK, TX_LIGHTCYAN, RGB(253, 251, 179), 5, 1, 85};


    Button BmenuResume = {300, 275, 600, 100, "����������", TX_BLACK, TX_LIGHTCYAN, RGB(253, 251, 179), 5, 1, 85};
    Button BmenuMenu = {300, 425 , 600, 100, "�����", TX_BLACK, TX_LIGHTCYAN, RGB(253, 251, 179), 5, 1, 85};

    Button BOnKomp = {342, 132, 7, 7, "", RGB(0, 78, 155), RGB(0, 78, 155), RGB(253, 251, 179), 1, 1, 85};

    Button BMon = {247, 132, 55, 43, "��� ���!", TX_LIGHTCYAN, TX_LIGHTCYAN, TX_BLACK, 1, 1, 13};

    Button BGame = {300, 450, 600, 100, "������", TX_BLACK, TX_BLUE, TX_WHITE, 10, 1, 85};
    Button BGameE = {300, 450, 600, 100, "�����", TX_BLACK, TX_BLUE, TX_WHITE, 10, 1, 85};
    Button BGameO = {300, 450, 600, 100, "�������� ����", TX_BLACK, TX_BLUE, TX_WHITE, 10, 1, 82};

    Button BmenuExit2 = {880, 175, 240, 75, "�����", TX_BLACK, TX_LIGHTCYAN, RGB(253, 251, 179), 5, 1, 52};

    plot Boat = {178 + 165, 250, 150, 50, 5};

    prep[0] = {90, 45, 908, 293, 7}; // 958 243 715

    for (int i = 1; i <= 9; i++) {

        prep[i] = {random(50, 100), random(10, 50), random(178 + 65,1023 - 65), random(56 + 65, 745 - 65), random(5, 10)}; // 958 243 715    | , , ,

    }

    while (PAGE != "exit") {

        txSetFillColor(TX_GRAY);
        txClear();
        txBegin();

        if(PAGE == "menu") {


            BmenuStart.draw();
            BmenuHelp.draw();
            BmenuExit.draw();
            txSetColor(TX_WHITE);
            txSelectFont("Comic Sans MS", 160);
            txDrawText(0, 0, 1200, 300, "������� �����");


            if(txMouseButtons() == 1 && txMouseX() > BmenuStart.x &&
            txMouseX() < BmenuStart.x + BmenuStart.w && txMouseY() > BmenuStart.y
            && txMouseY() < BmenuStart.y + BmenuStart.h) {PAGE = SaveCadr;while (txMouseButtons() == 1) {txSleep(10);}}

           if(txMouseButtons() == 1 && txMouseX() > BmenuHelp.x &&
            txMouseX() < BmenuHelp.x + BmenuHelp.w && txMouseY() > BmenuHelp.y
            && txMouseY() < BmenuHelp.y + BmenuHelp.h) {PAGE = "help";while (txMouseButtons() == 1) {txSleep(10);}}

            if(txMouseButtons() == 1 && txMouseX() > BmenuExit.x &&
            txMouseX() < BmenuExit.x + BmenuExit.w && txMouseY() > BmenuExit.y
            && txMouseY() < BmenuExit.y + BmenuExit.h) {PAGE = "exit";while (txMouseButtons() == 1) {txSleep(10);}}
        }

        if (PAGE == "help") {

            txSetColor(RGB(253, 251, 179));
            txSelectFont("Comic Sans MS", 85);
            txDrawText(0, -95 , 1200, 800 - 95, "��������� WASD ��� ����������!");
            txDrawText(0, 0, 1200, 800, "GitHab ������: fykeek");

            txSelectFont("Comic Sans MS", 45);
            txSetColor(TX_WHITE);
            txDrawText(0, 95, 1200, 895, "ESC - �����");

            if(txMouseButtons() == 1 && txMouseX() > BmenuHelp.x &&
            txMouseX() < BmenuHelp.x + BmenuHelp.w && txMouseY() > BmenuHelp.y
            && txMouseY() < BmenuHelp.y + BmenuHelp.h) {PAGE = "G_Cadr6";while (txMouseButtons() == 1) {txSleep(10);}}

            if  (GetAsyncKeyState(VK_ESCAPE)) {PAGE = "menu";}
        }

        if (PAGE == "RMenu") {

            BmenuResume.draw();
            BmenuMenu.draw();

            if (txMouseButtons() == 1 && txMouseX() > BmenuResume.x &&
            txMouseX() < BmenuResume.x + BmenuResume.w && txMouseY() > BmenuResume.y
            && txMouseY() < BmenuResume.y + BmenuResume.h) {PAGE = SaveCadr;while (txMouseButtons() == 1) {txSleep(10);}}

            if(txMouseButtons() == 1 && txMouseX() > BmenuMenu.x &&
            txMouseX() < BmenuMenu.x + BmenuMenu.w && txMouseY() > BmenuMenu.y
            && txMouseY() < BmenuMenu.y + BmenuMenu.h) {PAGE = "menu";while (txMouseButtons() == 1) {txSleep(10);}}

        }

        if(PAGE == "G_Cadr1") {

            txSetFillColor(RGB(44, 216, 65));

            House.draw();

            kub.down();

            Rmenu();

            Phisik();

            if (kub.x + kub.w <= House.xDoor + House.wDoor && kub.y + kub.h <= House.yDoor + House.hDoor &&
            kub.y >= House.yDoor && kub.x >= House.xDoor && GetAsyncKeyState(VK_LBUTTON))
            {PAGE = "G_Cadr2"; SaveCadr = "G_Cadr2"; kub.x = 200; kub.y = 800 - kub.h;while (txMouseButtons() == 1) {txSleep(10);}}

            if (kub.x + kub.w <= House.xDoor + House.wDoor && kub.y + kub.h <= House.yDoor + House.hDoor &&
             kub.y >= House.yDoor && kub.x >= House.xDoor) {txSetColor(TX_WHITE); txSelectFont("Comic Sans MS", 30); txDrawText(750, 600, 1050, 650, "������� ���");}

        }

        if(PAGE == "G_Cadr2") {

            Rmenu();

            kub.down();

            Phisik();

            Room(1);

            comp(ONk);

            mon();

            if (vrem <= 1000)
                dialog("׸��. ���� ���� �� ������������� \n"
                       "���������. ����� ���� ������");

            if(ONk == 1) {

                BMon.draw();

                if(txMouseButtons() == 1 && txMouseX() > BMon.x &&
                txMouseX() < BMon.x + BMon.w && txMouseY() > BMon.y
                && txMouseY() < BMon.y + BMon.h) {PAGE = "G_Cadr3"; SaveCadr = "G_Cadr3"; vrem = 0;while (txMouseButtons() == 1) {txSleep(10);}}

            }

            if(txMouseButtons() == 1 && txMouseX() > BOnKomp.x &&
            txMouseX() < BOnKomp.x + BOnKomp.w && txMouseY() > BOnKomp.y
            && txMouseY() < BOnKomp.y + BOnKomp.h) {ONk = 1;while (txMouseButtons() == 1) {txSleep(10);}}

            vrem +=10;

        }

        if(PAGE == "G_Cadr3") {

            Rmenu();

            mon2();

            txSetColor(TX_WHITE);

            txSelectFont("Comic Sans MS", 100);

            txDrawText(178 + 65, 56 + 65, 1023 - 65, 450, "�������� �����");

            BGame.draw();

            if (vrem <= 1000)
                dialog("� ��� ����� ��� ������� �����!\n" "");

            vrem += 10;

            if(txMouseButtons() == 1 && txMouseX() > BGame.x &&
            txMouseX() < BGame.x + BGame.w && txMouseY() > BGame.y
            && txMouseY() < BGame.y + BGame.h) {PAGE = "G_Cadr4"; SaveCadr = "G_Cadr4";while (txMouseButtons() == 1) {txSleep(10);} vrem == 0;}

        }

        if(PAGE == "G_Cadr3+") {

            Rmenu();

            mon2();

            txSetColor(TX_WHITE);

            txSelectFont("Comic Sans MS", 90);

            txDrawText(178 + 65, 56 + 65, 1023 - 65, 450, "���������� ��� ���");

            BGame.draw();

            if(txMouseButtons() == 1 && txMouseX() > BGame.x &&
            txMouseX() < BGame.x + BGame.w && txMouseY() > BGame.y
            && txMouseY() < BGame.y + BGame.h) {PAGE = "G_Cadr4"; SaveCadr = "G_Cadr4";while (txMouseButtons() == 1) {txSleep(10);}}

        }

            if(PAGE == "G_Cadr4"){

            txSetColor(TX_BLACK);
            txSetFillColor(TX_BLACK);
            txRectangle(178 + 65, 56 + 65, 1023 - 65, 745 - 65);

             for (int i = 0; i <= 9; i++) {

                prep[i].draw();

                prep[i].x -= prep[i].v;

                if (prep[i].x <= 0) {

                    prep[i].x = 1200;
                    prep[i].v += 0.5;
                    prep[i].y += random(-200, 200);

                }

                if (txGetPixel (Boat.x + Boat.w, Boat.y) == RGB (255, 255, 0) || txGetPixel (Boat.x + Boat.w - Boat.h, Boat.y + Boat.h) == RGB (255, 255, 0) ||
                (prep[i].y > Boat.y && prep[i].y  < Boat.y + Boat.h && prep[i].x < Boat.x + Boat.w - Boat.h  && prep[i].x > Boat.x)) {

                    PAGE = "G_Cadr3+"; SaveCadr = "G_Cadr3+"; vrem = 0; txSetColor(TX_RED); txTextOut(100, 100, "00"); prep[i].x = random(10, 100) + 800;

                }

            }

            ig();

            Rmenu();

            Boat.draw();
            Boat.ph();

            vrem += 10;

            if (vrem >= 18000) {PAGE = "G_Cadr5"; SaveCadr = "G_Cadr5";  vrem = 0;}

        }

        if(PAGE == "G_Cadr5"){

            Rmenu();

            mon2();

            txSetColor(TX_WHITE);

            txSelectFont("Comic Sans MS", 70);

            txDrawText(178 + 65, 56 + 65, 1023 - 65, 450, "�� ������� ������ �����");

            BGameO.draw();

            if(txMouseButtons() == 1 && txMouseX() > BGameO.x &&
            txMouseX() < BGameO.x + BGameO.w && txMouseY() > BGameO.y
            && txMouseY() < BGameO.y + BGameO.h) {PAGE = "G_Cadr5+"; SaveCadr = "G_Cadr5+"; while (txMouseButtons() == 1) {txSleep(10);}}

        }

        if(PAGE == "G_Cadr5+"){

            Rmenu();

            mon2();

            txSetColor(TX_WHITE);

            txSelectFont("Comic Sans MS", 65);

            txDrawText(178 + 65, 56 + 65, 1023 - 65, 450, "�� ������� �������� ����");

            BGameE.draw();

            if(txMouseButtons() == 1 && txMouseX() > BGameE.x &&
            txMouseX() < BGameE.x + BGameE.w && txMouseY() > BGameE.y
            && txMouseY() < BGameE.y + BGameE.h) {PAGE = "G_Cadr6"; SaveCadr = "G_Cadr6";while (txMouseButtons() == 1) {txSleep(10);}}

        }

        if(PAGE == "G_Cadr6") {

            Rmenu();

            bed();

            kub.down();

            Phisik();

            Room(0);

            comp(ONk);

            mon();

            if (vrem <= 1000)
                dialog("� � ��� ����� ����� ������\n" "");

            vrem += 10;

            if (kub.x + kub.w <= 1200 && kub.y + kub.h <= 250 &&
            kub.y >= 0 && kub.x >= 960 && GetAsyncKeyState(VK_LBUTTON))
            {PAGE = "G_Cadr7"; SaveCadr = "G_Cadr7"; while (txMouseButtons() == 1) {txSleep(10);}}  //1200 - 240, 0, 1200, 250

            if (kub.x + kub.w <= 1200 && kub.y + kub.h <= 250 &&
            kub.y >= 0 && kub.x >= 960) {txSetColor(TX_WHITE); txSelectFont("Comic Sans MS", 30); txDrawText(960, 250, 1200, 300, "������� ���");}

        }

        if(PAGE == "G_Cadr7") {

            txSetColor(RGB(253, 251, 179));
            txSetFillColor(RGB(253, 251, 179));
            txRectangle(0,0,1200,800);

            chel();

            dialog("������� �����! �� ����� ���.\n""����� �� ��� ����������. ������. � �� � ����� 4 �����.");

            BmenuExit2.draw();

            if(txMouseButtons() == 1 && txMouseX() > BmenuExit2.x &&
            txMouseX() < BmenuExit2.x + BmenuExit2.w && txMouseY() > BmenuExit2.y
            && txMouseY() < BmenuExit2.y + BmenuExit2.h) {PAGE = "exit";while (txMouseButtons() == 1) {txSleep(10);}}

        }

        txEnd();
        txSleep(10);
    }

    txDisableAutoPause();
    txTextCursor (false);
    return 0;
}

