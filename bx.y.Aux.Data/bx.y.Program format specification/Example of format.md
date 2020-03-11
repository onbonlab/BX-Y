# 3.   节目文件格式与范例

## 3.1  概述

​	节目文件分成普通节目、动态区节目和公告区节目三类。

​	普通节目是异步控制卡的主要节目形式，是由xml格式的播放列表文件和节目文件共同描述的分区节目形式：同一节目文件内的所有分区统一调度；不同节目文件描述的分区，根据播放列表文件的组织轮流播放。

​	动态区节目是一种掉电不保存的（通常情况下）特殊的节目形式。动态区可作为全局节目独立于普通节目进行调度，也可与普通节目绑定参与普通节目的调度。

​	公告区节目实际上是一个特殊的区域，在屏幕的最前面，显示用户定义的文字信息，独立于普通节目和动态区节目，单独调度。

​	没有特殊说明，所有与颜色相关的字段，均以以0xAARRGGBB字符串格式给出。

​	所有xml文件统一采用UTF-8编码方式。

## 3.2  普通节目

​	普通节目由播放列表文件和节目文件组成，均为xml格式：播放列表文件中确定了节目适用的型号、屏幕尺寸，并安排了节目文件播放的顺序和播放时效；节目文件则包含了节目的具体分区及内容。

* [3.2.1     列表文件](program/list.md)
* [3.2.2     节目文件](program/program.md)
* [3.2.3     图片分区](program/picturepanel.md)
* [3.2.4     字幕分区](program/textpanel.md)
* [3.2.5     视频分区](program/videopanel.md)
* [3.2.6     表盘分区](program/clockpanel.md)
* [3.2.7     时间分区](program/timepanel.md)
* [3.2.8     计时分区](program/countpanel.md)
* [3.2.9     农历分区](program/calendarpanel.md)
* [3.2.10    传感器分区](program/sensorpanel.md)
* [3.2.11    数据库分区](program/databasepanel.md)
* [3.2.12    炫彩文本分区](program/colortextpanel.md)
* [3.2.13    炫动背景分区](program/animationbg.md)
* [3.2.14    多彩边框分区](program/borderpanel.md)
* [3.2.15    背景音乐分区](program/bgmusic.md)

## [3.3    动态区节目](dynamic.md)

## [3.4    公告区节目](bulletin.md)

