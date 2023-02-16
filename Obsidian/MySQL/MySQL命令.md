
**<font color=Crimson>注意：[ ]内的内容可写可不写，[ ]不用加上</font>**

# **1_连接数据库**

```CMD
MySQL -u root -p
```

&nbsp;
# **2_注释**

```SQL
# 单行注释

-- 单行注释

/*
多行
注释
*/
```


&nbsp;
# **3_ DDL**

## **_1_DDL-库管理**

### **1_查看数据库**

```SQL
show databases;
```

### **2_使用数据库**

```SQL
use 数据库名称;
```

### 3_创建数据库

```SQL
create database 数据库名称 [charset utf8];    # 一般charset utf8 写上去比较好
```

### **4_删除数据库**

```SQL
drop database 数据库名称;
```

### **5_查看当前使用的数据库**

```SQL
select database();
```

&nbsp;
## **_2_DDL-表管理**

### **1.查看有哪些表**

```SQL
show tables;    # 要先选择数据库
```

### **2.删除表**

```SQL
# 方法1
drop table 表名称;

# 方法2
drop table if exists 表名称;
```

### **3.创建表**

```SQL
create table 表名称(
	列名称 列类型,
	列名称 列类型，
	......
);

# --列表类型有
int                         # --整数
float                       # --浮点数
varchar(length)             # --length表示长度，文本，长度为数字，做最大长度限制
date                        # --日期类型
timestamp                   # 时间戳类型
```

&nbsp;
# **4_DML**

### **1.数据插入insert**

```SQL
insert into 表(列1, 列2, ......, 列N) values(值1, 值2, ......, 值N), (值1, 值2, ......, 值N);      # SQL写字符串时只能用''包围
```

### **2.数据删除**

```SQL
# 基础数据删除
delete from 表名称 [where 条件判断];

# 删除整个表的数据
delete from 表名称;
```

### **3.数据更新**

```SQL
# 基础数据更新
update 表名 set 列=值 [where 条件判断];

# 表中的全部列的值
update 表名 set 列=值;
```

&nbsp;
# **_5_DQL**

### **1.基础数据查询**

```SQL
# 基础数据查询
select 字段列表 from 表;

# 查询表中所有的列
select * from 表;

# 查询数据条件判断
select * from 表 where 条件判断;
```

### **2.分组聚合**

```SQL
select 字段 | 聚合函数 from 表 [where 条件] group by 列;

# 聚合函数有：
- sum(列)       # 求和
- avg(列)       # 求平均值
- min(列)       # 求最小值
- max(列)       # 求最大值
- count(列 | *) # 求数量
```

### **3.排序和分页的查询**

```SQL
# 除第一行, 每一行可写可不写
select 列 | 聚合函数 | * from 表
where ...
group by ...
order by ... [asc | desc]    # asc 表示从小到大(升序)， desc表示从大到小(降序)
limit n[, m];                # 只写n展示前n条，加上m 从n+1开始取m条
```
