# 3.7     查询WiFi - queryWifiStatus

 *命令样例：*

```json
{
"protocol": {
 "name": "YQ-COM2",
 "version": "1.0",
 "targetpid":  "50C811344D45594D4110000008AB53AD",
 "targetbarcode": "C0Y2001805150056",
 "remotefunction": {
   "name": "queryWifiStatus"
  }
 }
}
```

 *回复样例：*

```json
{
"targetpid":"50C811344D45594D4110000012B755AB",
"targetbarcode":"C0Y2L01805100002",
  "remotefunction": {
    "name": "queryWifiStatus",
    "networkdevice":"eth0",
    "output": {
      "wifistatus":"connected"
    }
  }
}
```

参数说明：

-  "wifistatus"：返回的 WiFi的连接状态

-  “associating”：正在关联中

-  “connected”：已连接

-  “scanning”：正在扫描中

-  “unconnected”：未连接

-  “other”：其他未知状态