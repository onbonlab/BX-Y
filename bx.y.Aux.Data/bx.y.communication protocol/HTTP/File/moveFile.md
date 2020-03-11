# 4.5.4    移动文件(夹) - moveFile

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "moveFile",
      "input": {
        "src": "backup/file1.txt",
         "dst": "share/file2.txt"
    }
    }
  }
}
```

将源文件移动到目的文件，可用于重命名。如果源中不含路径，只是文件名，则默认将上传临时目录中的对应文件移动到目的。

**请勿用此命令修改用户工作目录下的专用目录名。**