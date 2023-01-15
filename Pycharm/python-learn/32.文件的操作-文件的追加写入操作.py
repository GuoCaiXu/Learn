# 写入不清空文件内容，追加上去    文件不存在就创建一个文件

f = open("test_write.txt", "a", encoding = "UTF-8")

f.write("\n追加文件实验!")

f.flush()

f.close()
