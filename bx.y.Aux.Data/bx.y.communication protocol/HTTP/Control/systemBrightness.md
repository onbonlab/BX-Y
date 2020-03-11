# 4.3.12   即时调亮 - systemBrightness

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "systemBrightness"
      "input": {
        "brightness": "255",
        "changemode": "yes"
      }
    }
  }
}
```

参数说明：

- "brightness"：需要调节的亮度值， 范围是 1～255，255为最亮

- "changemode"：是否需要改变调亮模式。"yes" - 同时更改调亮模式为手动调亮；"no" - 临时调整亮度，不改变原来的调亮模式。默认为"yes"。