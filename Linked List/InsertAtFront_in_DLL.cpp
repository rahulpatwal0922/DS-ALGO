#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

class Node {
public:
	int data;
	Node *next, *prev;

	Node(int d)
	{
		this -> data = d;
		this -> next = NULL;
		this -> prev = NULL;
	}

};

void print( Node* & head )
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp-> data << " ";
		temp = temp-> next;
	}
	cout << endl;
}

void insertAtHead(Node* &head , int data)
{
	// create a node
	Node* newNode = new Node(data);

	if (head == NULL)
	{
		head = newNode;
		return;
	}

	newNode -> next = head;
	head -> prev = newNode;

	head = newNode;

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	Node* head = new Node(4);
	insertAtHead(head , 45);
	insertAtHead(head , 23);
	insertAtHead(head , 99);
	insertAtHead(head , 12);
	print(head);
	return 0 ;
}