#include <iostream>
using namespace std;
class BTT
{
    struct node
    {
        int data;
        int rflag;
        int lflag;
        node *lc;
        node *rc;
    }*root ,*header;

    public :
        BTT()
        {
            header=new node;
            header->data=-1;
            header->lc=header;
            root=NULL;
        }
        void create()
        {
            node *temp ,*curr;
            int ans;
            do
            {
                temp=new node;
                cout<<"enter the data for new node"<<endl;
                cin>>temp->data;
                // temp->lc=NULL;
                // temp->rc=NULL;
                temp->rflag=0;
                temp->lflag=0;
                if(root==NULL)
                {
                    root=temp;
                    root->lc=root->rc=header;
                }
                else
                {
                    curr=root;
                    while(1)
                    {
                    
                        if(temp->data<curr->data)
                        {
                            if(curr->lflag==0)
                            {
                                temp->lc=curr->lc;
                                temp->rc=curr;
                                curr->lc=temp;
                                curr->lflag=1;
                                break;
                            }
                            else
                            {
                                curr=curr->lc;
                            }
                        }
                        if(temp->data>curr->data)
                        {
                            if(curr->rflag==0)
                            {
                                temp->rc=curr->rc;
                                temp->lc=curr;
                                curr->rc=temp;
                                curr->rflag=1;
                                break;
                            }
                            else
                            {
                                curr=curr->rc;
                            }
                        }
                    }
                }
                cout<<"do you want to enter new node (1/0)?"<<endl;
                cin>>ans;
            } while (ans==1);
            
            
        }

        void dis_preorder()
        {
            int flag=0;
            node *t;
            t=root;
            cout<<"preorder traversal"<<endl;
            cout<<t->data<<" ";
            while(t!=header)
            {
                // flag=0;
                if(t->lflag == 1 && flag!=1)
                {
                    t = t->lc;
                    cout<<t->data<<" ";
                }
                
                else if(t->rflag == 1)
                {
                    flag=0;
                    t = t->rc;
                    cout<<t->data<<" ";
                }
                else
                {
                    flag=1;
                    t = t->rc;
                }
            }
                
                // while(t->lflag==1)
                // {
                //     cout<<t->data<<" ";
                //     t=t->lc;
                // }
                // while(t->rflag==0)
                // {
                //     t=t->rc;
                // }
            
        }
        void inorder_traversal()
        {
            node *t;
            t=root;
            while(t->lflag!=0 )
            {
                t=t->lc;
            }
            cout<<endl;
            cout<<"inorder traversal"<<endl;
            while(t!=header)
            {
                cout<<t->data<<" ";
                if(t->rflag==0)
                {
                    t=t->rc;
                }
                else if(t->rflag==1)
                {
                    t=t->rc;
                    while(t->lflag!=0 )
                    {
                        t=t->lc;
                    }
                }
            }
        }
       
};
int main()
{
    BTT b1;
    b1.create();
    b1.dis_preorder();
    b1.inorder_traversal();
    return 0;
}