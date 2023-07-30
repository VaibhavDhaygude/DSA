#include <iostream>
using namespace std;
class DLL
{
    private:
        int count;
        int n;
        struct node
        {
            bool digit;
            node *next;
            node *prev;
        }*start,*curr;
    public:
        DLL()
        {
            start=NULL;
            curr=NULL;
        }
        void get_number()
        {
            node *temp;
            
            cout<<"enter how many digits you want in your binary number"<<endl;
            cin>>n;
            for(int i=0;i<n;i++)
            {
                temp=new node;
                temp->next=NULL;
                temp->prev=NULL;
                cout<<"enter digit (start from MSB digit) "<<endl;
                cin>>temp->digit;
                if(start==NULL)
                {
                    start=temp;
                    curr=temp;
                }
                else
                {
                    curr->next=temp;
                    temp->prev=curr;
                    curr=curr->next;
                }
            }
            
        }
       /*void reset()
        {
            node *t;
            t=start;
            int count=10;
            int i=0;
            bool arr[count];
            while(t!=NULL)
            {
                arr[i]=t->digit;
                i++;
                t=t->next;
                //count++;
            }
            //count=0;
            i=0;
            t=start;
            while(t!=NULL)
            {
                t->digit=arr[i];
                i++;
                t=t->next;
                //count++;
            }

        }*/
        void display()
        { 
            node *t;
            t=start;
            
            while(t!=NULL)
            {
                cout<<t->digit<<" ";
                t=t->next;
               
            }
            cout<<endl;
        }
        void ones_comp()
        {
            get_number();
            node *t;
            t=start;
            
            while(t!=NULL)
            {
                if(t->digit==0)
                {
                    t->digit=1;
                }
                else
                {
                    t->digit=0;
                }
                //cout<<t->digit<<" ";
                t=t->next;
            }
            cout<<"your 1's complement is: "<<endl;
            display();
            cout<<endl;
        }
        void twos_comp()
        {
            get_number();
            node *t1 , *t;
            t1=curr;
            //cout<<t1->digit;
            t=start;
            
            
            while(t1->digit!=1)
            {
               t1=t1->prev; 
            }
            while(t1->prev!=NULL)
            {
                t1=t1->prev;
                if(t1->digit==1)
                {
                    t1->digit=0;
                }
                else
                {
                    t1->digit=1;
                }
                
            }
            cout<<"2's complement is: "<<endl;
            display();
            cout<<endl;
        }
        void insert_st()
        {
            node *t;
            t=new node;
            t->digit=0;
            t->prev=NULL;
            t->next=NULL;
            t->next=start;
            start->prev=t;
            start=t;
        }
        void add(DLL obj)
        {
            int c1 , c2;
            node *t1 , *t2;
            t1=curr;
            t2=obj.curr;
            c1=n;
            c2=obj.n;
            
            bool carry=0;
            if(c1!=c2)
            {
                if(c1>c2)
                {
                    while(c1!=c2)
                    {
                        obj.insert_st();
                        c2++;
                    }
                }
                else
                {
                    while(c1!=c2)
                    {
                        insert_st();
                        c1++;
                    }
                }
            }
            // display();
            // obj.display();
            while(t1!=NULL && t2!=NULL)
            {
              
                if(t1->digit==0 && t2->digit==0 && carry==0)
                {
                    t1->digit=0;
                    t1=t1->prev;
                    t2=t2->prev;
                }
                else if((t1->digit==0 && t2->digit==1 && carry==0)||(t1->digit==1 && t2->digit==0 && carry==0))
                {
                    t1->digit=1;
                    t1=t1->prev;
                    t2=t2->prev;
                }
                else if(t1->digit==1 && t2->digit==1 && carry==0)
                {
                    t1->digit=0;
                    t1=t1->prev;
                    t2=t2->prev;
                    carry=1;
                }
                else if(t1->digit==0 && t2->digit==0 && carry==1)
                {
                    t1->digit=1;
                    t1=t1->prev;
                    t2=t2->prev;
                    carry=0;
                }
                else if((t1->digit==0 && t2->digit==1 && carry==1)||(t1->digit==1 && t2->digit==0 && carry==1))
                {
                    t1->digit=0;
                    t1=t1->prev;
                    t2=t2->prev;
                    carry=1;
                }
                else if(t1->digit==1 && t2->digit==1 && carry==1)
                {
                    t1->digit=1;
                    t1=t1->prev;
                    t2=t2->prev;
                    carry=1;
                }

            }  
            if(carry==1)
            {
                node *temp;
                temp->next=NULL;
                temp->prev=NULL;
                temp->digit=1;
                temp->next=start;
                start->prev=temp;
                start=start->prev;
            }
            cout<<"Binary addition is: "<<endl;
            display();
        }
};
int main()
{
    DLL b1 , b2 , b3 ,b4;
    //b1.get_number();
    //b2.get_number();
    //b1.display();
    //b2.display();
    cout<<"enter for ones complement: "<<endl;
    b1.ones_comp();
    //b1.reset();
    //b1.display();
    //b1.get_number();
    cout<<"enter for twos complement: "<<endl;
    b2.twos_comp();
    //b1.reset();
    cout<<"enter for binary addition:"<<endl;
    cout<<"enter for first binary number: "<<endl;
    b3.get_number();
    cout<<"enter for second binary number: "<<endl;
    b4.get_number();
    b3.add(b4);
    // b3.display();
    return 0;
}