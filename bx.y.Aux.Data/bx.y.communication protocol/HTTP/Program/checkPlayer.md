# 4.6.4    查询播放状态 - checkPlayer

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "checkPlayer"
    }
  }
}
```

*回复样例：*

```json
{
  "remotefunction":
  {
    "name": "checkPlayer",
    "output": {
      "programlist":"lists/plist1.xml",
      "programname":"program/program_1.xml",
		"insertlist":"lists/plist1.xml",
      "playstatus":"Lock"
    }
  }
}
```

参数说明：

- "programlist"：当前播放的列表文件

- "insertlist"：正处于插播时，才会返回当前正插播的列表文件

- "programname"：当前播放的节目文件

- "playstatus"：当前节目的锁定状态，"Lock"或"Unlock"