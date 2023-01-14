while 1:
    Account = input("请输入你的账号:")
    password = input("请输入你的密码:")

    if Account == "35196" and password == "1234":
        break
    else:
        print("密码错误,请重新输入")

print("恭喜你登录成功!")