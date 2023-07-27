#include<iostream>
using namespace std;
# define len 5
class hashing
{
    private:
        int key[len];
        int chain[len];
        int number;
    public:
        hashing()
        {
            for(int i=0;i<len;i++)
            {
                key[i]=chain[i]=-1;
            }
        }
        void create(int number)
        {
            int ch;
            int loc_h;
            int temp_loc;
            int temp_loc_p;
            int temp_number;
            
            loc_h=number%len;
            if(key[loc_h]==-1)
            {
                    key[loc_h]=number;
            }
            else if(key[loc_h]!=-1)
            {
                if(key[loc_h]%len==loc_h)
                {
                    if(chain[loc_h]==-1)
                    {
                        temp_loc=loc_h;
                        while(key[temp_loc]!=-1)
                        {
                            temp_loc++;
                        }
                        key[temp_loc]=number;
                        chain[loc_h]=temp_loc;
                    }
                    else
                    {
                        temp_loc=loc_h;
                        while(key[temp_loc]!=-1)
                        {
                            temp_loc=chain[loc_h];
                        }
                        temp_loc_p=temp_loc;
                        while(key[temp_loc]!=-1)
                        {
                            temp_loc++;
                        }
                        key[temp_loc]=number;
                        chain[temp_loc_p]=temp_loc;
                    }
                }
                else
                {
                    int i=0;
                    temp_number=key[loc_h];
                    key[loc_h]=number;
                    temp_loc_p=chain[loc_h];
                    // chain[loc_h]=-1;
                    while(chain[i]!=loc_h)
                    {
                        i++;
                    }
                    if(chain[loc_h]==-1)
                    {
                        chain[i]=-1;
                    }
                    else
                    {
                        chain[i]=chain[loc_h];
                    }
                    create(temp_number);
                }
            }
                   
            
               
            
        }
        void display()
        {
            for(int i=0;i<len;i++)
            {
                cout<<key[i]<<" : "<<chain[i]<<endl;
            }
        }
};
int main()
{
    int ch;
    int number;
    hashing ht;
    do
    {
        cout<<"enter the number you want to insert: "<<endl;
        cin>>number;
        ht.create(number);
        cout<<"do you want to enter one more number?(1/0)"<<endl;
        cin>>ch;
    } while (ch==1);
    ht.display();
    
   
}