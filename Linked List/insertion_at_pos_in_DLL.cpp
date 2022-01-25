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


void insertAtPos(Node* & head, int pos, int data)
{
	// create a node
	Node* newNode = new Node(data);

	if (head == NULL)
	{
		head = newNode;
		return;
	}
	// here I consider positioning start with 1;
	// First node is present at pos 1

	if (pos == 1)
	{
		newNode->next = head;
		head = newNode;
		return;
	}
	int cnt = 1;
	Node* curr = head;

	while (cnt < pos - 1) {
		curr = curr->next;
		cnt++;
	}

	if (curr->next == NULL)
	{
		newNode->prev = curr;
		curr->next = newNode;
		return;
	}

	newNode->next = curr->next;
	newNode->prev = curr;
	curr->next->prev = newNode;
	curr->next = newNode;

}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	Node* head = new Node(4);
	insertAtPos(head, 2, 45);
	insertAtPos(head, 1, 1);
	insertAtPos(head, 4, 100);
	print(head);
	return 0 ;
}