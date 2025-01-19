n = int(input("Enter the integer group"))
for a in range(2, n):
    for i in range(n):
        print(a, "^", i, " mod ", n, " = ", (a**i)%n)