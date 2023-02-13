"""
演示变量的类型注解
"""
import json
import random

# 基础数据类型注解
var_1: int = 10
var_2: str = "ITHEIMA"
var_3: bool = True


# 类对象类型注解
class Student:
    pass


stu: Student = Student()

# 基础容器类型注解
my_list: list = [1, 2, 3]
my_tuple: tuple = (1, 2, 3)
my_dict: dict = {"itheima": 666}

# 容器类型详细注释
my_list_2: list[int] = [1, 2, 3]
my_tuple_2: tuple[int, str, bool] = (1, "itheima", True)
my_dict_2: dict[str, int] = {"itheima": 666}

# 在注释中进行类型注解
var_4 = random.randint(1, 10)   # type: int
var_5 = json.loads('{"name": "zhangsan"}')  # type: dict[str, str]
def func():
    return 10

var_6 = func()  # type: int

# 类型注解的限制

