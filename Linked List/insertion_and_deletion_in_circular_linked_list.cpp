#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

class Node
{
public:
	int data;
	Node* next;
	Node(int data) {
		this -> data = data;
		this -> next = NULL;
	}
};


void insert(Node* &head , int data)
{
	// create a node
	Node * newNode = new Node(data);


	if (head == NULL)
	{
		head  = newNode;
		newNode -> next = head;
	}
	else
	{
		Node * tail  = head;

		do {
			tail = tail -> next;
		} while (tail -> next != head);

		tail -> next = newNode;
		tail = newNode;
		tail -> next = head;
	}
}



void deleteInCircularLinkedList(Node* &head , int x)
{
	Node* tail = head;

	do {
		tail = tail->next;
	} while (tail -> next != head);

	// Only single node is present in the linked list
	if (head -> next == tail and x == 1)
	{
		Node* temp = head;
		temp-> next = NULL;
		delete temp;
		head = NULL;
	}

	else if (head -> next != NULL and x == 1)
	{
		Node* temp = head ;
		head = head -> next ;
		tail -> next = head;
		temp -> next = NULL;
		delete temp;
	}

	else
	{
		Node* rear = NULL;
		Node* curr = head;

		int pos = 1;
		while (pos < x)
		{
			rear = curr;
			curr = curr -> next;
			pos++;
		}

		if (curr -> next == head)
		{
			Node* temp = curr;
			rear -> next = head ;
			tail = rear;

			temp -> next = NULL;
			delete temp;
		}
		else
		{
			Node* temp = curr;
			rear -> next = curr-> next;
			temp -> next = NULL;
			delete temp;
		}
	}
}




void print( Node* & head)
{
	Node* temp = head;

	do {
		cout << temp-> data << " ";
		temp = temp -> next;
	} while (temp != head);
	cout << endl;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	Node*head = NULL;
	insert(head , 5);
	print(head);
	insert(head , 45);
	print(head);
	insert(head , 23);
	print(head);
	insert(head , 98);
	print(head);
	cout << "Deletion " << endl;
	deleteInCircularLinkedList(head , 3);
	print(head);
	deleteInCircularLinkedList(head , 1);
	print(head);

	return 0 ;
}