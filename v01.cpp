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

int studsk=0;
int const ndsk=5;
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
void isvedimas (vector <stud> &D)
{
    cout<<"Vardas"<<std::setw(14)<<"Pavarde"<<std::setw(45)<<"Galutinis(vid.)/Galutinis(med)"<<endl;
    cout<<"----------------------------------------------------------------------------------"<<endl;
    for(int i=0; i<studsk; i++)
    {
        cout<<D[i].vrd<<std::setw(14)<<D[i].pvrd<<std::setw(24)<<std::fixed<<std::setprecision(2)<<D[i].vid<<std::setw(24)<<std::fixed<<std::setprecision(2)<<D[i].med<<endl;
    }
}
void rivedimas(vector <stud> &D)
{
    string tikrinama="t";
    while(tikrinama=="t"){
    cout<<"Iveskite t raide, jei norite prideti studento duomenis, jei ne, spauskite kita raide: ";
    cin>>tikrinama;
    if(tikrinama=="t")
    {
    D.push_back(stud());
        cout<<endl<<"Iveskite studento varda: ";
        string v;
        cin>>v;
        D[studsk].vrd=v;
        cout<<"Iveskite studento pavarde: ";
        string p;
        cin>>p;
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
    isvedimas(D);
}
void fivedimas(vector <stud> &D)
{
  ifstream in ("A.txt");
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
sort(D);
isvedimas(D);
}
void ivedimas (vector <stud> &D)
{
    string tikrinama;
    cout<<"Iveskite r raide, jei ranka norite prideti studento duomenis, jei norite nuskaityti is failo, spauskite bet kuri kita mygtuka: ";
    cin>>tikrinama;
    if(tikrinama=="r")
    {
        rivedimas(D);
        }
        else
        {
            fivedimas(D);
        }
}

int main()
{
vector <stud> D;
ivedimas(D);
return 0;
}
