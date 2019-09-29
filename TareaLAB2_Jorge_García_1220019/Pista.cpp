#include "Pista.h"



Pista::Pista()
{
	
}


Pista::~Pista()
{
}

void Pista::Preparar() {
	for (int i = 0; i < 71; i++)
	{
		PistaL[i] = i+1;
		PistaT[i] = i+1;
	}

	 PLiebre = &PistaL[0];
	 PTortuga = &PistaL[0];
}

void Pista::PasoTortuga(int n) {
	if (n < 6 && n > 0) {
		if (*PTortuga + 3 >= 70) {
			PTortuga = &PistaT[69];
		}
		else {
			PTortuga += 3;
		}
	}
	else if (n < 8 && n > 5)
	{
		if (*PTortuga- 6 < 1) {
			PTortuga = &PistaT[0];
		}
		else {
			PTortuga -= 6;
		}
	}
	else
	{
		if (*PTortuga + 1 >= 70) {
			PTortuga = &PistaT[69];
		}
		else {
			PTortuga += 1;
		}
	}
}
int Pista::PosLiebre() {
	return *PLiebre;
}
int Pista::PosTortuga() {
	return *PTortuga;
}
void Pista::PasoLiebre(int n) {
	if (n < 3 && n>0)
	{

	}
	else if(n>2 && n<5)
	{
		if (*PLiebre + 9 >= 70) {
			PLiebre = &PistaL[69];
		}
		else {
			PLiebre += 9;
		}
		
	}
	else if (n == 5) {
		if (*PLiebre- 12 < 1) {
			PLiebre = &PistaL[0];
		}
		else {
			PLiebre -= 12;
		}
	}
	else if (n>5 && n<9) {
		if (*PLiebre+1 > 70 ) {
			PLiebre= &PistaL[69];
		}
		else {
			PLiebre += 1;
		}
	}
	else
	{
		if (*PLiebre -2 < 1) {
			PLiebre = &PistaL[0];
		}
		else {
			PLiebre -= 2;
		}
	}
}

