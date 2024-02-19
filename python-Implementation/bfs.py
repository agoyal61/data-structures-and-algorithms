from collections import deque

def bfs(g,start):
    vis=set()
    # visited = [False] * (max(self.graph) + 1)
    q=deque([start])
    vis.add(start)
    while q:
        node=q.popleft()
        print(node,end=' ')
        for nbr in g[node]:
            if nbr not in vis:
                q.append(nbr)
                vis.add(nbr)
    return vis

g={
    0:[1,2],
    1:[0,3,4],
    2:[0,4],
    3:[1],
    4:[1,2]
}
bfs(g,0)