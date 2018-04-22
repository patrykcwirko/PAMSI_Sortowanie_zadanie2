#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <iostream>
#include <cstring>
#include <ctime>
#include <ratio>
#include <chrono>

#include "SortSzybkie.h"


using namespace std;
using namespace std::chrono;

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
        while (*(tWartosci+i));
        *(tWartosci+i) = id;
    }
}

template <typename T>
grupaSortowania( string rodzaj ,long wielkoscTablicy, T* tWartosciKopia ) {
    cout << rodzaj << "::Sortowanie tablicy " << rodzaj << "[" << wielkoscTablicy << "]" << endl;
    T* tWartosci = new T [wielkoscTablicy];
    wypelnijTabllice(tWartosciKopia, wielkoscTablicy);

    cout << rodzaj << "::Szybkie Sortowanie " << endl;
    memcpy ( tWartosci, tWartosciKopia, wielkoscTablicy*sizeof(T) );
    wyswietlanieTablicy(tWartosci, wielkoscTablicy);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    sortSzybkie(tWartosci, 0, wielkoscTablicy-1);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    cout << "- Czas sortowania " << time_span.count() << endl;

    delete [] tWartosci;
}

#endif // SORT_H_INCLUDED
