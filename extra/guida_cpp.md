# C++ per le Olimpiadi

## Template standard

#### I/O su file

Questo è il template che userete più spesso

```cpp
#include<fstream>
using namespace std;

int main() {
    ifstream in("input.txt"); //specifico qual è il mio file di input
    ofstream out("output.txt"); //specifico qual è il mio file di output
  
    // lettura variabile
    int a;
    in>>a;
  
    // qui la soluzione
   
    // output variabile
    out<<a;
    
    in.close(); //chiudo file di input
    out.close(); //chiudo file di output
    return 0;
}
```

#### Implementare una funzione data 

In alcune gare invece vi evitano la lettura / scrittura di dati e vi danno direttamente una funzione (con tutti i parametri necessari) da implementare. Vedremo questo caso più avanti.

## STL (Algoritmi e strutture dati già implementate)

#### Vector
Implementazione di array dinamici:
```cpp
#include<vector> //bisogna importarli

vector<int> v; //dichiarazione di un vettore di interi v

//inserisco in v il valore a
int a = 2;
v.push_back(a);

//size restituisce la dimensione del vettore, in questo caso 1 perché c'è un solo elemento
int c = v.size();

//è un array dinamico quindi posso aggiungere quanti elementi voglio (più o meno)
v.push_back(1);
v.push_back(3);
v.push_back(4);

//vale la stessa modalità di accesso degli array statici, v[0] è uguale a 2
int z = v[0];

//Nonostante abbia dimensione """illimitata""" non si può accedere ad un elemento non ancora asseggnato
//Non si può quindi fare:
//int z = v[5]



//Potete però dare al vettore una dimensione (NON è fissa, può variare) facendo:
int N;
in>>N;
vector<int> v(N);

//oppure
int N;
vector<int> v;

in>>N;
v.resize(N);
```

Piccolo esempio:
```cpp
#include <vector>
using namespace std;

int main()
{
    vector <int> V; //dichiarazione del vettore
    int temp, somma = 0;
    for (int i = 0; i < 10; i++) //lettura
    {
        in >> temp;
        V.push_back(temp);
    }
    for (i = 0; i < 10; i++) //somma
    somma += V.at(i);
    cout << La somma vale: << somma << endl;
return 0;
```

Alcuni metodi importanti:
```cpp
vector<int> v

//Aggiungere elementi dalla coda
v.push_back(1);
v.push_back(3);
v.push_back(4);
//{1,3,4}

//Rimuovere elementi dalla coda
v.pop_back() //4
//rimane {1,3]

//Accedere all'ultimo elemento (la coda)
v.back() //4

//Accedere al primo elemento (la testa)
v.front() //1

//Verificare se il vettore è vuoto
v.empty() //false

//Ottenere il numero di elementi contenuti
v.size() //3

//ITERARE sull'intero vettore
for(int n:v){
    //istruzioni...
}
```
per saperne di più: https://it.cppreference.com/w/cpp/container/vector


#### Sort
Implementazione di un algoritmo di ordinamento (efficiente):
```cpp
#include<algorithm>

vector<int> v; //supponete sia riempito dai valori [1,6,5,9,10,-1,4]

sort(v.begin(), v.end()); //ordina in-place il vettore

```
Dopo l'esecuzione, v conterrà [-1,1,4,5,6,9,10]



## Cose utili

#### Operatore % (modulo)
L'operatore % mi restituisce il resto di una divisione:
```cpp
int a = 5;
int b = 2;
int c = a % b;
```
A fine esecuzione c varrà 1.

#### Funzioni max / min
Le funzioni max e min restituiscono rispettivamente il massimo e il minimo di due numeri:
```cpp
int a = 5;
int b = 2;
int c = max(a,b);
int d = min(a,b);
```
A fine esecuzione c varrà 5 e d varrà 2.

#### Funzione abs
Le funzione abs restituisce il valore assoluto di un numero:
```cpp
int a = -5;
int b = 5;
int c = abs(a); 
int d = abs(b); 
```
A fine esecuzione c varrà 5 e d varrà 5.

#### String
Consiste in una collezione di caratteri (char)
Per poterle utilizzare è necessario includere la libreria string
```cpp
#include <string>
string nome = "Stefano"
string cognome = "Perenzoni"
string nomeCompleto = nome + cognome; //Concatenazione di stringhe, trova l'"errore"
cout << nomeCompleto
```

Alcuni metodi utili
```cpp
#include <string>
string nome = "Stefano"
string cognome = "Perenzoni"

//Ottenere la lunghezza della stringa
nome.length();

//Accedere a caratteri singoli
nome[0] //S
```

Per saperne di più: https://it.cppreference.com/w/cpp/string/basic_string
    
## Cose a cui prestare attenzione

#### Integer overflow
Quando lavorate con numeri molto grandi fate attenzione a non sforare il limite massimo dei numeri interi, infatti se un numero viene rappresentato su N bit, allora potrà contenere tutti i numeri nell'intervallo ![formula](http://latex.codecogs.com/gif.latex?[-2^{n-1};2^{n-1}-1]).

In particolare:
* Un intero a 32 bit (``` int ```) può arrivare fino a 2147483647 (thumb rule: può contenere numeri con 10 cifre)
* Un intero a 64 bit (``` long / long long ```) può contenere numeri fino a 18 cifre e dovrebbe essere sufficiente per tutte le applicazioni del caso.

Se non avete bisogno dei numeri negativi potete raddoppiare il valore massimo della rappresentazione considerando gli ``` unsigned int ``` e ``` unsigned long ```.
