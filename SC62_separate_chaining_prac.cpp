#include <iostream>
using namespace std;

class  s_c
{
    private:
        int len=10;
        int loc_h;
        struct node
        {
            int key;
            char mng[15];
            node *next;
        }*ht[10];
    public:
        s_c()
        {
            for(int i=0;i<len;i++)
            {
                ht[i]=NULL;
            }
           
        }
        void create()
        {
          
            node *temp ;
            int ch;
            do
            {
                temp=new node;
                cout<<"enter key: "<<endl;
                cin>>temp->key;
                cout<<"enter meaning: "<<endl;
                cin>>temp->mng;
                temp->next=NULL;
                loc_h=temp->key%len;
                
                if(ht[loc_h]==NULL)
                {
                    ht[loc_h]=temp;
                }
                else
                {
                   
                    node *t;
                    t=ht[loc_h];
                    while(t->next!=NULL)
                    {
                        t=t->next;
                    }
                    t->next=temp;
                }
            cout<<"do you want to enter new node(1/0)?"<<endl;
            cin>>ch;
            }while(ch==1);
        }

        void display()
        {
            node *t;
            for(int i=0;i<len;i++)
            {
                t=ht[i];
                while(t!=NULL)
                {
                    cout<<"key: "<<t->key <<" meaning: "<<t->mng<<endl;
                    t=t->next;
                }
            }
        }
        void search()
        {
            node *t;
            int key_s;
            int flag=0;
            cout<<"enter the key to find meaning: "<<endl;
            cin>>key_s;
            loc_h=key_s%len;
            t=ht[loc_h];
            while(t!=NULL)
            {
                if(t->key==key_s)
                {
                    
                    flag=1;
                    break;
                }
                else
                {
                    t=t->next;
                }
            }
            if(flag==1)
            {
                cout<<"key is present"<<endl;
                cout<<"key: "<<t->key <<" meaning: "<<t->mng<<endl;
            }
            else
            {
                cout<<"key is not present in this dictionary"<<endl;
            }
        }
        void del()
        {
            int key_d;
            int loc_h;
            node*t , *t1 ,*t2;
            cout<<"enter the key to delete: "<<endl;
            cin>>key_d;
            loc_h=key_d%len;
            t=ht[loc_h];
            
            if(t==NULL)
            {
                cout<<key_d<<" is not present in the dictionary"<<endl;

            }
            
            else
            {
                while(t->key!=key_d && t!=NULL)
                { 
                    t1=t;
                    t=t->next;
                }
                
                if(t==NULL)
                {
                    
                    cout<<key_d<<" is not present in the dictionary"<<endl;
                    
                }
                else
                {
                    if(t==ht[loc_h] && t->next==NULL) //if t is first node and rest bucket is empty
                    {
                        cout<<t->key<<" : "<<t->mng<<" this pair has been deleted"<<endl;
                        ht[loc_h]=NULL;
                        delete t;
                    }
                    else if(t==ht[loc_h] && t->next!=NULL) // if t is first node and bucket also has some more nodes
                    {
                        t2=t->next;
                        cout<<t->key<<" : "<<t->mng<<" this pair has been deleted"<<endl;
                        ht[loc_h]=t2;
                        delete t;
                    }
                    
                    else if(t->next==NULL) // if t is the last node in the bucket
                    {
                        t1->next=NULL;
                        cout<<t->key<<" : "<<t->mng<<" this pair has been deleted"<<endl;
                        delete t;
                    }
                    else                // if t is middle node in the bucket
                    {
                        t2=t->next;
                        t1->next=t2;
                        cout<<t->key<<" : "<<t->mng<<" this pair has been deleted"<<endl;
                        delete t;
                    }
                   
                }
            }
            
        }
        
};

int main()
{
    s_c s1;
    char ch;
    int choice;
    do
    {
        cout<<"MENU :-"<<endl;
        cout<<"1--to insert in dictionary"<<endl;
        cout<<"2--to display dictionary"<<endl;
        cout<<"3--to search in dictionary"<<endl;
        cout<<"4--to delete node in dictionary"<<endl;
        cout<<"enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1: s1.create();
            break;
        case 2: cout<<"dictionary is as follows: "<<endl;
            s1.display();
            break;
        case 3: s1.search();
            break;
        case 4: s1.del();
            break;
        default: cout<<"you entered unknown choice"<<endl;
            break;
        }
        cout<<"do you want to continue?(y/n) :";
        cin>>ch;
    } while (ch=='y'||ch=='Y');
    
    
}


