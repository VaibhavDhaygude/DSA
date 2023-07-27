class set_operations:
    flag=0
    def __init__(self,n,sets):
        
        for i in range(n):
            element=input("enter the element: ")
            sets.add(element)
        
    def remove_element(self,element,sets):
        sets.remove(element)
        print(element," has been removed")
    def search(self,element_s,sets):
        if element_s in sets:
            print(element_s ," is present in your set")
        else:
            print(element_s ," is not present in your set")
    def lenght(self,sets):
        print(len(sets))
    def display_set(self,sets):
        print(sets)
    def intersection(self,sets1,sets2):
        intersection_set=set.intersection(set(sets1),set(sets2))
        print("intersection of given set is: ",intersection_set)
    def union(self,sets1,sets2,sets3):
        sets3.update(sets1,sets2)
        print("union of given set is: ",sets3)
    def finddifference(self,sets1,sets2):
        print("set1-set2 is: ",sets1-sets2)
        print("set2-set1 is: ",sets2-sets1)
    def findsubset(self,sets1,sets2):
        
        if sets1.issubset(sets2):
            self.flag=1
            return True
        elif sets2.issubset(sets1):
            self.flag=2
            return True
        else:
            return False
            
        
def main():
    set1=set([])
    set2=set([])
    set3=set([])
    
    n1=int(input("enter the number of elements you want in your set1: "))
    s1=set_operations(n1,set1)
    print()
    n2=int(input("enter the number of elements you want in your set2: "))
    s1=set_operations(n2,set2)
    print()
    print("SET1: ")
    s1.display_set(set1)
    print()
    print("SET2: ")
    s1.display_set(set2)
    print()
    element=input("enter the element to remove in set1: ")
    s1.remove_element(element,set1)
    print()
    element=input("enter the element to remove in set2: ")
    s1.remove_element(element,set2)
    print()
    print("SET1: ")
    s1.display_set(set1)
    print()
    print("SET2: ")
    s1.display_set(set2)
    print()
    element_s=input("enter the element to search in set1: ")
    s1.search(element_s,set1)
    print()
    element_s=input("enter the element to search in set2: ")
    s1.search(element_s,set2)
    print()
    print("number of elements prsent in set1 is: ")
    s1.lenght(set1)
    print("number of elements prsent in set2 is: ")
    s1.lenght(set2)
    print()
    s1.intersection(set1,set2)
    print()
    s1.union(set1,set2,set3)
    print()
    s1.finddifference(set1,set2)
    print()
    check=s1.findsubset(set1,set2)
    if check==True and s1.flag==1:
        print("set1 is subset of set2")
    elif check==True and s1.flag==2:
        print("set2 is subset of set1")
    else :
        print("no subsets found")
main()


