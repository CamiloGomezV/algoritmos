#include "proyecto.hpp"

const int MAX_CREDITS = 19;

Subject::Subject(){
	Name = "";
	num_credits = 0;
	request = nullptr;
	priority = def_priority(this);
}

Subject::Subject(string name, int credits, Subject *pre){

	Name = name;
	num_credits = credits;
	request = pre;
	priority = def_priority(this);
}

unsigned int Subject::def_priority(Subject *subj){
	if (subj->request == nullptr){ return 0 + hash(subj->Name); }
	else {return 7 + hash(subj->Name) + def_priority(subj->request);}
}

unsigned int Subject::hash ( string name){
	unsigned int hashval = 0;
	for (char ch : name)
		hashval += ch;
	return hashval % 7;


}

unsigned int Subject::get_priority() const{
	return priority;
}

string Subject::get_name() const {
	return Name;
}

bool operator <( const Subject &s1, const Subject &s2){
	unsigned int a = s1.get_priority();
	unsigned int b = s2.get_priority();
	return a < b;
}

ostream& operator << (ostream &os, const Subject &s){
	os << s.get_name();
	return os;
}

curriculum::curriculum(){
	Semester *S1 = new Semester;
	S1->next_semester = nullptr;
	S1->previous_semester = nullptr;
	first_semester = S1;
	last_semester  = S1;
	count_semester = 1;
}

curriculum::~curriculum(){
	delete first_semester;
	delete last_semester;
}

void curriculum::insert(const Subject &subj){




}

bool curriculum::search(const Subject &subj){
	target = first_semester->S;
	
	if (target.auxf(subj)){
		return true;
	}
	else if (first_semester->next_semester != nullptr) {
		first_semester = first_semester->next_semester;
		search(const Subject &subj)
			
	}
	return false;

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







		
