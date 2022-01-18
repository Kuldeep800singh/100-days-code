#include<iostream>
using namespace std;

void traverseArray(int * array,int len);
void deleteArrElement(int * arr, int len,int indexOfDel);
int searchArrElement(int *arr, int len, int element);
void updateArrElement(int *arr, int index,int newElement);
int main(){
	//-------------Array Operations--------------//
	int arr[]={10,20,30,40,50}; //Array Declaration
	
	//Travarsing:-Itrating all the elements
	cout<<"Travarsing Array:"<<endl;
	for ( int i =0; i < sizeof(arr)/4; i++){
		cout<<"\t"<<arr[i]<<endl;
	}
	
	
	//Insertion:-Adds an element at the given index
	int *arr1=new int[10];
	int arrIndex,arrValue;
	cout<<"\nInserting Array"<<endl;
	for( int i=0; i<10;i++){
		cin>>arr1[i];
	}
	cout<<"Element in arr1 are"<<endl;
	traverseArray(arr1,10);

	cout<<"Enter index to insert element"<<endl;
	cin >> arrIndex;
	cout<<"Enter element value"<<endl;
	cin >> arrValue;
	
	int *arr2=new int[11];//here we can use n a variable to maintain size for start
	bool inserted=false;
	for(int i=0; i<11;i++){
		if(i == arrIndex){
			arr2[i]=arrValue;
			inserted=true;
		}else{
			arr2[i]=arr1[inserted?i-1:i];
		}
	}
	arr1 = arr2;
	traverseArray(arr1,11);
	
	//Deleting Element in array
	cout<<"\nDeleting Element"<<endl;
	deleteArrElement(arr1,11,5);
	traverseArray(arr1,10);

	//Searching Element in array
	cout<<"\nSearch element"<<endl;
	cout<<"-1 means Not Found"<<endl;
	cout<<"Element found at:"<<searchArrElement(arr1,10,2)<<endl;
	
	//Updateting element in array
	cout<<"\nUpdate element"<<endl;
	updateArrElement(arr1,5,2000);
	traverseArray(arr1,10);
}


void traverseArray(int * array, int len){
	for(int i = 0; i<len;i++){
		cout<<array[i]<<',';
	}
	cout<<endl;
}

void deleteArrElement(int * arr, int len,int indexOfDel){
	bool deleted=false;
	for(int i=0; i<len-1; i++){
		if(i==indexOfDel || deleted){
			deleted=true;
			arr[i]=arr[i+1];
		}
	}
}

int searchArrElement(int *arr, int len, int element){
	for(int i=0; i<len; i++){
		if(arr[i]==element){
			return i;
		}
	}
	return -1;
}


void updateArrElement(int *arr, int index,int newElement){
	arr[index]=newElement;
}
