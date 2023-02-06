"""
字符串相关的工具模块
"""

def str_reverse(s):
    """
    将字符串完成反转
    :param s: 需要反转的字符串
    :return: 反转后的字符串
    """
    return s[::-1]

def substr(s, x, y):
    """
    按照给定的下标完成给定的字符串切片
    :param s: 即将被切片的字符串
    :param x: 切片开始的下标
    :param y: 切片结束的下标
    :return: 切片完成后的字符串
    """
    return s[x:y]

if __name__ == '__main__':
    print(str_reverse("Hello World"))
    print(substr("Hello Wrold Python", 0, 8))
