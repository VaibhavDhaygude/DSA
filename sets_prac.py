def get(sets,n):
    for i in range(n):
        element=input("enter element: ")
        sets.add(element)
def display(sets):
    print(sets)
def remove_element(sets):
    element=input("enter element to be removed")
    if element in sets:
        sets.remove(element)
        print(element," has been removed")
    else:
        print(element," is not present in set")
def search(sets):
    element=input("enter element to search in ")
    if element in sets:
        print(element," is present in set")
    else:
        print("element is not present in set")
def length(sets):
    print(len(sets))
def intersection(sets1,sets2):
    intersection_set=set.intersection(set(sets1),set(sets2))
    print("intersection of given sets is: ",intersection_set)
def union(sets1,sets2,sets3):
    sets3.update(sets1,sets2)
    print("union of given sets is: ",sets3)
def find_diff(sets1,sets2):
    print("set1 - set2 = ",sets1-sets2)
    print("set2 - set1 = ",sets2-sets1)
def find_subset(sets1,sets2):
    flag=0
    if sets1.issubset(sets2):
        flag=1
        print("set1 is subset of set2")
    if sets2.issubset(sets1):
        flag=1
        print("set2 is subset of set1")
    if flag==0:
        print("no subsets found")
    
    
 
def main():
    set1=set()
    set2=set()
    set3=set()
    n1=int(input("enter number of elements in set1"))
    get(set1,n1)
    n2=int(input("enter number of elements in set2"))
    get(set2,n2)
    print("SET1: ")
    display(set1)
    print("SET2: ")
    display(set2)
    print("for set1")
    remove_element(set1)
    print("for set2")
    remove_element(set2)
    print("SET1: ")
    display(set1)
    print("SET2: ")
    display(set2)
    print("for set1")
    search(set1)
    print("for set2")
    search(set2)
    print("length of set1 is: ")
    length(set1)
    print("length of set2 is: ")
    length(set2)
    intersection(set1,set2)
    union(set1,set2,set3)
    find_diff(set1,set2)
    find_subset(set1,set2)
main()
    
    
    
    
    
    
    
    
    