
#ifndef TRAINEE_H
#define TRAINEE_H 


#include "Worker.h"



class Trainee : public Worker
{
public:
	Trainee(int = 0, string = "", string = "", int = 0, string = "", string = "", double = 0.0);

	void setFaculty(string);
	string getFaculty()const;

	void setYear(string);
	string getYear()const;

	void setGpa(double);
	double getGpa()const;

	virtual void createTable(sqlite3 *, char *, string);
	
	virtual void add(sqlite3 *, string, char *);
	virtual void edit(sqlite3 *, string, char *);
	//virtual void print(sqlite3 *);

	virtual string modifyAdd(string);
	virtual string modifyEdit(string);

private:
	string faculty;
	string academic_year;
	double gpa;
	
};


#endif