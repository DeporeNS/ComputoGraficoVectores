#include "pch.h"
#include "Trasladar.h"


void Trasladar::setVX(int _vx)
{
	int vx = _vx;

}

void Trasladar::setVY(int _vy)
{
	int vy = _vy;

}

Trasladar::Trasladar(int vx, int vy)
{
	mat.resize(3);
	for (int i = 0; i < mat.size(); i++) {
		mat[i].resize(3, 0);
	}

	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;

	mat[0][2] = vx;
	mat[1][2] = vy;
}
