/****************************************************/
/*													*/
/*													*/
/*			    Searching Algorithm					*/
/*													*/
/*													*/
/****************************************************/




//Linear search
//Algorithm:
//---1.check first element and then go if not match go to next utile we find
//
//It's time complexilty is O(n)
template <class SearchingDataType>
int linear_search(std::vector<SearchingDataType>  array,SearchingDataType searchValue){
	int i=0;
	for (;i < array.size(); i++){		
		if(array[i] == searchValue){
			return i;
		}
	}
	return -1;
}


//Binaray Search
//Algorithm
//---1.First find midIndex then
//---2.Check if mid index is equal if not then
//---3.Check if mid index is small than search value if yes 
//------1.Call the function again with the array for mid to end
//---4.Check if mid index is greater than search if yes
//------1.Call the function again with the array for start to mid
template <class SearchingDataType>
int binary_search(std::vector<SearchingDataType> array,SearchingDataType searchValue){

	int midValue = array.size()/2;
	
	//checing for not found value
	if(array.size()<=1 && array[0]!= searchValue)
		return -1;
	//checking if value found at mid
	if(array[midValue] == searchValue)
		return midValue;
	
	int result = 0;
	
	///Check if current mid value is greater than search value 
	if (array[midValue] > searchValue){
		std::cout<< "Before " << midValue <<" "<< array[midValue]<< std::endl;
		result = binary_search(std::vector<SearchingDataType>(array.begin(), array.end()-midValue),searchValue);	
		
		//returning index of value
		return result;
	}

	// Cecking if current mid value is less than search value
	else if ( array[midValue] < searchValue){
		std::cout<<"After "<< midValue << " " << array[midValue]<< std::endl;
		result =  binary_search(std::vector<SearchingDataType>(array.begin()+midValue, array.end()),searchValue);	
		if(result == -1)
			return result;
		//returning index of value
		return midValue + result;
	}
	return 0;

}
