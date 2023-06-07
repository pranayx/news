#include<iostream>
using namespace std;
template<typename t>
class Stack
{
    t arr[50];
    int MAX=50;
    int top;
    public:
    Stack()
    {
        top=-1;
    }
    void push(t data)
    {
        if(top==MAX-1)
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=data;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else
        {
            top--;
        }
    }
    t gettop()
    {
        return arr[top];
    }
    bool empty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class node
{
    int data;
    node *left;
    node *right;
    public:
    node()
    {
        left=NULL;
        right=NULL;
    }
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    friend class Binary_tree;
    friend int main();
};
class Binary_tree
{
    node *root;
    int count;
    public:
    Binary_tree()
    {
        root=NULL;
        count=0;
    }

    node *getNewNode(int data)
    {
        node *new_node_ptr = new node(data);
        new_node_ptr->data = data;
        new_node_ptr->left = new_node_ptr->right = NULL;
        return new_node_ptr;
    }

    void insertIterative(int data)
    {
        count++;
        node *nnptr = new node(data);
        if(root==NULL)
        {
            root=nnptr;
            return;
        }

        bool flag = true;
        node *nptr = root;
        while(flag==true)
        {
            char side;
            cout<<"On which side of "<<nptr->data<<" you want to insert "<<data<<endl;
            cin>>side;

            if(side=='l')
            {
                if(nptr->left==NULL)
                {
                    nptr->left=nnptr;
                    flag = false;
                }
                else
                {
                    nptr=nptr->left;
                }
            }
            if(side=='r')
            {
                if(nptr->right==NULL)
                {
                    nptr->right=nnptr;
                    flag=false;
                }
                else
                {
                    nptr=nptr->right;
                }
            }
        }
    }

    void insert(node *&root,int data)
    {
        node *nnptr = new node(data);
        if(root==NULL)
        {
            root=nnptr;
            return;
        }
        else
        {
            char side;
            cout<<"Enter the side on which the element is to be inserted:(0/1)"<<endl;
            cin>>side;

            if(side=='0')
            {
                insert(root->left,data);
            }
            else if(side=='1')
            {
                insert(root->right,data);
            }
        }
    }

    void inorderIterative()
    {
        node *nptr = root;
        Stack<node *>s;
        bool flag=true;
        while(flag==true)
        {
            while(nptr!=NULL)
            {
                s.push(nptr);
                nptr=nptr->left;
            }
            cout<<s.gettop()->data<<" ";
            nptr=s.gettop()->right;
            s.pop();

            if((nptr==NULL)&&(s.empty()==true))
            {
                flag=false;
            }
        }
    }

    void inorder(node *root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorderIterative()
    {
        node *nptr = root;
        Stack<node *>s;
        bool flag=true;
        while(flag==true)
        {
            while(nptr!=NULL)
            {
                cout<<nptr->data<<" ";
                s.push(nptr);
                nptr=nptr->left;
            }
            nptr = s.gettop()->right;
            s.pop();

            if((nptr==NULL)&&(s.empty()==true))
            {
                flag=false;
            }
        }
    }

    void preorder(node *root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorderIterative()
    {
        node *nptr = root;
        Stack<node *>s1;
        Stack<node *>s2;

        s1.push(nptr);

        while(s1.empty()!=true)
        {
            node *temp = s1.gettop();
            s1.pop();
            s2.push(temp);

            if(temp->left!=NULL)
            {
                s1.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                s1.push(temp->right);
            }
        }

        while(s2.empty()!=true)
        {
            cout<<s2.gettop()->data<<" ";
            s2.pop();
        }
    }

    void postorder(node *root)
    {
        if(root==NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    int height(node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            int lchild = height(root->left);
            int rchild = height(root->right);
            if(lchild>rchild)
            {
                return (lchild+1);
            }
            else
            {
                return (rchild+1);
            }
        }
    }

    node *Clone_binary_tree(node *root,int data)
    {
        if(root==NULL)
        {
            return NULL;
        }
        node *newnode = getNewNode(data);
        if(root->left)
        {
            newnode->left = Clone_binary_tree(root->left,root->left->data);
        }
        if(root->right)
        {
            newnode->right = Clone_binary_tree(root->right,root->right->data);
        }
        return newnode;
    }

    void mirror(node *root)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            node *temp;
            mirror(root->left);
            mirror(root->right);

            temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
    }

    void Delete_binary_tree(node *root)
    {
        if(root==nullptr)
        {
            return;
        }

        Delete_binary_tree(root->left);
        Delete_binary_tree(root->right);
        cout<<"Deleted node "<<root->data<<endl;
        delete root;
        root=nullptr;
    }

    int internal_node(node *root)
    {
        if((root==NULL)||(root->left==NULL && root->right==NULL))
        {
            return 0;
        }
        else
        {
            int Left = internal_node(root->left);
            int Right = internal_node(root->right);
            return Left+Right+1;
        }
    }

    int leafcount()
    {
        int internal_nodes = internal_node(root);
        int leafcount = count - internal_nodes;
        return leafcount;
    }
    friend int main();
};
int main()
{
    Binary_tree b;
    char ans='y';
    while(ans=='y')
    {
        int choice;
        cout<<"########MENU########"<<endl;
        cout<<"1.Insert a node"<<endl;
        cout<<"2.Perform inorder,preorder and postorder traversal of the tree"<<endl;
        cout<<"3.Swapping of binary tree"<<endl;
        cout<<"4.Height of tree"<<endl;
        cout<<"5.Copy this tree to another"<<endl;
        cout<<"6.Number of leaves and internal nodes"<<endl;
        cout<<"7.Erase all nodes in Binary tree"<<endl;
        cout<<"Enter the choice of operation that you want to perform";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int d;
                cout<<"Enter the element:";
                cin>>d;
                b.insertIterative(d);
                break;
            }
            case 2:
            {
                cout<<"Inorder traversal:";
                b.inorderIterative();
                cout<<endl;
                cout<<"Preorder traversal:";
                b.preorderIterative();
                cout<<endl;
                cout<<"Postorder traversal:"<<endl;
                b.postorderIterative();
                break;
            }
            case 3:
            {
                node *newroot = b.Clone_binary_tree(b.root,b.root->data);
                cout<<"The mirror of Binary tree is: "<<endl;
                b.mirror(newroot);
                b.inorder(newroot);
                break;
            }
            case 4:
            {
               cout<<"The Height of the tree: "<<endl;
               cout<<b.height(b.root)<<endl;
               break;
            }
            case 5:
            {
                node *newroot = b.Clone_binary_tree(b.root,b.root->data);
                cout<<"The copy of the Binary tree is: "<<endl;
                b.inorder(newroot);
                break;
            }
            case 6:
            {
                cout<<"The no. of leaf nodes in tree are: "<<b.leafcount()<<endl;
                cout<<"The no. of non-leaf nodes in tree are: "<<b.internal_node(b.root)<<endl;
                break;
            }
            case 7:
            {
                cout<<"Erasing all nodes of Binary tree: "<<endl;
                b.Delete_binary_tree(b.root);
                break;
            }
            default:
            {
                cout<<"Invalid choice"<<endl;
                break;
            }
        }
        cout<<endl;
        cout<<"Do you want to continue?(y/n)"<<endl;
        cin>>ans;
    }
    return 0;
}