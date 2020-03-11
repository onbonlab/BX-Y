# 3.2.6     表盘分区

| 标签                    | 属性           | 类型                                                         | 说明                                                         |
| ----------------------- | -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| <clockpanel  >或<clock> | -              | 表盘分区                                                     |                                                              |
| √                       | xCoord/x       | int                                                          | 分区左上角x坐标                                              |
| √                       | yCoord/y       | int                                                          | 分区左上角y坐标                                              |
| √                       | width/w        | int                                                          | 分区宽度                                                     |
| √                       | height/h       | int                                                          | 分区高度（建议与width/w相同）                                |
| √                       | zOrder/z       | int                                                          | 分区层次，0代表底层，数字越大层次越高                        |
| -                       | transparency/t | int                                                          | 分区透明度(0~100)：100为完全不透明，默认100                  |
| -                       | duration       | int                                                          | 播放时间：  以秒为单位，默认5秒；只是定义了该分区的默认时长，节目的播放实际时长为该节目中所有分区的最大时长 |
| √                       | bgImage        | string                                                       | 背景图片路径                                                 |
| -                       | timeEquation   | string                                                       | 调整时间，格式‘hh:mm:ss’，默认‘00:00:00’                     |
| -                       | positiveTE     | bool                                                         | 调整时间方向：‘True’为加，‘False’为减，默认‘True’            |
| -                       | hourColor      | int                                                          | 时针颜色，默认‘0xFFFFFF00’ - 黄色                            |
| -                       | minuteColor    | int                                                          | 分针颜色，默认‘0xFF00FF00’ - 绿色                            |
| -                       | secondColor    | int                                                          | 秒针颜色，无默认值                                           |
| <hour>                  | -              | <clock>的子标签，定义时针  存在此标签，自动忽略‘hourColor’   |                                                              |
| -                       | image          | string                                                       | 时针图片文件路径  为空时，表示控制卡自绘简单直线             |
| -                       | color          | int                                                          | 时针颜色：  image为空时使用，默认‘0xFFFFFF00’  - 黄色        |
| -                       | length/l       | int                                                          | 时针的长度，暂不支持，暂固定为分区宽度和高度中较小者的30%    |
| √                       | width/w        | int                                                          | 时针的宽度，不超过分区宽高中较小者的10%                      |
| <minute>                | -              | <clock>的子标签，定义分针  存在此标签，自动忽略‘minuteColor’ |                                                              |
| -                       | image          | string                                                       | 分针图片文件路径  为空时，表示控制卡自绘简单直线             |
| -                       | color          | int                                                          | 分针颜色：  image为空时使用，默认‘0xFF00FF00’  - 绿色        |
| -                       | length/l       | int                                                          | 分针的长度，暂不支持，暂固定为分区宽度和高度中较小者的35%    |
| √                       | width/w        | int                                                          | 分针的宽度，不超过分区宽高中较小者的10%                      |
| <second>                | -              | <clock>的子标签，定义秒针  存在此标签，自动忽略‘secondColor’。**如果既没有该子标签也没有****‘secondColor’****，将不绘制秒针**。 |                                                              |
| -                       | image          | string                                                       | 秒针图片文件路径  为空时，表示控制卡自绘简单直线             |
| -                       | color          | int                                                          | 秒针颜色：  image为空时使用，没有默认色，                    |
| -                       | length/l       | int                                                          | 秒针的长度，暂不支持，暂固定为分区宽度和高度中较小者的40%    |
| √                       | width/w        | int                                                          | 秒针的宽度，不超过分区宽高中较小者的10%                      |