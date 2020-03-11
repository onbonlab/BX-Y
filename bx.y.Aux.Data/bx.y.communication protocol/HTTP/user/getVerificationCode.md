# 4.2.1    获取校验码 - getVerificationCode

 *指令样例：*

```json
{
  "protocol": {
     "name": "YQ-COM2","version": "1.0",
     "remotefunction": {
      "name": "getVerificationCode",
      "input": {
        "username": "guest"
      }
    }
  }
}
```

 *回复样例：*

```json
{
  "remotefunction": {
   "name": "getVerificationCode",
    "output": {
      "verificationcode": "20180515184625583374"
    }
  }
}
```

* "verificationcode"是控制卡生成的一段与时间相关的字符，用于后续的登录指令。