#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
using namespace std;

class Matriz {
private:
	int line, column;
	double** matriz;
	
public:
	//Construtores
		Matriz(int linhas =0, int colunas= 0,const double &valor = 0);
		Matriz(const Matriz &m);
		~Matriz();
	//Funções Membro
		void unit();
		void zeros();
		void ones();
		int getRows() const;
		int getCols() const;
	//Sobrecarga de Operadores
		Matriz& operator=(const Matriz&);
		Matriz& operator*=(const int &right);
		Matriz& operator+=(const Matriz&);
		Matriz& operator-=(const Matriz&);
		Matriz& operator*=(const Matriz&);
		Matriz operator+(const Matriz&);
		Matriz operator-(const Matriz&);
		Matriz operator~();
		Matriz operator*(const Matriz&);

		bool operator==(const Matriz&);
		bool operator!=(const Matriz&);
		double& operator()(const int &linhas, const int &colunas);

		friend istream& operator>>(istream&, Matriz&);
		friend ostream& operator<<(ostream&, const Matriz&);
};

inline int Matriz::getRows() const { return(line); }
inline int Matriz::getCols() const { return(column); }

#endif // !MATRIZ_H
