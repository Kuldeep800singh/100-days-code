#include<iostream>

using namespace std;

struct Node{
	int data;
	Node *next= nullptr;
};

int insertNode(struct Node *headNode,int insData);
int deleteNode(struct Node *headNode,int index);

int main(){
	struct Node myNode;
	myNode.data=100;
	cout<<myNode.data<<endl;
	insertNode(&myNode,20);	
}

int insertNode(struct Node *headNode,int insData){
	struct Node *newNode, *lastNode;
	newNode->data=insData;
	lastNode = headNode;
	while(lastNode->next!=nullptr){
		lastNode = lastNode->next;	
	}
	lastNode->next = newNode;
	cout<<"Data inserted Successfuly"<<endl;
	return 1;
}
int deleteNode(struct Node *headNode,int index){
}
