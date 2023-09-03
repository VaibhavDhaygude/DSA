#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int i;
    char name[11];
    char number[11];
    char s;
    ofstream fout("stud.dat",ios::app);
    cout<<"enter the number of telephone numbers you want to insert"<<endl;
    cin>>i;
    fout<<"NAME   NUMBER "<<endl;
    for(int j=0;j<i;j++)
    {
        cout<<"enter the name of telephone number holder"<<endl;
        cin>>name;
        fout<<name;
        fout<<"  ";
        cout<<"enter the telephone number"<<endl;
        cin>>number;
        fout<<number<<endl;
    }
    fout.close();
    ifstream fin("stud.dat",ios::binary);
    while(!fin.eof())
    {
        fin.get(s);
        cout<<s;
    }
    fin.close();

    return 0;
}
