# c语言里面的数组

num = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

for i in range(0, 10):
    print(f"{num[i]} ", end = '')
print()

# 定义空列表
num1 = []
num2 = list()

# 列表可以存放不同的数据类型

My = ["张三", 18, "男"]

for i in range(0, len(My)):
    print(f"{My[i]} ", end = '')
print()

# 倒序输出
print(f"{My[-1]} ", end = '')
print(f"{My[-2]} ", end = '')
print(f"{My[-3]}")

# 可以嵌套
num3 = [["张三", 19, "男"], ["李明", 20, "女"]]

for i in range(0, len(num3)):
    for j in range(0, len(num3[i])):
        print(f"{num3[i][j]} ", end = '')
    print()
