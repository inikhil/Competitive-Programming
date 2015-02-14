#include<iostream>
#include<cstdio>
using namespace std;

class link{
public:
    int val;
    link *next;
    link(int d,link *p){val=d;next=p;}
};

int main(){
    int n,i,d,m,j;
    cin>>n;
    link **p =new link* [n];
    link **q;
    q=p;
    link *r,*s;
    for(i=0;i<n;i++){
        cin>>m;
        cin>>d;
        p[i]=new link(d,0);
        r=p[i];
        for(j=1;j<m;j++){
            cin>>d;
            s=new link(d,0);
            r->next=s;
            r=r->next;
        }
    }
    for(i=0;i<n;i++){
        r=p[i];
        while(r!=0){
            cout<<r->val<<"->";
            r=r->next;
        }
        cout<<"\n";
    }
}
