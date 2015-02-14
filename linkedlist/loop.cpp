#include<iostream>
#include<cstdio>
using namespace std;

class node{
public:
    int val;
    node *next;
    node(int d,node *p){val=d;next=p;}
};
void printlist(node *b){
     while(b!= NULL){
        cout<<b->val<<"->";
        b=b->next;
    }
    cout<<"\n";

}

node * makeloop(){
    int i,n,k;
    cout<<"Length of the linked list: \n";
    cin>>n;
    if(n>=1){
        cout<<"Enter your numbers: \n";
        cin>>k;
        node *root=new node(k,0);
        node *p=root,*q,*r;
        for(i=1;i<n;i++){
            cin>>k;
            node *q=new node(k,0);
            p->next=q;
            p=p->next;
            if(i==n/2){r=p;}
        }
        p->next=r;
        return root;
    }
}
node *checkcycle(node *p){
    //cout<<p->val<<" ";
    node *hare=p;
    node *tor=p;
    int m=0;
    while(m!=1){
        if(tor->next==NULL){cout<<"No loop Found \n";m=1;}
        else{
            tor=tor->next;
            hare=hare->next->next;
            //cout<<tor->val<<" "<<hare->val<<" ";
            if(tor==hare){cout<<"Loop found\n"; m=1;}
        }
    }
    return hare;
}
int length(node *p){
    node *r=p->next;
    int cnt=1;
    while(r!=p){
        r=r->next;
        cnt++;
    }
    return cnt;
}

void removeloop(node *root,int k){
    node *q=root;
    node *p=root;
    int cnt=0;
    while(cnt!=k){
        q=q->next;
        cnt++;
    }
    while(q->next!=p->next){
        q=q->next;
        p=p->next;
    }
    cout<<"Point of loop: "<<q->next->val<<endl;
    q->next=NULL;
    printlist(root);
}

int main(){
    node *p,*q;
    int k;
    p=makeloop();
    q=checkcycle(p);
    //cout<<q->val<<" ";
    if(q->next!=NULL){
        k=length(q);
        removeloop(p,k);
    }
}
