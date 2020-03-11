# 4.10.5   删除动态区文件 - deleteDynamicFile

 *指令样例：*

```json
{
  "protocol": {
    "name": "YQ-COM2","version": "1.0",
    "remotefunction": {
      "name": "StopDynamic",
      "input": {
        "id":["0","1"] 
      }
    }
  }
}
```

该指令删除已经保存的（使用”SaveDynamicFile”命令保存过的）动态区文件，重启控制器后该动态区不再重新播放。不影响在播的动态区节目。

* “id”： 需要删除的已保存的动态区的ID，为["*"]删除所有以保存的动态区。