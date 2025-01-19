import sympy as s
import math as m
import random

def generate_large_prime_numbers(b):
    prime1 = s.randprime(2**(b-1), 2**b)
    prime2 = s.randprime(2**(b-1), 2**b)
    return prime1, prime2

def keyGen(n):
    phiN = s.totient(n)
    print("ø(n) = ", phiN)
    e = random.randint(1, phiN)
    while(m.gcd(e, phiN) != 1):
        e = random.randint(1, phiN)
    return e  

def privateKey(n, e):
    phiN = s.totient(n) 
    d = s.mod_inverse(e, phiN)
    return d

def encryption(n, e, msg):
    m = []
    for ch in msg:
        if(ch != ' '):
            m.append(ord(ch)-65)
        else:
            m.append(' ')
    # m = int(m) 
    print("Message: ", m)   
    c = [pow(l, e, n) if l != ' ' else ' ' for l in m]
    return c

def decryption(n, d, msg):
    decrypt = [pow(l, d, n) if l != ' ' else ' ' for l in msg]
    print("Decrypted message", decrypt)
    msgd = ""
    for i in range(0, len(decrypt)):
        if(decrypt[i]!= ' '):
            msgd += chr(decrypt[i]+65)
        else:
            msgd += decrypt[i]    
    return msgd

b = int(input("Enter the bit size for RSA Key Generation: "))
p,q = generate_large_prime_numbers(b)
print("p: ", p, "\n\nq: ", q)
n = p*q

e = keyGen(n)
print("RSA Public Key ({pubE}, {N})".format(pubE = e, N =n))

d = privateKey(n, e)
print("RSA Private Key ({prD}, {N})".format(prD = d, N =n))

msg = input("Enter message: ").upper()
c = encryption(n, e, msg)
print("Encrypted Message: ", c)

d = decryption(n, d, c)
print("Decrypted Message: ", d)