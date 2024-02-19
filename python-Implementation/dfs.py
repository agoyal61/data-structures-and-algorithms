
def dfs(g, src, vis=None):
    if vis is None:
        vis=set()
    vis.add(src)
    print(src)
    for nbr in g[src]:
        if nbr not in vis:
            dfs(g,nbr,vis)
    return vis


def dfs_iterative(g, src):
    vis = set()
    stack = [src]
    while stack:
        node = stack.pop()
        if node not in vis:
            vis.add(node)
            print(node)
            for nbr in g[node]:
                if nbr not in vis:
                    stack.append(nbr)
    return vis

if __name__ == "__main__":
    graph = {
        'A': ['B', 'C'],
        'B': ['A', 'D', 'E'],
        'C': ['A', 'F'],
        'D': ['B'],
        'E': ['B', 'F'],
        'F': ['C', 'E']
    }
    vis = dfs(graph, 'A')
    print(vis)

    print("Iterative DFS")
    vis = dfs_iterative(graph, 'A')
