#include <iostream>
#include <string>

#include "../include/input.hpp"
#include "../include/inputSize.hpp"
#include "../include/printAscii.hpp"
#include "../include/menu.hpp"

enum keys
{
	UP = 65,
	DOWN = 66,
	ENTER = 10,
};
	
int inputSize(int size,std::string name)
{
	cbreak();
	system("clear");
	printSolution();
	size = 1;
	std::cout <<"\n\n\t\t\t\t\t\t\t   "<< "\033[1;32m" << name << " : " << size <<" ↑ ↓\033[0m\033[0m" << std::endl;
	while(1)
    {
		const int key = keypress();
        cbreak();
	
        switch(key)
        {
            case keys::UP:
            {
                system("clear");
				printSolution();
                ++size;
                std::cout <<"\n\n\t\t\t\t\t\t\t   "<< "\033[1;32m" << name << " : " << size <<" ↑ ↓\033[0m\033[0m" << std::endl;
                break;
            }
            case  keys::DOWN:
            {
                if (size > 1)
                {
					system("clear");
					printSolution();
                    --size;
					std::cout <<"\n\n\t\t\t\t\t\t\t   "<< "\033[1;32m" << name << " : " << size <<" ↑ ↓\033[0m\033[0m" << std::endl;
                    break;
                }
                else
                {
                    break;
                }
            }
            case keys::ENTER:
            {
                return size;
            }
        }
    }
} 
