# 4.8.8    直接控制继电器 - controlRelay

*指令样例：*

```json
{
  "protocol": {
    "name": "YQ-COM2",
    "version": "1.0",
    "remotefunction": {
       "name": "controlRelay",
      "input": {
        "mask": "0x00ff",
        "action": "0x00ff"
      }
    }
  }
}
```

参数说明：

-  “mask”： 需要控制的继电器掩码，16位无符号整形数，每位匹配一个继电器，为1 时需要控制对应序号的继电器，否则略过。0~7 对应#1网口下第一块多功能卡的 8 个继电器；8 和 9 对应板上两个 GPIO 控制的外接继电器；其他预留。

- “action”： 控制“mask”所匹配继电器的电平，具体是开还是关与继电器控制类型有关。