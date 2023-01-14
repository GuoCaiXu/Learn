print("欢迎来到黑马动物园")
height = int(input("请输入你的身高(cm):"))

if height < 120:
    print("你的身高小于120cm，可以免费游玩")
elif int(input("请输入你的vip等级(1~5)")) > 3:
    print("你的vip等级大于3，可以免费游玩")
else:
    print("不好意思，所有条件都不满足，需要购票10元")

print("祝你游玩愉快")