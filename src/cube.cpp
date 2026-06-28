#include "sim3d.h"


cube::cube(Coordinates c)
	:A {c[0]},
	B {c[1]},
	C {c[2]},
	D {c[3]}
{
	std::cout << "Initalized cube!" << std::endl;
}

Coordinates cube::getCoordinates() {
	return { A, B, C, D };
}

int cube::getSideLen() {

	// length...
	
	return 0;
}


//NOTE: MAKE edge table AND vertice array FOR 3D cube
