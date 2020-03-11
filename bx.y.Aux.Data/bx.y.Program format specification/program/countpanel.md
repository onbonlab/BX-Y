# 3.2.8     计时分区

| 标签                  | 属性           | 类型       | 说明                                                         |
| --------------------- | -------------- | ---------- | ------------------------------------------------------------ |
| <countpanel>或<count> | -              | 计时分区   |                                                              |
| √                     | xCoord/x       | int        | 分区左上角x坐标                                              |
| √                     | yCoord/y       | int        | 分区左上角y坐标                                              |
| √                     | width/w        | int        | 分区宽度                                                     |
| √                     | height/h       | int        | 分区高度                                                     |
| √                     | zOrder/z       | int        | 分区层次，0代表底层，数字越大层次越高                        |
| -                     | transparency/t | int        | 分区透明度(0~100)：100为完全不透明，默认100                  |
| -                     | duration       | int        | 播放时间：  以秒为单位，默认5秒；只是定义了该分区的默认时长，节目的播放实际时长为该节目中所有分区的最大时长 |
| -                     | bgColor        | string     | 背景颜色，默认’0x00000000’ - 透明黑色                        |
| √                     | targetType     | string     | 计时类型：  ‘end’  - 倒计时，start’ - 正计时  倒计时，时间递减直到目标时刻，之后始终为0；正计时从计时时刻开始累加，之前始终为0 |
| √                     | targetDate     | string     | 目标日期：  格式：‘yyyy-MM-dd’， 可以不指定；不指定或为空时，将进行每日循环计时，并在本地时间0点切换 |
| √                     | targetTime     | string     | 目标时间：  格式：‘hh:mm:ss’，必须指定                       |
| -                     | fontColor      | string     | 字体颜色，默认’0xFFFFFFFF’  - 不透明白色                     |
| √                     | fontName       | string     | 字体名称                                                     |
| √                     | fontSize       | int        | 字体大小                                                     |
| -                     | fontSizeType   | string/int | 字体大小单位：  ‘pixel’/0 以像素为单位，‘point’/1  以磅为单位  默认’pixel’ |
| -                     | fontAttributes | string/int | 字体附加属性：  包括‘bold’, ‘italic’, ‘normal’, ‘underline’, ‘strikeout’等五种;  可通过‘&’组合,例如 ：‘bold&  italic& underline’ |
| √                     | contentX       | int        | 文字渲染区左下角相对分区左上角的水平偏移                     |
| √                     | contentY       | int        | 文字渲染区左下角相对分区左上角的垂直偏移                     |
| √                     | content        | string     | 格式字符串：  ‘dd’ - 代表天数，‘hh’ - 代表小时殊， ‘mm’  - 代表分钟数， ‘ss’  - 代表秒数；例如：  ‘距离目标：dd天hh时mm分ss秒’ |
| -                     | convert        | string     | 单位换算(计时累加)：  ‘no’ - 否；‘yes’  - 是（默认）  ‘yes’ 时，如果某一格式串没有，其值逐级换算成下一存在格式串的级别，并并入其中；‘no’时不做以上处理，只是不显示空缺格式串的对应数字。  例如：  ‘hh时ss秒’  格式字符串在距离目标1天1小时2分10秒时：‘yes’  最终会显示‘25小时130秒’；而‘no’  最终会显示 ‘1小时10秒’ |