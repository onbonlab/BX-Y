# 4.5.6    删除文件(夹) -  deleteFile

 *指令样例：*

```json
{
  "protocol": {     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "deleteFile",
      "input": {
        "items": [
          "123.jpg"，
　　　　　　　　　　　"lists/plist1.xml"
        ]
    }
    }
  }
}
```

删除"items"列表指定的文件。如果文件名中不含路径，只是文件名，则删除上传临时目录中的对应文件。