#include <iostream>

bool Validation(std::string str) //This is to check the innput is valid or not.
{
	for (unsigned int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;

	return true;
}