#include <iostream>
#include <vector>
#include <ctime>

#include "Sort.h"

using namespace std;

#define ILOSCTAB 100

//#define WIELKOSCTAB { 10000, 50000, 100000, 500000, 1000000 }
//unsigned long long WIELKOSCTAB[] = { 10000ull, 50000ull, 100000ull, 500000ull };
unsigned long long WIELKOSCTAB[] = { 150ull };

int main() {

    CRaport raport;

    unsigned int wielkosc = sizeof(WIELKOSCTAB)/sizeof(unsigned long long);
    for(int i=0; i<wielkosc; i++) {
//        //-----------------------------------------------------------------
//        short* tShortWartosciKopia = new short [WIELKOSCTAB[i]];
//        grupaSortowania( "SHORT" ,WIELKOSCTAB[i], tShortWartosciKopia, &raport);
//        delete [] tShortWartosciKopia;
        //-----------------------------------------------------------------
        int* tIntWartosciKopia = new int [WIELKOSCTAB[i]];
        grupaSortowania( "INT" ,WIELKOSCTAB[i], tIntWartosciKopia, &raport);
        delete [] tIntWartosciKopia;
//        //-----------------------------------------------------------------
//        long* tLongWartosciKopia = new long [WIELKOSCTAB[i]];
//        grupaSortowania( "LONG" ,WIELKOSCTAB[i], tLongWartosciKopia, &raport);
//        delete [] tLongWartosciKopia;
//        //-----------------------------------------------------------------
//        float* tFloatWartosciKopia = new float [WIELKOSCTAB[i]];
//        grupaSortowania( "FLOAT" ,WIELKOSCTAB[i], tFloatWartosciKopia, &raport);
//        delete [] tFloatWartosciKopia;
//        //-----------------------------------------------------------------
//        double* tDoubleWartosciKopia = new double [WIELKOSCTAB[i]];
//        grupaSortowania( "DOUBLE" ,WIELKOSCTAB[i], tDoubleWartosciKopia, &raport);
//        delete [] tDoubleWartosciKopia;

    }
    raport.wyswietl();

    return 0;
}
