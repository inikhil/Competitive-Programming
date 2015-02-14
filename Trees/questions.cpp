#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;
class node{
public:
    int key;
    node *left;
    node *right;
    node *parent;
    node(int d, node *p,node *q, node *r){key=d;left=p;right=q;parent=r;}
};

class tree{
public:
    node *root;
    tree(){root=NULL;}
    void insertfunc(int k);
    void inorder(node *x);
    void preorder(node *x);
    void postorder(node *x);
    node *searchfunc(int k);
    int successor(int k);
    int tree_minimum(node *x);
    void deletefunc(int k);
    void transplant(node *x, node *y);
    int sizecalc(node *x);
    void deletecomplete(node *x);
    void mirror(node *x);
    void paths();
    void printallpaths(node *x,int *path,int maxlen);
    void level();
    void levelqueue();
    void spirallevel();
    void inorderrec();
    void optimisedinorder();
    node * bstconstruct(int *a, int *st, int *en, int *ind, int n);
    void construct();
    void preorderstack();
    void postordtwostacks();
    void postordonestack();
    void startconvert();
    void converttodll(node *p,node *&head, node *&tail);
    void flip();
    void diff(int &sum1,int &sum2,int level, node *p);
};

class stackdata{
public:
    int top;
    stackdata(){top=0;}
    void insertion(node **a,node *b);
    node* destack(node **a);
    bool isempty();
};

bool stackdata::isempty(){
    if(top>0){return false;}
    else{return true;}
}

void stackdata::insertion(node **a,node *b){
    a[top]=b;
    top++;
}

node* stackdata::destack(node **a){
    if(top==0){return NULL;}
    top--;
    return a[top];
}

int tree::sizecalc(node *x){
    int m=0;
    if(x!=NULL){
        m=1+sizecalc(x->left)+sizecalc(x->right);
    }
    return m;
}

void tree::insertfunc(int k){
    node *y=NULL;
    node *x=root;
    while(x!=NULL){
        y=x;
        if(k<x->key){x=x->left;}
        else{x=x->right;}
    }
    node *z=new node(k,0,0,y);
    if(y==NULL){root=z;}
    else if(z->key<y->key){y->left=z;}
    else{y->right=z;}
}

void tree::postorder(node *x){
    if(x!=NULL){
        postorder(x->left);
        postorder(x->right);
        cout<<x->key<<" ";
    }
}

void tree::preorder(node *x){
    if(x!=NULL){
        cout<<x->key<<" ";
        preorder(x->left);
        preorder(x->right);
    }
}

void tree::inorder(node *x){
    if(x!=NULL){
        inorder(x->left);
        cout<<x->key<<" ";
        inorder(x->right);
    }
}

node* tree::searchfunc(int k){
    node *x=root;
    while(x!=NULL && k!=x->key){
        if(k<x->key){x=x->left;}
        else{x=x->right;}
    }
    return x;
}

int tree::tree_minimum(node *x){
    while(x->left!=NULL)
        x=x->left;
    return x->key;
}

int tree::successor(int k){
    node *x=searchfunc(k);
    if(x==NULL){return -1;}
    if(x==root && x->right==NULL){return -1;}
    if(x->right!=NULL){return tree_minimum(x->right);}
    node *y=x->parent;
    while(y!=NULL && x==y->right){
        x=y;
        y=y->parent;
        if(x==root){return -1;}
    }
    return y->key;
}
void tree::transplant(node *u, node *v){
    if(u->parent==NULL){root=v;}
    else if(u==u->parent->left){u->parent->left=v;}
    else{u->parent->right=v;}
    if(v!=NULL){v->parent=u->parent;}
}
void tree::deletefunc(int k){
    int m;
    node *x=searchfunc(k);
    if(x->left==NULL){transplant(x,x->right);}
    else if(x->right==NULL){transplant(x,x->left);}
    else{
        m=successor(k);
        node *y=searchfunc(m);
        if(y->parent!=x){
            transplant(y,y->right);
            y->right=x->right;
            y->right->parent=y;
        }
        transplant(x,y);
        y->left=x->left;
        y->left->parent=y;
    }
}

bool compare(node *x, node *y){
    if(x==NULL && y==NULL){return true;}
    else if(x==NULL||y==NULL){return false;}
    else if(x->key==y->key){
        return (compare(x->left,y->left) && compare(x->right,y->right));
    }
    return false;
}

void tree::deletecomplete(node *x){
    if (x==NULL){return;}
    if(x->left!=NULL){deletecomplete(x->left);}
    if(x->right!=NULL){deletecomplete(x->right);}
    delete(x);
}

void tree::mirror(node *x){
    if(x==NULL){return;}
    mirror(x->left);
    mirror(x->right);
    node *y=x->left;
    x->left=x->right;
    x->right=y;
}

void tree::printallpaths(node *x, int *path, int maxlen){
    if(x==NULL){return;}
    path[maxlen]=x->key;
    maxlen++;
    if(x->left==NULL && x->right==NULL){
        int i;
        for(i=0;i<maxlen;i++){cout<<path[i]<<" ";}
        cout<<"\n";
    }
    else{
        printallpaths(x->left,path,maxlen);
        printallpaths(x->right,path,maxlen);
    }
}

void tree::paths(){
    int maxlen=0;
    int *path=new int[1000];
    printallpaths(root,path,maxlen);
}

void tree::level(){
    int m=sizecalc(root);
    node **p=new node*[m];
    int start=0,en=0;
    p[0]=root;
    while(start!=m){
        cout<<p[start]->key<<" ";
        if(p[start]->left!=NULL){
            p[en+1]=p[start]->left;
            en=en+1;
        }
        if(p[start]->right!=NULL){
            p[en+1]=p[start]->right;
            en=en+1;
        }
        start=start+1;
    }
    cout<<"\n";
}

void tree::levelqueue(){
    node *p=root;
    queue<node *> s1;
    while(p!=NULL){
        if(p->left)
            s1.push(p->left);
        if(p->right)
            s1.push(p->right);
        cout<<p->key<<" ";
        p=s1.front();
        s1.pop();
    }
    cout<<"\n";
}

void tree::spirallevel(){
    int m=sizecalc(root);
    stackdata a,b;
    node **p =new node*[m];
    node **q =new node*[m];
    a.insertion(p,root);
    node *r=a.destack(p);
    while(r!=NULL){
        while(r!=NULL){
            cout<<r->key<<" ";
            if(r->right!=NULL){b.insertion(q,r->right);}
            if(r->left!=NULL){b.insertion(q,r->left);}
            r=a.destack(p);
        }
        node *s=b.destack(q);
        while(s!=NULL){
            cout<<s->key<<" ";
            if(s->left!=NULL){a.insertion(p,s->left);}
            if(s->right!=NULL){a.insertion(p,s->right);}
            s=b.destack(q);
        }
        r=a.destack(p);
    }
    cout<<"\n";
}

void tree::inorderrec(){
    stackdata a;
    int m=sizecalc(root);
    node **p=new node*[m];
    node *q=root,*r;
    if(root==NULL){return;}
    a.insertion(p,root);
    q=q->left;
    int done=0;
    while(done!=1){
        if(q!=NULL){a.insertion(p,q);q=q->left;}
        else{
            if(a.isempty()==false){
                q=a.destack(p);
                cout<<q->key<<" ";
                q=q->right;
            }
            else{done=1;}
        }
    }
    cout<<"\n";
}

void tree::optimisedinorder(){
    node *cur=root,*pre;
    while(cur!=NULL){
        if(cur->left==NULL){
            cout<<cur->key<<" ";
            cur=cur->right;
        }
        else{
            pre=cur->left;
            while(pre->right!=NULL && pre->right!=cur){pre=pre->right;}
            if(pre->right==NULL){pre->right=cur;cur=cur->left;}
            else{
                pre->right=NULL;
                cout<<cur->key<<" ";
                cur=cur->right;
            }
        }
    }
    cout<<"\n";
}

node* tree::bstconstruct(int *a, int *st, int *en, int *ind, int n){
    int i,j,k;//cout<<"xyz";
    //if( *ind >n){return NULL;}
    if(*st > *en){return NULL;}
    node *p= new node(a[*st],0,0,0);
    //cout<<p->key<<" ";
    if(*st == *en){return p;}
    for(i=*st+1;i<=n;i++){
        if(a[i]>a[*st]){break;}
    }
    j=(*st)+1;k=i-1;
    p->left=bstconstruct(a,&j,&k,ind,n);
    p->right=bstconstruct(a,&i,en,ind,n);
    return p;
}

void tree::construct(){
    int n,i;
    cout<<"Length of your input array: ";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter you array :\n";
    for(i=0;i<n;i++){cin>>a[i];}
    int st=0,en=n-1,ind=0;
    root=bstconstruct(a,&st,&en,&ind,n-1);
    //inorder(root);
}

void tree::preorderstack(){
    if(root==NULL){return;}
    stack<node* > s1;
    s1.push(root);
    while(!s1.empty()){
        node *p=s1.top();
        cout<<p->key<<" ";
        s1.pop();
        if(p->right!=NULL){s1.push(p->right);}
        if(p->left!=NULL){s1.push(p->left);}
    }
}

void tree::postordtwostacks(){
    if(root==NULL){return;}
    stack<node* > s1,s2;
    s1.push(root);
    node *p;
    while(!s1.empty()){
        p=s1.top();
        s2.push(p);
        s1.pop();
        if(p->left!=NULL){s1.push(p->left);}
        if(p->right!=NULL){s1.push(p->right);}
    }
    while(!s2.empty()){
        p=s2.top();
        cout<<p->key<<" ";
        s2.pop();
    }
    cout<<"\n";
}

void tree::diff(int &sum1,int &sum2,int level, node *p){
    if(p==NULL){return;}
    if(level%2==0){sum2+=p->key;}
    else{sum1+=p->key;}
    if(p->left){diff(sum1,sum2,level+1,p->left);}
    if(p->right){diff(sum1,sum2,level+1,p->right);}
    return;
}

void tree::postordonestack(){
    if(root==NULL){return;}
    stack<node *> s1;
    if(root->right!=NULL){s1.push(root->right);}
    s1.push(root);
    node *curr=root->left,*p,*q;
    while(!s1.empty()){
        while(curr!=NULL){
            if(curr->right)
                s1.push(curr->right);
            s1.push(curr);
            curr=curr->left;
        }
        p=s1.top();s1.pop();
        if(!s1.empty() && p->right==s1.top()){
            q=s1.top();
            s1.pop();
            s1.push(p);
            curr=q;
        }
        else{
            cout<<p->key<<" ";
            curr=NULL;
        }
    }
    cout<<"\n";
}

void tree::converttodll(node *p, node * &head, node * &tail){
    if(p==NULL){return;}
    if(p->left){converttodll(p->left,head,tail);}
    p->left= tail;
    if(tail==NULL)
        head=p;
    else
        (tail)->right=p;
    tail=p;
    if(p->right){converttodll(p->right,head,tail);}
}

void tree::startconvert(){
    if(root==NULL){return;}
    node *head=NULL;
    node *tail=NULL;
    converttodll(root,head,tail);
    node *p=head;
    while(p!=NULL){cout<<p->key<<" ";p=p->right;}
    p=tail;
    cout<<"\n";
    while(p!=NULL){cout<<p->key<<" ";p=p->left;}
    cout<<"\n";
}

int fin(int *in,int a, int b, int value){
    int i;
    for(i=a;i<=b;i++){
        if(in[i]==value){return i;}
    }
}

node *build(int *in,int *pre, int a, int b){
    static int index=0;
    if(a>b){return NULL;}
    node *p=new node(pre[index],0,0,0);
    index ++;
    if(a==b){return p;}
    int m = fin(in,a,b,pre[index-1]);
    p->left=build(in,pre,a,m-1);
    p->right=build(in,pre,m+1,b);
    return p;
}

void tree::flip(){
    node *p,*q,*r,*s,*t;
    p=root;
    if(root==NULL){return;}
    q=p->right;
    r=p->left;p->right=NULL;
    while(r!=NULL){
        s=r->left;
        t=r->right;
        r->left=q;
        r->right=p;
        p=r;q=t;r=s;
    }
    root=p;
    optimisedinorder();
}

int main(){
    int i,m,k;
    tree temp,temp1;
    int sum1=0,sum2=0,level=0;
    node *x;
    while(true){
        cout<<"Press 1 to insert in tree1 : \n";
        cout<<"Press 2 to find the successor element: \n";
        cout<<"Press 3 to find the predecessor element: \n";
        cout<<"Press 4 to print inorder traversal: \n";
        cout<<"Press 5 to print pre order traversl: \n";
        cout<<"Press 6 to print post order traversal: \n";
        cout<<"Press 7 to search a value: \n";
        cout<<"Press 8 to delete: \n";
        cout<<"Press 9 to calculate size: \n";
        cout<<"Press 10 to insert in tree2: \n";
        cout<<"Press 11 to determine whether two trees are identical or not: \n";
        cout<<"Press 12 to delete the complete tree: \n";
        cout<<"Press 13 to print the mirror image: \n";
        cout<<"Press 14 to print all paths from root to leaf: \n";
        cout<<"Press 15 for level order traversal: \n";
        cout<<"Press 16 for spiral level order traversal: \n";
        cout<<"Press 17 for printing inorder traversal without recursion: \n";
        cout<<"Press 18 for inorder withot stack and recursion or Morris Traversal: \n";
        cout<<"Press 19 to create a tree from inorder and preorder: \n";
        cout<<"Press 20 to create a binary serach tree from the preorder traversal: \n";
        cout<<"Press 21 for preorder traversal using stack:\n";
        cout<<"Press 22 for postorder traversal using two stacks: \n";
        cout<<"Press 23 for postorder traversal using one stack: \n";
        cout<<"Press 24 to convert to dll: \n";
        cout<<"Press 25 to print level order using queue: \n";
        cout<<"Print 26 to flip the tree: \n";
        cout<<"Press 27 to print difference between odd and even levels: \n";
        cin>>m;
        switch(m){
            case 1:
                cin>>k;
                temp.insertfunc(k);
                break;
            case 2:
                cin>>k;
                cout<<temp.successor(k)<<endl;
                break;
            case 4:
                temp.inorder(temp.root);
                cout<<"\n";
                break;
            case 5:
                temp.preorder(temp.root);
                cout<<"\n";
                break;
            case 6:
                temp.postorder(temp.root);
                cout<<"\n";
                break;
            case 7:
                cin>>k;
                x = temp.searchfunc(k);
                if(x==NULL){cout<<"Value not found"<<endl;}
                else{cout<<"Value Found"<<endl;}
                break;
            case 8:
                cin>>k;
                temp.deletefunc(k);
                break;
            case 9:
                cout<<temp.sizecalc(temp.root)<<endl;
                break;
            case 10:
                cin>>k;
                temp1.insertfunc(k);
                break;
            case 11:
                if(compare(temp.root,temp1.root)==true){cout<<"True"<<endl;}
                else{cout<<"False"<<endl;}
                break;
            case 12:
                temp.deletecomplete(temp.root);
                temp.root=NULL;
                break;
            case 13:
                temp.mirror(temp.root);
                break;
            case 14:
                temp.paths();
                break;
            case 15:
                temp.level();
                break;
            case 16:
                temp.spirallevel();
                break;
            case 17:
                temp.inorderrec();
                break;
            case 18:
                temp.optimisedinorder();
                break;
            case 19:
                cout<<"Press the length of inorder string: \n";
                cin>>k;
                /*int *in=new int[k];
                int *pre=new int[k];
                for(i=0;i<k;i++){cin>>in[i];}
                for(i=0;i<k;i++){cin>>pre[i];}
                temp.root=build(in,pre,0,k-1);
                temp.inorder(temp.root);
                cout<<"\n";*/
                break;
            case 20:
                temp.construct();
                break;
            case 21:
                temp.preorderstack();
                break;
            case 22:
                temp.postordtwostacks();
                break;
            case 23:
                temp.postordonestack();
                break;
            case 24:
                //temp.converttodll();
                temp.startconvert();
                break;
            case 25:
                temp.levelqueue();
                break;
            case 26:
                temp.flip();
                break;
            case 27:
                sum1=0;sum2=0;level=0;
                temp.diff(sum1,sum2,level,temp.root);
                cout<<sum1<<" "<<sum2<<endl;
        }
    }
}


