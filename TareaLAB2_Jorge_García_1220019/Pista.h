#pragma once
class Pista
{
	int PistaL[70];
	int PistaT[70];
	int* PLiebre;
	int* PTortuga;

public:
	Pista();
	~Pista();
	void Pista::Preparar();
	void Pista::PasoTortuga(int n);
	void Pista::PasoLiebre(int n);
	int Pista::PosLiebre();
	int Pista::PosTortuga();
};

