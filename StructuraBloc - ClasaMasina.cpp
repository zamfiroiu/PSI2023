#include<iostream>

using namespace std;

struct Bloc {
	string strada;
	int numarStrada;
	int nrEtaje;
	int nrScari;
	int nrLocatari;
	string tipConstructie;
	bool esteAnvelopat;
};

class BlocTurn {

};

class Carte {
	string titlu;
	int nrPagini;
	string gen;
};

class Masina {
public:
	static int nrMasini;
	static int TVA;
	const float cc;
	float combustibilDisponibil;
	string producator;
	int nrUsi;
	int nrCauciucuri;
	string* cauciucuri;
public:
	//void alimentare(Masina * this, float nrLitriCombustibil);
	void alimentare(float nrLitriCombustibil) {
		this->combustibilDisponibil += nrLitriCombustibil;
	}
	Masina():cc(2), combustibilDisponibil(10) {
		nrMasini++;
		this->producator = "Dacia";
		this->nrUsi = 5;
		this->nrCauciucuri = 4;
		this->cauciucuri = new string[this->nrCauciucuri];
		for (int i = 0; i < this->nrCauciucuri; i++) {
			this->cauciucuri[i] = "Michellin";
		}
	}

	Masina(string mProducator):cc(2) {
		nrMasini++;
		this->combustibilDisponibil = 10;
		this->producator = mProducator;
		this->nrUsi = 5;
		this->nrCauciucuri = 4;
		this->cauciucuri = new string[this->nrCauciucuri];
		for (int i = 0; i < this->nrCauciucuri; i++) {
			this->cauciucuri[i] = "Michellin";
		}
	}

	Masina(float mCC, float combustibilDisponibil, string producator,
		int nrUsi, int nrCauciucuri, string* cauciucuri):cc(mCC) {
		nrMasini++;
		this->combustibilDisponibil = combustibilDisponibil;
		this->producator = producator;
		this->nrUsi = nrUsi;
		this->nrCauciucuri = nrCauciucuri;
		this->cauciucuri = new string[this->nrCauciucuri];
		for (int i = 0; i < this->nrCauciucuri; i++) {
			this->cauciucuri[i] = cauciucuri[i];
		}
	}
	~Masina() {
		if (this->cauciucuri != NULL) {
			delete[]this->cauciucuri;
		}
	}
};

int Masina::TVA = 19;
int Masina::nrMasini = 0;


void main() {
	{
		Masina masina1;
	}
	Masina masina2("Audi");

	string cauciucuri[4]{ "Michellin", "Bridgestone","Michellin", "Bridgestone" };
	Masina masina3(3, 30, "Ford", 5, 4, cauciucuri);

	cout << masina3.cauciucuri[2] << endl;
	//cout << masina1.nrUsi;

	cout << "Nr masini"<<Masina::nrMasini;

}