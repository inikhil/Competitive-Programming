#include<iostream>
using namespace std;
class node{
    public:
    node(int k,node* pp=0){
        key=k;
        next=pp;
    }
    int key;
    node *next;
};
int print(node **p,int n){
    int i;
    for(i=0;i<n;i++){
        while(p[i]!=0){
            cout<<p[i]->key<<"->";
            p[i]=p[i]->next;
        }
        cout<<"\n";
    }
    return 0;
}
node** adjacencylist(int **a,int n){
    node** p =new node*[n];
    int i,m,t;
    node *q=0,*r=0;
    for(i=0;i<n;i++)
    {
       p[i]=0;
    }
    for(i=0;i<n;i++){
        p[i]=new node(i+1,0);
    }
    for(i=0;i<n-1;i++){
        m=a[i][0];
        t=a[i][1];
        q=p[m-1];
        r=p[t-1];
       while(q->next!=0){
            q=q->next;
        }
        while(r->next!=0){
            r=r->next;
        }
        q->next=new node(t,0);
        r->next=new node(m,0);
    }
    return p;
}
int check(node **p,int k,int n){
    int i,m,d=0;
    for(i=0;i<n;i++){
        m=-1;
        while(p[i]!=0){
            m++;
            p[i]=p[i]->next;
        }
        if(m<=k){
            d=d+k;
        }
    }
    return d;
}
int main(){
    int n,k,i,d;
    cin>>n;
    cin>>k;
    int **a =new int*[n-1];
    for(i=0;i<n-1;i++){
        a[i]=new int[2];
    }
    for(i=0;i<n-1;i++){
        cin>>a[i][0];
        cin>>a[i][1];
    }
    node **p;
    p=adjacencylist(a,n);
    d=check(p,k,n);
    if(k>=1){
        cout<<d+n+1;
    }
    if(k=0){
        cout<<1;
    }
    return 0;
}
