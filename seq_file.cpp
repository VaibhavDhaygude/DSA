#include <iostream>
#include<cstring>
// #include<string>
#include <fstream>
using namespace std;
class file
{
    private:
        struct node 
        {
            int rn;
            char name[20];
        }s;
    public:
        void create()
        {
            ofstream outfile;
            int ans;
            outfile.open("stud.data" , ios::out | ios::binary);
            do
            {
                cout<<"enter the roll number of student :"<<endl;
                cin>>s.rn;
                cout<<"enter the name of student :"<<endl;
                cin>>s.name;
                outfile.write((char*)&s,sizeof(s));
                cout<<"do you want to continue ?"<<endl;
                cin>>ans;
            } while (ans==1); \
            outfile.close();
        }

        void display()
        {
            ifstream infile;
            infile.open("stud.data" , ios::in | ios::binary);
            while(infile.read((char*)&s , sizeof(s)))
            {
                cout<<s.rn<<"  "<<s.name<<endl;
            }
            infile.close();
        }
        void search()
        {
            int key , flag=0;
            ifstream infile;
            infile.open("stud.data" , ios::in | ios::binary);
            cout<<"enter the roll number to search"<<endl;
            cin>>key;
            while(infile.read((char*)&s,sizeof(s)))
            {
                if(s.rn==key)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                cout<<"record is present"<<endl;
                cout<<s.rn<<"  "<<s.name<<endl;   
            }
            else
            {
                cout<<"record is not present"<<endl;
            }
            infile.close();
        }

        void delete_entry()
        {
            int key;
            ifstream infile;
            ofstream outfile;
            outfile.open("new.data",ios::out | ios::binary);
            infile.open("stud.data", ios::in | ios::binary);
            cout<<"enter roll number to modify"<<endl;
            cin>>key;
            while(infile.read((char*)&s,sizeof(s)))
            {
                if(s.rn==key)
                {
                    continue;
                }
                else
                {
                    outfile.write((char*)&s,sizeof(s));
                }
            }
            infile.close();
            outfile.close();
            remove("stud.data");
            rename("new.data" , "stud.data");
            display();
        }

        void modify()
        {
            fstream file;
            int key , flag=0;
            int t_roll;
            char t_name[20];
            file.open("stud.data" , ios::in | ios::out | ios::binary);
            cout<<"enter roll number to delete :"<<endl;
            cin>>key;
            while(file.read((char*)&s , sizeof(s)))
            {
                if(key == s.rn)
                {
                    flag=1;
                    cout<<"enter new roll number of student"<<endl;
                    cin>>t_roll;
                    cout<<"enter new name of student"<<endl;
                    cin>>t_name;
                    s.rn=t_roll;
                    strcpy(s.name,t_name);
                    file.write((char*)&s,sizeof(s));
                    // break;
                }
            }
            // if(flag==1)
            // {
            //     cout<<"enter new roll number of student"<<endl;
            //     cin>>t_roll;
            //     cout<<"enter new name of student"<<endl;
            //     cin>>t_name;
            //     s.rn=t_roll;
            //     strcpy(s.name,t_name);
            //     file.write((char*)&s,sizeof(s));
                
            // }
            // else
            // {
            //     cout<<"record is not present"<<endl;
            // }
            display();
            file.close();
        }
};
int main()
{
    file obj;
    obj.create();
    obj.display();
    obj.search();
    // obj.modify();
    obj.delete_entry();
    return 0;
}
