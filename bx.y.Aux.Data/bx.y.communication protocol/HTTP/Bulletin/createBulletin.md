# 4.9.1    创建公告  - createBulletin

*指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "createBulletin"
      "input": {
        "name":"bulletin0",
        "xcoord": "0",
        "ycoord":"0",
        "width":"400",
        "height":"32",
        "order":"0",
        "transparency":"100",
        "layoutMode":"Top",
        "bgColor":"0xFF00FF00",
        "fontName":"SimSun",
        "fontSize":"24",
        "fontColor":"0xFFFF0000",
        "fontAttributes":"normal",
        "stuntType":"5",
        "stuntSpeed":"16",
        "stayTime":"0",
        "startDate":"",
        "stopDate":"",
        "startTime":"",
        "stopTime":"",
        "content":"经过base64编码的公告显示内容"
      }
    }
  }
}
```

参数说明：

- "order"：公告序号，暂定0 ～ 99

- "name"：自定义公告名称

- "layoutMode"：公告布局模式，‘top’/0 - 居上，‘bottom’/1 - 居下，‘custom’/2 - 自定义

- "xCoord"：自定义布局模式有效，定义左上角x坐标

- "yCoord"：自定义布局模式有效，定义左上角y坐标

- "width"：自定义布局模式有效，定义区域宽度

- "height"：自定义布局模式有效，定义区域高度

- "transparency"：区域整体透明度，范围0～100，默认100为完全不透明

- "startDate"：播放开始日期，年月日格式：’yyyy-MM-dd’

- "startTime"：播放开始时间，时分秒格式：’hh:mm:ss’

- "stopDate"：播放结束日期，年月日格式：’yyyy-MM-dd’

- "stopTime"：播放结束时间，时分秒格式：’hh:mm:ss’

- "weekFlag"：星期有效属性：第1～7位分别代表周一～周日,例如：’1’表示只在周一播放，’127’表示在周一～周日都播放

- "bgColor"："0xAARRGGBB"格式的区域背景色，默认‘0xFF000000’ - 不透明黑色

- "fontName"：字体名称，默认宋体 - "SimSun"

- "fontSize"：字体大小，与"fontSizeType"一道确定字体的实际大小

- "fontSizeType"：字体大小单位，‘pixel’/0 以像素为单位(默认)，‘point’/1 以磅为单位

- "fongColor"："0xAARRGGBB"格式的字体颜色，默认’0xFFFFFFFF’ - 不透明白色

- "fontAttributes"：字体附加属性，包括’bold’,’italic’,’normal’,’underline’, ’strikeout’等五种; 可通过’&’组合,例如 ：’bold& italic& underline’

- "fontAlignment"：文本对齐方式（未实现）

- "stuntType"：分区特技类型序号

- "stuntSpeed"：分区特技速度等级，范围1～16，1为最快

- "stayTime"：分区特技停留时间，以秒为单位（暂定）

- "content"：文本内容