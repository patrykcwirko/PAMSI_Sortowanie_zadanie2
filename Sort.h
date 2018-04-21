#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <iostream>
#include <cstring>
#include <ctime>

#include "SortSzybkie.h"


using namespace std;

//KIERUNEKSORT  1 - rosnaca
//KIERUNEKSORT -1 - malejaca
#define KIERUNEKSORT 1

template <typename T>
void wyswietlanieTablicy( T* tWartosci, long wielkoscTablicy ) {
    for (long i = 0 ; i < wielkoscTablicy ; ++i) {
        cout << tWartosci[i] << " ";
    }
    cout << endl;
}

template <typename T>
void wypelnijTabllice( T* tWartosci, long wielkoscTablicy ) {
    T id;
    memset(tWartosci, 0, wielkoscTablicy * sizeof(long) );
    for (long i = 0 ; i < wielkoscTablicy ; ++i) {
        do
        	id = rand() % wielkoscTablicy;
        while (*(tWartosci+id));
        *(tWartosci+id) = i + 1;
    }
}

template <typename T>
grupaSortowania( string rodzaj ,long wielkoscTablicy, T* tWartosciKopia ) {
    clock_t tStart;
    clock_t tStop;

    cout << rodzaj << "::Sortowanie tablicy " << rodzaj << "[" << wielkoscTablicy << "]" << endl;
    T* tWartosci = new T [wielkoscTablicy];
    wypelnijTabllice(tWartosciKopia, wielkoscTablicy);

    memcpy ( tWartosci, tWartosciKopia, wielkoscTablicy*sizeof(T) );
    wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    cout << rodzaj << "::Szybkie Sortowanie " << endl;
    tStart = clock();
    sortSzybkie(tWartosci, 0, wielkoscTablicy-1);
    tStop = clock();
    wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    cout << "- Czas sortowania " << tStop - tStart << endl;

    delete [] tWartosci;
}

#endif // SORT_H_INCLUDED
