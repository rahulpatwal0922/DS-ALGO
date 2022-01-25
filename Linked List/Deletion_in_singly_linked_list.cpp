#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

class Node {
public:
	int data;
	Node * next;

	Node(int d) {
		this -> data = d;
		this -> next = NULL;
	}

	~Node()
	{
		int value = this -> data;
		cout << "memory is free for node with data " << value << endl;
	}
};

void deleteNode(Node*& head , int pos)
{
	// here I consider positioning start form 1
	// pos ==1  means first node

	if (pos == 1)
	{
		Node* temp = head;
		head = head -> next;
		temp->next = NULL;
		delete(temp);
		return;
	}

	// delete of node other than the first node
	Node* curr = head;
	Node* prev = NULL;

	int cnt = 1;
	while (cnt < pos)
	{
		prev = curr;
		curr = curr -> next;
		cnt += 1;
	}

	prev -> next = curr -> next;
	curr -> next = NULL;
	delete(curr);
}

void print(Node* & head)
{
	Node* temp = head ;
	while (temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	Node* head = new Node(5);
	Node* node1 = new Node(58);
	Node* node2 = new Node(4);
	Node* node3 = new Node(29);

	head -> next = node1;
	node1 -> next = node2;
	node2 -> next = node3;

	print(head);
	deleteNode(head, 1);
	print(head);


	return 0 ;
}