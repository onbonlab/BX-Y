# 3.2     设置网络属性 - setNetworkOption

ü *命令样例：*

```json
{
	"protocol": {
		"name": "YQ-COM2",
		"version": "1.0",
		"targetpid": "50C811344D45594D4110000008AB53AD",
		"targetbarcode": "C0Y2001805150056",
		"remotefunction": {
			"name": "setNetworkOption",
			"input": {
				"ip": "192.168.0.199",
				"subnetMask": "255.255.255.0",
				"gateway": "192.168.0.1",
				"ipmode": "static",
				"wifiipaddress": 		"192.168.2.199",
				"wifisubnetmask":"255.255.255.0",
				"wifigateway":"192.168.2.1",
				"wificonnectmode":"static"
			}
		}
	}
}
```

该指令可设置的网络参数详见[附录1](Appendix1.md)。该指令执行后，需要继续发送“重启网络”指令才能真正生效。该指令会影响 “搜索控制器” 指令的结果，直到“重启网络”之后才会正常。