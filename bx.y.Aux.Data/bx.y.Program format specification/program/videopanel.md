# 3.2.5     视频分区

| 标签                  | 属性           | 类型                                                         | 说明                                                         |
| --------------------- | -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| <videopanel>或<video> | -              | 视频分区                                                     |                                                              |
| √                     | xCoord/x       | int                                                          | 分区左上角x坐标                                              |
| √                     | yCoord/y       | int                                                          | 分区左上角y坐标                                              |
| √                     | width/w        | int                                                          | 分区宽度                                                     |
| √                     | height/h       | int                                                          | 分区高度                                                     |
| √                     | zOrder/z       | int                                                          | 分区层次，0代表底层，数字越大层次越高                        |
| -                     | transparency/t | int                                                          | 分区透明度(0~100)：100为完全不透明，默认100                  |
| -                     | clone          | string                                                       | 克隆分区的坐标及宽高：  以‘X:Y[:W:H]’的格式给出，没有‘[:W:H]’代表使用分区宽高；最多可以克隆3个（多出来的不处理），使用逗号分隔。  例：‘100:200,200:200:200:160,100:400:200:160’ |
| √                     | videoType      | string/int                                                   | 视频类型：  ‘local’/0 - 本地视频或网络流媒体  ‘capture’/1 - 外部输入视频(**Y****系列暂不支持**) |
| √                     | volumeMode     | string/int                                                   | 是否静音：‘Unmute’/0 - 非静音；‘Mute’/1  - 静音              |
| √                     | rotationMode   | int                                                          | 逆时针旋转角度：  仅支持0/90/180/270四种，默认0              |
| √                     | scaleMode      | string/int                                                   | 缩放模式：  ‘original’/0 - 原始比例(**Y****系列暂不支持**)  ‘window’/1 - 窗口比例 |
| <videoUnit>           | √              | <video>的子标签，视频子单元定义  最大允许个数暂定128个，按order顺序播放 |                                                              |
|                       | order          | int                                                          | 播放顺序：0~127                                              |
| √                     | file           | string                                                       | 视频文件路径或流媒体URL  视频文件路径以相对路径给出，例如：  “share/abcdtest.mp4”  流媒体URL以有效的流媒体链接形式给出，例如：  “rtmp://live.hkstv.hk.lxdns.com/live/hks”  已测试过的流媒体协议有：rtmp，rtsp，hls |
| √                     | source         | string/int                                                   | 外部输入视频类型：‘cvbs’/0  或’hdmi’/1  videoType  为‘capture’时有效(**Y****系列暂不支持**) |
| -                     | startTime      | int                                                          | 播放开始时刻以秒为单位：  视频文件播放时有效，默认0；不得大于视频文件本身时长 |
| √                     | playTime       | int                                                          | 播放时长以秒为单位：  0表示在节目时效内一直播放或由文件时长决定 |
| √                     | volume         | int                                                          | 视频音量：0~100                                              |