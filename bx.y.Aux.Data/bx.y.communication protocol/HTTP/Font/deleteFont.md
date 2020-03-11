# 4.7.4    删除字库 - deleteFont

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "deleteFont",
      "input": {
        "items":["SimSun"]
      }
    }
  }
}
```

* "items"列表中的每一个子项为字体名称，建议采用英文的名称。由于一个字库文件中可能含有多个字体，删除指定字体，实际上删除的是该字体对应的字库文件，因此该字库文件中含有的所有字库都会被删除。该指令还在完善中，存在缺陷。