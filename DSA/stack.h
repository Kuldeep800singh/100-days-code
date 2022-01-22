/********************************************************/
/*														*/
/*                     Stacks							*/
/*														*/
/********************************************************/
#include"linkedlist.h"

/*----------Class and structure declaration------------*/
template <typename StackDataType>
class Stack{
private:
	LinkedList<StackDataType> stack;
	int maxSize;
public:
	//Counstructor for the stack to setting its size
	Stack(int size = 10){
		maxSize = size;	
	}
	

	//This function is for inserting element at end of linked list
	int push(StackDataType item){
		if(stack.getSize() == maxSize){
			return -1;
		}	
		stack.addItem(item,0);
		return stack.getSize();
	}

	//This function is for the removing of the element at the end
	StackDataType pop(){
		return stack.remove(0);
	}	
	
	//This function return the data at the top of stack	
	StackDataType peek(){
		return stack.getItem(0);
	}
	
	//It will update the size of the stack
	void setMaxSize(int size){
		if(size < 0)
			return;
		//if size given is greater that current it will simply set to new size
		if(size >= maxSize || size >= stack.getSize()){
			maxSize = size;
			return;
		}
				
		int count = stack.getSize();
		//for removing element if stack size decrease more that allocated linked list
		while(count!=size){
			pop();
			count--;	
		}		
	}
	
	//for getting current stack size
	int getSize(){
		return stack.getSize();
	}
	//for getting the maxSize of the stack
	int getMaxSize(){
		return maxSize;
	}

	// checking if stack is full or not
	bool isFull(){
		return maxSize == stack.getSize();
	}

	//For checking if stack is empty or not
	bool isEmpty(){
		return stack.getSize()==0;
	}	
};
