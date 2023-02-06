"""
文件处理相关的工具模块
"""

def print_file_info(file_name):

    """
    将给定的路径文件内容输出到控制台中
    :param file_name: 即将读取的文件路径
    :return: None
    """
    f = None
    try:
        f = open(file_name, "r", encoding = "UTF-8")
        print("文件的内容如下:")
        print(f.read())
    except Exception as e:
        print(f"文件出现异常，原因是:{e}")
    finally:
        if f:   # 如果变量是None，表示False，如果有人任何内容就是True
            f.close()

def append_to_file(file_name, data):

    """
    将指定的数据追加到指定的文件中
    :param file_name: 指定的文件路径
    :param data: 指定的数据
    :return: None
    """
    f = open(file_name, "a", encoding = "UTF-8")
    f.write("\n")
    f.write(data)
    f.close()

if __name__ == '__main__':
    print_file_info("C:/Project/Pycharm/python-learn/07_异常_模块_包/6.综合案例/综合案例.txt")
    append_to_file("C:/Project/Pycharm/python-learn/07_异常_模块_包/6.综合案例/综合案例.txt", "追加函数!")
    print_file_info("C:/Project/Pycharm/python-learn/07_异常_模块_包/6.综合案例/综合案例.txt")
