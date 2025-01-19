import sympy as s

for i in s.primerange(1,100):
    print(i, end = ' ')

print("\nRandom Prime number in range 1-100: ", s.randprime(1,100))  
n = s.randprime(1,100)
print(n ,"is prime ?", s.isprime(n))