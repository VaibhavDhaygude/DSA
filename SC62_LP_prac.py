a=[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]
size=10
print(a)
def lp():
    cnt=0
    ans=1
    while(ans==1):
        if(cnt==size):
            print("hashtable is already full")
            print(a)
            print("number of elements present in hash table is: ",cnt)
            return
        key=int(input("enter the element you want to insert: "))
        loc=key%size
        flag=0
       
        while(flag==0 and cnt<size):
            if(a[loc]==-1):
                a[loc]=key
                flag=1
                cnt=cnt+1
                break
            else:
                loc=(loc+1)%size
        ans=int(input("do you want to continue(1/0)?"))
    print(a)
    print("number of elements present in hash table is: ",cnt)

def search():
    key=int(input("enter the element you want to search: "))
    loc=key%size
    flag=0
    cnt=0
    while(flag==0):
        
        if(a[loc]==key):
            flag=1
            print(key," is present in the hashtable")
            break
        elif(a[loc]==-1 or cnt>size):
            print(key," is not present in the hashtable")
            flag=1
            break
        else:
            cnt=cnt+1
            loc=(loc+1)%size

lp()        
search()