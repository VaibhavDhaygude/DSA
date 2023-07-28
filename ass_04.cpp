#include<iostream>
#include<cstring>
using namespace std;

class sll
{
    private:
        struct node
        {
            int element;
            
            node *next;
        }*start;
    public:
        sll()
        {
            start=NULL;   // initially start will be NULL
            
        }
        void create()
        { 
             node *temp , *curr;
             int ch;
        
        do
        {
           
            temp=new node;
            cout<<"enter PRN of student for new entry: "<<endl;
            cin>>temp->element;
            
            temp->next=NULL;
            
            if(start==NULL)
            {
                start=temp;  //temp=start is wrong way
                curr=temp;
            }
            else
            {
                curr->next=temp;
                curr=curr->next;
                
            }
            cout<<"enter the 1 if you want to add new node else enter 0 "<<endl;
            cin>>ch;
        }while(ch==1);
            
        }
        void display()
        {
            node *t;
            if(start==NULL)
            {
                cout<<"sll is empty "<<endl;
                return;
            }
            t=start;
            while(t!=NULL)
            {
                cout<<t->element<<endl;
                t=t->next;
            }
        }
        void concate(sll obj)
        {
          node *head1 , *head2 ,*h1; //head for pointing first node of second division 
                       // and t for pointing last node of first division
          head1=start;
          head2=obj.start;
          node *temp;
          
          while(head1!=NULL)
          {
                temp=new node;
                if(head2->element<head1->element && (head1==start && head2==obj.start))
                {
                    temp->element=head2->element;
                    temp->next=head1;
                    start=temp;
                    head2=head2->next;
                }
                else if(head2->element<head1->element )
                {
                    temp->element=head2->element;
                    temp->next=head1;
                    
                    head2=head2->next;
                }
                else
                {
                    h1=head1;
                    head1=head1->next;
                }
          }
          if(head2!=NULL)
          {
              while(head2!=NULL)
              {
                  temp=new node;
                  temp->element=head2->element;
                  
                  h1->next=temp;
                  temp->next=NULL;
                  head2=head2->next;


              }
          }

       
          
        }
};
int main()
{
    sll s1 , s2;
    s1.create();
    s2.create();
    //s1.display();
    //s2.display();
    s1.concate(s2);
    s1.display();
    return 0;
}