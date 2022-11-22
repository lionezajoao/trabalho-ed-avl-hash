// CPP program to implement hashing with chaining
#include<bits/stdc++.h>
using namespace std;

class Hash
{
	int tamanho;
	list<int> *lista;

public:
	Hash(int V);

	void inserir_dado(int val);

	void apagar_dado(int val);

	int funcao_hash(int val) {
		return (val % tamanho);
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->tamanho = b;
	lista = new list<int>[tamanho];
}

void Hash::inserir_dado(int val)
{
	int index = funcao_hash(val);
	lista[index].push_back(val);
}

void Hash::apagar_dado(int val)
{
	int index = funcao_hash(val);

	list <int> :: iterator i;
	for (i = lista[index].begin();i != lista[index].end(); i++) {
		if (*i == val)
		break;
	}

	if (i != lista[index].end())
		lista[index].erase(i);
}

void Hash::displayHash() {
	for (int i = 0; i < tamanho; i++) {
		cout << i;
		for (auto x : lista[i])
		cout << " --> " << x;
		cout << endl;
	}
}


