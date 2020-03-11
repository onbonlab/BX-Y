# 4.7.2    安装字库 - installFont

*指令样例：*

```json
{
    "protocol": {
        "name": "YQ-COM2",
        "version": "1.0",
        "remotefunction": {
            "name": "installFont",
            "input": {
                "items":["fonts/a.ttf","share/b.ttf"]
            }
        }
    }
}
```

参数说明：

* "items ：需要安装的字体文件路径列表

需要提前将字库文件上传到控制卡中，可以是用户目录中任意位置，建议使用"fonts"目录。如果不在"fonts"下，该指令执行时会自动将其移动到"fonts"目录中。

*回复样例：*

```json
{
  "remotefunction":
  {
    "name": "installFont",
    "output": {
      "minwaittime":"5",
      "maxwaittime":"15"
    }
  }
}
```

