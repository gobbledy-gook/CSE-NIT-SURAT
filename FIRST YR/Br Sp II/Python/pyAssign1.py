# Q1
# a = 2
# b = "a"
# c = 2.1
# d = [2,4]
# e = {1, 3}
# f = {"a":1, "b":2}
# g = 2 + 3j
# h = True
# i = (2, 3)
# print(a, type(a))
# print(b, type(b))
# print(c, type(c))
# print(d, type(d))
# print(e, type(e))
# print(f, type(f))
# print(g, type(g))
# print(h, type(h))
# print(i, type(i))

# Q2
# print("Addition: 2+3 = ", 2+3)
# print("Multiplication: 2*3 = ", 2*3)
# print("Division: 3/2 = ", 3/2)
# print("Floor Division: 3//2 = ", 3//2)
# print("Modulo: 3%2 = ", 3%2)
# print("Power: 2^3 = ", 2**3)


# Q3
# l = [1,2,3,4,5]
# print("Original List: ", l)
# l.pop()
# print("Pop Method (without argument): ", l)
# l.pop(0)
# print("Pop Method (with argument): ", l)
# l.append("a")
# print("Append Method: ", l)
# l.extend(["x", "y"])
# print("Extend Method: ", l)
# l.remove(2)
# print("Remove Method: ", l)
# l.insert(3, "A")
# print("Insert Method: ", l)
# print("Length Function: ", len(l))
# l.clear()
# print("Clear Method: ", l)

# Q4
dict1 = {
    "fname" : "Steve",
    "lname" : "Jobs",
    "company" : "AAPL"
}
print("Original Dictionary: ", dict1)
print("Dictionary Items: ", dict1.items())
print("Using get(): ", dict1.get("fname"))
dict1["company"] = "NeXT"
print("Changed the value: ", dict1)
print("Using len(): ", len(dict1))


# Q5
# str1 = "Violets and Purples"
# str2 = "Diamonds and Circles"
# print("Printing both the strings: ", str1, str2)
# print("Concatenation: ", str1+str2)

# Q6
# a = 2
# b = 3
# print("Addition of two numbers: ", a+b)


# Q7
# a = input("Enter an integer - ")
# if int(a) > 0:
#     print("Positive")
# elif int(a) < 0:
#     print("Negative")


# Q8
# A = input("1st Number: ")
# B = input("2nd Number: ")
# C = input("3rd Number: ")
# a, b, c = float(A), float(B), float(C)
# if a>b and a>c:
#     print("Largest Number:", A)
# elif b>a and b>c:
#     print("Largest Number:", B)
# else:
#     print("Largest Number:", C)  


# Q9
# n = int(input("Enter the number - "))
# fact = 1
# for i in range(1, n+1):
#     fact *= i
# print("Factorial of", n, "is", fact)


#Q10
# p = float(input("Principal: "))
# t = float(input("Time (in yrs): "))
# r = float(input("Rate (in % p.a.): "))
# si = (p*t*r)/100
# print("Simple Interest:", si)


# Q11
# n = int(input("Enter a number to check - "))
# sum = 1
# for i in range(2, n):
#     if n%i ==0:
#        sum += i
# if sum == n:
#     print("Perfect Number")
# else:
#     print("Imperfect Number")


# Q12
marks = float(input("Enter your marks - "))
if marks>90 and marks<=100:
    print("Grade A")
elif marks>80 and marks<= 90:
    print("Grade B")
elif marks>70 and marks <= 80:
    print("Grade C")
elif marks>60 and marks<=70:
    print("Grage D")
elif marks >= 50 and marks <=60:
    print("Grade E")
elif marks < 50:
    print("Grade F = Fail !")
    
