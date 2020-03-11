# 4.11.2   设置开机画面 - setLogo

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "setLedFlag",
      "input": {
        "logoflag": "on",
      "filepath": "share/123.bon",
        "logopos": "center"
      }
    }
  }
}
```

该指令尚未实现，BX-Y系列暂不支持开机画面。

参数说明：

- “logoflag”："on"或1 - 使用自定义开机画面，"off"或0 - 使用出厂开机画面；如果需要禁止开机画面，请发送全黑图片

-  “filepath”： 开机画面Logo图片路径

- “logopos”： "fullscreen"，全屏，按屏幕尺寸缩放；"center"，居中，保持图片比例；"topleft"，左上角放置，图片只缩不放，不保持图片比例。


 