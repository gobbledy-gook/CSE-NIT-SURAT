# Design and implement a program to perform encryption and decryption
# using the Vigenère Cipher with repeating keywords. Consider the following
# inputs for the program.

def encryption(message, key):
    ciphertext = ""
    j = 0
    for i in message:
        if i != ' ':
            ciphertext += chr( (((ord(i) - 65 ) + (ord(key[j])-65))%26)+65)
            j = (j+1)%len(key)  
        else:
            ciphertext += ' '      
    return ciphertext

def decryption(ciphertext, key):
    decryptedtext = ""
    j = 0
    for i in ciphertext:
        if i != ' ':
            decryptedtext += chr( (((ord(i) - 65 ) - (ord(key[j])-65))%26)+65)
            j = (j+1)%len(key)  
        else:
            decryptedtext += ' '      
    return decryptedtext



f1 = open("/Users/garvitshah/Desktop/College/VI/ISC/Lab/Assign6/input.txt", "r+")
f2 = open("/Users/garvitshah/Desktop/College/VI/ISC/Lab/Assign6/key.txt", "r+")
message = ''.join(f1.readlines()).upper()
key = ''.join(f2.readlines()).upper()
print("Message is ->\n", message)
print("\nKey is ->\n", key)

#Encryption
ciphertext = encryption(message, key)
print("\nCipherText is ->\n", ciphertext)

#Decryption
decryptedtext = decryption(ciphertext, key)
print("\nDecryptedText is ->\n", decryptedtext)