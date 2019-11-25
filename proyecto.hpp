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


	//Constructor
	Subject();
	Subject(string name, int credits, Subject *pre, char lb);

	//Destructor
	~Subject();

	//Operator Overloading
	bool operator()(const Subject &s1, const Subject &s2);

	//Get Methods
	unsigned int get_priority() const;
	string get_name() const;
	Subject* get_request() const;
	int get_num_credits() const;
	char get_label() const;

};

bool operator> (const Subject &s1, const Subject &s2);
ostream& operator<<(ostream &os, const Subject &s);
bool operator==(const Subject &s1, const Subject &s2);




class Curriculum{ // LINKED VECTOR LIST

private:

	struct Semester{

		int tot_credits;
		vector<Subject> S;
		Semester *next_semester;
		Semester *previous_semester;

		bool aux_search(const Subject &subj){
			for(unsigned int i = 0; i < S.size(); i++){
				if (S[i]==subj) return true;
			}
			return false;
		}

		Semester& operator =(Semester& sem){
			tot_credits = sem.tot_credits;
			S = sem.S;
			next_semester = sem.next_semester;
			previous_semester = sem.previous_semester;

			return *this;
		}
	};

	public:

	//Constructor
	Curriculum();

	//Destructor
	~Curriculum();

	//Public Methods
	void insert (Subject &subj);
	bool search (const Subject &subj);
	void display();

private:

	Semester *first_semester;
	Semester *last_semester;
	Semester *insert_control; // pointer to the first semester where i can insert a subject
	int count_semester;       // number of semesters

	//Private Methods
	void create_new_semester(); // expand capacity
	void set_insert_control();	// set insert_control
	void aux_insert( Subject &subj);

};

//SORTING ALGORITHM
Curriculum maker( vector<Subject> array);

#endif
