"""
有字符串："万过薪月，员序程马黑来，nohtyp学"
得到"黑马程序员"
"""

my_str = "万过薪月，员序程马黑来，nohtyp学"

# 倒序字符串，切片取出
result1 = my_str[::-1][9:14]
print(f"方式1的结果：{result1}")

# 切片取出，然后倒序
result2 = my_str[5:10][::-1]
print(f"方式2的结果：{result2}")

# split分隔 “,” replace 替换“来”为空格
my_str = "万过薪月，员序程马黑来，nohtyp学"
new_list = my_str.split("，")[1].replace("来", "")[::-1]
print(f"方式3结果为：{new_list}")
