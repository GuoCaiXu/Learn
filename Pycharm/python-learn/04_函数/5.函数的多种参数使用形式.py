def user_info(name, age, gender):
    print(f"你的名字是:{name}, 年龄是:{age}, 性别是:{gender}")

# 位置参数
print("位置参数")
user_info("小明", 18, "男")
print()

# 关键字参数 可不按顺序
print("关键字参数 可不按顺序")
user_info(name = "小明", gender = "男", age = 18)
# 可和位置参数混用
print("可和位置参数混用时位置参数必须放到关键字参数前面 否则语法错误")
user_info("小明", age = 18, gender = "男")
print()

# 缺省参数  作用：当调用函数时没有传递参数，就会使用默认是用缺省参数的对应值
# 默认值必须在最后面 否则报错
def new_test_info(name, age, gender = "男"):
    print(f"你的名字是:{name}, 年龄是:{age}, 性别是:{gender}")

print("缺省参数")
new_test_info("小明", 18)
new_test_info("小明", 18, "女")
print()

# 不定长 - 位置不定长， *号
# 不定长定义的形式参数会作为元组存在，接收不定长数量的参数传入
def user_info(*args):
    print(f"args参数类型是：{type(args)}, 姓名:{args[0]}, 年龄{args[1]}, 性别{args[2]}")

user_info("小明", 18, "男")
print()

# 不定长 - 位置不定长， **号
# 不定长定义的形式参数会作为字典存在，接收不定长数量的参数传入
def user_info(**kwargs):
    if len(kwargs) == 3:
        print(f"kwargs参数类型是：{type(kwargs)}, 姓名:{kwargs['name']}, 年龄:{kwargs['age']}, 性别:{kwargs['gender']}")
    elif len(kwargs) == 4:
        print(f"kwargs参数类型是：{type(kwargs)}, 姓名:{kwargs['name']}, 年龄:{kwargs['age']}, 性别:{kwargs['gender']}, 地址:{kwargs['addres']}")

user_info(name = "小明", age = 18, gender = "男")
user_info(name = "小明", age = 18, gender = "男", addres = "广西")
print()
