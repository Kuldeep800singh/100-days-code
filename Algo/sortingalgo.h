/********************************************************************/
/*																	*/
/*																	*/
/*						Sorting Algorithm							*/
/*																	*/
/*																	*/
/********************************************************************/


//Bubble sort
//Algorithm 
//---1.For each element in list compare them
//---2.if element is not sorted acording to condition swap them
//
//It's time complexity is O(n^2)
void bubble_sort(std::vector<int>& arr){
	int temp;
	for(int i=0; i < arr.size()-1; i++){
		bool swapped = false;
		for(int j=0; j < arr.size()-1; j++){
			if(arr[j] > arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1] = temp;
				swapped = true;
			}
		}
		if(!swapped){
			break;
		}
	}	
}


//Insertion sort
void insertion_sort(std::vector<int>& arr){
	int temp = arr[0];
	int currentPos;
	for(int i = 1; i < arr.size(); i++){
		temp = arr[i];
		currentPos = i;

		while( currentPos > 0 && arr[currentPos-1] > temp){
			arr[currentPos] = arr[currentPos-1];
			currentPos--;
		}

		if(currentPos != i){
			arr[currentPos] = temp;
		}
	}
}


//Selection sort
void selection_sort(std::vector<int>& arr){
	int swapIndex=0;
	for (int i=0; i < arr.size()-1; i++){
		swapIndex = i;
		for(int j=i+1; j < arr.size(); j++){
			if(arr[j] < arr[swapIndex])
				swapIndex = j;
		}
		if(swapIndex != i){
			int temp = arr[i];
			arr[i] = arr[swapIndex];
			arr[swapIndex] = temp;
		}
	}
}



