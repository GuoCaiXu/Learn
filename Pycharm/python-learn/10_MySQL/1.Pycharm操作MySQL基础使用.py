"""
演示Python pymysql库的基础操作
"""
from pymysql import Connection

# 构建到MySQL数据库的链接
conn = Connection(
    host="localhost",       # 主机名(IP)
    port=3306,              # 端口
    user="root",            # 账户
    password="xgc030920"    # 密码
)

# print(conn.get_server_info())
# 执行非查询性质SQL
cursor = conn.cursor()          # 获取到游标对象

# 选择数据库
# conn.select_db("test")
conn.select_db("world")

# 执行查询性质SQL
# cursor.execute("create table test_pymysql(id int);")    # 创建一个表
cursor.execute("select * from student")

result: tuple = cursor.fetchall()
print(result)

# 关闭链接
conn.close()
