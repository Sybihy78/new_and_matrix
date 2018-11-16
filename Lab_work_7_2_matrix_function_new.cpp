#include <iostream>
#include <ctime>


int** createArr(const int a, const int b) {
	int** ptr_arr = new int*[a];
	for (int i = 0; i < a; ++i) {
		ptr_arr[i] = new int[b];
	}

	return ptr_arr;
}


void deleteArr(int** ptr_arr, const int a) {
	for (int i = 0; i < a; ++i) {
		delete[] ptr_arr[i];
	}
	delete[] ptr_arr;
	ptr_arr = nullptr;
}


int** fillArr(int** ptr_arr, const int a, const int b) {

	srand(time(NULL));
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			ptr_arr[i][j] = rand() % 10;
		}
	}

	return ptr_arr;
}


int** printArr(int** ptr_arr, const int a, const int b) {

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			std::cout << ptr_arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return ptr_arr;
}


int get_sum_diagonal(int** ptr_arr, const int a, const int b) {
	
	int sum = 0;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			if (i == j) {
				sum += ptr_arr[i][j];
			}
		}
	}

	return sum;
}


int** addColumn(int** ptr_arr, const int a, const int b, const int m) {

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j <= b; ++j) {
			if (j < m) {
				std::cout << ptr_arr[i][j] << " ";
			}
			else if (j > m) {
				std::cout << ptr_arr[i][j - 1] << " ";
			}
			else {
				std::cout << 0 << " ";
			}
		}
		std::cout << std::endl;
	}

	return ptr_arr;
}


int** addString(int** ptr_arr, const int a, const int b, const int n) {
	
	int i = 0;
	for (i = 0; i < n; ++i) {
		for (int j = 0; j < b; ++j) {
			std::cout << ptr_arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	if ( i == n) {
		for (int j = 0; j < b; ++j) {
			std::cout << 0 << " ";
		}
		std::cout << std::endl;
	}
	for (i = n + 1; i <= a; ++i) {
		for (int j = 0; j < b; ++j) {
			std::cout << ptr_arr[i - 1][j] << " ";
		}
		std::cout << std::endl;
	}
	return ptr_arr;
}


int main() {

	std::cout << "Enter number of strings \t";
	int a = 0;
	std::cin >> a;
	std::cout << std::endl;
	std::cout << "Enter number of columns \t";
	int b = 0;
	std::cin >> b;
	std::cout << std::endl;

	int** ptr = createArr(a, b);
	fillArr(ptr, a, b);
	printArr(ptr, a, b);
	
	std::cout << get_sum_diagonal(ptr, a, b) << std::endl;
	
	std::cout << "Enter number of column what do you want to add \t";
	int column_number = 0;
	std::cin >> column_number;
	std::cout << std::endl;

	addColumn(ptr, a, b, column_number);
	
	std::cout << "Enter number of string what do you want to add \t";
	int string_number = 0;
	std::cin >> string_number;
	std::cout << std::endl;
	
	addString(ptr, a, b, string_number);
	
	deleteArr(ptr, a);
	
	system("pause");
	return 0;
}

