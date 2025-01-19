def countPatients(path):
    i = 0
    file = open(path, "r")
    while(file.readline()):
        i+=1
    return i-1    

def addRecord(path, srno):
    file = open(path, "a")
    fname = input("Enter first name: ")
    lname = input("Enter last name: ")
    age = int(input("Enter Age: "))
    date = input("Enter Admission date in 'DD-MM-YYYY' format: ")
    gender = input("Enter gender: ")
    area = input("Enter area: ")
    file.write(str(srno).ljust(6, " ") + "|"+
                fname.ljust(12, " ")+ "|"+
                lname.ljust(11, " ")+ "|"+
                str(age).ljust(5, " ")+ "|"+
                date.ljust(16, " ")+ "|"+
                gender.ljust(8, " ")+ "|"+
                area.ljust(10, " ")+"\n")
    file.close()            

def delRecord(path, count):
    index = int(input("Enter the Record Sr No.: "))
    f = open(path, "r")
    data = f.readlines()
    f.close()
    f = open(path, "w")
    for i in range(len(data)):
        if i < index:
            f.write(data[i])
        elif i > index:
            f.write(str(i-1).ljust(6," ")+"|"+data[i][7:])  

def modRecord(path, count):
    index = int(input("Enter the Record Sr No.: "))
    f = open(path, "r")
    data = f.readlines()
    f.close()    
    fname = input("Enter first name: ")
    lname = input("Enter last name: ")
    age = int(input("Enter Age: "))
    date = input("Enter Admission date in 'DD-MM-YYYY' format: ")
    gender = input("Enter gender: ")
    area = input("Enter area: ")
    data[index] = str(index).ljust(6, " ") + "|"+ fname.ljust(12, " ")+ "|"+lname.ljust(11, " ")+ "|"+str(age).ljust(5, " ")+ "|"+date.ljust(16, " ")+ "|"+gender.ljust(8, " ")+ "|"+area.ljust(10, " ")+"\n"
    file = open(path, "w")
    for i in range(count+1):
        file.write(data[i])

def printfile(path, count):
    file = open(path, "r")
    for i in range(count+1):
        print(file.readline())

def summary(path, count):
    file = open(path, "r")
    print("\n1. Total\n2. Gender\n3. Age\n4. Area")
    n = int(input("--> "))
    if(n == 1):
        print("No. of Patients in Record = ", count, "\n")
    elif(n == 2):
        m, f = 0, 0
        for i in range(count+1):
            line = file.readline
            if i != 0:
                linedata = line.split("|")
                if linedata[6][0] == "M":
                    m += 1
                elif linedata[6][0] == "F":
                    f += 1
    elif(n == 3):
                        
    


path = "Patients.txt"
count = countPatients(path)
print("No. of Patients in Record = ", count)
while(True):  
    print("\n"+"COVID PATIENTS RECORD".center(74, "_") + "\n")
    count = countPatients(path)
    print("No. of Patients in Record = ", count, "\n")
    printfile(path, count)
    print("1. Add Record\n2. Delete Record\n3. Modify Record")
    print("4. Count Based on\n5. Ascending Order By\n6. Descending Order By\n7. Display By Range\n0. Exit\n--> ")
    n = int(input())
    if(n == 1):
        addRecord(path, count + 1)
    elif(n == 2):
        delRecord(path, count)  
    elif(n == 3):
        modRecord(path, count)  
    elif(n == 4):
        summary(path)        
    else:
        break    