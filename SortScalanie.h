#ifndef SORTSCALANIE_H_INCLUDED
#define SORTSCALANIE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

template <typename T>
T *pom;

template <typename T>
void scalanie(T* tab, unsigned long lewy, unsigned long srodek, unsigned long prawy) {
    T i = lewy, j = srodek + 1;

    for( unsigned long i=lewy; i <= prawy; i++) {
        *(pom<T> + i) = *(tab+i);
    }

    for(unsigned long k=lewy; k <= prawy; k++) {
        if(i <= srodek) {
            if(j <= prawy) {
                 if( *(pom<T> + j) < *(pom<T> + i) ) {
                     *(tab+k) = *(pom<T> + j++);
                 } else {
                     *(tab+k) = *(pom<T> + i++);
                 }
            } else {
                *(tab+k) = *(pom<T> + i++);
            }
        } else {
          *(tab+k) = *(pom<T> + j++);
        }
    }
}

template <typename T>
void sortowaniePrzezScalanie(T* tab, unsigned long lewy, unsigned long prawy) {
	if(prawy<=lewy) return;
	int srodek = (prawy+lewy)/2;
	sortowaniePrzezScalanie(tab, lewy, srodek);
	sortowaniePrzezScalanie(tab, srodek+1, prawy);
	scalanie(tab, lewy, srodek, prawy);
}

template <typename T>
void sortScalanie(T* tab, unsigned long wielkoscTablicy, unsigned long lewy, unsigned long prawy) {
    pom<T> = new T[wielkoscTablicy];
	sortowaniePrzezScalanie(tab, lewy, prawy);
    delete [] pom<T>;
}

#endif // SORTSCALANIE_H_INCLUDED
