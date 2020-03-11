# 4.8.5    绑定继电器 - bindRelay

*指令样例：*

```json
{
  "protocol": {
      "name": "YQ-COM2",
      "version": "1.0",
      "remotefunction": {
          "name":"bindRelay",
          "input": {
              "updatetime": "5", 
              "sensorList": 
              [
                  {"sequence": "2",
                   "sensorAddress": "0x8000",
                   "relayType": "0",
                   "relaySwitch": "0x200",
                   "unitType": "0",
                   "unitCoefficient": "0.1",
                   "decimal": "1",
                   "correction": "-0.1",
                   "threshMode": "1",
                   "threshValue": "40.2"},
                  {"sequence": "0x03",
                   "sensorAddress": "0x8000",
                   "relayType": "1",
                   "relaySwitch": "0x100",
                   "unitType": "0",
                   "unitCoefficient": "0.01",
                   "decimal": "2",
                   "correction": "0.05",
                   "threshMode": "1",
                   "threshValue": "58.50"}
              ]
          }
      }
  }
}
```

参数说明：

- “updatetime”：以秒为单位的传感器检测周期。

- “sensorList”：绑定继电器的传感器列表

- “sequence”：传感器功能序号，参见[附录6](Appendix6.md)

- “sensorAddress”：传感器地址，参见[附录 5](Appendix5.md)

- “relayType”： 板载继电器模块控制类型；1 – 高点平触发，0 – 低电平触发；现阶段Y系列使用低电平触发模式。

- “relaySwitch”：32位无符号整形数，每一位对应一个继电器；某位为0时不控制、为1时控制对应序号的继电器；0~7对应#1网口下第一块多功能卡的8个继电器，8和9对应板上两个GPIO控制的外接继电器。通过传感器只允许控制#1网口下第一块多功能卡的8个继电器和板上GPIO控制的外接继电器。

- “decimal”：小数位数。

- “unitType”： 传感器单位标识。

- 温度传感器：0 - 摄氏度；1 - 华氏度；

- 粉尘传感器：0 - PM2.5；1 - PM10；

- 液位传感器：0 - 状态（是否报警）；1 - 液位值。

- “unitCoefficient”： 单位转换系数，浮点型字符串，默认为1.0；例如：0.001 - 可将距离传感器的毫米值转换成米。

- “correction”：修正值，浮点形字符串。

- 传感器最终值 = [原始值] x [unitCoefficient] + [correction]

- “threshMode”： 阈值判断模式。‘0’ - 小于阈值时断开继电器，否则吸合；‘1’ - 大于阈值时断开继电器，否则吸合。

- “threshValue”： 阈值，浮点型字符串。超出“decimal”规定的范围外的小数部分截断处理。