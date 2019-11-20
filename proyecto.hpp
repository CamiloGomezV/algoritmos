#ifndef __PROYECTO_HPP
#define __PROYECTO_HPP

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Subject{

private:
	string Name;
	int num_credits;
	Subject *request;
	unsigned int priority;
	char label;
	
	unsigned int def_priority(Subject *subj);
	unsigned int hash ( string name);

public:	
	
	Subject();
	Subject(string name, int credits, Subject *pre, char lb);
	bool operator()(const Subject &s1, const Subject &s2);
	unsigned int get_priority() const;
	string get_name() const;
	Subject * get_request() const;
	int get_num_credits() const;
	char get_label() const;
};

bool operator<(const Subject &s1, const Subject &s2);
ostream& operator<<(ostream &os, const Subject &s);
bool operator==(const Subject &s1, const Subject &s2);


class curriculum { //semestres concatenados

private:

	struct Semester{
		int tot_credits;
		vector<Subject> S;
		Semester *next_semester;
		Semester *previous_semester;

		bool auxf(const Subject &subj){
			for(unsigned int i = 0; i < S.size(); i++)
				if (S[i]==subj) return true;
			return false;
		}
	};

public:

	curriculum();
	~curriculum();

	void insert (const Subject &subj);
	bool search (const Subject &subj);
	int  num_semesters();
	void display();
		
private:

	Semester *first_semester;
	Semester *last_semester;
	Semester *insert_control; 
	int count_semester;

	void create_new_semester();
	void set_insert();
	void aux_insert(const Subject &subj);


};

curriculum maker( Subject array[]);
#endif












	



