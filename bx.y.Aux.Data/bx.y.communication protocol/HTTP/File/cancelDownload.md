# 4.5.9    取消下载 - cancelDownload

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "cancelDownload",
      "input": {
        "id": "<任务id>"
    }
    }
  }
}
```

取消"id"指定的任务。"id"为空时，将`取消所有下载。**请慎用取消所有下载**。`