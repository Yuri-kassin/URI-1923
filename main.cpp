#include<iostream>
#include<vector>
#include<queue>
#include <cstdlib>
#include <map>
#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > g;
vector<string> auxi;
map<string, int> m1;
map<int, string> m2;

int busca(string a, int *x){
    map<string,int>::iterator it;
    it = m1.find(a);
    int z;
    if(it == m1.end()){
        m1.insert(pair<string,int>(a,*x));
        m2.insert(pair<int,string>(*x,a));
        z = *x;
        *x=*x+1;
    }
    else{
        z= m1.find(a)->second;
    }
    return z;
}

vector<int> bfs(int inicio, int W)
{
    //para os 3 vetores a seguir, cada posi��o do vetor representa um vertice do grafo.
    vector<int> d(g.size(), -1); // Vetor de dist�ncia minima para alcan�ar o vertice.
    vector<int> p(g.size(), -1); // Vetor que armazena o pai de cada vertice.
    vector<bool> cor(g.size(), false); // Define se cada vertice ja foi encontrado ou n�o.

    queue<int> Q; // Fila que define a ordem de acesso aos vertices.

    // Inicializa��o
    cor[inicio] = true; // Define a cor do v�rtice raiz como acessado.
    d[inicio] = 0; // Define a dist�ncia da raiz para ela mesma como 0.

    Q.push(inicio); // Enfileira a raiz.

    // Enquanto a fila n�o estiver vazia.
    while(!Q.empty())
    {
        int u = Q.front(); // Define u como sendo o v�rtice na frente na fila.
        Q.pop(); // Desenfileira.
//        cout<<"vertice atual: "<<u<<endl;
        // Para todo vertice adjacente � "u".
        for(int i = 0; i < g[u].size(); i++)
        {
            // Se o vertice adjacente � "u" n�o tiver sido encontrado.
            if(cor[g[u][i]] == false)
            {
//                cout<<g[u][i]<<endl;
                Q.push(g[u][i]); // Enfileira o vertice adjacente.
                cor[g[u][i]] = true; // Define o vertice adjacente como encontrado.
                d[g[u][i]] = d[u]+1; // Define a distancia minima para alcan�ar o vertice.
                if(d[u]+1<=W){
                    auxi.push_back(m2.find(g[u][i])->second);
                }
                p[g[u][i]] = u; // Define o pai do vertice adjacente como "u".
            }
        }
//        cout<<endl;
    }

    // *** OBS: O RETORNO DA FUN��O PODE SER ALTERADO CONFORME A NECESSIDADE DO PROBLEMA. ***
    return d; // Retorna o vetor peso.
}

int main()
{
    int N,M;
    map<string,int>::iterator it;
    map<int,string>::iterator ti;
    cin>>N>>M;
    int x,y;

    g.resize(N+1);
    string a,b;
    m1["Rerisson"] = 0;
    m2[0]="Rerisson";
    int aux=1;
    for(int i=0;i<N;i++)
    {
        cin>>a;
        cin>>b;

        x = busca(a,&aux);
        y = busca(b,&aux);


        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> dist = bfs(0,M);
    cout<<auxi.size()<<endl;
    sort(auxi.begin(),auxi.end());
    for (int j = 0; j < auxi.size(); ++j) {
        cout<<auxi[j]<<endl;
    }
    auxi.clear();
    m1.clear();
    m2.clear();

    system("pause");

    return 0;
}
