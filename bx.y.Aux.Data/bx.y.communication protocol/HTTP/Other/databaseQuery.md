# 4.11.5   数据库查询 - databaseQuery

*指令样例：*

```json
{
  "protocol": {
	"name": "YQ-COM2","version": "1.0",
	"remotefunction": {
	"name": "databaseQuery",
	"input": {
      "host": "192.168.8.173",
      "port": "1433",
      "user": "sa",
      "pass": "ODg4ODg4",
      "dbtype": "sqlserver",
      "dbname": "",
      "querycmd": "select [ID] AS 'ID',[name] AS 'Name',\
		[age] AS 'Age', [sex] AS 'Sex' from table_A"
 		}
	  }
	}
}
```

参数说明：

- "host"：数据库服务器主机域名或IP

- "port"：数据库服务器主机端口

- "user"：数据库服务器访问用户名 

- "pass"：数据库服务器访问密码的base64编码值

- "dbtype"：数据库类型"sqlserver"或"mysql"

- "dbname"："dbtype"为"mysql"时用于指定数据库名

- "querycmd"：数据库查询命令，注意不同数据库类型指令的差异；控制卡使用该参数的原语句尝试查询，不做任何修改。


*回复样例：*

```json
{
"remotefunction": {
    "name": "databaseQuery",
    "output": {
        "totalRows" : 3, 
        "totalColumns" : 4, 
        "filed": ["ID", "Name", "Age", "Sex"],
        "data" : [["002", "Tom", "12", "boy"],
                  ["003", "Jerry", "12", "boy"],
                  ["005", "Mairy", "11", "girl"]
                 ]
    }
}
}
```

参数说明：

- "totalRows"：返回数据库查询结果的数据总条数，超过10条的只返回10

- "totalColumns"：返回数据库查询结果的总字段数

- "field"：返回一维数组形式的数据库查询结果的各字段名（或由指令决定的别名）

- "data"：返回二维数组形式的数据库查询结果


*错误样例：*

```json
{
"remotefunction": {
  "name": "databaseQuery",
  "error": {
    "code": "错误码",
    "mesg": "具体错误描述"
	}
  }
}
```

参见[附录2：错误码列表](Appendix.md)