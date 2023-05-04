//#include<iostream>
//
//using namespace std;
//
//class Clasa {
//public:
//	char* pointer;
//	int atribut;										 //c2=c2;
//
//	const Clasa& operator=(const Clasa& c) { //operator=(Clasa* this, const Clasa& c)
//		//verificare de autoasignare
//		if (this != &c) {
//			if (this->pointer != NULL)
//			{
//				delete[]this->pointer;
//			}
//
//			this->pointer = new char[strlen(c.pointer) + 1];
//			strcpy_s(this->pointer, strlen(c.pointer) + 1, c.pointer);
//			this->atribut = c.atribut;
//		}
//		return *this;
//	}
//
//	Clasa(const Clasa& c) {
//		this->pointer = new char[strlen(c.pointer) + 1];
//		strcpy_s(this->pointer, strlen(c.pointer) + 1, c.pointer);
//		this->atribut = c.atribut;
//	}
//
//	Clasa() {
//		this->pointer = NULL;
//	}
//
//	~Clasa() {
//		if (this->pointer) {
//			delete[]this->pointer;
//		}
//	}
//
//	void metoda(const Clasa& c) {
//
//	}
//
//	Clasa metoda2() {
//		Clasa c;
//		c.pointer = new char[strlen("default") + 1];
//		strcpy_s(c.pointer, strlen("default") + 1, "default");
//		return c;
//	}
//
//
//};
//
//
//void main() {
//	Clasa c1;
//	c1.pointer = new char[strlen("text") + 1];
//	strcpy_s(c1.pointer, strlen("text") + 1, "text");
//	c1.atribut = 10;
//
//
//	Clasa c2(c1); //Clasa c2=c1;
//	strcpy_s(c2.pointer,5, "newT");
//
//	//Clasa c3;
//	//c3 = c2 = c1;
//
//	//cout << c1.pointer;
//
//	c2 = c2;
//
//
//
//
//	//Clasa c1;
//	//c1.pointer = new char[strlen("text") + 1];
//	//strcpy(c1.pointer, "text");
//
//	////c1.metoda(c1);
//	////c1.metoda2();
//
//	//Clasa c2;
//	//c2 = c1;
//
//	//c1.metoda(c2);
//
//	//c2=c1.metoda2();
//
//}