temp = [1,2,3,4]

# 查询功能

print(f"{temp.index(4)}") # 找不到就报错

# 插入元素

print(f"{temp[1]}")

temp.insert(1, 5)

print(f"{temp[1]}")

# 追加元素(从后面插入元素)

temp.append("你好")

print(f"temp = {temp}", end = '')
print()

# 列表增加一批元素

temp2 = [6,7,8]
temp.extend(temp2) # 第一种
# temp.extend([6,7,8]) # 第二种
print(f"temp = {temp}", end = '')
print()

# 删除元素

# 删除第一种方法
del temp[2]

print(f"{temp}", end = '')
print()

# 删除第二种方法

element = temp.pop(2)

print(f"temp 删除的元素为:{element}, temp = {temp}", end = '')
print()

temp_1 = [1,2,3,4,3]

temp_1.remove(3)
print(f"{temp_1}", end = '') # 从前到后搜索删除
print()

# 清空列表

temp_1.clear()
if len(temp_1) == 0:
    print("删除成功")
else:
    print("删除失败")

# 统计某元素在列表内的数量

temp_2 = [1,2,3,4,3,3]

print(f"temp_2 的数量为:{temp_2.count(3)}")

# 统计列表中元素的数量

print(f"temp_2 的数量为:{len(temp_2)}")
