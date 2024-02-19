# implementation of disjoint set with path compression and union by rank.
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        # self.parent=[i for i in range(n)]
        self.rank = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x_root = self.find(x)
        y_root = self.find(y)
        if x_root == y_root:
            return
        if self.rank[x_root] < self.rank[y_root]:
            x_root, y_root = y_root, x_root
        self.parent[y_root] = x_root
        if self.rank[x_root] == self.rank[y_root]:
            self.rank[x_root] += 1

    def is_connected(self, x, y):
        return self.find(x) == self.find(y)

    def __repr__(self):
        return f"UnionFind({self.parent})"

obj = UnionFind(5)
obj.union(0, 2)
obj.union(4, 2)
obj.union(3, 1)
if obj.find(4) == obj.find(0):
    print('Yes')
else:
    print('No')

 