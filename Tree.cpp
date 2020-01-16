#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node *right;
    node *left;

    node(int d){
        data=d;
        right=NULL;
        left =NULL;
    }
};

node *buildtree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node *root =new node(d);
    root->left =buildtree();
    root->right=buildtree();
    return root;
}



// Printing trees using different ways
// 1. Inorder
// 2. Postorder
// 3. Inorder
// 4. Printing the Kth level
void println(node*root){
    if(root==NULL){
        return;
    }
    //Otherwise left root right
    println(root->left);
    cout<<root->data<<" ";
    println(root->right);
}

void printpost(node*root){
    if(root==NULL){
        return;
    }
    // print Left right root
    printpost(root->left);
    printpost(root->right);
    cout<<root->data<<" ";

}

void print(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void printKthlevel(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthlevel(root->left,k-1);
    printKthlevel(root->right,k-1);

}



// Height of a tree

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}


void bfs(node*root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *f=q.front();
        cout<<f->data<<" ";
        q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
}

// Second method
void bfs2(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *f=q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
            else{
        cout<<f->data<<" ";
        q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }

    }
    return;
}

int count(node*root){
    if(root==NULL){
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}

int main(){

    node* root=buildtree();
    print(root);
    cout<<endl;
    println(root);
    cout<<endl;
    printpost(root);

    cout<<endl;
    cout<<height(root);
    cout<<endl;

    // printing all levels
    for(int i=1;i<=height(root);++i){
        printKthlevel(root,i);
        cout<<endl;
    }
    bfs2(root);

    cout<<endl<<count(root)<<endl;
    return 0;

}


// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
