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
int add_element(int mas[row_size][col_size]) {		//	��������� ��������� ������
	int i = 0;
	cout << "Write element's of massive:" << endl;
	for (int j = 0;j < col_size;j++) {
		if (j == col_size - 1 && i < row_size-1) {		//	���� ��������� ������� � ������ � �� ��������� ������
			cout << "Element " << j << " row " << i << ": ";
			cin >> mas[i][j];		//	������ ��������� �������
			i++;		//	��������� �� ����� ������
			for (j;j > 0;j--) {		//	�������� ��������� �������� ������ � �������� �������
				cout << "Element " << j << " row " << i << ": ";
				cin >> mas[i][j];
			}
			cout << "Element " << j << " row " << i << ": ";		//	������ ������ ������� ������
			cin >> mas[i][j];
			j--;		//	��� ����������, ����� ���� ������� � ������� ��������
			i++;		//	��������� �� ����� ������
		}
		else {
			cout << "Element " << j << " row " << i << ": ";
			cin >> mas[i][j];
		}
	}
	return 0;
}
int view_massive(int mas[row_size][col_size]) {		//	������� ������
	cout << "\n\n\nMassive:\n";
	for (int i = 0;i < row_size;i++) {
		for (int j = 0;j < col_size;j++) {
			cout << mas[i][j]<<"  ";
		}
		cout << endl;
	}
	return 0;
}