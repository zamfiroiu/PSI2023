//#include<iostream>
//#include<string>
//
//using namespace std;
//
//void main() {
//	int intreg = 10;
//
//	int* pIntreg = &intreg;
//
//	int* *ppIntreg = &pIntreg;
//
//	//cout << **ppIntreg<<endl;
//
//	//cout << *ppIntreg<<endl;
//
//	//cout << ppIntreg<<endl;
//
//	//cout << endl << sizeof(int*) << endl;
//
//	
//	//int a = 3;
//	//int b = 5;
//	//a = ++b;//preincrementare
//	//a=? 4 5 6 4
//	//b=? 6 7 6 8
//
//
//	//int a = 3;
//	//int b = 5;
//	//a = b++;//postincrementare
//	//a = ? 5
//	//b = ? 6
//
//	int v1 = 6;
//	int v2 = 8;
//	int v3 = 3;
//	int v4 = 5;
//
//	int lungimeVector = 4;
//	int vector[100];//alocare de spatiu pe stiva;
//	vector[0] = 6;
//	vector[1] = 8;
//	vector[2] = 3;
//	vector[3] = 5;
//
//	for (int i = 0; i < lungimeVector; i++) {
//		cout << vector[i] << " ";
//	}
//	cout << endl;
//
//	int dim = 5;
//	cout << "Introduceti numarul de elemente dorite:";
//	cin >> dim;
//	int* colectie;
//	colectie = new int[dim];
//	for (int i = 0; i < dim; i++) {
//		colectie[i] = i + 1;
//	}
//
//	for (int i = 0; i < dim; i++) {
//		cout << colectie[i] << " ";
//	}
//
//	delete[]colectie;
//	int a = 10;
//	a = 20;
//	a = 70;
//	const int b = 20;
//	b = 90;
//}