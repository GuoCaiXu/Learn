# 集合最主要的特点就是：不支持元素的重复(自带去重功能),并且内容无序
"""
1.不支持下标索引访问
2.允许修改
3.添加新元素 .add(元素)
4.移除元素   .remove(元素)
5.随机取出来一个元素 .pop()
6.清空集合   .clear()
7.取两个集合的差集  集合1.difference(集合2)
8.消除2 个集合的差集    集合1.difference_update(集合2)
9.两个集合合并    集合1.union(集合2)
10.统计集合元素是数量    len(元素)
11.集合遍历
"""

# 集合的定义

my_set = {1,2,4,5,5,3}
my_set_empty = set()

print(f"my_set = {my_set}, 类型是:{type(my_set)}")
print(f"my_set_empty = {my_set_empty},类型是:{type(my_set_empty)}")
print()

# 添加新元素

my_set_empty.add("你好世界!")
print(f"my_set_empty = {my_set_empty}")
print()

# 移除元素
my_set_empty.remove("你好世界!")
print(f"my_set_empty = {my_set_empty}")
print()

# 随机取一个元素

element = my_set.pop()
print(f"集合被取出元素是{element}, 被取出元素后:{my_set}")

# 清空集合
my_set.clear()
print(f"my_set 集合被清空了，结果是:{my_set}")
print()

# 取两个集合的差集
"""
功能：取出集合1 和集合2 的差集(集合1 有而集合2 没有的)
结果：得到一个新集合，集合1 和集合2 不变
"""

set1 = {1, 2, 3}
set2 = {1, 5, 6}
set3 = set1.difference(set2)
print(set3)
print(set2)
print(set1)
print()

# 消除2 个集合的差集
"""
功能：对比集合1 和集合2，在集合1内，删除和集合2 相同的元素
结果：集合1 被修改，集合2 不变
"""

set1 = {1, 2, 3}
set2 = {1, 5, 6}
set1.difference_update(set2)
print(set1)
print(set2)
print()

# 两个集合合并
"""
功能：将集合1 和集合2 组合成新集合
结果：得到新集合，集合1 和集合2 不变
"""

set1 = {1, 2, 3}
set2 = {1, 5, 6}
set3 = set1.union(set2)
print(set3)
print(set1)
print(set2)
print()

# 统计集合元素是数量

print(len(set3))
print()

# 集合的遍历 不可以用while 可以用 for

for element in set3:
    print(f"{element} ", end = '')
print()
