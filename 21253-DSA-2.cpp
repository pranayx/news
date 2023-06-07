#include <iostream>
using namespace std;
template <class t>
class stack{
    int top;
    t arr[20];
    public:
    stack(){
        top = -1;
    }
    void push(t x);
    t pop();
    bool is_empty();
};
template <class t>
void stack<t> :: push(t x){
    if(top>19){
        cout<<"Stack overflow"<<endl;
    }
    else{
        top++;
        arr[top] = x;
    }
}

template <class t>
t stack<t> :: pop(){
    t x;
    if(top == -1){
        cout<<"Stack underflow"<<endl;
    }
    else{
        x = arr[top];
        top--;
    }
    return x;
}

template <class t>
bool stack<t> :: is_empty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

class node{
    int data;
    node* left;
    node* right;
    public:
    node(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    friend class tree;
};

class tree{
    
    public:
    node* root;
    tree(){
        root = NULL;
    }
    void insert(int data);
    void inorder(node* c);
    node* get_root();
    void preorder(node* c);
    void postorder(node* c);
};

node* tree :: get_root(){
    return root;
}

void tree :: insert(int data){
    node* new1 = new node;
    new1->data = data;
    if(root == NULL){
        root = new1;
    }
    else{
        node* c = root;
        while(c != NULL){
            cout<<"Where do want to insert data(l/r):";
            char x;
            cin>>x;
            if(x == 'l'){
                if(c->left == NULL){
                    c->left = new1;
                    break;
                }
                else{
                    c = c->left;
                }
            }
            else if(x == 'r'){
                if(c->right == NULL){
                    c->right = new1;
                    break;
                }
                else{
                    c = c->right;
                }
            }
        }
    }
        
}

void tree :: inorder(node* c){
    stack<node*> s;
    while(c != NULL){
        s.push(c);
        c = c->left;
    }
    while(s.is_empty() == false){
        c = s.pop();
        cout<<c->data<<" ";
        c = c->right;
        while(c != NULL){
            s.push(c);
            c = c->left;
        }
    }
}

void tree :: preorder(node* c){
    stack<node*> s;
    s.push(c);
    while(s.is_empty() == false){
        c = s.pop();
        cout<<c->data<<" ";
        if(c->right != NULL){
            s.push(c->right);
        }
        if(c->left != NULL){
            s.push(c->left);
        }
    }
}

void tree :: postorder(node* c){
    stack<node*> s1;
    stack<node*> s2;
    s1.push(c);
    while(s1.is_empty() == false){
        c = s1.pop();
        s2.push(c);
        if(c->left != NULL){
            s1.push(c->left);
        }
        if(c->right != NULL){
            s1.push(c->right);
        }
    }
    while(s2.is_empty() == false){  
       c = s2.pop();
       cout<<c->data<<" "; 
    }
}
int main(){
    tree t;
    while(true){
        cout<<"*************MENU***************"<<endl;
        cout<<"1) Insert an element"<<endl;
        cout<<"2) Inorder display"<<endl;
        cout<<"3) Preorder display"<<endl;
        cout<<"4) Postorder traversal"<<endl;
        cout<<"Enter your choice:";
        int choice;
        cin>>choice;
        if(choice == 1){
            int x;
            cout<<"Enter data:";
            cin>>x;
            t.insert(x);
        }
        else if(choice == 2){
            t.inorder(t.root);
            cout<<endl;
        }
        else if(choice == 3){
            t.preorder(t.get_root());
            cout<<endl;
        }
        else if(choice == 4){
            t.postorder(t.get_root());
            cout<<endl;
        }
    }
    return 0;
}