# 4.3.4    语言设置 - setLanguage

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "setLanguage"
      "input": {
        "language": "zh_CN"
      }
    }
  }
}
```

参数说明：

*  "language":语言标识，参见[附录8](Appendix8.md)（注意：区分大小写）。

 *错误回复样例：*

```json
{
  "remotefunction": {
    "name": "setLanguage",
    "error": {
      "code": "38",
      "mesg": "Language is not supported !"
    }
  }
}
```

