# 4.9.5    查询公告  - queryBulletin

*指令样例：*

```json
{
  "protocol": {
    "name": "YQ-COM2","version": "1.0",
    "remotefunction": {
      "name": "queryBulletin"
    }
  }
}
```

*回复样例：*

```json
{
  "remotefunction": {
    "name": "queryBulletin",
    "output": {
      "0":"bulletin1",
      "1":"bulletin1"
    }
  }
}
```

返回当前所有的公告序号和公告名称（“公告序号”:“公告名称”）。如果没有公告，回复格式为：

```json
{
    "remotefunction": {
    "name": "queryBulletin"
  }
}
```

