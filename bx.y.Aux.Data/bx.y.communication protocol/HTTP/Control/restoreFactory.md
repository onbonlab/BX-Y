# 4.3.19   恢复出厂固件 - restoreFactory

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "restoreFactory",
      "input": {
        "saveconfig":"yes"
      }
    }
  }
}
```

该指令用于恢复固件到出厂版本。该指令同 “reboot”，是异步指令。

参数说明：

* “saveconfig”： 标识是否保存配置文件。“yes”：保存现有配置；默认保存。

*回复样例：*

```json
{
  "remotefunction": {
    "name": "restoreFactory",
    "output": {
      "minwaittime": "30",
      "maxwaittime": "50"
    }
  }
}
```

参数说明：

- “minwaittime”：最小等待时间。

- “maxwaittime”： 最大等待时间。