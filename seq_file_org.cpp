#include<iostream>
#include<fstream>
using namespace std;


class Seq_file
{
    private:
        struct stud{
            int rn;
            char nm[10];
        }s;
    public:
        void create();
        void display();
        void search();
        void delete_entry();
        void modify();
};

void Seq_file::create(){
    ofstream outFile;
    outFile.open("stud.data", ios::out|ios::binary);
    /*if(outFile == NULL){
    cout<<"File does not exist"<<endl;
    return;
    }*/
    int choice;
    do{
        cout<<"Enter the name and roll no. of the student."<<endl;
        cin>>s.nm>>s.rn;
        outFile.write((char*)&s, sizeof(s));
        cout<<"Do you want to enter more entries?(1/0)"<<endl;
        cin>>choice;
    }while(choice==1);
    outFile.close();
}
void Seq_file::display(){
    ifstream inFile;
    inFile.open("stud.data", ios::in|ios::binary);
    /*if(inFile == NULL){
    cout<<"File does not exist"<<endl;
    return;
    }*/
    while(inFile.read((char*)&s, sizeof(s))){
        cout<<s.rn<<"\t\t"<<s.nm<<endl;
    }
    inFile.close();
}

void Seq_file::search(){
    ifstream inFile;
    inFile.open("stud.data", ios::in|ios::binary);
    int flag = 0;
    int key;
    cout<<"Enter the roll no. to be searched:"<<endl;
    cin>>key;
    /*if(inFile == NULL){
    cout<<"File does not exist"<<endl;
    return;
    }*/
    while(inFile.read((char*)&s, sizeof(s))){
        if(key == s.rn){
        flag = 1;
        cout<<"Record found!!"<<endl;
        cout<<s.rn<<"\t\t"<<s.nm<<endl;
        break;
        }
    }
    inFile.close();
}

void Seq_file::delete_entry(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("stud.data", ios::in|ios::binary);
    outFile.open("new.data", ios::out|ios::binary);
    int flag = 0;
    int key;
    cout<<"Enter the roll no. to be deleted:"<<endl;
    cin>>key;
    /*if(inFile == NULL){
    cout<<"File does not exist"<<endl;
    return;
    }*/
    while(inFile.read((char*)&s, sizeof(s))){
        if(key == s.rn){
        flag = 1;
        cout<<"file to be deleted is:"<<endl;
        //cout<<s.rn<<"\t\t"<<s.nm<<endl;
        }
        else{
            outFile.write((char*)this, sizeof(s));
        }
    }
    inFile.close();
    outFile.close();
    remove("stud.data");
    rename("new.data", "stud.data");
}

void Seq_file::modify(){
/*fstream file;
ofstream outFile;
//outFile.open("stud.data", ios::out|ios::binary);
file.open("stud.data", ios::in|ios::out|ios::binary);
int flag = 0;
int key;
cout<<"Enter the roll no. to be searched:"<<endl;
cin>>key;
/*if(inFile == NULL){
cout<<"File does not exist"<<endl;
return;
}
while(file.read((char*)&s, sizeof(s))){
if(key == s.rn){
flag = 1;
cout<<"Enter new data:"<<endl;
cin>>this->s.rn>>this->s.nm;
file.write((char*)this, sizeof(s));
cout<<s.rn<<"\t\t"<<s.nm<<endl;
cout<<"New??"<<endl;
break;
}
}
file.close();*/
ifstream inFile;
ofstream outFile;
inFile.open("stud.data", ios::in|ios::binary);
outFile.open("new.data", ios::out|ios::binary);
int flag = 0;
int key, pos=0;
cout<<"Enter the roll no. to be deleted:"<<endl;
cin>>key;
/*if(inFile == NULL){
cout<<"File does not exist"<<endl;
return;
}*/
while(inFile.read((char*)&s, sizeof(s))){
if(key == s.rn){
flag = 1;
cout<<"file to be deleted is:"<<endl;
//cout<<s.rn<<"\t\t"<<s.nm<<endl;

}
else{
outFile.write((char*)this, sizeof(s));
}
pos++;
}
inFile.close();
outFile.close();
remove("stud.data");
rename("new.data", "stud.data");
}
int main(){
    Seq_file file;
    file.create();
    file.display();
    //file.delete_entry();
    file.modify();
    file.display();
    return 0;
}