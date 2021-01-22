#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
ifstream in ("t.in");
struct nod
{
    char nr[200],prod[200],model[200],pret[200],culoare[200];
    nod *urm;
};
struct qq
{
    char nrr[200],prodd[200],modell[200],prett[200],culoaree[200];
    qq *urmm;
};
qq *cap1=NULL;
nod *cap=NULL;
void fisier ()
{
    char a[300],s[200],b[300];
    memset(a,0,300);
    int i=0,k=0,j=0;
    in.get();
    while(in.getline(s,200))
    {
        nod *p= new nod;
        p->urm=cap;
        memset(a,0,300);
        i=0;
        k=0;
        while(s[i]!='*')
        {
            a[k]=s[i];
            k++;
            i++;
        }
        strcpy(p->nr,a);
        memset(a,0,300);
        i++;
        k=0;
        while(s[i]!='*')
        {
            a[k]=s[i];
            k++;
            i++;
        }
        strcpy(p->prod,a);
        memset(a,0,300);
        i++;
        k=0;
        while(s[i]!='*')
        {
            a[k]=s[i];
            k++;
            i++;
        }
        strcpy(p->model,a);
        memset(a,0,300);
        i++;
        k=0;
        while(s[i]!='*')
        {
            a[k]=s[i];
            k++;
            i++;
        }
        strcpy(p->culoare,a);
        memset(a,0,300);
        i++;
        k=0;
        while(s[i]!='*')
        {
            a[k]=s[i];
            k++;
            i++;
        }
        strcpy(p->pret,a);
        p->urm=cap;
        cap=p;
    }
}
void addFisier(char *nr,char *prod,char *model,char *culoare,char *pret)
{
    fstream in("t.in",ios::app);
    in<<nr;
    in<<'*';
    in<<prod;
    in<<'*';
    in<<model;
    in<<'*';
    in<<culoare;
    in<<'*';
    in<<pret;
    in<<'*';
    in<<'\n';
    in.close();
}
void adaugaMasina ()
{
    char nr[200],prod[200],model[200],culoare[200],pret[200];
    cout<<"\n";
    cout<<" 1. Adaugare masina\n";
    cout<<"\n";
    cout<<" Introduceti urmatoarele informatii despre masina:\n";
    cout<<"\n";
    cin.get();
    cout<<" Numar de inmatriculare: ";
    cin.getline(nr,200);
    cout<<" Nume producator: ";
    cin.getline(prod,200);
    cout<<" Model: ";
    cin.getline(model,200);
    cout<<" Culoare: ";
    cin.getline(culoare,200);
    cout<<" Pret(euro): ";
    cin.get(pret,200);
    cout<<"\n";
    cout<<" Informatiile au fost introduse cu succes in baza de date./n";
    cout<<"\n";
    addFisier(nr,prod,model,culoare,pret);
}
void UP (char *s)
{
    int i=0;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>='a'&&s[i]<='z')s[i]=s[i]-32;
    }
}
void cautaNr (char *s)
{
    nod *p=cap;
    int ok=0;
    char aux[200];
    strcpy(aux,s);
    UP(aux);
    while (p)
    {
        if(stricmp(p->nr,s)==0)
        {
            cout<<" Informatiile despre masina sunt urmatoarele:\n";
            cout<<"\n";
            cout<<" Producator: "<<p->prod<<"\n";
            cout<<" Model: "<<p->model<<"\n";
            cout<<" Pret: "<<p->pret<<" euro"<<"\n";
            cout<<" Culoare: "<<p->culoare<<"\n";
            ok=1;
            break;
        }
        else p=p->urm;
    }
    if (ok==0)
    {
        cout<<"\n";
        cout<<" Informatii despre masina cu numarul de inmatriculare: "<<aux<<endl;
        cout<<"\n";
        cout<<" NU EXISTA!";
        cout<<"\n";
        cout<<"\n";
    }
}
void cautaCuloare (char *s)
{
    nod *p=cap;
    int ok=0,j=0;
    while (p)
    {
        ok=0;
        if(stricmp(p->culoare,s)==0)ok=1;
        if(ok==1)
        {
            j++;
            cout<<"\n";
            cout<<" Producator: "<<p->prod<<"\n";
            cout<<" Model: "<<p->model<<"\n";
            cout<<" Pret: "<<p->pret<<" euro"<<"\n";
            cout<<" Numar de inmatriculare: "<<p->nr<<"\n";
            cout<<"\n";
        }
        p=p->urm;
    }
    if (j==0)
    {
        cout<<"\n";
        cout<<" NU EXISTA!";
        cout<<"\n";
        cout<<"\n";
    }
}
void cautaPret (char *s, char *c)
{
    int pMin,pMax,pt,ok=0,j=0;
    pMin=atoi(s);
    pMax=atoi(c);
    nod *p=cap;
    while (p)
    {
        pt=atoi(p->pret);
        ok=0;
        if(pt>=pMin&&pt<=pMax)ok=1;
        if(ok==1)
        {
            j++;
            cout<<"\n";
            cout<<" Producator: "<<p->prod<<"\n";
            cout<<" Model: "<<p->model<<"\n";
            cout<<" Pret: "<<p->pret<<" euro"<<"\n";
            cout<<" Culoare: "<<p->culoare<<"\n";
            cout<<" Numar de inmatriculare: "<<p->nr<<"\n";
            cout<<"\n";
        }
        p=p->urm;
    }
    if (j==0)
    {
        cout<<"\n";
        cout<<" NU EXISTA!";
        cout<<"\n";
        cout<<"\n";
    }
}
void ordonareLista (qq *&p)
{
    qq *a;
    int ok=0;
    do
    {
        a=p;
        ok=1;
        while(a->urmm)
        {
            if (stricmp(a->modell,a->urmm->modell)>0)
            {
                ok=0;
                swap(a->modell,a->urmm->modell);
                swap(a->prett,a->urmm->prett);
                swap(a->culoaree,a->urmm->culoaree);
                swap(a->nrr,a->urmm->nrr);
            }
            a=a->urmm;
        }
    }
    while(ok==0);
}
void cautaMasiniProducator (char *s)
{
    nod *p=cap;
    char model[200][200],pret[200][200],culoare[200][200],nr[200][200];
    int ok=0,j=0,i=0;
    while (p)
    {
        if(stricmp(p->prod,s)==0)
        {
            ok=1;
            strcpy(model[j],p->model);
            strcpy(pret[j],p->pret);
            strcpy(culoare[j],p->culoare);
            strcpy(nr[j],p->nr);
            j++;
        }
        if(p!=0)p=p->urm;
    }
    if (ok==1)
    {
        qq *c;
        for(i=0; i<j; i++)
        {
            qq *c=new qq;
            strcpy(c->modell,model[i]);
            strcpy(c->prett,pret[i]);
            strcpy(c->culoaree,culoare[i]);
            strcpy(c->nrr,nr[i]);
            c->urmm=cap1;
            cap1=c;
        }
        ordonareLista(cap1);
        while(cap1)
        {
            cout<<"\n";
            cout<<" Model: "<<cap1->modell<<"\n";
            cout<<" Pret: "<<cap1->prett<<" euro"<<"\n";
            cout<<" Culoare: "<<cap1->culoaree<<"\n";
            cout<<" Numar de inmatriculare: "<<cap1->nrr<<"\n";
            cout<<"\n";
            cap1=cap1->urmm;
        }
    }
    else
    {
        cout<<"\n";
        cout<<" NU EXISTA!";
        cout<<"\n";
        cout<<"\n";
    }
}
void meniu ()
{
    int n;
    char s[200],c[200],pm[200],pM[200],pr[200],aux[200],aux1[200],aux2[200];
    cout<<"\n";
    cout<<" MENIU\n";
    cout<<"\n";
    cout<<" 1. Adaugare masina\n";
    cout<<"\n";
    cout<<" 2. Cautare masina dupa numarul de inmatriculare\n";
    cout<<"\n";
    cout<<" 3. Afisare masini de o anumita culoare\n";
    cout<<"\n";
    cout<<" 4. Afisare masini cu pretul cuprins intr-un anumit interval\n";
    cout<<"\n";
    cout<<" 5. Afisare masini ale unui producator, in ordine alfabetica, dupa model\n";
    cout<<"\n";
    cout<<" 6. Iesire program\n";
    cout<<"\n";
    cout<<" ATENTIE! Dupa fiecare introducere a datelor apasati tasta ENTER.\n";
    cout<<"\n";
    cout<<" Introduceti numarul optiunii dorite: ";
    cin>>n;
    if(n==1)
    {
        system("cls");
        adaugaMasina();
        fisier();
        system("pause");
        system("cls");
        meniu();
    }
    else if(n==2)
    {
        system("cls");
        fisier();
        cout<<endl;
        cout<<" 2. Cautare masina dupa numarul de inmatriculare\n";
        cout<<"\n";
        cout<<" Introduceti numarul de inmatriculare: ";
        cin.get();
        cin.getline(s,200);
        cout<<"\n";
        cautaNr(s);
        cout<<"\n";
        system("pause");
        system("cls");
        meniu();
    }
    else if (n==3)
    {
        system("cls");
        fisier();
        cout<<endl;
        cout<<" 3. Afisare masini de o anumita culoare\n";
        cout<<"\n";
        cout<<" Introduceti culoarea dorita: ";
        cin.get();
        cin.getline(c,200);
        strcpy(aux,c);
        UP(aux);
        cout<<"\n";
        cout<<" Informatii despre masinile de culoarea "<<aux<<": \n";
        cautaCuloare(c);
        cout<<"\n";
        system("pause");
        system("cls");
        meniu();
    }
    else if(n==4)
    {
        system("cls");
        cout<<endl;
        cout<<" 4. Afisare masini cu pretul cuprins intr-un anumit interval\n";
        cout<<"\n";
        cout<<" Introduceti pret minim(euro): ";
        fisier();
        cin.get();
        cin.getline(pm,200);
        cout<<" Introduceti pret maxim(euro): ";
        cin.getline(pM,200);
        cout<<"\n";
        cout<<" Informatii despre masinile cu pretul cuprins intre "<<pm<<" euro si "<<pM<<" euro: \n";
        cautaPret(pm,pM);
        cout<<"\n";
        system("pause");
        system("cls");
        meniu();
    }
    else if (n==5)
    {
        system("cls");
        fisier();
        cout<<endl;
        cout<<" 5. Afisare masini ale unui producator, in ordine alfabetica, dupa model\n";
        cout<<"\n";
        cout<<" Introduceti producatorul: ";
        cin.get();
        cin.getline(pr,200);
        strcpy(aux1,pr);
        UP(aux1);
        cout<<"\n";
        cout<<" Informatii despre modelele producatorului "<<aux1<<": \n";
        cautaMasiniProducator(pr);
        cout<<"\n";
        system("pause");
        system("cls");
        meniu();
    }
    else if(n==6)
    {
        system("cls");
        cout<<"\n";
        cout<<" 6. Iesire\n";
        cout<<"\n";
        cout<<" Apasati tasta ENTER pentru a inchide programul.";
        cout<<"\n";
        cout<<"\n";
        return;
    }
}
int main()
{
    meniu();
    return 0;
}
