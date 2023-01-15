my_str = "itheima and itcast"

# 字符串和元组一样，无法修改数据容器，创建新字符串

# my_str[2] = "H"   报错

# 通过下标索引取值

value = my_str[2]
value2 = my_str[-16] # 倒数第16 索引为16的元素

print(f"value = {value}")
print(f"value2 = {value2}")

# index 方法

value = my_str.index("and")
print(f"在字符串{my_str}中查找and 起始下标{value}")

# replace 方法 字符串替换 不是修改字符串本身而是得到了一个新字符串

new_my_str = my_str.replace("it", "程序") # 第一个空表示被替换的，第二个空表示要替换的数据
print(f"将字符串{my_str}替换后得到:{new_my_str}")

# split 方法 字符串的分割 按指定的分隔符字符将字符串划分为多个字符串，并存入列表对象中

my_str = "hello python itheima itcast"
my_str_list = my_str.split(" ") # 按照空格符分割
print(f"将字符串{my_str}进行split切分后得到:{my_str_list}")

# strip 方法 字符串的规整操作(去除前后指定参数)

my_str = "  itheima and itcast  "
new_my_str = my_str.strip() # 不传参数指定去除空格
print(f"将字符串{my_str}进行strip规整后得到:{new_my_str}")

my_str = "12itheima and itcast21"
new_my_str = my_str.strip("12")
print(f"将字符串{my_str}进行strip规整后得到:{new_my_str}")

# 统计字符串中某个字符串出现次数

my_str = "itheima and itcast"
count = my_str.count("it")
print(f"字符串{my_str}中it出现的次数是:{count}")

# 统计字符串的长度

num = len(my_str)
print(f"字符串{my_str}的长度是:{num}")
