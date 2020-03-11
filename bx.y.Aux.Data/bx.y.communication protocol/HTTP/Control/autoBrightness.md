# 4.3.14   自动调亮 - autoBrightness

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "autoBrightness"
      "input": {
        "brightnessValue": ["1","1","2", ... ,"255"], 
      "sensorValue": ["2","100","600", ... ,"65535"], 
     　　"sensorAddress": "0x8000"
      }
    }
  }
}
```

参数说明：

- "sensorValue"：16个范围0～65535的传感器数值，对应16个阈值

- "brightnessValue"：16个范围1～255的数值，对应16个亮度调节值

- "sensorAddress"：参见[附录5](Appendix5.md)；可用的地址除了多功能卡对应的地址外，还有板载I2C的亮度传感器0x823  

