# 3.3     重启网络 - restartNetwork

*命令样例：*

```json
{
"protocol": {
 "name": "YQ-COM2",
 "version": "1.0",
 "targetpid": "50C811344D45594D4110000008AB53AD",
 "targetbarcode": "C0Y2001805150056",
 "remotefunction": {
   "name": "restartNetwork"
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
    "name": "restartNetwork",
    "networkdevice":"eth0",
    "output": {
      "minwaittime":"5",
      "maxwaittime":"10"
   }
  }
}
```

“重启网络”为非实时指令，需要告知上位机在多久之后来查询（通过登录流程）执行结果：

* "minwaittime"：等待非实时命令处理完毕所需的最小时间，以秒单位；建议在此之后开始尝试与控制卡通信

* "maxwaittime"：等待非实时命令处理完毕所需的最大时间，以秒单位