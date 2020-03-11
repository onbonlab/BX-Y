# 4.6.6    删除所有节目 - clearAllProgram

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "clearAllProgram",
      "input": {
        "keepmaterial":"yes"
      }
    }
  }
}
```

参数说明：

* "keepmaterial"：保留素材标志。"yes":保留，"no"：不保留。

该指令停止播放所有节目，并删除所有类型节目的播放列表和节目素材（可选）。