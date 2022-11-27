#include "disp.h"
#include "stdio.h"
using namespace std;

#include "lan.cpp"
#include "steam.cpp"
#include "sound.cpp"
#include "block.cpp"
#include "board.cpp"
#include "window.cpp"

int main()
{
    printf("The game is currently under development. If you have any comments or suggestions, please feedback to the community or email: ax_pokl@qq.com\n");
    Lan lan;
    if (FindWindow("MineSweeperTetrisClass", NULL) != 0)
    {
        msgboxw(lan.getlan(lan.LAN_RUNNING_W), lan.getlan(lan.LAN_TITLE_W), MB_ICONINFORMATION);
    }
    else
    {
        Window w;
        w.bd.sd.initsound();
        w.bd.initbd(1);
        w.initwindow(false);
        while (iswin())
        {
            w.doaction();
            if (w.bd.addmask())
            {
                w.paintevent();
            }
            w.bd.sd.checkmusic();
            delay(1);
        }
    }
    return 0;
}