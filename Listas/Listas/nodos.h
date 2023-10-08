#pragma once
#include <fstream>
#include <stdlib.h>
#include<string>
#include <cstdlib>
#include"nodos.h"
using namespace std;
class nodos
{
private:
	string insertar;
	nodos* enlace= NULL;
public:
	nodos();
	void set_artista(string);

	string get_artista();
	void set_enlace(nodos*);
	nodos* get_enlace();
		

};

