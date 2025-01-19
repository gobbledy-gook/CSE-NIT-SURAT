def utility(state):
	for row in state:
		if (row[0] == row[1]) and (row[0] == row[2]) and (row[0] != -1):
			if (row[0] == 1):
				return 1 # WIN
			else:
				return -1 # LOSS
	
	for i in range(0, len(state)):
		if (state[0][i] == state[1][i]) and (state[0][i] == state[2][i]) and (state[0][i] != -1):
			if state[0][i] == 1:
				return 1 # WIN
			else:
				return -1 # LOSS

	# checking diagonals:
	if (((state[0][0] == state[1][1]) and (state[0][0] == state[2][2])) or ((state[2][0] == state[1][1]) and (state[2][0] == state[0][2]))) and (state[1][1] != -1):
		if state[1][1] == 1:
			return 1 # WIN
		else:
			return -1 # LOSS
	
	# if no three-in-a-row, check if all are filled
	unfilledFlag = 0
	for row in state:
		for elem in row:
			if elem == -1:
				unfilledFlag = 1

	if unfilledFlag == 0:
		return 0 # DRAW
	
	# if none of the above, this is not a terminal state
	return -2
	

# CHECK IF END HAS BEEN REACHED 
def terminalTest(state):
	utilityTest = utility(state)
	if utilityTest != -2:
		return True
	else:
		return False

# GETS THE SET OF ACTIONS POSSIBLE FOR THIS STATE
def actions(state):
	zeroCount = 0
	oneCount = 0
	nextPly = -1
	possibleMoves = []
	for i in range(0, len(state)):
		for j in range(0, len(state)):
			if state[i][j] == 0:
				zeroCount+=1
			elif state[i][j] == 1:
				oneCount+=1
			else:
				possibleMoves.append([i, j])
	
	# assuming 1 always plays first (without loss of generality)
	if(zeroCount == oneCount):
		# one's turn
		nextPly = 1
	else:
		nextPly = 0

	for move in possibleMoves:
		move.append(nextPly)

	return possibleMoves
	
# GETS THE RESULT OF PERFORMING AN ACTION ON A STATE
def result(stateIn, action):
	#print("inside result")
	state = [ i for i in stateIn ]
	# action is a list of three things: i, j, player(1 or 0)

	state[action[0]][action[1]] = action[2]

	return state


def minimaxDecision(stateIn):
	#print("in minimax decision")
	state = stateIn
	listOfMinValues = []
	bestVal = float('-inf')
	bestAction = []
	
	for a in actions(state):
		stateTemp = []
		for i in range(0, len(state)):
			stateTemp.append([])
			for j in range(0, len(state)):
				stateTemp[i].append(state[i][j])

		val = minValue(result(stateTemp, a))
		
		if val > bestVal:
			bestVal = val
			bestAction = a
	
	#for row in state:
	#		print("\n")
	#		for elem in row:
	#			print(elem, "\t", end='')

	return bestAction
	

def maxValue(stateIn):
	#print("in maxvalue")
	state = stateIn
	if terminalTest(state):
		return utility(state)
	
	v = float('-inf')	
	possibleActions = actions(state)

	for a in possibleActions:
		
		stateTemp = []
		for i in range(0, len(state)):
			stateTemp.append([])
			for j in range(0, len(state)):
				stateTemp[i].append(state[i][j])

		v = max(v, minValue(result(stateTemp, a)))
	return v


def minValue(stateIn):
	#print("in minvalue")
	state = stateIn
	if terminalTest(state):
		return utility(state)
		
	v = float('+inf')
	
	possibleActions = actions(state)
	for a in possibleActions:
		
		stateTemp = []
		for i in range(0, len(state)):
			stateTemp.append([])
			for j in range(0, len(state)):
				stateTemp[i].append(state[i][j])

		v = min(v, maxValue(result(stateTemp, a)))
	return v

def gameBegins():
	print("Lets Play Tic-Tac-Toe?\n")
	
	gameBoard = [[-1, -1, -1], [-1, -1, -1], [-1, -1, -1]]

	while(utility(gameBoard) == -2):
		# AI Makes it's move
		copyBoard = [ i for i in gameBoard ]
		#curAction = minimaxDecision(copyBoard)
		#result(gameBoard, curAction)
		gameBoard = result(gameBoard, minimaxDecision(copyBoard))

		for row in gameBoard:
			print("\n")
			for elem in row:
				print(elem, "\t", end='')

		if(utility(gameBoard) != -2):
			#print("hello")
			break

		# Now the Human's turn
		inputCoordinates = input("enter row and column here: ")
		# Splitting the input string by space
		inputCoordinates = inputCoordinates.split()

		# Converting each element to integer using list comprehension
		numbers = [int(num) for num in inputCoordinates]
		
		gameBoard[numbers[0]][numbers[1]] = 0

		
	if utility(gameBoard) == 1:
		print("Game Over: Looks like I won!")
	elif utility(gameBoard) == -1:
		print("Congratulations, You won!")
	else:
		print("Good game, partner. Looks like a draw")


gameBegins()

	

				
	


