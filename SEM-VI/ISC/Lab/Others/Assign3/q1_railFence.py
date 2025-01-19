def rail_fence_encrypt(text, depth):
    encrypted_text = [''] * depth
    row = 0
    direction = -1

    for char in text:
        encrypted_text[row] += char
        if row == 0 or row == depth - 1:
            direction *= -1
        row += direction

    return ''.join(encrypted_text)

def rail_fence_decrypt(cipher, key):
# Create the matrix to cipher plain text
    # key = rows, length(text) = columns
    rail = [['\n' for _ in range(len(cipher))] for _ in range(key)]
    row = 0
    col = 0
    direction = -1

    for i in range(len(cipher)):
        rail[row][col] = '*'
        if row == 0 or row == key - 1:
            direction *= -1
        row += direction
        col+=1

    print(rail)
    print()
    
    # Now we can construct the fill the rail matrix
    index = 0
    for i in range(key):
        for j in range(len(cipher)):
            if rail[i][j] == '*' and index < len(cipher):
                rail[i][j] = cipher[index]
                index += 1

    # Now read the matrix in zig-zag manner to construct
    # the resultant text
    result = ''
    row = 0
    col = 0
    for i in range(len(cipher)):
        # Check the direction of flow
        if row == 0:
            dir_down = True
        if row == key - 1:
            dir_down = False

        # Place the marker
        if rail[row][col] != '*':
            result += rail[row][col]
            col += 1

        # Find the next row using direction flag
        if dir_down:
            row += 1
        else:
            row -= 1

    return result


def main():
    # text = input("Enter the plaintext: ")

    # depth_2_cipher = rail_fence_encrypt(text, 2)
    # print("Encrypted text with depth 2:", depth_2_cipher)

    # depth_3_cipher = rail_fence_encrypt(text, 3)
    # print("Encrypted text with depth 3:", depth_3_cipher)

    decrypted_depth_2 = rail_fence_decrypt("Mng noiseat elyIsarmi o pnn ow hl ako mis tasteg sllna", 2)
    decrypted_depth_3 = rail_fence_decrypt("Mng noiseat elyIsarmi o pnn ow hl ako mis tasteg sllna", 3)

    print("Decrypted text with depth 2:", decrypted_depth_2)
    print("Decrypted text with depth 3:", decrypted_depth_3)

if __name__ == "__main__":
    main()
