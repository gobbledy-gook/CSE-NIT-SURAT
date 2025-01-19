global N
 
def printSolution(board):
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:
                print("Q",end=" ")
            else:
                print(".",end=" ")
        print()
 

def isSafe(board, row, col):
    # Check this row on left side
    for i in range(col):
        if board[row][i] == 1:
            return False
 
    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1),
                    range(col, -1, -1)):
        if board[i][j] == 1:
            return False
 
    # Check lower diagonal on left side
    for i, j in zip(range(row, N, 1),
                    range(col, -1, -1)):
        if board[i][j] == 1:
            return False
 
    return True
 
 
def place(board, col):
    if col >= N:
        return True
 

    for i in range(N):
        if isSafe(board, i, col):
            board[i][col] = 1
            if place(board, col + 1) == True:
                return True

            board[i][col] = 0
 
    return False
 
 

def solveNQ():
    board = [[0 for i in range(N)] for i in range(N)]
    if place(board, 0) == False:
        print("Solution does not exist")
        return False
    print("\nSolution -")
    printSolution(board)
    return True
 
 
N = int(input("Enter the size of the board: ")) 
solveNQ()