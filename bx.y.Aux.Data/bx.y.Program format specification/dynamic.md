# 3.3    动态区节目

​	动态区节目是暂存到内存中，不会存储到本地介质，掉电不保存。动态区分可以作为全局节目独立播放，也可以关联普通节目进行播放。动态区始终显示在所有节目的上层，不影响其他节目的播放。可以通过设置动态区的透明度来兼顾其他节目。

-  作为全局节目（未关联节目）时，动态区会立即播放

-  关联节目播放时，动态区的播放时效会依赖或者从属于所关联的节目。

-  动态区时效性：未关联节目的动态区为全局动态区，时效性始终有效。关联节目的动态区，时效性是以所关联的节目的时效性为准。只有在时效范围内的动态区才可以播放。

-  若保存了动态区文件，则控制器重新启动会自动根据关联关系和时效性播放已保存的动态区。

   动态区节目的播放使用"动态区更新"命令，而停止动态区使用"清除动态区"命令。

 

**动态区节目不建议以xml的格式下发，本文也不描述xml文件的具体格式。需要下发动态区节目，请使用通信协议中动态区管理类指令**