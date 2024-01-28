#include <iostream>

using namespace std;

int main(){
    
    int* dukaz;//otevreme fochtlik
    dukaz = NULL;//vyklidime papiry s adresou z fochtliku
    dukaz = new int; //fochtliku priradime adresu noveho domecku
    *dukaz = 42;//nastehovani najemnika
    delete dukaz;//zborime domecek
    dukaz = NULL;//smazeme adresu z fochtliku
    
}




























float fceII(){
    return 57.3f;
}

void nic(){
    return;
}

int cislo(){
    return 5;
}

int mainIII(){
    int a;
    a = cislo();
    cout << a;

    return 0;
}































void vynasobdvema(int* b);
//void vynasobdvemaprvek(int pole[], int prvek);
void vynasobdvemaprvek(int* pole, int prvek);

int mainII() {

    //int a = 0;

    int pole[10];
    // pole = &pole

    //int* ukaz = NULL;

    //a = 56;

    //ukaz = &a;

    //*ukaz = 78;

    //*ukaz == a kdo tam bydli
    //ukaz == &a domecek

    //cout << *ukaz; 

    //vynasobdvema(&a);

    pole[4] = 20;

    vynasobdvemaprvek(pole, 4);

    cout << pole[4];

    //cout << endl << a;
    
    return 0;
}

void vynasobdvema(int* b){
    *b = *b * 2;

}

void vynasobdvemaprvek(int* pole, int prvek){
    //*(&pole + sizeof(int)*4) = pole[prvek]*2;
    pole[prvek] = pole[prvek]*2;
}