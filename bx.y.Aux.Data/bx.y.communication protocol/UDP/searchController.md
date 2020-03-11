# 3.1     搜索控制器 - searchController

 *指令样例：*

```json
{
	"protocol": {
		"name": "YQ-COM2",
		"version": "1.0",
		"remotefunction": {
			"name": "searchController",
			"input": {
				"barcode": "",
				"pid": "",
				"ipmode": "",
				"ip": "",
				"subnetmask": "",
				"gateway": ""
			}
        }
	}
}
```

该指令属于查询指令，用于搜索控制器，亦可用于查询控制器属性，“input”中的子键即为需要查询的属性（它们的“值”均为空），个数可变。“barcode”和“pid”是默认查询属性。属性列表，参见[附录1](Appendix1.md)。

 *回复样例：*

```json
{
"targetpid":"50C811344D45594D4110000012B755AB",
"targetbarcode":"C0Y2L01805100002",
"remotefunction": {
    "name": "searchController",
    "networkdevice":"eth0",
    "output": {
      "barcode": "50C811344D45594D4110000008AB53AD",
      "pid": "C0Y2001805150056",
      "ipmode": "dhcp",
      "ip": "192.168.0.199",
      "subnetmask": "255.255.255.0",
      "gateway": "192.168.0.1"
    }
 }
}
```

 *附加说明：*

如果在指令中增加“targetpid” 和“targetbarcode”，可以用于查询指定控制卡的属性，例如：

```json
{
"protocol": {
   "name": "YQ-COM2",
   "version": "1.0",
   "targetpid": "50C811344D45594D4110000008AB53AD ",
   "targetbarcode": "C0Y2001805150056",
   "remotefunction": {
    "name": "searchController",
    "input": {
      "outputtype": "",
   }
  }
 }
}
```

 

 