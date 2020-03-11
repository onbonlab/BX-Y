# 4.1.1    获取校验码报文示例

 POST方式

请求实体：

```json
POST / HTTP/1.1
Host: 192.168.0.199
Accept:text/json
Content-Type: application/json;charset=UTF-8
Content-Length: 96

{"protocol":{"name":"YQ-COM2","version":"1.0", "remotefunction":{"name":"getVerificationCode"}}}
```

控制器回复：

```json
HTTP/1.1 200 OK
Server: nginx/1.10.1
Date: Tue, 15 May 2018 10:46:25 GMT
Content-Type: application/json
Transfer-Encoding: chunked
Connection: keep-alive

{"remotefunction": {"name": "getverificationcode", "output": {"verificationcode": "20180515184625583374"}}}
```

 

 GET方式

请求实体：

```json
GET /?parameter=%7B%22protocol%22:%7B%22name%22:%22YQ-COM2%22,%22version%22:%221.0%22,%20%22remotefunction%22:%7B%22name%22:%22GetVerificationCode%22%7D%7D%7D HTTP/1.1

Host: 192.168.1.19
Connection: keep-alive
Cache-Control: max-age=0
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
Date: Thu, 17 May 2018 01:20:47 GMT
Content-Type: application/json
Transfer-Encoding: chunked
Connection: keep-alive

{"remotefunction": {"name": "getverificationcode","output": {"verificationcode":"20180517092047470808"}}}
```

