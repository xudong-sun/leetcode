'''
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
'''


from structs.undirected_graph import generate_graph, UndirectedGraphNode

class Solution:
    def cloneGraph(self, node):
        if node is None: return None
        mappings = {}
        def walk(node):
            new_node = UndirectedGraphNode(node.label)
            mappings[node] = new_node
            for n in node.neighbors:
                if n not in mappings: walk(n)
                new_node.neighbors.append(mappings[n])
        walk(node)
        return mappings[node]

if __name__ == '__main__':
    g = generate_graph(3, [(0,1), (0,2), (1,2), (2,2)])
    print Solution().cloneGraph(g)
    g = generate_graph(1, [(0,0)])
    print Solution().cloneGraph(g)
    g = generate_graph(1, [])
    print Solution().cloneGraph(g)
    g = generate_graph(0, [])
    print Solution().cloneGraph(g)

