#include<iostream>
#include<cstdio>
using namespace std;

class tree{
public:
    int key;
    tree *left;
    tree *right;
    tree *parent;
    //tree *root;
    tree(int d, tree *p,tree *q, tree *r){key=d;left=p;right=q;parent=r;}
    //tree(){root=NULL;}
};
tree *root;

tree * insertfunc(tree * root, int k){
    tree *y=NULL;
    tree *x=root;
    while(x!=NULL){
        y=x;
        if(k<x->key){x=x->left;}
        else{x=x->right;}
    }
    tree *z=new tree(k,0,0,y);
    if(y==NULL){root=z;}
    else if(z->key<y->key){y->left=z;}
    else{y->right=z;}
    return root;
}

void inorder(tree *x){
    if(x!=NULL){
        inorder(x->left);
        cout<<x->key<<" ";
        inorder(x->right);
    }
}

int main(){
    int i,m,k;
    //tree *root=new tree;
    root=NULL;
    while(true){
        cout<<"Press 1 to insert: \n";
        cout<<"Press 2 to find the successor element: \n";
        cout<<"Press 3 to find the predecessor element: \n";
        cout<<"Press 4 to print inorder traversal: \n";
        cout<<"Press 5 to print pre order traversl: \n";
        cout<<"Press 6 to print post order traversal: \n";
        cout<<"Press 7 to search a value: "
        cin>>m;
        switch(m){
            case 1:
                cin>>k;
                root=insertfunc(root,k);
                break;
            case 4:
                inorder(root);
                cout<<"\n";
                break;

        }
    }
}
