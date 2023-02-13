# 设计一个类
class Student:
    name = None
    age = None
    sex = None

    def say_hi(self):           # self 类似于c++中的this关键字
        print(f"Hi大家好，我是{self.name}")

    # 加参数
    def say_hi2(self, msg):
        print(f"Hi大家好，我是{self.name}，{msg}")


# 基于类创建对象
stu_1 = Student()

# 对象属性进行赋值
stu_1.name = "徐国彩"
stu_1.age = 18
stu_1.sex = "男"

# 调用成员方法
stu_1.say_hi()

# 调用方法加参数
stu_1.say_hi2("很高兴认识大家!")
