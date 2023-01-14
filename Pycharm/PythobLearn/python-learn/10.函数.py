def my_len(data):
    """
    求字符串长度
    :param data: 求出字符串的长度
    :return: 空的值
    """
    count = 0
    for i in data:
        count += 1

    print(f"字符串{data},的长度为:{count}")
    return None
# None 表示c 语言的void


str1 = "python"

my_len(str1)
