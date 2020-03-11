# 4.1.4    上传文件报文示例

 普通文件上传（不包含实际指令）

请求实体（其中URI路径为/upload）：

```json
POST /upload HTTP/1.1
Content-Type: multipart/form-data; boundary=--------------------------866009359719137606378166
Accept: text/json
accept-encoding: gzip, deflate
content-length: 223019
----------------------------866009359719137606378166
Content-Disposition: form-data; name="409b24bb8fb7f03d76908852c9f105d0.bmp"; filename="testPic1.bmp"
Content-Type: image/bmp

BM6.......6...(.......`..... ....（完整文件内容）
----------------------------866009359719137606378166

Content-Disposition: form-data; name="0bb856e65ec7a08cc12a7d791c8be271.bmp"; filename="testPic2.bmp"
Content-Type: image/bmp
BM8.......6... （完整文件内容）
----------------------------866009359719137606378166--
```

控制器回复：

```json
HTTP/1.1 200 OK
Server: nginx/1.10.1
Date: Thu, 25 Oct 2018 05:32:35 GMT
Content-Type: application/json
Transfer-Encoding: chunked
Connection: keep-alive

Upload OK
```

 

 动态区文件上传（动态区指令包含在“command”字段中：更新播放动态区指令或更新动态区素材指令）

请求实体（其中URI路径为/dynamic/;stok=有效的sessionID）：

```json
POST /dynamic/;stok=372267c68435e4ea61150cb752fcbae4 HTTP/1.1

Content-Type: multipart/form-data; boundary=--------------------------866009359719137606378166
Accept: text/json
accept-encoding: gzip, deflate
content-length: 223019
----------------------------866009359719137606378166

Content-Disposition: form-data; name="409b24bb8fb7f03d76908852c9f105d0.bmp"; filename="testPic1.bmp"
Content-Type: image/bmp
BM6.......6...(.......`..... ....（完整文件内容）
----------------------------866009359719137606378166

Content-Disposition: form-data; name="0bb856e65ec7a08cc12a7d791c8be271.bmp"; filename="testPic2.bmp"
Content-Type: image/bmp
BM8.......6... （完整文件内容）
----------------------------866009359719137606378166

Content-Disposition: form-data; name="command"

{"protocol":{"name": "YQ-COM2","version": "1.0","remotefunction":{"name": "UpdateDynamic","input": {"immediatelyPlay":"0","cover":"0","dynamics":[{"id":"0","xCoord": "0","yCoord":"0","width":"128","height":"96","transparency":"100","relativeProgram":"","runMode":"0","updateFrequency":"10","unit":[ {"type":"Picture","order":"0","stuntType":"1","stuntSpeed":"1","stayTime":"5","content":"409b24bb8fb7f03d76908852c9f105d0.bmp","gifFlag":"0"},{"type":"Picture","order":"1","stuntType":"1","stuntSpeed":"1","stayTime":"5","content":"0bb856e65ec7a08cc12a7d791c8be271.bmp","gifFlag":"0"}]}]}}}}
----------------------------866009359719137606378166--
```

控制器回复：

```json
HTTP/1.1 200 OK
Server: nginx/1.10.1
Date: Thu, 25 Oct 2018 05:32:35 GMT
Content-Type: application/json
Transfer-Encoding: chunked
Connection: keep-alive

{"remotefunction": {"name": "updatedynamic"}}
```

 

 

注：表单中的文件名命名须符合规则，具体参见：[附录7  表单上传文件命名规则](Appendix7.md)