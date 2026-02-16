LosController/
├── CMakeLists.txt                # 顶层构建文件，统筹全局
├── common/                       # 【公共库】前后端通用的工具
│   ├── include/
│   │   ├── Protocol.h            # 极其重要：定义数据包头结构
│   │   └── Logger.h              # 通用的日志打印
│   └── src/
├── protocol/                     # 【协议层】
│   └── remote_msg.proto          # (进阶推荐) 如果用Protobuf定义消息
├── server/                       # 【后端】Linux 被控端程序
│   ├── CMakeLists.txt
│   ├── include/
│   │   ├── ScreenGrabber.h       # 屏幕采集接口
│   │   ├── ImageCompressor.h     # 图像压缩逻辑
│   │   └── TcpServer.h           # 网络发送逻辑
│   └── src/
│       ├── main.cpp              # 服务端入口
│       ├── ScreenGrabberX11.cpp  # X11具体实现
│       └── ...
├── client/                       # 【前端】Qt 控制端程序
│   ├── CMakeLists.txt
│   ├── src/
│   │   ├── main.cpp
│   │   ├── MainWindow.cpp
│   │   ├── NetworkManager.cpp    # 核心：负责TCP连接与粘包处理
│   │   └── component/            # 存放你之前生成的Page
│   │       ├── InitPage/
│   │       └── DashboardPage/    # 核心：负责渲染接收到的画面
│   ├── ui/                       # .ui 文件存放处
│   └── resources/                # 图标、样式
└── third_party/                  # 第三方库 (libjpeg-turbo, protobuf)
