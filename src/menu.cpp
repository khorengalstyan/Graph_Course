#include <iostream>

#include "../include/menu.hpp"
#include "../include/printAscii.hpp"

void Menu(size_t point)

{
	switch(point)
	{
        case 1:
        {
			system("clear");
			printMenu();
			std::cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\033[1;34m->SOLUTION<-\033[0m\n";
			std::cout<<"\t\t\t\t\t\t\t\t\033[1;33mGUIDE\033[0m\n";
			std::cout<<"\t\t\t\t\t\t\t\t\033[1;33mGRAPHVIZ\033[0m\n";
			std::cout<<"\t\t\t\t\t\t\t\t\033[1;33mEXIT\033[0m\n";
			break;
        }
        case 2:
        {
		    system("clear");
			printMenu();
            std::cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\033[1;33mSOLUTION\033[0m\n";
            std::cout<<"\t\t\t\t\t\t\t\t\033[1;34m->GUIDE<-\033[0m\n";
			std::cout<<"\t\t\t\t\t\t\t\t\033[1;33mGRAPHVIZ\033[0m\n";
            std::cout<<"\t\t\t\t\t\t\t\t\033[1;33mEXIT\033[0m\n";
            break;
        }
		case 3:
        {
            system("clear");
            printMenu();
            std::cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\033[1;33mSOLUTION\033[0m\n";
            std::cout<<"\t\t\t\t\t\t\t\t\033[1;33mGUIDE\033[0m\n";
            std::cout<<"\t\t\t\t\t\t\t\t\033[1;34m->GRAPHVIZ<-\033[0m\n";
            std::cout<<"\t\t\t\t\t\t\t\t\033[1;33mEXIT\033[0m\n";
            break;
        }

        case 4:
		{
            system("clear");
			printMenu();
            std::cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\033[1;33mSOLUTION\033[0m\n";
            std::cout<<"\t\t\t\t\t\t\t\t\033[1;33mGUIDE\033[0m\n";
            std::cout<<"\t\t\t\t\t\t\t\t\033[1;33mGRAPHVIZ\033[0m\n";
            std::cout<<"\t\t\t\t\t\t\t\t\033[1;34m->EXIT<-\033[0m\n";
            break;
		}
	}
}
