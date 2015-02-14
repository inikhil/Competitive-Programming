#include<iostream>
#include<list>

using namespace std;

class node{
public:
    char col;
    int d;
    int index;
    node* prev;
    int f;
    node(int i){col='w';d=0;prev=NULL;index=i;f=0;}
};

class graph{
    public:
    int v;
    list<node> *a;
    graph(int v);
    void addedge(node u,node v);
    void print();
    void dfs(node **p);
    void dfsvisit(node **p,int n);
};

graph::graph(int v){
    this->v=v;
    a=new list<node>[v];
}

void graph::addedge(node u,node v){
    a[u.index].push_back(v);
}

void graph::print(){
    int i;
    list<node>::iterator j;
    for(i=0;i<v;i++){
        cout<<i<<":: ";
        for(j=a[i].begin();j != a[i].end();j++){
            cout<<(*j).index<<"->";
        }
        cout<<"\n";
    }
}

int time=0;

void graph::dfsvisit(node **p,int u){
    p[u]->col='g';
    time=time+1;
    p[u]->d=time;
    list<node> ::iterator j;
    for(j=a[u].begin();j!=a[u].end();j++){
        if(p[(*j).index]->col=='w'){
            p[(*j).index]->prev=p[u];
            dfsvisit(p,(*j).index);
        }
    }
    p[u]->col='b';
    time=time+1;
    p[u]->f=time;
}

void graph::dfs(node **p){
    int i;
    for(i=0;i<v;i++){
        if(p[i]->col=='w'){
            dfsvisit(p,i);
        }
    }
}

int main(){
    int n;cin>>n;
    int i,p,q;
    graph g(n);
    node *r;
    node **b=new node*[n];
    for(i=0;i<n;i++){b[i]=new node(i);}
    for(i=0;i<10;i++){
        cin>>p>>q;
        node u(p);
        node v(q);
        g.addedge(u,v);
    }
    g.print();
    g.dfs(b);
    for(i=0;i<n;i++){r=b[i]->prev;if(r){cout<<r->index<<" ";}else{cout<<"NULL"<<" ";}}
}

