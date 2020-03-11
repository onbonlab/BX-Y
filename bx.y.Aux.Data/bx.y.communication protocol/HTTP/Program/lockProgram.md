# 4.6.3    锁定/解锁节目 -  lockProgram

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "lockProgram",
      "input": {
        "programlockedstatus": "on",
        "programlockedname": "program_0"
      }
    }
  }
}
```

该命令只针对普通节目。

参数说明：

- "programlockedstatus"："lock"或1 - 锁定, "unlock"或0 - 解锁

- "programlockedname": 节目名称，由节目文件中的"name"属性指定


*回复样例：*

```json
{
"remotefunction": {
 "name": "lockProgram",
 "output": {
    "type": "true"
  }
 }
}
```

参数说明：

* "type"：对应指令中的"programlockedstatus"，true - 锁定, false - 解锁

*错误回复样例：*

```json
{
  "remotefunction": {
      "name": "lockProgram",
      "error": {
          "code": 30,
          "mesg": "Mediaplayer process lockProgram failed"}
  }
}
```

