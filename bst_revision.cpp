#include<iostream>
using namespace std;

class BST
{
    private:
        struct node
        {
            int data;
            node *lc;
            node *rc;
        }*root;
    public:
        BST()
        {
            root=NULL;
        }
        void create()
        {
            int choice;
            node *temp, *t;
            do
            {
                temp=new node;
                temp->lc=temp->rc=NULL;
                cout<<"enter the data"<<endl;
                cin>>temp->data;
                if(root==NULL)
                {
                    root=temp;
                }
                else
                {
                    t=root;
                    while(t!=NULL)
                    {
                        if(temp->data < t->data && t->lc!=NULL)
                        {
                            t=t->lc;
                        }
                        else if(temp->data > t->data && t->rc!=NULL)
                        {
                            t=t->rc;
                        }
                       else
                       {
                           break;
                       }
                    }
                    if(temp->data < t->data)
                    {
                        t->lc=temp;
                    }
                    else
                    {
                        t->rc=temp;
                    }
                }
                cout<<"do you want to continue(1/0)?"<<endl;
                cin>>choice;
            } while (choice==1);
            
            
        }
    void display_inorder(node *t)
    {
        if(t!=NULL)
        {
            display_inorder(t->lc);
            cout<<t->data<<" ";
            display_inorder(t->rc);
        }
        
    }
    void display_preorder(node *t)
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";
            display_preorder(t->lc);
            display_preorder(t->rc);
        }
    }
    void dis()
    {
        display_inorder(root);
        cout<<endl;
        display_preorder(root);
    }
};
int main()
{
    BST obj;
    obj.create();
    obj.dis();
    return 0;
}