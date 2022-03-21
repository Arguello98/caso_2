#include "textSearch.h"

void SuffixTrieNode::insertSuffix(string s, int index)
{
    indexes->push_back(index);
 
    if (s.length() > 0)
    {
        char cIndex = s.at(0);
 		
 		//si no existe el nodo entonces lo crea
        if (children[cIndex] == NULL)
            children[cIndex] = new SuffixTrieNode();
            
 		//inserta la siguiente letra en el hijo
        children[cIndex]->insertSuffix(s.substr(1), index+1);
    }
}
 
//funcion que busca un patron en el arbol
list<int>* SuffixTrieNode::search(string s)
{
    // si ya se recorrio la palabra se retorna los indices
    if (s.length() == 0)
        return indexes;
 
    // busca el patron letra por letra hasta que se recorra la palabra o no se encuentre la siguiente letra del patron
    if (children[s.at(0)] != NULL)
        return (children[s.at(0)])->search(s.substr(1));
 
    // If there is no edge, pattern doesn’t exist in text
    else return NULL;
}
 
/* funcion de busqueda que recibe una palabra e imprime las posiiones donde araece*/
void SuffixTrie::search(string pat)
{
	//llama a la funcion de busqueda dentro del primer nodo y busca si aparecen los patrones 
    list<int> *result = root.search(pat);
 
    //verifica si esta vacio o no
    if (result == NULL)
        cout << "Patron no encontrado" << endl;
    else
    {
       list<int>::iterator i;
       int patLen = pat.length();
       // a partir de la lista de posiciones imprime las posiciones menos el largo de la palabra para obtener donde empiza
       return;
       for (i = result->begin(); i != result->end(); ++i){}
	   
        // cout << "Encontrado en posicion " << *i - patLen<< endl;
    }
}

 void SuffixTrie::insert(string s,int indice){
 	for (int i = 0; i < s.length(); i++)
            root.insertSuffix(s.substr(i), indice+i);
 }

//funcion que recine un puntero a un arbol de sufijos y un string para insertar las palabras que aparecen en el string
void insertar(SuffixTrie * T, string texto){
	string temp = "";
	
	int indice =0;
	for(int i =0; i<texto.length();i++){
		
		while( i+indice <texto.length() && texto.substr(i+indice,1) != " "){
			temp += texto.substr(i+indice,1);
			indice++;
		}
		
		T->insert(temp,i);
		i+=indice;
		
		indice=0;
		temp ="";
	}
	
}

//funcion que lee un archivo de texto y retorna un string
string readFile(){
	string tmp;
	string resultado = "";
	ifstream archivo("sample.txt");
	while (getline (archivo, tmp)) {
	  resultado += tmp + " ";
	}
	archivo.close();
	return resultado;
}


/*
	Este algoritmo el mayor tiempo se va a la hora de insertar las palabras en el arbol pero este proceso se tiene que realizar solo 1 vez
	a la hora de buscar los ptrones de una palabra se realiza utilizadon el arbol 
	
	un ejemplo ignorando donde los hijos son nulos para el dibujo, si se inserta la palabra "carro y casa"
		
								   [a]     	          [c]      [r]  		   [s]
								  / \	           	 / 	       / \		      / 
								[s] [r]	            [a] 	 [r] [o]         [a]
								/   /\			    / \       \
							  [a] [r][o]		 [s]   [r]     [o]
   								  /              /     / \ 
								[o]            [a]   [r] [o]
								                     /
								                   [o]
								                     
	Entonces a la hora de realizar una busqueda de un string si fuera "ro" pregunta en el root si nodo[r] != null y como no seria null buscaria dentro del nodo [r] si tiene un hijo [o] 
	y como existe retorna la lista de apariciones a la cuales se les resta el largo de la palabra buscada en este caso 2
	
	pero si se buscara un string "za" se pregunta si root[z] != null pero al no existir ningun patron o string que contuviera z el root[z] sera null y retorna null
	
	el comportamiento seria O(n) siendo n el largo de la palabra cuando se realiza la busqueda 						
*/
