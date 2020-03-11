# 4.11.3   屏幕截取 - screenCapture

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name":"ScreenCapture",
      "input": {
        "suffix": "jpg",
        "framecount": "5",
        "picwidth": "800",
        "picheight": "600"
      }
    }
  }
}
```

参数说明：

- "suffix"： 截屏保存的文件类型，png - 单图截取或gif - 动画截取(耗时较长)

- "picwidth"：截取后图片的宽度

- "picheight"：截取后图片的高度，如果宽高与屏幕宽高不一样，将会做拉伸或缩小处理

- "framecount"：截取的帧数，最大15帧，"suffix"为gif时有效


*回复样例：*

```json
{
  "remotefunction":
  {
    "name": "screenCapture",
    "output":
    {
      "filepath": "share/screen.jpg"，
      "maxwaittime": "10"，
      "minwaittime": "5"
    }
  }
}
```

“屏幕截取”为非实时指令，需要告知上位机在多久之后来查询（通过“查询文件信息”指令）执行结果。

- "minwaittime"： 等待非实时命令处理完毕所需的最小时间，以秒单位

- "maxwaittime"：等待非实时命令处理完毕所需的最大时间，以秒单位

- "filepath"：截取成功后，文件的保存路径和文件名，应用于后续“查询文件信息”


上位机在收到回复后，根据最小／最大等待时间下发“查询文件信息”，以确定是否完成截屏；确认完成后，再通过“从控制卡下载文件”指令获取结果。