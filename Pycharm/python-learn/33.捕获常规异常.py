"""
基本语法：

try:
    可能发生错误的代码
except:
    如果出现异常执行的代码
"""

# 基本捕获语法
try:
    f = open("abc.txt", "r", encoding = "UTF-8")
except:
    print("出现异常!文件不存在，用w 模式创建文件在r 模式读取!")
    f = open("abc.txt", "w", encoding = "UTF-8")
    f.close()
    f = open("abc.txt", "r", encoding = "UTF-8")

# 捕获指定异常
"""
try:
    # print(name)
    1/0
except NameError as e:
    print("出现了变量未定义")
"""

# 捕获所有异常
try:
    # print(name)
    print("Hello")
except Exception as e:
    print("except 出现了异常")
else:       # else 表示如果没有异常要执行的代码
    print("else 没有出现异常!")
finally:    # finflly   表示是否异常都要执行的代码，例如关闭文件
    f.close()
    print("finally 一定要执行的代码")
