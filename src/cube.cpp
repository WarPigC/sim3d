#include "sim3d.h"


cube::cube(int X1, int Y1, int X2, int Y2)
	:x1 {X1},
	y1 {Y1},
	x2 {X2},
	y2 {Y2}
{
	std::cout << "Initalized cube!";
}
