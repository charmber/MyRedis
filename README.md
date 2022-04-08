### MyRedis实现

### 目录介绍
---DataStruct
    ---存放基本键值数据结构
---ParseChar
    ---解析命令以及字符串相关
---Persistence
    ---持久化操作
---public
    ---公共全局数据区域
---ServerCommun
    ---通信服务
---System
    ---获取系统参数相关

目前支持string以及set两种数据类型
支持数据AOF持久化操作
支持内存淘汰策略，可以根据当前缓存使用达到某一个阀值启动内存淘汰，或者达到系统内存的某一个预警阀值进行内存淘汰
