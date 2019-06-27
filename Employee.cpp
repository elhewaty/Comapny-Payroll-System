#include "Employee.h"


Employee::Employee(int i, string first, string last, int a, int g, double h)
:Worker(i, first, last, a)
{
	setGrade(g);
	setHours(h);
}


void Employee::setGrade(int g){
	switch(g){
		case 1:
			position = "Manager", tax = .15, pay_rate = 400;
			break;
		case 2:
			position = "Team Leader", tax = .1, pay_rate = 250;
			break;
		case 3:
			position = "Team Member", tax = .05, pay_rate = 150;
	}
}


string Employee::getPosition()const{
	return position;
}

double Employee::getTax()const{
	return tax;
}

double Employee::getPayRate()const{
	return pay_rate;
}


void Employee::setHours(double h){
	hours = (h > 0 && h <= 160) ? h : 0;
}

double Employee::getHours()const{
	return hours;
}

void Employee::setSalary(){
	double gross_salary = ((this->getHours())*(this->getPayRate()));
	this->salary = gross_salary - ((this->getTax())*gross_salary);
}

double Employee::getSalary()const{
	return this->salary;
}


void Employee::createTable(sqlite3 *db, char *err, string table_name){
	sqlite3_open("com.db", &db);
	string s = "create table " + table_name + " (id int unique, FirstName varchar(20), LastName varchar(20), Age int, position varchar(20), hours double, salary double)";
	sqlite3_exec(db, s.c_str(), NULL, 0, &err);
	sqlite3_close(db);
}


string Employee::modifyAdd(string table_name){
	//insert into employee values(id, fn, ln, pos, hour, sala)
	string c = "," , c1 = "'";
	string s = "insert into " + table_name + " values ("+ c1 + to_string(this->getId()) + c1 + c + c1 + this->getFirstName() + c1 + c +
	c1 + this->getLastName()+ c1 + c + c1 + to_string(this->getAge())+ c1 + c + c1 + this->getPosition() + c1 + c + c1 + to_string(this->getHours())+ c1 + c 
	+ c1 + to_string(this->getSalary()) + c1 + ")";
	return s;
}


void Employee::add(sqlite3 *db, string table_name, char *err){
	sqlite3_open("com.db", &db);
	int id = message("Please Enter thee id");
	string first, last;
	int g, a;
	double h;
	cout << "Please Enter first name, last name, age and the hours worked" << endl;
	cin >> first >> last >> a >> h;
	cout << "Please Enter your position" << endl
		<< "1.Manager" << endl
		<< "2.Team Leader" << endl
		<< "3.Team Member" << endl;

	cin >> g;
	setId(id);
	setFirstName(first);
	setLastName(last);
	setAge(a);
	setGrade(g);
	setHours(h);
	setSalary();
	string s = modifyAdd(table_name);
	sqlite3_exec(db, s.c_str(), NULL, 0, &err);
	if(err){
		cerr << "#id " << id << " is already exist" << endl;
		err = NULL;
		exit(1);
	}
	sqlite3_close(db);
}


string Employee::modifyEdit(string table_name){
	string c = ",";
	string s = "update " + table_name + " set FirstName = "+ this->getFirstName() + c + " LastName = " + this->getLastName() + c + " Age = " + to_string(this->getAge()) + c + " position = "
			+ this->getPosition() + c + " hours = " + to_string(this->getHours()) + c + " salary = "  + to_string(this->getSalary());
	return s;	
}


void Employee::edit(sqlite3 *db, string table_name, char *err){
	int id = message("Please Enter the id to update the data");
	sqlite3_open("com.db", &db);
	string first, last;
	int g,a;
	double h;
	cout << "Please Enter the new data : first name, last name, age and the hours worked" << endl;
	cin >> first >> last >> a >> h;
	cout << "Please Enter your new position" << endl
		<< "1.Manager" << endl
		<< "2.Team Leader" << endl
		<< "3.Team Member" << endl;
	cin >> g;
	setId(id);
	setFirstName(first);
	setLastName(last);
	setGrade(g);
	setHours(h);
	setSalary();
	string s = modifyEdit(table_name);
	if(err){
		cerr << "#id " << id << " is not exist" << endl;
		err = NULL;
		exit(1);
	}
	sqlite3_close(db);
}



