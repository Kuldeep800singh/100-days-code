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


///Merge Sort
//It based on divide and concure algorithm
std::vector<int> merge(std::vector<int> arr1,std::vector<int> arr2){
	std::vector<int> merged;
	int i=0,j=0;

	std::cout << "Array 1" <<std::endl;
	for(int i=0; i< arr1.size(); i++)
		std::cout << arr1[i] << std::endl;
	
	std::cout << "Array 2" <<std::endl;
	for(int i=0; i< arr2.size(); i++)
		std::cout << arr2[i] << std::endl;	
	std::cout<< "Merged " << arr1.size() << " " << arr2.size()<< std::endl;
	std::cout << "Firt" << arr1[0] << " " << arr2[0] << std::endl;
	while(i!=-1 || j!=-1){
		if(j!=-1 && arr1[i!=-1?i:arr1.size()-1] >= arr2[j]){
			merged.push_back(arr2[j]);
			j++;
		}else{
			std::cout << "Array : " << arr1[i] << std::endl;
			merged.push_back(20);
			//i++;
		}

	//	else if(i!=-1 && arr1[i] <= arr2[j!=-1?j:arr2.size()-1]){
	//		merged.push_back(arr1[i]);
	//		i++;
	//	}

		if(j>=arr2.size())
			j=-1;
		if(i>=arr1.size())
			i=-1;
	}

	std::cout << std::endl;	
	for(int el: merged){
		std::cout<< " " << el;
	}
	std::cout << std::endl;	
	return merged;

}
std::vector<int> merge_sort(std::vector<int> arr){	
	
	std::vector<int> result;
	if(arr.size()<=i2){
		result.push_back(arr[0]);
		return result;
	}

	std::vector<int> firstHalf(arr.begin(),arr.begin()+(int)(arr.size()/2));
	std::vector<int> secondHalf(arr.begin()+(int)(arr.size()/2), arr.end());
	
	for(int first:firstHalf){
		std::cout << first << " ";
	}
	
	std::cout << " S:";
	
	for(int first:secondHalf){
		std::cout << first << " ";
	}
	std::cout << std::endl;	
	std::cout << "Ending "<< std::endl;
	return merge(merge_sort(firstHalf),merge_sort(secondHalf));
}




