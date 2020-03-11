# 4.11.1   设置LED标识 -  setLedFlag

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "setLedFlag"
      "input": {
        "ledflag": "off"
      }
    }
  }
}
```

主要应用于调试屏幕，可以在屏幕的四角个正中显示“LED”字样。

参数说明：

* “ledflag”："on"或1 - 显示，"off"或0 - 不显示