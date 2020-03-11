# 4.8.7    关开屏绑定继电器 - screenOnOffRelay

*指令样例：*

```json
{
  "protocol": {
    "name": "YQ-COM2",
    "version": "1.0",
    "remotefunction": {
       "name": "screenOnOffRelay",
      "input": {
        "relayAddress": "0x8000",
        "relayType": "0", 
        "relaySwitch":"0x00ff" 
      }
    }
  }
}
```

参数说明：

- “relayAddress”：继电器地址，同传感器的“sensorAddress”类似（[参考附录5](Appendix5.md)）

- 0x0100 - 板上GPIO控制的外接继电器

- 0x8000 - #1网口下第一块多功能卡上的继电器

- “relayType”： 板载继电器模块控制类型；1 – 高点平触发，0 – 低电平触发

- “relaySwitch”：16位无符号整形数，每一位对应一个继电器；某位为0时不控制、为1时控制对应序号的继电器；0~7对应#1网口下第一块多功能卡的8个继电器，8和9对应板上两个GPIO控制的外接继电器；其他预留。开关机只允许控制#1网口下第一块多功能卡的8个继电器和板上GPIO控制的外接继电器。