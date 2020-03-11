# 4.4.2    查询指定介质信息 - queryDisk

*指令样例：*

```json
{

  "protocol": {

​     "name": "YQ-COM2","version": "1.0",

​     "remotefunction": {

​      "name": "queryDisk"

​      "input":　{

​        "storagemedia": "emmc"

​      }

​    }

  }

}
```

*回复样例：*

```json
{
  "remotefunction": {
    "name": "queryDisk",
    "output": {
      "totalsize": "3200000000",
      "usedsize": "1000000000",
      "freesize": "2199000000",
      "usedpercent": "31.3%",
      "filesystem": "ext4"
    }
  }
}
```

参数说明：

- "totalsize"：以字节为单位的总容量

- "usedsize"：已用空间

- "freesize"：可用空间

- "usedpercent"：已用空间的百分比

- "filesystem"：文件系统类型，如ext4、vfat等