# 4.3.10   设置输出方式 - setOutputType

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "setOutputType"
      "input": {
        "outputtype": "LCD"
      }
    }
  }
}
```

BX-Y系列暂不支持切换输出方式。

参数说明：

* "outputtype": 输出方式，"LCD"或"DVI"("HDMI")