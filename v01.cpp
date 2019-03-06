#include "funkcijos.h"

int main()
{
vector <stud> D;
vector <stud> k;
vector <stud> v;
auto start = std::chrono::high_resolution_clock::now();
ivedimas(D,k,v);
auto finish = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = finish - start;
std::cout << "veikimo laikas: " << elapsed.count() << " s\n";
return 0;
}
