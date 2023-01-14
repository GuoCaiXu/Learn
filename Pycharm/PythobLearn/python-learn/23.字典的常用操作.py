"""
1.新增元素
2.元素的更新
3.删除元素  字典.pop(Key)
4.清空元素  字典.clear()
5.获取全部key   字典.keys()   结果：得到字典中全部的key
6.遍历字典(不能使用while 只能用for)        for key in 字典.keys():
7.统计字典中的数量  len()
"""

my_dict = {"张三": 98}

# 新增元素
my_dict["李四"] = 96
print(f"{my_dict}")
print()

# 元素的更新
my_dict["张三"] = 60
print(f"{my_dict}")
print()

# 删除元素  字典.pop(Key)
my_dict.pop("张三")
print(f"{my_dict}")
print()

# 清空元素  字典.clear()
my_dict.clear()
print(f"{my_dict}")
print()

# 获取全部key   字典.keys()   结果：得到字典中全部的key
my_dict = {"张三": 98, "李四": 67, "李红": 89}
keys = my_dict.keys()
print(f"{keys}")
print()

# 遍历字典
for key in keys:
    print(f"字典的key是：{key} ", end = '')
    print(f"字典的value是：{my_dict[key]}")
print()

# 统计字典中的数量  len()
print(f"字典中的元素数量有:{len(my_dict)}个")
