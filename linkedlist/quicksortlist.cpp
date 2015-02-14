#include<iostream>
#include<cstdio>
using namespace std;

class link{
public:
    int val;
    link *next;
    link(int d, link *p){val=d;next=p;}
};

class diff{
public:
    link *u;
    link *v;
};

link* insertlist(link *p,int n){
    int i,k;
    link *q,*r;
    q=p;
    for(i=1;i<n;i++){
        cin>>k;
        r=new link(k,0);
        q->next=r;
        q=q->next;
    }
    return p;
}

void printlist(link *b){
    while(b!= NULL){
        cout<<b->val<<"->";
        b=b->next;
    }
    cout<<"\n";
}

link *findlastlink(link *p){
    if(p==NULL){return p;}
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}

link* part(link *a,link *b){
    link *p=a;
    link *q=a;
    link *r=p;
    if(a==b){return NULL;}
    //diff *ob;
    while(q!=b){
        if(q->val<=b->val){
            swap(p->val,q->val);
            r=p;
            //cout<<r->val<<" ";
            q=q->next;p=p->next;
        }
        else{
            q=q->next;
        }
    }
    swap(p->val,b->val);
    //printlist(a);
    //ob->u=r;ob->v=p->next;
    return r;
    //return ob;
}

void quicksort(link **head, link **tail){
    link *a,*b;
    a=*head;b=*tail;
    //printlist(a);
    if(a!=NULL && a!=b){
        link *r=part(a,b);//cout<<r->val<<endl;
        quicksort(&a,&r);
        quicksort(&r->next,&b);
        //printlist(r);
        //\\if(a==r)
          //  quicksort(&r->next,&b);
    }
}



int main(){
    int n,k;
    cout<<"Print the length of the linked list: \n";
    cin>>n;
    if(n!=0){
        cout<<"Print the elements: \n";
        cin>>k;
        link *p=new link(k,0);
        p=insertlist(p,n);
        link *q=findlastlink(p);
        quicksort(&p,&q);
        printlist(p);
    }
}
