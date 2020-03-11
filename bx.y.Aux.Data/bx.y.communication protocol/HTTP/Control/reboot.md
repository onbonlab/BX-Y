# 4.3.1    系统重启 - reboot

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "reboot"
    }
  }
}
```

 *回复样例：*

```json
{
  "remotefunction":
  {
    "name": "reboot",
    "output": {
      "minwaittime":"30",
      "maxwaittime":"50"
    }
  }
}
```

