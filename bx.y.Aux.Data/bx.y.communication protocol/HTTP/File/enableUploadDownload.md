# 4.5.1    开启/关闭文件上传/下载 - enableUploadDownload

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "enableUploadDownload",
      "input": {
        "type": "upload",
        "flag": "on"
      }
    }
  }
}
```

参数说明：

- "type"：类型，"upload" - 上传，"download" - 下载

- "flag"："on"或1 - 开启，"off"或0 - 关闭


举例：

{ "type":"upload","flag":"on"} : 开启文件上传通道

{ "type":"download","flag":"off"} : 关闭文件下载通道

上传文件流程（参见[5.2章节](Process/Upload.md)）：

1)     开启文件上传通道后（默认关闭）

2)     通过HTTP POST方式上传文件，可供上传的URL路径：

http://控制卡IP[:控制卡端口80]/upload

3)     上传完成后，关闭通道

下载文件流程：

1)     开启文件下载通道后（默认关闭）

2)     通过HTTP GET方式下载文件， URL路径：

http://控制卡IP[:控制卡端口80]/download/[文件路径]

3)     下载完成后，关闭通道

开启下载通道后，在浏览器中输入http://控制卡IP[:控制卡端口80]/download，可以浏览控制卡用户路径。

 