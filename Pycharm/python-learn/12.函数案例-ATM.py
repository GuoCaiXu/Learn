name = "徐国彩"
money = 5000000

# 查询余额函数
def Show_money():
    print(f"尊敬的{name}，您账号的余额为:{money}")

    return None


def Save_money():

    global money

    money_temp = int(input("请输入你要存款的数额:"))
    money += money_temp
    print(f"{name}账号存款{money_temp}成功!")

    return None


def Take_money():

    global money

    money_temp = int(input("请输入你要取款的数额:"))
    num = money - money_temp
    if num <= 0:
        print("取款失败！账户余额不足！")
    else:
        money -= money_temp
        print(f"{name}账号取款{money_temp}成功!还剩{money}!")
    return None


print("欢迎使用ATM机!")
while True:

    name_temp = input("请输入你的名字查询账号:")

    if name_temp == name:
        while True:
            print()
            print("1.查询余额")
            print("2.存款")
            print("3.取款")

            Cmd = int(input("请输入你要选择的操作:"))
            if Cmd == 1:
                Show_money()
            elif Cmd == 2:
                Save_money()
            elif Cmd == 3:
                Take_money()
            else:
                print("操作有误!")
    else:
        print("账号不存在请重新输入!")