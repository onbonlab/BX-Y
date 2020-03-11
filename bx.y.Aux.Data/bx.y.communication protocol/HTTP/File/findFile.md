# 4.5.3    查询文件信息- findFile

*指令样例：*

```JSON
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "findFile",
      "input": {
        "items": [
        {
          "filename": "share/123.jpg"
        },
        {
          "filename": "lists/plist1.xml"
        }]
    }
    }
   }
}
```

*回复样例：*

```json
{
  "remotefunction": {
    "name": "FindFile",
    "output": {
      "items": [
      {
        "filename": "share/123.jpg",
        "mtime": "2018-3-20 13:02:12",
        "size": "125688"
      },
      {
        "filename": "lists/plist1.xml",
  	    "mtime": "",
        "size": "0"
      }]
    }
  }
}
```

- "size"：文件的大小信息

- "mtime"：文件的最后修改时间，如果为空，表示文件不存在