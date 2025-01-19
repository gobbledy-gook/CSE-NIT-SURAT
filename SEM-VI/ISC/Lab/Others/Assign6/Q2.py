# Design and implement a program to perform encryption and decryption
# using the Vigenère Cipher with a running key (key is as long as plaintext).
# Consider the following inputs for the program.
import random


def encryption(message, key):
    ciphertext = ""
    j = 0
    for i in message:
        if i != ' ':
            ciphertext += chr( (((ord(i) - 65 ) + (ord(key[j])-65))%26)+65)
        else:
            ciphertext += ' ' 
        j +=1         
    return ciphertext

def decryption(ciphertext, key):
    decryptedtext = ""
    j = 0
    for i in ciphertext:
        if i != ' ':
            decryptedtext += chr( (((ord(i) - 65 ) - (ord(key[j])-65))%26)+65)
        else:
            decryptedtext += ' ' 
        j +=1          
    return decryptedtext



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