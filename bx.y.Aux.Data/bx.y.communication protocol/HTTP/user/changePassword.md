# 4.2.4    修改口令 - changePassword

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "changePassword",
      "input": {
        "username": "guest",
        "password1": "SHA1值",
        "password2": "验证码"
      }
    }
  }
}
```

修改密码后，请自行记录。遗忘密码，将导致控制卡无法使用（发送节目等）。需使用专用工具才能恢复密码，或者恢复出厂固件也可以恢复密码。

参数说明：

 "username": 需要修改密码的用户名（现阶段只有guest用户）

 "password1": 新密码的SHA1加密值

 "password2": 对新密码的SHA1加密值"password1"进行base64编码的结果