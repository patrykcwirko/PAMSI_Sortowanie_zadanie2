#include <iostream>
#include <vector>
#include <ctime>

#include "Sort.h"

using namespace std;

#define ILOSCTAB 100

//#define WIELKOSCTAB { 10000, 50000, 100000, 500000, 1000000 }
unsigned long long WIELKOSCTAB[] = { 10000ull, 50000ull, 100000ull, 500000ull };

int main()
{
    unsigned int wielkosc = sizeof(WIELKOSCTAB)/sizeof(unsigned long long);
    for(int i=0; i<wielkosc; i++) {
        //-----------------------------------------------------------------
        int* tIntWartosciKopia = new int [WIELKOSCTAB[i]];
        grupaSortowania( "INT" ,WIELKOSCTAB[i], tIntWartosciKopia);
        delete [] tIntWartosciKopia;
        //-----------------------------------------------------------------
        long* tLongWartosciKopia = new long [WIELKOSCTAB[i]];
        grupaSortowania( "LONG" ,WIELKOSCTAB[i], tLongWartosciKopia);
        delete [] tLongWartosciKopia;
        //-----------------------------------------------------------------
        float* tFloatWartosciKopia = new float [WIELKOSCTAB[i]];
        grupaSortowania( "FLOAT" ,WIELKOSCTAB[i], tFloatWartosciKopia);
        delete [] tFloatWartosciKopia;
        //-----------------------------------------------------------------
        double* tDoubleWartosciKopia = new double [WIELKOSCTAB[i]];
        grupaSortowania( "DOUBLE" ,WIELKOSCTAB[i], tDoubleWartosciKopia);
        delete [] tDoubleWartosciKopia;

    }

//      typ sortowania, typ danych, ilosc danych, upozadkowanie danych
//    wypelnijTabllice( tWartosci );
//    switch(SORTOWANIE) {
//    case 1:
//        sortSzybkie(tWartosci);
//        break;
//    case 2:
//        sortScalanie(tWartosci);
//        break;
//    case 3:
//        sortIntroSp(tWartosci);
//        break;
//    }

//    cout << clock();

    return 0;
}
