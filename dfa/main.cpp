#include <iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include <fstream>
#include<windows.h>
using namespace std;
class automat
{
    int q;
    int *F;
    int f;
    char *V;
    int v;
    int g;
    int sc;

    struct trans{
        int a;  //incep
        int b;   //final
        char c;  //parcurc
	}*G;

	int tranzitie(int curent, char c)
    {
        int i;
        for(i=0;i<g;i++)
            if((G[i].a==curent)&&(G[i].c==c))
                return G[i].b;
        return -1;
    }

public:
    automat()
    {
        sc = 0;
        ifstream P("dfa.in");
        P>>q; // citesc numarul starilor din automat
        P>>f; //citesc numarul starilor finale din automat
        F = new int[f];
        for (int i=0;i<f;i++)
            P>>F[i];
        P>>v; //citesc cardinalul alfabetului
        V = new char[v];
        for (int i=0;i<v;i++)
            P>>V[i];
        P>>g; // citesc numarul tranzitiilor
        G = new trans[g];
        for (int i=0;i<g;i++)
            P>>G[i].a>>G[i].c>>G[i].b;
        P.close();
    }
    bool citire(char*cuvant)
    {
        for(int i=0;i<strlen(cuvant);i++)
        {
            sc=tranzitie(sc,cuvant[i]);
            if(sc==-1) return false;
        }
        for(int i=0;i<f;i++)
            if(sc==F[i]) return true;
        return false;

    }

};
int main()
{
    automat A;
    char w[100];
    cin>>w;
    if (A.citire(w) == true) cout<<"Cuvant acceptat";
    else cout<<"Cuvant respins";
    return 0;
}
