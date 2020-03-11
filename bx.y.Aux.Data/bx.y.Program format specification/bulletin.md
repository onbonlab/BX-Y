# 3.4    公告区节目

​	公告区可以使用命令方式创建公告，也可以以xml格式的文件方式直接上传至公告区专用目录。为便于统一维护，使用上传xml文件方式时，公告文件必须以"bulletin"加公告序号(order字段+1)开头，以".xml"为后缀名。

​	如需要在文件名中添加额外信息，必须在公告序号之后，并使用下划线"_" 进⾏分割。例如，公告序号(order)为"0"，则公告节目文件命名为"bulletin0.xml"，或者是bulletin0_ [MD5].xml"等等。如果公告文件名不符合命令规则，可能导致无法正常使用公告区管理相关功能。

​	暂定：公告最多允许100条（order字段：范围0——99）。

 

 样例：

```xml
<?xml version="1.0" encoding="utf-8"?>
<bulletin order="0" name="公 告-1" layoutMode="2"
x="0" y="0" w="1280" h="48" t="100" 
bgColor="#00000000"
fontSize="18" fontSizeType="point" fontName="SimSun" 
fontColor="0xFFFF0000" fontAttributes="normal" 
stuntType="51" stuntSpeed="50" stayTime="0" 
startDate="" stopDate="" startTime="" stopTime="" weekFlag="127"
content="测试测试"/>
```

 

 公告区节目文件标签及属性

| 标签       | 属性           | 类型       | 说明                                                         |
| ---------- | -------------- | ---------- | ------------------------------------------------------------ |
| <bulletin> | -              | 公告区     |                                                              |
|            | order / z      | int        | 公告序号（暂定0  - 99）                                      |
|            | name           | string     | 自定义名字                                                   |
|            | layoutMode     | string/int | 布局模式：  ‘top’/0 - 居上，‘bottom’/0  - 居下，‘custom’/0 - 自定义 |
|            | xCoord/x       | int        | 自定义布局左上角x坐标                                        |
|            | yCoord/y       | int        | 自定义布局左上角y坐标                                        |
|            | width/w        | int        | 自定义布局宽度                                               |
|            | height/h       | int        | 自定义布局高度                                               |
|            | startDate      | string     | 播放开始日期，格式：’yyyy-MM-dd’,年月日                      |
|            | startTime      | string     | 播放开始时间，格式：’hh:mm:ss’,时分秒                        |
|            | stopDate       | string     | 播放结束日期，格式：’yyyy-MM-dd’ ,年月日                     |
|            | stopTime       | string     | 播放结束时间，格式：’hh:mm:ss’ ,时分秒                       |
|            | weekFlag       | int        | 星期有效属性：第1-7位分别代表周一~周日,例如：  ’1’表示只在周一播放，’127’表示在周一~周日都播放 |
|            | transparency/t | int        | 分区整体透明度(0~100)：默认100为完全不透明                   |
|            | bgColor        | int        | 公告区背景色，默认‘0xFF000000’ - 不透明黑色                  |
|            | fontColor      | string     | 字体颜色，默认’0xFFFFFFFF’  - 不透明白色                     |
|            | fontName       | string     | 字体名称                                                     |
|            | fontSize       | int        | 字体大小                                                     |
|            | fontSizeType   | string/int | 字体大小单位（默认 ‘pixel’）：  ‘pixel’/0 以像素为单位，‘point’/1  以磅为单位 |
|            | fontAttributes | string/int | 字体附加属性：  包括’bold’,’italic’,’normal’,’underline’, ’strikeout’等五种;  可通过’&’组合,例如 ：’bold&  italic& underline’ |
|            | fontAlignment  | string     | （待定）                                                     |
|            | stuntType      | int        | 分区特技类型  建议只使用0，50~57这9种特技类型                |
|            | stuntSpeed     | int        | 特技速度等级，1~16，1为最快                                  |
|            | stayTime       | int        | 特技停留时间，以秒为单位(暂定)                               |
|            | content        | string     | 文本内容                                                     |