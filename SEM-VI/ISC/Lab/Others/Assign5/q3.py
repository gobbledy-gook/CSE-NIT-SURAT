import random
import numpy as np

def determinant_recursive(A, total=0):
    flag =1
    if np.linalg.det(A) == 0:
        flag = 0
    return flag

def encrypt(plain_text, key, n):
    ciphertext = ""

    # preprocessing and converting text to matrices
    messageMatrix = preprocessing(plain_text, key, n)

    cipherMatrix = []
    for k in range(len(messageMatrix)):
        m1 = [0 for i in range(n)]
        for i in range(n):
            for j in range(n):
                m1[i] += key[j][i]*messageMatrix[k][j]
            m1[i] = chr((m1[i]%26)+65)    
        cipherMatrix.append(''.join(m1))    


    print("Encrypted Matrix: ", cipherMatrix)
    return ''.join(cipherMatrix)

def preprocessing(plain_text, key, n):
    # removing spaces & paddding extra character if needed
    plain_text = ''.join(plain_text.split(' ')).upper()

    if(len(plain_text)%n != 0):
        plain_text+= 'X'*(len(plain_text)%n)

    # to convert message to column matrices
    messageMatrix = []

    for i in range(0, len(plain_text)-1, n):
        m2 = []
        for j in range(i,min(i+n, len(plain_text))):
            m2.append(ord(plain_text[j])-65)

        messageMatrix.append(m2)

    print("\nMessageMatrix -- ", messageMatrix)
    return messageMatrix

def decrypt(ciphertext, key, n):
    decrypttext = ""
    inverse_key = [0]
    while(np.linalg.det(inverse_key) == 0):
        inverse_key = list(np.linalg.inv(key))
        inverse_key = [i%26 for i in inverse_key]
    print("\nInverse Matrix\n", inverse_key)
    messageMatrix = preprocessing(ciphertext, inverse_key, n)
    decryptMatrix = []

    for k in range(len(messageMatrix)):
        m1 = [0 for i in range(n)]
        for i in range(n):
            for j in range(n):
                m1[i] += inverse_key[j][i]*messageMatrix[k][j]
            m1[i] = chr(int((m1[i]%26)+65))    
        decryptMatrix.append(''.join(m1))    


    # print("\nDecrypted Matrix: ", decryptMatrix)
    return ''.join(decryptMatrix)
    

def main():
    plain_text = input("Enter plain text message: ")
    flag = 0
    global key
    key= [] 
    n = random.randrange(2,6)
    print("N value is - ", n)
    while(not flag):
        key = [[random.randrange(0,26) for i in range(n)] for j in range(n)]
        flag = determinant_recursive(key)
    
    print("Key is: ", key)
    ciphertext = encrypt(plain_text, key, n)
    print("\nEncrypted Text: ", ciphertext)
    
    decrypttext = decrypt(ciphertext, key, n)
    print("Decrypted Text: ", decrypttext)

if __name__ == "__main__":
    main()

