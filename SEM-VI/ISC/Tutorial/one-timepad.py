# hexconv = {'a': 10, 'b':11, 'c':12, 'd':13, 'e':14, 'f':15}
cipher = input("Enter: ")
# cipher1 = []
cipher = str(int(cipher, 16))

for i in range(0,len(cipher), 2):
    binary = bin(int(cipher[i]))
    if(len(bin(int(cipher[i]))) < 6):
        binary = '0'*(4 - len(str(bin(int(cipher[i])))[2:])) + str(bin(int(cipher[i])))[2:]

    print(int(binary[0])^0)

# for i in range(len(cipher)):
#     try:
#         cipher1.append(int(cipher[i]))   
#     except:
#         cipher1.append(hexconv[cipher[i]])


# for i in range(len(cipher1)):
#     cipher1[i] = bin(cipher1[i]) 
#     if(len(cipher1[i][2:]) <= 3):
#         cipher1[i] = '0'*(4-len(cipher1[i][2:])) + cipher1[i][2:] 
#     else:
#         cipher1[i] = cipher1[i][2:]         

# # print(cipher1)
# key = ''
# for i in range(0,len(cipher1),2):
#     if(cipher1[i][0] == '0'):
#         key+='0'
#     else:
#         key+='1'

# print(key)            