# 4.5.7    从URL下载文件 -  downloadFileFromURL

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "downloadFileFromURL",
      "input": {
        "failonwaitingtimeout":"10",
        "downloadmode":"queue",
        "downloadtimes":"1",
        "updatetime":"0",
        "items": [
        {
          "srcurl": "<需要下载的完整链接>",
          "dstpath": "<控制器上的目标路径>",
          "dstfilename":"<目标文件名>",
          "size": "<文件大小>"
        },
        {
          "srcurl": "<需要下载的完整链接>",
          "dstpath": "<控制器上的目标路径>",
          "dstfilename":"<目标文件名>",
           "size": "<文件大小>"
        }]
    }
    }
  }
}
```

- "items"：给出要下载的文件列表

- "srcurl"： 需要下载文件的完整、有效的URL路径，例如：

  　　　　　　ftp://[username]:[password]@[ip地址或域名]/[路径]/[文件名]

  　　　　　　http://[username]:[password]@[ip地址或域名]/[路径]/[文件名]

- "dstpath"：控制器上工作目录中的相对路径，如：share/

- "dstfilename"：需要保存的文件名

- "size"：文件大小

- downloadmode：文件下载方式，"queue"-`文件按队列一次下载；`"batch"-`文件批量下载，最多三个文件同时下载。

- downloadtimes：文件下载次数，0-`不限次数，重复下载；大于等于`1-`下载次数达到后将任务置为完成。这里的下载次数是指成功的次数。较为常用的是为`1-单次下载，普通任务只需要下载一次。（**注：所有非单次下载的文件总大小不能超过50兆**)

- "failonwaitingtimeout"：超时时间，以秒为单位。如果`超时时间到，下载任务仍处于等待下载状态则置为下载失败状态；设`0将禁用该功能，任务将一直等待，直至下载完成或被取消。

- "updatetime"：重复下载时，两次下载的间隔时间；"downloadtimes"非1时起效，须大于"failonwaitingtimeout"


 

*回复样例：*

```json
{
  "remotefunction": {
    "name": "downloadFileFromURL",
    "output": {
      "id": "下载任务id"
    }
  }
}
```

返回的"id"用于后续查询进度、取消任务等操作。