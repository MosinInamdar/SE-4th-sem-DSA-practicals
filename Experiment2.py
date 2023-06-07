class SetADT:
    def __init__(self):
        self.items = []

    def add(self, item):
        if item not in self.items:
            self.items.append(item)

    def remove(self, item):
        if item in self.items:
            self.items.remove(item)

    def contains(self, item):
        return item in self.items

    def size(self):
        return len(self.items)

    def iterator(self):
        return iter(self.items)

    def subset(self, other_set):
        for item in self.items:
            if not other_set.contains(item):
                return False
        return True

    def intersection(self, other_set):
        intersection_set = SetADT()
        for item in self.items:
            if other_set.contains(item):
                intersection_set.add(item)
        return intersection_set

    def difference(self, other_set):
        difference_set = SetADT()
        for item in self.items:
            if not other_set.contains(item):
                difference_set.add(item)
        return difference_set

    def union(self, other_set):
        union_set = SetADT()
        union_set.items = self.items[:]
        for item in other_set.items:
            if not self.contains(item):
                union_set.items.append(item)
        return union_set


# Take user input for first set
set1 = SetADT()
n1 = int(input("Enter the number of elements in set 1: "))
print("Enter the elements of set 1: ")
for i in range(n1):
    set1.add(input())

# Take user input for second set
set2 = SetADT()
n2 = int(input("Enter the number of elements in set 2: "))
print("Enter the elements of set 2: ")
for i in range(n2):
    set2.add(input())

# Use switch case for set operations
while True:
    print("Enter 1 to add an element to set 1")
    print("Enter 2 to add an element to set 2")
    print("Enter 3 to remove an element from set 1")
    print("Enter 4 to remove an element from set 2")
    print("Enter 5 to check if an element is in set 1")
    print("Enter 6 to check if an element is in set 2")
    print("Enter 7 to get the size of set 1")
    print("Enter 8 to get the size of set 2")
    print("Enter 9 to iterate over set 1")
    print("Enter 10 to iterate over set 2")
    print("Enter 11 to get the intersection of set 1 and set 2")
    print("Enter 12 to get the difference between set 1 and set 2")
    print("Enter 13 to get the union of set 1 and set 2")
    print("Enter 14 to check if set 1 is a subset of set 2")
    print("Enter 15 to check if set 2 is a subset of set 1")
    print("Enter 0 to exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        element = input("Enter the element to be added to set 1: ")
        set1.add(element)
        print(f"{element} added to set 1")
    elif choice == 2:
        element = input("Enter the element to be added to set 2: ")
        set2.add(element)
        print(f"{element} added to set 2")
    elif choice == 3:
        element = input("Enter the element to be removed from set 1")
        set1.remove(element)
        print(f"{element} removed from set 1")
    elif choice == 4:
        element = input("Enter the element to be removed from set 2")
        set2.remove(element)
        print(f"{element} removed from set 2")
    elif choice == 5:
        if set1.contains(element):
            print(f"{element} is in set 1")
        else:
            print(f"{element} is not in set 1")
    elif choice == 6:
        element = input("Enter the element to be checked in set 2: ")
        if set2.contains(element):
            print(f"{element} is in set 2")
        else:
            print(f"{element} is not in set 2")
    elif choice == 7:
        print(f"Size of set 1 is {set1.size()}")
    elif choice == 8:
        print(f"Size of set 2 is {set2.size()}")
    elif choice == 9:
        print("Elements of set 1 are: ")
        for element in set1.iterator():
            print(element)
    elif choice == 10:
        print("Elements of set 2 are: ")
        for element in set2.iterator():
            print(element)
    elif choice == 11:
        intersection_set = set1.intersection(set2)
        print("Intersection of set 1 and set 2 is: ")
        for element in intersection_set.iterator():
            print(element)
    elif choice == 12:
        difference_set = set1.difference(set2)
        print("Difference between set 1 and set 2 is: ")
        for element in difference_set.iterator():
            print(element)
    elif choice == 13:
        union_set = set1.union(set2)
        print("Union of set 1 and set 2 is: ")
        for element in union_set.iterator():
            print(element)
    elif choice == 14:
        if set1.subset(set2):
            print("Set 1 is a subset of set 2")
        else:
            print("Set 1 is not a subset of set 2")
    elif choice == 15:
        if set2.subset(set1):
            print("Set 2 is a subset of set 1")
        else:
            print("Set 2 is not a subset of set 1")
    elif choice == 0:
        print("Exiting program")
        break
    else:
        print("Invalid choice")
