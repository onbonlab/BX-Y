# 4.10.1   更新播放动态区 - updateDynamic

*指令样例：*

```json
{
"protocol": {
    "name": "YQ-COM2","version": "1.0",
    "remotefunction": {
      "name": "UpdateDynamic",
      "input": {
        "immediatelyPlay":"0",
        "cover":"0",
        "dynamics":[{
          "id":"0",
          "xCoord": "200",
          "yCoord":"500",
          "width":"400",
          "height":"400",
          "transparency":"100",
          "relativeProgram":"",
          "runMode":"0",
          "updateFrequency":"",
         "unit":[{
            "type":"Picture",
            "order":"0",
            "stuntType":"1",

            "stuntSpeed":"1",
            "stayTime":"5",
            "content":"Qk2mZAAA..."，
            "gifFlag":"0"
          },{
            "type":"Text",
            "order":"1",
            "stuntType":"1",
            "stuntSpeed":"1",
            "stayTime":"5",
            "content":"5paH5a2X"，
            "bgColor":"0xFF00FF00",
            "fontSize":"16",
            "fontName":"SimSun",
            "fontSizeType":"0",
            "fontColor":"0xFFFF0000",
            "alignment-H":"0",
            "alignment-V":"0"
          },{
            "type":"Video",
            "order":"2",
           "scaleMode":"Window",
            "volume":"70",
            "rotationMode":"0"
            "content":"ZnRwOi..."，
          }, {
             "type":"URLPicture"，
            "order":"3",
            "stuntType":"1",
            "stuntSpeed":"1",
            "stayTime":"5",
            "content":"ZnRwOi..."，
             "gifFlag":"0"
          }，{
            "type":"URLText",
            "order":"4",
            "stuntType":"1",
            "stuntSpeed":"1",
            "stayTime":"5",
             "content":"ZnRw..."，
            "bgColor":"0xFF00FF00",
            "fontSize":"16",
            "fontName":"SimSun",
            "fontSizeType":"0",
            "fontColor":"0xFFFF0000",
            "fontAttributes":"normal",
            "alignment-H":"0",
            "alignment-V":"0"
          }]
        }]
      }
    }
  }
}
```

该指令用于播放新的动态区和更新已经在播的动态区，更新在播的动态区时，该动态区会重新调度，不在更新命令中的在播动态区不受影响。可以一次发多个动态区，也可以只发一个动态区。当“type”类型是 “Picture”的单元(“unit”)数量较多时，建议以单个动态区发送，这样可以避免通信体过大而引起的丢包问题。资源类型为“Video”，“URLPicture”，“URLText”时，资源下载需要时间，资源播放依实际网络状况会有不同程度延迟。

 

-  “immediatelyPlay”：可以指定一个关联了普通节目的动态区ID（必须是dynamics参数中存在的id），让该动态区尝试立即播放。若动态区的运行方式”runMode”为0或1或2时，该动态区的节目优先级为最高，并立即播放；若”runMode”为3或4或5时，该动态区取所关联的普通节目的节目优先级，并尝试与所关联的普通节目一起播放（当有更高优先级的普通节目在播放时，回复失败）；若”runMode”为6时，该动态区取所关联的普通节目的节目优先级，并作为普通节目参与调度。只可以指定一个id。为空("")时，表示未关联任何普通节目。

-  “cover”：是否覆盖普通节目，即是否只播放动态区，"0"：动态区和普通节目共存播放，"1"：停止播放普通节目，只播放动态区节目。

- “dynamic”：动态区各项属性配置列表。

- “unit”：动态内所有类型单元的属性配置列表。unit中单元个数1~10，不可以为空。

- “dynamic”和“unit”列表内参数说明见下表，参数类型均为”string”。


 

| 属性            | 说明                                                         |                                                              |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| dynamic         | xCoord                                                       | x坐标                                                        |
| yCoord          | y坐标                                                        |                                                              |
| width           | 宽度，不可以超过设置的屏幕尺寸                               |                                                              |
| height          | 高度，不可以超过设置的屏幕尺寸                               |                                                              |
| transparency    | 透明度（0-100）                                              |                                                              |
| id              | 动态区ID号，范围0~31  （最多支持32个动态区）                 |                                                              |
| relativeProgram | 关联的节目，即所要关联的节目序号(节目列表中的order字段("0","1",...))。  为空时，无关联节目，动态区为全局节目。  若关联的普通节目不存在，或者关联的普通节目无效，则该动态区按全局节目处理。 |                                                              |
| runMode         | 动态区运行方式：   "0"：全局播放动态区，所有unit循环显示  "1"：全局动态区节目，所有unit顺序显示，显示完一遍后停止播放该动态区节目  "2"：全局动态区节目，所有unit顺序显示，显示完一遍后静止显示该动态区最后一个unit(以unit的order为序)  "3"：绑定播放动态区，关联节目开始播放时播放动态区，所有unit按order排序循环显示，直到关联节目播放完毕  "4"：绑定播放动态区，关联节目开始播放时播放动态区，所有unit顺序显示，显示完一遍后本轮不再显示  "5"：绑定播放动态区，关联节目开始播放时播放动态区，所有unit顺序显示，显示完一遍后静止显示该动态区最后一个unit  "6"：插播动态区，关联节目播放完后播放动态区，所有unit顺序显示一遍后本轮不再显示 ，继续播放关联节目后的节目   注意：  Ⅰ：未关联任何普通节目时，该字段只能取0、1、2，指定关联节目时，该字段只能取3、4、5、6，越界取值无效  Ⅱ：3、4、5、6的运行模式用于动态区关联普通节目时，动态区的播放方式，动态区参与关联节目的轮播 |                                                              |
| updateFrequency | URLPicture或URLText类型资源下载更新频率，单位秒。小于5s均按5s处理。为空或0则只下载一次 |                                                              |
| unit            | type                                                         | 动态区内各单元（“unit”）类型：  "Picture/0"：图片流  "Text/1"：文字  "Video/2"：网络视频（mpeg1/mpeg2/mpeg4）（暂不支持）  "URLPicture/3"：网络图片  "URLText/4"：网络文字(txt) |
| order           | 播放顺序，范围0~9 （最多支持10个单元）                       |                                                              |
| stuntType       | 特技类型：   "Picture"和"URLPicture"适用的特技:  "Text"和"URLText"适用的特技: |                                                              |
| stuntSpeed      | 特技速度（1-16）                                             |                                                              |
| stayTime        | 停留时间 （秒）                                              |                                                              |
| content         | 播放内容：  1.当type类型为URLPicture或URLText或Video时，该字段指定标准的URL格式的base64编码  2.当type类型为"Picture/0或"Text/1"时，该字段为图片流或文字的base64编码  当文件以表单形式上传时，该字段为上传文件的另存文件名([命名规则](Appendix.md)) |                                                              |
| gifFlag         | GIF类型图片的标识：  "0"：非GIF类型  "1"：GIF类型（暂不支持动态播放，只作普通图片播放） |                                                              |
| bgColor         | 背景颜色（ARGB），类型为“Text”和"URLText"时有效  例如，黑色：0xFF000000 |                                                              |
| fontSize        | 字体大小，类型为“Text”和"URLText"时有效                      |                                                              |
| fontSizeType    | 指定字体大小是以pixel还是point为单位：  "0"：pixel  "1"：point |                                                              |
| fontName        | 字体名称，类型为“Text”和"URLText"时有效                      |                                                              |
| fontColor       | 字体颜色（ARGB），类型为“Text”和"URLText"时有效  例如，红色：0xFFFF0000 |                                                              |
| fontAttributes  | 包括“bold”、“italic”、“normal”，其中“bold”和“italic”可以通过“&”进行组合 |                                                              |
| alignment-H     | 水平方向对齐方式，类型为“Text”和"URLText"时有效：  "left/0"：居左  "right/1"：居右  "center/2"：居中 |                                                              |
| alignment-V     | 垂直方向对齐方式，类型为“Text”和"URLText"时有效：  "top/0"：居上  "bottom/1"：居下  "center/2"：居中 |                                                              |
| volume          | 视频播放音量（0-100）                                        |                                                              |
| scaleMode       | 缩放模式，包括窗口比例"Window"、原始比列"Original"           |                                                              |
| rotationMode    | 逆时针旋转角度，包括0度、90度、180度、270度                  |                                                              |