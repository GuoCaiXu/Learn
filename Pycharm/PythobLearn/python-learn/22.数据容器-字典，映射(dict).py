"""
1.key 不允许重复 后面重复的key 会覆盖前面的key
2.不可以使用下标索引， 只能使用key 来获取
3.字典的嵌套 key 和 value 可以是任意数据类型(key 不可以为字典)
"""
# 字典的定义 my_dict = {key: value}
my_dict = {"张三": 99, "李明": 67, "小红": 97} # ":"(冒号) 后面要加空格

# 定义空字典
my_dict_empty = dict() # 方式1
my_dict_empty = {}     # 方式2
print(f"字典1的内容是{my_dict}， 类型是{type(my_dict)}")
print()

# 定义重复key 的字典
my_dict1 = {"张三": 99, "张三": 88, "李明": 77}
print(f"重复key 的字典的内容是：{my_dict1}")  # 后面重复的key 会覆盖前面的key
print()

# 从字典中基于key 的字典
my_dict2 = {"张三": 99, "李明": 67, "小红": 97}
print(f"张三的考试分数是：{my_dict2['张三']}")  # 方法1
print()

score = my_dict2["张三"]      # 方法2
print(f"张三的考试分数是：{score}")
print()

# 字典的嵌套 key 和 value 可以是任意数据类型(key 不可以为字典)
stu_score_dict = {"张三": {
                    "语文": 98,
                    "数学": 96,
                    "英语": 89},
                  "李明": {
                     "语文": 78,
                     "数学": 87,
                     "英语": 86}
}
print(f"张三的考试成绩为:{stu_score_dict['张三']}")
print(f"张三的语文考试成绩为:{stu_score_dict['张三']['语文']}")
print()
print(f"李明的考试成绩为:{stu_score_dict['李明']}")
print(f"李明的英语考试成绩为:{stu_score_dict['李明']['英语']}")
