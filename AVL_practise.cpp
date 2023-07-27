#include<iostream>
#include<stack>
using namespace std;
class AVL
{
    private:
        struct node
        {
            int data;
            node *lc;
            node *rc;
        }*root;
        stack<node *>stk;
        // int height(node*t);
        // int balance_f(node *t);
        // node* r_rotate(node*t);
        // node* l_rotate(node*t);
    public:
        AVL()
        {
            root=NULL;
        }
        void create()
        {
            int ans;
            node *x;
            node *temp,*t;
            
            do
            {
                temp =new node ;
                temp->rc=temp->lc=NULL;
                cout<<"enter data"<<endl;
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
                        if(temp->data<t->data && t->lc!=NULL)
                        {
                            stk.push(t);
                            t=t->lc;
                        }
                        else if(temp->data>t->data && t->rc!=NULL)
                        {
                            stk.push(t);
                            t=t->rc;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(temp->data<t->data)
                    {
                        t->lc=temp;
                    }
                    else
                    {
                        t->rc=temp;
                    }
                }
                cout<<"do you want to continue ?(1/0)"<<endl;
                cin>>ans;
            } while (ans==1);

            while(!stk.empty())
            {
                int bf;
                t=stk.top();
                stk.pop();
                bf=balance_f(t);
                if(bf>1 && temp->data<t->lc->data)
                {
                    x=stk.top();
                    x=r_rotate(t);
                }
                else if(bf>1 && temp->data>t->lc->data)
                {
                    x=stk.top();
                    t=l_rotate(t->lc);
                    x=r_rotate(t);
                }
                else if(bf<-1 && temp->data<t->lc->data)
                {
                    x=stk.top();
                    x=l_rotate(t);
                }
                else if(bf<-1 && temp->data>t->lc->data)
                {
                    x=stk.top();
                    t=r_rotate(t->rc);
                    x=l_rotate(t);
                }

            }
        }
        int height(node *t)
        {
            int lheight=0;
            int rheight=0;
            if(t==NULL)
            {
                return -1;
            }
            else
            {
                lheight=height(t->lc);
                rheight=height(t->rc);
                if(lheight>rheight)
                {
                    return lheight+1;
                }
                else
                {
                    return rheight+1;
                }
            }
            
        }
        int balance_f(node*t)
        {
            return height(t->lc)-height(t->rc);
        }
        node* r_rotate(node*t)
        {
            node *t1,*t2;
            t1=t->lc;
            t2=t1->rc;

            t1->rc=t;
            t->lc=t2;
            return t1;
        }
        node* l_rotate(node *t)
        {
            node *t1,*t2;
            t1=t->rc;
            t2=t1->lc;

            t1->lc=t;
            t->rc=t2;
            return t1;
        }

        void display(node*t)
        {
            if(t!=NULL)
            {
                display(t->lc);
                cout<<t->data<<" "<<balance_f(t)<<endl;
                display(t->rc);
            }
        }
        void dis()
        {
            display(root);
        }
};
int main()
{
    AVL obj;
    obj.create();
    obj.dis();
    
    
}