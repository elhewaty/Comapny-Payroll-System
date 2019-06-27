#include "Worker.h"


Worker::Worker(int i, string first, string last, int a){
	setId(i);
	setFirstName(first);
	setLastName(last);
	setAge(a);
}


void Worker::setId(int i){
	id = (i > 0) ? i : 0;
}


void Worker::setFirstName(string s){
	first_name = s;
}


void Worker::setLastName(string s){
	last_name = s;
}



void Worker::setAge(int a){
	a = (a >= 18 && a <= 60) ? a : 0;
}


int Worker::getId()const{
	return id;
}


int Worker::message(const char *const prompt){
	int id;
	do{
		cout << prompt << endl;
		cin >> id;
	}while(id <= 0);
	return id;
}


string Worker::getFirstName()const{
	return first_name;
}


string Worker::getLastName()const{
	return last_name;
}


int Worker::getAge()const{
	return age;
}

void Worker::setSalary(){
	salary = 760;
}


double Worker::getSalary()const{
	return salary;
}


string Worker::modifyRemove(string table_name, int id){
	//delete from table_name where id = number
	string c = "'";
	string s = "delete from " + table_name + " WHERE id=" + c + to_string(id) + c;
	return s;
}

void Worker::remove(sqlite3 *db, string table_name, char *err){
	sqlite3_open("com.db", &db);
	int id = message("Please Enter id of the Worker you wanna delete");
	string s = modifyRemove(table_name, id);
	sqlite3_exec(db, s.c_str(), NULL, 0, &err);
	if(sqlite3_changes(db) == 0){
		cerr << "#id " << id << " is not exist" << endl;
		err = NULL;
		exit(1);
	}
	sqlite3_close(db);
}