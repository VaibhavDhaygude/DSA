#include<iostream>
using namespace std;
#define MAX 10

class graph
{
    int Mat[MAX][MAX]={0};
    int n;

    public:

    graph()
    {
        cout<<"Enter no. of vertices : ";cin>>n;
    }

    void create()
    {
        int a;
        int start_pt,end_pt,cost;

        do
        {
            cout<<"Enter starting point of line : ";cin>>start_pt;
            cout<<"Enter ending point of line : ";cin>>end_pt;
            cout<<"Enter cost of line : ";cin>>cost;

            Mat[start_pt][end_pt]=cost;
            Mat[end_pt][start_pt]=cost;

            cout<<"Want to continue ? (1/0) : ";cin>>a;
        }while(a==1);
    }

    void display()
    {
        cout<<"Adjacency Matrix : \n";
        for(int i=0;i<n;i++)
        {
            cout<<endl;
            for(int j=0;j<n;j++)
            {
                cout<<" "<<Mat[i][j];
            }
        }
    }

    void prims_algo()
    {
        int min;
        int min_cost=0;
        int visited[MAX]={0};
        int st,p,q;
        cout<<"enter starting vertex"<<endl;
        cin>>st;
        visited[st]=1;
        for(int k=0;k<n-1;k++)
        {
            min=999;
            for(int i=0;i<n;i++)
            {
                if(visited[i]==1)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(visited[j]==0)
                        {
                            if(Mat[i][j]!=0 && min>Mat[i][j])
                            {
                                min=Mat[i][j];
                                p=i;
                                q=j;
                            }
                        }
                        
                    }

                }
                
            }
            visited[p]=visited[q]=1;
            min_cost=min_cost+min;
        }
        cout<<min_cost<<endl;
        
    }
};

int main()
{
    graph g;
    g.create();
    g.display();
    g.prims_algo();

    return 0;
}

