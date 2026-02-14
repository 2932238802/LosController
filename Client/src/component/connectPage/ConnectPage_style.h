#pragma once
#include <QString>

namespace ConnectPageStyle {
    const QString style = R"(
        QWidget#DashboardPage {
            background-color: #050505;
            color: #E0E0E0;
            font-family: "Consolas", "Monospace";
        }

        QFrame#videoSurface {
            background-color: #000000;
            border: 2px solid #1A1A1A;
        }

        QLabel#lblStreamPlaceholder {
            color: #333333;
            font-size: 18px;
        }

        QFrame#sidebar {
            background-color: #0A0A0A;
            border-left: 1px solid #222222;
            min-width: 280px;
            max-width: 280px;
        }

        QFrame.card {
            background-color: #111111;
            border: 1px solid #222222;
            margin-bottom: 15px;
        }

        QLabel.card-title {
            color: #00FF99;
            font-weight: bold;
            font-size: 13px;
            letter-spacing: 1px;
            text-transform: uppercase;
            padding: 10px;
        }

        QLabel.info-key {
            color: #888888;
            font-size: 12px;
        }

        QLabel.info-value {
            color: #00FF99;
            font-weight: bold;
            font-size: 12px;
        }

        QPushButton.action-btn {
            background-color: #1A1A1A;
            color: #FFFFFF;
            border: 1px solid #333333;
            padding: 12px;
            text-align: center;
            font-size: 13px;
        }

        QPushButton.action-btn:hover {
            background-color: #252525;
            border-color: #444444;
        }

        QPushButton.action-btn:pressed {
            background-color: #000000;
        }

        QPushButton#btnDisconnect {
            background-color: #1A1212;
            color: #FF4444;
            border: 1px solid #442222;
            font-weight: bold;
            text-transform: uppercase;
        }

        QPushButton#btnDisconnect:hover {
            background-color: #FF4444;
            color: #000000;
        }

        QScrollArea {
            border: none;
            background-color: transparent;
        }

        QScrollBar:vertical {
            background: #050505;
            width: 8px;
        }

        QScrollBar::handle:vertical {
            background: #222222;
            border-radius: 4px;
        }
    )";
}
