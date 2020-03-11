# 2.   用户工作目录结构

以下为控制卡内部供用户使用的根目录结构，用户节目文件中能使用的目录、文件都是相对于该根目录的。**请勿删除根下的专用目录**。

```
└──/
   ├── backup/
   ├── bulletins/
   ├── download/
   ├── dynamics_save/
   ├── fonts/
   ├── lists/
   ├── log/
   ├── nginx_upload/
   ├── programs/
   ├── share/
   ├── update/
   ├── upload/
   └── user/
```

 

- backup：备份用目录
- bulletins：公告节目专用目录
- download：临时下载目录
- dynamics_save：保存动态区节目专用目录
- fonts：保存用户自行安装字库专用目录
- lists：保存播放列表的专用目录
- log：保存各模块日志文件的专用目录
- nginx_upload：用户通过http协议上传文件的临时中转目录，使能上传功能后有效
- programs：保存节目文件的专用目录
- share：保存节目素材文件的专用目录
- update：系统升级维护的专用目录
- user：用户自维护目录