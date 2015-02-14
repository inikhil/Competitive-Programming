#include<iostream>
#include<cstdio>
using namespace std;

class node{
public:
    int val;
    node *next;
    node(int d,node *p){val=d;next=p;}
};

class bst{
public:
    int data;
    bst *left;
    bst *right;
    bst(int d,bst *p,bst *q){data=d;left=p;right=q;}
};
void printlist(node *b){
     while(b!= NULL){
        cout<<b->val<<"->";
        b=b->next;
    }
    cout<<"\n";

}

node * inputlist(){
    int i,n,k;
    cout<<"Length of the linked list: \n";
    cin>>n;
    if(n>=1){
        cout<<"Enter your numbers: \n";
        cin>>k;
        node *root=new node(k,0);
        node *p=root,*q;
        for(i=1;i<n;i++){
            cin>>k;
            node *q=new node(k,0);
            p->next=q;
            p=p->next;
        }
        return root;
    }
}

void printbst(bst *r){
    cout<<r->data<<" ";
    if(r->left!=NULL)
        printbst(r->left);
    if(r->right!=NULL)
        printbst(r->right);

}

bst* convertbst(node *head){
    node *p,*q,*r;
    p=head;q=head;
    if(p==NULL){return NULL;}
    else if(p->next==NULL){
        bst *result=new bst(0,0,0);
        result->data=q->val;
        return result;
    }
    while(p!=NULL && p->next!=NULL){
        p=p->next->next;
        r=q;
        q=q->next;
    }
    bst *result=new bst(0,0,0);
    result->data=q->val;
    //cout<<result->data<<endl;
    r->next=NULL;
    //printlist(head);
    //printlist(q->next);
    result->left=convertbst(head);
    result->right=convertbst(q->next);
    return result;
}

int main(){
    node *p,*q;
    bst *r;
    int k;
    p=inputlist();
    printlist(p);
    r=convertbst(p);
    printbst(r);
}

