#include "RecursiveLinkedList.h"
#include<iostream>
#include<string>
using namespace std;


bool RecursiveLinkedList::add(string value)
{
	Node* x = new Node;
	Node* current = headpointer;
	x->data = value;
	x->next = NULL;

	if(current == NULL)
	{
		headpointer = x;
		size1 = size1 + 1;
		return true;
	}
	else
	{
		while(current -> next != NULL)
		{
			current = current -> next;
		}
		current -> next = x;
		size1 = size1 + 1;
		return true;
	}
	return false;
}

int RecursiveLinkedList::size()
{
	return size1;
}

bool RecursiveLinkedList::isEmpty()
{
	if (size1 == 0 && headpointer == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string RecursiveLinkedList::get(int atIndex)
{
	int currentIndex=0;
	Node* current = headpointer;

	while ((current != NULL) && (currentIndex < atIndex))
	{
		current = current->next;
		currentIndex = currentIndex+1;
	}
	if((current != NULL) && (currentIndex == atIndex))
	{
		return current->data;
	}
	else
	{
		return "";
	}
}

bool RecursiveLinkedList::insert(string value, int atIndex)
{

	Node* add = new Node;
	add->data = value;
	Node* current = headpointer;
	Node* before = current;
	int presentIndex = 0;
	if ((headpointer == NULL) && (atIndex == 0))
	{
		headpointer = add;
		add->next = NULL;
		size1 = size1 + 1;
		return true;
	}
	else if ((headpointer != NULL) && (atIndex == 0))
	{
		add->next = current;
		headpointer = add;
		size1 = size1 + 1;
		return true;
	}
	else if ((headpointer->next == NULL) && (atIndex == 1))
	{
		headpointer->next = add;
		add->next = NULL;
		size1 = size1 + 1;
		return true;
	}
	else if ((headpointer->next == NULL) && (atIndex == 0))
	{
		add->next = current;
		headpointer = add;
		size1 = size1 + 1;
		return true;
	}
	else if (headpointer->next != NULL)
	{
		while ((current != NULL) && (presentIndex<atIndex))
		{
			before = current;
			current = current->next;
			presentIndex = presentIndex + 1;
		}

		if ((before != NULL) && (atIndex == presentIndex))
		{
			before->next = add;
			add->next = current;
			size1 = size1 + 1;
			return true;
		}

		else
		{
			return false;;
		}
	}

	else
	{
		return false;
	}
}

string RecursiveLinkedList::remove(int atIndex)
{
	Node *current = headpointer;
	string save;
	int currentIndex = -1;

	if (atIndex < 0 || atIndex > size1 - 1)
	{
		return "";
	}

	if (atIndex == 0)
	{
		save = current->data;
		headpointer = headpointer->next;
		delete current;
		size1 = size1 - 1;
		return save;
	}

	while (current != NULL)
	{
		currentIndex = currentIndex + 1;

		if (currentIndex == atIndex - 1)
		{
			save = current->next->data;
			delete current->next;
			current->next = current->next->next;
			size1 = size1 - 1;
			return save;
		}
		else
		{
			current = current->next;
		}
	}
	return "";
}

void RecursiveLinkedList::clear()
{
	headpointer = NULL;
	size1=0;
}

string RecursiveLinkedList::set(int atIndex, string value)
{
	string old;
	int currententIndex = 0;
	Node* current = headpointer;
	while ((current != NULL) && (currententIndex < atIndex))
	{
		current = current->next;
		currententIndex = currententIndex + 1;
	}
	if ((current != NULL) && (currententIndex == atIndex))
	{
		old=current->data;

		current->data = value;
		return old;
	}
	return "";
}

bool RecursiveLinkedList::contains(string value)
{
	Node* current = headpointer;

	while (current != NULL)
	{
		if (current->data == value)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

bool RecursiveLinkedList::remove(string value)
{
	Node* current = headpointer;
	Node* prev = NULL;
	while ((current != NULL) && (current->data != value))
	{
		prev = current;
		current = current->next;
	}
	if ((prev == NULL) && (current != NULL))
	{
		headpointer = headpointer->next;
		delete current;
		current = NULL;
		size1 = size1 - 1;
		return true;
	}
	else if (current != NULL)
	{
		prev->next = current->next;
		delete current;
		current = NULL;
		size1 = size1 - 1;
		return true;
	}
	else
	{
		return false;
	}
}

int RecursiveLinkedList::indexOf(string value)
{
	Node* current = headpointer;
	if(headpointer == NULL)
	{
		return -1;
	}
	else
	{
		for(int i=0; i<size1; i++)
		{
			if(current->data == value)
			{
				return i;
			}
			current=current->next;
		}

	}
	return -1;
}

int RecursiveLinkedList::lastIndexOf(string value)
{
	Node *current = headpointer;
	int storage = -1;
	for(int i=0; i<size1; i++)
	{
		if (current->data == value)
		{
			storage = i;
		}
		current=current->next;
	}
	return storage;

}
