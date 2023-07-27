#include <iostream>
#include <stack>
using namespace std;
class AVL
{
    private:
    
        struct node 
        {
            int data;
            node *lc;
            node *rc;
            // int height;
            // int bal_fac;
        }*root;
        stack<node*>stk;
    public:
        AVL()
        {
            root=NULL;
        }

        int height(node *t)
        {
            int lheight=0 , rheight=0;
            if(t==NULL)
            {
                return -1;
            }
            else
            {
                lheight=height(t->lc);
                rheight=height(t->rc);
                if(lheight > rheight)
                {
                    return lheight+1;
                }
                else
                {
                    return rheight+1;
                }
            }
        }
        int balance_factor(node *t)
        {
            // cout<<height(t->lc) - height(t->rc)<<endl;
            return(height(t->lc) - height(t->rc));
        }
        void create()
        {
            int bf , ans;
            node *temp ,*t;
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
                            stk.push(t);
                            t=t->lc;
                        }
                        else if(temp->data > t->data && t->rc!=NULL)
                        {
                            stk.push(t);
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
                while(!stk.empty())
                {
                    t=stk.top();
                    stk.pop();
                    bf=balance_factor(t);
                    // cout<<bf<<endl;
                    if(bf>1 && temp->data < t->lc->data)
                    {
                        right_rotate(t);
                    }
                    if(bf<-1 && temp->data > t->rc->data)
                    {
                        left_rotate(t);
                    }
                    if(bf > 1 && temp->data > t->lc->data)
                    {
                        left_rotate(t->lc);
                        right_rotate(t);
                    }
                    if(bf<-1 && temp->data < t->rc->data)
                    {
                        right_rotate(t->rc);
                        left_rotate(t);
                    }
                    
                }
                cout<<"do you want to continue(0/1)?"<<endl;
                cin>>ans;
            } while (ans==1);
        }

        node *right_rotate(node *t)
        {
            // node *x;
            node *t1=t->lc;
            node *t2=t1->rc;

            t1->rc=t;
            t->lc=t2;
            return t1;
            // if(!stk.empty())
            // {
            //     x=stk.top();
            //     if(t2==NULL)
            //     {
            //         x->lc=t1;
            //     }
            //     else
            //     {
            //         x->lc=t2;
            //     }  
            // }
           

        }
        node  *left_rotate(node *t)
        {
            // node *x;
            node *t1=t->rc;
            node *t2=t1->lc;

            t1->lc=t;
            t->rc=t2;
            return t1;
            // if(!stk.empty())
            // {
            //     x=stk.top();
            //     if(t2==NULL)
            //     {
            //         x->rc=t1;
            //     }
            //     else
            //     {
            //         x->rc=t2;
            //     }   
            // }
            
        }
        void dis_inorder(node *t)
        {
            if(t!=NULL)
            {
                
                dis_inorder(t->lc);
                cout<<t->data<<" ";
                cout<<balance_factor(t)<<endl;
                dis_inorder(t->rc);
            }
            
        }
        void display()
        {
            dis_inorder(root);
        }
};
int main()
{
    AVL obj;
    obj.create();
    obj.display();
}