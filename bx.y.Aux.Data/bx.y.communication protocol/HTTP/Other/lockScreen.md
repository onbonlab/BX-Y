# 4.11.4   锁定/解锁屏幕 -  lockScreen

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "lockScreen",
      "input": {
        "screenlockedstatus": "on"
      }
    }
  }
}
```

参数说明：

* "screenlockedstatus": "on"或1 - 锁定, "off"或0 - 解锁