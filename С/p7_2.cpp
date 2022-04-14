#include <iostream>
#include <time.h>
#pragma warning(disable : 4996)
using namespace std;
const int row_size = 5;
const int col_size = 3;
struct now_date {
	int t_year;
	int t_mounth;
	int t_day;
};
struct now_time {
	int t_hour;
	int t_min;
	int t_second;
};
struct user_name {
	string last_name;
	string first_name;
	string patronymic;
};
struct user_mas {
	int number;
	now_date dt;
	now_time tm;
	user_name us;
};
void inpud_date_time(tm*, now_date& d, now_time& t);
void inpud_data(user_name& u);
int main() {
	int i = 0, j = 0;
	user_mas massive[row_size];
	now_date data_day;
	now_time data_time;
	user_name data_user;
	for (i; i < row_size; i++) {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		inpud_data(data_user);
		inpud_date_time(ltm, data_day, data_time);
		massive[i].us = data_user;
		massive[i].number = i + 1;
		massive[i].tm = data_time;
		massive[i].dt = data_day;
	}
	cout << endl;
	for (int a = 0; a < row_size; a++) {
		cout << massive[a].number << "  " << massive[a].tm.t_hour << ":" << massive[a].tm.t_min << ":" << massive[a].tm.t_second << "  " << massive[a].dt.t_day << "." << massive[a].dt.t_mounth << "." << massive[a].dt.t_year << "       " << massive[a].us.last_name << " " << massive[a].us.first_name << " " << massive[a].us.patronymic << endl;
	}
	return 0;
}
void inpud_date_time(tm* lt, now_date& d, now_time& t) {
	d.t_day = lt->tm_mday;
	d.t_mounth = 1 + lt->tm_mon;
	d.t_year = 1900 + lt->tm_year;
	t.t_hour = lt->tm_hour;
	t.t_min = lt->tm_min;
	t.t_second = 1 + lt->tm_sec;
}
void inpud_data(user_name& u) {
	cout << "Write lastname: ";
	cin >> u.last_name;
	cout << "Write firstname: ";
	cin >> u.first_name;
	cout << "Write patronymic: ";
	cin >> u.patronymic;
	cout << endl;
}