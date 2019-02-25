#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <vector>
#include <time.h>
#include <cmath>
#include <algorithm>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
int studsk = 0;

struct stud {
  string vrd;
  string pvrd;
  int n;
  vector < int > nd;
  int egz;
  double vid;
  int med;
};

bool arsk(const string & sk) {
  string::const_iterator sv = sk.begin();
  while (sv != sk.end() && std::isdigit( * sv)) ++sv;
  return !sk.empty() && sv == sk.end();
}

void skaic(vector < stud > & D) {
  double ndsuma = 0, galv = 0;
  for (int i = 0; i < D[studsk].n; i++) {
    ndsuma = ndsuma + D[studsk].nd[i];
    galv = 0.4 * (ndsuma / D[studsk].n) + (0.6 * D[studsk].egz);
    D[studsk].vid = galv;
  }
}

void mskaic(vector < stud > & D) {
  std::sort(D[studsk].nd.begin(), D[studsk].nd.end());
  if (D[studsk].n % 2 == 0) {
    D[studsk].med = (D[studsk].nd[D[studsk].n / 2 - 1] + D[studsk].nd[D[studsk].n / 2]) / 2;
  } else {
    D[studsk].med = (D[studsk].nd[D[studsk].n / 2]);
  }
}
void swap(struct stud* i, struct stud* j)
{
    stud t;
     t = *i;
    *i = *j;
    *j = t;

}
void sort(vector <stud> &D)
{
		int i=0;
		bool swapped=true;
		while(swapped)
		{
            i++;
			swapped = false;
			for (int j = 0; j < studsk-i; j++)
			{
				if(D[j].vrd > D[j+1].vrd)
				{
					swap(&D[j],&D[j+1]);
					swapped = true;
				}
				if(D[j].vrd == D[j+1].vrd)
				{
					if(D[j].pvrd > D[j+1].pvrd)
					{
						swap(&D[j],&D[j+1]);
						swapped = true;
					}
				}
			}
		}
}
void fivedimas(vector <stud> &D)
{
    string pav;
    cout<<"iveskite failo pavadinima: ";
    cin>>pav;
    std::ifstream fd (pav+".txt");
    fd.ignore(256,'\n');
    int nmd;
    while(!fd.eof())
    {
        D.push_back(stud());
        fd>>D[studsk].vrd>>std::ws>>D[studsk].pvrd;
        for(int i=0; i<D[studsk].n; i++)
        {
            D[studsk].nd.push_back(nmd);
        }
        fd>>D[studsk].egz;
        fd.ignore(0,'\n');
        skaic(D);
        mskaic(D);
        studsk++;
    }
}

void isvedimas(vector < stud > & D) {
  cout << "Vardas" << std::setw(14) << "Pavarde" << std::setw(45) << "Galutinis(vid.)/Galutinis(med)" << endl;
  cout << "----------------------------------------------------------------------------------" << endl;
  for (int i = 0; i < studsk; i++) {
    cout << D[i].vrd << std::setw(14) << D[i].pvrd << std::setw(24) << std::fixed << std::setprecision(2) << D[i].vid << std::setw(24) << std::fixed << std::setprecision(2) << D[i].med << endl;
  }
}
void ivedimas(vector < stud > & D) {

  int n = 0;
  double gal[256];
  string pirmas;
        pradzia:
        cout << "iveskite namu darbu uzduociu skaiciu: ";
      string snd;
      cin >> snd;
      if (arsk(snd) == false) {
        cout << "ivestas skaicius netinkamas, iveskite tinkama skaiciu (teigiama sveikaji skaiciu) " << endl;
        goto pradzia;
      } else {
        D[studsk].n = std::stoi(snd);
      }
  cout<<"Pasirinkite ar įvesite failą patys (t), jei ne, spauskite bet kurį kitą mygtuką: "<<endl;
  cin>>pirmas;
  if(pirmas!="t")
  {
      fivedimas(D);
  }
  if(pirmas=="t")
  {
  string tikrinama = "t";
  while (tikrinama == "t") {
    cout << "Iveskite t raide, jei norite prideti studento duomenis: ";
    cin >> tikrinama;

    if (tikrinama == "t") {
      D.push_back(stud());
      cout << endl << "Iveskite studento varda: ";
      string v;
      cin >> v;
      D[studsk].vrd = v;
      cout << "Iveskite studento pavarde: ";
      string p;
      cin >> p;
      D[studsk].pvrd = p;
      pcheck:
        cout << "Ar norite ivesti pazymius (t), ar sugeneruoti atsitiktinai(a)?" << endl;
      string ptkr;
      cin >> ptkr;
      int pzm;
      string pazym;
      int e;
      if (ptkr == "t") {
        cout << endl;
        cout << "Iveskite studento pazymius: " << endl;
        for (int i = 0; i < D[studsk].n; i++) {
          pazymiai: cout << "Pazymys nr. " << i + 1 << ": ";
          cin >> pazym;
          if (arsk(pazym) == false) {
            cout << "Iveskite skaiciu!";
            goto pazymiai;
          } else {
            pzm = std::stoi(pazym);
            D[studsk].nd.push_back(pzm);
          }
        }
        cout << "Iveskite studento egzamino rezultata: ";
        int e;
        cin >> e;
        D[studsk].egz = e;
        cout << D[studsk].egz << endl;
      }
      srand(time(NULL));
      if (ptkr == "a") {
        for (int i = 0; i < D[studsk].n; i++) {
          pzm = 1 + std::round((double) rand() / RAND_MAX * (10 - 1));
          D[studsk].nd.push_back(pzm);

        }
        srand(time(NULL));
        e = 1 + (double) rand() / RAND_MAX * (10 - 1);

      }
      else
        {
        cout << "ivedete netinkama raide!" << endl;
        goto pcheck;
      }
    }
  }
  }

    else
        {

      isvedimas(D);
    }
}

int main() {
  vector < stud > D;
  ivedimas(D);
  return 0;
}
