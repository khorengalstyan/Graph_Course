#include <iostream>
#include <string>

#include "../include/input.hpp"

int input(int size,std::string name)
{
	cbreak();
	system("clear");
	const int UP = 65;
	const int DOWN = 66;    
	const int ENTER = 10;
	size = 1;
	std::cout << "\033[1;32m" << name << " : " << size <<" ↑ ↓\033[0m\033[0m" << std::endl;

	while(1)
    {
        cbreak();
        const int key = keypress();
        switch(key)
        {
            case UP:
            {
                system("clear");
                ++size;
                std::cout << "\033[1;32m" << name << " : " << size <<" ↑ ↓\033[0m\033[0m" << std::endl;
                break;
            }
            case  DOWN:
            {
                if (size > 1)
                {
					system("clear");
                    --size;
                    std::cout << "\033[1;32m" << name << " : " << size << " ↑ ↓\033[0m\033[0m" << std::endl;
                    break;
                }
                else
                {
                    break;
                }
            }
            case ENTER:
            {
                return size;
            }
        }
    }
}

