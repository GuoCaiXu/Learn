my_list = ['黑马程序员', '传智播客', '黑马程序员', '传智播客', 'itheima', 'itcast', 'itheima', 'best']

# 定义一个空集合
my_set = set()

# 通过for 循环遍历列表
for element in my_list:
    print(f"{element} ", end = '')
print()

# 在for 遍历中将列表的元素添加至集合
for element in my_list:
    my_set.add(element)

# 最终得到元素去重后的集合对象，并打印输出
for element in my_set:
    print(f"{element} ", end = '')
print()
