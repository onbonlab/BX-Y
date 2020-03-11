# 4.8.2    搜索传感器 - searchSensor

*指令样例：*

```json
{
"protocol": {
	"name": "YQ-COM2",
	"version": "1.0",
	"remotefunction": {
		"name": "searchSensor"
		"input": {
			"sensorBus":[
			  "0x8000",
			  "0x800" ]
			}
		}
	}
}
```

异步指令，需配合"listSensor"指令使用。

参数说明：

* "sensorBus"：可能已安装传感器的总线列表，一般都在"listSensorBus"返回的结果中；当其中含有"*"时，查询所有支持/已接入的传感器总线

*回复样例：*

```json
{
"remotefunction": {
	"name": "searchSensor",
	"output" : {
		"minwaittime": "5",
		"maxwaittime": "15"
		}
	}
}
```

