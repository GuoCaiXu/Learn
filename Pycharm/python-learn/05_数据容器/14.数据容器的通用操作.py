"""
演示数据容器的通用功能
"""

my_list = [1, 2, 3, 4, 5]
my_tuple = (1, 2, 3, 4, 5)
my_str = "abcdefg"
my_set = {1, 2, 3, 4, 5}
my_dict = {"key1": 1, "key2": 2, "key3": 3, "key4": 4, "key5": 5}

# len 元素个数
print("len 元素个数")
print(f"列表 元素个数有{len(my_list)}个")
print(f"元组 元素个数有{len(my_tuple)}个")
print(f"字符串 元素个数有{len(my_str)}个")
print(f"集合 元素个数有{len(my_set)}个")
print(f"字典 元素个数有{len(my_dict)}个")
print()

# max 最大元素
print("max 最大元素")
print(f"列表 最大元素为：{max(my_list)}")
print(f"元组 最大元素为：{max(my_tuple)}")
print(f"字符串 最大元素为：{max(my_str)}")
print(f"集合 最大元素为：{max(my_set)}")
print(f"字典 最大元素为：{max(my_dict)}")
print()

# min 最小元素
print("min 最小元素")
print(f"列表 最小元素为：{min(my_list)}")
print(f"元组 最小元素为：{min(my_tuple)}")
print(f"字符串 最小元素为：{min(my_str)}")
print(f"集合 最小元素为：{min(my_set)}")
print(f"字典 最小元素为：{min(my_dict)}")
print()

# 容器转列表
print("容器转列表")
print(f"元组转列表的结果为:{list(my_tuple)}")
print(f"字符串转列表的结果为:{list(my_str)}")
print(f"集合转列表的结果为:{list(my_set)}")
print(f"字典转列表的结果为:{list(my_dict)}")
print()

# 容器转元组
print("容器转元组")
print(f"列表转元组的结果为：{tuple(my_list)}")
print(f"字符串转元组的结果为：{tuple(my_str)}")
print(f"集合转元组的结果为：{tuple(my_set)}")
print(f"字典转元组的结果为：{tuple(my_dict)}")
print()

# 容器转字符串
print("容器转字符串")
print(f"列表转字符串的结果为:{str(my_list)}")
print(f"元组转字符串的结果为:{str(my_tuple)}")
print(f"集合转字符串的结果为:{str(my_set)}")
print(f"字典转字符串的结果为:{str(my_dict)}")
print()

# 容器转集合
print("容器转集合")
print(f"列表转集合的结果为:{set(my_list)}")
print(f"元组转集合的结果为:{set(my_tuple)}")
print(f"字符串转集合的结果为:{set(my_str)}")
print(f"字典转集合的结果为:{set(my_dict)}")
print()

# 容器转字典 不能转换    报错
print("容器转字典 不能转换   报错")
"""
print(f"列表转字典的结果为:{dict(my_list)}")
print(f"元组转字典的结果为:{dict(my_tuple)}")
print(f"字符串转字典的结果为:{dict(my_str)}")
print(f"集合转字典的结果为:{dict(my_set)}")
print()
"""

# 通用排序功能    sorted(容器, [reverse=True])  将给定容器进行排序
my_list = [3, 1, 2, 5, 4]
my_tuple = (3, 1, 2, 5, 4)
my_str = "gabcedf"
my_set = {3, 1, 2, 5, 4}
my_dict = {"key3": 1, "key1": 2, "key2": 3, "key5": 4, "key4": 5}


print(f"列表对象的排序结果：{sorted(my_list)}")
print(f"元组对象的排序结果：{sorted(my_tuple)}")
print(f"字符串对象的排序结果：{sorted(my_str)}")
print(f"集合对象的排序结果：{sorted(my_set)}")
print(f"字典对象的排序结果：{sorted(my_dict)}")

print(f"列表对象的反向排序结果：{sorted(my_list, reverse=True)}")
print(f"元组对象的反向排序结果：{sorted(my_tuple, reverse=True)}")
print(f"字符串对象反向的排序结果：{sorted(my_str, reverse=True)}")
print(f"集合对象的反向排序结果：{sorted(my_set, reverse=True)}")
print(f"字典对象的反向排序结果：{sorted(my_dict, reverse=True)}")
print()