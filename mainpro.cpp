#include "proyecto.hpp"

int main(){
	
	//typedef priority_queue<Subject, vector<Subject>,Subject> mypq_type;
	
	Subject preca("Precalculo", 3, nullptr, 'B');
	Subject logica1("Lógica Teoria de numeros y conjuntos", 3, nullptr, 'B');
	Subject progra ("Programacion de computadores", 3, nullptr, 'B');
	Subject pensa ("pensamiento matematico", 2, nullptr, 'B');
	Subject Arqui ("Arquitectura del computador", 3 , nullptr, 'B');
	Subject intro ("introduccion a las ciencias naturales", 2, nullptr, 'B');
	
	Subject *p1 = &preca;
	Subject *p2 = &logica1;
	Subject *p3 = &progra;
	
	
	Subject c1("calculo1", 3, p1, 'B');
	Subject logica2("logica para ciencias de la computacion", 2, p2, 'B');
	Subject algor("algoritmos y estructuras de datos", 3, p3, 'B');
	
	Subject *p4 = &c1;
	Subject *p5 = &algor;	
	
	Subject c2("calculo2", 3, p4, 'B');
	Subject lineal("algebra lineal", 4, p4, 'B');
	Subject bases("manejo de bases de datos", 3, p5, 'B');
	
	Subject *p6 = &c2;
	
	Subject proba("probabilidad", 3, p6, 'B');
	
	
	Subject arr[] = {preca, logica1, progra, pensa, Arqui, intro, c1, logica2, algor, c2, lineal, bases, proba};
	
	vector<Subject> array(arr, arr + sizeof(arr) / sizeof(Subject));

	//mypq_type mypq(array, array+13);
			
	maker(array).display();
	/*while(!mypq.empty()){
		Subject a = mypq.top();
		cout << a << "," << endl;
		mypq.pop();		
	}*/
	
	return 0;
}
/*
	Subject preca("Precalculo", 3, nullptr);
	Subject logica1("Lógica Teoria de numeros y conjuntos", 3, nullptr);
	Subject progra ("Programacion de computadores", 3, nullptr);
	Subject pensa ("pensamiento matematico", 2, nullptr);
	Subject Arqui ("Arquitectura del computador", 3 , nullptr);
	Subject intro ("introduccion a las ciencias naturales", 2, nullptr);
	
	Subject *p1 = &preca;
	Subject *p2 = &logica1;
	Subject *p3 	
	while(!myqueue.empty()){
		Subject a = myqueue.top();
		cout << a << "," << endl;
		myqueue.pop();		
	}= &progra;
	
	
	Subject c1("calculo1", 3, p1);
	Subject logica2("logica para ciencias de la computacion", 2, p2);
	Subject algor("algoritmos y estructuras de datos", 3, p3);
	
	Subject *p4 = &c1;
	Subject *p5 = &algor;	
	
	Subject c2("calculo2", 3, p4);
	Subject lineal("algebra lineal", 4, p4);
	Subject bases("manejo de bases de datos", 3, p5);
	
	Subject *p6 = &c2;
	
	Subject proba("probabilidad", 3, p6);
	
	cout << "preca: "<< preca.get_priority() << endl;
	cout << "logica1: " << logica1.get_priority() << endl;
	cout << "progra: " << progra.get_priority() << endl;
	cout << "pensamiento: " << pensa.get_priority() << endl;
	cout << "Arquitectura: " << Arqui.get_priority() << endl;
	cout << "intro: " << intro.get_priority() << endl;
	cout << "c1: " << c1.get_priority() << endl;
	cout << "logica2: " << logica2.get_priority() << endl;
	cout << "algoritmos: " << algor.get_priority() << endl;
	cout << "c2: " << c2.get_priority() << endl;
	cout << "lineal: " << lineal.get_priority() << endl;
	cout << "bases: " << bases.get_priority() << endl;
	cout << "proba: " << proba.get_priority() << endl;	
	
	cout << (preca == preca) << endl;
	
	Subject array[] = {preca, logica1, progra, pensa, Arqui, intro, c1, logica2, algor, c2, lineal, bases, proba};
	priority_queue<Subject> myqueue (array, array+13);
	
	while(!myqueue.empty()){
		Subject a = myqueue.top();
		cout << a << "," << endl;
		myqueue.pop();		
	}

	curriculum w;
	w.insert(preca);
	return 0;
}*/
