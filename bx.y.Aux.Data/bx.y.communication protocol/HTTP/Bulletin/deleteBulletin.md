# 4.9.3    删除公告  - deleteBulletin

 *指令样例：*

```json
{
  "protocol": {
    "name": "YQ-COM2","version": "1.0",
    "remotefunction": {
      "name": "deleteBulletin"
      "input": {
        "items": ["0","1","8"]
      }
    }
  }
}
```

公告删除是依据公告序号 “order”进行匹配的，本指令删除“items”列举的公告，当“items”为["*"]时删除所有公告。