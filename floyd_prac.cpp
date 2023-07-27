#include<iostream>
using namespace std;

class Floyd
{
    private:
        int arr[10][10];
        int vertices;
    public:
        Floyd()
        {
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    arr[i][j] = 999;
                    if (i == j) 
                    {
                        arr[i][j] = 0;
                    }
                    
                }
                
            }
            
        }
        void create();
        void algo();
        void display();
};

void Floyd::create()
{
    int choice;
    do
    {
        int start, end, cost;
        cout<<"Enter starting vertex: "<<endl;
        cin>>start;
        cout<<"Enter end vertex: "<<endl;
        cin>>end;
        cout<<"Enter cost: "<<endl;
        cin>>cost;
        arr[start][end] = cost;
        cout<<"Continue?"<<endl;
        cin>>choice;
    } while (choice == 1);
}

void Floyd::algo()
{
    // int arr1[10][10];
    for(int k = 0; k < vertices; k++)
    {    for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (i==j||i==k||j==k)
                {
                    continue;
                }
                else
                {
                    if (arr[i][j]>arr[i][k]+arr[k][j])
                    {
                        arr[i][j] = arr[i][k]+arr[k][j];
                    }
                    
                }
                
            }
            
        }
    }
}

void Floyd::display()
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout<<arr[i][j]<<" ";        
        }
        cout<<endl;         
    }
}

int main()
{
    Floyd f;
    f.create();
    f.algo();
    f.display();
    return 0;
}