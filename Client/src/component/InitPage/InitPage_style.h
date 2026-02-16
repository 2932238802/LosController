#pragma once
#include <QString>

namespace InitPageStyle {
    const QString style = R"(
        QMainWindow, QWidget#centralwidget {
            background-color: #1A1A1A; /* 深色背景 */
            font-family: "Consolas", "Courier New", monospace; /* 类似截图的等宽/技术风格字体 */
            color: #E0E0E0;
        }

        /* 顶部大标题 */
        QLabel#lblTitle {
            font-size: 24px;
            font-weight: bold;
            color: #FFFFFF;
            letter-spacing: 2px;
            padding-bottom: 10px;
            border-bottom: 2px solid #333333; /* 标题下方的装饰线 */
        }

        /* 中心卡片容器 */
        QFrame#loginCard {
            background-color: #252525; /* 比背景稍浅 */
            border: 1px solid #333333;
            border-radius: 4px;
        }

        /* 输入框上方的标签 (IP, PORT...) */
        QLabel.input-label {
            font-size: 12px;
            color: #AAAAAA;
            font-weight: bold;
            text-transform: uppercase; /* 强制大写 */
            margin-bottom: 5px;
            margin-top: 15px;
        }

        /* 输入框样式 */
        QLineEdit {
            background-color: #111111; /* 深黑背景 */
            border: 1px solid #333333;
            border-radius: 2px;
            padding: 10px;
            font-size: 14px;
            color: #888888; /* 占位符颜色/文字颜色 */
            selection-background-color: #00FF99;
            selection-color: #000000;
        }

        QLineEdit:focus {
            border: 1px solid #555555;
            color: #FFFFFF;
        }

        /* 连接按钮 */
        QPushButton#btnConnect {
            background-color: #00FF99; /* 亮绿色 */
            color: #000000;
            border: none;
            border-radius: 2px;
            padding: 12px;
            font-size: 14px;
            font-weight: bold;
            text-transform: uppercase;
            margin-top: 20px;
        }

        QPushButton#btnConnect:hover {
            background-color: #33FFAA;
        }

        QPushButton#btnConnect:pressed {
            background-color: #00CC7A;
        }

        /* 底部状态栏 */
        QLabel#lblStatus {
            background-color: #2A1A1A; /* 暗红色背景 */
            color: #FF5555; /* 红色文字 */
            padding: 8px 20px;
            font-size: 12px;
            border: 1px solid #3A1A1A;
        }
    )";
}
