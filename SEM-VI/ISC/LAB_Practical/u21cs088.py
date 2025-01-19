import random
import sympy
import numpy as np

def preprocessing(message):
    #blocks of 3
    message = message.upper()
    message = message + "Z"*(len(message)%3)
    messageP = [[] for i in range(len(message)//3)]
    k = 0
    for i in range(len(message)//3):
        for j in range(3):
            messageP[i].append(ord(message[k]) -65)    
            k+=1
    # print(messageP)  
    return messageP  

    pass

def encrypt(message, key):
    message = preprocessing(message)
    cipher = [[] for i in range(len(message))]
    j = 0
    for i in range(len(message)):
        cipher[i] = np.matmul(key, message[i])%26
        print(cipher[i])
    return cipher   
    pass


def decryption(cipher, inv_key):

    decrypt = [[] for i in range(len(cipher))]
    cipher = np.array(cipher)
    j = 0
    for i in range(len(cipher)):
        decrypt[i] = (np.matmul(inv_key, cipher[i])%26)
        
    decrypt = list(decrypt)
    for i in range(3):
        decrypt[i] = list(decrypt[i])
    decrypt_text = [[] for i in range(len(cipher))]
    for i in range(len(decrypt)):
        for j in range(3):
            decrypt_text[i].append(chr(round(decrypt[i][j])+65))

    decrypt_text = list(decrypt_text)
    for i in range(3):
        decrypt_text[i] = list(decrypt_text[i])       
    print("Decrypted", decrypt_text)   
    pass

    pass

def verify(key):
    keyDet = np.linalg.det(key)
    if(keyDet > 0 and keyDet == int(keyDet)):
        inv_keyDet = sympy.mod_inverse(keyDet, 26)
        if(int(inv_keyDet) >0):
            print("KeyDet \n", keyDet, "Inverse Det ", inv_keyDet)
            inv_key = np.linalg.inv(key)
            inv_key = inv_key*(keyDet)
            inv_key = inv_key*(inv_keyDet)
            inv_key = inv_key%(26)
            print("3, ",inv_key)

            return True
    else:
        return False    
   

def keyGen():
    key = [[random.randint(0,25) for i in range(3)] for i in range(3)]
    key = np.array(key)
    while(not verify(key)):
        key = [[random.randint(0,25) for i in range(3)] for i in range(3)]
        key = np.array(key)
    print("Key ",key)
    pass



message = input("Enter the message:")

print("Generating the key --")
# key = keyGen()
key = [[20, 13,  5],[ 9,  2,  2],[23, 19,  6]]
key = np.array(key)
inv_key = np.linalg.inv(key)
print("Encrypting the message -- ")
cipher = encrypt(message, key)
decryption(list(cipher), inv_key)
