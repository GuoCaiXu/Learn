"""
常用的组合形式：
1. import 模块名
2. from 模块名 import 类, 变量, 方法等
3. from 模块名 import *
4. import 模块名 as 别名
5. from 模块名 import 功能名 as 别名
"""
Choose = int(input("请输入你选择的功能:"))

# 使用import 导入time 模块使用sleep功能(函数)
if Choose == 1:
    print("使用import 导入time 模块使用sleep功能(函数)")
    import time   #导入Python 内置的time 模块(time.py 这个代码文件)
    print("Hello")
    time.sleep(5)
    print("World")
    print()
# 使用from 导入time 的sleep 功能(函数)
elif Choose == 2:
    print("使用from 导入time 的sleep 功能(函数)")
    from time import sleep
    print("Hello")
    sleep(5)
    print("World")
    print()
# 使用* 号导入time 模块的全部功能
elif Choose == 3:
    print("使用* 号导入time 模块的全部功能")
    from time import *  # * 表示全部的意思
    print("Hello")
    sleep(5)
    print("World")
    print()
# 使用as 给特定的名字加上别名
elif Choose == 4:
    print("使用as 给特定的名字加上别名")
    import time as t
    print("Hello")
    t.sleep(5)
    print("World")
    print()

elif Choose == 5:
    from time import sleep as sl
    print("Hello")
    sl(5)
    print("World")
