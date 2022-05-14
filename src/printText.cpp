#include <iostream>

#include "printText.hpp"

using std::cout;

void printGuideText()
{
	cout<<"\n\n\t\t\t\t\t\033[1;35m   The purpose of the course work is to cover m x n\033[0m\n"; 
	cout<<"\t\t\t\t\t\033[1;35m   square grid with three length simple chains. The\033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   square grid can be covered with 3 length  simple\033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   chains when either both the rows and the columns\033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   are multiples of 3 or both are divisible by 2 re\033[0m\n";
	cout<<"\t\t\t\t\t\033[1;35m   mainders of three.\033[0m\n";
}
