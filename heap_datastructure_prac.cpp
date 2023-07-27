#include<iostream>
using namespace std;
class heap_datastr
{
    private:
        int arr[10];
        int heap_max[10];
        int heap_min[10];
        int n;

    public:
        void get()
        {
            cout<<"enter the number of students in class"<<endl;
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cout<<"enter the marks of "<<i+1<<" student"<<endl;
                cin>>arr[i];
            }
        }
        void create_max_heap()
        {
            int temp ,i;
            for(int j=0;j<n;j++)
            {
                temp=arr[j];
                i=j;
                while(i>0 && temp>heap_max[(i-1)/2])
                {
                    // cout<<(i-1)/2<<endl;
                    heap_max[i]=heap_max[(i-1)/2];
                    i=(i-1)/2;
                }
                heap_max[i]=temp;
            }

        }
        void dis_max_heap()
        {
            cout<<" maximum heap result: "<<endl;
            for(int i=0; i<n;i++)
            {
                cout<<heap_max[i]<<" ";
            }
            cout<<endl;
        }
        void create_min_heap()
        {
            int temp,i;
            for(int j=0;j<n;j++)
            {
                temp=arr[j];
                i=j;
                while(i>0 && temp<heap_min[(i-1)/2])
                {
                    heap_min[i]=heap_min[(i-1)/2];
                    i=(i-1)/2;                 
                }
                heap_min[i]=temp;
            }

        }
        void dis_min_heap()
        {
            cout<<"minimum heap result: "<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<heap_min[i]<<" ";
            }
        }
};
int main()
{
    heap_datastr obj;
    obj.get();
    obj.create_max_heap();
    obj.dis_max_heap();
    obj.create_min_heap();
    obj.dis_min_heap();

}