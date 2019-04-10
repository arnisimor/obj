#include "funkcijos.h"

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

int studsk=0;
int const ndsk=5;
int irasai=0;
bool arsk(const string &sk)
{
    string::const_iterator sv=sk.begin();
    while(sv!=sk.end()&&std::isdigit(*sv)) ++sv;
    return !sk.empty()&&sv==sk.end();
}

void skaic (vector <stud> &D)
{
    double ndsuma=0, galv=0;
    for(int i=0; i<D[studsk].n; i++)
    {
        ndsuma=ndsuma+D[studsk].nd[i];
    }
    galv=0.4*(ndsuma/D[studsk].n)+(0.6*D[studsk].egz);
    D[studsk].vid=galv;
}

void mskaic(vector <stud> &D)
{
    std::sort(D[studsk].nd.begin(),D[studsk].nd.end());
    if(D[studsk].n % 2 == 0)
        {
            D[studsk].med=(D[studsk].nd[D[studsk].n/2-1]+D[studsk].nd[D[studsk].n/2])/2;
        }
        else
        {
            D[studsk].med=(D[studsk].nd[D[studsk].n/2]);
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
bool compare_m (stud &a, stud &b){
  return a.vid<b.vid;
}

    void skirstymas(vector < stud > & D, vector < stud > & kietiakai, vector < stud > & vargsiukai) {
   sort(D.begin(), D.end(), compare_m);

   vector < stud > ::iterator ptr = D.begin();
   for (vector < stud > ::iterator it = D.begin(); it != D.end(); it++) {
      if (( * it).vid >= 5) {
         ptr = it;
         break;
      }
   }
   nenaudeliai.resize(ptr - D.begin());
   nenaudeliai.assign(D.begin(), ptr);
   D.resize(D.end() - ptr);
   D.assign(ptr, D.end());
}

void isvedimas (vector <stud> &D, vector <stud> &kietiakai, vector <stud> &vargsiukai)
{
    ofstream frk("kietiakai.txt",std::ios::app);
    ofstream frv("vargsiukai.txt",std::ios::app);
    frk<<"Vardas"<<std::setw(14)<<"Pavarde"<<std::setw(45)<<"Galutinis(vid.)/Galutinis(med)"<<endl;
    frk<<"----------------------------------------------------------------------------------"<<endl;
    for(auto &i:kietiakai)
    {
        frk<<i.vrd<<std::setw(14)<<i.pvrd<<std::setw(24)<<std::fixed<<std::setprecision(2)<<i.vid<<std::setw(24)<<std::fixed<<std::setprecision(2)<<i.med<<endl;
    }
    frk.close();
    frv<<"Vardas"<<std::setw(14)<<"Pavarde"<<std::setw(45)<<"Galutinis(vid.)/Galutinis(med)"<<endl;
    frv<<"----------------------------------------------------------------------------------"<<endl;
    for(auto &i:vargsiukai)
    {
        frv<<i.vrd<<std::setw(14)<<i.pvrd<<std::setw(24)<<std::fixed<<std::setprecision(2)<<i.vid<<std::setw(24)<<std::fixed<<std::setprecision(2)<<i.med<<endl;
    }
    frv.close();
}

void rivedimas(vector <stud> &D,vector <stud> &k,vector <stud> &v)
{
    string tikrinama="t";
    while(tikrinama=="t"){
    cout<<"Iveskite t raide, jei norite prideti studento duomenis, jei ne, spauskite kita raide: ";
    cin>>tikrinama;
    if(tikrinama=="t")
    {
    D.push_back(stud());
    vardoc:
        cout<<endl<<"Iveskite studento varda: ";
        string v;
        cin>>v;
        string kl = "Varde negali buti tik skaiciai!";
        try {
        if (arsk(v)==true)
          throw kl;

      } catch (string kl) {
        cout << kl << endl;
        goto vardoc;
      }
        D[studsk].vrd=v;
        pvrdc:
        cout<<"Iveskite studento pavarde: ";
        string p;
        cin>>p;
        string klp = "Pavardeje negali buti tik skaiciai!";
        try {
        if (arsk(p)==true)
          throw klp;

      } catch (string klp) {
        cout << klp << endl;
        goto pvrdc;
      }
        D[studsk].pvrd=p;
        pradzia:
        cout<<"iveskite namu darbu uzduociu skaiciu: ";
        string snd;
        cin>>snd;
        if(arsk(snd)==false)
        {
            cout<<"ivestas skaicius netinkamas, iveskite tinkama skaiciu (teigiama sveikaji skaiciu) "<<endl;
            goto pradzia;
        }
        else
        {
            D[studsk].n=std::stoi(snd);
        }
        pcheck:
        cout<<"Ar norite ivesti pazymius (t), ar sugeneruoti atsitiktinai(a)?"<<endl;
        string ptkr;
        cin>>ptkr;
        int pzm;
        string pazym;
        int e;
        if(ptkr=="t")
        {
            cout<<endl;
            cout<<"Iveskite studento pazymius: "<<endl;
            for(int i=0; i<D[studsk].n; i++)
            {
                pazymiai:
                    cout<<"Pazymys nr. "<<i+1<<": ";
                    cin>>pazym;
                    if(arsk(pazym)==false)
                    {
                        cout<<"Iveskite skaiciu!";
                        goto pazymiai;
                    }
                    else
                    {
                        pzm=std::stoi(pazym);
                        D[studsk].nd.push_back(pzm);
                    }
            }
            cout<<"Iveskite studento egzamino rezultata: ";
            int e;
            cin>>e;
            D[studsk].egz=e;
            skaic(D);
            mskaic(D);
            studsk++;
        }
        else if(ptkr=="a")
        {
            srand(time(NULL));
            for(int i=0; i<D[studsk].n; i++)
            {
                pzm=1+std::round((double)rand()/RAND_MAX*(10-1));
                D[studsk].nd.push_back(pzm);
            }
                srand(time(NULL));
                e=1+(double)rand()/RAND_MAX*(10-1);
                skaic(D);
            mskaic(D);
            sort(D);
            studsk++;
        }
        else
            {
            cout<<"ivedete netinkama raide!"<<endl;
            goto pcheck;
        }
    }
    }
    sort(D);
    skirstymas(D,k,v);
    isvedimas(D,k,v);
}

void generavimas(string irasai) {
    int ir;
    ir=std::stoi(irasai);
    string fd="studentai" + irasai + ".txt";
      ofstream fr(fd);
  string studv = "vardas";
  string studp = "pavarde";
  //fr << "ivedimas" << endl;
  int sk[ndsk];
  int egz;
  std::mt19937 rand(time(0));
  std::uniform_int_distribution<int> pazymiai(1,10);
  for (int i=0; i<=ir; i++) {
    fr << studv << i << "  " << studp << i << "  ";
    for (int j = 0; j < ndsk; j++) {
      sk[j] = std::round(pazymiai(rand));
      fr << sk[j] << "  ";
    }
    egz = std::round(pazymiai(rand));
    fr << egz << endl;
  }
  fr.close();
}

void fivedimas(vector <stud> &D,vector <stud> &k,vector <stud> &v,string irasai)
{
    generavimas(irasai);
    auto pavad=irasai;
  ifstream in ("studentai" + pavad + ".txt");
in.ignore(256,'\n');
int p;

while(!in.eof()){
D.push_back(stud());
in>>D[studsk].vrd>>std::ws>>D[studsk].pvrd;
for(int i=0;i<ndsk;i++){
in>>p;
D[studsk].nd.push_back(p);
}
in>>D[studsk].egz;
D[studsk].n=ndsk;
in.ignore(0,'\n');
skaic(D);
mskaic(D);
studsk++;
}
studsk=studsk-1;
skirstymas(D,k,v);
isvedimas(D,k,v);
}

void ivedimas (vector <stud> &D,vector <stud> &k,vector <stud> &v, string irasai)
{
    string tikrinama;
    //string zmoniusk;
    cout<<"Iveskite r raide, jei ranka norite prideti studento duomenis, jei norite nuskaityti is failo, spauskite bet kuri kita mygtuka: ";
    cin>>tikrinama;
    if(tikrinama=="r")
    {
        rivedimas(D,k,v);
        }
        else
        {
            irasucp:
            cout<<"iveskite kiek zmoniu duomenu bus:"<<endl;
            cin>>irasai;
            if(arsk(irasai)==false)
        {
            cout<<"ivestas skaicius netinkamas, iveskite tinkama skaiciu (teigiama sveikaji skaiciu) "<<endl;
            goto irasucp;
        }
        else
        {
        {
            generavimas(irasai);
        }
            auto start = std::chrono::high_resolution_clock::now();
            fivedimas(D,k,v,irasai);
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            std::cout << "veikimo laikas: " << elapsed.count() << " s\n";
        }
}
}
