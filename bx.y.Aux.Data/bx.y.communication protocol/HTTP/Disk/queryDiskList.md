# 4.4.1    查询可用介质列表 - queryDiskList

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "queryDiskList"
    }
  }
}
```

 *回复样例：*

```json
{
  "remotefunction": {
    "name": "queryDiskList",
    "output": {
      "items": ["emmc","sd","usb1"]
    }
  }
}
```

说明：返回的"items" 中的元素个数根据控制器的实际情况而定，如果为空表明控制卡异常。"emmc","sd","usb1"为现阶段控制卡支持的三种介质。