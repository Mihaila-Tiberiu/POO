#include <iostream>

using namespace std;

enum stareDeAgregare {
	SOLID, LICHID, GAZ, PLASMA
};

class Material {
	const int cod;
	string denumire = "NA";
	int nrProduseFolosit = 0;
	string* listaProduseFolosit = NULL;
	stareDeAgregare sa = stareDeAgregare::SOLID;

public:
	Material(int cod) : cod(cod)
	{
		cout << "Apel const cu 1 parametru" << endl;
	}

	Material(int cod, string denumire, int nrProduseFolosit, string* listaProduseFolosit, stareDeAgregare sa) : cod(cod)
	{
		cout << "Apel const cu toti parametrii" << endl;
		this->denumire = denumire;
		this->sa = sa;
		if (nrProduseFolosit > 0 && listaProduseFolosit != NULL)
		{
			this->nrProduseFolosit = nrProduseFolosit;
			this->listaProduseFolosit = new string[this->nrProduseFolosit];
			for (int i = 0; i < this->nrProduseFolosit; i++)
				this->listaProduseFolosit[i] = listaProduseFolosit[i];
		}
	}

	Material(int cod, int nrProduseFolosit, string* listaProduseFolosit) : cod(cod)
	{
		cout << "Apel const cu cativa parametri" << endl;
		this->denumire = "NA";
		this->sa = stareDeAgregare::SOLID;
		if (nrProduseFolosit > 0 && listaProduseFolosit != NULL)
		{
			this->nrProduseFolosit = nrProduseFolosit;
			this->listaProduseFolosit = new string[this->nrProduseFolosit];
			for (int i = 0; i < this->nrProduseFolosit; i++)
				this->listaProduseFolosit[i] = listaProduseFolosit[i];
		}
	}

	Material(const Material& m) : cod(m.cod)
	{
		cout << "Apel const de copiere" << endl;
		this->denumire = m.denumire;
		this->sa = m.sa;
		if (m.nrProduseFolosit > 0 && m.listaProduseFolosit != NULL)
		{
			this->nrProduseFolosit = m.nrProduseFolosit;
			this->listaProduseFolosit = new string[this->nrProduseFolosit];
			for (int i = 0; i < this->nrProduseFolosit; i++)
				this->listaProduseFolosit[i] = m.listaProduseFolosit[i];
		}
	}
	~Material()
	{
		cout << "Apel destructor" << endl;
		if (listaProduseFolosit != NULL)
			delete[] this->listaProduseFolosit;
	}

	Material operator=(const Material& m)
	{
		cout << "Apel OP=" << endl;
		if (this != &m) {
			delete[] this->listaProduseFolosit;
			this->denumire = m.denumire;
			this->sa = m.sa;
			if (m.nrProduseFolosit > 0 && m.listaProduseFolosit != NULL) {
				this->nrProduseFolosit = m.nrProduseFolosit;
				this->listaProduseFolosit = new string[this->nrProduseFolosit];
				for (int i = 0; i < this->nrProduseFolosit; i++)
					this->listaProduseFolosit[i] = m.listaProduseFolosit[i];
			}
			else {
				this->nrProduseFolosit = 0;
				this->listaProduseFolosit = NULL;
			}
		}
		return *this;
	}

	int getCod()
	{
		return this->cod;
	}

	string getDenumire()
	{
		return this->denumire;
	}

	void setDenumire(string denumire)
	{
		this->denumire = denumire;
	}

	int getNrProduseFolosit()
	{
		return this->nrProduseFolosit;
	}

	string* getListaProduseFolosit()
	{
		string* copie = new string[this->nrProduseFolosit];
		for (int i = 0; i < this->nrProduseFolosit; i++)
			copie[i] = this->listaProduseFolosit[i];

		return copie;
	}

	string getListaProduseFolositPozitie(int pozitie)
	{
		if (this->nrProduseFolosit > 0 && this->listaProduseFolosit != NULL && this->nrProduseFolosit > pozitie)
			return this->listaProduseFolosit[pozitie];
		else
			return "Nu exista";
	}

	void setProduseFolosite(int nrProduseFolosit, string* listaProduseFolosit)
	{
		this->nrProduseFolosit = nrProduseFolosit;
		if (this->listaProduseFolosit != NULL)
			delete[] this->listaProduseFolosit;
		if (nrProduseFolosit > 0 && listaProduseFolosit != NULL) {
			this->nrProduseFolosit = nrProduseFolosit;
			this->listaProduseFolosit = new string[this->nrProduseFolosit];
			for (int i = 0; i < this->nrProduseFolosit; i++)
				this->listaProduseFolosit[i] = listaProduseFolosit[i];
		}
		else {
			this->nrProduseFolosit = 0;
			this->listaProduseFolosit = NULL;
		}
	}

	stareDeAgregare	getSa()
	{
		return this->sa;
	}

	void setSa(stareDeAgregare sa)
	{
		this->sa = sa;
	}

	void afisare()
	{
		cout << "Codul materialului este: " << this->cod << endl;
		cout << "Denumirea materialului este: " << this->denumire << endl;
		cout << "Numarul produselor in care materialul este folosit este: " << this->nrProduseFolosit << endl;
		if (this->nrProduseFolosit > 0 && this->listaProduseFolosit != NULL)
		{
			cout << "Produsele in care materialul se foloseste sunt: ";
			for (int i = 0; i < nrProduseFolosit; i++)
				cout << listaProduseFolosit[i] << " ";
			cout << endl;
		}
		cout << "Starea de agregare a materialului este: " << this->sa << endl << "----------" << endl;
	}
};

Material functie(Material m1) {
	Material m(10);
	return m;
}


int main()
{
	Material m1(1);
	m1.afisare();
	string nume2 = "Apa";
	string listaProduse[] = { "Apa minerala", "Apa plata" };
	Material m2(2, nume2, 2, listaProduse, stareDeAgregare::LICHID);
	m2.afisare();
	Material m3(m2);
	m3.afisare();
	m1.setDenumire("Lava");
	m1.setProduseFolosite(2, listaProduse);
	m1.setSa(stareDeAgregare::PLASMA);
	cout << m1.getDenumire() << endl;
	cout << m1.getListaProduseFolosit()[0] << endl;
	cout << m1.getListaProduseFolositPozitie(1) << endl;
	cout << m1.getListaProduseFolositPozitie(2) << endl;
	cout << m1.getSa() << endl;
	Material m4 = m1;
	m1.afisare();
	m4.setDenumire("Materialul m4");
	m4.afisare();
	Material m5(5);
	m5 = m1;
	m5 = m5;
	m5.setDenumire("Materialul m5");
	m5.afisare();

	cout << "##########" << endl;
	Material m10 = functie(m5);
	cout << "##########" << endl;
	m10 = functie(m5);
	cout << "##########" << endl;
	return 0;
}

/*
	clasa cu enum, atribut constant, atribut cu alocare dinamica;
	tot pana acum (constr, destr, getteri, setteri, afisare) + operator=
	+ o functie in afara clasei
*/