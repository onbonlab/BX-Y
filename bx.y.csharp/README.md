# BX-Y CSharp SDK
本项目为仰邦科技 BX-Y 系列的 CSharp 实现，调用仰邦封装的动态库文件，任何人都可直接在此代码上进行添加与修改。

本项目由Visual Stuio 2010编写， 本 demo 中提供了 TCP 模式的简单使用方式。

* 代码

  https://github.com/onbonlab/bx.k.delphi/blob/master/src/MainFrm.pas

* 可执行程序

  https://github.com/onbonlab/bx.k.delphi/releases



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

```
init_sdk();
```

**步骤2：**

编辑节目，动态区

**步骤3：**

更新节目，动态区

**步骤4：**

释放动态库

```
release_sdk();
```

## 使用例程

```
//初始化动态库
init_sdk();
            byte[] ip = Encoding.ASCII.GetBytes("192.168.89.3");
            int port = 80;
            string str = "guest";
            int err = 0;
            //清除显示屏所有节目
            LedYNetSdk.clear_all_program(ip, (ushort)port, str, str);
            //清除显示所有动态区
            LedYNetSdk.clear_dynamic(ip, (ushort)port, str, str);
            
            IntPtr playlist = LedYNetSdk.create_playlist(192, 64, 8536);
                string name = "program_0";
                IntPtr program = LedYNetSdk.create_program(name, "0xff000000");
                //图片
                IntPtr pic_area = LedYNetSdk.create_pic();
                string file = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase + "0_0_1.png";
                int err = LedYNetSdk.add_pic_unit(pic_area, 5, 5, 10, file);
                 file = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase + "0_0_0.png";
                 err = LedYNetSdk.add_pic_unit(pic_area, 5, 5, 10, file);
                Console.WriteLine("add_pic_unit:" + err);
                err = LedYNetSdk.add_pic(program, pic_area, 0, 0, 192, 64, 100);
                Console.WriteLine("add_pic:" + err);

                string m_aging_start_time = "";
                string m_aging_stop_time = "";
                string m_period_ontime = "";
                string m_period_offtime = "";
                err = LedYNetSdk.add_program_in_playlist(playlist, program, 1, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);
                Console.WriteLine("add_program_in_playlist:" + err);

                int send_style = 0;
                var szLocalTempDir = "F:\\Temp\\";
                long free_size = 0; long total_size = 0;
                err = LedYNetSdk.send_program(ip, port, str, str, szLocalTempDir, playlist, send_style, ref free_size, ref total_size);
                Console.WriteLine("send_program:" + err);

                LedYNetSdk.cancel_send_program(playlist);
                LedYNetSdk.delete_playlist(playlist);

//释放动态库
release_sdk();
```

