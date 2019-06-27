#include "Employee.h"
#include "Trainee.h"


int getMenue(){
	int choice;
	cout << "Enter the operation" << endl
		<< "1.Add Employee" << endl
		<< "2.Remove Employee" << endl
		<< "3.Edit Employee" << endl
		<< "4.Add Trainee" << endl
		<< "5.Remove Trainee" << endl
		<< "6.Edit Trainee" << endl
		<< "7.End the program" <<endl;
	cin >> choice;
	return choice;
}

int main(){
	Employee emp;
	Worker *wr = NULL;
	Trainee tr;
	int choice ;
	sqlite3 *db;
	char *err;
	wr = &emp;
	wr->createTable(db, err, "employee");
	wr = &tr;
	wr->createTable(db, err, "trainee");
	while((choice = getMenue()) != 7){
		switch(choice){
			case 1:
				wr = &emp;
				wr->add(db, "employee", err);
				break;
			case 2:
				wr = &emp;
				wr->remove(db, "employee", err);
				break;
			case 3:
				wr = &emp;
				wr->edit(db, "employee", err);
				break;
			case 4:
				wr = &tr;
				wr->add(db, "trainee", err);
				break;
			case 5:
				wr = &tr;
				wr->remove(db, "trainee", err);
				break;
			case 6:
				wr = &tr;
				wr->edit(db, "trainee", err);
				break;
			default:
				cerr << "Incorrect choice" << endl;
				break;
		}
		
	}

	return 0;
}