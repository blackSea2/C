#include <iostream>
using namespace std;
const int row_size = 10;
const int col_size = 10;
char sort(string[row_size][col_size], char[2][8]);
int main() {
	string massive[row_size][col_size]{ {" 8 ", "   "," E "," H "," S "," W ", " Q ", " S ", "   ", " E "},
		{" 7 ", "   "," P ", " P ", " P ", " P "," P ", "   ", " P ", "   "},
		{" 6 ", "   ","   ", "   ","   ", "   ", "   ", " H ","   ", "   "},
		{" 5 ", "   ","   ", "   "," S ", "   ", "   ", " P ","   ", " P "},
		{" 4 ", "   ","   ", "   ","   ", "   ", "   ", "   ","   ", "   "},
		{" 3 ", "   ","   ", " P ","   ", "   ", "   ", "   ","   ", "   "},
		{" 2 ", "   "," P ", "   ", " P ", " P "," P ", " P ", " P ", " P "},
		{" 1 ", "   "," E "," H ","   "," W ", " Q ", " S ", " H ", " E "},
		{"   ", "   ","   ", "   ","   ", "   ", "   ", "   ","   ", "   "},
		{"   ", "   "," A ", " B "," C ", " D ", " E ", " F "," G ", " H "} };		//	Доска с фигурами и разметкой
	char res_massive[2][8]{ {'A','B','C','D','E','F','G','H'},
		{'8','7','6','5','4','3','2','1'} };		//	Массив используемый для вывода ходов
	for (int i = 0; i < row_size; i++) {		//	Вывод доски на экран
		for (int j = 0; j < col_size; j++) {
			cout << massive[i][j];
		}
		cout << endl;
	}
	cout << endl;
	sort(massive, res_massive);
	return 0;
}
char sort(string mas[row_size][col_size], char res[2][8]) {		//	Поиск доступных для ладьи ходов
	int i = 4, j = 3, b = 1, n = i - 2;
	cout << "\nOpen steps for S (C5):" << endl;
	for (int a = 1; (i + a < 10 && i - a >= 2) && (j + b < 8 && j - b >= 0); a++) {		/*	Условие нахождения фигуры на доске
																						а также условия передвижения по диагонали*/
		for (int u = 0; u < 1; u++) {
			if (mas[j + b][i + a] == "   ") {		//	Ищем сободные клетки
				cout << res[0][n + a] << res[1][j + b] << endl;
			}
		}
		for (int l = 0; l < 1; l++) {
			if (mas[j + b][i - a] == "   ") {		//	Ищем сободные клетки
				cout << res[0][n - a] << res[1][j + b] << endl;
			}
		}
		for (int d = 0; d < 1; d++) {
			if (mas[j - b][i - a] == "   " || mas[j - b][i - a] == " P ") {	//	Ищем сободные клетки и клетки с пешками(для данного случая)
				cout << res[0][n - a] << res[1][j - b] << endl;
			}
		}
		for (int r = 0; r < 1; r++) {
			if (mas[j - b][i + a] == "   " || mas[j - b][i + a] == " P ") {	//	Ищем сободные клетки и клетки с пешками(для данного случая)
				cout << res[0][n + a] << res[1][j - b] << endl;
			}
		}
		b++;
	}
	return 0;
}