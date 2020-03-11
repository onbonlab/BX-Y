# 4.8.6    取消绑定继电器 - unbindRelay

*指令样例：*

```json
{
  "protocol": {
    "name": "YQ-COM2",
    "version": "1.0",
    "remotefunction": {
      "name":"unbindRelay",
      "input": {
        "sensorList": [
        {
          "sequence": "2",
          "sensorAddress": "0x8000"
        }, 
         {
          "sequence": "0x03",
          "sensorAddress": "0x8000"
        }]
      }
    }
  }
}
```

参数说明：

* “sensorList”：需要取消继电器绑定关系的传感器列表，当其为[“*”]表示取消所有继电器绑定关系