#include<iostream>

using namespace std;

//ZIar

enum Categorie {
	Stiri, CanCan, Sport, Divertisment, Extern, Politica
};

string getDenumireCategorie(Categorie categorie) {
	switch (categorie)
	{
	case Stiri:return "Stiri";
		break;
	case CanCan: return "CanCan";
		break;
	case Sport: return "Sport";
		break;
	case Divertisment: return "Divertisment";
		break;
	case Extern:return "Extern";
		break;
	case Politica:return "Politica";
		break;
	default: return "Categorie neidentificata.";
		break;
	}
}

class Autor {
private:
	string numeAutor;
	int aniExperienta;
	float salariu;
	Categorie categorie;
public:
	Autor() {
		this->numeAutor = "Anonim";
		this->aniExperienta = 0;
		this->salariu = 10;
		this->categorie = Stiri;
	}

	Autor(string numeAutor, int nrAniExperienta) {
		this->numeAutor = numeAutor;
		this->aniExperienta = nrAniExperienta;
		this->salariu = 20;
		this->categorie = Stiri;
	}

	Autor(string numeAutor, int aniExperienta, float salariu, Categorie categorie) {
		this->numeAutor = numeAutor;
		this->aniExperienta = aniExperienta;
		this->salariu = salariu;
		this->categorie = categorie;
	}

	Autor(const Autor& a) {
		this->numeAutor = a.numeAutor;
		this->aniExperienta = a.aniExperienta;
		this->salariu = a.salariu;
		this->categorie = a.categorie;
	}

	Autor operator=(const Autor& a) {
		this->numeAutor = a.numeAutor;
		this->aniExperienta = a.aniExperienta;
		this->salariu = a.salariu;
		this->categorie = a.categorie;
		return *this;
	}
	
	string getNumeAutor() const{
		return this->numeAutor;
	}
	void setNumeAutor(string nouaValoare) {
		if (nouaValoare.length() >= 3) {
			this->numeAutor = nouaValoare;
		}
	}
	int getNumarAniExperienta() const{
		return this->aniExperienta;
	}
	void setAniExperienta(int nouaExperienta) {
		if (nouaExperienta > 0) {
			this->aniExperienta = nouaExperienta;
		}
	}
	float getSalariu() const{
		return this->salariu;
	}
	void setSalariu(float salariu) {
		if (salariu > 0) {
			this->salariu = salariu;
		}
	}
	Categorie getCategorie() const {
		return this->categorie;
	}
	void setCategorie(Categorie categorie) {
		this->categorie = categorie;
	}
};

class Articol {
private:
	static int generatorID;
	const int id;
	char* titlu;
	Autor autor;
	int anulScrierii;
	int nrRanduri;
public:
	Articol() :id(generatorID), autor() {
		generatorID++;
		this->titlu = new char[strlen("Articol") + 1];
		strcpy_s(this->titlu, strlen("Articol") + 1, "Articol");
		this->anulScrierii = 2023;
		this->nrRanduri = 200;
	}

	Articol(const char* titlu, Autor autor) : id(generatorID++) {
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
	Articol(const Articol& a) :id(generatorID++) {
		this->titlu = new char[strlen(a.titlu) + 1];
		strcpy_s(this->titlu, strlen(a.titlu) + 1, a.titlu);
		this->autor = a.autor;
		this->anulScrierii = a.anulScrierii;
		this->nrRanduri = a.nrRanduri;
	}

	Articol& operator=(const Articol& a) {
		if (&a != this) {
			if (this->titlu != NULL) {
				delete[]this->titlu;
			}
			this->titlu = new char[strlen(a.titlu) + 1];
			strcpy_s(this->titlu, strlen(a.titlu) + 1, a.titlu);
			this->autor = a.autor;
			this->anulScrierii = a.anulScrierii;
			this->nrRanduri = a.nrRanduri;
		}
		return *this;
	}

	~Articol() {
		if (this->titlu != NULL) {
			delete[]this->titlu;
		}
	}
	int getID() const {
		return this->id;
	}
	char* getTitlu() const {
		return this->titlu;
	}

	void setTitlu(const char* titlu) {
		if (strlen(titlu) > 5) {
			if (this->titlu != NULL) {
				delete[]this->titlu;
			}
			this->titlu = new char[strlen(titlu) + 1];
			strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
		}

	}
	Autor& getAutor()  {
		return this->autor;
	}
	void setAutor(const Autor& a) {
		this->autor = a;
	}
	int getAnScriere() const{
		return this->anulScrierii;
	}
	void setAnScriere(int anScriere) {
		if (anScriere > 2000) {
			this->anulScrierii = anScriere;
		}
	}
	int getNrRanduri() const{
		return this->nrRanduri;
	}
	void setNrRanduri(int nrRanduri) {
		if (nrRanduri > 2) {
			this->nrRanduri = nrRanduri;
		}
	}

	static int getValoareGenerator() {
		return Articol::generatorID;
	}
};
int Articol::generatorID = 1;

class Ziar {
private:
	string nume;
	int tiraj;
	int nrPagini;
	float pret;
	int nrArticole;
	Articol* articole;
public:
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

	Ziar(const Ziar& z) {
		this->nume = z.nume;
		this->tiraj = z.tiraj;
		this->nrPagini = z.nrPagini;
		this->pret = z.pret;
		this->nrArticole = z.nrArticole;
		this->articole = new Articol[this->nrArticole];
		for (int i = 0; i < this->nrArticole; i++) {
			this->articole[i] = z.articole[i];
		}
	}

	Ziar operator=(const Ziar& z) {
		if (&z != this) {
			this->nume = z.nume;
			this->tiraj = z.tiraj;
			this->nrPagini = z.nrPagini;
			this->pret = z.pret;
			this->nrArticole = z.nrArticole;
			if (this->articole) {
				delete[]this->articole;
			}
			this->articole = new Articol[this->nrArticole];
			for (int i = 0; i < this->nrArticole; i++) {
				this->articole[i] = z.articole[i];
			}
		}
		return *this;
	}

	~Ziar() {
		if (this->articole != NULL) {
			delete[]this->articole;
		}
	}
	string getNume() const{
		return this->nume;
	}
	void setNume(string nume) {
		if (nume.length() > 2) {
			this->nume = nume;
		}
	}
	int getTiraj() const{
		return this->tiraj;
	}
	void setTiraj(int tiraj) {
		if (tiraj > 0) {
			this->tiraj = tiraj;
		}
	}
	int getNrPagini() const{
		return this->nrPagini;
	}
	void setNrPagini(int nr) {
		if (nr > 0) {
			this->nrPagini = nr;
		}
	}
	float getPret() const{
		return this->pret;
	}
	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}
	int getNrArticole() const { //getNrArticole(const Articol* this)
		return this->nrArticole;
	}
	Articol* getArticole() const {
		return this->articole;
	}
	Articol& getArticol(int index) const{
		if (index >= 0 && index < this->nrArticole) {
			return this->articole[index];
		}
	}

	void setArticole(Articol* articole, int nrArticole) {
		if (nrArticole > 0 && articole != NULL) {
			if (this->articole != NULL) {
				delete[]this->articole;
			}
			this->articole = new Articol[nrArticole];
			for (int i = 0; i < nrArticole; i++) {
				this->articole[i] = articole[i];
			}
			this->nrArticole = nrArticole;
		}
	}

	
};


int calculeazaNumarRanduriTotal(const Ziar& ziar)
{
	int nrRanduriTotal = 0;
	for (int i = 0; i < ziar.getNrArticole(); i++) {
		nrRanduriTotal += ziar.getArticol(i).getNrRanduri();
	}
	return nrRanduriTotal;
}

int calculeazaTotalSalarii(const Ziar& ziar)
{
	int costuriSalariale = 0;
	for (int i = 0; i < ziar.getNrArticole(); i++) {
		costuriSalariale += ziar.getArticol(i).getAutor().getSalariu();
	}
	return costuriSalariale;
}


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

	cout << "Autorul " << autor3.getNumeAutor() << " are " << autor3.getNumarAniExperienta() << " ani experienta, si primeste un salariu de " << autor3.getSalariu() << endl;


	cout << "Articolul " << articol3.getTitlu() << " este scris in anul " << articol3.getAnScriere() << " si are ca autor pe " << articol3.getAutor().getNumeAutor() << endl;

	cout << "Ziarul " << ziar4.getNume() << " contine " << ziar4.getNrArticole() << " articole, iar acestea sunt:" << endl;
	for (int i = 0; i < ziar4.getNrArticole(); i++) {
		cout << ziar4.getArticol(i).getTitlu() << " SCRIS DE " << ziar4.getArticol(i).getAutor().getNumeAutor() << endl;
	}

	cout<<ziar4.getArticole()[1].getTitlu()<<endl;
	cout<<ziar4.getArticol(2).getTitlu()<<endl;

	cout<<"Numarul de randuri din ziar: " << calculeazaNumarRanduriTotal(ziar4) << endl;
	cout << "Total Salarii: " << calculeazaTotalSalarii(ziar4);
	delete[]articole;

}