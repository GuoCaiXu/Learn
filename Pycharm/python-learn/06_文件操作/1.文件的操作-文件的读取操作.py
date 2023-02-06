"""
1.open()  打开函数
2.open(name, mode, encoding)
    name:打开的目标文件名的字符串(可以包含文件所在的具体路径)
    mode:设置打开文件的模式(访问模式):只读(r)， 写入(w)，追加(a)
    encoding:编码格式(推荐使用UTF-8)
"""

# 打开文件
f = open("test.txt", "r", encoding = "UTF-8")

# 读取文件  read()
"""
文件对象.read() 读取文件中所有的数据
文件对象.read(num)  读取文件中num个字节数据
"""
print("读取文件  read()")
print(f.read())
print()
print()
f.close()

# 读取文件  readlines() 读取多行
"""
文件对象.readlines() 读取文件中所有行的数据
"""
print("读取文件  readlines() 读取多行")
f = open("test.txt", "r", encoding = "UTF-8")
print(f"{f.readlines()}")
print()
print()
f.close()

# 读取文件  readline()  读取1行
"""
文件对象.readline() 一行一行读取文件中的数据
"""
print("读取文件  readline()  读取1行")
f = open("test.txt", "r", encoding = "UTF-8")
print(f"文件第一行的数据是:{f.readline()}")
print(f"文件第二行的数据是:{f.readline()}")
print()
print()
f.close()

# for 循环读取文件行
print("for 循环读取文件行")
f = open("test.txt", "r", encoding = "UTF-8")
for line in f:
    print(f"文件每一行的数据是:{line}")
print()
print()
f.close()

"""
import time # 先导入时间
time.sleep(50000) # 程序暂停50w秒
"""

# with open(name, mode, encoding) as f语法操作文件  执行完里面的语句自动关闭文件
print("with open 语法操作文件  执行完里面的语句自动关闭文件")
with open("test.txt", "r", encoding = "UTF-8") as f:
    for line in f:
        print(f"文件每一行数据是：{line}")

