#include <iostream>

using namespace std;

class ClasaLiceu{
private:
	int anStudiu;
	int nrElevi;
	string* numeElevi;
	string numeDiriginte;
	bool seral;
public:
	// constructor fara parametri
	ClasaLiceu() {
		cout << "Constructor fara parametri" << endl;
		this->anStudiu = 0;
		this->nrElevi = 0;
		this->numeElevi = NULL;
		this->numeDiriginte = "Nedefinit";
		this->seral = NULL;
	}

	// constructor cu toti parametri
	ClasaLiceu(int anStudiu, int nrElevi, string* numeElevi, string numeDiriginte, bool seral)
	{
		cout << "Constructor cu toti parametrii" << endl;
		this->anStudiu = anStudiu;
		this->nrElevi = nrElevi;
		this->numeElevi = new string[nrElevi];
		for (int i = 0; i < nrElevi; i++)
			this->numeElevi[i] = numeElevi[i];
		this->numeDiriginte = numeDiriginte;
		this->seral = seral;
	}

	// constructor cu cativa
	ClasaLiceu(int nrElevi, string* numeElevi, string numeDiriginte)
	{
		cout << "Constructor cu cativa parametrii" << endl;
		this->anStudiu = 0;
		this->nrElevi = nrElevi;
		this->numeElevi = new string[nrElevi];
		for (int i = 0; i < nrElevi; i++)
			this->numeElevi[i] = numeElevi[i];
		this->numeDiriginte = numeDiriginte;
		this->seral = NULL;
	}

	// constructor de copiere
	ClasaLiceu(const ClasaLiceu& l)
	{
		cout <<  "Apel constructor de copiere" << endl;
		this->anStudiu = l.anStudiu;
		this->nrElevi = l.nrElevi;
		if (l.nrElevi > 0 && l.numeElevi != NULL)
		{
			this->numeElevi = new string[l.nrElevi];
			for (int i = 0; i < l.nrElevi; i++)
				this->numeElevi[i] = l.numeElevi[i];
		}
		else
			cout << "Numarul de elevi este invalid!" << endl;
		this->numeDiriginte = l.numeDiriginte;
		this->seral = l.seral;
	}

	~ClasaLiceu()
	{
		cout << endl << "Apel destructor" << endl;
		delete[] this->numeElevi;
	}

	// metoda de afisare
	void afisare() 
	{
		cout << "----------" << endl;
		cout << "Clasa se afla in anul de studiu: " << this->anStudiu << endl;
		cout << "Clasa are un numar de " << this->nrElevi << " elevi" << endl;
		if (this->nrElevi>0 && numeElevi != NULL)
		{
			cout << "Numele elevilor sunt: " << endl;
			for (int i = 0; i < this->nrElevi; i++)
			{
				cout << this->numeElevi[i];
				if (i < this->nrElevi - 1)
					cout << ", ";
				else
					cout << endl;
			}
		}
		cout << "Numele dirigintelui este: " << this->numeDiriginte << endl;
		if (!seral)
			cout << "Clasa NU este de seral" << endl;
		else
			cout << "Clasa este de seral" << endl;
		cout << "----------" << endl << endl;
	}

	int getAnStudiu()
	{
		return this->anStudiu;
	}

	void setAnStudiu(int anStudiu)
	{
		this->anStudiu = anStudiu;
	}

	int getNrElevi()
	{
		return this->nrElevi;
	}

	bool getSeral()
	{
		return this->seral;
	}

	void setSetal(bool seral)
	{
		this->seral = seral;
	}

	string getNumeDiriginte()
	{
		return this->numeDiriginte;
	}

	void setNumeDiriginte(string numeDiriginte)
	{
		this->numeDiriginte = numeDiriginte;
	}

	string* getNumeElevi()
	{
		string* copie = new string[this->nrElevi];
		for (int i = 0; i < this->nrElevi; i++)
			copie[i] = this->numeElevi[i];

		return copie;
	}

	string setElevi(int nrElevi, string* numeElevi)
	{
		this->nrElevi = nrElevi;
		if (this->numeElevi != NULL)
		delete[] this->numeElevi;
		this->numeElevi = new string[nrElevi];
		for (int i = 0; i < nrElevi; i++)
			this->numeElevi[i] = numeElevi[i];
	}
};

int main()
{
	ClasaLiceu c1;
	c1.afisare();

	string numec2[] = {"Andrei", "Alexandru"};
	ClasaLiceu c2(10, 2, numec2, "Marian", true);
	c2.afisare();

	string numec3[] = { "Anton", "Alin", "Ana" };
	ClasaLiceu c3(3, numec3, "Maria");
	c3.afisare();

	ClasaLiceu c4(c3);
	c4.afisare();

	return 0;
}