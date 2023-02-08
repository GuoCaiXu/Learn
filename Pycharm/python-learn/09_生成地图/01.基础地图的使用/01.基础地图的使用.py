"""
演示地图可视化的基本使用
"""

from pyecharts.charts import Map
from pyecharts.options import VisualMapOpts

# 准备地图对象
ch_map = Map()

# 准备数据
data = [
    ("北京市", 99),
    ("上海市", 199),
    ("湖南省", 299),
    ("台湾省", 399),
    ("广东省", 499)
]

# 添加数据
ch_map.add("测试地图", data, "china")

# 设置全局选项
ch_map.set_global_opts(
    visualmap_opts=VisualMapOpts(
        is_show=True,        # 是否显示可视化
        is_piecewise=True,   # 开启手动校准范围
        pieces=[             # 具体范围是多少
            {"min": 1, "max": 9, "label": "1-9人", "color": "#CCFFFF"},
            {"min": 10, "max": 99, "label": "10-99人", "color": "#FFFF99"},
            {"min": 100, "max": 499, "label": "99-499人", "color": "#FF9966"},
            {"min": 500, "max": 999, "label": "499-999人", "color": "#FF6666"},
            {"min": 1000, "max": 9999, "label": "1000-9999人", "color": "#CC3333"},
            {"min": 10000, "label": "10000以上", "color": "#990033"}
        ]
    )
)

# 绘图
ch_map.render()
