# 4.3.6    设置定时开关屏幕 - customScreenOnOff

 *指令样例：*

```json
{
  "protocol": {
"name": "YQ-COM2","version": "1.0",
"remotefunction": {
      "name": "customScreenOnOff"
      "input": {
        "items": [{
          "starttime": "07:00:00",
          "action": "on"
        }, {
          "starttime": "07:59:59",
          "action": "off"
        }, {
          "starttime": "13:00:00",
          "action": "on"
        }, {
          "starttime": "13:59:59",
          "action": "off"
        }]
      }
    }
  }
}
```

参数说明：

-  "starttime":　以"hh:mm:ss"格式给出的时间节点

-  "action":　"on"或1 - 开机，"off"或0 - 关机


本指令以定义多组动作的方式给出，最多支持８组。