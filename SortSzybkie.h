#ifndef SORTSZYBKIE_H_INCLUDED
#define SORTSZYBKIE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

//template <typename T>
//void sortSzybkie(T* tab, unsigned long lewy, unsigned long prawy) {
//    if(prawy <= lewy) return;
//
//	unsigned long i = lewy - 1, j = prawy + 1;
//	unsigned long pivotIndex = (lewy + rand()% prawy)/2;
//	unsigned long pivot = *(tab+pivotIndex);
//
//	while(1) {
//		while( pivot > *(tab + ++i) );
//		while( pivot < *(tab+ --j) );
//		if( i <= j) {
//			swap( *(tab+i), *(tab+j) );
//		} else {
//			break;
//		}
//	}
//	if(j > lewy) {
//        sortSzybkie(tab, lewy, j);
//	}
//	if(i < prawy) {
//        sortSzybkie(tab, i, prawy);
//	}
//}

template <typename T>
void sortSzybkie( T* tab, unsigned long left, unsigned long right )
{
    unsigned long i = left;
    unsigned long j = right;
    T x = tab[( left + right ) / 2 ];
    do
    {
        while( tab[ i ] < x )
             i++;

        while( tab[ j ] > x )
             j--;

        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );

            i++;
            j--;
        }
    } while( i <= j );

    if( left < j ) sortSzybkie( tab, left, j );

    if( right > i ) sortSzybkie( tab, i, right );

}


#endif // SORTSZYBKIE_H_INCLUDED
