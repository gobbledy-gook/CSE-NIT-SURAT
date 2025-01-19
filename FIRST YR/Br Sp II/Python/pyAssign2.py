'''
# Q1
str1 = input("Enter the string - ")
count = 0
for letter in str1:
    if letter.lower() == "a" or letter.lower() == "e" or letter.lower() == "i" or letter.lower() == "o" or letter.lower() == "u":
           count +=1
    else:
        pass
print("No. of vowels in given string =", count)    


# Q2
num = input("Enter a number - ")
numR = num[-1::-1]
print("Reversed Number - ", numR)


# Q3
n = input("Enter the number - ")
l = len(n)
print("No. of digits in number -", l)



# Q4
def fact(n):
    if n == 1:
        return 1
    elif n == 0:
        return 1
    else:
        return n*fact(n-1)

n = int(input("Enter the number - "))
print("Factorial with recursion -", fact(n))
fact = 1
for i in range(1, n+1):
    fact *= i
print("Factorial without recursion -", fact)


# Q5
a = int(input("Enter the base -"))
A = a
b = int(input("Enter the power -"))
for i in range(1,b):
    a *= A;
print("Power of", A, "is", a)    
   


# Q6
n = int(input("Enter the no. of terms - "))
sum = 0
for i in range(1, n+1):
    sum += (1/i)
print("Sum is -", sum)    


# Q7
present = list(map(int, input("Enter roll nos. space separated: ").split()))
rolln = int(input("Enter the roll no.: "))
if rolln in present:
    print("-- Present --")
else:
    print("-- Absent --")


# Q8
A = input("1st Number: ")
B = input("2nd Number: ")
C = input("3rd Number: ")
a, b, c = float(A), float(B), float(C)
if a > b and a > c:
    print("Largest is", A)
elif b > a and b >c:
    print("Largest is", B)
else:
    print("Largest is", C)


# Q9
def areaCircle(r):
    return 3.14*(r**2)

rad = input("Enter the radius - ")
print("Area of the circle for given radius - ", areaCircle(float(rad)))


# Q10
x = 0
while x ==0:
    age = int(input("Age: "))
    if age < 3 and age>0:
        print("Hurray! FREE")
    elif age >=3 and age<12:
        print("Fee: $", 10)
    else:
        print("Fee: $", 15)
    c = input("Continue(Y/N): ")
    if c.upper() != "Y":
        x =1
    else:
        continue


# Q11
def make_album(track=0):
    art = input("Enter the name of the artist: ")
    tit = input("Enter the name of the title: ")
    d = {"artist":art, "title":tit, "track":track}
    return d

dict1 = make_album()
dict2 = make_album()
dict3 = make_album()
dict4 = make_album(10)
print(dict1)
print(dict2)
print(dict3)
print(dict4)


# Q12
def show_magicians(mList):
    for name in mList:
        print(name)

m = ["Harry Houdini", "Penn", "Teller", "David Blaine"]
show_magicians(m)
'''























