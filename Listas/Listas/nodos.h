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
	string artista;
	string cancion;
	string tiempo;
	nodos* enlace= NULL;
public:
	nodos();
	void set_artista(string);
	void set_cacnion(string);
	void set_tiempo(string);
	string get_artista();
	string get_cacnion();
	string get_tiempo();
	void set_enlace(nodos*);
	nodos* get_enlace();
		

};

