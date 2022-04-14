#include <iostream>
using namespace std;

class Matrix {
private:
	int** matrix_dinamic = new int* [row_size];
public:
	int row_size, col_size;
	void create_matrix();
	int get_operation();
};

int main() {
	Matrix mtx1;
	mtx1.create_matrix();
	mtx1.get_operation();
}

void Matrix::create_matrix() {
	cout << "Write row size matrix: ";
	cin >> row_size;
	cout << "Write col size matrix: ";
	cin >> col_size;
	cout << "Write your matrix " << row_size << "x" << col_size << endl;
	for (int i = 0; i < row_size; i++) {
		matrix_dinamic[i] = new int[col_size];
	}
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			cout << "Write row " << i + 1 << " element " << j + 1 << ": ";
			cin >> matrix_dinamic[i][j];
		}
	}
}

int Matrix::get_operation() {
	Matrix mtx2;
	char operation;
	int a;
	int** result_matrix = new int* [row_size];
	for (int i = 0; i < row_size; i++) {
		result_matrix[i] = new int[mtx2.col_size];
	}
	cout << "Write operation (+, -, *, /): ";
	cin >> operation;
	switch (operation) {
	case '+':
		cout << "Warring!!! Matrix A and B will need balance size!" << endl;
		mtx2.create_matrix();
		if (row_size = mtx2.row_size) {
			if (col_size = mtx2.col_size) {
				for (int i = 0; i < row_size; i++) {
					for (int j = 0; j < col_size; j++) {
						result_matrix[i][j] = matrix_dinamic[i][j] + mtx2.matrix_dinamic[i][j];
					}
				}
				break;
			}
		}
		else {
			cout << "Matrixs don't balance!!!";
			return 0;
		}
		break;
	case '-':
		cout << "Warring!!! Matrix A and B will need balance size!" << endl;
		mtx2.create_matrix();
		if (row_size = mtx2.row_size) {
			if (col_size = mtx2.col_size) {
				for (int i = 0; i < row_size; i++) {
					for (int j = 0; j < col_size; j++) {
						result_matrix[i][j] = matrix_dinamic[i][j] - mtx2.matrix_dinamic[i][j];
					}
				}
				break;
			}
		}
		else {
			cout << "Matrixs don't balance!!!";
			return 0;
		}
		break;
	case '*':
		int select_multiplicator;
		cout << "Select multiplicators (1 - matrix; 2 - number): ";
		cin >> select_multiplicator;
		if (select_multiplicator == 1) {
			cout << "Warring!!! Matrix A and B will need balance row matrix A and col matrix B!" << endl;
			mtx2.create_matrix();
			if (col_size = mtx2.row_size) {
				for (int i = 0; i < row_size; i++) {
					result_matrix[i] = new int[mtx2.col_size];
				}
				for (int i = 0; i < row_size; i++) {
					for (int j = 0; j < mtx2.col_size; j++) {
						int sum_rowAndCol = 0;
						for (int k = 0; k < row_size; k++) {
							sum_rowAndCol += (matrix_dinamic[i][k] * mtx2.matrix_dinamic[k][j]);
						}
						result_matrix[i][j] = sum_rowAndCol;
					}
				}
				break;
			}
			else {
				cout << "Matrixs don't balance row matrix A and col matrix B!!!";
				return 0;
			}
		}
		else if (select_multiplicator == 2) {
			cout << "Write number for multiplication origin's matrix: ";
			cin >> a;
			for (int i = 0; i < row_size; i++) {
				for (int j = 0; j < col_size; j++) {
					result_matrix[i][j] = matrix_dinamic[i][j] * a;
				}
			}
			break;
		}
		break;
	case '/':
		int select_division;
		cout << "Select divisions (1 - matrix; 2 - number): ";
		cin >> select_division;
		if (select_division == 2) {
			cout << "Warring!!! Matrix A and B will need balance row matrix A and col matrix B!" << endl;
			mtx2.create_matrix();
			if (col_size = mtx2.row_size) {
				for (int i = 0; i < row_size; i++) {
					result_matrix[i] = new int[mtx2.col_size];
				}
				for (int i = 0; i < row_size; i++) {
					for (int j = 0; j < mtx2.col_size; j++) {
						int sum_rowAndCol = 0;
						for (int k = 0; k < row_size; k++) {
							sum_rowAndCol += (matrix_dinamic[i][k] / mtx2.matrix_dinamic[k][j]);
						}
						result_matrix[i][j] = sum_rowAndCol;
					}
				}
				break;
			}
			else {
				cout << "Matrixs don't balance row matrix A and col matrix B!!!";
				return 0;
			}
		}
		else if (select_multiplicator == 2) {
			cout << "Write number for division origin's matrix: ";
			cin >> a;
			for (int i = 0; i < row_size; i++) {
				for (int j = 0; j < col_size; j++) {
					result_matrix[i][j] = matrix_dinamic[i][j] * a;
				}
			}
			break;
		}
		break;
	default:
		cout << "You're writed don't right simbol! You need writing: + OR - OR * OR /" << endl;
		return 0;
	}
	cout << endl << "Result matrix:" << endl;
	switch (operation)
	{
	case '*':
	case '/':
		for (int i = 0; i < row_size; i++) {
			cout << endl;
			for (int j = 0; j < mtx2.col_size; j++) {
				if (result_matrix[i][j] >= 0) {
					if (result_matrix[i][j] > 99) {
						cout << result_matrix[i][j] << "  ";
					}
					else if (result_matrix[i][j] > 9) {
						cout << result_matrix[i][j] << "   ";
					}
					else {
						cout << result_matrix[i][j] << "    ";
					}
				}
				else {
					if (result_matrix[i][j] < -99) {
						cout << result_matrix[i][j] << " ";
					}
					else if (result_matrix[i][j] < -9) {
						cout << result_matrix[i][j] << "  ";
					}
					else {
						cout << result_matrix[i][j] << "   ";
					}
				}
			}
		}
		break;

	default:
		for (int i = 0; i < row_size; i++) {
			cout << endl;
			for (int j = 0; j < col_size; j++) {
				if (result_matrix[i][j] >= 0) {
					if (result_matrix[i][j] > 99) {
						cout << result_matrix[i][j] << "  ";
					}
					else if (result_matrix[i][j] > 9) {
						cout << result_matrix[i][j] << "   ";
					}
					else {
						cout << result_matrix[i][j] << "    ";
					}
				}
				else {
					if (result_matrix[i][j] < -99) {
						cout << result_matrix[i][j] << " ";
					}
					else if (result_matrix[i][j] < -9) {
						cout << result_matrix[i][j] << "  ";
					}
					else {
						cout << result_matrix[i][j] << "   ";
					}
				}
			}
		}
	}
	
	for (int i = 0; i < row_size; i++) {
		delete[] matrix_dinamic[i];
	}
	for (int i = 0; i < mtx2.row_size; i++) {
		delete[] mtx2.matrix_dinamic[i];
	}
	for (int i = 0; i < row_size; i++) {
		delete[] result_matrix[i];
	}
}
