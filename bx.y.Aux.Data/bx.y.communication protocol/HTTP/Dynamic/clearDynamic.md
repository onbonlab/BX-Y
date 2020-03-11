# 4.10.3   清除动态区 - clearDynamic

 *指令样例：*

```json
{
  "protocol": {
    "name": "YQ-COM2","version": "1.0",
    "remotefunction": {
      "name": "clearDynamic",
      "input":{
        "id":["0","1"]
      }
    }
  }
}
```

清除正在播放的动态区，即停止动态区的播放并删除动态区（不会删除已经保存的动态区文件）。

* “id”： 需要清除的动态区的ID号，为["*"]全部清除。