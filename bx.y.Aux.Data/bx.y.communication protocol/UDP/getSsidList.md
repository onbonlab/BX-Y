# 3.5     获取无线热点列表 - getSsidList

*命令样例：*

```json
{
	"protocol": {
		"name": "YQ-COM2",
		"version": "1.0",
		"targetpid": "50C811344D45594D4110000008AB53AD",
		"targetbarcode": "C0Y2001805150056",
		"remotefunction": {
			"name": "getSsidList"
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
    "name": "getSsidList",
    "networkdevice":"eth0",
    "output": {
      "items": [
     {
        "ssid": "NETGEAR40",
        "signallevel": "-60"
      },
      {
        "ssid": "ChinaNet-8E20",
        "signallevel": "-75"
      }]
    }
  }
}
```

该指令返回周边热点列表，包含热点名称与信号强度，列表长度不定，可能为空。

参数说明：

* "ssid"：热点名称

* "signallevel"：热点的信号强度（单位：dB）