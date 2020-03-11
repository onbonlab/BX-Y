# 4.5.5    复制文件(夹) - copyFile

 *指令样例：*

```
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "copyFile",
      "input": {
        "src": "backup/file1.txt",
         "dst": "share/file2.txt"
      }
    }
  }
}
```

将源文件复制到目的文件。如果源中不含路径，只是文件名，则默认将上传临时目录中的对应文件复制到目的。