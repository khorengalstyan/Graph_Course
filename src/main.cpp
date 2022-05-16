#include <iostream>

#include "../include/menu.hpp"
#include "../include/solver.hpp"
#include "../include/input.hpp"
#include "../include/printAscii.hpp"
#include "../include/printText.hpp"


enum keys
{
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
    while(1)
    {
        const int key = keypress();
        switch(key)
        {
            case keys::UP:
            {
                --point;
                if (point == 0)
                {
                    point = 3;
                }
                Menu(point);
                break;
            }
            case keys::DOWN:
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
                    break;
                }
                if (point == 2)
                {
					system("clear");
                    printGuide();
					printGuideText();
                    break;
                }
                if (point == 3)
                {
					system("clear");
                    normal();
					system("wmctrl -r ':ACTIVE:' -b toggle,fullscreen");
                    exit(0);
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
	return 0;
}
