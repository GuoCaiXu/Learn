for i in range(1, 10):
    for j in range(1, i+1):
        print(f"{j} * {i} = {j*i}\t", end = '')
    print()

# 序列range语法

""""
语法1
range(num)
从0 开始序列到num 每次加1 不含num

语法2
range(num1, num2)
从num1 开始到num2 每次加1 不含num2

语法3
rang(num1, num2, step)
从num1 到 num2 每次加step 不含num2
"""