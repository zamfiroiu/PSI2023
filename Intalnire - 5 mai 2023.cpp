#include<iostream>

using namespace std;

//ZIar

enum Categorie {
	Stiri, CanCan, Sport, Divertisment, Extern, Politica 
};

class Autor {
public:
	string numeAutor;
	int aniExperienta;
	float salariu;
	Categorie categorie;

	Autor() {
		this->numeAutor = "Anonim";
		this->aniExperienta = 0;
		this->salariu = 0;
		this->categorie = Stiri;
	}

	Autor(string numeAutor, int nrAniExperienta) {
		this->numeAutor = numeAutor;
		this->aniExperienta = nrAniExperienta;
		this->salariu = 0;
		this->categorie = Stiri;
	}

	Autor(string numeAutor, int aniExperienta, float salariu, Categorie categorie) {
		this->numeAutor = numeAutor;
		this->aniExperienta = aniExperienta;
		this->salariu = salariu;
		this->categorie = categorie;
	}
	~Autor() {

	}
};

class Articol {
public:
	static int generatorID;
	const int id;
	char* titlu;
	Autor autor;
	int anulScrierii;
	int nrRanduri;
	
	Articol():id(generatorID),autor() {
		generatorID++;
		this->titlu = new char[strlen("Articol") + 1];
		strcpy_s(this->titlu, strlen("Articol") + 1, "Articol");
		this->anulScrierii = 2023;
		this->nrRanduri = 200;
	}

	Articol(const char* titlu, Autor autor): id(generatorID++) {
		this->titlu = new char[strlen(titlu) + 1];
		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
		this->autor = autor;
		this->anulScrierii = 2023;
		this->nrRanduri = 200;

	}

	Articol(const char* titlu, Autor autor, int anulScrierii, int nrRanduri) :id(generatorID++) {
		this->titlu = new char[strlen(titlu) + 1];
		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
		this->autor = autor;
		this->anulScrierii = anulScrierii;
		this->nrRanduri = nrRanduri;
	}

	Articol operator=(Articol a) {
		this->titlu = new char[strlen(a.titlu) + 1];
		strcpy_s(this->titlu, strlen(a.titlu) + 1, a.titlu);
		this->autor = a.autor;
		this->anulScrierii = a.anulScrierii;
		this->nrRanduri = a.nrRanduri;
		return *this;
	}

	~Articol() {
		if (this->titlu != NULL) {
			delete[]this->titlu;
		}
	}


};
int Articol::generatorID = 1;

class Ziar {
public:
	string nume;
	int tiraj;
	int nrPagini;
	float pret;
	int nrArticole;
	Articol* articole;

	Ziar() {
		this->nume = "Ziarul";
		this->tiraj = 2000;
		this->nrPagini = 10;
		this->pret = 5;
		this->nrArticole = 0;
		this->articole = NULL;
	}

	Ziar(string nume) {
		this->nume = nume;
		this->tiraj = 2000;
		this->nrPagini = 10;
		this->pret = 5;
		this->nrArticole = 0;
		this->articole = NULL;
	}

	Ziar(string nume, int tiraj, int nrPagini, float pret, int nrArticole, const Articol* articole) {
		this->nume = nume;
		this->tiraj = tiraj;
		this->nrPagini = nrPagini;
		this->pret = pret;
		this->nrArticole = nrArticole;
		this->articole = new Articol[this->nrArticole];
		for (int i = 0; i < this->nrArticole; i++) {
			this->articole[i] = articole[i];
		}
	}

	~Ziar() {
		if (this->articole != NULL) {
			delete[]this->articole;
		}
	}
};

void main() {
	Autor autor1;
	Autor autor2("Gigel", 3);
	Autor autor3("Popescu", 5, 5000, CanCan);

	Articol articol1;
	Articol articol2("Conflict armat", autor2);
	Articol articol3("La scoala", autor3, 2023, 140);

	Ziar ziar1;
	Ziar ziar2("Romania libera");
	//Ziar ziar3("Adevarul", 4000, 18, 10, 3, new Articol[3]{ articol1, articol2, articol3 });

	Articol* articole = new Articol[3];
	articole[0] = articol1;
	articole[1] = articol2;
	articole[2] = articol3;
	Ziar ziar4("Tribuna economica", 2300, 8, 7, 3, articole);

	cout << "Autorul " << autor3.numeAutor << " are " << autor3.aniExperienta << " ani experienta, si primeste un salariu de " << autor3.salariu << endl;


	cout << "Articolul " << articol3.titlu << " este scris in anul " << articol3.anulScrierii << " si are ca autor pe " << articol3.autor.numeAutor << endl;
	
	cout << "Ziarul " << ziar4.nume << " contine " << ziar4.nrArticole << " articole, iar acestea sunt:" << endl;
	for (int i = 0; i < ziar4.nrArticole; i++) {
		cout << ziar4.articole[i].titlu << " SCRIS DE " << ziar4.articole[i].autor.numeAutor<<endl;
	}
	
	delete[]articole;

}


