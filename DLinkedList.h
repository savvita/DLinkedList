#pragma once
#include<iostream>

template<typename T>
struct Node
{
	T value;
	Node* prev;
	Node* next;
};

template<typename T>
class DLinkedList
{
private:
	Node<T>* head;
	unsigned long size;

public:
	explicit DLinkedList();

	unsigned long getSize() const;

	bool isEmpty() const;

	bool isContain(const T& value) const;

	void add(const T& value);
	void remove(const T& value);

	void printList(std::ostream& out = std::cout) const;

	Node<T>* operator[](unsigned long index);

	~DLinkedList();
};

template<typename T>
inline DLinkedList<T>::DLinkedList() :head{ nullptr }, size{ 0 }
{
}

template<typename T>
inline unsigned long DLinkedList<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline bool DLinkedList<T>::isEmpty() const
{
	return this->size == 0;
}

template<typename T>
inline bool DLinkedList<T>::isContain(const T& value) const
{
	Node<T>* tmp = this->head;
	while (tmp != nullptr)
	{
		if (tmp->value == value)
		{
			delete tmp;
			return true;
		}

		tmp = tmp->next;
	}

	delete tmp;

	return false;
}

template<typename T>
inline void DLinkedList<T>::add(const T& value)
{
	if (this->head == nullptr)
	{
		this->head = new Node<T>;
		this->head->prev = nullptr;
		this->head->next = nullptr;
		this->head->value = value;
	}
	else
	{
		Node<T>* tmp = this->head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}

		tmp->next = new Node<T>;
		tmp->next->value = value;
		tmp->next->next = nullptr;
		tmp->next->prev = tmp;
	}

	this->size++;
}

template<typename T>
inline void DLinkedList<T>::remove(const T& value)
{
	if (this->head->value == value)
	{
		Node<T>* tmp = this->head;
		this->head->next->prev = nullptr;
		this->head = this->head->next;
		delete tmp;
		this->size--;
	}
	else
	{
		Node<T>* tmp = this->head;
		while (tmp != nullptr)
		{
			if (tmp->value == value)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
				this->size--;
				break;
			}
			tmp = tmp->next;
		}
	}
}

template<typename T>
inline void DLinkedList<T>::printList(std::ostream& out) const
{
	Node<T>* tmp = this->head;

	while (tmp != nullptr)
	{
		out << tmp->value << "\t";
		tmp = tmp->next;
	}
	out << "\n";
}

template<typename T>
inline Node<T>* DLinkedList<T>::operator[](unsigned long index)
{
	Node<T>* tmp = this->head;
	unsigned long i = 0;
	while (tmp != nullptr && i != index)
	{
		tmp = tmp->next;
		++i;
	}
	return tmp;
}

template<typename T>
inline DLinkedList<T>::~DLinkedList()
{
	delete this->head;
}
