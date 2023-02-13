"""
演示Python内置的各类魔术方法
"""


class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    # __str__字符串方法
    def __str__(self):
        return f"姓名:{self.name}, 年龄:{self.age}"

    # __lt__大小于比较方法
    def __lt__(self, other):
        return self.age < other.age     # 也可以 >

    # __le__大于等于和小于等于比较符号方法
    def __le__(self, other):
        return self.age <= other.age    # 也可以 >=

    # __eq__比较运算符实现方法
    def __eq__(self, other):
        return self.age == other.age


stu1 = Student("徐国彩", 19)
stu2 = Student("徐国艳", 21)
stu3 = Student("张三", 19)

# __str__字符串方法
print(stu1)
print(str(stu1))
print()

# __lt__大小于比较方法
print(stu1 < stu2)
print(stu1 > stu2)
print()

# __le__大于等于和小于等于比较符号方法
print(stu1 >= stu2)
print(stu1 <= stu2)
print(stu1 >= stu3)
print()

# __eq__比较运算符实现方法
# print(stu1 == stu3)     # 未使用__eq__魔术方法两个年龄相等 输出：False
print(stu1 == stu3)       # 使用后 输出：True
print()
