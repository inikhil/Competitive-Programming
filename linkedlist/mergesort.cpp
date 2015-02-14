#include<iostream>
#include<cstdio>
using namespace std;

class link{
public:
    int val;
    link *next;
    link(int d, link *p){val=d;next=p;}
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

void frontbacksplit(link *p, link **frnt,link **bck){
    link* fast;
    link* slow;
  if (p==NULL || p->next==NULL)
  {
    /* length < 2 cases */
    *frnt = p;
    *bck = NULL;
  }
  else
  {
    slow = p;
    fast = p->next;
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
    *frnt = p;
    *bck = slow->next;
    slow->next = NULL;
  }
}

link* sortedmerge(link * a, link * b){
  link* result = NULL;
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
  if (a->val <= b->val)
  {
     result = a;
     result->next = sortedmerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = sortedmerge(a, b->next);
  }
  return(result);
}


void mergesort(link **r){
    link *q = *r;
    if(q==NULL||q->next==NULL){return;}
    link *a,*b;
    frontbacksplit(q,&a,&b);
    mergesort(&a);
    mergesort(&b);
   *r=sortedmerge(a,b);
    //printlist(r);
}

link* deletelist(link *p,int a,int b){
    int cnt=1;
    link *q;
    link *root=p;
    //printlist(p);
    while(p->next!=NULL){
        cnt=1;
        while(cnt<a && p->next!=NULL){
            p=p->next;
            cnt++;
        }
        q=p->next;cnt=1;
        p->next=NULL;
        while(cnt<b && q!=NULL){
            q=q->next;
            cnt++;
        }
        if(q!=NULL){p->next=q->next;p=p->next;}
        //printlist(root);
    }
    return root;
}

int main(){
    int n,k;
    cout<<"Print the length of the linked list: \n";
    cin>>n;
    //int a,b;
    //cout<<"Print a and b: \n";
    //cin>>a>>b;
    if(n!=0){
        cout<<"Print the elements: \n";
        cin>>k;
        link *p=new link(k,0);
        p=insertlist(p,n);
        //p=deletelist(p,a,b);
       // p=reversealternate(p);
        printlist(p);
        //mergesort(&p);
        //printlist(p);

    }
}
