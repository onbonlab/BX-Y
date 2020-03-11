# 4.3.18   固件升级 - updateFirmware

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "updateFirmware",
      "input": {
        "firmwarepath":"backup/BX-Y3_V18051400.bxf"
      }
    }
  }
}
```

​	使用指定的固件文件升级控制卡。使用该命令前，需要事先使用上传文件流程或“从URL下载文件”命令，将固件文件上传至控制卡"share"目录或其他可用目录（避免直接使用"update"目录），然后将"firmwarepath"指向该文件。