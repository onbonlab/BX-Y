# 4.3.3    校对时间 - systemClockCorrect

 *指令样例：*

```json
{
  "protocol": {
  "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "systemClockCorrect"
      "input": {
		"datetime": "2018-5-15 13:59:59"，
		"isutc": "yes"
      }
    }
  }
}
```

参数说明： 

-  "datetime":　格式与Linux设置系统时间命令“date”的格式相同，如"yyyy-MM-dd hh:mm:ss"

-  "isutc":　设置是否以UTC时间校正控制器时间。"yes":以UTC时间进行校正，"no":以本地时间（控制卡上的时区设置为准）进行校正。 