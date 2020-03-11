# 4.5.10   上传文件到FTP - uploadFileToFtpServer

*指令样例：*

```json
{
"protocol": {
	"name": "YQ-COM2", "version": "1.0",
	"remotefunction": {
		"name": "uploadFileToFtpServer",
		"input": {
		  "host": "192.168.88.222",
		  "port": "21",
		  "user": "guest",
		  "password": "guest",    
		  "srcfile": "share/example.bmp",
		  "dstfile": "exampledir/exampleDst.bmp"
		}
	}
  }
}
```

参数说明：

- "host"：FTP服务器主机，可以是域名，前提是控制卡设置了域名服务器

- "port": FTP服务器端口，没有该项，默认用21

- "user": 用户名

- "password": 密码

- "srcfile": 控制卡中用户目录中的文件名

- "dstfile": 服务器中的有效路径，如果不带文件名(以‘/’结尾)，则使用源文件名


*回复样例：*

```json
{
"remotefunction": {
    "name": "uploadFileToFtpServer","output": {
        "size": "10921"
    }
}
}
```

参数说明：

* "size"：控制卡中文件的大小，可能发生变化

 