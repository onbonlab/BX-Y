unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, IdHashMessageDigest;
const   pw=200; ph=120;

type
  TSetDisplayModeThread = class(TThread)
  private
    { Private declarations }
    fip: string;
    ffilename: string;
    fresult: integer;

  protected
    procedure Execute; override;
  public
    constructor Create(ip, fname: string);

    property Xresult: integer read fresult;

  end;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Button4: TButton;
    Button5: TButton;
    Memo1: TMemo;
    Edit3: TEdit;
    Button6: TButton;
    Button7: TButton;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  dir:WideString;
  hDll:THandle;

  function init_sdk():integer; stdcall external 'YQNetCom';
  function release_sdk(): integer; stdcall external 'YQNetCom';
  function set_screen_turnonoff(ip:pchar;port:longword;user_name,user_pwd:widestring;turnonoff_status:integer):integer; stdcall;  external 'YQNetCom';  //开关屏

  function create_playlist(w,h,device_type:integer): LongWord ; stdcall external 'YQNetCom';                               //创建播放列表
  function create_program(name,bg_color:WideString): LongWord; stdcall  external 'YQNetCom';                                       //创建节目

  function create_pic(): LongWord; stdcall  external 'YQNetCom';                                                          //创建图分区
  function add_pic_unit(pic_area:Longword;stay_time,display_effects,display_speed:integer;src_path:WideString): integer; stdcall external 'YQNetCom';  //图片分区添加图片
  function add_pic(program_,pic_area:longword;x,y,w,h,transparency:integer): integer; stdcall external 'YQNetCom'; //节目添加图片分区

  function create_time(): LongWord; stdcall  external 'YQNetCom';                                                          //创建图分区
  function add_time_unit(time_area:Longword;content,font_color,font_namestay_time:WideString;font_size,x,y:integer;font_attributes:WideString): integer; stdcall external 'YQNetCom';  
  function add_time(program_,time_area:longword;x,y,w,h,transparency:integer;bg_color,time_equation,positive_te:WideString): integer; stdcall external 'YQNetCom';
  
  function create_video(): LongWord; stdcall external 'YQNetCom';  
  //创视频分区
  function add_video_unit(video_area:longword;volume,scale_mode,source,play_time:integer;src_path,crop_type:WideString): integer; stdcall external 'YQNetCom'; //视频分区添加视频
  function add_video_md5(PlayList:longword;vutMD5,filePath:widestring): integer; stdcall external 'YQNetCom';
  function add_video(program_,video_area:longword; x, y, w, h, volume_mode, video_type,ratation_mode:integer;clone_str,crop_type:WideString): integer; stdcall external 'YQNetCom';  //节目添加视频分区

  function add_program_in_playlist(playlist,program_:longword;play_mode,play_time:integer;
  aging_start_time,aging_end_time,period_ontime,period_offtime:WideString;play_week:integer): integer; stdcall external 'YQNetCom'; //播放列表添加节
  function send_program(ip:pchar;port:longword;user_name,user_pwd,tmp_path:WideString;playlist:longword;send_style:integer;var free_size,total_size:int64): integer; stdcall external 'YQNetCom';  //发送播放列表到控制卡
  function cancel_send_program(playlist:longword): integer; stdcall external 'YQNetCom';
implementation

    function create_dynamic(): longword;stdcall external 'YQNetCom'; // 创建动态区句柄
	
    function add_dynamic(tree,area_tree: longword; dynamic_id, x, y, w, h, relative_program, run_mode: integer; update_frequency: pwidechar; transparency: integer): integer;stdcall external 'YQNetCom'; // 把动态区添加到节目
	
    function add_dynamic_unit(dynamic_area: longword; dynamic_type, display_effects, display_speed, stay_time: integer; file_path: WideString; gif_flag: integer; bg_color: pwidechar; font_size: integer; font_name, font_color, font_attributes, align_h, align_v: pwidechar; volumn, scale_mode, rolation_mode: integer): integer;stdcall external 'YQNetCom'; // 添加动态区图文数据
	
    procedure delete_dynamic(area_tree:longword); stdcall external 'YQNetCom';//删除动态区句柄

    function update_dynamic(ip: pchar; port: longword; user_name, user_pwd: pwidechar; dynamic_playlist: longword; immediately_play,  conver,  onlyUpdate: integer): integer;stdcall external 'YQNetCom';//更新动态区

{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);
begin
  init_sdk;
  dir:=ExtractFilePath(Application.ExeName);
  if not DirectoryExists(dir+'data') then MkDir(dir+'data');
end;

procedure TForm1.Button1Click(Sender: TObject);
const device_type=9048;
var play_list,program_,pic_area:Cardinal;
    stay_time,display_effects,display_speed,x,y,transparency:integer;
    play_mode,play_week,play_time:integer;
    nResult           : Cardinal;
    str,bg_color:WideString;
	free_size,total_size:int64;
  typed:Integer;
begin
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
end;

procedure TForm1.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  release_sdk;
end;

procedure TForm1.Button2Click(Sender: TObject);
var nResult:Cardinal;
begin
   nResult :=set_screen_turnonoff(PChar(Edit1.Text),80,pchar('guest'),pchar('guest'),1);
   Caption :=inttostr(nResult);
   if nResult=0 then Caption :='发送 成功' else Caption :='发送 失败';
end;

procedure TForm1.Button3Click(Sender: TObject);
var nResult:Cardinal;
begin
   nResult :=set_screen_turnonoff(PChar(Edit1.Text),80,pchar('guest'),pchar('guest'),0);
   if nResult=0 then Caption :='发送 成功' else Caption :='发送 失败';
end;

procedure TForm1.Button4Click(Sender: TObject);
var play_list,program_,time_area:Cardinal;
    stay_time,display_effects,display_speed,x,y,transparency:integer;
    play_mode,play_week,play_time:integer;
    nResult           : Cardinal;
    str,content,content1,content2,content3,font,color,font_attributes,bg_color,time_equation,positive_te:WideString;
	free_size,total_size:int64;
  typed:Integer;
begin
  typed:=StrToInt(Edit3.Text);
  play_list :=create_playlist(128,96,typed);
  str:='program_1';
  bg_color := '0xff000000';
  program_:=create_program(PWideChar(str),PWideChar(bg_color));
  time_area :=create_time;

  stay_time:=1; display_effects:=1; display_speed:=16;
  content:='使用';
  content1:='%Y年%m月%d日';
  content2:='星期%w';
  content3:='%H时%M分%S秒';
  font:='宋体';
  color:='0xffff0000';
  font_attributes:='bold';
  bg_color:='0xff000000';
  time_equation:='00:00:00';
  positive_te:='+';
  add_time_unit(time_area, PWideChar(content), PWideChar(color), PWideChar(font), 12, 0, 16, PWideChar(font_attributes));
  add_time_unit(time_area, PWideChar(content1), PWideChar(color), PWideChar(font), 12, 0, 32, PWideChar(font_attributes));
  add_time_unit(time_area, PWideChar(content2), PWideChar(color), PWideChar(font), 12, 0, 48, PWideChar(font_attributes));
  add_time_unit(time_area, PWideChar(content3), PWideChar(color), PWideChar(font), 12, 0, 64, PWideChar(font_attributes));
  add_time(program_,time_area,0, 0, 128, 96, 255,PWideChar(bg_color), PWideChar(time_equation), PWideChar(positive_te));

  play_mode:=1;  play_week:=15;  play_time:=1;

  str:='';
  add_program_in_playlist(play_list,program_,play_mode,play_time,PWideChar(str),PWideChar(str),PWideChar(str),PWideChar(str), 127);
  str:='guest';
  nResult:=send_program(PChar(Edit1.Text),80,PWideChar(str),PWideChar(str),PWideChar(dir),play_list,0, free_size, total_size);
  if nResult=0 then Caption :='发送 成功' else Caption :='发送 失败'+IntToStr(nResult);
  cancel_send_program(play_list);
end;

procedure TForm1.Button5Click(Sender: TObject);
var play_list,program_,video_area:Cardinal;
    stay_time,display_effects,display_speed,x,y,transparency:integer;
    play_mode,play_week,play_time:Integer;
    nResult           : Cardinal;
    str,str1,bg_color:WideString;
	free_size,total_size:int64;
  typed:Integer;
begin
  typed:=StrToInt(Edit3.Text);
  play_list :=create_playlist(128,96,typed);
  str:='program_1';
  bg_color := '0xff000000';
  program_:=create_program(PWideChar(str),PWideChar(bg_color));
  video_area :=create_video;
  str:=Edit2.Text;
  str1:=' ';
  add_video_unit(video_area,  2, 1, 0, 100, PWideChar(str), PWideChar(str1));
  //add_video_md5(play_list, md5, PWideChar(str));
  str:='';
  add_video(program_,video_area,0, 0, 128, 96, 0,0,0,PWideChar(str1), PWideChar(str1));

  play_mode:=1;  play_week:=15;  play_time:=1;

  str:='';
  add_program_in_playlist(play_list,program_,play_mode,play_time,PWideChar(str),PWideChar(str),PWideChar(str),PWideChar(str), 127);
  str:='guest';
  nResult:=send_program(PChar(Edit1.Text),80,PWideChar(str),PWideChar(str),PWideChar(dir),play_list,0, free_size, total_size); 
  if nResult=0 then Caption :='发送 成功' else Caption :='发送 失败'+IntToStr(nResult);
  cancel_send_program(play_list);
end;
procedure TForm1.Button6Click(Sender: TObject);
begin
end;
{ TSetDisplayModeThread }

constructor TSetDisplayModeThread.Create(ip, fname: string);
begin
  FreeOnTerminate := false;
  inherited Create(true);
  ffilename := fname;
  fip := ip;
end;

procedure TSetDisplayModeThread.Execute;

var
  play_list, program_, video_area: Cardinal;
  stay_time, display_effects, display_speed, x, y, transparency: integer;
  play_mode, play_week, play_time: integer;
  nResult: Cardinal;
  str,str1,bg_color: WideString;
  md5: string;
  // MemSteam: TMemoryStream;
  // MyMD5: TIdHashMessageDigest5;
	free_size,total_size:int64;

begin
  inherited;
  play_list := create_playlist(128, 96, $2158);
  str := 'program_1';
  bg_color := '0xffff0000';
  program_:=create_program(PWideChar(str),PWideChar(bg_color));
  video_area := create_video;
  str := ffilename;  
  str1 := '';
  md5 := 'avk';
  { MemSteam := TMemoryStream.Create;
    MemSteam.LoadFromFile(str);
    MyMD5 := TIdHashMessageDigest5.Create;
    md5 := MyMD5.HashStreamAsHex(MemSteam);
    MyMD5.Free;
    MemSteam.Free;
    Memo1.Text := md5; }
  add_video_unit(video_area,  2, 1, 0, 100, pchar(str),pchar(str1));
  add_video_md5(play_list, PWideChar(md5), pchar(str));
  str := '';
  add_video(program_, video_area, 0, 0, 128, 96, 0, 0,0,pchar(str),pchar(str));

  play_mode := 1;
  play_week := 15;
  play_time := 1;

  str := '';
  add_program_in_playlist(play_list,program_,play_mode,play_time,PWideChar(str),PWideChar(str),PWideChar(str),PWideChar(str), 127);

  str := 'guest';

  nResult := send_program(pansichar(PChar(fip)), 80, PWideChar(str),
    PWideChar(str), PWideChar(dir), play_list, 0,free_size, total_size);
  // if nResult = 0 then
  // Caption := '发送 成功'
  // else
  // Caption := '发送 失败' + IntToStr(nResult);
  cancel_send_program(play_list);
end;
procedure TForm1.Button7Click(Sender: TObject);
var
  play_list, program_, dynamic_area: Cardinal;
  gif_flag,dynamic_type,stay_time, display_effects, display_speed, x, y, transparency: integer;
  play_mode, play_week, play_time: integer;
  nResult: Cardinal;
  str, content, content1, content2, content3, font, color, font_attributes,
    bg_color, time_equation, positive_te,align_h,align_v: WideString;

  typed:Integer;
begin
  typed:=StrToInt(Edit3.Text);
  play_list := create_playlist(128, 96, typed);
  str := 'program_1';
  bg_color := '0xff000000';
  program_ := create_program(pchar(str),pchar(bg_color));
  dynamic_area := create_dynamic;

  stay_time := 1;
  dynamic_type := 0;
  display_effects := 1;
  display_speed := 16;
  content := '使用';
  content1 := '%Y年%m月%d日';
  content2 := '星期%w';
  content3 := '%H时%M分%S秒';
  font := 'SimSun';
  color := '0xffff0000';
  font_attributes := 'normal';
  bg_color := '0xff000000';
  time_equation := '00:00:00';
  positive_te := '+';
  align_h := '0';
  align_v := '0';
  gif_flag := 0;
  
  str := 'D:\a.bmp';
  nResult := add_dynamic_unit(dynamic_area, 0, display_effects, display_speed, stay_time, PWideChar(str),
   gif_flag, PWideChar(bg_color), 12, PWideChar(font), PWideChar(color), PWideChar(font_attributes), PWideChar(align_h),
    PWideChar(align_v), 0, 0, 0);
  //Console.WriteLine("add_dynamic_unit:" + err);
  str := '';
  nResult := add_dynamic(program_, dynamic_area, 0, 0, 0, 128, 96, -1, 0, PWideChar(str), 255);
  //Console.WriteLine("add_dynamic:" + err);
  delete_dynamic(dynamic_area);

  play_mode := 1;
  play_week := 15;
  play_time := 1;

  str := '';
  add_program_in_playlist(play_list, program_, play_mode, play_time, PWideChar(str),
    PWideChar(str), PWideChar(str), PWideChar(str), 127);
  str := 'guest';
  nResult := update_dynamic(pansichar(ansistring(Edit1.Text)), 80, PWideChar(str),
    PWideChar(str), play_list, -1,0,0);
  if nResult = 0 then
    Caption := '发送 成功'
  else
    Caption := '发送 失败' + IntToStr(nResult);
  cancel_send_program(play_list);
end;


end.
