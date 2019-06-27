
#include "Trainee.h"

Trainee::Trainee(int i, string first, string last, int a, string fac, string ac, double gp)
:Worker(i, first, last, a)
{
	setFaculty(fac);
	setYear(ac);
	setGpa(gp);
}



void Trainee::setFaculty(string f){
	faculty = f;
}


void Trainee::setYear(string y){
	academic_year = y;
}


void Trainee::setGpa(double g){
	gpa = (g >= 0 && g <= 4) ? g : 0.0;
}


string Trainee::getFaculty()const{
	return faculty;
}


string Trainee::getYear()const{
	return academic_year;
}


double Trainee::getGpa()const{
	return gpa;
}


void Trainee::createTable(sqlite3 *db, char *err, string table_name){
	sqlite3_open("com.db", &db);
	string s = "create table " + table_name + 
			" (id int unique, FirstName varchar(20), LastName varchar(20), Age int, Faculty varchar(60), Academic Year varchar(30), Gpa double)";
	sqlite3_exec(db, s.c_str(), NULL, 0, &err);
	sqlite3_close(db);
}


string Trainee::modifyAdd(string table_name){
	string c = "," , c1 = "'";
	string s = "insert into " + table_name + " values ("+ c1 + to_string(this->getId()) + c1 + c + c1 + this->getFirstName() + c1 + c +
	c1 + this->getLastName()+ c1 + c + c1 + to_string(this->getAge())+ c1 + c + c1 + this->getFaculty() + c1 + c + c1 + this->getYear() + c1 + c 
	+ c1 + to_string(this->getGpa()) + c1 + ")";
	return s;
}



void Trainee::add(sqlite3 *db, string table_name, char *err){
	sqlite3_open("com.db", &db);
	int id = message("Please Enter new id");
	string first, last, fac, ac;
	int age;
	double gpa;
	cout << "Please Enter first name, last name and age" << endl;
	cin >> first >> last >> age;
	getchar();
	cout << "Please Enter the faculty name" << endl;
	getline(cin, fac);
	cout << "PLease enter the academic Year and gpa" << endl;
	cin >> ac >> gpa;

	setId(id);
	setFirstName(first);
	setLastName(last);
	setAge(age);
	setFaculty(fac);
	setYear(ac);
	setGpa(gpa);

	string s = modifyAdd(table_name);
	sqlite3_exec(db, s.c_str(), NULL, 0, &err);
	if(err){
		cerr << "#id " << id << " is already exist" << endl;
		err = NULL;
		exit(1);
	}
	sqlite3_close(db);
}



string Trainee::modifyEdit(string table_name){
	string c = ",";
	string s = "update " + table_name + " set FirstName = "+ this->getFirstName() + c + " LastName = " + this->getLastName() + c + " Age = " + to_string(this->getAge()) + c + " Faculty = "
			+ this->getFaculty() + c + " AcademicYear = " + this->getYear() + c + " Gpa = "  + to_string(this->getGpa());
	return s;	
}



void Trainee::edit(sqlite3 *db, string table_name, char *err){
	sqlite3_open("com.db", &db);
	int id = message("Please Enter the id u wanna update");
	string first, last, fac, ac;
	int age;
	double gpa;
	cout << "Please Enter first name, last name and age" << endl;
	cin >> first >> last >> age;
	getchar();
	cout << "Please Enter the faculty name" << endl;
	getline(cin, fac);
	cout << "PLease enter the academic Year and gpa" << endl;
	cin >> ac >> gpa;

	setId(id);
	setFirstName(first);
	setLastName(last);
	setAge(age);
	setFaculty(fac);
	setYear(ac);
	setGpa(gpa);

	string s = modifyEdit(table_name);
	sqlite3_exec(db, s.c_str(), NULL, 0, &err);
	if(err){
		cerr << "#id " << id << " is already not exist" << endl;
		err = NULL;
		exit(1);
	}
	sqlite3_close(db);
}
