"""
演示河南省疫情地图开发
"""
import json
from pyecharts.charts import Map
from pyecharts.options import TitleOpts, VisualMapOpts

# 读取文件
f = open("疫情.txt", "r", encoding="UTF-8")
data = f.read()

# 关闭文件
f.close()

# 数据转化为Python
data_dict = json.loads(data)

HeNan_province_data_list = []
# 获取河南省数据
province_data_list = data_dict['areaTree'][0]['children']
for province_data in province_data_list:
    if province_data['name'] == "河南":
        HeNan_province_data_list = province_data['children']
        break

data_list = []
# 准备数据为元组并放入list
for HeNan_province_data in HeNan_province_data_list:
    HeNan_name = HeNan_province_data['name'] + "市"
    HeNan_confirm = HeNan_province_data['total']['confirm']
    data_list.append((HeNan_name, HeNan_confirm))

# 手动添加济源市数据
data_list.append(("济源市", 5))

# 构建地图
HeNan_map = Map()

HeNan_map.add("河南省确诊人数", data_list, "河南")

# 设置全局选项
HeNan_map.set_global_opts(
    title_opts=TitleOpts(title="河南省疫情地图"),
    visualmap_opts=VisualMapOpts(
        is_show=True,
        is_piecewise=True,
        pieces=[  # 具体范围是多少
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
HeNan_map.render("河南疫情地图.html")
