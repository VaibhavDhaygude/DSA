#include <iostream>
#include <fstream>
#include<ctime>
using namespace std;
class ATM
{
    int pin;
    string ac_no;                   
    string name;
    float balance;
    int amt_D;
    int amt_w;
public:     
   
    ATM()
    {
        balance=0.0;
        amt_D=0;
        amt_w=0;
        pin=1234;
        name="ABC";
        ac_no="SBI12345";
    }
    int get_pin()
    {
        return pin;
    }
    
    void set_pin()
    {
        int pin_temp;
        cout<<"Enter your new Pin : ";
        cin>>pin_temp;
        pin=pin_temp;
        cout<<"\nNEW PIN IS SUCCESSFULLY UPDATED"<<endl;
    }
    void deposit()
    {
        cout<<"\nEnter the Amount you want to Deposit : ";
        cin>>amt_D;
        balance=balance+amt_D;
        cout<<"Amount deposited in  account succesfully \n"<<endl;            
    }
    
    void withdraw()
    { 
        cout<<"\nEnter the amount you want to Withdraw : ";
        cin>>amt_w;
        if(amt_w<=balance)
        {
            balance=balance-amt_w;
            cout<<"Thank You ! "<<" Now your  account Balance is : "<<balance<<endl;
        }
        else
        {
            cout<<"Your balance is not enough to withdraw this Amount : "<<amt_w<<endl;
            cout<<"Your  account balance is : "<<balance<<endl;
        }
    }
    
    
    void receipt()
    {
        cout<<"user details: "<<ac_no<<"  "<<name<<endl;
        cout<<"amount deposited: "<<amt_D<<endl;
        cout<<"amount withdraw: "<<amt_w<<endl;
        cout<<"current balance: "<<balance<<endl;
    }
    
    friend void write_record(ATM a);

};

string time()
    {
        time_t t=time(NULL); //making object of time_t  
                        //time(NULL) will return integer value(i.e number of second since 1970)
        string tmp=ctime(&t); //will convert t in to character string consist of current time and date
        return tmp;

    }
void write_record(ATM a)
    {
        
        ofstream fout("bank_database.txt",ios::app);
        
        fout<<time();
        
        fout<<"---- user details ----"<<endl;
        fout<<"account number :";
        fout<<a.ac_no<<endl;
        fout<<"name :";
        fout<<a.name<<endl;
        fout<<"---- user transaction ----"<<endl;
        fout<<"amount deposited "<<a.amt_D<<endl;
        fout<<"amount withdraw "<<a.amt_w<<endl;
        fout<<"balance is: ";
        fout<<a.balance<<endl<<endl<<endl;
        cout<<"RECORD SAVED TO DATABASE"<<endl;
        fout.close();
        
    }

    void menu()
    {
        cout<<"1---> To change the pin"<<endl;
        cout<<"2---> To deposit the amount"<<endl;
        cout<<"3---> To withdraw"<<endl;
        cout<<"4---> To get receipt"<<endl;
        
    }

int main()
{ 
    ATM a;
    int i;
    char ch;
    int flag=0;
    int pin_temp;
    cout<<"******************* WELCOME TO ATM *******************"<<endl;
    cout<<"Enter your pin : ";
    cin>>pin_temp;
    if(pin_temp==a.get_pin())
    {
        cout<<"Login successfully !!"<<endl;
        do
        {
            
            menu();
            cout<<"Enter your choice : "<<endl;
            cin>>i;
                
            switch(i)
            {
                case 1: a.set_pin();
                    cout<<"Enter your new pin to stay login"<<endl;
                    cin>>pin_temp;
                    if(pin_temp==a.get_pin())
                    {
                        cout<<"Login successfully !!"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"Sorry!!!You entered wrong pin"<<endl;
                        cout<<"try again"<<endl;
                        cout<<"enter your pin"<<endl;
                        cin>>pin_temp;
                        if(pin_temp==a.get_pin())
                        {
                            cout<<"Login successfully !!"<<endl;
                            break;
                        }
                       else
                       {
                           flag=1;
                           cout<<"Sorry!!!You entered wrong pin again"<<endl;
                           break;
                       }
                        
                    }
                case 2: a.deposit();
                    break;
                case 3: a.withdraw();
                    break;
                case 4: cout<<time();
                    a.receipt();
                    break;
                default: cout<<"OOPSSSS!! You entered unknown choice"<<endl;
                    break;
            }
        if(flag==0)
        {
            cout<<"Do you want to continue(y/n)"<<endl;
            cin>>ch;
        }
        else
        {
            ch='n'; //terminating do while loop 
        }  
        } while(ch=='y'||ch=='Y');
        write_record(a);
    }
    else
    {
        cout<<"You entered wrong pin!!!!"<<endl;
    }
    
    return 0;
}

