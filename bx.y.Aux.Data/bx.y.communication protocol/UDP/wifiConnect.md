# 3.6     连接WiFi - wifiConnect

 *命令样例：*

```json
{
"protocol": {
 "name": "YQ-COM2",
 "version": "1.0",
 "targetpid": "50C811344D45594D4110000008AB53AD",
 "targetbarcode": "C0Y2001805150056",
  "remotefunction": {
   "name": "wifiConnect",
   "input": {
    "ssid": "ChinaNet-8E20",
    "psk": "12345678"
   }
  }
 }
}
```

参数说明：

-  "ssid"： 需要连接的热点名称

-  "psk"：需要连接的热点的密码


 *回复样例：*

```json
{
"targetpid":"50C811344D45594D4110000012B755AB",
"targetbarcode":"C0Y2L01805100002",
  "remotefunction": {
    "name": "wifiConnect",
    "networkdevice": "eth0",
    "output": {
      "minwaittime":"3",
      "maxwaittime":"9"
    }
  }
}
```

“连接热点”为非实时指令，需要告知上位机在多久之后来查询（通过“查询WiFi连接状态”指令）执行结果：

-  minwaittime： 等待非实时命令处理完毕所需的最小时间，以秒单位

-  maxwaittime：等待非实时命令处理完毕所需的最大时间，以秒单位


例外：如果连接的 “ssid” 和 “psk”均为改变，控制卡会以通用的成功回复格式回复：

```json
{
"targetpid":"50C811344D45594D4110000012B755AB",
"targetbarcode":"C0Y2L01805100002",
  "remotefunction": {
    "name": "wifiConnect",
    "networkdevice": "eth0"
  }
}
```

