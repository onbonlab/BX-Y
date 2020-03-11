# 3.2.9     农历分区

| 标签            | 属性           | 类型                                                         | 说明                                                         |
| --------------- | -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| <calendarpanel> | -              | 农历分区                                                     |                                                              |
| √               | xCoord/x       | int                                                          | 分区左上角x坐标                                              |
| √               | yCoord/y       | int                                                          | 分区左上角y坐标                                              |
| √               | width/w        | int                                                          | 分区宽度                                                     |
| √               | height/h       | int                                                          | 分区高度                                                     |
| √               | zOrder/z       | int                                                          | 分区层次，0代表底层，数字越大层次越高                        |
| -               | transparency/t | int                                                          | 分区透明度(0~100)：100为完全不透明，默认100                  |
| -               | duration       | int                                                          | 播放时间：  以秒为单位，默认5秒；只是定义了该分区的默认时长，节目的播放实际时长为该节目中所有分区的最大时长 |
| -               | bgColor        | string                                                       | 背景颜色，默认‘0x00000000’ - 透明黑色                        |
| -               | timeEquation   | string                                                       | 调整时间，格式‘hh:mm:ss’，默认‘00:00:00’                     |
| -               | positiveTE     | bool                                                         | 调整时间方向：‘True’为加，‘False’为减，默认‘True’            |
| <calendar>      | -              | <calendarpanel>的子标签，子单元定义  最大允许个数暂定３个，同时显示（没有order） |                                                              |
| √               | mode           | string                                                       | 农历的各种形式：  ‘heavenlystem’:  为 干支纪年，‘甲子’  - ‘癸亥’  ‘lunarcalendar’:  为阴历，如‘正月 初六’  ‘solarterms’: 为节气或距离下个节气的天数，如           ‘立夏’、  ‘距小满10天’等 |
| -               | fontColor      | string                                                       | 字体颜色，默认‘0xFFFFFFFF’  - 不透明白色                     |
| √               | fontName       | string                                                       | 字体名称                                                     |
| √               | fontSize       | int                                                          | 字体大小                                                     |
| -               | fontSizeType   | string/int                                                   | 字体大小单位（默认’pixel’ 像素）：  ‘pixel’/0 以像素为单位，‘point’/1  以磅为单位 |
| -               | fontAttributes | string/int                                                   | 字体附加属性：  包括‘bold’, ‘italic’, ‘normal’, ‘underline’, ‘strikeout’等五种;  可通过‘&’组合,例如 ：‘bold&  italic& underline’ |
| √               | contentX       | int                                                          | 文字渲染区左下角相对分区左上角的水平偏移                     |
| √               | contentY       | int                                                          | 文字渲染区左下角相对分区左上角的垂直偏移                     |