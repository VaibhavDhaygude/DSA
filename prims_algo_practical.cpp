#include<iostream>
using namespace std;
class graph
{
    int n;
    int mat[10][10];

    public:
    graph()
    {
        cout<<"enter number of vertices"<<endl;
        cin>>n;
    }
    void mat_in()
    {
        for(int i=0 ; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mat[i][j]=0;
            }
        }
    }
    void mat_dis()
    {
        for(int i=0 ; i<n; i++)
        {
            for(int j=0 ; j<n; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void create()
    {
        int ans;
        int v1;
        int v2;
        int cost;
        // int arr[10]={0};
        do
        {
            cout<<"enter the first vertex";
            cin>>v1;
            cout<<"enter the second vertex";
            cin>>v2;
            
            if(mat[v1][v2]!=0)
            {
                cout<<"this edge is already covered"<<endl;
            }
            else
            {
                cout<<"enter the cost of the given edge";
                cin>>cost; 
                mat[v1][v2]=cost;
                mat[v2][v1]=cost;
                // arr[v1]=1;
                // arr[v2]=1;
            }
            
            cout<<"do you want to continue?(1/0)";
            cin>>ans;
        } while (ans==1);
        
        
    }
    void prims_algo()
    {
        int min;
        int min_cost=0;
        // int sv;
        // int flag=0;
        // int j=1;
        int visited[10]={0};
        // mat_in();
        int minimum_cost;
        // cout<<"enter the starting vertex"<<endl;
        // cin>>sv;
        // visited[sv]=1;
        for(int i=0;i<n-1;i++)
        {
            visited[i]=1;
            min =999;
            for(int j=0;j<n;j++)
            {
                if(visited[j]==0)
                {
                    if(mat[i][j]!=0 && mat[i][j]<min)
                    {
                        min=mat[i][j];
                        visited[j]=1;
                    }
                }
            }
            // cout<<min<<endl;
            if(min!=999)
            {
                min_cost=min_cost+min;

            }
        }
        cout<<"minimum cost of given graph is :"<<endl;
        cout<<min_cost<<endl;
    }

};
int main()
{
    graph g1;
    g1.mat_in();
    g1.create();
    g1.mat_dis();
    g1.prims_algo();
}