#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

class llist{
public:
    int val;
    llist *next;
    llist(int n, llist *p){val=n;next=p;}
};

void printlist(llist *b){
    while(b!= NULL){
        cout<<b->val<<"->";
        b=b->next;
    }
    cout<<"\n";
}
void splitlist(llist *b){
    llist *p,*q,*c;
    p=b;
    q=p->next;
    c=q;
    while(q!=NULL && q->next!=NULL){
        p->next=p->next->next;
        q->next=p->next->next;
        q=q->next;
        p=p->next;
    }
    p->next=0;
    printlist(b);
    printlist(c);
}

llist* reversealternate(llist *b,int k){
    llist *p,*q,*r,*root;
    p=b;
    q=p->next;
    p->next=NULL;
    int cnt=1;
    while(cnt!=k && q!=NULL){
        r=q->next;
        q->next=p;
        p=q;
        q=r;
        cnt++;
    }
    //printlist(p);
    if(r==NULL){b->next=NULL;}
    cnt=0;
    while(cnt!=k && q!=NULL){
        b->next=q;
        q=q->next;
        cnt++;
        b=b->next;
    }
    if(q!=NULL){b->next=reversealternate(q,k);}
    return p;
}

void segregate(llist *head){
    llist *p=new llist(0,0);
    llist *q=new llist(0,0);
    llist *head1,*head2;
    head1=p;head2=q;
    llist *r=head;
    while(r!=NULL){
        if(r->val%2==0){head1->next=r;head1=head1->next;}
        else{head2->next=r;head2=head2->next;}
        r=r->next;
    }
    head1->next=q->next;
    head2->next=NULL;
    printlist(p->next);
}

int main(){
    int n,k,m; cin>>n;cin>>k;
    int i;
    llist * a=new llist(0,0);
    llist *b,*c,*s;
    b=a;
    for(i=1;i<=n;i++){
        c=new llist(i,0);
        a->next=c;
        a=a->next;
    }
    //printlist(b);
    //splitlist(b);
    //s=reversealternate(b,k);
    //printlist(s);
    segregate(b);
}
