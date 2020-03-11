# 3.2.1     列表文件

播放列表文件标签及属性

|           | 标签属性     | 类型                                             | 说明                                                         |
| --------- | ------------ | ------------------------------------------------ | ------------------------------------------------------------ |
| <list>    | -            | 播放列表                                         |                                                              |
| √         | deviceType   | int                                              | 控制器型号，用于指定列表使用的控制器型号                     |
| √         | screenWidth  | int                                              | 控制器屏幕宽度                                               |
| √         | screenHeight | int                                              | 控制器屏幕高度                                               |
| <program> | -            | <list>的子标签，节目描述  最大允许64个（可扩展） |                                                              |
| √         | order        | int                                              | 播放顺序：从小到大                                           |
| √         | playMode     | string  /int                                     | 播放模式：  ‘Timer’/0  - 定时长播放  ‘Counter’/1  - 定次数播放 |
| -         | priority     | Int                                              | 节目优先级（新）：  1~16，优先级，1最高，16最低（默认值）  在某个时段内，优先播放等级高的节目。  不在1-16范围内的值一律按16 - 最低优先级处理。 |
| -         | loop         | int                                              | 轮播次数（新）：  0 - 始终参与轮播；1~1000 - 参与轮播次数。默认0。 |
| √         | programFile  | string                                           | 节目文件的相对路径                                           |
| -         | playTime     | int                                              | 播放时长，定时长播放时有效，单位：秒，默认5                  |
| -         | playCount    | int                                              | 播放次数，定次数播放时有效，默认1                            |
| -         | integrate    | string/int                                       | 是否连播（新）：  'yes'/1 - 连续播放playTime指定的次数；  'no'/0 - 不连续播放：播完一遍，切换其他同等优先级次数未满的节目。  定次数播放时有效，默认：'yes'/1。 |
| -         | startDate    | string                                           | 播放时效开始日期  格式：‘yyyy-MM-dd’，默认：‘1970-01-01’     |
| -         | startTime    | string                                           | 每日播放开始时间  格式：‘hh:mm:ss’，默认：‘00:00:00’         |
| -         | stopDate     | string                                           | 播放时效结束日期  格式：‘yyyy-MM-dd’ ，默认：‘2099-12-31’    |
| -         | stopTime     | string                                           | 每日播放结束时间  格式：‘hh:mm:ss’ ，默认：‘23:59:59’        |
| -         | weekFlag     | int                                              | 星期有效标识  1,2,4,8,16,32,64分别代表代表周一~周日，将需要播放日期对应的数字相加即得结果；默认  127。  举例：‘1’表示只在周一播放，‘17’表示在周一和周五播放，‘127’表示在周一~周日都播放 |
| -         | dates        | string                                           | 播放日期段（新）：  基本格式：‘[起始日期] [结束日期]’  起始/结束日期以‘yyyy-MM-dd’形式给出，中间以空格分开；最多允许8组，每组间以逗号分隔；为空时按‘1970-01-01 2099-12-31’处理。  例：‘2018-08-01 2018-0804,2018-08-06 2018-0809’  该类型所有标签定义的日期还需处理weekFlag有效。 |
| -         | times        | string                                           | 播放时间段（新）：  基本格式：‘[起始时间] [结束时间]’  起始/结束日期以‘hh:mm:ss’形式给出，中间以空格分开；最多允许8组，每组间以逗号分隔；为空时按’00:00:00 24:00:00’处理  例如：’07:30:00  09:00:00,11:00:00 13:30:00’ |

样例：

```xml
<?xml version="1.0" encoding="utf-8"?>
	<list deviceType="9048" screenWidth="1280" screenHeight="1024">
	 <program order="0" playMode="1" playTime="1" 
	  startDate="" stopDate="" startTime="" stopTime="" weekFlg="127" 
	  programFile="programs/1c761cf57e689b7012de839a9776025e.xml" />
	 <program order="1" playMode="1" playTime="1" 
	  startDate="" stopDate="" startTime="" stopTime="" weekFlag="127"
	  programFile="programs/0f3b1ab03f2c622a3a3242cecb8972c6.xml" />
</list>
```

或新样例：

```xml
<?xml version="1.0" encoding="utf-8"?>
	<list deviceType="9048" screenWidth="1280" screenHeight="1024">
	 <program order="0" playMode="1" playTime="1" priority="1"loop="5"
              dates="" times="08:00:00 11:30:00" weekFlg="127"
              programFile="programs/1c761cf57e689b7012de839a9776025e.xml" />
	 <program order="1" playMode="1" playTime="1" priority="2"loop="5" 
              dates="" times="08:00:00 11:30:00" weekFlg="63"
              programFile="programs/0f3b1ab03f2c622a3a3242cecb8972c6.xml" />
</list>
```

 行为说明：

- 定时长播放类节目，当一次处理。播足'playTime'设定的时长，算作一次。如果设定的时长，与节目本身的实际时长不相同时，须以设定的时长为标准。如果节目实际时长小于设定的时长，则循环重复播放（剩余时长不足时，掐尾播放）；否则掐断播放，只播放前面一部分。
- 播放时效内同等优先级的所有节目满次数后，根据各自的'loop'决定是否重新计次。
- 当loop不为0时，可能存在黑屏的情况。避免黑屏需正确设计播放列表：例如可以设计一全时段有效且优先级最低的背景节目。
- 新增的日期段属性<dates>与原来的 <startDate>/<stopDate>可以同时出现，但是优先使用<dates>。建议上位机根据版本不同（V18082700之后的版本，不包括V18082700）决定下发哪些属性。不同日期段有交集或衔接时，须自动合并。
- 新增的时间段属性<times>与原来的 <startTime>/<stopTime>可以同时出现，但是优先使用<times>。建议上位机根据版本不同（V18082700之后的版本，不包括V18082700）决定下发哪些属性。不同时段有交集或衔接时，须自动合并。
- 由于<program>标签内<times>/<dates>描述的日期段/时间段数量有限，要实现同一节目更多日期段/时间段播放，可以在列表中添加多个含有不同日期段/时间段定义的<program>标签，其'programFile'指向同一节目文件。但是必须自行避免不同<program>标签中的<times>、<dates>重合。
- 当一个低优先级的节目被高优先级节目打断时，按此次节目未开始处理。
- 当有锁定节目相关操作（锁定节目指令或遥控器切换节目）时，时效控制和优先级控制将失效。