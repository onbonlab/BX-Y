# 4.8.1    获取总线列表 - listSensorBus

*指令样例：*

```json
{
   "protocol": {
    "name": "YQ-COM2",
    "version": "1.0",
    "remotefunction": {
      "name": "listSensorBus"
    }
  }
}
```

*回复样例：*

```json
{
  "remotefunction": {
    "name": "listSensorBus",
    "output" : {
      "items": [
        "0x800",
        "0x2000",
        "0x8000"
      ]
    }
  }
}
```

该指令用于列举所有控制卡可能已安装传感器的总线。

参数说明：

* "items"：所有可能已安装传感器的总线首地址，参见[附录5](Appendix.md)