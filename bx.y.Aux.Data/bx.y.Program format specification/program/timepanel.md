# 3.2.7     时间分区

| 标签                                                         | 属性           | 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| <timepanel>或<time>                                          | -              | 时间分区                                                     |                                                              |
| √                                                            | xCoord/x       | int                                                          | 分区左上角x坐标                                              |
| √                                                            | yCoord/y       | int                                                          | 分区左上角y坐标                                              |
| √                                                            | width/w        | int                                                          | 分区宽度                                                     |
| √                                                            | height/h       | int                                                          | 分区高度                                                     |
| √                                                            | zOrder/z       | int                                                          | 分区层次，0代表底层，数字越大层次越高                        |
| -                                                            | transparency/t | int                                                          | 分区透明度(0~100)：100为完全不透明，默认100                  |
| -                                                            | duration       | int                                                          | 播放时间：  以秒为单位，默认5秒；只是定义了该分区的默认时长，节目的播放实际时长为该节目中所有分区的最大时长 |
| -                                                            | bgColor        | string                                                       | 背景颜色，默认’0x00000000’ - 透明黑色                        |
| -                                                            | timeEquation   | string                                                       | 调整时间，格式’hh:mm:ss’，默认’00:00:00’                     |
| -                                                            | positiveTE     | bool                                                         | 调整时间方向：True为加，False为减，默认True                  |
| <dateTime>                                                   | -              | <time>的子标签，子单元定义  最大允许个数暂定8个，同时显示（没有order） |                                                              |
| -                                                            | fontColor      | string                                                       | 字体颜色，默认’0xFFFFFFFF’  - 不透明白色                     |
| √                                                            | fontName       | string                                                       | 字体名称                                                     |
| √                                                            | fontSize       | int                                                          | 字体大小                                                     |
| -                                                            | fontSizeType   | string/int                                                   | 字体大小单位：  ’pixel’/0 以像素为单位，’point’/1  以磅为单位  默认’pixel’ |
| -                                                            | fontAttributes | string/int                                                   | 字体附加属性：  包括‘bold’, ‘italic’, ‘normal’, ‘underline’, ‘strikeout’等五种;  可通过‘&’组合,例如 ：‘bold&  italic& underline’ |
| √                                                            | contentX       | int                                                          | 文字渲染区左下角相对分区左上角的水平偏移                     |
| √                                                            | contentY       | int                                                          | 文字渲染区左下角相对分区左上角的垂直偏移                     |
| √                                                            | content        | string                                                       | 符合RFC-2822标准的格式字符串                                 |
| "%A":  完整英文星期，如”Monday”  "%a":  简写英文星期，如”Mon”  "%B":  完整英文月份，如"February"  "%b":  简写英文月份，如"Feb"  "%d":  两位(0补充)数字日期，‘01’  -  ‘31’  "%H":  两位显示“时”， ‘00’  -  ‘23’  "%I":  两位显示“时”， ‘01’  -  ‘12’  "%k":  两位显示“时”， ‘0’  -  ‘23’，以空格填充  "%l":  两位显示“时”， ‘1’  -  ‘12’，以空格填充  "%M":  两位显示“分”，  ‘00’  -  ‘59’  "%p":  英文大写上/下午标志， ‘AM’/‘PM’  "%P":  英文小写上/下午标志，‘am’/‘pm’  "%S":  两位显示“秒” ，  ’00’  -  ’59’  "%Y":  完整的公历年份，如’2018’  "%y":  公历年份后2位，如’18’  "%m":  两位(0补充)数字月份，’01’  -  ’12’ |                |                                                              |                                                              |
| 自定义字符串格式（修改了RFC-2822中的定义）                   |                |                                                              |                                                              |
| "%T":  中文上/下午标志，‘上午’/  ‘下午’  "%w":  中文星期，‘星期一’ - ‘星期日’ |                |                                                              |                                                              |