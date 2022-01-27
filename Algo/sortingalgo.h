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

