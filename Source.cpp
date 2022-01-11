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

	list.remove(19);
	list.remove(10);
	list.printList();
	std::cout << list.getSize() << "\n";
}