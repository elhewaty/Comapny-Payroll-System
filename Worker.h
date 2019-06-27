#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

class Worker
{
public:
	Worker(int = 0, string = "", string = "", int = 0);

	void setId(int);
	int getId()const;

	void setFirstName(string);
	string getFirstName()const;

	void setLastName(string);
	string getLastName()const;

	void setAge(int);
	int getAge()const;

	int message(const char *const);

	virtual void createTable(sqlite3 *, char *, string) = 0;
	virtual void remove(sqlite3 *, string, char *);
	virtual void setSalary();
	virtual double getSalary()const;
	virtual void add(sqlite3 *, string, char *) = 0;
	virtual void edit(sqlite3 *, string, char *) = 0;
	//virtual void print(sqlite3 *, string) = 0;
	virtual string modifyAdd(string) = 0;
	virtual string modifyEdit(string) = 0;
	virtual string modifyRemove(string , int);

protected:
	double salary;

private:
	int id;
	string first_name;
	string last_name;
	int age;
};

#endif