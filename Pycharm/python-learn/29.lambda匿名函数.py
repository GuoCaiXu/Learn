"""
1.def 关键字， 可以定义带有名称的函数
2.lambda 关键字， 可以定义匿名函数(无名称)

3.有名称的函数，可以基于名称重复使用
4.无名称的匿名函数，只可以临时使用一次

5.匿名函数定义语法:
    lambda 传入参数: 函数体(一行代码)
"""

def test_func(compute):
    result = compute(3, 1)
    print(result)

test_func(lambda x, y: x+y)
