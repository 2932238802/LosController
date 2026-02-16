#pragma once
#include <QString>

namespace MainWindowStyle {
    const QString style = R"(
        QWidget#MainWindow {
            background-color: #050505;
            color: #FFFFFF;
            font-family: "Consolas", "Monospace";
        }

        QWidget#widgetTop {
            background-color: #0A0A0A;
            border-bottom: 1px solid #222222;
        }

        QLabel#lblLogo {
            color: #00FF99;
            font-size: 18px;
            font-weight: bold;
            letter-spacing: 2px;
            padding-left: 20px;
        }

        QPushButton.nav-item {
            background-color: transparent;
            color: #888888;
            border: none;
            font-size: 13px;
            font-weight: bold;
            text-transform: uppercase;
            padding: 0 20px;
            border-bottom: 3px solid transparent;
        }

        QPushButton.nav-item:hover {
            color: #FFFFFF;
            background-color: #111111;
        }

        QPushButton.nav-item:checked {
            color: #00FF99;
            border-bottom: 3px solid #00FF99;
            background-color: #151515;
        }

        QWidget#widgetWindowControls QPushButton {
            background-color: transparent;
            border: none;
            color: #555555;
            font-size: 16px;
            width: 40px;
        }

        QWidget#widgetWindowControls QPushButton:hover {
            color: #FFFFFF;
            background-color: #222222;
        }

        QPushButton#btnClose:hover {
            background-color: #E81123;
        }

        QWidget#widgetBottom {
            background-color: transparent;
        }

        QStackedWidget {
            background-color: transparent;
        }
    )";
}
