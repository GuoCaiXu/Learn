"""
演示类和对象的关系，即面向对象的编程套路
"""

# 设计一个闹钟类
class Clock:
    id = None       # 序列号
    price = None    # 价格

    def ring(self):
        import winsound         # 导入包，可以让电脑发出声音
        winsound.Beep(2000, 1000)         # 2000表示频率，1000表示持续时间

# 构建2个闹钟对象并让其工作
clock1 = Clock()
clock1.id = "003032"
clock1.price = 19.99
print(f"闹钟ID：{clock1.id}，价格为：{clock1.price}")
clock1.ring()

clock2 = Clock()
clock2.id = "003033"
clock2.price = 19.99
print(f"闹钟ID：{clock2.id}，价格为：{clock2.price}")
clock2.ring()

