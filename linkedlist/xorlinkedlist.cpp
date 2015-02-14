#include<iostream>
#include<cstdio>
using namespace std;

class node{
public:
    int val;
    node * npx;
    node(int d,node *p){val=d;p=npx;}
};

node* XOR (node *a, node *b)
{
    return (node*) ((unsigned int) (a) ^ (unsigned int) (b));
}

void printlist(node *p){
     node *prev=NULL,*next;
     while(p!=NULL){
            cout<<p->val<<" ";
            next=XOR(prev,p->npx);
            prev=p;
            p=next;
     }
}

node* insertlist(){
    int n,i,k;
    cin>>n;
    cin>>k;
    node *p=new node(k,0);
    node *q=p,*r,*prev=NULL;
    for(i=1;i<n;i++){
        cin>>k;
        r=new node(k,0);
        q->npx=XOR(prev,r);
        prev=q;
        q=r;
    }
    q->npx=XOR(prev,NULL);
    printlist(p);
    cout<<"\n";
    printlist(q);
    return q;
}


int main(){
    node *p;
    p=insertlist();
    //printlist(p);
}
