# 4.5.8    查询下载进度 - queryDowloadProgress

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "queryDownloadProgress",
      "input": {
        "id": "下载任务id"
    }
    }
  }
}
```

“从URL下载文件”指令返回的<任务id>。

*回复样例：*

```json
{
  "remotefunction":
  {
    "name": "queryDownloadProgress",
    "output": {
      "id": "<任务id>",
      "status": "failure",
      "rate": "10",
      "errorinfo": [
      {
        "url": "<下载出错的url>",
        "message": "<错误信息>"
      },
      {
        "url": "<下载出错的url>",
        "message": "<错误信息>"
      }]
    }
  }
}
```

参数说明：

- ``"id"：任务id``
- ``"status"：下载状态``

- `"waiting"：`等待下载中
- "downloading"：`正在下载中`

- "complete"：`下载已完成`

- `"failure"：`下载失败
- ``"notfound"：<任务id >指定的`任务不存在```

- "rate"：千分比形式的总下载进度，0～1000

- "errorinfo"：出错的信息，"status"为"failure"时才存在，并以列表形式给出

- "url"：出错的url

- "message"：出错的信息