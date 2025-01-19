import sympy as s

def euler_totient(n):
    return s.totient(n)

def generate_large_prime_numbers():
    prime1 = s.randprime(2**(1021-1), 2**1021)
    prime2 = s.randprime(2**(1021-1), 2**1021)
    return prime1, prime2

p,q = generate_large_prime_numbers()


number = 15
phi = euler_totient(number)
print(f"Euler's totient function for {number} is {phi}")
rsaModN = p*q
rsaModphi = s.totient(p)*s.totient(q)
print("RSA Modulus N: ", rsaModN)
print("RSA Modulus Phi: ", rsaModphi)