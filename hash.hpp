// CPP program to implement hashing with chaining
#include<bits/stdc++.h>
using namespace std;

class Hash
{
	int tamanho; // Tamanho da hash
	list<int> *lista;

public:
	Hash(int V); // Constructor

	// inserts a key into hash lista
	void inserir_dado(int x);

	// deletes a key from hash lista
	void apagar_dado(int key);

	// hash function to map values to key
	int funcao_hash(int x) {
		return (x % tamanho);
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->tamanho = b;
	lista = new list<int>[tamanho];
}

void Hash::inserir_dado(int key)
{
	int index = funcao_hash(key);
	lista[index].push_back(key);
}

void Hash::apagar_dado(int key)
{
	// get the hash index of key
	int index = funcao_hash(key);

	// find the key in (index)th list
	list <int> :: iterator i;
	for (i = lista[index].begin();i != lista[index].end(); i++) {
		if (*i == key)
		break;
	}

	// if key is found in hash lista, remove it
	if (i != lista[index].end())
		lista[index].erase(i);
}

// function to display hash lista
void Hash::displayHash() {
	for (int i = 0; i < tamanho; i++) {
		cout << i;
		for (auto x : lista[i])
		cout << " --> " << x;
		cout << endl;
	}
}


