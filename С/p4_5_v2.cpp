#include <iostream>
using namespace std;
void data_add(char[], int);
void encrip_discrip_str(char[], int, int, int);
int main() {
	const int size_str = 100;
	char str[size_str];
	char var;
	int key;
	cout << "Encriptions (1) or discriptions (2)? ";		//	������� ��� ��������� ����������
	cin >> var;
	if (var != '1' && var != '2') {
		cout << "You write don't correction number!";
		return 0;
	}
	else {
		cout << "Write key: ";		//	����������� ����
		cin >> key;
		cout << "Write text: ";
		data_add(str, size_str);
		encrip_discrip_str(str, size_str, var, key);
		cout << "Code: " << str;
		return 0;
	}
}
void data_add(char simb[], int razm) {		//	��������� ���������� ������
	for (int i = 0; i <= 1; i++) {
		cin.getline(simb, razm);
	}
}
void encrip_discrip_str(char simb[], int razm, int ver, int step) {		//	�������/���������
	int i = 0, x = 97, y = 122;
	int dist = y - x + 1;
	while (simb[i] != '\0') {
		if (simb[i] >= x && simb[i] <= y) {		//	���������� ��� ��������, �� ���������� ��������� ���������� �������
			if (ver == '1') {		//	�������
				simb[i] = simb[i] + step;
				if (simb[i] > y) {
					simb[i] = simb[i] - dist;
				}
			}
			else {		//	���������
				simb[i] = simb[i] - step;
				if (simb[i] < x) {
					simb[i] = simb[i] + dist;
				}
			}
			i++;
		}
		else {
			i++;
		}
	}
}