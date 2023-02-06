# 导入自定义模块使用
# import my_module1
# from my_module1 import test
# test(1, 2)
# print()

# 导入不同模块的同名功能
# from my_module1 import test
# from my_module2 import test
# test(1, 2)  # 后面导入的同名函数会覆盖前面的同名函数
# print()

# __main__ 变量
from my_module1 import test

# __all__ 变量
from my_module2 import *
test_A(1, 2)
# test_B(1, 2)    # 用了__all__ = ['test_A'] 只能使用test_A,test_B不能使用
from my_module2 import test_B
test_B(1, 2)    # 但可以使用导入函数的方法来使用函数
