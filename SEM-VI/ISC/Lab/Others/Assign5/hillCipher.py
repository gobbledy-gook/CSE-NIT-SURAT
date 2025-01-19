def encrypt(plain_text, key):
    ciphertext = ""

    # preprocessing and converting text to matrices
    messageMatrix = preprocessing(plain_text, key)

    cipherMatrix = []
    for k in range(len(messageMatrix)):
        m1 = [0 for i in range(2)]
        for i in range(2):
            for j in range(2):
                m1[i] += key[j][i]*messageMatrix[k][j]
            m1[i] = chr((m1[i]%26)+65)    
        cipherMatrix.append(''.join(m1))    


    print("Encrypted Matrix: ", cipherMatrix)
    return ''.join(cipherMatrix)

def preprocessing(plain_text, key):
    # removing spaces & paddding extra character if needed
    plain_text = ''.join(plain_text.split(' ')).upper()

    if(len(plain_text)%2 != 0):
        plain_text+= 'X'

    # to convert message to column matrices
    messageMatrix = []

    for i in range(0, len(plain_text)-1, 2):
        messageMatrix.append([ord(plain_text[i])-65, ord(plain_text[i+1])-65])

    print(messageMatrix)
    return messageMatrix

def decrypt(ciphertext, key):
    decrypttext = ""
    inverse_key = [[15,20],[17,9]]

    messageMatrix = preprocessing(ciphertext, inverse_key)
    decryptMatrix = []

    for k in range(len(messageMatrix)):
        m1 = [0 for i in range(2)]
        for i in range(2):
            for j in range(2):
                m1[i] += inverse_key[j][i]*messageMatrix[k][j]
            m1[i] = chr((m1[i]%26)+65)    
        decryptMatrix.append(''.join(m1))    


    print("\nDecrypted Matrix: ", decryptMatrix)
    return ''.join(decryptMatrix)
    

def main():
    plain_text = input("Enter plain text message: ")
    key = [[3,2],[3,5]]
    
    ciphertext = encrypt(plain_text, key)
    print("\nEncrypted Text: ", ciphertext)
    
    decrypttext = decrypt(ciphertext, key)
    print("Decrypted Text: ", decrypttext)

if __name__ == "__main__":
    main()

