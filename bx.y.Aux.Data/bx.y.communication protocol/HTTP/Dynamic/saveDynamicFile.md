# 4.10.4   保存动态区文件 - saveDynamicFile

*指令样例：*

```json
{
  "protocol": {
    "name": "YQ-COM2","version": "1.0",
    "remotefunction": {
      "name": "SaveDynamicFile",
      "input": {
        "id":["0","1"]
      }
    }
  }
}
```

该指令可以保存在播的动态区文件，当控制器重启后会重新播放保存过的动态区节目。针对” URLPicture”和” URLText”类型的动态区不保存素材，只保存素材的URL，重启控制器后播放动态区时需重新下载相应素材。

* “id”： 需要保存的动态区的ID号，为["*"]保存全部在播动态区。