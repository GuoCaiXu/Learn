在终端输入命令：

```linux
sudo passwd root
```

&nbsp;
会显示以下内容，根据内容输入：

```linux
1.  [sudo] password for kerwin:               #输入当前用户密码
2.  New password:                             #输入root新密码
3.  Retype new password:                      #再次输入root密码
4.  passwd: password updated successfully     #密码更新成功
```

&nbsp;
root密码设置完成了，输入

```linux
su root
```

即可切换到root用户，能切换到证明修改成功
