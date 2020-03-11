# 3.2.12    炫彩文本分区

​	该分区是特殊的文本分区，由指定格式的文本掩模图片和字芯图片组成。通过叠加，将文本掩模中的文字笔画用字芯图片中的色彩代替，呈现多彩的文本文字。该分区与炫动背景区组合，能够呈现更加绚烂多彩的文本文字。

​	文本掩模图片是事先渲染好的文字图片，并且必须是带有alpha通道的文件格式，例如PNG或BMP等；其背景必须为全透明（0x00），而渲染的笔画为不透明（0xFF）。字芯图片则没有格式限制，可以是除GIF以外，任意控制卡支持的图片格式。

| 标签                          | 属性          | 类型                                                         | 说明                                                         |
| ----------------------------- | ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| <colortextpanel>或<colortext> | -             | 炫彩文本分区                                                 |                                                              |
| √                             | xCoord/x      | int                                                          | 分区左上角x坐标                                              |
| √                             | yCoord/y      | int                                                          | 分区左上角y坐标                                              |
| √                             | width/w       | int                                                          | 分区宽度                                                     |
| √                             | height/h      | int                                                          | 分区高度                                                     |
| √                             | zOrder/z      | int                                                          | 分区层次，0代表底层，数字越大层次越高                        |
| <maskUnit>                    |               | <colortext>的子标签，文本掩模子单元定义  最大允许暂定128个，按order顺序播放 |                                                              |
| √                             | order         | int                                                          | 播放顺序：0~127                                              |
| √                             | file          | string                                                       | 文本掩模图片文件路径                                         |
| √                             | stuntType     | int                                                          | 文本掩模特技类型索引：只支持0，50~53这5种特技类型，其他类型索引会使用0替代 |
| √                             | stuntSpeed    | int                                                          | 文本掩模特技速度等级，1~16，默认为1最快                      |
| √                             | stayTime      | int                                                          | 文本掩模单元停留时间，以秒为单位                             |
| √                             | waveStuntType | int                                                          | 叠加波动效果类型索引（不在以下范围当 ‘0’ 处理）  0 - 无  58 - 水平静止波；59 -  水平移动波  60 - 垂直静止波；61 -  垂直移动波  当文本掩模移动（50~53号特技）时，波动方向须与其方向一致，否则用0替代，当文本掩模静止（0号特技）时，无此限制 |
| -                             | waveCount     | int                                                          | 波峰数目： 最小个数为1，最大个数与波动方向的像素数相关。水平波取决于分区宽度，垂直波取决于分区高度。小于200时，为不超过  N/12的最大偶数；大于1000时，为不超过N/60的最大偶数；其他为16 |
| -                             | waveSpeed     | int                                                          | 波动速度等级，1~16；移动波时有效，1为最快                    |
| -                             | waveAmplitude | int                                                          | 波峰幅度占比：波峰幅度在分区宽度（水平波）或分区高度（垂直波）中的所占的**千分比**，1~250 |
| <hollowUnit>                  | -             | <colortext>的子标签，字芯子单元定义  最大个数允许暂定128，按order顺序播放  字芯子单元与文本掩模子单元没有直接关系 |                                                              |
| √                             | order         | int                                                          | 播放顺序：0~127                                              |
| √                             | file          | string                                                       | 字芯图片文件路径                                             |
| √                             | stuntType     | int                                                          | 字芯特技类型索引：只支持0、3~6，这5种特技类型，其他类型索引会使用0替代 |
| √                             | stuntSpeed    | int                                                          | 字芯特技速度等级，1~16，默认为1  最快                        |
| √                             | stayTime      | int                                                          | 单元停留时间，以秒为单位                                     |