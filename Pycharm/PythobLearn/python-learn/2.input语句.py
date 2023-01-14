# input语句

print("请告诉我你是谁？")
name = input()
print("Get!!!你是：%s" % name)

# 等同于

name1 = input("请告诉我你是谁？")
print("Get!!!你是：%s" % name1)

# 输入数字类型

num = input("请输入一个数字:")
print("你输入数字类型为:", type(num)) #输入的数据都是字符串类型 str

# 数据类型转化
num = int(num)
print("你输入数字类型为:", type(num))

