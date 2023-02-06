"""
1. 打开文件
    f = open("C:/Project/Pycharm/test_write.txt")
2. 文件写入
    f.write("hello" world)
3. 内容刷新
    f.flush()
4. 写入会把文件内容全部清空然后写入     文件不存在就创建一个文件
"""
# 打开文件  close 内置flush
with open("test_write.txt", "w", encoding = "UTF-8") as f:
    # 文件写入  把数据写入到内存中
    f.write("hello world")

    # 内容刷新  把内存里的数据写入到硬盘中
    # f.flush()
