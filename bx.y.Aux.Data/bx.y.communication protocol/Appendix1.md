# 附录1  属性列表

| 类型                | 属性名称                                                   | 描述                                      | 缺省值                                             | 应用指令          |
| ------------------- | ---------------------------------------------------------- | ----------------------------------------- | -------------------------------------------------- | ----------------- |
| 系统                | controllertype                                             | 控制卡型号码，见[附录3](#_附录3___1)      | 小端十进制型号，  例如8536,  8792, 9048等          | -                 |
| pid                 | *控制器**ID**号*                                           | *<”50”**开头的**32**位字符串**>*          | -                                                  |                   |
| barcode             | 控制器条形码                                               | <实际条码>                                | -                                                  |                   |
| controllername      | 控制器名称                                                 | 空                                        | setProperty                                        |                   |
| width               | 屏幕宽度                                                   | <缺省宽度>                                | setScreenSize                                      |                   |
| height              | 屏幕高度                                                   | <缺省高度>                                | setScreenSize                                      |                   |
| Screendata          | 屏参标记                                                   | 1                                         | -                                                  |                   |
| foldtype            | 折屏类型                                                   | 0                                         | SetFoldScreen                                      |                   |
| foldcount           | 折行后的行数                                               | 空                                        | SetFoldScreen                                      |                   |
| foldwidth           | 水平折屏每行宽度                                           | 空                                        | SetFoldScreen                                      |                   |
| foldheight          | 垂直折屏每列宽度                                           | 空                                        | SetFoldScreen                                      |                   |
| Logicwidth          | 逻辑宽                                                     | 空                                        | -                                                  |                   |
| Logicheight         | 逻辑高                                                     | 空                                        | -                                                  |                   |
| 固件                | firmwareversion                                            | 固件版本号                                | <yymmddxx>                                         | updateFirmware    |
| Playerversion       | 应用程序版本号                                             | <yymmddxx>                                | updateFirmware                                     |                   |
| Reliedversion       | 当前固件版本的依赖版本号                                   | <yymmddxx>                                | updateFirmware                                     |                   |
| fpgaversion         | FPGA版本号                                                 | <yymmddxx>                                | updateFirmware                                     |                   |
| 网络                | dnsserver                                                  | 域名服务器地址                            | 空                                                 | setNetworkOption  |
| mac                 | 以太网卡MAC地址                                            | <实际MAC>                                 | setNetworkOption                                   |                   |
| ipmode              | 以太网卡IP地址分配方式dhcp/static                          | static                                    | setNetworkOption                                   |                   |
| ip                  | 以太网卡IP地址                                             | 192.168.0.199                             | setNetworkOption                                   |                   |
| subnetmask          | 以太网卡子网掩码                                           | 255.255.255.0                             | setNetworkOption                                   |                   |
| gateway             | 以太网卡网关                                               | 192.168.0.1                               | setNetworkOption                                   |                   |
| wificonnectmode     | WiFi 地址分配方式dhcp/static                               | static                                    | setNetworkOption                                   |                   |
| wifiipaddress       | WiFi  IP地址                                               | 192.168.11.101                            | setNetworkOption                                   |                   |
| wifisubnetmask      | WiFi子网掩码                                               | 255.255.255.0                             | setNetworkOption                                   |                   |
| wifigateway         | WiFi网关                                                   | 192.168.11.1                              | setNetworkOption                                   |                   |
| apipaddress         | AP模式IP地址                                               | 192.168.22.1                              | setApProperty                                      |                   |
| apssid              | AP模式热点名(热点的密钥不在属性列表中，可设但不可查)       | <实际条码>                                | setApProperty                                      |                   |
| restartnetwork      | 标识setNetworkOption后是否重启过网络：wait/completed       | completed                                 | -                                                  |                   |
| serverip            | 普通服务器代理IP地址                                       | 空                                        | setProperty                                        |                   |
| serverport          | 普通服务器代理端口                                         | 空                                        | setProperty                                        |                   |
| cloudip             | 云服务器代理IP地址                                         | 139.196.231.196                           | setProperty                                        |                   |
| cloudport           | 云服务器代理端口                                           | 3802                                      | setProperty                                        |                   |
| clouduserid         | 云服务器用户ID                                             | 空                                        | setProperty                                        |                   |
| servermode          | 服务器模式server/cloud/off                                 | cloud                                     | enableServerMode                                   |                   |
| ppp_apn ①           | 4G模块拨号APN(接入点名称)                                  | 空                                        | setProperty                                        |                   |
| ppp_number  ①       | 4G模块拨号号码                                             | 空                                        | setProperty                                        |                   |
| ppp_username  ①     | 4G模块拨号用户名                                           | 空                                        | setProperty                                        |                   |
| ppp_password  ①     | 4G模块拨号密码                                             | 空                                        | setProperty                                        |                   |
| 授时                | timezoneflag                                               | 自动授时开关  on/off                      | off                                                | setTimezoneServer |
| timezone            | 时区 ：主时区/次时区                                       | Asia/Shanghai                             | setTimezoneServer                                  |                   |
| timezoneserver      | 自动授时网络地址                                           | 120.24.166.46                             | setTimezoneServer                                  |                   |
| 节目                | playlist                                                   | 当前节目播放列表                          | 空                                                 | play              |
| programlockedstatus | 节目锁定状态,  0/1                                         | 0                                         | lockProgram                                        |                   |
| programlockedname   | 锁定的节目名称                                             | 空                                        | lockProgram                                        |                   |
| playermode          | 播放模式                                                   | 0                                         | switchplayermode                                   |                   |
| FTP                 | ftpserveraddr                                              | ftp服务器地址；已废弃，可用于保存普通信息 | 空                                                 | setProperty       |
| ftpserverport       | ftp服务器端口；已废弃，可用于保存普通信息                  | 空                                        | setProperty                                        |                   |
| ftploginname        | ftp服务器用户名；已废弃，可用于保存普通信息                | 空                                        | setProperty                                        |                   |
| ftploginpassword    | ftp服务器密码；已废弃，可用于保存普通信息                  | 空                                        | setProperty                                        |                   |
| 其他                | ipflag                                                     | IP显示标记  on/off                        | off                                                | setProperty       |
| outputtype          | 输出方式  LCD/DVI                                          | LCD                                       | setOutputType                                      |                   |
| loglevel            | 日志等级: DEBUG/INFO/WARNING/ERROR                         | INFO                                      | -                                                  |                   |
| storagemedia        | 存储介质：emmc,sd,usb1                                     | emmc                                      | setStorageMedia                                    |                   |
| screenlockedstatus  | 屏幕锁定状态：on/off                                       | off                                       | lockScreen                                         |                   |
| screenonoffstatus   | 屏幕开关状态 ：on/off                                      | on                                        | screenOnOff                                        |                   |
| customscreenstatus  | 定时开关屏幕动作列表                                       | 空                                        | customScreenOnOff                                  |                   |
| volume              | 音量：0-100                                                | 100                                       | setVolume                                          |                   |
| brightness          | 亮度  1-255                                                | 255                                       | systemBrightness                                   |                   |
| brightnessmode      | 调亮模式：  system即时调亮   custom定时调亮,  auto自动调亮 | system                                    | systemBrightness  customBrightness  autoBrightness |                   |
| httpserverport      | httpserver监听的端口                                       | 80                                        | -                                                  |                   |
| scheduletaskflag    | 计划任务存在标记：true/false                               | false                                     | -                                                  |                   |
| i2cnum              | I2C主设备序号                                              | 2                                         | -                                                  |                   |
| i2caddress          | I2C从设备地址                                              | 0x23                                      | -                                                  |                   |
| optimizedspeed      | 速度优化  on/off （未启用）                                | on                                        | setProperty                                        |                   |
| language            | 提示信息语言                                               | zh_CN                                     | setLanguage                                        |                   |
| bxparam             | 仰邦内部参数                                               | 空                                        | setProperty                                        |                   |
| customize           | 客户自定义参数                                             | 空                                        | setProperty                                        |                   |

注：① 普通网络无须设置，特殊网络需移动运营商提供具体参数



 