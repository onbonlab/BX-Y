# 3.10    切换服务器模式 - switchServerMode

 *命令样例：*

```json
{
"protocol": {
 "name": "YQ-COM2",
 "version": "1.0",
 "targetpid": "50C811344D45594D4110000008AB53AD",
 "targetbarcode": "C0Y2001805150056",
 "remotefunction": {
  "name": "switchServerMode",
  "input": {
   "servermode": "off"
   }
  }
 }
}
```

该指令一般在使用“设置控制器属性”正确设置相关参数后使用。普通服务器模式需要正确设置："serverip"和"serverport"；云服务器模式需要正确设置："cloudip"、"cloudport"和"clouduserid"。

参数说明：

-  "servermode"：需要切换的服务器模式

-  "off"-关闭所有服务器模式

-  "server"-切换至普通服务器模式，

-  "cloud"- 切换至云服务器模式