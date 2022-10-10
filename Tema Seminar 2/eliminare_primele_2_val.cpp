#include <iostream>

using namespace std;

void eliminaPrimele2Valori(int*& v, int& n)
{
    // p1 se calculeaza noua dimensiune
    int n2 = n-2;

    // p2 alocare dinamica nou vector cu dimensiunea calculata la p1
    int* aux = (int*)malloc(n2 * sizeof(int));

    // p3 se copiaza in aux elementele care vrem sa ramana
    int k = 0;

    for (int i = 2; i < n; i++)
        aux[k++] = v[i];

    // p4 se dezaloca vectorul vechi
    free(v);

    // p5 vectorul vechi pointeaza spre vector nou(aux)
    v = aux;
    n = n2;
}


int main()
{   
    int n;
    int* v; 
   
    cout << "n= "; cin >> n;

    v = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        cout << "v[" << i << "]= "; cin >> v[i];
    }

    eliminaPrimele2Valori(v, n);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    free(v);
}
