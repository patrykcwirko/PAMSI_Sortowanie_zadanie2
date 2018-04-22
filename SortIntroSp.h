#ifndef SORTINTROSPEKTYWNE_H_INCLUDED
#define SORTINTROSPEKTYWNE_H_INCLUDED
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>

#define M_LN2  0.69314718055994530942  /* log_e 2 */
#define MAX_LICZBA_PODZIALOW 9
#define WIELKOSC_PACZKI 3

using namespace std;

template <typename T>
void wstawianieSortujace (T *tab, unsigned long wielkoscTablicy) {
    long i, j;
    T temp;
    for (i=1; i < wielkoscTablicy; ++i) {
        temp = *(tab+i);
        for (j=i; (j>0) && (temp < *(tab+j-1)); --j) {
            *(tab+j) = *(tab+j-1);
        }
        *(tab+j)=temp;
    }
}

template <typename T>
void zamiana(T *tab, long i, long j) {
    T temp;
    temp = *(tab+i);
    *(tab+i) = *(tab+j);
    *(tab+j) = temp;
}

template <typename T>
void kopcowanie (T *tab, long i, unsigned long wielkoscTablicy) {
    long j;
    while (i <= wielkoscTablicy/2) {
        j=2*i;
        if (j+1 <= wielkoscTablicy && (*(tab+j+1) > *(tab+j))) {
          j=j+1;
        }
        if ( *(tab+i) < *(tab+j)) {
          zamiana(tab,i,j);
        } else {
             break;
        }
        i=j;
    }
}

template <typename T>
void sortKopc (T *tab, unsigned long wielkoscTablicy) {
    long i;
    for (i=wielkoscTablicy/2; i > 0; --i) {
        kopcowanie(tab-1, i, wielkoscTablicy);
    }
    for (i=wielkoscTablicy-1; i > 0; --i) {
        zamiana(tab, 0, i);
        kopcowanie(tab-1, 1, i);
    }
}

template <typename T>
void medianaDlaTrzech (T *tab, long &lewy, long &prawy) {
    if ( *(tab+ ++lewy -1) > *(tab+ --prawy)) {
        zamiana(tab, lewy -1, prawy);
    }
    if ( *(tab + lewy -1) > *(tab + prawy/2)) {
        zamiana(tab, lewy -1, prawy/2);
    }
    if ( *(tab + prawy/2) > *(tab + prawy)) {
        zamiana(tab, prawy/2, prawy);
    }
    zamiana(tab, prawy/2, prawy-1);
}

template <typename T>
long paczkowanie (T *tab, long lewy, long prawy) {
    long i, j;
    if (prawy >= WIELKOSC_PACZKI) {
        medianaDlaTrzech(tab, lewy, prawy);
    }
    for (i=lewy, j=prawy-2; ; ) {
        for( ; *(tab+i) < *(tab + prawy-1); ++i);
        //----
        for( ; j>=lewy && *(tab+j) > *(tab + prawy-1); --j);
        //----
        if (i<j) {
            zamiana(tab, i++, j--);
        }else {
             break;
        }
    }
    zamiana(tab, i, prawy-1);
    return i;
}

template <typename T>
void sortowanieWewnetrzne (T *tab, unsigned long wielkoscTablicy, int srodek) {
    unsigned long i;
    if ( srodek <= 0 ) {
        sortKopc( tab, wielkoscTablicy );
        return;
    }
    i = paczkowanie( tab, 0, wielkoscTablicy );
    if ( i > MAX_LICZBA_PODZIALOW ) {
        sortowanieWewnetrzne( tab, i, srodek-1 );
    }
    if ( wielkoscTablicy-1-i > MAX_LICZBA_PODZIALOW ) {
        sortowanieWewnetrzne( tab+i+1, wielkoscTablicy-1-i, srodek-1);
    }
}

template <typename T>
void sortIntroSp(T *tab, unsigned long wielkoscTablicy) {
    sortowanieWewnetrzne( tab, wielkoscTablicy, (int)floor( 2 * log(wielkoscTablicy) / M_LN2 ) );
    wstawianieSortujace( tab, wielkoscTablicy );
}

#endif // SORTINTROSPEKTYWNE_H_INCLUDED
