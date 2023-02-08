"""
演示全国疫情可视化地图开发
"""
import json
from pyecharts.charts import Map
from pyecharts.options import VisualMapOpts, TitleOpts

# 读取数据文件
ch_f = open("疫情.txt", "r", encoding="UTF-8")
ch_data = ch_f.read()

# 关闭文件
ch_f.close()

# 将字符串JSON转化为Python的字典
ch_data_dict = json.loads(ch_data)      # 基础数据字典

# 从字典中取各省数据
province_data_list = ch_data_dict['areaTree'][0]['children']

data_list = []      # 绘图需要用到的列表

# 组装每个省份和确认人数为元组，并各个省的数据都封装入列表内
for province_data in province_data_list:
    province_name = province_data['name'] + "省"
    province_confirm = province_data['total']['confirm']
    data_list.append((province_name, province_confirm))

# 创建地图对象
ch_map = Map()

# 添加数据
ch_map.add("各省份确诊人数", data_list, "china")

# 设置全局配置，定制分段的视觉映射
ch_map.set_global_opts(
    title_opts=TitleOpts(title="全国疫情地图"),
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
ch_map.render("全国疫情.html")
