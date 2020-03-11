# 3.9     设置热点 - setApProperty

 *命令样例：*

```json
{
"protocol": {
 "name": "YQ-COM2",
 "version": "1.0",
 "targetpid": "50C811344D45594D4110000008AB53AD",
 "targetbarcode": "C0Y2001805150056",
 "remotefunction": {
  "name": "setApProperty",
  "input": {
   "ssid": "BX-Y03_XiZangNanLu",
   "password": "12345678",
   "apipaddress": "192.168.22.100"
   }
  }
 }
}
```

该指令用于修改控制卡WiFi AP模式下，供用户连接的热点属性：

参数说明：

-  "ssid"：用户自定义的热点名称，建议采用ASCII字符，不使用中文；不超过32位；当"ssid"为空时，表示关闭WiFi热点功能

-  "password"：用户自定义的热点密码，８~32位ASCII字符

-  "apipaddress"：WiFi AP模式下的IP地址


**该指令需要“重启网络”（restartNetwork）后生效**