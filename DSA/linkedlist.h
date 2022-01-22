/********************************************************/
/*														*/
/*                     Linked List						*/
/*														*/
/********************************************************/
/*----------Class and structure declaration------------*/
#include<stdexcept>

template <typename LinkedListDataType>
class LinkedList{
private:
	//structure for a node of singly linked list
	struct Node{
		LinkedListDataType data;
		Node *next = nullptr;
	};		
	
	//Variables
	Node * headNode=nullptr;
	int size=0;

public:	
	//Constructor for initilization
	LinkedList(){
			headNode=nullptr;
			size=0;
	}

	//Return the size of the array
	int getSize(){
		return size;
	}
	
	
	//This function for inserting data at specific index
	//Algorithm:
	//---1.Check if index provided is valid
	//---2.Copy the pointer of linkedList Node->next at index
	//---3.Change index Node->next to newNode and set newNode->next to copyed next
	//---4.Increse size
	//
	//index = -1 so that it set the index to size of array and append to it end
	int addItem(LinkedListDataType item, int index=-1){
		if(index==-1)
			index = size;

		if(index >= 0 && index <= size){
			if(index==0){
				struct Node *currentNode = new struct Node;
				currentNode->data = item;
				currentNode->next = headNode;
				headNode = currentNode;
			}
			else {
				int count=0;
				struct Node *lastNode = headNode;
				struct Node *newNode = new struct Node;
				
				while(count != index-1){
					lastNode = lastNode->next;
					count+=1;
				}
				
				newNode->data = item;
				newNode->next = lastNode->next;
				lastNode->next = newNode;
			}
			size+=1;
			return index;
		}
		return -1;
	}

	//Deleteing item from item
	//
	//Algorithm:
	//---1.find the previous node to delete node
	//---2.set previeous node->next to deleteNode->next
	//---3.decrease the size - 1
	LinkedListDataType remove(int index=-1){
		if(index == -1)
			index = size-1;	
		if(size == 0)
			return headNode->data;
		if(index>=0 && index<=size-1){
			struct Node * currentNode = headNode,*deletingNode;
			int count=0;
			LinkedListDataType data;
			if(count==index){
				LinkedListDataType data = headNode->data;
				headNode = headNode->next;
				size-=1;
				return data;
			}
			while (count != index-1){
				currentNode = currentNode->next;
				count+=1;
			}
			deletingNode = currentNode->next;
			data = deletingNode->data;
			currentNode->next = currentNode->next->next;
			size-=1;
			
			return data;
		}
		return -1;
	}

	//Deleting item from start using remove function	
	int pop(){
		return remove(0);
	}

	//Searching Value in linked List
	//Algorithm:
	//---1.First start form head node check it data to value
	//---2.go to next node and check its value
	//---3.if value found then return it else say not fount go until end
	//O(n) is its time complexity
	int search(LinkedListDataType value){
		struct Node *currentNode = headNode;
		for(int i=0; i<size; i++){
			if(currentNode->data == value){
				return i;
			}
			currentNode = currentNode->next;
		}
		return -1;
	}
	
	//Function for getting the data at specific index
	//Algorithm
	//---1.Iterate the linked list until index
	LinkedListDataType getItem(int index){
		//LinkedListDataType data = LinkedListDataType;
		LinkedListDataType data;
		if (size == 0){
			return data;
		}
		if (index >= size-1 && index < 0)
			throw std::invalid_argument("Stack index value is not correct");
		struct Node *iterateNode = headNode;
		int count=0;
		while(count != index){
			iterateNode = iterateNode->next;
		}
		return iterateNode->data;	

	}
	
	//For printing all data out also traversing
	void coutData(){
		struct Node * lastNode=headNode;
		if(size==0){
			std::cout << "Size: " << size<<std::endl;
			return;
		}
		do{
			std::cout << lastNode->data<< std::endl;	
			lastNode = lastNode->next;	
		}while(lastNode!=nullptr);
		std::cout << "Size: " << size<<std::endl;
	}
};

