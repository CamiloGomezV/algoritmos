#include "proyecto.hpp"

const int MAX_CREDITS = 19;

//CLASS SUBJECT

//CONSTRUCTORS

Subject::Subject(){
	Name = "";
	num_credits = 0;
	request = nullptr;
	priority = def_priority(this);
	label = 'a';
}

Subject::Subject(string name, int credits, Subject *pre, char lb){
	Name = name;
	num_credits = credits;
	request = pre;
	priority = def_priority(this);
	label = lb;
}

//DESTRUCTOR
Subject::~Subject(){
}

// PRIVATE METHODS

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

//OPERATOR OVERLOADING

bool operator > (const Subject &s1, const Subject &s2){
	unsigned int a = s1.get_priority();
	unsigned int b = s2.get_priority();
	return a > b;
}

bool operator == (const Subject &s1, const Subject &s2){
	return s1.get_name() == s2.get_name();
}

ostream& operator << (ostream &os, const Subject &s){
	os << s.get_name();
	return os;
}

bool Subject::operator () (const Subject &s1, const Subject &s2){
	return s1 > s2;
}

//GET METHODS

unsigned int Subject::get_priority() const{
	return priority;
}

string Subject::get_name() const {
	return Name;
}

Subject * Subject::get_request() const {
	return request;
}

int Subject::get_num_credits() const {
	return num_credits;
}

char Subject::get_label() const{
	return label;
}

//CLASS Curriculum


//CONSTRUCTOR
Curriculum::Curriculum(){

	Semester *S1 = new Semester;

	S1->tot_credits = 0;
	S1->next_semester = nullptr;
	S1->previous_semester = nullptr;

	first_semester = S1;
	last_semester  = S1;
	insert_control = S1;
	count_semester = 1;
}

//DESTRUCTOR

Curriculum::~Curriculum(){

}

//PUBLIC METHODS

void Curriculum::insert(Subject &subj){

	Subject * exist = subj.get_request();
	int free_credits = insert_control->tot_credits + subj.get_num_credits();

	if (exist == nullptr){
		if (free_credits < MAX_CREDITS ){
			insert_control->S.push_back(subj);
			insert_control->tot_credits += subj.get_num_credits();
		}
		else{
			set_insert_control();
			insert_control->S.push_back(subj);
			insert_control->tot_credits += subj.get_num_credits();
		}
	}else if(search(*exist)){
		if (free_credits < MAX_CREDITS){
			aux_insert(subj);
		}else{
			set_insert_control();
			aux_insert(subj);
		}
	}
}

void Curriculum::aux_insert(Subject &subj){

	Semester *aux;
	Semester *itr = first_semester;

	while( itr != nullptr ){

		Semester targetS = *itr;
		Subject* req = subj.get_request();

		if(targetS.aux_search(*req)){ aux = itr;}

		itr = itr->next_semester;
	}

	if(aux->next_semester == nullptr) {create_new_semester();}

	int free_nextcredits = aux->next_semester->tot_credits + subj.get_num_credits();
	int free_credits = insert_control->tot_credits + subj.get_num_credits();

	if(free_nextcredits < MAX_CREDITS){
		aux->next_semester->S.push_back(subj);
		aux->next_semester->tot_credits += subj.get_num_credits();
	}else if(free_credits < MAX_CREDITS){
		insert_control->S.push_back(subj);
		insert_control->tot_credits += subj.get_num_credits();
	}else{
		insert_control->next_semester->S.push_back(subj);
		insert_control->next_semester->tot_credits += subj.get_num_credits();
	}
}


bool Curriculum::search(const Subject &subj){

	Semester* target = first_semester;

	while(target != nullptr){
		Semester targetS = *target;

		if(targetS.aux_search(subj)){ return true;}

		else {target = target->next_semester;}
	}

	return false;

}


void Curriculum::display(){

	Semester *itr = first_semester;
	int cont = 1;
	while(itr != nullptr){
		vector<Subject> aux = itr->S;
		cout << "Semester: " << cont << endl;
		for (unsigned int i = 0; i < aux.size(); i++){
			cout << aux[i] << ", ";
		}
		cout << itr->tot_credits << endl;
		cout << endl << endl;
		cont++;
		itr = itr->next_semester;
	}
	cout << endl<<endl;
}

//PRIVATE METHODS

void Curriculum::create_new_semester(){

	Semester *new_semester;
	new_semester = new Semester;
	new_semester->previous_semester = last_semester;
	new_semester->tot_credits = 0;
	new_semester->next_semester = nullptr;

	last_semester->next_semester = new_semester;
	last_semester = new_semester;
	count_semester ++;

}

void Curriculum::set_insert_control(){
	if(insert_control->next_semester == nullptr){
		create_new_semester();
	}
	insert_control = insert_control->next_semester;
}



//SORTING ALGORITHM

Curriculum maker( vector<Subject> array){

	typedef priority_queue <Subject, vector<Subject>,Subject> mypq_type;

	Curriculum myCurriculum;
	mypq_type basics;
	mypq_type complement;
	mypq_type elective;
	mypq_type degree_option;

	for(unsigned int i = 0; i < array.size(); i++){
		char lb = array[i].get_label();
		if (lb == 'B'){ basics.push(array[i]); }
		else if(lb == 'C'){ complement.push(array[i]); }
		else if(lb == 'E'){ elective.push(array[i]); }
		else if(lb == 'D'){ degree_option.push(array[i]); }
	}

	while(!elective.empty()){
		Subject c = elective.top();
		myCurriculum.insert(c);
		elective.pop();
	}
	while(!basics.empty()){
		Subject a = basics.top();
		myCurriculum.insert(a);
		basics.pop();
		if(!basics.empty()){
			Subject c = basics.top();
			myCurriculum.insert(c);
			basics.pop();
		}
		if(!complement.empty()){
			Subject b = complement.top();
			myCurriculum.insert(b);
			complement.pop();
		}
	}

	while(!degree_option.empty()){
		Subject a = degree_option.top();
		myCurriculum.insert(a);
		degree_option.pop();
	}
	return myCurriculum;
}
