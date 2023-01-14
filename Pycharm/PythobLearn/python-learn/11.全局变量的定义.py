num = 100
print(f"{num}")

def testA():
    global num
    num = 200
    print(f"{num}")

testA()
print(f"{num}")

