#include <iostream>
#include <string>

int validInputRows(std::string input)
{
	int count;	
	do
	{
		std::cin.clear();
		std::cout<<"Please input rows "  << " : "; 
		std :: cin >> input;
		count = 0;
		for (int i = 0; i < input.length();++i)
		{
			if (isdigit(input[i]))
			{
				++count;
			}
		}
		
		
	} while (count!=input.length());
	int answer = std::stoi(input);
	return answer;
}

int validInputCols(std::string input)
{
	int count;	
	do
	{
		std::cin.clear();
		std::cout<<"Please input cols "  << " : "; 
		std :: cin >> input;
		count = 0;
		for (int i = 0; i < input.length();++i)
		{
			if (isdigit(input[i]))
			{
				++count;
			}
		}
		
		
	} while (count!=input.length());
	int answer = std::stoi(input);
	return answer;
}
