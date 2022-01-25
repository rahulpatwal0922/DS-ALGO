#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

class Node {
public:
	int data;
	Node* next;

	Node(int d) {
		this -> data = d;
		this->next = NULL;
	}
};

void insertAtTail(Node* &head , int d)
{
	// create a new node
	Node* newNode = new Node(d);

	if (head == NULL) {
		head = newNode;
		return ;
	}
	Node* temp = head;

	while (temp->next != NULL) {
		temp = temp -> next;
	}

	temp -> next = newNode;
}


void print(Node* &head)
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp-> data << " ";
		temp = temp-> next;
	}
	cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	Node* head = NULL;

	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	print(head);
	return 0 ;
}