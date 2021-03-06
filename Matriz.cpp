#include <iostream>
#include <exception>
#include "Matriz.h"
using namespace std;

Matriz::Matriz(int linhas, int colunas, const double &valor) { //Construtor único, recebe, respecivamente, o valor das linhas, coolunas
								//e o valor inicial pelo qual a matriz será preenchida. O valor default para cada um é zero
	line = linhas;
	column = colunas; 
	matriz = new double*[linhas];

	for (int k = 0; k < linhas; k++) {
		matriz[k] = new double[colunas];
	}

	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			matriz[i][j] = valor;
		}
	}
}

Matriz::Matriz(const Matriz &m){ //Construtor de cópia, recebe uma matriz e cria outra idêntica (A=B)
	line = m.line;
	column = m.column;

	matriz = new double*[line]; //alocação dinâmica

	for (int k = 0; k < line; k++) { //alocação dinância
		matriz[k] = new double[column];
	}

	for (int i = 0; i <line; i++) { //cópia de valores
		for (int j = 0; j < column; j++) {
			matriz[i][j] = m.matriz[i][j];
		}
	}
}

Matriz::~Matriz() //destrutor, simplesmente desaloca a memória
{
	for (int i = 0; i < line; ++i)
		delete[]matriz[i];

	delete[]matriz;
}

void Matriz::unit() { //função que torna uma matriz em sua respectiva matriz identidade
	if (line != column) return; //caso não quadrada, não opera
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++){
			if (i == j)
				matriz[i][j] = 1;
			else
				matriz[i][j] = 0;
		}
	}
}

void Matriz::zeros() { //função que preenche uma matriz de zeros
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			matriz[i][j]=0;
		}
	}
}

void Matriz::ones() { //função que preenche uma matriz de uns
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			matriz[i][j] = 1;
		}
	}
}

//Sobrecarga de operador

Matriz& Matriz::operator=(const Matriz& right) 
{
	if (this == &right) return *this; //confere pelo endereço de memória dos objetos se ele não são o mesmo, para evitar recursão infinita e indesejável
	for (int i = 0; i < line; ++i)  //desaloca memória da matriz à esquerda da operação(objeto que manifesta o comportamento .operator=() )
		delete[]matriz[i];

	delete[]matriz;

		line = right.line; //copia os atributos da matriz à direita 
		column = right.column;

		matriz = new double*[line]; //aloca memória de acordo

		for (int k = 0; k < line; k++) {
			matriz[k] = new double[column];
		}

		for (int i = 0; i < line; i++) { //copia valores
			for (int j = 0; j < column; j++) {
				matriz[i][j] = right.matriz[i][j];
			}
		}

	return *this; //retorna o objeto que manifestou o comportamento para permitir operações do tipo A=B=C=D
}

double& Matriz::operator()(const int &linhas, const int &colunas) { //acessa um elemento específico de uma matriz por meio de um valor linear e de coluna, tal qual A(x,y)
	return(matriz[linhas-1][colunas-1]); //retorna o elemento indicado pelos valores subtraídos de um porque as linhas e colunas da matriz começam de 0
}

Matriz Matriz::operator+(const Matriz& right) {
	try {
		if ((right.column != column) || (right.line != line)) //confere se a operação é válida (requer dimensões iguais)
			throw "Matrizes de tamanho diferente";
		Matriz aux(right); //cria uma matriz igual à da direita
		for (int i = 0; i < line; i++) { //soma os valores da matriz à esquerda aos valores da cópia, para impedir que a matriz da direita seja alterada (indesejável)
			for (int j = 0; j < column; j++) {
				aux.matriz[i][j] += matriz[i][j];
			}
		}
		return aux; //retorna a cópia
	}
	catch(const char *e){
		cout << "As matrizes tem tamanho diferente." << endl;
	}
}

Matriz& Matriz::operator+=(const Matriz& right) {
	try {
		if ((right.column != column) || (right.line != line)) //confere se a operação é válida (requer dimensões iguais)
			throw "Matrizes de tamanho diferente";
		*this = (*this) + right; //soma do objeto comportamental o objeto à direita
		
		return *this;
	}
	catch (const char *e) {
		cout << "As matrizes tem tamanho diferente." << endl;
	}
}

bool Matriz::operator==(const Matriz& right) {
	if (line != right.line || column != right.column) return false; //verifica se as dimensões são iguais. se não forem, a igualdade já está comprometida
	for (int i = 0; i < right.line; i++) {
		for (int j = 0; j < right.column; j++) {
			if(matriz[i][j] != right.matriz[i][j]) {
				return false; //se a desigualdade entre qualquer um dos elementos da matriz for detectada, retorna falso
			}
		}
	}return true; //se passar por ambos os testes de desigualdade, retorna verdadeiro 
}

bool Matriz::operator!=(const Matriz& right) {
	if (line != right.line || column != right.column) return true; //verifica se as dimensões são iguais. se não forem, a igualdade já está comprometida
	for (int i = 0; i < right.line; i++) {
		for (int j = 0; j < right.column; j++) {
			if (matriz[i][j] != right.matriz[i][j]) {
				return true; //se a desigualdade entre qualquer um dos elementos da matriz for detectada, retorna fatrue
			}
		}
	}return false; //se passar por ambos os testes de desigualdade, retorna false //nega o resultado da desigualdade
}

Matriz Matriz::operator-(const Matriz& right) {
	try {
		if ((right.column != column) || (right.line != line)) //testa se a operação é válida
			throw "Matrizes de tamanho diferente";
		Matriz aux(*this); //cria uma matriz idêntida ao objeto comportamental

		for (int i = 0; i < line; i++) { //subtrai dos valores da cópia os valores da matriz à direita, para não alterar o objeto
			for (int j = 0; j < column; j++) {
				aux.matriz[i][j] -= right.matriz[i][j];
			}
		}
		return aux; //retorna a cópia
	}
	catch (const char *e) {
		cout << "As matrizes tem tamanho diferente." << endl;
	}
}

Matriz& Matriz::operator-=(const Matriz& right) {
	try {
		 if ((right.column != column) || (right.line != line))
			throw "Matrizes de tamanho diferente";
		*this=(*this)-right; //subtrai do objeto comportamental o objeto à direita
		return *this;
	}
	catch (const char *e) {
		cout << "As matrizes tem tamanho diferente." << endl;
	}
}

Matriz& Matriz::operator*=(const int& right) { //multiplica cada elemento de uma matriz por uma constante
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			matriz[i][j] *= right;
		}
	}

	return *this; //retorna-se o objeto comportamental 
}


Matriz Matriz::operator~() { //gera uma matriz transposta
	Matriz aux; //cria-se uma matriz de dimensões idênticas
	aux.line = column; 
	aux.column = line;
	aux.matriz = new double*[aux.line];
	for (int i = 0; i < aux.line; i++) {
		aux.matriz[i] = new double[aux.column];
	}
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			aux.matriz[j][i] = matriz[i][j]; //transpõe a matriz comportamental
		}
	}
	return aux; // retorna a cópia
}

Matriz Matriz::operator*(const Matriz &right){
	try{
		if (column != right.line)
			throw "Colunas diferente de linha";
		Matriz aux(line, right.column, 0); //cria uma matriz auxiliar preenchida de zeros com as dimensões resultantes da multiplicação
		for (int i = 0; i < line; i++) {  //algoritmo padrão, O(n^3), para multiplicação de matrizes
			for (int j = 0; j < right.column; j++) {
				for (int k = 0; k < column; k++) {
					aux.matriz[i][j] = aux.matriz[i][j]+(matriz[i][k] * right.matriz[k][j]);
				}
			}
		}
		return aux;
	}
	catch(const char *e){
		cout << "Colunas != Linhas" << endl;
	}
}

Matriz& Matriz::operator*=(const Matriz &right) {
	try {
		if (column != right.line)
			throw "Colunas diferente de linha";
		(*this) = (*this)*right;
		return *this;
	}
	catch (const char *e) {
		cout << "Colunas != Linhas" << endl;
	}
}

ostream& operator<<(ostream& output, const Matriz& m) {

	for (int i = 0; i < m.line; i++) {
		for (int j = 0; j < m.column; j++) {
			output << m.matriz[i][j] << " ";
		}
		output << endl;
	}

	return output;
}

istream& operator>>(istream& input, Matriz& m) {
	for (int i = 0; i < m.line; ++i)
		delete[]m.matriz[i];

	delete[]m.matriz;

	cout << "Leitura de dados, digite o numero de linhas: ";

	input >> m.line;

	cout << "Leitura de dados, digite o numero de colunas: ";

	input >> m.column;

	m.matriz = new double*[m.line];

	for (int k = 0; k < m.line; k++) {
		m.matriz[k] = new double[m.column];
	}

	for (int i = 0; i < m.line; i++) {
		for (int j = 0; j < m.column; j++) {
			cout << "Leitura de dados, digite o valor para a posicao " << i + 1 << " " << j + 1 << " : ";
			input >> m.matriz[i][j];
		}
	}
	return input;
}


// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
