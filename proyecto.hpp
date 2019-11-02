#ifndef __PROYECTO_HPP
#define __PROYECTO_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Subject{

private:
	string Name;
	int num_credits;
	Subject *request;
	Subject *co_request;
	int priority;
	
	int def_priority(Subject *subj);
	
public:	
	
	Subject();
	Subject(string name, int credits, Subject *pre, Subject *co);
	int get_priority();
	
};


class curriculum { //semestres concatenados

private:

	struct Semester{
		int tot_credits;
		vector<Subject> S;
		Semester *next_semester;
		Semester *previous_semester;
	};

public:

	curriculum();
	~curriculum();

	void insert (Subject subj);
	bool search (const Subject subj);
	int  num_semesters();

private:

	Semester *first_semester;
	Semester *last_semester;
	Semester S;
	int count_semester;

	void create_new_semester();

};
#endif












	



