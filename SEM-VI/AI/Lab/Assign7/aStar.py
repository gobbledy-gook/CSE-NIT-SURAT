import heapq

class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, node, neighbour, weight):
        if node not in self.graph:
            self.graph[node] = []
        self.graph[node].append((neighbour, weight))

    def a_star(self, start, goal):
        open_set = [(0, start)]
        came_from = {}
        g_score = {node: float('inf') for node in self.graph}
        g_score[start] = 0
        f_score = {node: float('inf') for node in self.graph}
        f_score[start] = self.heuristic(start, goal)

        while open_set:
            current_cost, current_node = heapq.heappop(open_set)
            if current_node == goal:
                path = []
                while current_node in came_from:
                    path.append(current_node)
                    current_node = came_from[current_node]
                path.append(start)
                return path[::-1], current_cost

            for neighbour, weight in self.graph[current_node]:
                tentative_g_score = g_score[current_node] + weight
                print("--> ",current_node[1], neighbour[1], tentative_g_score)
                if tentative_g_score < g_score[neighbour]:
                    came_from[neighbour] = current_node
                    g_score[neighbour] = tentative_g_score
                    f_score[neighbour] = tentative_g_score + self.heuristic(neighbour, goal)
                    heapq.heappush(open_set, (f_score[neighbour], neighbour))

        return None

    def heuristic(self, node, goal):
        # Example heuristic: Manhattan distance
        return abs(node[0] - goal[0])

# Example usage:
if __name__ == "__main__":
    graph = Graph()
    graph.add_edge((10, 'A'), (8,'B'), 6)
    graph.add_edge((10, 'A'), (6,'F'), 3)
    graph.add_edge((8,'B'), (10, 'A'), 6)
    graph.add_edge((8,'B'), (7,'D'), 2)
    graph.add_edge((8,'B'), (5,'C'), 3)
    graph.add_edge((5,'C'), (8,'B'), 3)
    graph.add_edge((5,'C'), (7,'D'), 1)
    graph.add_edge((5,'C'), (3,'E'), 5)
    graph.add_edge((7,'D'), (8,'B'), 2)
    graph.add_edge((7,'D'), (5,'C'), 1)
    graph.add_edge((7,'D'), (3,'E'), 8)
    graph.add_edge((3,'E'), (5,'C'), 5)
    graph.add_edge((3,'E'), (0,'J'), 5)
    graph.add_edge((3,'E'), (7,'D'), 8)
    graph.add_edge((3,'E'), (1,'I'), 5)
    graph.add_edge((0,'J'), (3,'E'), 5)
    graph.add_edge((0,'J'), (1,'I'), 3)
    graph.add_edge((1,'I'), (5,'G'), 3)
    graph.add_edge((1,'I'), (3,'H'), 2)
    graph.add_edge((1,'I'), (3,'E'), 5)
    graph.add_edge((1,'I'), (0,'J'), 3)
    graph.add_edge((5,'G'), (1,'I'), 3)
    graph.add_edge((5,'G'), (6,'F'), 1)
    graph.add_edge((3,'H'), (1,'I'), 2)
    graph.add_edge((3,'H'), (6,'F'), 7)
    graph.add_edge((6,'F'), (5,'G'), 1)
    graph.add_edge((6,'F'), (3,'H'), 7)
    graph.add_edge((6,'F'), (10, 'A'), 3)

    start = (10,'A')
    goal = (0,'J')
    path, pathCost = graph.a_star(start, goal)

    if path:
        print("Shortest path found:", path)
        hCost = 0
        for i in path:
            hCost += i[0]
        print("Total Path Cost", pathCost+hCost)

    else:
        print("No path found")
