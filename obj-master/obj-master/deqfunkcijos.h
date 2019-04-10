#ifndef GUARD_DEQFUNKCIJOS_H
#define GUARD_DEQFUNKCIJOS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include <time.h>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <random>

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::deque;
using std::ifstream;
using std::ofstream;

struct stud
{
    string vrd;
    string pvrd;
    int n;
    deque <int> nd;
    int egz;
    double vid;
    double med;
};


bool arsk(const string &sk);
void skaic (deque <stud> &D);
void mskaic(deque <stud> &D);
void swap(struct stud* i, struct stud* j);
void sort(deque <stud> &D);
void atrinkimas(deque <stud> &D, deque <stud> &kietiakai, deque <stud> &vargsiukai);
void isvedimas (deque <stud> &D, deque <stud> &kietiakai, deque <stud> &vargsiukai);
void rivedimas(deque <stud> &D,deque <stud> &k,deque <stud> &v);
void generavimas(string irasai);
void fivedimas(deque <stud> &D,deque <stud> &k,deque <stud> &v, string irasai);
void ivedimas (deque <stud> &D,deque <stud> &k,deque <stud> &v, string irasai);

#endif // FUNKCIJOS_H
