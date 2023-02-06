# 获取1-100的随机数字
import random
num = random.randint(1, 100)

flag = True
while flag:
    guss_num = int(input("请输入你猜测的数字:"))

    if guss_num== num:
        print("猜中了！")
        flag = False
    elif guss_num > num:
        print("猜大了！")
    else:
        print("猜小了")

print("恭喜你！通关游戏!")