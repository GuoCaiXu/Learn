### **1.安装SSH**

&nbsp;
##### 查看SSH的版本：
```linux
ssh -V
```

&nbsp;
##### SSH 服务器的安装：

```linux
sudo apt-get install openssh-server
```

&nbsp;
##### SSH 客户端的安装：

```linux
sudo apt-get install openssh-client
```

&nbsp;
##### 启动SSH服务：

```linux
sudo service ssh start或者sudo service ssh restart
```

&nbsp;
##### 关闭SSH服务：

```linux
service ssh start或service sshd stop
```

&nbsp;
### **CMD远程连接Linux出现## Permission denied(publickey,password)解决方法**

&nbsp;
##### 1.修改配置文件：

```linux
vim /etc/ssh/sshd_config
```

&nbsp;
![[Pasted image 20230216175619.png]]
##### 2.输入i进入编辑模式，将28行代码中prohibit-password 修改为yes,修改效果如下图，点击ESC键，输入:wq保存文件

&nbsp;
**<font color=Crimson>如果:wq 保存不了就输入：</font>**

```linux
w ! sudo tee %
```

&nbsp;
##### 3. 重启ssh服务：

```linux
/etc/init.d/ssh restart
```

&nbsp;
##### 4. CMD重新连接即可：

```linux
ssh root@ip地址
```
