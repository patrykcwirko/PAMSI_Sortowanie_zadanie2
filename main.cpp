#include <iostream>
#include <vector>
#include <ctime>
#include "Sort.h"

using namespace std;

//SORTOWANIE 1 - Szybkie
//SORTOWANIE 2 - Przez Scalanie
//SORTOWANIE 3 - Introspektywne
#define SORTOWANIE 1

//#define WIELKOSCTAB 10000
//#define WIELKOSCTAB 50000
//#define WIELKOSCTAB 100000
//#define WIELKOSCTAB 500000
#define WIELKOSCTAB 1000000

#define ILOSCTAB 100

template <typename T> void wypelnijTabllice( T tWartosci ) {

}

int main()
{
    int tWartosci[ILOSCTAB][WIELKOSCTAB];

    wypelnijTabllice( tWartosci );
    switch(SORTOWANIE) {
    case 1:
        sortSzybkie();
        break;
    case 2:
        sortScalanie();
        break;
    case 3:
        sortIntroSp();
        break;
    }

    cout << clock();

    return 0;
}
