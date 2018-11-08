#include <iostream>
#include "Matriz.h"

using namespace std;

int main() {
	Matriz A;
	Matriz B(3, 3);
	Matriz C(3, 3, 3), D(3,3,4),E(3,3,5);
	Matriz F = C;
	Matriz G(E);
	Matriz H(3, 3, 8);
	Matriz X;
	
	int keep = 1;
	
	do {
		cout << "Escolhe as opcoes abaixo:" << endl;
		cout << endl << "0. Para sair" << endl;
		cout << endl << "1. Escrever uma matriz X" << endl;
		cout << endl << "2. Imprimir Matrizes criadas" << endl;
		cout << endl << "3. A = C + D" << endl;
		cout << endl << "4. G += H" << endl;
		cout << endl << "5. F = E - D" << endl;
		cout << endl << "6. F -= D" << endl;
		cout << endl << "7. Transformar matriz H em identidade" << endl;
		cout << endl << "8. Transformar matriz C = transposta de X" << endl;
		cout << endl << "9. Transformar todos os elementos da matriz H em valores iguais a 0" << endl;
		cout << endl << "10. Transformar todos os elementos da matriz H em valores iguais a 1" << endl;
		cout << endl << "11. F *= 2" << endl;
		cout << endl << "12. F = D * E" << endl;
		cout << endl << "13. F *= D" << endl;
		cout << endl << "14. F(2,2) = 123,32" << endl;
		cout << endl << "15. F == C" << endl;
		cout << endl << "16. F != C" << endl;

		cout << endl;
		cin >> keep;
		system("cls || clear");
		switch (keep) {
			case 1:
				cin >> X;
			case 2:
				cout << "A:" << endl << A << endl;
				cout << "B:" << endl << B << endl;
				cout << "C:" << endl << C << endl;
				cout << "D:" << endl << D << endl;
				cout << "E:" << endl << E << endl;
				cout << "F:" << endl << F << endl;
				cout << "G:" << endl << G << endl;
				cout << "H:" << endl << H << endl;
				cout << "X:" << endl << X << endl;
				break;
			case 3:
				cout << "A antes da soma:" << endl << A << endl;
				A = C + D;
				cout << "A depois da soma:" << endl << A << endl;
				cout << "C:" << endl << C << endl;
				cout << "D:" << endl << D << endl;
				break;
			case 4:
				cout << "G antes da soma:" << endl << G << endl;
				G += H;
				cout << "G depois da soma:" << endl << G << endl;
				cout << "H:" << endl << H << endl;
				break;
			case 5:
				cout << "F antes da subtracao:" << endl << F << endl;
				F = E - D;
				cout << "F depois da subtracao:" << endl << F << endl;
				cout << "E:" << endl << E << endl;
				cout << "D:" << endl << D << endl;
				break;
			case 6:
				cout << "F antes da subtracao:" << endl << F << endl;
				F -= D;
				cout << "F depois da subtracao:" << endl << F << endl;
				cout << "D:" << endl << D << endl;
				break;
			case 7:
				cout << "H antes de virar identidade:" << endl << H << endl;
				H.unit();
				cout << "H identidade:" << endl << H << endl;
				break;
			case 8:
				cout << "C sem ser transposta de X:" << endl << C << endl;
				C =~ X;
				cout << "C transposta de X:" << endl << C << endl;
				cout << "X:" << endl << X << endl;
				break;
			case 9:
				cout << "H antes dos zeros:" << endl << H << endl;
				H.zeros();
				cout << "H cheio de zeros:" << endl << H << endl;
				break;
			case 10:
				cout << "H antes dos ones:" << endl << H << endl;
				H.ones();
				cout << "H depois dos ones:" << endl << H << endl;
				break;
			case 11:
				cout << "F antes da multiplicao por 2:" << endl << F << endl;
				F *= 2;
				cout << "F depois da multiplicao por 2:" << endl << F << endl;
				break;
			case 12:
				cout << "F antes da multiplicacao:" << endl << F << endl;
				F = D * E;
				cout << "F depois da multiplicacao:" << endl << F << endl;
				cout << "D:" << endl << D << endl;
				cout << "E:" << endl << E << endl;
				break;
			case 13:
				cout << "F antes da multiplicacao:" << endl << F << endl;
				F *= D;
				cout << "F depois da multiplicacao:" << endl << F << endl;
				cout << "D:" << endl << D << endl;
				break;
			case 14:
				cout << "F antes da mudanca:" << endl << F << endl;
				F(2, 2) = 123, 32;
				cout << "F depois da mudanca:" << endl << F << endl;
				break;
			case 15:
				if (F == C) {
					cout << "F eh igual a C" << endl;
					cout << "F:" << endl << F << endl;
					cout << "C:" << endl << C << endl;
				}
				else {
					cout << "F NAO eh igual a C" << endl;
					cout << "F:" << endl << F << endl;
					cout << "C:" << endl << C << endl;
				}
				break;
			case 16:
				if (F != C) {
					cout << "F eh diferente de C" << endl;
					cout << "F:" << endl << F << endl;
					cout << "C:" << endl << C << endl;
				}
				else {
					cout << "F NAO eh diferente de C" << endl;
					cout << "F:" << endl << F << endl;
					cout << "C:" << endl << C << endl;
				}
				break;
			default:
				break;
		}
		cout << endl << "Deseja Continuar?" << endl;
		cout << "Digite qualquer numero para SIM." << endl << "Digite 0 para sair" << endl;
		cin >> keep;
	} while (keep);
}
