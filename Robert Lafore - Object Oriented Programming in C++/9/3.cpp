#include <iostream>
#include <string>
using namespace std;

class Sales {

private:
	float sales[3];

public:
	void getData() {
		for (int i = 0; i < 3; i++) {
			cout << "Enter sales for " << i + 1 << " month: ";
			cin >> sales[i];
		}
		cout << endl;
	}

	void putData() {
		for (int i = 0; i < 3; i++)
			cout << i + 1 << " month sales: " << sales[i] << endl;
		cout << endl;
	}

};

class Publication {

private:
	string name;
	float price;

public:
	void getData() {
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter price: ";
		cin >> price;
	}

	void putData() {
		cout << "Book: " << name << endl;
		cout << "Price: " << price << endl;
	}

};

class Book : private Publication, private Sales {

private:
	int pages;

public:
	void getData() {
		this->Publication::getData();
		cout << "Enter pages: ";
		cin >> pages;
		this->Sales::getData();
	}

	void putData() {
		this->Publication::putData();
		cout << "Pages: " << pages << endl;
		this->Sales::putData();
	}

};

class Tape : private Publication, private Sales {

private:
	float time;

public:
	void getData() {
		this->Publication::getData();
		cout << "Enter time (in minutes): ";
		cin >> time;
		this->Sales::getData();
	}

	void putData() {
		this->Publication::putData();
		cout << "Time (in minutes): " << time << endl;
		this->Sales::putData();
	}

};


int main() {

	char answer;

	do {

		char type;
		cout << "Enter 'b' for book and 't' for tape: ";
		cin >> type;

		if (type == 'b') {
			Book b;
			b.getData(); cout << endl;
			b.putData(); cout << endl;
		}
		else if (type == 't') {
			Tape t;
			t.getData(); cout << endl;
			t.putData(); cout << endl;
		}
		else
			cout << "Wrong input" << endl;

		cout << "Do you want to continue? (y / n):";
		cin >> answer;

	} while (answer == 'y');

	return 0;

}
