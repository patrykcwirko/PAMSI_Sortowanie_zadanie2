#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

//KIERUNEKSORT  1 - rosnaca
//KIERUNEKSORT -1 - malejaca
#define KIERUNEKSORT 1

template <typename T>
void wypelnijTabllice( T tWartosci ) {

}

template <typename T>
void sortSzybkie(T* tablia) {
    cout << "Szybkie" << endl;
}

template <typename T>
void sortScalanie(T* tablia) {
    cout << "Scalanie" << endl;
}

template <typename T>
void sortIntroSp(T* tablia) {
    cout << "Introspektywne" << endl;
}

template <typename T>
grupaSortowania( string rodzaj ,long wielkoscTablicy, T* tWartosciKopia ) {
    clock_t tStart;
    clock_t tStop;

    cout << rodzaj << "::Sortowanie tablicy " << rodzaj << "[" << wielkoscTablicy << "]" << endl;
    T* tWartosci = new T [wielkoscTablicy];
    wypelnijTabllice(tWartosciKopia);

    memcpy ( tWartosci, tWartosciKopia, sizeof(T) );
    cout << rodzaj << "::Szybkie Sortowanie ";
    tStart = clock();
    sortSzybkie(tWartosci);
    tStop = clock();
    cout << "- Czas sortowania " << tStop - tStart << endl;

    memcpy ( tWartosci, tWartosciKopia, sizeof(T) );
    cout << rodzaj << "::Sortowanie przez scalanie ";
    tStart = clock();
    sortScalanie(tWartosci);
    tStop = clock();
    cout << "- Czas sortowania " << tStop - tStart << endl;

    memcpy ( tWartosci, tWartosciKopia, sizeof(T) );
    cout << rodzaj << "::Sortowanie introspektywne ";
    tStart = clock();
    sortIntroSp(tWartosci);
    tStop = clock();
    cout << "- Czas sortowania " << tStop - tStart << endl;

    delete [] tWartosci;
}

#endif // SORT_H_INCLUDED
