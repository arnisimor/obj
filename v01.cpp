#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
int studsk=0;

struct stud
{
    string vrd;
    string pvrd;
    int n;
    vector <int> nd;
    int egz;
    double vid;

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
        galv=0.4*(ndsuma/D[studsk].n)+0.6*D[studsk].egz;
        D[studsk].vid=galv;
        cout<<D[studsk].vid;
    }
}
void isvedimas (vector <stud> &D)
{
    cout<<"Vardas"<<std::setw(14)<<"Pavarde"<<std::setw(24)<<"Vidurkis"<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    for(int i=0; i<studsk; i++)
    {
        cout<<D[studsk].vrd<<std::setw(14)<<D[studsk].pvrd<<std::setw(24)<<std::setprecision(2)<<D[studsk].vid<<endl;
    }
}
void ivedimas (vector <stud> &D)
{
    pradzia:
    int n=0;
    double gal[256];
    string tikrinama="t";
    while(tikrinama=="t"){
    cout<<"Iveskite t raide, jei norite prideti studento duomenis: ";
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
        cout<<endl;
        cout<<"Iveskite studento pazymius: "<<endl;
        for(int i=1; i<=D[studsk].n; i++)
        {
            int pzm;
            cout<<"Pazymys nr. "<<i<<": ";
            cin>>pzm;
            D[studsk].nd.push_back(pzm);
        }
        cout<<"Iveskite studento egzamino rezultata: ";
        int e;
        cin>>e;
        D[studsk].egz=e;
        studsk++;
        kaic(D);
    }
    else
    {
        isvedimas(D);
    }
    }

}


int main()
{
vector <stud> D;
ivedimas(D);
return 0;
}
