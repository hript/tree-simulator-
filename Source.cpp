#include <iostream> 
#include <Windows.h>
#include <string>

#define DAYS_IN_MONTH 31
#define DAYS_IN_YEAR 372

using namespace std;

class Date {
public:
	int day;
	int month;
	int year;
	int prevYear;
	int prevDay;
	int prevMonth;
	int temp;

    Date() {
		day = 1;
		month = 1;
		year = 2001;
		prevYear = year;
		prevDay = day;
		prevMonth = month;
		temp = 0;
	}

	void check() {
		day = 100;
	}

	void temperature() {

		if (prevMonth == 12 || prevMonth == 1) {
			temp = (-rand() % 15);
			cout << "ok";
		}
		else if (prevMonth >= 10) {
			temp = rand() % 10;
		}
		else if (prevMonth >= 6) {
			temp = rand() % 30 + 20;
		}
		else if (prevMonth >= 4) {
			temp = rand() % 25 + 10;
		}
		else {
			temp = rand() % 10;
		}

		/*if (prevMonth >= 4 && prevMonth <= 5) {
			
		}
		if (prevMonth >= 6 && prevMonth <= 9) {
			
		}
		if (prevMonth >= 2 && prevMonth <= 3) {
			
		}
		if (prevMonth == 12 || prevMonth == 1) {
			
		}
		if (prevMonth >= 10 && prevMonth <= 11) {
			
		}*/

	}
};

class Tree {
public:
	int countOfLeaves;
	int height;
	int fruit;
	int age;
	//bool isAlive;
	//int pointsOfHealth;
	Tree() {
		countOfLeaves = 0;

		height = 0;
		fruit = 0;
		age = 0;
		//isAlive = true;
		//pointsOfHealth = 3;
	}

	void leavesCounter(Date* date) {

		if (date->prevMonth >= 4 && date->prevMonth <= 7 && date->temp >= 20) {
			if (height >= 100 && countOfLeaves < height * 10) {
				countOfLeaves += 20;
			}
			if (height > 20 && countOfLeaves < height * 5) {
				countOfLeaves += 10;
			}
		}
		else if (date->prevMonth >= 9 || date->prevMonth <= 3) {
			countOfLeaves -= rand() % 30 + 10;
			if ( countOfLeaves < 0) {
				countOfLeaves = 0;
			}
		}
	}

	void heightCounter(Date date) {
		if (date.prevMonth >= 4 && date.prevMonth <= 9 && date.temp >= 20) {
			height += 5;
		}
	}

	void fruits(Date date) {
		if (date.prevMonth >= 7 && date.prevMonth <= 8 && date.temp >= 20) {
			if (height >= 100 && fruit < height / 10) {
				fruit += 3;
			}
		}
		if (date.prevMonth >= 9 || date.prevMonth <= 3) {
			if (fruit > 0) {
				fruit -= 3;
			}
		}
	}
	
	/*void ageCounter(Date date) {
		if (date.prevYear != date.year && date.month >= 5 && date.day >= 1) {
			age += 1;
			date.prevYear = date.year;
		}
	}*/
};

string lit[] = {"Jan", "Feb", "Mart", "April", "May", "Jun", "July", "Augh", "Sept", "Oct", "Nov", "Dec"};

int main() {

	Date date;
	Tree tree;


	while (1) {
		system("cls");

		date.temperature();

		cout << "Today is " << date.day << "." << lit[date.month - 1] << "." << date.year << endl;
		cout << "Temperature: " << date.temp << endl;
		cout << "Count of leaves: " << tree.countOfLeaves << endl;
		cout << "Height: " << tree.height << endl;
		cout << "Fruits: " << tree.fruit << endl;
		cout << "Age: " << tree.age << endl << endl;

		cout << "Skip days" << endl;
		int skip;
		cin >> skip;

		date.prevDay = date.day;
		date.prevMonth = date.month;
		date.prevYear = date.year;
		date.year += (skip + date.day + date.month * DAYS_IN_MONTH) / DAYS_IN_YEAR;
		date.month = (skip + date.day + date.month * DAYS_IN_MONTH) % DAYS_IN_YEAR / DAYS_IN_MONTH % 12 ;
		date.day = (skip + date.day + date.month * DAYS_IN_MONTH - 1) % DAYS_IN_YEAR % DAYS_IN_MONTH + 1;

		for (int i = 1; i <= skip; i++) {
			date.prevDay = (date.prevDay + 1) % DAYS_IN_MONTH + 1;
			if (date.prevDay == 1) {
				date.prevMonth = (date.prevMonth + 1) % DAYS_IN_MONTH + 1;
			}
			if (date.prevDay == 1 && date.prevMonth == 1) {
				date.prevYear += 1;
			}

			date.temperature();
			tree.leavesCounter(&date);
			tree.heightCounter(date);
			tree.fruits(date);
		}
	}
	return 0;
}