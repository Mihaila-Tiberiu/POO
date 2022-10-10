#include <iostream>

using namespace std;

void eliminaUltimelekValori(int*& v, int& n, int k)
{
    // p1 se calculeaza noua dimensiune
    int n2 = n-k;

    // p2 alocare dinamica nou vector cu dimensiunea calculata la p1
    int* aux = (int*)malloc(n2 * sizeof(int));

    // p3 se copiaza in aux elementele care vrem sa ramana
    int h = 0;

    for (int i = 0; i < n-k; i++)
        aux[h++] = v[i];

    // p4 se dezaloca vectorul vechi
    free(v);

    // p5 vectorul vechi pointeaza spre vector nou(aux)
    v = aux;
    n = n2;
}


int main()
{   
    int n, k;
    int* v; 
   
    cout << "n= "; cin >> n;
    cout << "k= "; cin >> k;
    
    if (k > n)
        cout << "k trebuie sa fie <= n!";

    else
    {
        v = (int*)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            cout << "v[" << i << "]= "; cin >> v[i];
        }

        eliminaUltimelekValori(v, n, k);

        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }

        free(v);
    }
}
