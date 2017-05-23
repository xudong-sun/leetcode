class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []
    def __str__(self):
        all_nodes = []
        all_edges = []
        visited = set()
        def walk(node):
            visited.add(node)
            all_nodes.append(node)
            for n in node.neighbors:
                if node.label <= n.label: all_edges.append((node, n))
                if n not in visited: walk(n)
        walk(self)
        s1 = ', '.join([str(node.label) for node in all_nodes])
        s2 = 'None' if len(all_edges) == 0 else '<' + '>, <'.join([str(n1.label) + ', ' + str(n2.label) for n1,n2 in all_edges]) + '>'
        return 'nodes: ' + s1 +'\nedges: ' + s2

def generate_graph(num_nodes, edges):
    if num_nodes == 0: return None
    nodes = [UndirectedGraphNode(i) for i in xrange(num_nodes)]
    for i1, i2 in edges:
        nodes[i1].neighbors.append(nodes[i2])
        if i1 != i2: nodes[i2].neighbors.append(nodes[i1])
    return nodes[0]

