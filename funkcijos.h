#ifndef GUARD_FUNKCIJOS_H
#define GUARD_FUNKCIJOS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
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
using std::vector;
using std::ifstream;
using std::ofstream;

struct stud
{
    string vrd;
    string pvrd;
    int n;
    vector <int> nd;
    int egz;
    double vid;
    double med;
};


bool arsk(const string &sk);
void skaic (vector <stud> &D);
void mskaic(vector <stud> &D);
void swap(struct stud* i, struct stud* j);
void sort(vector <stud> &D);
void atrinkimas(vector <stud> &D, vector <stud> &kietiakai, vector <stud> &vargsiukai);
void isvedimas (vector <stud> &D, vector <stud> &kietiakai, vector <stud> &vargsiukai);
void rivedimas(vector <stud> &D,vector <stud> &k,vector <stud> &v);
void generavimas(string irasai);
void fivedimas(vector <stud> &D,vector <stud> &k,vector <stud> &v, string irasai);
void ivedimas (vector <stud> &D,vector <stud> &k,vector <stud> &v, string irasai);

#endif // FUNKCIJOS_H
