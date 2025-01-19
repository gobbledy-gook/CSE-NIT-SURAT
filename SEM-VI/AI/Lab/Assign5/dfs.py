from collections import defaultdict

class Graph:
	def __init__(self):
		self.graph = defaultdict(list)

	def addEdge(self, u, v):
		self.graph[u].append(v)

	def DFSUtil(self, v, visited):

		visited.add(v)
		print(v, end=' ')
		for neighbour in self.graph[v]:
			if neighbour not in visited:
				self.DFSUtil(neighbour, visited)


	def DFS(self, v):

		visited = set()
		self.DFSUtil(v, visited)


# Driver's code
if __name__ == "__main__":
	g = Graph()
	g.addEdge(0, 1)
	g.addEdge(0, 2)
	g.addEdge(0, 6)
	g.addEdge(1, 2)
	g.addEdge(1, 0)
	g.addEdge(1, 3)
	g.addEdge(2, 0)
	g.addEdge(2, 1)
	g.addEdge(2, 6)
	g.addEdge(2, 4)
	g.addEdge(2, 3)
	g.addEdge(3, 2)
	g.addEdge(3, 1)
	g.addEdge(3, 4)
	g.addEdge(3, 5)
	g.addEdge(4, 2)
	g.addEdge(4, 3)
	g.addEdge(4, 5)
	g.addEdge(4, 6)
	g.addEdge(5, 3)
	g.addEdge(5, 4)
	g.addEdge(5, 6)
	g.addEdge(6, 0)
	g.addEdge(6, 2)
	g.addEdge(6, 4)
	g.addEdge(6, 5)

	print("Following is Depth First Traversal (starting from vertex 2)")
	
	g.DFS(0)


