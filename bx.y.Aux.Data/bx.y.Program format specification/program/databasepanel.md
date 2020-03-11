# 3.2.11    数据库分区

|                             | 标签属性           | 类型                                                         | 说明                                                         |
| --------------------------- | ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| <databasepanel>或<database> | -                  | 数据库分区                                                   |                                                              |
| √                           | xCoord/x           | int                                                          | 分区左上角x坐标                                              |
| √                           | yCoord/y           | int                                                          | 分区左上角y坐标                                              |
| √                           | width/w            | int                                                          | 分区宽度                                                     |
| √                           | height/h           | int                                                          | 分区高度                                                     |
| √                           | zOrder/z           | int                                                          | 分区层次，0代表底层，数字越大层次越高                        |
| -                           | transparency/t     | int                                                          | 分区透明度(0~100)：100为完全不透明，默认100                  |
| <dbUnit>                    | -                  | <database>的子标签，子单元定义  最大允许个数暂定32个，按order顺序播放 |                                                              |
| √                           | order              | int                                                          | 播放顺序：0~31                                               |
| -                           | bgImage            | string                                                       | 背景图片文件路径                                             |
| √                           | pageStayTime       | int                                                          | 页停留时间，3~3600秒                                         |
| -                           | updateEmptyData    | bool/int                                                     | 查询数据库数据为空时是否显示最后一次数据：  ‘true’/1 - 显示为空，‘false’/0  - 保持上次查询数据  默认为‘false’ |
| √                           | dbType             | string                                                       | 数据库服务器类型：  ‘mysql’ - MySQL  ‘sqlserver’ - MS SQL Server  ‘postgresql’ – PostgreSQL（暂不支持） |
| √                           | host               | string                                                       | 服务器地址或域名                                             |
| √                           | port               | int                                                          | 服务器端口                                                   |
| -                           | instance           | string                                                       | ‘sqlserver’的可选参数（暂不支持）                            |
| √                           | user               | string                                                       | 用户名                                                       |
| √                           | password           | string                                                       | 密码                                                         |
| -                           | dbName             | string                                                       | 数据库名称，‘mysql’必须有该参数                              |
| √                           | queryCommand       | string                                                       | **数据库查询指令**（全局）                                   |
| √                           | displayRows        | int                                                          | 每页显示行数                                                 |
| √                           | displayColumns     | int                                                          | 每页显示列数                                                 |
| -                           | oddLinesBgColor    | string                                                       | 奇数行背景颜色，默认‘0x00000000’  - 透明无色(黑色)           |
| -                           | evenLinesBgColor   | string                                                       | 偶数行背景颜色，默认‘0x00000000’  - 透明无色(黑色)           |
| -                           | oddLinesFontColor  | string                                                       | 奇数行字体颜色，默认‘0xFFFFFFFF’  - 不透明白色               |
| -                           | evenLinesFontColor | string                                                       | 偶数行字体颜色，默认‘0xFFFFFFFF’  - 不透明白色               |
| √                           | fontName           | string                                                       | 字体名称                                                     |
| √                           | fontSize           | int                                                          | 字体大小                                                     |
| -                           | fontSizeType       | string/int                                                   | 字体大小单位选择（默认‘pixel’）：  ‘pixel’/0 以像素为单位，‘point’/1  以磅为单位 |
| -                           | fontAttributes     | string                                                       | 字体附加属性：  包括‘bold’, ‘italic’, ‘normal’, ‘underline’, ‘strikeout’等五种;  可通过‘&’组合,例如 ：‘bold&  italic& underline’ |
| -                           | alignment_H        | string                                                       | 水平方向对齐方式（默认‘center’）：  ‘left’ - 居左，‘center’  - 居中，‘right’ - 居右 |
| -                           | alignment_V        | string                                                       | 垂直方向对齐方式（默认‘center’）：  ‘top’ - 居上，‘center’  - 居中，‘bottom’ - 居下 |
| -                           | autoLF             | bool                                                         | 自动换行标志：‘True’ - 自动换行，默认‘False’                 |
| -                           | rowToColumn        | bool                                                         | 行列互换标志：‘True’ - 行列互换，默认‘False’  该字段只是改变数据内容的显示方式，**不改变样式中的行列定义** |
| -                           | displayFieldName   | bool                                                         | 字段名显示与否标志：‘False’ - 不显示，默认‘True’             |
| -                           | paintTable         | bool                                                         | 表格边框绘制与否标志：‘False’ - 不绘制，默认‘True’           |
| -                           | tableLineWidth     | int                                                          | 网格线宽：1~5                                                |
| -                           | tableLinear        | string                                                       | 网格线样式：‘solid’ - 实线； ‘dash’  - 虚线；‘dot’ – 点虚线；‘dashdot’  - 点划线；‘dashdotdot’ - 双点划线；默认‘solid’ |
| -                           | tableLineColor     | string                                                       | 网格线颜色，默认‘0xFFFF0000’  - 不透明红色                   |
| <specifyRow>                | -                  | <dbUnit>的子标签，特定行属性定义，用于指定特定行的高度。可以有多个，也可以没有。没有用该标签指定高度的行，高度自动计算获得 |                                                              |
| √                           | row                | int                                                          | 指定行的索引值：1 ~ displayRows                              |
| -                           | rowHeight          | int                                                          | 指定行的高度，**不能小于以像素为单位的字体高度**             |
| -                           | bgColor            | string                                                       | 指定行背景色                                                 |
| -                           | fontColor          | string                                                       | 单元格字体颜色                                               |
| -                           | fontName           | string                                                       | 单元格字体名称                                               |
| -                           | fontSize           | int                                                          | 单元格字体大小                                               |
| -                           | fontSizeType       | string/int                                                   | 单元格字体大小单位选择（默认‘pixel’）：  ‘pixel’/0 以像素为单位，‘point’/1  以磅为单位 |
| -                           | fontAttributes     | string                                                       | 字体附加属性：  包括‘bold’, ‘italic’, ‘normal’, ‘underline’, ‘strikeout’等五种;  可通过‘&’组合,例如 ：‘bold&italic&underline’ |
| -                           | alignment_H        | string                                                       | 水平方向对齐方式（默认‘center’）：  ‘left’ - 居左，‘center’  - 居中，‘right’ - 居右 |
| -                           | alignment_V        | string                                                       | 垂直方向对齐方式（默认‘center’）：  ‘top’ - 居上，‘center’  - 居中，‘bottom’ - 居下 |
| -                           | autoLF             | bool                                                         | 自动换行标志：‘True’ - 自动换行，默认‘False’                 |
| <specifyColumn>             | -                  | <dbUnit>的子标签，特定列属性定义，用于指定特定列的宽度。可以有多个，也可以没有。没有用该标签指定宽度的列，宽度自动计算获得 |                                                              |
| √                           | column             | int                                                          | 指定列的索引值：1 ~ displayColumns                           |
| -                           | columnWidth        | int                                                          | 指定列的高度                                                 |
| -                           | bgColor            | string                                                       | 指定列背景色                                                 |
| -                           | fontColor          | string                                                       | 单元格字体颜色                                               |
| -                           | fontName           | string                                                       | 单元格字体名称                                               |
| -                           | fontSize           | int                                                          | 单元格字体大小                                               |
| -                           | fontSizeType       | string/int                                                   | 单元格字体大小单位选择（默认‘pixel’）：  ‘pixel’/0 以像素为单位，‘point’/1  以磅为单位 |
| -                           | fontAttributes     | string                                                       | 字体附加属性：  包括‘bold’, ‘italic’, ‘normal’, ‘underline’, ‘strikeout’等五种;  可通过‘&’组合,例如 ：‘bold&italic&underline’ |
| -                           | alignment_H        | string                                                       | 水平方向对齐方式（默认‘center’）：  ‘left’ - 居左，‘center’  - 居中，‘right’ - 居右 |
| -                           | alignment_V        | string                                                       | 垂直方向对齐方式（默认‘center’）：  ‘top’ - 居上，‘center’  - 居中，‘bottom’ - 居下 |
| -                           | autoLF             | bool                                                         | 自动换行标志：‘True’ - 自动换行，默认‘False’                 |
| <specifyCell>               | -                  | <dbUnit>的子标签，特定单元格定义，用于指定特定单元格的显示属性。可以有多个，也可以没有。 |                                                              |
| √                           | row                | int                                                          | 指定单元格的行索引值：1 ~ displayRows                        |
| √                           | column             | int                                                          | 指定单元格的列索引值：1 ~ displayColumns                     |
| -                           | bgColor            | string                                                       | 指定单元格背景色                                             |
| -                           | content            | string                                                       | 强制指定该单元格的显示指定内容  忽略全局和局部 ‘queryCommand’的内容 |
| -                           | fontColor          | string                                                       | 单元格字体颜色                                               |
| -                           | fontName           | string                                                       | 单元格字体名称                                               |
| -                           | fontSize           | int                                                          | 单元格字体大小                                               |
| -                           | fontSizeType       | string/int                                                   | 单元格字体大小单位选择（默认‘pixel’）：  ‘pixel’/0 以像素为单位，‘point’/1  以磅为单位 |
| -                           | fontAttributes     | string                                                       | 字体附加属性：  包括‘bold’, ‘italic’, ‘normal’, ‘underline’, ‘strikeout’等五种;  可通过‘&’组合,例如 ：‘bold&italic&underline’ |
| -                           | alignment_H        | string                                                       | 水平方向对齐方式（默认‘center’）：  ‘left’ - 居左，‘center’  - 居中，‘right’ - 居右 |
| -                           | alignment_V        | string                                                       | 垂直方向对齐方式（默认‘center’）：  ‘top’ - 居上，‘center’  - 居中，‘bottom’ - 居下 |
| -                           | autoLF             | bool                                                         | 自动换行标志：‘True’ - 自动换行，默认‘False’                 |

注：1. 特别指定的优先级为：指定单元格 > 指定列> 指定行 > 全局