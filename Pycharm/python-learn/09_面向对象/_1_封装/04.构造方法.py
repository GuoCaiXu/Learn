"""
演示类的构造方法
"""

class Student:
    name = None     # 姓名
    age = None      # 年龄
    tel = None      # 手机号

    # 演示使用构造方法对成员变量进行赋值
    def __init__(self, name, age, tel):
        self.name = name
        self.age = age
        self.tel = tel
        print("Student类创建了一个对象!")


stu_1 = Student("徐国彩", "19", "19167757371")

print(f"{stu_1.name}, {stu_1.age}, {stu_1.tel}")
