# 4.6.5    清除无用素材 - clearUselessMaterial

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "clearUselessMaterial"
    }
  }
}
```

删除当前播放列表相关文件以外的所有播放列表文件、节目文件和素材文件。如果，控制卡处于停播状态，该指令将删除所有播放列表文件、节目文件和素材文件。该指令只影响lists、programs和share目录下的文件，并不遍历其他目录。所以，**节目相关文件尽量放在这三个目录中。**