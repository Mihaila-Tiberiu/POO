#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	int varsta;
	Animal(int v = 0) : varsta(v) { cout << "\nConstructor animal"; }
	virtual void Speak() { cout << "\nAnimal speaks"; }
	int getVarsta()
	{
		return this->varsta;
	}
	~Animal() { cout << "\nDestructor animal"; }
};

class Caine : public Animal {
public:
	Caine(int v = 1) : Animal(v) { cout << "\nConstructor caine"; }
	void Speak() { cout << "\nCainele latra"; }
	~Caine() { cout << "\nDestructor caine"; }
};

class Pisica : public Animal {
public:
	Pisica(int v = 2) : Animal(v) { cout << "\nConstructor pisica"; }
	void Speak() { cout << "\nPisica miauna"; }
	~Pisica() { cout << "\nDestructor pisica"; }
};

class Ograda {
	Animal** animale = NULL;
	int nrAnimale = 0;
public:
	Ograda() { cout << "\nConstructor ograda fara parametri (ograda este goala)"; }
	Ograda(Animal** a, int nr)
	{
		cout << "\nConstructor ograda cu parametri";
		if (a != NULL && nr > 0)
		{
			this->animale = a;
			this->nrAnimale = nr;
		}
	}
	~Ograda() { cout << "\nDestructor ograda"; }

	void afisareOgrada() {
		if (this->animale != NULL && this->nrAnimale > 0)
		{
			for (int i = 0; i < this->nrAnimale; i++) {
				this->animale[i]->Speak();
				cout << " si are " << (*this->animale[i]).getVarsta() << " ani.";
			}
		}
	}
};

int main(){
	Pisica p;
	Caine c;
	Animal a;
	Animal* va[] = { &a, &p, &c };
	Ograda o(va, 3);
	o.afisareOgrada();

	return 0;
}