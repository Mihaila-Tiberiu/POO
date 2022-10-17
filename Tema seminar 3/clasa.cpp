#include <iostream>

using namespace std;

struct date {
    int zi;
    int luna;
    int an;
};


class cardDebit {

private:
    int cifreNrCard[16];
    int cifreCVV[3];
    int nrPlati;
    double* platiInLei;
    char* numeDetinator;
    date dataExpirare;

public:
    //constructor fara parametri
    cardDebit()
    {
        cout << "Apel constructor fara parametri" << endl;

        for (int i = 0; i < 16; i++)
            this->cifreNrCard[i] = 0;
        for (int i = 0; i < 3; i++)
            this->cifreCVV[i] = 0;
        this->nrPlati = 0;
        this->platiInLei = {};
        this->numeDetinator = new char[strlen("Nedefinit") + 1];
        strcpy(this->numeDetinator, "Nedefinit");
        this->dataExpirare.zi = 0;
        this->dataExpirare.luna = 0;
        this->dataExpirare.an = 0;
    }

    // constructor cu toti parametrii
    cardDebit(int* cifreNrCard, int* cifreCVV, int nrPlati, double* platiInLei, const char* numeDetinator, date dataExpirare)
    {
        cout << "Apel constructor cu toti parametri" << endl;

        for (int i = 0; i < 16; i++)
            this->cifreNrCard[i] = cifreNrCard[i];
        for (int i = 0; i < 3; i++)
            this->cifreCVV[i] = cifreCVV[i];

        this->nrPlati = nrPlati;
        this->platiInLei = platiInLei;

        this->numeDetinator = new char[strlen(numeDetinator) + 1];
        strcpy(this->numeDetinator, numeDetinator);

        this->dataExpirare.zi = dataExpirare.zi;
        this->dataExpirare.luna = dataExpirare.luna;
        this->dataExpirare.an = dataExpirare.an;
    }

    //constructor cu cativa parametri
    cardDebit(const char* numeDetinator, date dataExpirare)
    {
        cout << "Apel constructor cu cativa parametri" << endl;

        for (int i = 0; i < 16; i++)
            this->cifreNrCard[i] = 0;
        for (int i = 0; i < 3; i++)
            this->cifreCVV[i] = 0;
        this->nrPlati = 0;
        this->platiInLei = {};

        this->numeDetinator = new char[strlen(numeDetinator) + 1];
        strcpy(this->numeDetinator, numeDetinator);

        this->dataExpirare.zi = dataExpirare.zi;
        this->dataExpirare.luna = dataExpirare.luna;
        this->dataExpirare.an = dataExpirare.an;
    }

    // setter cifreNrCard
    void setCifreNrCard(int* cifreNrCard)
    {
        for (int i = 0; i < 16; i++)
            this->cifreNrCard[i] = cifreNrCard[i];
    }

    // getter cifreNrCard
    int* getCifreNrCard()
    {
        return this->cifreNrCard;
    }

    // setter cifreCVV
    void setCifreCVV(int* cifreCVV)
    {
        for (int i = 0; i < 3; i++)
            this->cifreCVV[i] = cifreCVV[i];
    }

    // getter cifreCVV
    int* getCifreCVV()
    {
        return this->cifreCVV;
    }

    // setter plati
    void setPlati(int nrPlati, double* platiInLei)
    {

        this->nrPlati = nrPlati;
        this->platiInLei = platiInLei;

    }

    // getter nrPlati
    int getNrPlati()
    {
        return this->nrPlati;
    }

    // getter platiInLei
    double* getPlatiInLei()
    {
        return this->platiInLei;
    }

    // setter numeDetinator
    void setNumeDetinator(const char* numeDetinator)
    {
        delete[] this->numeDetinator;
        this->numeDetinator = new char[strlen(numeDetinator) + 1];
        strcpy(this->numeDetinator, numeDetinator);
    }

    // getter numeDetinator
    char* getNumeDetinator()
    {
        return this->numeDetinator;
    }

    // setter dataExpirare
    void setDataExpirare(int DataExpirareZi, int DataExpirareLuna, int DataExpirareAn)
    {
        this->dataExpirare.zi = DataExpirareZi;
        this->dataExpirare.luna = DataExpirareLuna;
        this->dataExpirare.an = DataExpirareAn;
    }

    // getter dataExpirare.zi
    int getDataExpirareZi()
    {
        return this->dataExpirare.zi;
    }

    // getter dataExpirare.luna
    int getDataExpirareLuna()
    {
        return this->dataExpirare.luna;
    }

    // getter dataExpirare.an
    int getDataExpirareAn()
    {
        return this->dataExpirare.an;
    }

    // metoda de afisare
    void afisare()
    {
        cout << "Numarul cardului este: ";
        for (int i = 0; i < 16; i++)
            cout << this->cifreNrCard[i];
        cout << endl << "----------" << endl;

        cout << "CVV-ul cardului este: ";
        for (int i = 0; i < 3; i++)
            cout << this->cifreCVV[i];
        cout << endl << "----------" << endl;

        cout << "Nr de plati efectuate cu acest card este: " << nrPlati;
        cout << endl << "----------" << endl;

        cout << "Valoarile platilor in lei sunt: ";
        for (int i = 0; i < nrPlati; i++)
            cout << this->platiInLei[i] << "  ";
        cout << endl << "----------" << endl;

        cout << "Numele detinatorului cardului este: " << this->numeDetinator;
        cout << endl << "----------" << endl;

        cout << "Data de expirare a cardului este: " << this->dataExpirare.zi << "/" <<
            this->dataExpirare.luna << "/" << this->dataExpirare.an << endl << endl;
    }
};


int main()
{
    cardDebit c1;
    c1.afisare();

    date datac2;
    datac2.zi = 06;
    datac2.luna = 06;
    datac2.an = 2006;
    cardDebit c2("Alexandru", datac2);
    c2.afisare();

    date datac3;
    datac3.zi = 10;
    datac3.luna = 10;
    datac3.an = 2010;

    int numar3[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    int cvv3[] = { 3,2,1 };
    double platiC3[] = { 127.71, 34.56 };
    cardDebit c3(numar3, cvv3, 2, platiC3, "Andrei", datac3);
    c3.afisare();

    // Test getter-i si setter-i //

    cout << "Modificari c1: " << endl;

    int nrCardC1[16] = { 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1 };
    c1.setCifreNrCard(nrCardC1);
    cout << "Cifre nr card c1: ";
    for (int i = 0; i < 16; i++)
        cout << c1.getCifreNrCard()[i];
    cout << endl;

    int cvvC1[3] = { 4,4,4 };
    c1.setCifreCVV(cvvC1);
    cout << "Cifre cvv c1: ";
    for (int i = 0; i < 3; i++)
        cout << c1.getCifreCVV()[i];
    cout << endl;

    double platiC1[] = { 145.78, 90.65, 67.9 };
    c1.setPlati(3, platiC1);
    cout << "Platile sunt in numar de: " << c1.getNrPlati() << ": ";
    for (int i = 0; i < c1.getNrPlati(); i++)
        cout << c1.getPlatiInLei()[i] << "  ";
    cout << endl;

    c1.setNumeDetinator("Alin");
    cout << "Numele detinatorului este: " << c1.getNumeDetinator() << endl;

    c1.setDataExpirare(12, 12, 2012);
    cout << "Cardul c1 expira pe " <<
        c1.getDataExpirareZi() << "/" << c1.getDataExpirareLuna() << "/"
        << c1.getDataExpirareAn() << endl;

    return 0;
}
