# 4.1.3    校对时间报文示例

 POST方式

请求实体（其中stok后的字串为用户登录指令成功后返回的"sessionID"）：

```json
POST /;stok=71862f05d7dfcd189ce9d78109b9e8a1/ HTTP/1.1
Host: 192.168.8.39
Accept:text/json
Content-Type: application/json;charset=UTF-8
Content-Length: 139

{"protocol":{"name":"YQ-COM2","version":"1.0","remotefunction":{"name": "SystemClockCorrect","input":{"datetime":"2018-05-17 12:35:18"}}}}
```

控制器回复：

```json
HTTP/1.1 200 OK
Server: nginx/1.10.1
Date: Thu, 17 May 2018 04:35:18 GMT
Content-Type: application/json
Transfer-Encoding: chunked
Connection: keep-alive
 
{"remotefunction": {"name": "systemclockcorrect"}}
```

 

 GET方式

请求实体：

```json
GET /;stok=372267c68435e4ea61150cb752fcbae4/?parameter=%20%0A%0A%7B%22protocol%22:%7B%22name%22:%20%22YQ-COM2%22,%22version%22:%20%221.0%22,%22clienttype%22:%22PC%22,%22remotefunction%22:%7B%22name%22:%20%22systemClockCorrect%22,%22input%22:%7B%22datetime%22:%222018-05-17%2012:43:00%22%7D%7D%7D%7D%0A HTTP/1.1

Host: 192.168.8.39
Connection: keep-alive
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36

Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8

Accept-Encoding: gzip, deflate
Accept-Language: zh-CN,zh;q=0.9
```

