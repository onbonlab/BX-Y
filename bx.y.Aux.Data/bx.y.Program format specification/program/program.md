# 3.2.2     节目文件

节目文件标签及属性

| 标签      | 属性    | 类型     | 说明                                                         |
| --------- | ------- | -------- | ------------------------------------------------------------ |
| <program> | -       | 节目描述 |                                                              |
| √         | name    | string   | 节目名称（自定义，最长64字节）  建议采用 ‘program_’ + 数字的方式命名 |
| -         | bgColor | string   | 节目背景颜色，默认 ‘0x00000000’- 透明黑色                    |

 

样例：

```xml
<?xml version="1.0" encoding="utf-8"?>
	<program name="program_0" bgColor="0xFFFF8000">
		<picturepanel x="0" y="0" w="347" h="236" zOrder="0" 
　		 transparency="100" pictureType="0" lastPicMoveWidth="1">
		<picUnit file="/share/2310a45b2885be33c1b4e07882f56b84.jpg"
		  fileType="jpg" stuntType="1" stuntSpeed="16" stayTime="1" order="0"/>
		<picUnit file="/share/120a1224dd21116d1f128642e194d0ac.bmp"
		  fileType="bmp" stuntType="1" stuntSpeed="16" stayTime="1" order="1"/>
	</picturepanel>
</program>
```

节目中的分区个数不能超过128。