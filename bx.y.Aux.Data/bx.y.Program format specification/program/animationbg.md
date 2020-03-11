# 3.2.13    炫动背景分区

| 标签          | 属性           | 类型         | 说明                                                         |
| ------------- | -------------- | ------------ | ------------------------------------------------------------ |
| <animationbg> | -              | 炫动背景分区 |                                                              |
| √             | xCoord/x       | int          | 分区左上角x坐标                                              |
| √             | yCoord/y       | int          | 分区左上角y坐标                                              |
| √             | width/w        | int          | 分区宽度                                                     |
| √             | height/h       | int          | 分区高度                                                     |
| √             | zOrder/z       | int          | 分区层次，0代表底层，数字越大层次越高                        |
| -             | transparency/t | int          | 分区透明度(0~100)：100为完全不透明，默认100                  |
| -             | duration       | int          | 播放时间：  以秒为单位，默认5秒；只是定义了该分区的默认时长，节目的播放实际时长为该节目中所有分区的最大时长 |
| √             | animationType  | int          | 动画类型选择，暂时支持0  – 5  0  - 喷泉，1 - 环形扩散，2 - 雪花  3  - 泡泡，4 - 枫叶，5 - 方块轨迹移动 |
| √             | density        | int          | 密度等级，1  ~ 10逐渐增加；  所有炫动背景分区的总密度受限，会相互影响；  当类型为  ‘1’时，尽量使用低密度等级。 |
| √             | size           | int          | 纹理尺寸等级，1  ~ 10逐渐加大                                |
| √             | direction      | string       | 方向，类型为非‘1’、非‘5’时有效：  "top","bottom","left","right",  "lefttop","leftbottom","righttop", "rightbottom" |
| √             | speed          | int          | 速度度等级，1  ~ 10逐渐加大                                  |
| √             | color          | string       | 纹理颜色（注意alpha影响）  0  - 表示随机色或原始纹理色  类型  ‘4’时，建议使用0（原始纹理色） |
| √             | taper          | int          | 锥度等级，类型  ‘0’时有效，1 ~ 10逐渐加大                    |