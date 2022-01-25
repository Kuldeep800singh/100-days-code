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


//interpolation serach method
//
//It is more optimise that binary search its best time complexity is O(log log n)
//But its worst case complexity is O(n)
//
//Algorithm
//---1.First let take start and end index then find a pos valriable
//---2.The pos variabel give rough idea where the element could be if it is in array
//---3.Formulal for pos = start + ((end-start)/(arr[end]-arr[start]))*(e - arr[start]
//------ e     - represent searching value
//------ start - represent starting index
//------ end   - represent end index of array
//------ arr   - represent the array for serching
//---4.Check if arr[start] == e if yes then return index other change pos to start+1
//---5.Perform this algorthim until you find element or start<=end and arr[start]!=e
//
template <class SearchDataType>
int interpolation_search(std::vector<SearchDataType> arr,
						SearchDataType searchValue){
	
	int start=0, end=arr.size()-1,pos=0;

		
	while(start<=end && searchValue>=arr[start] && searchValue<=arr[end])
	{
		pos=(start+((double)(end-start)/(arr[end]-arr[start]))*(searchValue - arr[start]));
		std::cout << "Start : " << start << "End : " << end << "Pos :" << pos <<std::endl;
		if(arr[pos]==searchValue)
			return pos;
		if(arr[pos] < searchValue)
			start=pos + 1;
		else
			end = pos - 1;
	}
	return -1;
}
