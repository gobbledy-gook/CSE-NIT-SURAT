from collections import defaultdict

class Graph:
	def __init__(self):
		self.graph = defaultdict(list)
		
	def addEdge(self, u, v):
		self.graph[u].append(v)


	def BFS(self, s):
		visited = [False] * 6

		queue = []
		queue.append(s)
		visited[s] = True

		while queue:
			s = queue.pop(0)
			print(s, end=" ")
			for i in self.graph[s]:
				if visited[i] == False:
					queue.append(i)
					visited[i] = True


# Driver code
if __name__ == '__main__':
	g = Graph()
	g.addEdge(0, 1)
	g.addEdge(0, 2)
	g.addEdge(1, 3)
	g.addEdge(1, 4)
	g.addEdge(2, 5)
	g.addEdge(4, 5)


	print("Following is Breadth First Traversal"
		" (starting from vertex 0)")
	g.BFS(0)



