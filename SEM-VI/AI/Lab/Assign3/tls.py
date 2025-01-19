n = 4  # there are four nodes in example graph (graph is 1-based)
dist = [[0, 0, 0, 0, 0], [0, 0, 10, 15, 20], [
    0, 10, 0, 25, 25], [0, 15, 25, 0, 30], [0, 20, 25, 30, 0]]

# memoization for top down recursion
memo = [[-1]*(1 << (n+1)) for _ in range(n+1)]


def fun(i, mask):
    # base case
    if mask == ((1 << i) | 3):
        return dist[1][i], [1, i]

    # memoization
    if memo[i][mask] != -1:
        return memo[i][mask]

    res = 10**9  # result of this sub-problem
    path = []

    for j in range(1, n+1):
        if (mask & (1 << j)) != 0 and j != i and j != 1:
            cost, p = fun(j, mask & (~(1 << i)))  # recursively find cost and path
            cost += dist[j][i]
            if cost < res:
                res = cost
                path = [j] + p  # update path
    memo[i][mask] = (res, path)  # storing the minimum value and path
    return res, path


# Driver program to test above logic
ans_cost, ans_path = float('inf'), []
for i in range(1, n+1):
    cost, path = fun(i, (1 << (n+1))-1)
    cost += dist[i][1]
    if cost < ans_cost:
        ans_cost = cost
        ans_path = [i] + path  # update path

print("The cost of most efficient tour =", ans_cost)
print("The path of most efficient tour =", ans_path)



