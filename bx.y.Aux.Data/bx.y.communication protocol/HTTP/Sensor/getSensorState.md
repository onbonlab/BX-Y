# 4.8.4    获取传感器状态 - getSensorState

*指令样例：*

```json
{
  "protocol": {
    "name": "YQ-COM2",
    "version": "1.0",
    "remotefunction": {
      "name": "getSensorState",
      "input": {
        "sequence": "1",
        "sensorAddress": "0x8000"
      }
    }
  }
}
```

*回复样例：*

```json
{
  "remotefunction":  {
    "name": "getSensorState",
    "output":  {
      "sequence": "1",
      "sensorAddress": "0x8000",
      "sensorState": "0xFF",
      "value": "12345",
      "level": "23" 
    }
  }
}
```

参数说明：

- "sequence"：传感器功能序号，参见[附录6](Appendix6.md)

- "sensorAddress"：传感器地址，参见[附录 5](Appendix5.md)

- "sensorState": 传感器是否在线（一般为在线），0xFF - 在线，0x00 – 不在线

- "value"：传感器值，未配置过时使用默认配置；整形或浮点型的字符串

- "level"：亮度等级，"sequence"为"1"（亮度传感器）时的额外值