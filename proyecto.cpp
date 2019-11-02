#include "proyecto.hpp"

const int MAX_CREDITS = 19;

Subject::Subject(){
	Name = "";
	num_credits = 0;
	request = nullptr;
	co_request = nullptr;
	priority = def_priority(this);
}

Subject::Subject(string name, int credits, Subject *pre, Subject *co){

	Name = name;
	num_credits = credits;
	request = pre;
	co_request = co;
	priority = def_priority(this);
}

int Subject::def_priority(Subject *subj){
	if (subj->request == nullptr){ return 0; }
	else {return 1 + def_priority(subj->request);}
}

int Subject::get_priority(){
	return priority;
}


curriculum::curriculum(){
	Semester S1;
	S = S1;
	first_semester = &S;
	last_semester  = &S;
	count_semester = 1;
}

curriculum::~curriculum(){
	delete first_semester;
	delete last_semester;
	Semester *p = &S;	
	delete p;

}


void curriculum::create_new_semester(){
	Semester *new_semester;
	new_semester = new Semester;
	new_semester->previous_semester = last_semester;
	new_semester->tot_credits = MAX_CREDITS;
	new_semester->next_semester = nullptr;

	last_semester->next_semester = new_semester;
	last_semester = new_semester;
	count_semester ++;
}







		
