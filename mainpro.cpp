#include "proyecto.hpp"
#include<algorithm>

int main(){

	Subject preca("Precalculo", 3, nullptr, 'B');
	Subject *A = &preca;

	Subject logica1("Lógica Teoria de numeros y conjuntos", 3, nullptr, 'B');
	Subject *B = &logica1;

	Subject progra ("Programacion de computadores", 3, nullptr, 'B');
	Subject *C = &progra;

	Subject pensa ("pensamiento matematico", 2, nullptr, 'B');
	Subject Arqui ("Arquitectura del computador", 3 , nullptr, 'B');
	Subject intro ("introduccion a las ciencias naturales", 2, nullptr, 'B');

	Subject c1("calculo1", 3, A, 'B');
	Subject *D = &c1;

	Subject logica2("logica para ciencias de la computacion", 2, B, 'B');
	Subject *E = &logica2;

	Subject algor("algoritmos y estructuras de datos", 3, C, 'B');
	Subject *F = &algor;

	Subject c2("calculo2", 3, D, 'B');
	Subject *G = &c2;

	Subject lineal("algebra lineal", 4, D, 'B');
	Subject *H = &lineal;

	Subject bases("manejo de bases de datos", 3, F, 'B');

	Subject proba("probabilidad", 3, D, 'B');
	Subject *I = &proba;

	Subject catedra("catedra rosarista", 2, nullptr, 'C');
	Subject textos("Analisis de textos", 2, nullptr, 'C');
	Subject etica("Etica", 2, nullptr, 'C');
	Subject argumentos("Analisis de argumentos", 2, nullptr, 'C');

	Subject e1 ("electiva general", 3, nullptr, 'E');
	Subject* E1 = &e1;

	Subject e2 ("electiva general 2", 3, E1, 'E');
	Subject* E2 = &e2;

	Subject hm1 ("electiva HM 1", 2, nullptr, 'E');
	Subject* HM1 = &hm1;

	Subject consti("Constitucion politica", 2, nullptr, 'C');

	Subject hm2 ("electiva HM 2", 2, HM1, 'E');
	Subject *HM2 = &hm2;

	Subject c3 ("Calculo3", 2, G, 'B');
	Subject *J = &c3;

	Subject teoria("Teroria de la computacion", 3, E, 'B');
	Subject fisica("Elementos de Fisica", 3, G, 'B');

	Subject diferen("Ecuaciones Diferenciales", 3, G, 'B');
	Subject *K = &diferen;

	Subject opti("Optimizacion", 3, G, 'B');
	Subject *L = &opti;

	Subject ensayos("Escritura de ensayos de opinion", 2, nullptr, 'C');

	Subject analisis("Analisis real", 3, J, 'B');
	Subject *M = &analisis;

	Subject abstracta("Algebra abstracta y codificacion", 4, H, 'B');
	Subject grafos("Teoria De Grafos", 3, H, 'B');
	Subject compleja("Variable compleja", 2, J, 'B');

	Subject estadistica("Estadistica", 2, I, 'B');
	Subject *N = &estadistica;

	Subject e3("Electiva general 3", 2, E2, 'E');
	Subject* E3 = &e3;

	Subject topolo("Topologia", 3, M, 'B');
	//Subject* P = &topolo;

	Subject dinamicos("Modelacion de Sistemas dinamicos", 3, K, 'B');
	Subject diferenparcia("Ecuaciones Diferenciales parciales", 3, K, 'B');
	Subject analiEstadis("Analisis Estadistico De Datos", 3 , N, 'B');
	Subject geomet("Geometria Computacional", 3, L, 'B');
	Subject hm3("Electiva HM 3", 2, HM2, 'E');
	Subject geometdif("Geometria Diferencial", 2, K, 'B');
	Subject compucienti("Analisis numerico y computacion cientifica", 3, K, 'B');
	Subject e4("Electiva general 4", 3, E3, 'E');

	Subject seminario("seminario de grado", 1, nullptr, 'D');
	Subject opg1("Opcion de grado 1", 3, nullptr, 'D');
	Subject* OPG1 = &opg1;

	Subject ep1("Electiva de profundizacion 1", 9, nullptr, 'D');
	Subject* EP1 = &ep1;

	Subject opg2("Opcion de grado 2", 8, OPG1, 'D');
	Subject ep2("Electiva de profundizacion 2", 6, EP1, 'D');



	Subject arr[48] = {preca, logica1, progra, pensa, Arqui, intro,  c2, lineal, bases, c1, logica2, algor, proba, catedra,textos,etica,argumentos,e1,hm1,consti,hm2,e2,c3,teoria,fisica,diferen, opti, ensayos, e3,e4,hm3, analisis,abstracta,grafos,compleja,estadistica, topolo, dinamicos,diferenparcia, analiEstadis,geomet,geometdif, compucienti, seminario, opg1, opg2, ep1, ep2};

	vector<Subject> hola;

	for (int i = 0; i<48; i++){
		hola.push_back(arr[i]);
	}

	random_shuffle ( hola.begin(), hola.end() );

	Curriculum w = maker(hola);
	w.display();


	return 0;
}
