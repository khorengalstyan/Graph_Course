#include <iostream>

#include "../include/printText.hpp"
#include "../include/printAscii.hpp"

using std::cout;

void printGuideText()
{
	cout<<"\n\n\t\t\t\t\t\033[1;35m   The purpose of the course work is to cover m x n\033[0m\n"; 
	cout<<"\t\t\t\t\t\033[1;35m   square grid with three length simple chains. The\033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   square grid can be covered with 3-length  simple\033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   chains when either both the rows and the columns\033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   are multiples of 3 or both are divisible by 2 re\033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   mainders of three.\033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   Choosing Solution from menu you can increase the \033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   amount of rows or columns with ↑ or decrease  it \033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   with ↓.After that the square grid and  adjacency \033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   matrix of it is created and if it  is  coverable \033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   with three length simple chains then you can see \033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   the coverage, otherwise you can  see  a  message \033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   that the square grid can't be covered.\033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   You can change position of cursor  in menu  with \033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   ↑ ↓  or 'w' 's' from keyboard. To choose an opti \033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   on you must tap 'ENTER'.\033[0m\n";
	printGithub();

	cout<<"\n\t\t\t\t\t\033[1;31m     https://github.com/khorengalstyan/Graph_Course\033[0m\n";
}
