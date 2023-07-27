#include <iostream>
using namespace std;
class OBST
{
    private:
        int n;
        int data[10];
        int freq[10];
        int cost[10][10];
    public:
        OBST()
        {
            for(int i=0 ; i<10 ; i++)
            {
                data[i]=freq[i]=-1;
                for(int j=0;j<10;j++)
                {
                    if(i==j)
                    {
                        cost[i][j]=0;
                    }
                    else
                    {
                        cost[i][j]=0;
                    }
                    
                }
            }
        }
        void create()
        {
            
            int min=999;
            int weight=0;
            cout<<"enter the number of elements in BST"<<endl;
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cout<<"enter data"<<endl;
                cin>>data[i];
                cout<<"enter frequency of given data"<<endl;
                cin>>freq[i];
            }
            for(int z=0;z<n;z++)
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        if((j-i)==z)
                        {
                            cout<<"check"<<endl;
                            for(int r=i ; r<j ; r++)
                            {
                                if(cost[i][r]+cost[r+1][j]<min)
                                {
                                    min=cost[i][r]+cost[r+1][j];
                                }
                            }
                            for(int k=i+1; k<j+1; k++)
                            {
                                weight=weight+freq[k];
                            }
                            cost[i][j]=min+weight;
                            cout<<cost[i][j]<<endl;
                            
                        }
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if((j-i)==i+1)
                    {
                        cout<<"check"<<endl;
                        for(int r=i ; r<j ; r++)
                        {
                            if(cost[i][r]+cost[r+1][j]<min)
                            {
                                min=cost[i][r]+cost[r+1][j];
                            }
                        }
                        for(int k=i+1; k<j+1; k++)
                        {
                            weight=weight+freq[k];
                        }
                        cost[i][j]=min+weight;
                        cout<<cost[i][j]<<endl;
                        
                    }
                }
            }
        }
        void display()
        {
            cout<<"optimal searching cost is :"<<endl;
            cout<<cost[0][n];
        }
};
int main()
{
    OBST obj;
    obj.create();
    obj.display();
}