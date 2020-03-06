# BX-Y Delphi SDK
本项目为仰邦科技 BX-Y 系列的 Delphi 实现，调用仰邦封装的动态库文件，任何人都可直接在此代码上进行添加与修改。

本项目由Delphi7编写， 本 demo 中提供了 TCP 模式的简单使用方式。

* 代码

  

* 可执行程序

  



## 支持功能

* 更新动态区
* 删除动态区
* 更新节目
* 删除节目
* 其他

## 调用方法

此API接口的调用方式如下：

**步骤1：**

初始化动态库

```Delphi
init_sdk();
```

**步骤2：**

编辑节目，动态区

**步骤3：**

更新节目，动态区

**步骤4：**

释放动态库

```Delphi
release_sdk();
```

## 使用例程

```Delphi
//初始化动态库
init_sdk();
const device_type=9048;
var play_list,program_,pic_area:Cardinal;
    stay_time,display_effects,display_speed,x,y,transparency:integer;
play_mode,play_week,play_time:integer;
nResult           : Cardinal;
str,bg_color:WideString;
free_size,total_size:int64;
typed:Integer;

typed:=StrToInt(Edit3.Text);
play_list :=create_playlist(128,96,typed);
str:='program_1';    
bg_color := '0xff000000';
  program_:=create_program(PWideChar(str),PWideChar(bg_color));
pic_area :=create_pic;

stay_time:=1; display_effects:=1; display_speed:=16;
str:=Edit2.Text;
add_pic_unit(pic_area,1,1,1,PWideChar(str));

x:=0;  y:=0;  transparency:=100;
add_pic(program_,pic_area,0, 0, 128, 96, 255);

play_mode:=1;  play_week:=15;  play_time:=1;

str:='';
  add_program_in_playlist(play_list,program_,play_mode,play_time,PWideChar(str),PWideChar(str),PWideChar(str),PWideChar(str), 127);
str:='guest';
  nResult:=send_program(PChar(Edit1.Text),80,PWideChar(str),PWideChar(str),PWideChar(dir),play_list,0, free_size, total_size);
if nResult=0 then Caption :='发送 成功' else Caption :='发送 失败'+IntToStr(nResult);
cancel_send_program(play_list);

//释放动态库
release_sdk();
```

