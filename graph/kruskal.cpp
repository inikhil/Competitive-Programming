#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

class Edge{
public:
    int src;
    int dest;
    int wt;
};

class subset{
public:
    int parent;
    int ranking;
};

class graph{
public:
    int v,e;
    Edge * edge;
    subset * subsets;
    Edge * result;
    graph(int v, int e);
    void printgraph();
    void krushkal();
    int findset(int i);
    void unionset(int u,int v);
    void printresult();
};

bool compbywt(Edge a, Edge b){
    return a.wt<b.wt;
}

graph::graph(int v,int e){
    this->v=v;
    this->e=e;
    edge=new Edge[e];
    result=new Edge[v-1];
    subsets= new subset[v];
    int i;
    for(i=0;i<v;i++){
        subsets[i].parent=i;
        subsets[i].ranking=0;
    }
}

int graph::findset(int i){
    if(subsets[i].parent!=i){
        return findset(subsets[i].parent);
    }
    return subsets[i].parent;
}

void graph::unionset(int u,int v){
    int xroot=findset(u);
    int yroot=findset(v);
    if (subsets[xroot].ranking < subsets[yroot].ranking){
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].ranking > subsets[yroot].ranking){
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].ranking++;
    }
}

void graph::krushkal(){
    sort(edge,edge+e,compbywt);
    printgraph();
    int i=0,j=0;
    while(i<v-1 && j<e){
        int xroot=edge[j].src;
        int yroot=edge[j].dest;
        if(findset(xroot)!=findset(yroot)){
            result[i]=edge[j];
            unionset(xroot,yroot);
            i++;
        }
        j++;
    }
    printresult();
}

void graph::printresult(){
    int i;
    for(i=0;i<v-1;i++){
        cout<<result[i].src<<" "<<result[i].dest<<" "<<result[i].wt<<endl;
    }
}


void graph::printgraph(){
    int i;
    for(i=0;i<e;i++){
        cout<<edge[i].src<<" "<<edge[i].dest<<" "<<edge[i].wt<<endl;
    }
    cout<<"\n";
}

int main(){
    int ver=4;
    int edges=5;
    graph g(ver,edges);
    g.edge[0].src = 0;
    g.edge[0].dest = 1;
    g.edge[0].wt = 10;

    g.edge[1].src = 0;
    g.edge[1].dest = 2;
    g.edge[1].wt = 6;

    g.edge[2].src = 0;
    g.edge[2].dest = 3;
    g.edge[2].wt = 5;

    g.edge[3].src = 1;
    g.edge[3].dest = 3;
    g.edge[3].wt = 15;

    g.edge[4].src = 2;
    g.edge[4].dest = 3;
    g.edge[4].wt = 4;


//    g.creategraph();
    g.krushkal();
    //g.printgraph();
}
