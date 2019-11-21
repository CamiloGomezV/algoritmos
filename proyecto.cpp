#include "proyecto.hpp"

const int MAX_CREDITS = 19;

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

Subject * Subject::get_request() const {
	return request;
}

int Subject::get_num_credits() const {
	return num_credits;
}

bool operator > (const Subject &s1, const Subject &s2){
	unsigned int a = s1.get_priority();
	unsigned int b = s2.get_priority();
	return a > b;
}

bool Subject::operator () (const Subject &s1, const Subject &s2){
	return s1 > s2;
}

char Subject::get_label() const{
	return label;
}



bool operator == (const Subject &s1, const Subject &s2){
	return s1.get_name() == s2.get_name();
}

ostream& operator << (ostream &os, const Subject &s){
	os << s.get_name();
	return os;
}


curriculum::curriculum(){
	Semester *S1 = new Semester;
	S1->tot_credits = 0;
	S1->next_semester = nullptr;
	S1->previous_semester = nullptr;
	first_semester = S1;
	last_semester  = S1;
	insert_control = S1;
	count_semester = 1;
}

curriculum::~curriculum(){
	delete first_semester;
	delete last_semester;
}

void curriculum::insert(const Subject &subj){
	Subject *exist = subj.get_request();
	cout << "control insert " << endl;
	if (exist == nullptr){
		//cout << "control if insert " << endl;
		if (insert_control->tot_credits < MAX_CREDITS){
			//cout << "control if insert 2" << endl;
			aux_insert(subj);
		}
		else{
			//cout << "control if insert 3" << endl;
			set_insert();
			aux_insert(subj);
		}
	}
	else if (search(*exist)){
		//cout << "control if insert " << endl;
		if (insert_control->tot_credits < MAX_CREDITS){
			//cout << "control if insert 2" << endl;
			aux_insert(subj);
		}
		else{
			//cout << "control if insert 3" << endl;
			set_insert();
			aux_insert(subj);
		}
	}
}

bool curriculum::search(const Subject &subj){
	Semester target = *first_semester;
	
	if (target.auxf(subj)){
		return true;
	}
	else if (first_semester->next_semester != nullptr) {
		first_semester = first_semester->next_semester;
		search(subj);
			
	}
	return false;
}

void curriculum::create_new_semester(){
	Semester *new_semester;
	new_semester = new Semester;
	new_semester->previous_semester = last_semester;
	new_semester->tot_credits = 0;
	new_semester->next_semester = nullptr;

	last_semester->next_semester = new_semester;
	last_semester = new_semester;
	count_semester ++;
}

void curriculum::set_insert(){
	if(insert_control->next_semester == nullptr){
		create_new_semester();
	}
	insert_control = insert_control->next_semester;
}

void curriculum::aux_insert(const Subject &subj){
	int free_credits = insert_control->tot_credits + subj.get_num_credits();
	if (free_credits <= MAX_CREDITS){
		insert_control->S.push_back(subj);
	}
	else if(insert_control->next_semester != nullptr){
		insert_control->next_semester->S.push_back(subj);
	}
	else{
		create_new_semester();	
		insert_control->next_semester->S.push_back(subj);
	}
}

void curriculum::display(){
	Semester *itr = first_semester;
	while(itr != nullptr){
	//cout << "control" << endl;
		vector<Subject> aux = itr->S;
		cout << aux.size() << endl;
		for (unsigned int i = 0; i < aux.size(); i++){
			cout << aux[i] << ", ";
		}
		itr = itr->next_semester;
	}
	cout << endl;
}

curriculum maker( vector<Subject> array){
	//cout << "control maker0" << endl;
	typedef priority_queue<Subject, vector<Subject>,Subject> mypq_type;
	//cout << "control maker1" << endl;
	curriculum mycurriculum;
	mypq_type basics, complement;
	for(unsigned int i = 0; i < array.size(); i++){
		char lb = array[i].get_label();
		if (lb == 'B'){ basics.push(array[i]); }
		else if(lb == 'C'){ complement.push(array[i]); }
	}
	while(!basics.empty()){
		Subject a = basics.top();
		mycurriculum.insert(a);
		basics.pop();
		if(!complement.empty()){
			Subject b = complement.top();
			mycurriculum.insert(b);
			complement.pop();
		}
	}
	//cout << "control maker3" << endl;
	return mycurriculum;
}




		
