/********************************************************/
/*														*/
/*                     Queue							*/
/*														*/
/********************************************************/
#include"linkedlist.h"

/*----------Class and structure declaration------------*/
template <typename QueueDataType>
class Queue{
private:
	LinkedList<QueueDataType> queue;
	int maxSize;
public:
	//Counstructor for the queue to setting its size
	Queue(int size = 10){
		maxSize = size;	
	}


	//Add element in queue in using below function
	//Algorithm:
	//---1.Add element at the end of linked list just
	//
	//Output:
	// -1 - queue is full unable to insert element
	//
	//This operation take O(n) time complexity n is size of linked list
	int enqueue(QueueDataType item){
		if(queue.getSize()==maxSize)
			return -1;
		queue.addItem(item);
		return 0;
	}

	//This function is used to remove element for the queue
	//Algroithm:
	//---1.Remove element at start of queue
	//
	//Output:
	// return the poped value
	//It is an O(1) time complexit means constant as it remove start value
	int dequeue(){
		return queue.remove(0); 
	}
	
	
	//This function return the data at the top of stack	
	QueueDataType peek(){
		return queue.getItem(0);
	}

	
	//It will update the size of the queue
	void setMaxSize(int size){
		if(size < 0)
			return;
		//if size given is greater that current it will simply set to new size
		if(size >= maxSize || size >= queue.getSize()){
			maxSize = size;
			return;
		}
				
		int count = queue.getSize();
		//for removing element if queue size decrease more that allocated linked list
		while(count!=size){
			dequeue();	
			count--;	
		}		
	}

	//for getting current  size
	int getSize(){
		return queue.getSize();
	}
	
	//for getting the maxSize of the queue 
	int getMaxSize(){
		return maxSize;
	}
	
	// checking if queue is full or not
	bool isFull(){
		return maxSize == queue.getSize();
	}

	//For checking if queue is empty or not
	bool isEmpty(){
		return queue.getSize()==0;
	}	

};
