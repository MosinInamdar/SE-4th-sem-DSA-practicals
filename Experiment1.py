class HashTable:
    def __init__(self):
        self.max = 100
        self.arr = [[] for i in range(self.max)]

    def get_hash(self, key):
        h = 0
        for char in key:
            h += ord(char)
        return h % self.max

    def __getitem__(self, key):
        h = self.get_hash(key)
        for i in self.arr[h]:
            if i[0] == key:
                return i[1]

    def __setitem__(self, key, val):
        h = self.get_hash(key)
        found = False
        for idx, element in enumerate(self.arr[h]):
            if len(element) == 2 and element[0] == key:
                self.arr[h][idx] = (key, val)
                found = True
                break
        if not found:
            self.arr[h].append((key, val))

    def __delitem__(self, key):
        h = self.get_hash(key)
        for idx, element in enumerate(self.arr[h]):
            if element[0] == key:
                del self.arr[h][idx]

    def search(self, key, method='linear'):
        h = self.get_hash(key)
        comparisons = 0
        if method == 'linear':
            for i in range(self.max):
                comparisons += 1
                for j in self.arr[i]:
                    comparisons += 1
                    if j[0] == key:
                        return comparisons
        elif method == 'quadratic':
            for i in range(self.max):
                h_new = (h + i * i) % self.max
                comparisons += 1
                for j in self.arr[h_new]:
                    comparisons += 1
                    if j[0] == key:
                        return comparisons

        return comparisons

# Taking input from user
n = int(input("Enter the number of clients: "))
hash_table = HashTable()

for i in range(n):
    name = input("Enter client name: ")
    number = input("Enter client telephone number: ")
    hash_table[name] = number

# Searching for a specific telephone number
search_name = input("Enter client name to search: ")
method = input("Enter collision handling method (linear/quadratic): ")
comparisons = hash_table.search(search_name, method)

if comparisons > 0:
    print(f"Number of comparisons required: {comparisons}")
    print(f"{search_name}'s telephone number: {hash_table[search_name]}")
else:
    print(f"{search_name} not found in telephone book")
