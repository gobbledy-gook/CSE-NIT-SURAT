edge(a,b,12).
edge(a,c,10).
edge(a,g,12).
edge(b,c,8).
edge(c,g,9).
edge(b,d,12).
edge(c,d,11).
edge(c,e,3).
edge(g,e,7).
edge(e,d,11).
edge(g,f,9).
edge(e,f,6).
edge(d,f,10).

edge(b,a,12).
edge(c,a,10).
edge(g,a,12).
edge(c,b,8).
edge(g,c,9).
edge(d,b,12).
edge(d,c,11).
edge(e,c,3).
edge(e,g,7).
edge(d,e,11).
edge(f,g,9).
edge(f,e,6).
edge(f,d,10).
len([], 0).
len([H|T], N):- len(T, X), N is X+1 .


best_path(Visited, Total):- 
    path(a, a, Visited, Total).


path(Start, Fin, Visited, Total) :- 
    path(Start, Fin, [Start], Visited, 0, Total).


path(Start, Fin, CurrentLoc, Visited, Costn, Total) :-
    edge(Start, StopLoc, Distance), 
    NewCostn is Costn + Distance, 
    \+ member(StopLoc, CurrentLoc),
    path(StopLoc, Fin, [StopLoc|CurrentLoc], Visited, NewCostn, Total). 


path(Start, Fin, CurrentLoc, Visited, Costn, Total) :-
    edge(Start, Fin, Distance), 
    reverse([Fin|CurrentLoc], Visited), len(Visited, Q),
    (Q\=8 -> Total is 100000; Total is Costn + Distance).


shortest_path(Path):-
    setof(Cost-Path, best_path(Path,Cost), Holder),
    pick(Holder,Path).


best(Cost-Holder,Bcost-_,Cost-Holder):- Cost<Bcost, !.
best(_,X,X).

pick([Cost-Holder|R],X):- pick(R,Bcost-Bholder),best(Cost-Holder,Bcost-Bholder,X),!.
pick([X],X).