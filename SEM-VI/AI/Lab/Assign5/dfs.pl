% Define the edges between nodes
edge(0, 1).
edge(0, 2).
edge(0, 6).
edge(1, 2).
edge(1, 0).
edge(1, 3).
edge(2, 0).
edge(2, 1).
edge(2, 6).
edge(2, 4).
edge(2, 3).
edge(3, 2).
edge(3, 1).
edge(3, 4).
edge(3, 5).
edge(4, 2).
edge(4, 3).
edge(4, 5).
edge(4, 6).
edge(5, 3).
edge(5, 4).
edge(5, 6).
edge(6, 0).
edge(6, 2).
edge(6, 4).
edge(6, 5).

% Define the neighbour relationship
neighbour(U, V) :- edge(U, V).

% Perform depth-first search traversal
dfs(Start, Visited) :-
    dfs_helper(Start, [], Visited).

dfs_helper(Node, VisitedSoFar, Visited) :-
    \+ member(Node, VisitedSoFar),  % Ensure Node is not already visited
    dfs_neighbours(Node, [Node|VisitedSoFar], Visited).

dfs_helper(_, Visited, Visited).  % Base case: All reachable nodes visited

% Determine neighbors of a node and update the visited list
dfs_neighbours(Node, VisitedSoFar, Visited) :-
    findall(Neighbor, (neighbour(Node, Neighbor), \+ member(Neighbor, VisitedSoFar)), Neighbors),
    dfs_visit_neighbors(Neighbors, VisitedSoFar, Visited).

% Visit neighbors of a node and update the visited list
dfs_visit_neighbors([], Visited, Visited).
dfs_visit_neighbors([Neighbor|Rest], VisitedSoFar, Visited) :-
    dfs_helper(Neighbor, VisitedSoFar, TempVisitedSoFar),
    dfs_visit_neighbors(Rest, TempVisitedSoFar, Visited).