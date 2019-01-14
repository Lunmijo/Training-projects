//Creating a matrix and adding element as a "snake", example: http://uploads.ru/zt5Lp.jpg
#include <iostream>
#include <stdlib.h>

using namespace std;

void main()
{
	int matrix_size;
	int **matrix;
	cout << "Enter the size of a matrix: ";
	cin >> matrix_size;

	matrix = new int *[matrix_size];

	for (int i = 0; i < matrix_size; i++) {
		matrix[i] = new int[matrix_size];
	}

	int  element_value = 1, number_of_elements = 1;
	bool middle = 1;
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {

			if (i % 2 == 0) {
				matrix[i][j] = element_value;
			}
			else {
				matrix[i][matrix_size - j - 1] = element_value;
			}

			number_of_elements--;
			//we need var middle because when we are on the middle of the matrix we should add new numbers on the contrary
			if (element_value == matrix_size) {
				middle = 0;
			}

			if (number_of_elements == 0 && middle == 1) {
				element_value++;
				number_of_elements = element_value;
			} else if (number_of_elements == 0 && middle == 0) {
				element_value--;
				number_of_elements = element_value;
			}

		}

		cout << endl;
	
	}

	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}

	delete[]  matrix;
	
	cin.get();
	cin.get();
	
}
