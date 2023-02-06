import random
money = 10000

for i in range(1, 21):
    num = random.randint(1, 10)
    if num < 5:
        print(f"员工{i},绩效低于5，不发工资下一位")
        continue
    else:
        if money <= 0:
            print("工资发完了，下个月领取吧")
        else:
            money -= 1000
            print(f"向员工{i}发放1000元，账号余额还剩{money}")