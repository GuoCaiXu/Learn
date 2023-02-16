# **1_配置用户资料**

### **&emsp;1.配置一个全局的用户名和邮箱**

```git
# 配置你的用户名
git config --global user.name "你的用户名"

# 配置你的邮箱
git config --global user.email "你的邮箱"

# 查看全局配置
git config --list
```

&nbsp;
### **&emsp;2.生成公钥**

```git
ssh-keygen -t rsa -C "邮箱地址"
```

&nbsp;
# **2_创建仓库**

### **&emsp;目录中创建新的 Git 仓库**

```git
git init
```

&nbsp;
### **&emsp;克隆仓库**

```git
git clone SLR
```

&nbsp;

# **3_远程库**

### **&emsp;1.关联一个远程库**

```git
git remote add origin SLR标识
```

&nbsp;
### **&emsp;2.查询远程信息**

```git
git remote -v
```

&nbsp;
### **&emsp;3.删除远程库**

```git
git remote rm SLR标识
```

&nbsp;
# **4_分支**

### **&emsp;1.查看分支**

```git
git branch
```

&nbsp;
### **&emsp;2.删除分支**

```git
git branch -d 分支名      # 如果分支有内容就不能删除，需要强制删除

git branch -D 分支名      # 强制删除分支
```


&nbsp;
### **&emsp;3.切换到该分支**

```git
git checkout 分支名

git checkout -b 分支名     # 创建并切换到该分支
```

&nbsp;
### **&emsp;4.把分支合并到当前分支**

```git
git merge 分支名
```

&nbsp;
### **&emsp;5.查看树状图**

```git
tree
```

&nbsp;
### **&emsp;6.查看文件提交到哪个地方**

```git
git log
```

&nbsp;
# **5_文件仓库操作**

### **&emsp;1.查看修改状态(管理区，工作区)**

```git
git status
```

&nbsp;
### **&emsp;2.将文件添加进工作缓存区**

```git
git add -A
```


&nbsp;
### **&emsp;3.将文件添加到仓库**

```git
git commit -m "文件说明"
```

&nbsp;
### **&emsp;4.查看已经删除的记录**

```git
git reflog
```

&nbsp;
### **&emsp;5.回退到该代码名版本**

```git
git reset --hard 代码名
```

&nbsp;
# **6_上传远程库**

### **&emsp;1.关联后第一次发送master分支所有内容**

```git
git push -u origin master
```

&nbsp;
### **&emsp;2.往线上仓库提交对象**

```git
git push
```

&nbsp;
### **&emsp;3.拉取线上最新版本，同步远程库**

```git
git pull
```
