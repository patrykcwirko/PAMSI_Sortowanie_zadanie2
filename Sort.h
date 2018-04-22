#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <iostream>
#include <cstring>
#include <ctime>
#include <ratio>
#include <chrono>

#include "SortSzybkie.h"
#include "SortScalanie.h"
#include "SortIntroSp.h"


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
    high_resolution_clock::time_point t1, t2;
    duration<double> time_span;

    cout << rodzaj << "::Sortowanie tablicy " << rodzaj << "[" << wielkoscTablicy << "]" << endl;
    T* tWartosci = new T [wielkoscTablicy];
    wypelnijTabllice(tWartosciKopia, wielkoscTablicy);

    //--->>> Szybkie Sortowanie
    cout << rodzaj << "::Szybkie Sortowanie " << endl;
    memcpy ( tWartosci, tWartosciKopia, wielkoscTablicy*sizeof(T) );
    wyswietlanieTablicy(tWartosci, wielkoscTablicy);

    t1 = high_resolution_clock::now();
    sortSzybkie(tWartosci, 0, wielkoscTablicy-1);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    cout << "- Czas sortowania " << time_span.count() << endl;
    //---<<<

    //--->>> Sortowanie przez scalanie
    cout << rodzaj << "::Sortowanie przez scalanie " << endl;
    memcpy ( tWartosci, tWartosciKopia, wielkoscTablicy*sizeof(T) );
    wyswietlanieTablicy(tWartosci, wielkoscTablicy);

    t1 = high_resolution_clock::now();
    sortScalanie(tWartosci, wielkoscTablicy, 0, wielkoscTablicy-1);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    cout << "- Czas sortowania " << time_span.count() << endl;
    //---<<<

    //--->>> Sortowanie introspetywne
    cout << rodzaj << "::Sortowanie introspetywne " << endl;
    memcpy ( tWartosci, tWartosciKopia, wielkoscTablicy*sizeof(T) );
    wyswietlanieTablicy(tWartosci, wielkoscTablicy);

    t1 = high_resolution_clock::now();
    sortIntroSp(tWartosci, wielkoscTablicy);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    cout << "- Czas sortowania " << time_span.count() << endl;
    //---<<<

    delete [] tWartosci;
}

#endif // SORT_H_INCLUDED
