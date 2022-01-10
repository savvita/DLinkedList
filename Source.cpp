#include<iostream>
#include"DLinkedList.h"

int main()
{
	DLinkedList<int> list;
	std::cout << list.getSize() << "\n";
	std::cout << list.isEmpty() << "\n";
	std::cout << list.isContain(12) << "\n";
	list.printList();
	
	for (size_t i = 0; i < 10; i++)
	{
		list.add(10 + i);
	}

	list.printList();
	std::cout << list.getSize() << "\n";
	std::cout << list.isEmpty() << "\n";
	std::cout << list.isContain(180) << "\n";

	for (size_t i = 0; i < list.getSize(); i++)
	{
		std::cout << list[i]->value << "\t";
	}
	std::cout << "\n";

	list.remove(15);
	list.remove(16);
	list.remove(17);
	list.printList();
	std::cout << list.getSize() << "\n";
}