#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


class Node {
public:
	int data;
	Node* next;
	Node(int d)
	{
		this->data = d;
		this->next = NULL;
	}
};


void insertAtFront(Node* &head , int data)
{
	Node* newNode =  new Node(data);
	if (head == NULL)
	{
		head = newNode;
		return;
	}

	newNode -> next = head;
	head = newNode;
}


void display(Node* &head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp -> data << "->";
		temp = temp -> next;
	}
	cout << endl << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	// _________________________________________
	//  INSERT AT FRONT OF LINKED LIST
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


	Node* head = NULL;
	insertAtFront(head , 54);
	insertAtFront(head, 45);
	insertAtFront(head, 5);
	display(head);



	return 0 ;
}