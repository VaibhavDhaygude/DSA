a=[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]
size=10
print(a)
def qp():
    cnt=0
    ans=1
    while(ans==1):
        key=int(input("enter the element you want to insert: "))
        loc_n=key%size
        flag=0
        i=1
        loc=loc_n #loc_n is used for maintain first positioned of the key ex. for key=21 loc_n=1
        while(flag==0 and cnt<=size):
            if(a[loc]==-1):
                a[loc]=key
                flag=1
                cnt=cnt+1
                break
            else:
                loc=(loc_n+(i*i))%size
                i=i+1
        ans=int(input("do you want to continue(1/0)?"))
    print(a)
    print("number of elements present in hash table is: ",cnt)
qp()
def search():
    key=int(input("enter the element you want to search: "))
    loc_n=key%size
    flag=0
    loc=loc_n
    i=1
    while(flag==0):
        
        if(a[loc]==key):
            flag=1
            print(key," is present in the hashtable")
            break
        elif(a[loc]==-1):
            print(key," is not present in the hashtable")
            flag=1
            break
        else:
            loc=(loc_n+(i*i))%size
            i=i+1
search()