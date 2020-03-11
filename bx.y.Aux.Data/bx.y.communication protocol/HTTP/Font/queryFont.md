# 4.7.1    查询字库 - queryFont

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "queryFont"
    }
  }
}
```

*回复样例：*

```json
{
  "remotefunction": {
    "name": "queryFont",
    "output": {
      "systemfont": [
      {
        "fontname": [
        {
          "family":"Simsun",
          "familylang":"en"
        },
        {
          "family":"宋体",
          "familylang":"zh-cn"
        }],
        "fontstyle": [
        {
          "style":"Regular",
          "stylelang":"en"
        },
        {
          "style":"常规",
          "stylelang":"ca"
        }]
      },      {
        "fontname": [
        {
          "family":"SimHei",
          "familylang":"en"
        },
        {
          "family":"黑体",
          "familylang":"zh-cn"
        }],
        "fontstyle": [
        {
          "style":"Regular",
          "stylelang":"en"
        }]
      }],
      "customfont": [
      {
        "fontname": [
        {
          "family":"fontname1_en",
          "familylang":"en"
         },
        {
          "family":"fontname1_zh",
          "familylang":"zh-cn"
        }],
        "fontstyle": [
        {
          "style":"Regular",
          "stylelang":"en"
        },
        {
          "style":"Normal",
          "stylelang":"ca"
        }]
      },
      {
        "fontname": [
        {
          "family":"fontname2_en",
          "familylang":"en"
        },
        {
          "family":"fontname2_zh",
          "familylang":"zh-cn"
        }],
        "fontstyle": [
        {
          "style":"Regular",
          "stylelang":"en"
        }]
      }]
    }
  }
}
```

- "systemfont"返回的是控制卡内嵌字库，无法删除；"customfont"返回的是用户自行安装的字库，可以删除。所有字段均通过查询字体文件获得。

- 参数说明：

- "fontname"：字体名描述

- "family"：实际的字体名，

- "familylang"：字体名的语言，例如"en"、"zh-cn"等，与"family"一一对应

- "fontstyle"：字型风格描述

- "style"：具体风格名称，如"Regular"、"Normal"`、`"常规"`、`"粗体"等

- "stylelang"：风格名称的语言，例如"en"、"zh-cn"等，与"style"一一对应