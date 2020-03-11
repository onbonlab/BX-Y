# 4.7.3    检查字库 - queryFontExist

*指令样例：*

```json
{
"name": "queryFontExist",
    "input": {
        "items": [
            {"fontname": "SimSun"},
            {"fontname": "SimHei"}]
  }
}
```

*回复样例：*

```json
{
  "name": "queryFontExist",
  "output": {
    "items": [
    {
      "fontname": "SimSun",
      "status": "exist"
    },
    {
      "fontname": "SimHei",
      "status": "notfound"
    }]
}
}
```

 

检查字库是否存在，"fontname"指定了要检查的字体名。

- "fontname"：需要查询的字体名

- "status"：检查结果，"exist" – 存在/已安装成功， "notfound" – 不存在