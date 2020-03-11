# 4.10.2   更新动态区素材 - updateDynamicUnits

 *指令样例：*

```json
{
	"protocol":{
	  "name": "YQ-COM2","version": "1.0",
	  "remotefunction":{
	    "name": "UpdateDynamicUnits",
		"input": {
		"dynamics": [{
		  "id"："0",
		  "order":"0",
		  "content":"409b24bb8fb7f03d76908852c9f105d0.bmp"
		},{"id"："0",
		  "order":"1",
		  "content":"0bb856e65ec7a08cc12a7d791c8be271.bmp"
		},]
		}
	  }
	}
}
```

该指令用于更新现有动态区unit的素材，暂时只支持"Picture/0"和"Text/1"类型的动态区。使用该命令时需确保更新素材的动态区只有素材变更，其他所有属性均无变化，否则可能引起动态区未知异常。

-  “dynamics”：需要更新的动态区列表。其中动态区ID和unit order必须是已经存在的，且类型为"Picture/0"或"Text/1"。

-  “id”：动态区ID。

-  “order”：unit的order，必须同”更新动态区”命令中unit的order相对应。

-  “content”： 当文件内容包含于普通POST请求中时，该项为文件内容进行base64编码。当文件通过表单形式上传时（报文格式参见 [HTTP报文示例四 POST表单方式上传文件](HTTPcommand.md)），该项为表单文件另存文件名（另存文件名命名规则参见 [表单上传文件命名规则](Appendix7.md)）。


 