# 元组一旦定义完成 就不可以修改

# 定义元组

# 方法1
# 空元组
temp_1 = ()

# 单个元组
temp_3 = (1,) # 要加逗号 不然数据类型是str

# 方法2

temp_2 = tuple()

# 元组可以嵌套

temp_5 = ((), ())

# 元组的操作：index查找方法

# 元组的操作：count统计方法

# 元组的操作：len函数

# 元组里面内部list 可以修改list 但元组还是不能修改
temp_6 = (1, 2, ["abc", "def"])

print(f"temp_6 修改前的内容为:{temp_6}")

temp_6[2][0] = "123"
temp_6[2][1] = "456"

print(f"temp_6 修改后的内容为:{temp_6}")

del temp_6[2][0]

print(f"temp_6 删除后的内容为:{temp_6}")
