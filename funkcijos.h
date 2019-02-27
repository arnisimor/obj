#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <cmath>
#include <algorithm>
#include <fstream>

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


#define data "A.txt";

bool arsk(const string &sk);
void skaic (vector <stud> &D);
void mskaic(vector <stud> &D);
void swap(struct stud* i, struct stud* j);
void sort(vector <stud> &D);
void isvedimas (vector <stud> &D);
void rivedimas(vector <stud> &D);
void fivedimas(vector <stud> &D);
void ivedimas (vector <stud> &D);

#endif // FUNKCIJOS_H