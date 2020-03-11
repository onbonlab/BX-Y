# 4.2.2    用户登录 - userLogin

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "userLogin",
      "input": {
        "username": "guest",
        "verificationcode": "20180515184625583374",
        "password": "ece10bbcd940ef4356e6d6f61cc6525c7924bab6"
      }
    }
  }
}
```

参数说明：

-  "username": 登录的用户名,供用户使用的只有 ‘guest’　

-  "verificationcode": 必须为通过“获取校验码”命令获取的校验码，使用“用户登录”指令前必须先使用“获取校验码”

-  "password": 为“verificationcode”的值和登录用户的密码的SHA1码拼接后再进行SHA1计算的结果。


  *回复样例：*

```json
{
"remotefunction": {
"name": "userLogin",
"output": {
	"sessionID": "5029f6bcfb12e969cec02bd633d269d7"
    }
  }
}
```

* "sessionID"返回的值用于其他指令的路径中。