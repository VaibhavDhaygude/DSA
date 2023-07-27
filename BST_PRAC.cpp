#include <iostream>
#include <stack>
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
        stack<node*>stk;
        
    public:
        BST()
        {
            root=NULL;
        }
        void create()
        {
            node *temp ,*curr;
            int ans;
            do
            {
                int flag=0;
                temp=new node;
                temp->rc=NULL;
                temp->lc=NULL;
                cout<<"enter the data for new node"<<endl;
                cin>>temp->data;
                if(root==NULL)
                {
                    root=temp;
                }
                else
                {
                    curr=root;
                    while(flag==0)
                    {
                        if(temp->data<curr->data)
                        {
                            if(curr->lc==NULL)
                            {
                                curr->lc=temp;
                                flag=1;
                            }
                            else
                            {
                                curr=curr->lc;
                            }
                        }
                        else
                        {
                            if(curr->rc==NULL)
                            {
                                curr->rc=temp;
                                flag=1;
                            }
                            else
                            {
                                curr=curr->rc;
                            }
                        }
                    }
                }
            cout<<"do you want to continue(1/0)?"<<endl;
            cin>>ans;
            } while (ans==1);
           
        }
        
        
        void display_preorder()
        {
            int flag=0;
            node *curr ;
            curr=root;
            while(curr!=NULL || !stk.empty())        
            {
                while(curr!=NULL)
                {
                    cout<<curr->data<<" ";
                    if(curr->rc!=NULL)
                    {
                        stk.push(curr->rc);
                    }
                    curr=curr->lc;
                }
                if(curr==NULL && !stk.empty())
                {
                    curr=stk.top();
                    stk.pop();
                }
            }
            
        }
        void number_of_nodes()
        {
            int nodes_l=0;
            int nodes_r=0;
            int height_l=0;
            int height_r=0;
            node *t_l,*t_r;
            t_l=root->lc;
            t_r=root->rc;
            while(t_l!=NULL || !stk.empty())
            {
                while(t_l!=NULL)
                {
                    nodes_l++;
                    if(t_l->rc!=NULL)
                    {
                        stk.push(t_l->rc);
                    }
                    t_l=t_l->lc;
                }
                if(t_l==NULL && !stk.empty())
                {
                    t_l=stk.top();
                    stk.pop();
                }
            }
            cout<<"left sub tree nodes: "<<nodes_l<<endl;

            while(t_r!=NULL || !stk.empty())
            {
                while(t_r!=NULL)
                {
                    nodes_r++;
                    if(t_r->rc!=NULL)
                    {
                        stk.push(t_r->rc);
                    }
                    t_r=t_r->lc;
                }
                if(t_r==NULL && !stk.empty())
                {
                    t_r=stk.top();
                    stk.pop();
                }
            }
                cout<<"right sub tree nodes: "<<nodes_r<<endl;
        }

        void min_value()
        {
            node *t;
            t=root;
            while(t->lc!=NULL)
            {
                t=t->lc;
            }
            cout<<"minimum value is: "<<t->data<<endl;
        }
        void search()
        {
            int key;
            int flag=0;
            node *t;
            t=root;
            cout<<"enter the number to search: ";
            cin>>key;
            if(key==t->data)
            {
                flag=1;
            }
            else
            {
                while(t!=NULL)
                {
                    
                    if(key<t->data)
                    {
                        t=t->lc;
                        if(t==NULL)
                        {
                            break;
                        }
                        if(key==t->data)
                        {
                            flag=1;
                            break;
                        }
                    

                    }
                    if(key>t->data)
                    {
                        t=t->rc;
                        if(t==NULL)
                        {
                            break;
                        }
                        if(key==t->data)
                        {
                            flag=1;
                            break;
                        }
                        

                    }
                }

            }
            
            if(flag==1)
            {
                cout<<key<<" is present in the BST"<<endl;
            }
            else
            {
                cout<<key<<" is not present in the BST"<<endl;
            }
            
        }

        void mirror()
        {
            node *t ,*temp;
            t=root;
            while(t!=NULL || !stk.empty())
            {
                while(t!=NULL)
                {
                    temp=t->lc;
                    t->lc=t->rc;
                    t->rc=temp;
                    if(t->rc!=NULL)
                    {
                        stk.push(t->rc);
                    }
                    t=t->lc;
                }
                if(t==NULL && !stk.empty())
                {
                    t=stk.top();
                    stk.pop();
                }
            }
        }
        int height(node* t)
        {
            int lheight=0, rheight=0;
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
        // int depth(node *root)
        // {
        //     if(root==NULL)
        //     {
        //         return -1;
        //     }
        //     int lh=depth(root->lc);
        //     int rh=depth(root->rc);
            
        //     if(lh>rh)
        //     {
        //         return lh+1;
        //     }
        //     else
        //     {
        //         return rh+1;
        //     }
            
        // }
        // void height()
        // {
        //     depth(root);
        // }
        // void rec_preorder(node *t)
        // {
        //     if(t!=NULL)
        //     {
        //         cout<<t->data<<" ";
        //         rec_preorder(t->lc);
        //         rec_preorder(t->rc);
        //     }
        // }
        // void display_preorder()
        // {
        //     rec_preorder(root);
        // }
    void dis_height()
    {
        cout<<endl;
        cout<<height(root)<<endl;
    }
};
int main()
{
    BST s1;
    
    char ch;
    int ans;
    // s1.create();
    // s1.display_preorder();
    // s1.dis_height();
   
    do
    {
        cout<<"menu..."<<endl;
        cout<<"1.To enter new nodes in BST"<<endl;
        cout<<"2.To display BST (preorder method)"<<endl;
        cout<<"3.To search in BST"<<endl;
        cout<<"4.TO get number of nodes present in BST"<<endl;
        cout<<"5.To find minimum value in BST"<<endl;
        cout<<"6.To make mirror of BST"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ans;
        switch (ans)
        {
        case 1:
            s1.create();
            break;
        case 2:
            s1.display_preorder();
            break;
        case 3:
            s1.search();
            break;
        case 4:
            s1.number_of_nodes();
            break;
        case 5:
            s1.min_value();
            break;
        case 6:
            s1.mirror();
            break;
        default: cout<<"You entered unknown choice"<<endl;
            break;
        }
    cout<<"Do you want to continue(y/n)?"<<endl;
    cin>>ch;
    } while (ch=='y' || ch=='Y');
    s1.dis_height();
    
   
    return 0;
}