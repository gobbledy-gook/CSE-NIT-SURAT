# Design and implement a program to perform encryption and decryption
# using the One time pad. Consider the following inputs for the program.

import random

def encryption(message, key):
    ciphertext = ""
    j = 0
    for i in message:
        if i != ' ':
            c1 = hex( (ord(i) - 65 ) ^ (ord(key[j])-65))[2:]
            if(len(c1) == 1):
                c2 = '0'+c1
                ciphertext += c2
            else:
                ciphertext+=c1        
            j+=1       
        else:
            ciphertext += ' '  
    return ciphertext

def decryption(ciphertext, key):
    # return encryption(ciphertext, key)
    decrypt = ""
    j = 0
    i = 0
    while( i < len(ciphertext)-1):
        if ciphertext[i] != ' ' and ciphertext[i+1] != ' ':
            decrypt += chr( (((int(ciphertext[i:i+2], 16)) ^ (ord(key[j])-65))%26)+65) 
            j+=1       
        else:
            if(ciphertext[i] == ' '):
                i = i-1
            decrypt += ' ' 
        i+=2     
    return decrypt   


f1 = open("/Users/garvitshah/Desktop/College/VI/ISC/Lab/Assign6/input.txt", "r+")

message = ''.join(f1.readlines()).upper()
key = ''.join([chr(random.randint(0,25)+65).upper() for i in range(len(message))])
print("Message is ->\n", message)
print("\nKey is ->\n", key)

#Encryption
ciphertext = encryption(message, key)
print("\nCipherText is ->\n", ciphertext)

#Decryption
decryptedtext = decryption(ciphertext, key)
print("\nDecryptedText is ->\n", decryptedtext)