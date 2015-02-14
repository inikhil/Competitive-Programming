#include<iostream>
#include<cstdlib>
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
};

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

int main(){
    int i,m,k;
    tree temp;
    node *x;
    while(true){
        cout<<"Press 1 to insert: \n";
        cout<<"Press 2 to find the successor element: \n";
        cout<<"Press 3 to find the predecessor element: \n";
        cout<<"Press 4 to print inorder traversal: \n";
        cout<<"Press 5 to print pre order traversl: \n";
        cout<<"Press 6 to print post order traversal: \n";
        cout<<"Press 7 to search a value: \n";
        cout<<"Press 8 to delete: \n";
        cout<<"Press 9 to exit: \n";
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
                exit(0);
        }
    }
}

