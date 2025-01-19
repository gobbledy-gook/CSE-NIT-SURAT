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

% Perform breadth-first search traversal
bfs(Start, Visited) :-
    bfs_helper([Start], [], [], Visited).

% Base case: All reachable nodes visited
bfs_helper([], _, Visited, Visited).

% Perform BFS traversal from the current level
bfs_helper(CurrentLevel, VisitedSoFar, CurrentVisited, Visited) :-
    next_level(CurrentLevel, VisitedSoFar, CurrentVisited, NextLevel),
    append(CurrentVisited, NextLevel, NewVisited),  % Add NextLevel to CurrentVisited
    bfs_helper(NextLevel, VisitedSoFar, NewVisited, Visited).   % Recursively traverse NextLevel

% Determine the next level of nodes to visit
next_level([], _, _, []).
next_level([Node|Rest], VisitedSoFar, CurrentVisited, NextLevel) :-
    findall(Neighbor, (
        neighbour(Node, Neighbor),
        \+ member(Neighbor, VisitedSoFar),            % Ensure Neighbor hasn't been visited so far
        \+ member(Neighbor, CurrentVisited),          % Ensure Neighbor hasn't been visited in the current level
        \+ member(Neighbor, Rest)                    
    ), Neighbors),
    next_level(Rest, VisitedSoFar, CurrentVisited, OtherNeighbors),
    append(Neighbors, OtherNeighbors, NextLevel).

