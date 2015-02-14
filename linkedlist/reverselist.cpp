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
    int i,n,d;
    cin>>n;
    cin>>d;
    link *a=new link(d,0);
    link *b,*c,*e;
    b=a;
    for(i=1;i<n;i++){
        cin>>d;
        c=new link(d,0);
        a->next=c;
        a=a->next;
        //cout<<a->val;
    }
    a=b;
    while(a!= NULL){cout<<a->val<<"->";a=a->next;}
    cout<<"\n";
    link *p,*q,*r;
    /*e=new link(a->val,0);
    a=a->next;
    while(a!=NULL){
        c=new link(a->val,e);
        e=c;
        a=a->next;
    }
    while(e!=NULL){cout<<e->val<<"->";e=e->next;}*/
    p=b;
    q=p->next;
    p->next=0;
    while(q!=NULL){
        r=q->next;
        q->next=p;
        p=q;q=r;
    }
    while(p!= NULL){cout<<p->val<<"->";p=p->next;}
}
