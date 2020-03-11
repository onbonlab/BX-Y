# 4.8.3    获取传感器列表 - listSensor

*指令样例：*

```json
{
  "protocol": {
    "name": "YQ-COM2",
    "version": "1.0",
    "remotefunction": {
      "name": "listSensor"
    }
  }
}
```

*回复样例：*

```json
{
  "remotefunction": {
    "name": "listSensor",
    "output" : {
      "sensorList": [{
        "sequence": "0x01",
        "sensorAddress": "0x823",
        "sensorState": "0xFF",
        "value": "456"
      }, 
      {
        "sequence": "0x03",
        "sensorAddress": "0x8000",
        "sensorState": "0xFF",
        "value": "78.5"
      }]
    }
  }
}
```

返回最后一次"searchSensor"指令的结果。

参数说明：

- "sequence"：传感器功能序号，参见[附录6](Appendix6.md)

- "sensorAddress"：传感器地址，参见[附录 5](Appendix.md)

- "sensorState"：传感器是否在线（一般为在线），0xFF - 在线，0x00 – 不在线

- "value"：传感器值，未配置过时使用默认配置；整形或浮点型的字符串