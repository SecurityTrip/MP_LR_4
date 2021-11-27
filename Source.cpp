#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>

void stringsort(std::vector<int>& mass, std::string& instring)
{
	std::string s;
	std::string buff;
	for (int i = 0;i<instring.size();i++)
	{
		if (instring[i] >= 48 && instring[i] <= 57)
		{
			buff += std::to_string(instring[i]-'0');

			if (i == instring.size() - 1)
			{
				mass.push_back(stoi(buff));
				buff.clear();
			}
		}
		else
		{
			if (buff.size() > 0)
			{
				mass.push_back(stoi(buff));
				buff.clear();
			}
			s += instring[i];
		}
	}
	instring = s;
	s.clear();
}

void massprint(std::vector<int>& mass, std::ofstream& file)
{
	file << "[";
	for (int i = 0;i<mass.size();i++)
	{
		if(i==mass.size()-1) file << (int)mass[i];
		else file << (int)mass[i] << ", ";
	}
	file << "]";
}


int main()
{
	std::setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::vector<int> numbers;
	std::ifstream infile("E:\\VSProjects\\MP_LR_4\\input.txt");
	std::ofstream outfile("E:\\VSProjects\\MP_LR_4\\output.txt");
	if (infile.is_open()) 
	{
		if (outfile.is_open())
		{
			std::string test;
			getline(infile, test);
			stringsort(numbers, test);
			outfile << test << std::endl;
			massprint(numbers, outfile);

		}
		else std::cout << "Out file is not open";
		
	}
	else std::cout << "In file is not open";
	infile.close();
	outfile.close();
}