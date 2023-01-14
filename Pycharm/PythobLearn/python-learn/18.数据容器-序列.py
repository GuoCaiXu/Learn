"""
序列是指：内容连续，有序，可使用下标索引的一类数据容器
列表，元组，字符串，均可以视为序列
"""

# 序列操作：切片 此操作不会影响序列的本身，而是会得到一个新的序列

# 对list 进行切片，从1 开始，4 结束， 步长1
my_list = [0, 1, 2, 3, 4, 5, 6]
result1 = my_list[1:4]    # 步长默认是1，所以可以省略不写
print(f"result1 = {result1}")

# 对tuple 进行切片，从头开始，到最后结束，步长1
my_tuple = (0, 1, 2, 3, 4, 5, 6)
result2 = my_tuple[:]   # 起始和结束不写表示是从头到尾，步长为1 可以省略
print(f"result2 = {result2}")

# 对str 进行切片，从头开始，到最后结束，步长2
my_str = "01234567"
result3 = my_str[::2]
print(f"result3 = {result3}")

# 对str 进行切片，从头开始，到最后结束，步长-1
my_str = "01234567"
result4 = my_str[::-1]  # 等同于将序列反转了
print(f"result4 = {result4}")

# 对列表进行切片，从3 开始，到1 结束，步长-1
my_list = [0, 1, 2, 3, 4, 5, 6]
result5 = my_list[3:1:-1]
print(f"result5 = {result5}")

# 对元组进行切片，从头开始，到尾结束，步长-2
# 对tuple 进行切片，从头开始，到最后结束，步长1
my_tuple = (0, 1, 2, 3, 4, 5, 6)
result6 = my_tuple[::-2]
print(f"result6 = {result6}")
