#include "proyecto.hpp"

int main(){
	Subject c1;
	Subject c2;

	Subject *p1 = &c1;
	Subject *p2 = &c2;

	Subject c3 ("SoyGay", 12, p1, p2);

	cout << c3.get_priority() << endl;

	curriculum w;
	return 0;
}
