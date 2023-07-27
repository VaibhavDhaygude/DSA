#include<iostream>
using namespace std;
class obst
{
    private:
        int cost[10][10];
        int freq[10];
        int wt[10][10];
        int weight(int, int);
        int costs(int,int,int);
        int nodes;
    public:
        void create();
        void display();
        obst()
        {
            for (int i = 0; i < 10; i++)
            {
                freq[i] = 0;
                for (int j = 0; j < 10; j++)
                {
                    cost[i][j] = 0;
                    wt[i][j] = 0; 
                }
                
            }
            
        }
};
int obst::costs(int i, int j, int n)
{
    int min=999;
    // int n = 0;
    int c;
    if (j-i == n)
    {
        for (int k = i; k < j; k++)
        {
            c = cost[i][k] + cost[k+1][j] ;
            if (c< min)
            {
                min = c;
            }
                    
        }
    return min+wt[i][j]; 
    }
    return cost[i][j];
}

int obst::weight(int i, int j)
{
    int wgt=0;
    for (int k = i+1; k <= j; k++)
    {
        wgt = wgt+freq[k];
    }
    return wgt;
}
void obst::create()
{
    int n = 1;
    cout<<"Enter nodes: "<<endl;
    cin>>nodes;
    for (int i = 1; i <= nodes; i++)
    {
        int f;
        cout<<"enter: "<<endl;
        cin>>f;
        freq[i] = f;
    }
    for (int i = 0; i <= nodes; i++)
    {
        for (int j = 0; j <= nodes; j++)
        {
            if (i < j)
            {
                wt[i][j] = weight(i,j);
            }
            
        }  
    }
    for(int n=1; n<=nodes; n++)
    {
        // cout<<n<<endl;
        for (int i = 0; i <= nodes; i++)
        {
            for (int j = 0; j <= nodes; j++)
            {
                if (i < j)
                {
                    cost[i][j] = costs(i,j,n);
                }
            }  
        }    
    } 
   
}

void obst::display()
{
    cout<<"weight matrix:"<<endl;
    for (int i = 0; i <= nodes; i++)
    {
        for (int j = 0; j <= nodes; j++)
        {
            cout<<wt[i][j]<<" ";
        }
        cout<<endl;
    } 
    cout<<"cost matrix: "<<endl;
    for (int i = 0; i <= nodes; i++)
    {
        for (int j = 0; j <= nodes; j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }  
    cout<<"least search count of given tree is: "<<cost[0][nodes]<<endl;
}

int main()
{
    obst b;
    b.create();
    b.display();
    return 0;
}