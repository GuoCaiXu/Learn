"""
演示JSON数据和Python字典的互相转换
"""

import json

# 准备列表，列表中每一个元素都是字典，将其转化为JSON
data = [{"name": "张大山", "age": 11}, {"name": "王大锤", "age": 13}, {"name:": "赵小虎", "age": 16}]
json_str = json.dumps(data, ensure_ascii=False)     # ensure_ascii=False 不使用ASCII码转化，直接输出
print(type(json_str))
print(json_str)

# 准备字典，将字典转化为JSON

# 将JSON字符串转化为Python 数据类型[{k: v, k: v}, {k: v, k: v]

# 将JSON字符串转换为Python 数据类型{K: v, k: v}
