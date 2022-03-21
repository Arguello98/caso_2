#include <iostream>
#include <list>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#define MAX_CHAR 256
using namespace std;

/*
	Codigo obtenido de 
		https://www.geeksforgeeks.org/pattern-searching-using-trie-suffixes/
*/


//Nodo del arbol
class SuffixTrieNode
{
private:
    SuffixTrieNode *children[MAX_CHAR];
    list<int> *indexes;
public:
    SuffixTrieNode()
    {
        indexes = new list<int>;

        for (int i = 0; i < MAX_CHAR; i++)
          children[i] = NULL;
    }
 
    //funcion para insertar
    void insertSuffix(string suffix, int index);
 
    //funcion que retorna la lista con las posiciones donde aparece la palabra
    list<int>* search(string pat);
};
 
//Arbol
class SuffixTrie
{
private:
    SuffixTrieNode root;
public:
    // Constructor 
    SuffixTrie(){}
    
    //funcion para insertar un string en el arbol
 	void insert(string s,int indice);
 	
 	//funcion para buscar una palabra en el arbol
    void search(string pat);
};
 
// funcionpara insertar un suffijo que recibe un string y el indice donde aparece el sufijo


void insertar(SuffixTrie * T, string texto);

string readFile();
