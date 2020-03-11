# 3.2.4     字幕分区

​	本分区当 ‘unitType’ 为 ‘text’（控制卡自渲染）模式时，为单行显示。需要多行显示的情况，请使用‘image’（ 上位机渲染）模式。

| 标签                | 属性             | 类型                                                         | 说明                                                         |
| ------------------- | ---------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| <textpanel>或<text> | -                | 单行字幕分区                                                 |                                                              |
| √                   | xCoord/x         | int                                                          | 分区左上角x坐标                                              |
| √                   | yCoord/y         | int                                                          | 分区左上角y坐标                                              |
| √                   | width/w          | int                                                          | 分区宽度                                                     |
| √                   | height/h         | int                                                          | 分区高度                                                     |
| √                   | zOrder/z         | int                                                          | 分区层次，0代表底层，数字越大层次越高                        |
| -                   | transparency/t   | int                                                          | 分区透明度(0~100)：100为完全不透明，默认100                  |
| √                   | stuntType        | int                                                          | 分区特技类型索引  建议只使用0，50~57这9种特技类型            |
| √                   | unitType         | string/int                                                   | 子单元类型选择：  ’image’/0 - 渲染好的文本图片，上位机渲染  ‘text’/1 - 未渲染的文字，控制卡自渲染 |
| <imageUnit>         | -                | <text>的子标签，子单元类型为’image’时有效  最大个数允许暂定128，按order顺序播放 |                                                              |
| √                   | order            | int                                                          | 播放顺序：0~127                                              |
| √                   | file             | string                                                       | 图片文件路径                                                 |
| √                   | stuntSpeed       | int                                                          | 特技速度等级，1~16，1为最快                                  |
| √                   | stayTime         | int                                                          | 图片停留时间，以秒为单位                                     |
| -                   | lastPicMoveWidth | int                                                          | 整条字幕最后一张图的移动宽/高度   当多幅图时，不为最后一张，该值必须为0   整条字幕只有一张图，该值固定为窗口宽/高度 |
| <textUnit>          | -                | <text>的子标签，子单元类型为’text’时有效  最大个数允许暂定128，按order顺序播放 |                                                              |
| √                   | order            | int                                                          | 播放顺序：0~127                                              |
| √                   | content          | string                                                       | 文本内容                                                     |
| √                   | stuntSpeed       | int                                                          | 特技速度等级，1~16，1为最快                                  |
| √                   | stayTime         | int                                                          | 图片停留时间，以秒为单位                                     |
| -                   | bgColor          | string                                                       | 背景颜色，默认 ‘0x00000000’- 透明黑色                        |
| -                   | fontColor        | string                                                       | 字体颜色，默认 ‘0xFFFFFFFF’ - 不透明白色                     |
| √                   | fontName         | string                                                       | 字体名称                                                     |
| √                   | fontSize         | int                                                          | 字体大小                                                     |
| -                   | fontSizeType     | string/int                                                   | 字体大小单位(默认为‘pixel’)：  ‘pixel’/0 以像素为单位，‘point’/1  以磅为单位 |
| -                   | fontAttributes   | string/int                                                   | 字体附加属性：  包括‘bold’, ‘italic’, ‘normal’, ‘underline’, ‘strikeout’等五种;  可通过‘&’组合,例如 ：‘bold&  italic& underline’ |
| -                   | fontAlignment    | string                                                       | 待定                                                         |