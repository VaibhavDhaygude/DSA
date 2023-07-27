#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class BFS_DFS
{
    private:
        int graph[10][10];
        // int result[10];
        int visited[10];
        int explored[10];
        int vertices;
        queue<int> q;
        stack<int> stk;
    public:
        BFS_DFS()
        {
            for(int i=0;i<10;i++)
            {
                visited[i]=explored[i]=-1;
                for(int j=0;j<10;j++)
                {
                    graph[i][j]=-1;
                }
            }
        }
        void get()
        {
            int ans;
            int start,end;
            cout<<"enter number of vertices"<<endl;
            cin>>vertices;
            do
            {
                cout<<"enter first vertex "<<endl;
                cin>>start;
                cout<<"enter end vertex"<<endl;
                cin>>end;
                graph[start][end]=graph[end][start]=1;
                cout<<"do you want to continue?(1/0)"<<endl;
                cin>>ans;
            } while(ans==1);   
        }
        void BFS_algo()
        {
            int st , curr;
            cout<<"enter starting vertex"<<endl;
            cin>>st;
            curr=st;
            q.push(st);
            // int cnt=0;
            while(!q.empty())
            {
                // cnt++;
                curr=q.front();
                visited[curr]=1;
                q.pop();
                cout<<curr<<" ";
                for(int i=0;i<vertices;i++)
                {
                    if(graph[curr][i]==1 && visited[i]==-1 && explored[i]==-1)
                    {
                        explored[i]=1;
                        q.push(i);
                    }
                }
            }
        }

        void DFS_algo()
        {
            int st, curr;
            cout<<"Enter starting vertex: "<<endl;
            cin>>st;
            explored[st] = 1;
            visited[st] = 1;
            curr = st;
            do
            {
                for(int i=0; i<vertices; i++)
                {
                    if(graph[curr][i]==1 && visited[i]==-1 && explored[i]==-1)
                    {
                        stk.push(i);
                        explored[i] = 1;
                    }
                }
                cout<<curr<<" ";
                visited[curr] = 1;
                curr = stk.top();
                stk.pop();
            }while(!stk.empty());
            cout<<curr<<endl;
        }
};
int main()
{
    BFS_DFS obj;
    obj.get();
    obj.DFS_algo();
    return 0;
}
