#include <iostream>
#include "Matriz.h"

using namespace std;

int main() {
	
	Matriz Y(4,4);
	Matriz X(3,3,2), A(3,3,3), C(3, 3,2);
	Matriz W = C;
	Matriz Z;
	cin >> Z;
	cout << Z;
	/*int numeroLinhas = A.getRows();
	int numeroColunas = A.getCols();
	Y.unit();
	Y.imprimir();
	cout << endl;
	A(2,1) = 10;
	Matriz J;
	J = X + A;
	J.imprimir();
	Y.zeros();
	C = A + A;
	C -= A;
	A = C - A;
	A += A;
	C.imprimir();
	cout << endl;
	A = ~C;
	C.imprimir();
	cout << endl;
	A.imprimir();
	cout << endl;
	X.ones();
	X *= 2;
	X.imprimir();
	cout << endl;
	if (A != C) cout << "foi" << endl;
	*/

}
