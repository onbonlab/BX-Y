# 4.3.15   获取控制卡属性 - getProperty

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "getProperty"
      "input": {
        "controllertype": "",
        "screenonoffstatus": "",
        "firmwareversion": ""
      }
    }
  }
}
```

该指令属于查询指令，"input"中的子键即为需要查询的属性（它们的“值”均为空），个数可变。参见[附件1](Appendix1.md)。

*回复样例：*

```json
{
  "remotefunction": {
    "name": "getProperty",
    "output": {
      "controllertype": "9048",
      "screenonoffstatus": "1",
      "firmwareversion": "18051400"
    }
  }
}
```

返回所有查询参数的值，若有不存在的参数，则指令执行失败，返回错误信息。