# 1.  协议概述

​	《异步全彩二代通信协议》（后简称《二代协议》）是上位机软件实现和BX-Y系列控制卡通信的指导性文档。

​	异步全彩二代协议以类json-rpc的远程调用协议为核心，并以HTTP、UDP等多种协议代理为接口共同组成。《二代协议》中描述了UDP和HTTP两种协议代理方式，这两种方式的使用侧重点是不同的。

​	UDP代理主要使用在异步全彩控制卡（后简称控制卡）设置初期，用于网络相关设置。UDP代理在“UDP通信指令”章节中具体阐述。一旦网络设置完成后，则主要使用HTTP代理通信：设置屏幕参数、设置扫描参数、发送节目等等。HTTP代理在“HTTP通信指令” 章节中具体阐述。