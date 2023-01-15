print("--------------------------------------------")
print("字面量")

# 字面量 666 13.14 "Hello World"
print(666)
print(13.14)
print("Hello World")

"""
多行注释
"""

# 定义变量
print("--------------------------------------------")
print("定义变量")

money = 50
print("钱包还有:", money)
# 变量运算
money -= 10
print("钱包还有:", money, "元")

b = "Hello World"
print(b)

# 查看数据类型 type

print("--------------------------------------------")
print("查看数据类型 type")

print(type(6))
print(type(13.14))
print(type("你好 世界"))

# 储存type() 返回的结果

print("--------------------------------------------")
print("储存type() 返回的结果")

string_type = type("你好世界")
int_type = type(6)
float_type = type(13.14)

print(string_type)
print(int_type)
print(float_type)
print(type(string_type))

# 转化语句

"""
    int(x)
    float(x)
    str(x)
"""
print("--------------------------------------------")
print("转化语句")

# 数字转字符串
num = 11
num_str = str(num)
print(type(num_str), num_str)

float_str = str(11.345)
print(type(num_str), float_str)

# 字符串转数字s
str_int = int("9")
print(type(str_int), str_int)

# 错误示例
# num1 = int("你好世界")
# print(type(num1), num1) 这是错误的中文的字符串转不了数字

# 运算符

print("--------------------------------------------")
print("运算符")

"""
    //  取整除
    **  指数
"""

num1 = 9 // 2
num2 = 9 % 2
num3 = 2 ** 3 # 2 的 3 次方 = 2 * 2 * 2

print(num1)
print(num2)
print(num3)

# 字符串的三种定义方式

print("--------------------------------------------")
print("字符串的三种定义方式")

# 单引号定义
name1 = '你好 世界'

# 双引号定义
name2 = "你好 世界"

# 三引号定义
name3 = """
你好 世界
你好 C++
你好 Python
"""

print(name1)
print(name2)
print(name3)

name4 = '"你好世界"'

print(name4)

# 字符串拼接

print("--------------------------------------------")
print("字符串拼接")

name = "徐国彩"
name = "我的名字是：" + name + ",我是一个学生"

print(name)

# 字符串格式化

print("--------------------------------------------")
print("字符串格式化")

test_num = 191
test_age = 18
test_num1 = 19.9

message = "我的手机号是：%s, 我的年龄为：%s" % (test_num, test_age)
message1 = "我的手机号是：%d, 我的年龄为：%d" % (test_num, test_age)
message2 = "今天的股价是:%.1f" % test_num1

print(message)
print(message1)
print(message2)

# 字符串格式化_快速写法

print("--------------------------------------------")
print("字符串格式化_快速写法")

name5 = "传智播客"
set_up_year = 2006
stock_price = 19.99

print(f"我是{name5}, 我成立于{set_up_year}, 我今天的股票价格是:{stock_price}")

