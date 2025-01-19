import random


def objective_function(x):
    return -(x ** 2)  

MIN_VALUE = -10
MAX_VALUE = 10


STEP_SIZE = 0.1
MAX_ITERATIONS = 1000

# Hill climbing algorithm
def hill_climbing():
    current_solution = random.uniform(MIN_VALUE, MAX_VALUE)
    current_value = objective_function(current_solution)

    for _ in range(MAX_ITERATIONS):
        next_solution = current_solution + random.uniform(-STEP_SIZE, STEP_SIZE)
        next_solution = min(MAX_VALUE, max(MIN_VALUE, next_solution)) 

        next_value = objective_function(next_solution)

        if next_value > current_value:
            current_solution = next_solution
            current_value = next_value

    return current_solution, current_value


best_solution, best_value = hill_climbing()
print("Best solution:", best_solution)
print("Best value:", best_value)
