#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Worker.h"

class Employee : public Worker
{
public:
	Employee(int = 0, string  = "", string = "", int = 0, int = 0, double = 0.0);

	void setGrade(int);

	string getPosition()const;
	double getTax()const;
	double getPayRate()const;

	void setHours(double);
	double getHours()const;

	virtual void createTable(sqlite3 *, char *, string);

    virtual void setSalary();
	virtual double getSalary()const;

	virtual void add(sqlite3 *, string, char *);
	virtual void edit(sqlite3 *, string, char *);

	virtual string modifyAdd(string);
	virtual string modifyEdit(string);

protected:
	double salary;

private:
	double hours;
	int grade;
	double pay_rate;
	double tax;
	string position;
};

#endif