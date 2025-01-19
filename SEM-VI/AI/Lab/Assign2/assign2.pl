% assign2.pl

male(shankar).
male(ulhas).
male(satish).
male(saurabh).
male(prashant).
female(umabai).
female(mrunal).
female(sadhana).
female(swati).
parent(shankar,umabai,ulhas).
parent(shankar,umabai,satish).
parent(ulhas,mrunal,prashant).
parent(satish,sadhana,saurabh).
parent(satish,sadhana,swati).
brother(ulhas,satish).
brother(satish,ulhas).
brother(prashant,saurabh).
brother(saurabh,prashant).
sister(swati,saurabh).
sister(swati,prashant).

son(X, Y, M):- parent(X, Y, M), male(M).
daughter(X, Y, M):- parent(X, Y, M), female(M).
child(X,Y, M):- parent(X, Y,M).
father(X, M):- parent(X,_,M), male(X).
mother(X, M):- parent(_,X,M), female(X).
grandparent(X,M):- parent(X,Y,N), father(N,M);mother(N,M). 
