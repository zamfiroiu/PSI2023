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

Categorie getCategorieByID(int id) {
	switch (id)
	{
		case 0:return Stiri;
		case 1:return CanCan;
		case 2:return Sport;
		case 3:return Divertisment;
		case 4:return Extern;
		case 5:return Politica;
		default:return Stiri;
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

	friend ostream& operator<<(ostream& consola, Autor autor) {
		consola << autor.numeAutor << " are " << autor.aniExperienta
			<< " ani de experienta, un salariu de " << autor.salariu
			<< ", si scrie de obicei in categoria: "
			<< getDenumireCategorie(autor.categorie) << endl;
		return consola;
	}

	friend istream& operator>>(istream& tastatura, Autor& autor) {
		cout << "Numele autorului:";
		tastatura >> autor.numeAutor;
		cout << "Cati ani de experienta are "<< autor.numeAutor<<":";
		tastatura >> autor.aniExperienta;
		cout << "Care este salariu primit de catre " << autor.numeAutor << ":";
		tastatura >> autor.salariu;
		cout << "In ce categorie scrie " << autor.numeAutor 
			<< ": Stiri - 0, CanCan - 1, Sport - 2, Divertisment - 3, Extern - 4, Politica - 5 ?";
		int valoareCitita = 0;
		tastatura >> valoareCitita;
		autor.categorie = getCategorieByID(valoareCitita);

		return tastatura;
	}

	bool operator>=(Autor param) {
		return this->aniExperienta >= param.aniExperienta;
	}

	bool operator==(Autor param) {
		return this->numeAutor == param.numeAutor
			&& this->aniExperienta == param.aniExperienta
			&& this->salariu == param.salariu
			&& this->categorie == param.categorie;
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

	friend ostream& operator<<(ostream& monitor, Articol articol) {
		monitor << articol.id << ". Articolul '" << articol.titlu
			<< "' are " << articol.nrRanduri << " randuri, si a fost scris in anul "
			<< articol.anulScrierii << " de catre " << articol.autor.getNumeAutor() << endl;
		return monitor;
	}
	Articol operator++() {
		this->nrRanduri += 1;
		return *this;
	}

	Articol operator++(int) {
		Articol copie = *this;
		this->nrRanduri++;
		return copie;
	}
	Articol operator+(int valoare)const {
		Articol temp = *this;
		temp.nrRanduri += valoare;
		return temp;
	}
	Articol operator+=(int valoare) {
		this->nrRanduri += valoare;
		return *this;
	}
};
int Articol::generatorID = 1;


class ArticolStiintific :public Articol {
private:
	int nrCoAutori;
	Autor* coAutori;
public:
	ArticolStiintific() :Articol() {
		this->nrCoAutori = 0;
		this->coAutori = NULL;
	}

	ArticolStiintific(const char* titlu, Autor autorPrincipal, int nrCoAutori, Autor* coAutori) :Articol(titlu, autorPrincipal) {
		this->nrCoAutori = nrCoAutori;
		this->coAutori = new Autor[this->nrCoAutori];
		for (int i = 0; i < nrCoAutori; i++) {
			this->coAutori[i] = coAutori[i];
		}
	}

	ArticolStiintific(const char* titlu, Autor autorPrincipal,int anScriere, int nrRanduri, int nrCoAutori, Autor* coAutori) :Articol(titlu, autorPrincipal,anScriere,nrRanduri) {
		this->nrCoAutori = nrCoAutori;
		this->coAutori = new Autor[this->nrCoAutori];
		for (int i = 0; i < nrCoAutori; i++) {
			this->coAutori[i] = coAutori[i];
		}
	}
	ArticolStiintific(const ArticolStiintific & articolStiintific) :Articol(articolStiintific) {
		this->nrCoAutori = articolStiintific.nrCoAutori;
		this->coAutori = new Autor[this->nrCoAutori];
		for (int i = 0; i < this->nrCoAutori; i++) {
			this->coAutori[i] = articolStiintific.coAutori[i];
		}
	}

	ArticolStiintific operator=(const ArticolStiintific& articolStiintific) {
		if (this != &articolStiintific) {
			(Articol)*this = (Articol)articolStiintific;
			this->nrCoAutori = articolStiintific.nrCoAutori;
			if (this->coAutori != NULL) {
				delete[]this->coAutori;
			}
			this->coAutori = new Autor[this->nrCoAutori];
			for (int i = 0; i < this->nrCoAutori; i++) {
				this->coAutori[i] = articolStiintific.coAutori[i];
			}
		}

		return *this;
	}

	~ArticolStiintific() {
		if (this->coAutori != NULL) {
			delete[]this->coAutori;
		}
	}

	int getNrCoAutori() const{
		return nrCoAutori;
	}

	Autor* getCoAutori() const{
		return this->coAutori;
	}

	Autor& operator[](int pozitie) const{
		if (pozitie >= 0 && pozitie < this->nrCoAutori)
			return this->coAutori[pozitie];
	}

	void setCoAutori(int nrCoAutori, Autor* coAutori) {
		if (nrCoAutori > 0) {
			this->nrCoAutori = nrCoAutori;
			if (this->coAutori) {
				delete[]this->coAutori;
			}
			this->coAutori = new Autor[nrCoAutori];
			for (int i = 0; i < this->nrCoAutori; i++) {
				this->coAutori[i] = coAutori[i];
			}
		}
	}

};

ostream& operator<<(ostream& consola, const ArticolStiintific& as) {
	consola << (Articol)as;
	consola << " si urmatori co autori: ";
	for (int i = 0; i < as.getNrCoAutori(); i++) {
		consola << as[i].getNumeAutor()<<", ";
	}
	return consola;
}

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

	Articol& operator[](int index) {
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

	friend ostream& operator<<(ostream& oStream, Ziar ziar) {
		oStream << "Ziarul " << ziar.nume << " are un tiraj de "
			<< ziar.tiraj << " numere cu " << ziar.nrPagini
			<< " pagini fiecare la un pret de " << ziar.pret
			<< " RON si contine " << ziar.nrArticole << " articole:" << endl;
		for (int i = 0; i < ziar.nrArticole; i++) {
			oStream <<"  "<< ziar.articole[i];
		}
		oStream << endl;
		return oStream;
	}	

	Ziar operator+=(Articol articol) {
		Articol* temp = new Articol[this->nrArticole + 1];
		for (int i = 0; i < this->nrArticole; i++) {
			temp[i] = this->articole[i];
		}
		temp[this->nrArticole] = articol;
		if (this->articole) {
			delete []this->articole;
		}
		this->articole = temp;
		this->nrArticole++;
		return *this;
	}

	explicit operator int() {
		return this->nrPagini;
	}

	explicit operator float() {
		return this->pret;
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

	Articol articol4("Cutremur", autor3, 2023, 450);

	ArticolStiintific as1;
	Autor* autori = new Autor[2]{ autor2,autor3 };
	ArticolStiintific as2("OOP", autor1, 2, autori);
	cout<<"Articol Stiintific:"<<endl << as2<<endl<<endl;


	Ziar ziar1;
	Ziar ziar2("Romania libera");
	//Ziar ziar3("Adevarul", 4000, 18, 10, 3, new Articol[3]{ articol1, articol2, articol3 });

	Articol* articole = new Articol[3];
	articole[0] = articol1;
	articole[1] = articol2;
	articole[2] = articol3;
	Ziar ziar4("Tribuna economica", 2300, 8, 7, 3, articole);

	cout << autor3 <<autor2<<autor1<< endl;


	cout << articol3 << articol2 << articol1 << endl;
	cout << ziar4;
	
	ziar4 += articol4; //ziar4.operator+=(articol4);
	cout << ziar4;

	cout << "Primul articol este " << ziar4[0];

	int numarPagini = (int)ziar4;
	float pretZiar = (float)ziar4;
	cout << numarPagini << " - " << pretZiar << endl;
	
	delete[]articole;

}