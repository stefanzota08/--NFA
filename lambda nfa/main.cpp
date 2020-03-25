#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class automat
{
    int q;
    int f;
    int *F;
    int v;
    char *V;
    int g;
    struct trans
    {
        int a;
        int b;
        char c;
    } *G;
    int sc;
    int exista;

public:
    automat()
    {
        int i;
        ifstream P("lmbd-nfa.in");
        P>>q>>f;
        F = new int[f];
        for (i=0; i<f; i++)
            P>>F[i];
        P>>v;
        V = new char[v];
        for(i=0; i<v; i++)
            P>>V[i];
        P>>g;
        G = new trans[g];
        for(i=0; i<g; i++)
            P>>G[i].a>>G[i].c>>G[i].b;
        P.close();
        sc = 0;
        exista = 0;
    }

    bool verificare(char *cuvant, int sc, int pozitie_cuvant)
    {
        int i;
        if ((pozitie_cuvant==strlen(cuvant))&& sc<=q)
        {
            for(i=0; i<f; i++)
                if(sc == F[i])
                {
                    exista = 1;
                    return true;
                }
        }
        else
        {
            for(i=0; i<g; i++)
            {
                if(exista == 1)
                    return true;

                if(G[i].a == sc && G[i].c == cuvant[pozitie_cuvant])
                    verificare(cuvant, G[i].b, pozitie_cuvant+1);
                else if(G[i].a == sc && G[i].c =='^')
                    verificare(cuvant, G[i].b, pozitie_cuvant);
            }
        }
        return false;
    }

};

int main()
{
    char w[100];
    automat NFA;
    cin>>w;
    if(NFA.verificare(w,0,0) == true)
        cout<<"ACCEPTAT";
    else cout<<"RESPINS";
    return 0;
}
