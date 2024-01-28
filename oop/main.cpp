#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class TPole
{
public:
    int maxPocet;
    int pocet;
    int *pole;


    TPole(int n = 100);
    bool vlozDoPole(int cislo);
    int dejPrvek(int index);
    int pocetPrvku();
    virtual void nactiZeSouboru(const char *jmeno);
    void tisk();
};

TPole::TPole(int n)
//: maxPocet(n), pocet(0)
{
    pocet = 0;
    maxPocet = n;
    pole = new int[n];
    cout << "Created" << endl;
}

bool TPole::vlozDoPole(int cislo)
{
    if (pocet == maxPocet)
        return false;
    pole[pocet] = cislo;
    pocet++;
    return true;
}

int TPole::dejPrvek(int index)
{
    if (index > pocet)
        return -1;
    if (index < 0)
        return -1;
    return pole[index];
}

int TPole::pocetPrvku()
{
    return pocet;
}

void TPole::nactiZeSouboru(const char *jmeno)
{
    ifstream soubor;
    int cislo;
    soubor.open(jmeno);
    while (soubor >> cislo)
    {
        vlozDoPole(cislo);
    }
    soubor.close();
}

void TPole::tisk()
{
    for (int i = 0; i < pocet; i++)
    {
        cout << pole[i] << " ";
    }
    cout << endl;
}

class TSetridenePole : public TPole
{

public:
    TSetridenePole(int n = 100);
    bool vlozDoPole(int cislo);
};

TSetridenePole::TSetridenePole(int n)
    : TPole(n)
{
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

bool TSetridenePole::vlozDoPole(int cislo){
    if (pocet == maxPocet)
        return false;
    pole[pocet] = cislo;
    pocet++;
    qsort(pole,pocet, sizeof(int), compare);
    return true;
}


int main()
{
    cout << "Hello world!" << endl;
    TSetridenePole pole = TSetridenePole(100);
    pole.vlozDoPole(0);
    pole.vlozDoPole(10);
    pole.vlozDoPole(20);
    pole.vlozDoPole(30);
    pole.vlozDoPole(40);
    pole.vlozDoPole(50);
    pole.vlozDoPole(60);
    pole.vlozDoPole(70);
    pole.vlozDoPole(80);
    pole.vlozDoPole(90);
    pole.vlozDoPole(100);
    pole.nactiZeSouboru("cisla.txt");
    /*
    for (int i = 0; i < 100; i++)
    {
        cout << pole.vlozDoPole(i + 100) << " ";
    }
    cout << endl;
    cout << pole.dejPrvek(7) << " ";
    cout << pole.dejPrvek(15) << " ";
    cout << pole.dejPrvek(-1) << endl;
    cout << endl
         << pole.pocetPrvku() << endl;
        */
    pole.tisk();


    return 0;
}
