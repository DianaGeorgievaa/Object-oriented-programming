#include <iostream>

#include "Pair.h"
#include "Settings.h"

int main()
{
	Settings<int> setting;
	setting.Set("key1", 13);
	setting.Set("key2", 14);
	setting.Set("key3", 15);
	setting.Set("key3", 16);
	setting.Print();

	std::cout << "Number of settings: " << setting.Count() << std::endl;

	int y = 0;
	std::cout << "If there is a pair with the same key prints 1 else prints 0: ";
	std::cout<<setting.Get("key1", y) << std::endl;
	std::cout << "There is a pair with this key and its value is: " << y << std::endl;
	std::cout << std::endl;
	int y1 = 0;
	std::cout << "If there is a pair with the same key prints 1 else prints 0: ";
	std::cout << setting.Get("key4", y1) << std::endl;
	std::cout << "There is not a pair with this key: " << y1 << ::std::endl;

	std::cout << "_____________________________________________" << std::endl;
	std::cout << "Char setting:" << std::endl;
	std::cout << std::endl;
	Settings<char> setting1;
	setting1.Set("key1", 'v');
	setting1.Set("key2", 'a');
	setting1.Set("key3", 'l');
	setting1.Set("key3", 'u');
	setting1.Set("key4", 'e');
	setting1.Print();

	std::cout << "Number of settings: " << setting1.Count() << std::endl;

	return 0;
}
