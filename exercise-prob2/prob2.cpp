#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip> 
#include <algorithm>
#include <sstream>
using namespace std;

class Student {
public:
	string name;
	string id;
	string department;
	string year;
	string tel;

	Student(string name, string id, string department, string year, string tel) :
		name(name), id(id), department(department), year(year),  tel(tel) {};

};

class Studentlist {
public:
	vector<Student> v;
	void insert();
	void search();
	void sortingoption();
	void exit(const string& filename);
	static bool compareByName(const Student& s1, const Student& s2) {
		return s1.name < s2.name;
	}
	static bool compareById(const Student& s1, const Student& s2) {
		return s1.id < s2.id;
	}
	static bool compareByYear(const Student& s1, const Student& s2) {
		return s1.year < s2.year;
	}
	static bool compareByDepartment(const Student& s1, const Student& s2) {
		return s1.department < s2.department;
	}
	void sortByName() {
		sort(v.begin(), v.end(), compareByName);
	}
	void sortById() {
		sort(v.begin(), v.end(), compareById);
	}
	void sortByYear() {
		sort(v.begin(), v.end(), compareByYear);
	}
	void sortByDepartment() {
		sort(v.begin(), v.end(), compareByDepartment);
	}
};

void Studentlist::insert() {
	string name;
	string id;
	string department;
	string year;
	string tel;
	while (name.empty()) {
		cout << "Name ? ";
		cin.ignore();
		getline(cin,name);
		if (name.empty())
			cout << "Error : name is blank" << endl;
		name = name.substr(0, 15);
	}
	while (id.empty()) {
		cout << "Student ID (10digits) ? ";
		getline(cin, id);
		if (id.empty())
			cout << "Error : name is blank" << endl;
		id = id.substr(0, 10);
		for (Student i : this->v) {
			if (!id.compare(i.id)) {//if the same, error
				cout << "Error : Already inserted" << endl;
				cout << "Student ID (10digits) ? ";
				getline(cin, id);
			}
		}
		
	}
	cout << "Birth Year (4 digits) ? ";
	getline(cin, year);
	year = year.substr(0, 4);
	cout << "Department ? ";
	getline(cin, department);
	cout << "Tel ? ";
	getline(cin, tel);
	tel = tel.substr(0, 12);
	v.push_back(Student(name, id, department, year, tel));
}


 void Studentlist::search() {
	int sc;
	string s;
	cout << "-Search-" << endl;
	cout << "1. Search by name" << endl;
	cout << "2. Search by student ID(10 numbers)" << endl;
	cout << "3. Search by admission year(4 numbers)" << endl;
	cout << "4. Search by department name" << endl;
	cout << "5. List All" << endl;
	cout << ">";
	cin >> sc;
	switch (sc)
	{
	case 1:
		cout << "name keyword?";
		cin >> s;
		cout << setw(15) << left << "Name";
		cout << setw(10) << left << "StudentID";
		cout << setw(20) << left << "Dept";
		cout << setw(11) << left << "Birth Year";
		cout << setw(15) << left << "Tel" << endl;
		for (Student i : this->v) {
			if (!s.compare(i.name)) {// If the same thing exists
				cout << setw(15) << left << i.name;
				cout << setw(10) << left << i.id;
				cout << setw(20) << left << i.department;
				cout << setw(11) << left << i.year;
				cout << setw(15) << left << i.tel << endl;
			}
		}
		break;
	case 2:
		cout << "student ID keyword?";
		cin >> s;
		cout << setw(15) << left << "Name";
		cout << setw(10) << left << "StudentID";
		cout << setw(20) << left << "Dept";
		cout << setw(11) << left << "Birth Year";
		cout << setw(15) << left << "Tel" << endl;
		for (Student i : this->v) {
			if (!s.compare(i.id)) { //If the same thing exists
				cout << setw(15) << left << i.name;
				cout << setw(10) << left << i.id;
				cout << setw(20) << left << i.department;
				cout << setw(11) << left << i.year;
				cout << setw(15) << left << i.tel << endl;
			}
		}
		break;
	case 3:
		cout << "admission year keyword?";
		cin >> s;
		cout << setw(15) << left << "Name";
		cout << setw(10) << left << "StudentID";
		cout << setw(20) << left << "Dept";
		cout << setw(11) << left << "Birth Year";
		cout << setw(15) << left << "Tel" << endl;
		for (Student i : this->v) {
			if (!s.compare(i.year)) {// If the same thing exists
				cout << setw(15) << left << i.name;
				cout << setw(10) << left << i.id;
				cout << setw(20) << left << i.department;
				cout << setw(11) << left << i.year;
				cout << setw(15) << left << i.tel << endl;
			}
		}
		break;
	case 4:
		cout << "Department name keyword?";
		cin >> s;
		cout << setw(15) << left << "Name";
		cout << setw(10) << left << "StudentID";
		cout << setw(20) << left << "Dept";
		cout << setw(11) << left << "Birth Year";
		cout << setw(15) << left << "Tel" << endl;
		for (Student i : this->v) {
			if (!s.compare(i.department)) {// If the same thing exists
				cout << setw(15) << left << i.name;
				cout << setw(10) << left << i.id;
				cout << setw(20) << left << i.department;
				cout << setw(11) << left << i.year;
				cout << setw(15) << left << i.tel << endl;
			}
		}
		break;
	case 5:
		cout << setw(15) << left << "Name";
		cout << setw(10) << left << "StudentID";
		cout << setw(20) << left << "Dept";
		cout << setw(11) << left << "Birth Year";
		cout << setw(15) << left << "Tel" << endl;
		for (Student i : this->v) {
			cout << setw(15) << i.name;
			cout << setw(10) << i.id;
			cout << setw(20) << i.department;
			cout << setw(11) << i.year;
			cout << setw(15) << i.tel << endl;
		}
	break;

	}

}

void Studentlist::sortingoption() {
	int s;
	cout << "-Sorting Option" << endl;
	cout << "1. Sort by Name" << endl;
	cout << "2. Sort by Student ID" << endl;
	cout << "3. Sort by Admission Year" << endl;
	cout << "4. Sort by Department name" << endl;
	cout << ">";
	cin >> s;

	switch (s) {
	case 1:
		sortByName();
		cout << "Go back to the mein menu, after selecting the sorting option..";
		break;

	case 2:
		sortById();
		cout << "Go back to the mein menu, after selecting the sorting option..";
		break;

	case 3:
		sortByYear();
		cout << "Go back to the mein menu, after selecting the sorting option..";
		break;

	case 4:
		sortByDepartment();
		cout << "Go back to the mein menu, after selecting the sorting option..";
		break;
	}
}

bool isFileEmpty(const string& filename) {
	ifstream file(filename);

	if (file) {
		// open the file
		return file.peek() == ifstream::traits_type::eof();
	}
	else {
		cerr << "Error: Unable to open " << filename << " for reading." << endl;
		return false;
	}
}

void Studentlist::exit(const string& filename) {
	ofstream outputFile(filename); // Open the file for writing (either create or overwrite)
	if (outputFile.is_open()) { 
		if (isFileEmpty(filename)) {
			outputFile << left<< setw(13) <<  "Name";
			outputFile << left << setw(11)  << "StudentID";
			outputFile << left << setw(21)  << "Dept";
			outputFile << left << setw(11)  << "Birth Year";
			outputFile << left << setw(11)  << "Tel" << endl;
		}
		for (const Student& student : v) {
			outputFile << left << setw(13)  << student.name;
			outputFile << left << setw(11)  << student.id;
			outputFile << left << setw(21)  << student.department;
			outputFile << left << setw(11)  << student.year;
			outputFile << left << setw(11)  << student.tel << endl;
		}
	outputFile.close();
	cout << "Data saved to " << filename << endl;
	}
	else {
		cout << "Error: Unable to open " << filename << " for writing." << endl;
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <filename>" << endl;
		return 1;
	}
	string filename = argv[1];
	int c = 0;
	Studentlist list;
	ofstream outputFile(filename, ios::app);
	if (outputFile.is_open()) {
		outputFile.close();
		cout << "File " << filename << " created" << endl;
	}
	else {
		cout << "Error: Unable to open or create " << filename << " for writing." << endl;
		return 1;
	}
	ifstream inputFile(filename);
	if (inputFile.is_open()) {
		string line;
		getline(inputFile, line);//ignore first line
		while (getline(inputFile, line)) {
			stringstream ss(line);
			string name, id, department, year, tel;
			ss >> name >> id >> department >> year >> tel;
			list.v.push_back(Student(name, id, department, year, tel));
		}
		inputFile.close();
		cout << "Data loaded from " << filename << endl;
	}
	bool three = false;
	while (c != 4) {
		cout << "\n1. Insertion" << endl;
		cout << "2. Search" << endl;
		cout << "3. Sorting Option" << endl;
		cout << "4. Exit" << endl;
		cout << ">";
		cin >> c;
		if (!three) {
		list.sortByName();
	}
		if (c == 1) {
			list.insert();
		}
		else if (c == 2) {
			list.search();
		}
		else if (c == 3) {
			three = true;
			list.sortingoption();
		}
		else if (c == 4) {
			list.exit(filename);
		}
	}
	return 0;
}