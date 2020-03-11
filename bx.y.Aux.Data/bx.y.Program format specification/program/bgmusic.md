# 3.2.15    背景音乐分区

| 标签    | 属性   | 类型                                                         | 说明                          |
| ------- | ------ | ------------------------------------------------------------ | ----------------------------- |
| <muzak> | -      | 背景音乐（分区）  一个节目最多允一个次背景音乐分区；如存在多个，只取第一个；节目只要存在背景音乐分区，其他所有有音乐的分区都静音处理。 |                               |
| <unit>  | -      | <  muzak >的子标签，子单元定义  最多允许128个，按order顺序播放 |                               |
| √       | order  | int                                                          | 播放顺序：0~127               |
| √       | volume | int                                                          | 单元音量：1~100               |
| √       | file   | string                                                       | 音乐文件路径  暂时支持mp3格式 |

**注：**

​	本分区不作为节目实际时长控制，其他分区时间播满即算作播完。

​	只是形式上将本功能视为一个分区。