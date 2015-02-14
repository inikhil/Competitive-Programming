#include<iostream>
#include<cstdio>
#include<list>
#include<cstdlib>
using namespace std;

class node{
public:
    int index;
    char col;
    node* prev;
    int d;
    int f;
    node(int i){index=i;col='w';prev=NULL;d=0;f=0;}
};

class graph{
public:
    int v;
    node **p;
    list<int> *adj;
    void addedge(int u,int v);
    graph(int v);
    bool dfs();
    bool cycle(int i);
    void print();
    void printnodes();
};

graph::graph(int v){
    int i;
    this->v=v;
    adj=new list<int>[v];
    p=new node*[v];
    for(i=0;i<v;i++){p[i]=new node(i);}
}

void graph::addedge(int u,int v){
    adj[u].push_back(v);
}

int time=0;

bool graph::cycle(int u){
    p[u]->col='g';
    time=time+1;
    p[u]->d=time;
    list<int>:: iterator j;
    for(j=adj[u].begin();j!=adj[u].end();j++){
        if(p[(*j)]->col=='g'){return false;}
        else if(p[(*j)]->col=='w'){return cycle(*j);}
    }
    p[u]->col='b';
    time=time+1;
    p[u]->f=time;
    return true;
}

bool graph::dfs(){
    int i;
    for(i=0;i<v;i++){
        if(p[i]->col=='w'){
            if(cycle(i)==false){return false;}
        }
    }
    return true;
}

void graph::print(){
    int i;
    list<int>::iterator j;
    for(i=0;i<v;i++){
        cout<<i<<":: ";
        for(j=adj[i].begin();j != adj[i].end();j++){
            cout<<(*j)<<"->";
        }
        cout<<"\n";
    }
}
void graph::printnodes(){
    int i;
    for(i=0;i<v;i++){
        cout<<p[i]->index<<" ";
    }
    cout<<"\n";
}

int main(){
    int n;cin>>n;
    int i,p,q;
    graph g(n);
    for(i=0;i<n;i++){
        cin>>p>>q;
        g.addedge(p,q);
    }
    g.print();
    g.printnodes();
    if(g.dfs()){cout<<"NO cycle found"<<endl;}
    else{cout<<"cycle exists"<<endl;}
}

