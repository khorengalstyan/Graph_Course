#include <iostream>

#include "../include/menu.hpp"
#include "../include/solver.hpp"
#include "../include/input.hpp"
#include "../include/printAscii.hpp"
#include "../include/printText.hpp"
#include "../include/gotoXY.hpp"


enum keys
{
	W = 119,
	S = 115,
    UP = 65,
    DOWN = 66,
    ENTER = 10,
	ESC = 27,
};

int main()
{
	system("wmctrl -r ':ACTIVE:' -b toggle,fullscreen");
	system("clear");
    int point = 1;
    Menu(point);
    cbreak();
	bool isHiden = false;
    while(1)
    {
		if (isHiden == false)
		{
			printf("\e[?25l");
			isHiden = true;
		}
        const int key = keypress();
        switch(key)
        {
            case keys::UP : case keys::W:
            {
                --point;
                if (point == 0)
                {
                    point = 3;
                }
                Menu(point);
                break;
            }
            case keys::DOWN : case keys::S:
            {
                ++point;
                if (point == 4)
                {
                    point = 1;
                }
                Menu(point);
                break;
            }
            case keys::ENTER:
            {
                if (point == 1)
                {
                    solver();
					gotoXY(110,40);
					std::cout<<"\033[1;35mTAP ESC FOR MENU\033[0m\n";
                    break;
                }
                if (point == 2)
                {
					system("clear");
                    printGuide();
					printGuideText();
					gotoXY(110,40);
					std::cout<<"\033[1;35mTAP ESC FOR MENU\033[0m\n";
                    break;
                }
                if (point == 3)
                {
					system("clear");
                    normal();
					system("wmctrl -r ':ACTIVE:' -b toggle,fullscreen");
                    goto EXIT;
                }
                break;
            }
			case keys::ESC:
			{
				system("clear");
				Menu(point);
				break;	
			}
        }
	}
	EXIT : 
		printf("\e[?25h");
		return 0;
}
