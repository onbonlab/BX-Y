# 附录7  表单上传文件命名规则

```http
POST /upload HTTP/1.1

Content-Type: multipart/form-data; boundary=--------------------------866009359719137606378166

Accept: text/json

accept-encoding: gzip, deflate

content-length: 223019

 

----------------------------866009359719137606378166

Content-Disposition: form-data; name="409b24bb8fb7f03d76908852c9f105d0.bmp"; filename="testPic1.bmp"

Content-Type: image/bmp

 

BM6.......6...(.......`..... ....（完整文件内容）

----------------------------866009359719137606378166--
```

 

* "filename"：上传前的文件名（对控制卡来说无实际用途）

* "name"：上传后临时（后续需要移动）存储在控制卡上的文件名，其命名规则如下：

  * 命名方式有两种：

    文件名以文件的MD5值开头，格式：{MD5值}[.[文件后缀名]]，控制卡须进行MD5校验，校验值出错，控制卡回复错误并丢弃文件；文件名以"_"字符开头，格式：_{[a~z][A~Z][0~9]}[.[文件后缀名]] ，控制卡不校验，也不会回复错误

    文件名命名可用字符包括：数字（0~9），大小写字母（a~z,A~Z），“_”，“.”，“-”；不支持中文或其他特殊文字。