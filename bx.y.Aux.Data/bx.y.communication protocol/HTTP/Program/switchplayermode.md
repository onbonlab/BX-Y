# 4.6.9    切换播放模式 - switchplayermode

*指令样例：*

```json
{
  "protocol": {
	"name": "YQ-COM2","version": "1.0",
	"remotefunction": {
		"name": "switchplayermode",
		"input": {
		"playermode":"normal"
		}
	}
  }
}
```

参数说明：

* "playermode"：播放模式。"normal/0":异步模式，"sync/1":同步模式。

附加说明：

当前只有BX-Y5E支持该指令，其他型号接收到该指令会回复错误。

同步模式下，屏蔽异步节目播放指令(Play、UpdateDynamic、UpdateDynamicUnits)，回复错误。

同步模式下，不支持U盘节目播放和导入。