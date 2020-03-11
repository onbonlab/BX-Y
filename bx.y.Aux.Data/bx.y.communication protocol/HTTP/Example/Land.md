# 4.1.2    用户登录报文示例

 POST方式

请求实体：

```json
POST / HTTP/1.1
Host: 192.168.8.39
Accept:text/json
Content-Type: application/json;charset=UTF-8
Content-Length: 212

{"protocol":{"name":"YQ-COM2","version":"1.0","remotefunction":{"name": "UserLogin","input":{"password":"35c83b5baf44bf36c8340fa87845d8043a46a225","username":"guest","verificationcode":"20180517093429462773"}}}}
```

控制器回复：

```json
HTTP/1.1 200 OK
Server: nginx/1.10.1
Date: Thu, 17 May 2018 01:34:29 GMT
Content-Type: application/json
Transfer-Encoding: chunked
Connection: keep-alive

{"remotefunction": {"name": "userlogin", "output": {"sessionID": "71862f05d7dfcd189ce9d78109b9e8a1"}}}
```

 

 GET方式

请求实体：

```json
GET /?parameter=%7B%22protocol%22:%7B%22name%22:%20%22YQ-COM2%22,%22version%22:%20%221.0%22,%22remotefunction%22:%7B%22name%22:%20%22UserLogin%22,%22input%22:%7B%27username%27:%27admin%27,%27verificationcode%27:%2720180323184222719316%27,%27password%27:%274fdd7ce377ef533cb8d8a6048d1c5df3f03c7ce2%27%7D%7D%7D%7D HTTP/1.1

Host: 192.168.8.39
Connection: keep-alive
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36

Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8

Accept-Encoding: gzip, deflate
Accept-Language: zh-CN,zh;q=0.9
```

控制器回复：

```json
HTTP/1.1 200 OK
Server: nginx/1.10.1
Date: Thu, 17 May 2018 01:53:03 GMT
Content-Type: application/json
Transfer-Encoding: chunked
Connection: keep-alive

{"remotefunction": {"error": {"code": 27, "mesg": "Verification code error"}, "name": "userlogin"}}
```

