//#include<iostream>
//#include<string>
//using namespace std;
//
//enum Cifra {unu, doi, trei, patru};
//
//class Laptop {
//private:
//	static int nrLaptopuri;
//	const int id;
//	int RAM;
//	string tipCPU;
//	float rezolutieEcran;
//	bool cameraWeb;
//	int nrTaste;
//	int* nrApasariTasta;
//
//public:
//
//	Laptop operator=(const Laptop& laptop) {
//		this->RAM = laptop.RAM;
//		this->tipCPU = laptop.tipCPU;
//		this->rezolutieEcran = laptop.rezolutieEcran;
//		this->cameraWeb = laptop.cameraWeb;
//		this->nrTaste = laptop.nrTaste;
//		if (this->nrApasariTasta != NULL) {
//			delete[]nrApasariTasta;
//		}
//		this->nrApasariTasta = new int[this->nrTaste];
//		for (int i = 0; i < this->nrTaste; i++) {
//			this->nrApasariTasta[i] = laptop.nrApasariTasta[i];
//		}
//
//		return *this;
//	}
//
//
//
//	int getID() {
//		return id;
//	}
//	int getRAM() {
//		return RAM;
//	}
//	string getTipCPU() {
//		return tipCPU;
//	}
//	float getRezolutieEcran() {
//		return rezolutieEcran;
//	}
//	bool hasCameraWeb() {
//		return cameraWeb;
//	}
//
//	void setRAM(int RAM) {
//		if (RAM > 0) {
//			this->RAM = RAM;
//		}
//	}
//
//	void setTipCPU(string tipCPU) {
//		if (tipCPU.length() > 0) {
//			this->tipCPU = tipCPU;
//		}
//	}
//
//	void setRezolutieEcran(float rezolutieEcran) {
//		if (rezolutieEcran > 10) {
//			this->rezolutieEcran = rezolutieEcran;
//		}
//	}
//
//	void setCameraWeb(bool cameraWeb) {
//		this->cameraWeb = cameraWeb;
//	}
//
//	~Laptop() {
//		//dezalocari din HEAP
//	}
//
//	int getNrTaste() const {
//		return nrTaste;
//	}
//
//	void setNrTaste(int nr) {
//		nrTaste = nr;
//	}
//
//	int* getNrApasariTasta() {
//		return nrApasariTasta;
//	}
//
//	int getNrApasariTastaByPozitie(int index) {
//		if (index >= 0 && index < this->nrTaste) {
//			return this->nrApasariTasta[index];
//		}
//	}
//
//
//	int& operator[](int index) {
//		if (index >= 0 && index < nrTaste) {
//			return this->nrApasariTasta[index];
//		}
//	}
//
//	int& operator[](Cifra cifra) {
//		if (cifra == unu) {
//			return nrApasariTasta[1];
//		}
//		if (cifra == doi) {
//			return nrApasariTasta[2];
//		}
//	}
//
//	void setNrApasariTasta(int* vector, int dim) {
//		if (dim > 0 && vector != NULL) {
//			if (this->nrApasariTasta != NULL) {
//				delete[]nrApasariTasta;
//			}
//			nrApasariTasta = new int[dim];
//			for (int i = 0; i < dim; i++) {
//				nrApasariTasta[i] = vector[i];
//			}
//			nrTaste = dim;
//		}
//	}
//
//	Laptop() :id(0) {
//		RAM = 16;
//		tipCPU = "AMD";
//		rezolutieEcran = 13.3;
//		this->cameraWeb = true;
//		this->nrLaptopuri++;
//		nrTaste = 0;
//		nrApasariTasta = NULL;
//	}
//
//	Laptop(int RAM, string tipCPU, float rezolutie, bool camera) :id(0) {
//		this->RAM = RAM;
//		this->tipCPU = tipCPU;
//		this->rezolutieEcran = rezolutie;
//		this->cameraWeb = camera;
//	}
//
//	Laptop(int RAM, string tipCPU, float rezolutie, bool camera, int nrTaste, int* nrApasariTaste) :id(0) {
//		this->RAM = RAM;
//		this->tipCPU = tipCPU;
//		this->rezolutieEcran = rezolutie;
//		this->cameraWeb = camera;
//		this->nrTaste = nrTaste;
//		this->nrApasariTasta = new int[nrTaste];
//		for (int i = 0; i < nrTaste; i++) {
//			this->nrApasariTasta[i] = nrApasariTaste[i];
//		}
//	}
//
//	Laptop(int RAM, float rezolutie, bool camera) :id(0) {
//		this->RAM = RAM;
//		this->tipCPU = "Intel";
//		this->rezolutieEcran = rezolutie;
//		this->cameraWeb = camera;
//	}
//
//	Laptop operator+(Laptop l2) {//l1 - este in this
//		Laptop aux = *this;
//		aux.RAM = this->RAM + l2.RAM;
//		return aux;
//	}
//
//	Laptop operator+(int valoare)const {
//		Laptop aux = *this;
//		aux.RAM = this->RAM + valoare;
//		return aux;
//	}
//
//	Laptop operator+=(int valoare) {
//		this->RAM += valoare;
//		return *this;
//	}
//
//
//
///*
//* int a=8;
//* int b=a+2;
//* a+=3;
//* 
//* 
//*/
//
//
//	//friend Laptop operator+ (int valoare, Laptop l);
//
//	friend Laptop operator+ (int valoare, Laptop laptop) {
//		Laptop aux = laptop;
//		aux.RAM = laptop.RAM + valoare;
//		return aux;
//	}
//
//	bool operator<(Laptop l) {
//		return this->RAM < l.RAM;
//	}
//
//	//void operator<<(ostream& consola) {
//	//	consola << this->id << " " << this->RAM << " " << this->tipCPU << " ";
//	//	consola << this->nrTaste << " " << this->rezolutieEcran << " cu numarul de apasari:";
//	//	for (int i = 0; i < this->nrTaste; i++) {
//	//		consola << this->nrApasariTasta[i];
//	//	}
//	//}
//
//	friend ostream& operator<<(ostream& oStream, const Laptop& laptop) {
//		oStream << laptop.id << " " << laptop.RAM << " " << laptop.tipCPU << " ";
//		oStream << laptop.nrTaste << " " << laptop.rezolutieEcran << " cu numarul de apasari:";
//		for (int i = 0; i < laptop.nrTaste; i++) {
//			oStream << laptop.nrApasariTasta[i];
//		}
//		return oStream;
//	};
//	friend istream& operator>>(istream& iStream, Laptop& laptop) {
//		cout << "RAM:";
//		iStream >> laptop.RAM;
//		cout << "Tip CPU:";
//		iStream >> laptop.tipCPU;
//		cout << "Rezolutie:";
//		iStream >> laptop.rezolutieEcran;
//		cout << "Numar taste:";
//		iStream >> laptop.nrTaste;
//		if (laptop.nrApasariTasta != NULL) {
//			delete[]laptop.nrApasariTasta;
//		}
//		laptop.nrApasariTasta = new int[laptop.nrTaste];
//		for (int i = 0; i < laptop.nrTaste; i++) {
//			cout << "Numarul de apasari pentru tasta " << (i + 1) << ":";
//			iStream >> laptop.nrApasariTasta[i];
//		}
//		return iStream;
//	};
//
//	Laptop operator++() {
//		this->RAM += 1;
//		return *this;
//	}
//
//	Laptop operator++(int) {
//		Laptop stareInitiala = *this;
//		this->RAM+=1;
//		return stareInitiala;
//	}
//
//
//
//
//	explicit operator int() {
//		return this->RAM;
//	}
//
//	Laptop operator! () {
//		Laptop copie = *this;
//		copie.cameraWeb = !copie.cameraWeb;
//		return copie;
//	}
//
//	//numarul total de apasari
//	int operator()() {
//		int suma = 0;
//		for (int i = 0; i < this->nrTaste; i++) {
//			suma += this->nrApasariTasta[i];
//		}
//		return suma;
//	}
//
//	//numarul de apasari pt primele n taste
//	int operator()(int n) {
//		if (n > 0 && n < this->nrTaste) {
//			int suma = 0;
//			for (int i = 0; i < n; i++) {
//				suma += this->nrApasariTasta[i];
//			}
//			return suma;
//		}
//		else {
//			return 0;
//		}
//	}
//
//	//numarul de apasari pt tastele dintr-un interval
//	int operator()(int start, int end) {
//		if (start > 0 && start < this->nrTaste && end <= this->nrTaste && start < end) {
//			int suma = 0;
//			for (int i = start - 1; i < end; i++) {
//				suma += this->nrApasariTasta[i];
//			}
//			return suma;
//		}
//		else {
//			return 0;
//		}
//	}
//
//	Laptop* operator->() {
//		//this->RAM = 1000;
//		return this;
//	}
//
//
//
//};
//
////Laptop operator+(Laptop l2,Laptop l3) {//l1 - este in this
////	Laptop aux = l2;
////	aux.RAM = this->RAM + l2.RAM;
////	return aux;
////}
//
//int Laptop::nrLaptopuri = 0;
//
//
////ostream& operator<<(ostream& oStream, Laptop laptop) {
////	oStream << laptop.id << " " << laptop.RAM << " " << laptop.tipCPU<<" ";
////	oStream << laptop.nrTaste << " " << laptop.rezolutieEcran << " cu numarul de apasari:";
////	for (int i = 0; i < laptop.nrTaste; i++) {
////		oStream << laptop.nrApasariTasta[i];
////	}
////	return oStream;
////}
////istream& operator>>(istream& iStream, Laptop& laptop) {
////	cout << "RAM:";
////	iStream >> laptop.RAM;
////	cout << "Tip CPU:";
////	iStream >> laptop.tipCPU;
////	cout << "Rezolutie:";
////	iStream >> laptop.rezolutieEcran;
////	cout << "Numar taste:";
////	iStream >> laptop.nrTaste;
////	if (laptop.nrApasariTasta != NULL) {
////		delete[]laptop.nrApasariTasta;
////	}
////	laptop.nrApasariTasta = new int[laptop.nrTaste];
////	for (int i = 0; i < laptop.nrTaste; i++) {
////		cout << "Numarul de apasari pntru tasta " << (i + 1) << ":";
////		iStream >> laptop.nrApasariTasta[i];
////	}
////	return iStream;
////}
////
//
//
//
//
//void main() {
//
//	Laptop laptop33;
//	cout<<laptop33.getRAM()<<endl;
//
//	Laptop* pLaptop = new Laptop();
//	cout << (*pLaptop).getRAM()<<endl;
//	cout << pLaptop->getRAM()<<endl;
//
//	cout << laptop33->getRAM();
//
//	//int a = 10;
//	//int b = 5;
//	//a = ++b;
//	//cout << a << " " << b<<endl;
//	//// 6 - 6
//
//	//int x = 10;
//	//int y = 5;
//	//x = y++;
//	//cout << x << " " << y;
//	////5 - 6
//	
//	// 
//	//Laptop laptop1;
//	//
//	//cout << laptop1 << endl;
//	 //rezultatPrimit << endl;
//	//cout << 3;
//	//cout << laptop1;
//	//Laptop laptop2;
//	//cout << laptop2;
//	//Laptop laptop3;
//
//	////laptop3 = laptop1 + laptop2;
//	//laptop3 = laptop1 + 4;
//	//laptop3 = 4 + laptop2;
//	////int val = aptop + 4;
//	////etc
//
//	//Laptop laptop6;
//	////cin >> laptop6;
//	////cout << laptop6;
//
//
//
//
//	//laptop1.setRAM(6);
//	//laptop2 = laptop1++;
//	////laptop2- 6; laptop - 7
//
//	//laptop1.setRAM(6);
//	//laptop3 = ++laptop1;
//	////laptop3 -7; laptop - 7
//
//
//	//Laptop laptop9(10, "Intel", 13, true, 4, new int[4]{ 10,12,13,7 });
//	//cout << laptop9[0];
//
//	//laptop9[0] = 4;
//
//
//
//	////int memorieRAMImplicit = laptop9;
//	//int memorieRAMExplicit = (int)laptop9;
//
//
//	//Laptop laptop10(10, "Intel", 13, true, 4, new int[4]{ 10,12,13,7 });
//	//cout << endl;
//	//cout << laptop10() << endl;//42
//	//cout << laptop10(2)<<endl;//22
//	//cout << laptop10(2, 4)<<endl;//32
//
//	//cout << endl << endl;
//
//
//	//Laptop l34;
//	//l34.setRAM(1);
//	//cout << l34.getRAM() << endl;
//	//cout << l34->getRAM() << endl;
//
//	//Laptop L23{ 16,"INTEL",17,true,3,new int[3] {45, 27, 6} };
//	//Laptop L24;
//	//L23 = L24 + L24;
//	//L23 = L24.operator+(L24);
//
//	//cout << L23;
//	//cin >> L23;
//
//	////if (L23.getRAM() < L24.getRAM()) {
//
//	////}
//
//	////if (L23 < L24) {
//
//	////}
//
//	//L23.getNrApasariTasta()[1];
//	//L23.getNrApasariTastaByPozitie(1);
//	//L23[2]=16;
//
//	//L23 = !L24;
//	//cout << l34;
//	//cin >> l34;
//	//l34++;
//	//l34.setRezolutieEcran(l34.getRAM()+1);
//
//	//int* vector = new int[5] {10, 5, 7, 15, 9};
//	//Laptop l45(12,"Amd", 15, true, 5, vector);
//
//	//for (int i = 0; i < l45.getNrTaste(); i++) {
//	//	//cout << l45.getNrApasariTasta()[i] << ", ";
//	//	//cout << l45.getNrApasariTastaByPozitie(i) << ", ";
//	//	cout << l45[i]<<", ";
//	//}
//
//	//int a = l45[unu];
//	//l45[unu] = 67;
//
//	//cout << endl;
//
//	//for (int i = 0; i < l45.getNrTaste(); i++) {
//	//	cout << l45[i] << ", ";
//	//}
//
//	//float a = 4.5;
//	//int b=a;
//
//	//int x = 8;
//	//float y = x;
//
//	//Laptop l56;
//	//int n = 156;
//	//int m = (int)l56;
//
//	//Laptop l57 = !l56;
//	
//}