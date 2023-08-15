#include <iostream>
using namespace std;

class S_RECORD
{
    struct node
    {
        string name;
        int roll;
        int cls;
        int age;
        node *next;
    } * start;

public:
    S_RECORD()
    {
        start = NULL;
    }
    void create()
    {
        cout << "\nEnter Student data : \n";
        node *temp, *curr;
        int a;
        do
        {
            temp = new node;
            cout << "Enter Name : ";
            cin >> temp->name;
            cout << "Enter Roll NO. : ";
            cin >> temp->roll;
            cout << "Enter class : ";
            cin >> temp->cls;
            cout << "Enter Age : ";
            cin >> temp->age;
            temp->next = NULL;

            if (start == NULL)
            {
                start = temp;
                curr = temp;
            }
            else
            {
                curr->next = temp;
                curr = curr->next;
            }
            cout << "\nEnter 1 to add one more Student or Enter 0 to display database : ";
            cin >> a;cout<<endl;
        } while (a == 1);
        cout<<"\nStudent database is created \n";
        dis();
    }
    void ins_f()
    {
        node *temp;
        temp = new node;
        cout << "Enter Name : ";
        cin >> temp->name;
        cout << "Enter Roll NO. : ";
        cin >> temp->roll;
        cout << "Enter class : ";
        cin >> temp->cls;
        cout << "Enter Age : ";
        cin >> temp->age;
        temp->next = NULL;

        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            temp->next = start;
            start = temp;
        }
    }
    void ins_l()
    {
        node *temp, *t;
        temp = new node;
        cout << "Enter Name : ";
        cin >> temp->name;
        cout << "Enter Roll NO. : ";
        cin >> temp->roll;
        cout << "Enter class : ";
        cin >> temp->cls;
        cout << "Enter Age : ";
        cin >> temp->age;
        temp->next = NULL;

        t = start;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
    void ins_bw()
    {
        node *temp, *t;
        int n;
        cout << "Enter location at which you want to insert Student Data : ";
        cin >> n;cout<<endl;
        temp = new node;
        cout << "Enter Name : ";
        cin >> temp->name;
        cout << "Enter Roll NO. : ";
        cin >> temp->roll;
        cout << "Enter class : ";
        cin >> temp->cls;
        cout << "Enter Age : ";
        cin >> temp->age;
        temp->next = NULL;

        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            t = start;
            for (int i = 1; i < n - 1;+ i++)
            {
                t = t->next;
            }
            temp->next = t->next;
            t->next = temp;
        }
    }
    void dis()
    {
        node *t;
        if (start == NULL)
        {
            cout << "Student Database is Empty \n";
        }
        else
        {
            t = start;
            cout << "\nStudent Database : \n";
            cout << "RollNo." << "\t"<< "NAME"<< "\t"<< "CLASS"<< "\t"<< "AGE"<< "\n";
            while (t != NULL)
            {
                cout << t->roll << "\t" << t->name << "\t" << t->cls << "\t" << t->age << "\n";
                t = t->next;
            }
        }
        cout << endl;
    }
    void del_f()
    {
        node *t;
        if (start == NULL)
        {
            cout << "Student Database is Empty " << endl;
        }
        else
        {
            t = start;
            start = start->next;
            cout <<"Roll No."<< t->roll << " Student data deleted \n" << endl;
            delete t;
        }
    }
    void del_l()
    {
        node *l, *sl;
        if (start == NULL)
        {
            cout << " Student Database is Empty " << endl;
        }
        else
        {
            l = start;
            while (l->next != NULL)
            {
                sl = l;
                l = l->next;
            }
            cout <<"Roll No."<< l->roll << " Student data deleted \n" << endl;
            delete l;
            sl->next = NULL;
        }
    }
    void del_bw()
    {
        node *l, *sl;
        int b;
        if (start == NULL)
        {
            cout << "Student Database is Empty " << endl;
        }
        else
        {
            l = start;
            cout << "Enter location at which you want to Delete Student Data : " ;
            cin >> b; cout<<endl;
            for (int i = 1; i < b; i++)
            {
                sl = l;
                l = l->next;
            }
            sl->next = l->next;
            cout << "Roll No."<<l->roll << " Student Data deleted \n" << endl;
            delete l;
        }
    }
    void mod()
    {
        node *t;
        int b, a, c, r;
        string n;

        if (start == NULL)
        {
            cout << "Student Database is Empty " << endl;
        }
        else
        {
            t = start;
            cout << "Enter location at which you want to modify : " ;
            cin >> b;cout<< endl;
            for (int i = 1; i < b; i++)
            {
                t = t->next;
            }
            cout << "Enter new Student data : \n";
            cout << "Enter Name : ";
            cin >> n;
            cout << "Enter Roll No. : ";
            cin >> r;
            cout << "Enter class : ";
            cin >> c;
            cout << "Enter Age : ";
            cin >> a;
            t->name = n;
            t->roll = r;
            t->cls = c;
            t->age = a;
            cout << "\nStudent Data modified \n";
        }
    }
    void search()
    {
        node *t;
        int b;
        cout << "Enter Roll no. to Search : " ;
        cin >> b;cout<<endl;
        t = start;
        while (t != NULL)
        {

            if (b == t->roll)
            {
                cout << "Student data found " << endl;
                cout << "ROllNo."<< "\t"<< "NAME"<< "\t"<< "CLASS"<< "\t"<< "AGE"<< "\n";
                cout << t->roll << "\t" << t->name << "\t" << t->cls << "\t" << t->age << "\n";
                return;
            }
            else
            {
                t = t->next;
            }
        }
        if (t == NULL)
        {
            cout << "Student Data not found \n";
        }
    }
    void insert();
    void del();
};
void S_RECORD::insert()
{
    int n;
    do
    {
        cout << " \n*****   INSERT MENU   ******\n";
        cout << " 1 -- Insert Student Data at First location \n";
        cout << " 2 -- Insert Student Data at Random location \n";
        cout << " 3 -- Insert Student Data at Last location \n";
        cout << " 4 -- Display student data \n";
        cout << " 5 -- Exit to MAIN MENU \n\n";
        cout << " Enter your choice : ";cin>>n;
        switch(n)
        {
        case 1 :
            ins_f();
            break;
        case 2 :
            ins_bw();
            break;
        case 3 :
            ins_l();
            break;
        case 4 :
            dis();
            break;
        }
    } while (n!=5);
      
}
void S_RECORD::del()
{
    int n;
    do
    {
        cout << " \n*****   DELETE MENU   ******\n";
        cout << " 1 -- Delete Student Data at First location \n";
        cout << " 2 -- Delete Student Data at Random location \n";
        cout << " 3 -- Delete Student Data at Last location \n";
        cout << " 4 -- Display student data \n";
        cout << " 5 -- Exit to MAIN MENU \n\n";
        cout << " Enter your choice : ";cin>>n;
        switch(n)
        {
        case 1 :
            del_f();
            break;
        case 2 :
            del_bw();
            break;
        case 3 :
            del_l();
            break;       
        case 4 :
            dis();
            break;
        }
    } while (n!=5);
}
int main()
{
    S_RECORD S;

    cout << "***************\n";
    cout << "****  STUDENT DATABASE  *****\n";

    int a;
    do
    {
        cout << "\n******  MAIN MENU  ******\n";
        cout << " 1 -- Create Student Database \n";
        cout << " 2 -- Insert Student Data \n";
        cout << " 3 -- Delete Student Data \n";
        cout << " 4 -- Search Student Data \n";
        cout << " 5 -- Modify Student Data \n";
        cout << " 6 -- Display Student Data \n";
        cout << " 0 -- Exit \n\n";
        cout << "Enter your choice : ";
        cin >> a;cout<<endl;

        switch (a)
        {
        case 1:
            S.create();
            break;
        case 2:
            S.insert();
            break;
        case 3:
            S.del();
            break;
        case 4:
            S.search();
            break;
        case 5:
            S.mod();
            break;
        case 6:
            S.dis();
            break;
        }
    } while (a != 0);
    return 0;
}