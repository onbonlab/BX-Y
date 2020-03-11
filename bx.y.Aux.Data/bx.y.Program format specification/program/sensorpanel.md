# 3.2.10    传感器分区

| 标签                    | 属性             | 类型       | 说明                                                         |
| ----------------------- | ---------------- | ---------- | ------------------------------------------------------------ |
| <sensorpanel>或<sensor> | -                | 传感器分区 |                                                              |
| √                       | xCoord  / x      | int        | 分区左上角x坐标                                              |
| √                       | yCoord  / y      | int        | 分区左上角y坐标                                              |
| √                       | width  / w       | int        | 分区宽度                                                     |
| √                       | height  / h      | int        | 分区高度                                                     |
| √                       | zOrder  / z      | int        | 分区层次，0代表底层，数字越大层次越高                        |
| -                       | transparency  /t | int        | 分区透明度(0~100)：100为完全不透明，默认100                  |
| -                       | duration         | int        | 播放时间：  以秒为单位，默认5秒；只是定义了该分区的默认时长，节目的播放实际时长为该节目中所有分区的最大时长 |
| -                       | bgColor          | hex        | 背景颜色，默认0x00000000 - 透明黑色                          |
| -                       | fontColor        | hex        | 字体颜色，默认0xFFFFFFFF  - 不透明白色                       |
| √                       | fontName         | string     | 字体名称                                                     |
| √                       | fontSize         | int        | 字体大小                                                     |
| -                       | fontSizeType     | string/int | 字体大小单位（默认’pixel’ 像素）：  ‘pixel’/0 以像素为单位，‘point’/1  以磅为单位 |
| -                       | fontAttributes   | string/int | 字体附加属性：  包括‘bold’, ‘italic’, ‘normal’等; 可通过‘&’组合,例如 ：‘bold&  italic’ |
| √                       | contentX         | int        | 文字渲染区左下角相对分区左上角的水平偏移                     |
| √                       | contentY         | int        | 文字渲染区左下角相对分区左上角的垂直偏移                     |
| √                       | content          | string     | 显示内容：  ‘%%d’为关键字，表示传感器数值。  例如：‘当前温度：%%d ℃’ |
| √                       | threshValue      | float      | 传感器阈值：如‘-1.0’、’35.0’等                               |
| √                       | threshMode       | int        | 传感器阈值判断模式（默认为‘1’）：  ‘0’ - 小于阈值判定为有效；‘1’  - 大于阈值判定为有效 |
| -                       | threshFontColor  | hex        | 超阈值时的字体颜色，默认0xFFFFFFFF  - 不透明白色             |
| -                       | decimal          | int        | 需要显示的小数位数（0~10）：  0  – 整数模式（例：25°C），默认值  2  – 小数模式（例：25.50°C） |
| -                       | unitCoefficient  | float      | 单位转换系数  与原始值相乘，所以不得为0。默认为 1.0，例如：0.001  - 可将距离传感器的毫米值转换成米 |
| -                       | correction       | float      | 修正值（默认为0）：  [最终值]=[原始值]*[unitCoefficient]+  [correction] |
| √                       | sensorAddress    | int        | 参见[附录2](Appendix2.md)                                    |
| √                       | sequence         | int        | 参见[附录3](Appendix3.md)                                    |
| -                       | unitType         | int        | 传感器单位标识 （针对特定传感器有效）：  温度传感器：0 - 摄氏度；1 - 华氏度  液位传感器：0 - 状态（是否报警）；1 - 液位值  粉尘传感器：0 - PM2.5；1 - PM10 |
| -                       | updateTime       | int        | 传感器值更新时间间隔（默认5秒）：  单位秒，范围1秒~12小时    |