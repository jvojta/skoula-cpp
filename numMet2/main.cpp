#include <iostream>
#include <fstream>

using namespace std;

// MISC//
int **loadMat(const char *name, int *pocetR, int **matice);
int **createMat(int pocet);
void printMat(int *pocetR, int **matice);
// NUMBER METHODS//
void multiply(int *pocetR, int **matice, int index, int multipler);
void divide(int *pocetR, int **matice, int index, int divider);
void add(int *pocetR, int **matice, int index1, int index2);

void solve(int *pocetR, int **matice);

int **loadMat(const char *name, int *pocetR, int **matice)
{
    ifstream matFile;
    matFile.open(name);
    matFile >> *pocetR;
    matice = createMat(*pocetR);
    for (int i = 0; i < *pocetR; i++)
    {
        for (int j = 0; j <= *pocetR; j++)
        {
            matFile >> matice[i][j];
        }
    }
    matFile.close();
    return matice;
}

int **createMat(int pocet)
{
    int **pole = new int *[pocet];
    for (int i = 0; i < pocet; i++)
        pole[i] = new int[pocet];
    return pole;
}

void printMat(int *pocetR, int **matice)
{
    cout << "Pocet: " << *pocetR << endl
         << endl;
    for (int i = 0; i < *pocetR; i++)
    {
        for (int j = 0; j <= *pocetR; j++)
        {
            cout << matice[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void multiply(int *pocetR, int **matice, int index, int multipler)
{
    for (int i = 0; i <= *pocetR; i++)
    {
        matice[index][i] *= multipler;
    }
}

void divide(int *pocetR, int **matice, int index, int divider)
{
    for (int i = 0; i <= *pocetR; i++)
    {
        matice[index][i] /= divider;
    }
}

void add(int *pocetR, int **matice, int index1, int index2)
{
    for (int i = 0; i <= *pocetR; i++)
    {
        matice[index2][i] += matice[index1][i];
    }
}

void solve(int *pocetR, int **matice)
{
    int pom;
    for (int i = 0; i < *pocetR; i++)
    {
        for (int j = i + 1; j < *pocetR; j++)
        {
            if (matice[i][i] == 0 || matice[j][i] == 0)
                continue;
            pom = matice[i][i];
            multiply(pocetR, matice, i, matice[j][i]);
            multiply(pocetR, matice, j, -pom);
            add(pocetR, matice, i, j);
        }
    }
    for (int i = *pocetR - 1; i >= 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            if (matice[i][i] == 0 || matice[j][i] == 0)
                continue;
            pom = matice[i][i];
            multiply(pocetR, matice, i, matice[j][i]);
            multiply(pocetR, matice, j, -pom);
            add(pocetR, matice, i, j);
        }
    }
    for (int i = 0; i < *pocetR; i++)
    {
        divide(pocetR, matice, i, matice[i][i]);
    }
}

int main()
{
    int *pocetR = new int;
    int **matice = NULL;
    matice = loadMat("matice.txt", pocetR, matice);
    printMat(pocetR, matice);
    solve(pocetR, matice);
    printMat(pocetR, matice);
}
