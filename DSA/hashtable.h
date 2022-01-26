
/********************************************************/
/*														*/
/*                     	Hash Table						*/
/*														*/
/********************************************************/
/*----------Class and structure declaration------------*/
//Same as map in standard library in c++
class HashTable{
private:
	struct DataItem{
		int key = 0;
		int value;
	};
	
	std::vector<struct DataItem> table;
	int maxSize;

	int hashCode(int key){
		return key % maxSize;
	}
public:
	HashTable(int maxHashTableSize = 20){
		maxSize = maxHashTableSize;
		DataItem initialData;
		initialData.key = 0;
		for(int i = 0; i < maxSize; i++)
			table.push_back(initialData);	
	}


	//Inserting Element in hashTable
	//Algorithm
	//---1.Find a hashCode for indexing key
	//---2.Find a other index if the one index is not free
	void insert(int key, int value){
		int hashIndex = hashCode(key);
		while(table[hashIndex].key != 0 && table[hashIndex].key != -1){
			hashIndex++;
			hashIndex %= maxSize;
		}
		table[hashIndex].key = key;
		table[hashIndex].value = value;
		std::cout << "Hash : " << table[hashIndex].key << " " << table[hashIndex].value<< std::endl;
		
	}


	//Searhching Element
	int search(int key){
		int hashIndex = hashCode(key);
		while(table[hashIndex].key !=0){
			if(table[hashIndex].key == key)
				return table[hashIndex].value;
			hashIndex++;
			hashIndex %= maxSize;
		}
		return 0;
	}

	//Deleting Element
	int deleteItem(int key){
		int hashIndex = hashCode(key);
		while(table[hashIndex].key != 0){
			if(table[hashIndex].key == key){
				std::cout << "Deleted Hash : " << table[hashIndex].key << " "<< table[hashIndex].value << std::endl;
				table[hashIndex].key = 0;
				table[hashIndex].value = 0;
				return 0;
			}
			hashIndex++;
			hashIndex %=maxSize;
		}
		return -1;
	}

};
