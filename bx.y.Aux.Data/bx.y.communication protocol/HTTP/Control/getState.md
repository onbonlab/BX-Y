# 4.3.17   获取控制卡状态 - getState

*指令样例：*

```json
{
	"protocol": {
		"name": "YQ-COM2","version": "1.0",
		"remotefunction": {
		"name": "getState",
		"input": {
		 "rtctime": "",
		 "gps": {
		  "longitude": "",
		  "latitude": "",
		  "altitude": "",
		  "angle": "",
		  "speed": ""
		  }
		 }
		}
	}
}
```

参数说明：

- "rtctime"：需要返回RTC时间。

- "gps"：需要返回GPS信息。

  该指令属于查询指令，用于查询控制器运行当前时刻状态。"input"中的子键即为需要查询的属性（它们的“值”均为空），个数可变。目前支持"rtctime"和"GPS"信息的查询。

*回复样例：*

```json
{
	"remotefunction": {
		"name": "getState",
		"output": {
			"rtctime": "2011-8-30 9:50:38",
			"gps": {
				"longitude": "N3110.716557",
				"latitude": "E12123.715604",
				"altitude": "42.7",
				"angle": "232.0",
				"speed": "0.0"
			}
		}
	}
}
```

参数说明：

- "rtctime"：RTC时间。

- "gps"：GPS信息。包含以下属性：

- "longitude"：经度，E/Wdddmm.mmmmmm 度分。

- "latitude"：纬度，N/Sddmm.mmmmmm 度分。

- "altitude"：海拔高度。范围 -9999.9 ~ 99999.9米。

- "angle"：方位角。范围 0.0° ~ 359.9°。

- "speed"：速度。单位：km/h。