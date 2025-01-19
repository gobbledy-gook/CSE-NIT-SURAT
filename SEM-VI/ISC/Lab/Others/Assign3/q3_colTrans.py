import math
def encrypt_columnar_transposition(plaintext, keyword, order):
    keyword = keyword.replace(" ", "").upper()
    num_rows = math.ceil(len(plaintext) / len(keyword))
    
    # Pad the plaintext with spaces to fit the grid
    plaintext += '*' * (num_rows * len(keyword) - len(plaintext))
    
    # Create the grid
    grid = [[' ' for _ in range(len(keyword))] for _ in range(num_rows)]
    
    # Fill the grid with the plaintext characters
    index = 0
    for row in range(num_rows):
        for char, col in enumerate(order):
            grid[row][int(col)-1] = plaintext[index]
            index += 1
    print(grid)
    # Extract the ciphertext by reading the grid column by column
    ciphertext = ''
    for col in range(len(keyword)):
        for row in range(num_rows):
            ciphertext += grid[row][col]
    
    return ciphertext

def decrypt_columnar_transposition(ciphertext, keyword, order):
    # Remove spaces from the keyword and convert to uppercase
    keyword = keyword.replace(" ", "").upper()
    inv_order = ["" for i in range(len(order))]
    for ind, val in enumerate(order):
        inv_order[int(val)-1] = str(ind)
    inv_order = "".join(inv_order)
    print(inv_order)    
    # Determine the number of rows required for the grid
    num_rows = math.ceil(len(ciphertext) / len(keyword))
    
    # Create the grid
    grid = [[' ' for _ in range(len(keyword))] for _ in range(num_rows)]
    
    # Fill the grid with the ciphertext characters according to the order
    index = 0
    for char, col in enumerate(inv_order):
        for row in range(num_rows):
            grid[row][int(col)] = ciphertext[index]
            index += 1
    
    # Extract the plaintext by reading the grid row by row
    plaintext = ''
    for row in range(num_rows):
        for col in range(len(keyword)):
            plaintext += grid[row][col]
    
    return plaintext.strip()

def main():
    # Input plaintext, keyword, and order of key input from the user
    plaintext = input("Enter the plaintext message: ").upper()
    keyword = input("Enter the keyword: ").upper()
    order = input("Enter the order of key input (e.g., '54321'): ")
    
    # Encrypt the plaintext using columnar transposition cipher
    ciphertext = encrypt_columnar_transposition(plaintext, keyword, order)
    print("Encrypted message:", ciphertext)
    
    # Decrypt the ciphertext using columnar transposition cipher
    decrypted_text = decrypt_columnar_transposition(ciphertext, keyword, order)
    print("Decrypted message:", decrypted_text)

if __name__ == "__main__":
    main()
