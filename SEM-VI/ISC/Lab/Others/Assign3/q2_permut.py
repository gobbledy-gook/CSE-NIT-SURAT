def encrypt_permutation_cipher(plaintext, block_size, permutation_key):
    # Pad the plaintext if its length is not a multiple of the block size
    plaintext += ' ' * ((block_size - len(plaintext) % block_size) % block_size)

    
    # Encrypt the plaintext
    ciphertext = ''
    for i in range(0, len(plaintext), block_size):
        block = plaintext[i:i+block_size]
        for j in permutation_key:
            ciphertext += block[j-1]
    
    return ciphertext

def decrypt_permutation_cipher(ciphertext, block_size, permutation_key):    
    # Invert the permutation key for decryption
    inverse_permutation_key = [0] * len(permutation_key)
    i = 0

    # Fill in the inverse permutation key based on the positions in the permutation key
    for pos in permutation_key:
        inverse_permutation_key[pos-1] = i
        i+=1

    # Decrypt the ciphertext
    plaintext = ''
    for i in range(0, len(ciphertext), block_size):
        block = ciphertext[i:i+block_size]
        for j in inverse_permutation_key:
            plaintext += block[j]
    
    return plaintext.strip()

def main():
    plaintext = input("Enter the plaintext message: ")
    block_size = 10
    key = [3,2,5,4,1,6,7,9,8,0]
    
    # Encrypt the plaintext
    ciphertext = encrypt_permutation_cipher(plaintext, block_size, key)
    print("Encrypted message:", ''.join(ciphertext.split(' ')))
    
    # Decrypt the ciphertext
    decrypted_text = decrypt_permutation_cipher(ciphertext, block_size, key)
    print("Decrypted message:", ''.join(decrypted_text.split(' ')))

if __name__ == "__main__":
    main()