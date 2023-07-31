#include<iostream>
using namespace std;
class deque
{
    private:
        struct node
        {
            int data;
            node *next;

        }*front,*rear;
    public:
        deque()
        {
            front=NULL;
            rear=NULL;
        }
        void insert_front()
        {
            node *temp;
            temp=new node;
            cout<<"enter the number you want to add"<<endl;
            cin>>temp->data;
            temp->next=NULL;
            if(front==NULL && rear==NULL)
            {
                rear=temp;
                front=temp;
            }
            else
            {
                temp->next=front;
                front=temp;
            }
        }
        void insert_end()
        {
            node *temp;
            temp=new node;
            cout<<"enter the number you want to add"<<endl;
            cin>>temp->data;
            temp->next=NULL;
            if(front==NULL && rear==NULL)
            {
                rear=temp;
                front=temp;
            }
            else
            {
                rear->next=temp;
                temp->next=NULL;
                rear=rear->next;
            }
            
        }
        void delete_front()
        {
            node *t;
            if(front==NULL && rear==NULL)
            {
                cout<<"your que is already empty"<<endl;
            }
            else
            {
                t=front;
                front=front->next;
                cout<<t->data<<" "<<"has been deleted"<<endl;
                delete t;
            }
        }
        void delete_end()
        {
            node *t,*t1;
            if(front==NULL && rear==NULL)
            {
                cout<<"your que is already empty"<<endl;
            }
            else
            {
                t=front;
                while(t->next!=NULL)
                {
                    t1=t;   //for second last node
                    t=t->next;
                }
                t1->next=NULL;
                rear=t1;
                cout<<t->data<<" "<<"has been deleted"<<endl;
                delete t;
            }
        }
        void display()
        {
            node *t;
            
            cout<<"your QUE is as follows"<<endl;
            if(front==NULL )
            {
                cout<<"QUE is empty"<<endl;
                return ;
            }
            t=front;
            while(t!=NULL)
            {
                cout<<t->data<<endl;
                t=t->next;
            } 
            
            
        }
};

void menu()
{
    cout<<"1.for insert at front"<<endl;
    cout<<"2.for insert at end"<<endl;
    cout<<"3.for delete at front"<<endl;
    cout<<"4.for delete at end;"<<endl;
    cout<<"5.for displaying the QUE"<<endl;
}

int main()
{
    deque q;
    int ch;
    char choice;
    do
    {  
        menu(); 
        cout<<"enter your choice"<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1: q.insert_front();
                break;
            case 2: q.insert_end();
                break;
            case 3: q.delete_front();
                break;
            case 4: q.delete_end();
                break;
            case 5: q.display();
                break;
            default: cout<<"you enter unknown choice"<<endl;
                break;
        }
        cout<<"do you want to continue(y/n)"<<endl;
        cin>>choice;
    }while(choice=='y'||choice=='Y');

    return 0;
    
}