#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <iostream>
#include <cstring>
#include <ctime>
#include <ratio>
#include <chrono>
#include <vector>
#include <memory>

#include "SortSzybkie.h"
#include "SortScalanie.h"
#include "SortIntroSp.h"


using namespace std;
using namespace std::chrono;

#define WYSW_TAB_SORTSZYB 0
#define WYSW_TAB_SORTSCAL 0
#define WYSW_TAB_SORTINTR 0

//0 - wszystkie losowo
//1 - czesciowe wypelnienie
//2 - uporzadkowane w odwrotnej kolejnosci
#define OPCJE_WYPELNIANIA 2

//0 - 25% uporzadkowanych
//1 - 50% uporzadkowanych
//2 - 75% uporzadkowanych
//3 - 95% uporzadkowanych
//4 - 99% uporzadkowanych
//5 - 99,7% uporzadkowanych
#define PROCENT_WYPELNIENIA 0

struct TSortInfo {
    string nazwaSortowania;
    long iloscZmiennych;
    string typZmiennych;
    double czasSortowania;
    TSortInfo( string nazwaSortowania, long iloscZmiennych, string typZmiennych, double czasSortowania ):
        nazwaSortowania(nazwaSortowania),
        iloscZmiennych(iloscZmiennych),
        typZmiennych(typZmiennych),
        czasSortowania(czasSortowania) {}
    void wyswietl();
};

void TSortInfo::wyswietl() {
    cout << "Nazwa: " << nazwaSortowania << ", ";
    cout << typZmiennych << "[" << iloscZmiennych << "]" << ", ";
    cout << "Czas: " << czasSortowania << endl;
}

class CRaport {
    private:
       vector< shared_ptr<TSortInfo> > sortInfo;
    public:
    CRaport() {}
    ~CRaport() { sortInfo.clear(); }
    void dodajSortInfo( shared_ptr<TSortInfo> info ) { sortInfo.push_back(info); }
    void wyswietl();
};

void CRaport::wyswietl() {
    std::cout << "Raport z sortowania" << endl;
    shared_ptr<TSortInfo> sortowanie;
    for (vector< shared_ptr<TSortInfo> >::iterator it = sortInfo.begin() ; it != sortInfo.end(); ++it) {
        sortowanie = *it;
        sortowanie->wyswietl();
  }
  cout << '\n';
}

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
    switch(OPCJE_WYPELNIANIA) {
        case 0:
            for (long i = 0 ; i < wielkoscTablicy ; ++i) {
                do
                    id = rand() % wielkoscTablicy;
                while (*(tWartosci+i));
                *(tWartosci+i) = id;
            }
            break;
        case 1:
            for (long i = 0 ; i < wielkoscTablicy ; ++i) {
                do
                    if(i < wielkoscTablicy*PROCENT_WYPELNIENIA ){
                        id = i;
                    } else {
                    id = i + rand() % wielkoscTablicy-i;
                    }
                while (*(tWartosci+i));
                *(tWartosci+i) = id;
            }
            break;
        case 2:
            for (long i = 0 ; i < wielkoscTablicy ; ++i) {
                do
                    id = wielkoscTablicy - 1;
                while (*(tWartosci+i));
                *(tWartosci+i) = id;
            }
            break;
    }
}

template <typename T>
bool sprawdzanieSort( T* tWartosci, long wielkoscTablicy ) {
    for (long i = 0 ; i < wielkoscTablicy ; ++i) {
        if( *(tWartosci+i) >= *(tWartosci+i-1)){
        }else {
            return 0;
        }
    }
//    cout << "OK";
    return 1;
}

template <typename T>
grupaSortowania( string rodzaj ,long wielkoscTablicy, T* tWartosciKopia, CRaport* raport ) {
    high_resolution_clock::time_point t1, t2;
    duration<double> time_span;
    T* tWartosci = new T [wielkoscTablicy];
    wypelnijTabllice(tWartosciKopia, wielkoscTablicy);

    //--->>> Szybkie Sortowanie
    memcpy ( tWartosci, tWartosciKopia, wielkoscTablicy*sizeof(T) );
    if(WYSW_TAB_SORTSZYB) wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    do{
    t1 = high_resolution_clock::now();
    sortSzybkie(tWartosci, 0, wielkoscTablicy-1);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    }while( sprawdzanieSort(tWartosciKopia, wielkoscTablicy) );
    if(WYSW_TAB_SORTSZYB) wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    shared_ptr<TSortInfo> shptrSortSzybkie (
        new TSortInfo("Szybkie", wielkoscTablicy, typeid(T).name(), time_span.count()) );
    raport->dodajSortInfo(shptrSortSzybkie);
    //---<<<
    cout << "*";
    //--->>> Sortowanie przez scalanie
    memcpy ( tWartosci, tWartosciKopia, wielkoscTablicy*sizeof(T) );
    if(WYSW_TAB_SORTSCAL) wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    do{
    t1 = high_resolution_clock::now();
    sortScalanie(tWartosci, wielkoscTablicy, 0, wielkoscTablicy-1);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    }while( sprawdzanieSort(tWartosciKopia, wielkoscTablicy) );
    if(WYSW_TAB_SORTSCAL) wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    shared_ptr<TSortInfo> shptrSortScalanie (
        new TSortInfo("Przez scalanie", wielkoscTablicy, typeid(T).name(), time_span.count()) );
    raport->dodajSortInfo(shptrSortScalanie);
    //---<<<
    cout << "*";
    //--->>> Sortowanie introspetywne
    memcpy ( tWartosci, tWartosciKopia, wielkoscTablicy*sizeof(T) );
    if(WYSW_TAB_SORTINTR) wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    do{
    t1 = high_resolution_clock::now();
    sortIntroSp(tWartosci, wielkoscTablicy);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    }while( sprawdzanieSort(tWartosciKopia, wielkoscTablicy) );
    if(WYSW_TAB_SORTINTR) wyswietlanieTablicy(tWartosci, wielkoscTablicy);
    shared_ptr<TSortInfo> shptrSortIntrospec (
        new TSortInfo("Introspektywne", wielkoscTablicy, typeid(T).name(), time_span.count()) );
    raport->dodajSortInfo(shptrSortIntrospec);
    //---<<<
    cout << "*" << endl;
    delete [] tWartosci;
}

#endif // SORT_H_INCLUDED
