#include <iostream>
using namespace std;

class node
{
    int data;
    node *left;
    node *right;
    int lthread;
    int rthread;
    public:
    node()
    {
        data=0;
        left=NULL;
        right=NULL;
        lthread=1;
        rthread=1;
    }
    friend class tbt;
};

class tbt
{
    node *root;
    node *head;
    public:
    tbt()
    {
        root=NULL;
        head=new node;
    }
    node* get_root();
    void insert(int data);
    node* inorder_succ(node *c);
    void inorder(node *c);
    void preorder(node *c);
    node* del(int x);
    node* preorder_succ(node *c);
    node* casea(node *root,node *p,node *c);
    node* caseb(node *root,node *p,node *c);
    node* casec(node *root,node *p,node *c);
};

node* tbt::get_root()
{
    return root;
}

void tbt::insert(int data)
{
    node *new1=new node;
    new1->data=data;
    node *c=root;
    int flag=0;
    if(c==NULL)
    {
        root=new1;
        head->right=root;
        root->right=head;
        root->left=head;
    }
    else
    {
        while(flag==0)
        {
            if(c->data==data)
            {
                return;
            }
            if(c->data>data)
            {
                if(c->lthread==1)
                {
                    new1->left=c->left;
                    new1->right=c;
                    c->left=new1;
                    c->lthread=0;
                    flag=1;
                }
                c=c->left;
            }
            else if(c->data<data)
            {
                if(c->rthread==1)
                {
                    new1->right=c->right;
                    new1->left=c;
                    c->right=new1;
                    c->rthread=0;
                    flag=1;
                }
                c=c->right;
            }
        }
    }
}

node* tbt::inorder_succ(node *c)
{
    if(c->rthread==1)
    {
        return c->right;
    }
    else
    {
        c=c->right;
        while(c->lthread!=1)
        {
            c=c->left;
        }
        return c;
    }
}

node* tbt::preorder_succ(node *c)
{
    if(c->lthread==1)
    {
        return c->left;
    }
    c=c->left;
    while(c->rthread==0)
    {
        c=c->right;
    }
    return c;
}

void tbt::inorder(node *c)
{
    while(c->left!=head)
    {
        c=c->left;
    }
    while(c->right!=head)
    {
        cout<<c->data<<" ";
        c=inorder_succ(c);
    }
    cout<<c->data<<endl;
}

void tbt::preorder(node *c)
{
    while(c->left!=head)
    {
        cout<<c->data<<" ";
        c=c->left;
    }
    cout<<c->data<<" ";
    while(c->right!=head)
    {
        if(c->rthread==1)
        {
            c=c->right;
        }
        else
        {
            c=c->right;
            while(c->lthread!=1)
            {
                cout<<c->data<<" ";
                c=c->left;
            }
            cout<<c->data<<" ";
        }
    }

}

node* tbt::casea(node *root,node *p,node *c)
{
    if(p==NULL)
    {
        root=NULL;
    }
    else if(p->left==c)
    {
        p->left=c->left;
        p->lthread=1;
    }
    else if(p->right==c)
    {
        p->right=c->right;
        p->rthread=1;
    }
    delete(c);
    return root;
}

node* tbt::caseb(node *root,node *p,node *c)
{
    node *child=new node;
    if(c->lthread==0)
    {
        child=c->left;
    }
    else
    {
        child=c->right;
    }
    if(p==NULL)
    {
        root=child;
    }
    else if(p->left=c)
    {
        p->left=child;
    }
    else
    {
        p->right=child;
    }
    node *in=inorder_succ(c);
    node *pre=preorder_succ(c);
    if(c->lthread==0)
    {
        pre->right=in;
    }
    else if(c->rthread==0)
    {
        in->left=pre;
    }
    delete(c);
    return root;
}

node* tbt::casec(node *root,node *p,node *c)
{
    node *q=c;
    node *r=c->right;
    while(c->lthread!=1)
    {
        q=r;
        r=r->left;
    }
    c->data=r->data;
    if(r->lthread==1 && r->rthread==1)
    {
        root=casea(root,q,r);
    }
    else 
    {
        root=caseb(root,q,r);
    }
    return root;
}

node* tbt::del(int x)
{
    node *c=root;
    node *p=root;
    int flag=0;
    while(flag==0)
    {
        if(c->data==x)
        {
            flag=1;
        }
        if(c->data<x)
        {
            p=c;
            c=c->right;
        }
        else if(c->data>x)
        {
            p=c;
            c=c->left;
        }
    }
    if(flag==0)
    {
        cout<<"Key not found"<<endl;
    }
    else if(c->lthread==1 && c->rthread==1)
    {
        root=casea(root,p,c);
    }
    else if(c->lthread==0)
    {
        root=caseb(root,p,c);
    }
    else if(c->rthread==0)
    {
        root=caseb(root,p,c);
    }
    else
    {
        root=casec(root,p,c);
    }
    return root;
 
}

int main()
{
    tbt t;
    int c=1;
    while(c>0)
    {
        cout<<"Menu"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Inorder"<<endl;
        cout<<"3.Preorder"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"Enter your choice:";
        cin>>c;
        if(c==1)
        {
            int key;
            cout<<"Enter element:";
            cin>>key;
            t.insert(key);
        }
        else if(c==2)
        {
            t.inorder(t.get_root());
            cout<<endl;
        }
        else if(c==3)
        {
            t.preorder(t.get_root());
            cout<<endl;
        }
        else if(c==4)
        {
            cout<<"Enter data to delete:";
            int d;
            cin>>d;
            node *new1=t.get_root();
            new1=t.del(d);
        }
    }
    return 0;
}
