#include <iostream>
using namespace std;
const int row_size = 5;
const int col_size = 4;
int add_element(int[row_size][col_size]);
int view_massive(int[row_size][col_size]);
int main() {
	int massive[row_size][col_size];
	add_element(massive);
	view_massive(massive);
	return 0;
}
int add_element(int mas[row_size][col_size]) {		//	Заполняем двумерный массив
	int i = 0;
	cout << "Write element's of massive:" << endl;
	for (int j = 0;j < col_size;j++) {
		if (j == col_size - 1 && i < row_size-1) {		//	Если последний элемент в строке и не последняя строка
			cout << "Element " << j << " row " << i << ": ";
			cin >> mas[i][j];		//	Вводим последний элемент
			i++;		//	Переходим на новую строку
			for (j;j > 0;j--) {		//	Начинаем заполнять элементы строки в обратном порядке
				cout << "Element " << j << " row " << i << ": ";
				cin >> mas[i][j];
			}
			cout << "Element " << j << " row " << i << ": ";		//	Вводим первый элемент строки
			cin >> mas[i][j];
			j--;		//	Это необходимо, чтобы счет начался с первого элемента
			i++;		//	Переходим на новую строку
		}
		else {
			cout << "Element " << j << " row " << i << ": ";
			cin >> mas[i][j];
		}
	}
	return 0;
}
int view_massive(int mas[row_size][col_size]) {		//	Выводим массив
	cout << "\n\n\nMassive:\n";
	for (int i = 0;i < row_size;i++) {
		for (int j = 0;j < col_size;j++) {
			cout << mas[i][j]<<"  ";
		}
		cout << endl;
	}
	return 0;
}