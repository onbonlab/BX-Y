# 4.6.2    停止播放 - stopPlay

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "stopPlay",
      "input": {
        "type":"program",
      }
    }
  }
}
```

参数说明：

* "type"：指定停止播放的节目类型，可以为"program"-普通节目、"bulletin"-公告区节目、"dynamic"-所有在播动态区，还可以指定为"all"-全部节目，包括普通节目、公告区节目和所有在播动态区节目。停止播放公告可以使用“停播公告”命令。停止播放动态区可以使用“清除动态区”命令。

同“开始播放”指令类似，普通节目、公告区节目和动态区节目单独停止，在没有关联关系的情况下，三者互不相影响。

使用该命令停止动态区会清除所有在播的动态区。可以使用“清除动态区”命令进行指定清除。

*回复样例：*

```json
{
"remotefunction": {
  "name": "stopPlay",
  "output": {
    "type": "program"
	}
  }
}
```

*错误回复样例：*

```json
{
  "remotefunction": {
	"name": "stopPlay",
	"error": {
	"code": 30,
	"mesg": "Mediaplayer process stopPlay failed"
	}
  }
}
```

