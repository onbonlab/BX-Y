# 4.5.2    查询临时文件信息 - findTempFile

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "findTempFile",
      "input": {
        "filename": "123.jpg"
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
      "filename": " 123.jpg",
      "size": "125688"
      }
    }
  }
}
```

在上传临时目录中查询指定文件，用于上传文件流程中。 “size”为0，表示文件不存在或文件大小就为0字节。

 