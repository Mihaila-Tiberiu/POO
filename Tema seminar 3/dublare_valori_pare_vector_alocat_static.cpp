#include <iostream>

using namespace std;

void dubleazaValPare(int* v, int& n)
{
    if (n <= 0)
    {
        cout << "Nr de elemente din vector este invalid!";
    }
    else
    {
        // se calculeaza noua dimensiune
        int n2 = n;

        for (int i = 0; i < n; i++)
            if (v[i] % 2 == 0)
                n2++;
        if (n2 > 100)
            cout << "In vector sunt prea multe elemente pare!";
        else {
            int aux[100];

            // copiaza in aux elementele care vrem sa ramana
            int k = 0;

            for (int i = 0; i < n; i++)
                if (v[i] % 2 == 0)
                {
                    aux[k++] = v[i];
                    aux[k++] = 2 * v[i];
                }
                else
                {
                    aux[k++] = v[i];
                }

            // vectorul vechi ia valoarea vectorului nou
            n = n2;
            for (int i = 0; i < n2; i++)
            {
                v[i] = aux[i];
            }
        }
    }
}


int main()
{
    int n;
    int v[100];

    cout << "n= "; cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "v[" << i << "]= "; cin >> v[i];
    }

    dubleazaValPare(v, n);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
	
	return 0;
}
