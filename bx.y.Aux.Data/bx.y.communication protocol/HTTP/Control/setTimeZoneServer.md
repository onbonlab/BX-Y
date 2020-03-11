# 4.3.11   设置自动授时 - setTimeZoneServer

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "setTimeZoneServer"
` `      "input": {
        "timezoneflag": "on",
        "timezone": "`Asia/Shanghai`",
        "timezoneserver": "120.24.166.46"
      }
    }
  }
}
```

参数说明：

- "timezoneflag": "on"或1 - 使能，"off"或0 - 关闭

- "timezoneserver": 设定可行的时间服务器的IP地址，可同时设置多个IP，使用","分隔。若该参数为空""，则使用默认的时间服务器（0.pool.ntp.org，1.pool.ntp.org，2.pool.ntp.org，3.pool.ntp.org）

- "timezone": 设定控制器时区，若该参数为空""，使用默认时区"Asia/Shanghai"。可以不开启自动授时功能，只单独设置时区。