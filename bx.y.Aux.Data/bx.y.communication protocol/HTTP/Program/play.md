# 4.6.1    开始播放 - play

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "play",
      "input": {
        "type":"program",
        "playlist": "lists/plist1.xml"
      }
    }
  }
}
```

参数说明：

* "type"：指定开始播放的节目类型，可以为"program"-普通节目、"bulletin"-公告区节目、"dynamic"-保存过的动态区节目（控制器会先清除内存在播的所有动态区），还可以指定为"all"-全部节目，包括普通节目、公告区节目和保存过的动态区节目。播放公告有单独的指令“播放公告”。动态区播放使用“更新播放动态区”命令。

* "playlist"： 只适用于普通节目"program"；为空时，控制卡会自动搜索可用播放列表。

普通节目、公告区节目和动态区节目是单独控制播放，在没有关联关系的情况下，三者互不相影响。

使用该命令只能播放已经保存过的动态区，并同时清除在播的内容中的所有动态区。

控制器重启后，会自动播放”playlist”指定的普通节目、未删除（“删除公告”命令）的公告、以及保存过的动态区（“保存动态区文件”命令）。

*回复样例：*

```json
{
"remotefunction": {
  "name": "play",
  "output": {
    "message": "lists/plist1.xml",
    "type": "program"
	}
  }
}
```

*错误回复样例：*

```json
{
  "remotefunction": {
	"name": "play",
	"error": {
	  "code": 30,
	  "mesg": "Mediaplayer process play failed"
	  }
	}
}
```

