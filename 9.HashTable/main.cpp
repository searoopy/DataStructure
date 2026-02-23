#include "HashTable.h"
#include <iostream>


int main()
{
	HashTable table;


	table.Add("leesh", "0101010102929292929");
	table.Add("leesh", "0101010102929292929");
	table.Add("kevin", "01010101231232929");
	table.Add("baker", "010101010292111111111129");
	table.Add("john", "0101010123123123123222292929");
	table.Add("travolta", "0101010102929292929");
	table.Add("leesh", "0101010102929292929");
	table.Add("leesh", "0101010102929292929");
	table.Add("leesh", "0101010102929292929");

	table.Print();

	std::cout << "-------------------------------\n";


	Pair<std::string, std::string> outValue;
	if (table.Find("baker", outValue))
	{
		std::cout
			<< "검색 성공 . key: " << outValue.key
			<< " | Value: " << outValue.value << "\n";
	}

	std::cout << "-------------------------------\n";

	table.Delete("leesh");


	std::cout << "-------------------------------\n";


	HashTable::Entry& entry2 = table["john"];
	
	std::cout << entry2;


	table.Print();

	std::cin.get();
}