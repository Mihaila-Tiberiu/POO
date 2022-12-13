#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum Profil
{
	Filologie = 1, 
	MatematicaInformatica = 2, 
	StiinteAleNaturii = 3
};

class IFile
{
public:
	virtual void writeToFile(fstream& f) = 0;
	virtual void readFromFile(fstream& f) = 0;
};

class Elev : public IFile {
	char* prenumeElev = NULL;
	char initPrenumeTata = '!';
	string numeElev = "Anonim";
	int nrNote = 0;
	int* note = NULL;
	Profil profil = Filologie;
public:

	Elev(){}
	Elev(const char* prenumeElev, char initPrenumeTata, string numeElev,
		int nrNote, int* note, Profil profil)
	{
		if (prenumeElev != NULL)
		{
			this->prenumeElev = new char[strlen(prenumeElev) + 1];
			strcpy(this->prenumeElev, prenumeElev);
		}
		this->initPrenumeTata = initPrenumeTata;
		this->numeElev = numeElev;
		if (nrNote > 0 && note != NULL)
		{
			this->nrNote = nrNote;
			this->note = new int[nrNote];
			for (int i = 0; i < nrNote; i++)
				this->note[i] = note[i];
		}
		this->profil = profil;
	}
	~Elev() {
		//delete[] this->prenumeElev;
		delete[] this->note;
	}

	void writeToFile(fstream& f)
	{
		//scriere char*
		int lg = (strlen(this->prenumeElev)+1);
		f.write((char*)&lg, sizeof(char));
		f.write(this->prenumeElev, lg * sizeof(char));

		//scriere char
		f.write((char*)&this->initPrenumeTata, sizeof(char));

		//scriere string
		lg = this->numeElev.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->numeElev.data(), lg * sizeof(char));

		//scriere int
		f.write((char*)&this->nrNote, sizeof(int));

		//scriere int*
		for (int i = 0; i < this->nrNote; i++)
		{
			f.write((char*)&this->note[i], sizeof(int));
		}

		//scriere enum
		f.write((char*)&this->profil, sizeof(Profil));
	}

	void readFromFile(fstream& f)
	{
		//citire char*
		int lg;
		//lg = strlen(prenumeElev) + 1;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->prenumeElev = buffer;
		delete[] buffer;

		//citire char
		f.read((char*)&this->initPrenumeTata, sizeof(char));
	
		//citire string
		lg = numeElev.length() + 1;
		f.read((char*)&lg, sizeof(int));
		buffer = new char[lg];
		f.read(buffer, lg);
		this->numeElev = buffer;
		delete[] buffer;

		//citire int
		f.read((char*)&this->nrNote, sizeof(int));

		//citire int*
		this->note = new int[this->nrNote];
		for (int i = 0; i < this->nrNote; i++)
		{
			f.read((char*)&this->note[i], sizeof(int));
		}

		//citire enum
		f.read((char*)&this->profil, sizeof(Profil));
	}

	void afisare() {
		// if (prenumeElev != NULL) cout << prenumeElev;
		cout << "\n" << initPrenumeTata;
		cout << "\n" << numeElev;
		cout << "\n" << nrNote << "\n";
		if (note != NULL && nrNote > 0)
			for (int i = 0; i < nrNote; i++)
				cout << note[i] << "\t";
		cout << "\n" << profil;
	}
	
};

int main()
{
	int note[2] = { 9,10 };
	Elev e ("Andrei", 'V', "Maria", 2, note, MatematicaInformatica);

	IFile* pf;
	pf = &e;

	fstream fout("fisier.txt", ios::out | ios::binary);
	e.writeToFile(fout);
	fout.close();
	
	fstream fin("fisier.txt", ios::in | ios::binary);
	Elev e2;
	e2.readFromFile(fin);
	fin.close();
	e2.afisare();
	
	return 0;
}