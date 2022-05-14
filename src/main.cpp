#include <iostream>

#include "../include/menu.hpp"
#include "../include/solver.hpp"
#include "../include/input.hpp"
#include "../include/print.hpp"

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
    print_menu(point);
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
                print_menu(point);
                break;
            }
            case keys::DOWN:
            {
                ++point;
                if (point == 4)
                {
                    point = 1;
                }
                print_menu(point);
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
                    printGuide();
                    break;
                }
                if (point == 3)
                {
                    normal();
					system("clear");
					system("wmctrl -r ':ACTIVE:' -b toggle,fullscreen");
                    exit(0);
                }
                break;
            }
			case keys::ESC:
			{
				system("clear");
				print_menu(point);
				break;	
			}
        }
	}
	normal();
	return 0;
}
