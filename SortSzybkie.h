#ifndef SORTSZYBKIE_H_INCLUDED
#define SORTSZYBKIE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

template <typename T>
void sortSzybkie(T* tab, unsigned long lewy, unsigned long prawy) {
    if(prawy <= lewy) return;

	unsigned long i = lewy - 1, j = prawy + 1;
	unsigned long pivotIndex = (lewy + rand()% prawy)/2;
	unsigned long pivot = *(tab+pivotIndex);

	while(1) {
		while( pivot > *(tab + ++i) );
		while( pivot < *(tab+ --j) );
		if( i <= j) {
			swap( *(tab+i), *(tab+j) );
		} else {
			break;
		}
	}
	if(j > lewy) {
        sortSzybkie(tab, lewy, j);
	}
	if(i < prawy) {
        sortSzybkie(tab, i, prawy);
	}
}


#endif // SORTSZYBKIE_H_INCLUDED
