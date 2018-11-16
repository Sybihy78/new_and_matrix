#include <iostream>


void createArray();
void printArray(int* arr, const int size);


int main() {
	
	createArray();

	system("pause");
	return 0;
}


void createArray() {

	int sz = 1;
	int* ptr_arr = new int[sz];
	std::cout << "Enter number" << std::endl;
	int tmp = 0;
	std::cin >> tmp;
	ptr_arr[0] = tmp;
	
	while (true) {
		std::cout << "Enter number" << std::endl;
		std::cin >> tmp;
		if (tmp < 0) {
			break;
		}
		int* new_ptr = new int[sz + 1];
		
		int* ptrN = new_ptr;
		for (int* ptr = ptr_arr; ptr != ptr_arr + sz; ++ptr) {
			*ptrN = *ptr;
			++ptrN;
		}

		new_ptr[sz] = tmp;
		++sz;
		delete[] ptr_arr;
		ptr_arr = new_ptr;
	}

	printArray(ptr_arr, sz);

	int* min_ptr = ptr_arr;
	for (int* ptr = ptr_arr; ptr != ptr_arr + sz; ++ptr) {
		if (*ptr <= *min_ptr) {
			min_ptr = ptr;
		}
	}
	
	int* max_ptr = ptr_arr;
	for (int* ptr = ptr_arr; ptr != ptr_arr + sz; ++ptr) {
		if (*ptr >= *max_ptr) {
			max_ptr = ptr;
		}
	}

	std::cout << "Max element - Min element = ";
	std::cout << *max_ptr << " - " << *min_ptr << " = ";
	std::cout << *max_ptr - *min_ptr << std::endl;

	delete[] ptr_arr;
	ptr_arr = nullptr;
}


void printArray(int* arr, const int size) {
	
	std::cout << "Array:" << std::endl;
	for (int* ptr = arr; ptr != arr + size; ++ptr) {
		std::cout << *ptr << " ";
	}
	std::cout << std::endl;

}