# 设计一个类
class Student:
    name = None     # 记录学生姓名
    age = None      # 记录学生年龄
    sex = None      # 记录学生性别


# 基于类创建对象
stu_1 = Student()
stu_2 = Student()

# 对象属性进行赋值
stu_1.name = "徐国彩"
stu_1.age = 18
stu_1.sex = "男"

stu_2.name = "徐国艳"
stu_2.age = 21
stu_2.sex = "女"

# 获取对象中记录的信息
print(f"{stu_1.name}, {stu_1.age}, {stu_1.sex}")
print(f"{stu_2.name}, {stu_2.age}, {stu_2.sex}")
