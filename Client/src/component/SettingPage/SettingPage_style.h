#pragma once
#include <QString>

namespace SettingsPageStyle {
    const QString style = R"(
        QWidget#SettingsPage {
            background-color: #1A1A1A;
            color: #FFFFFF;
            font-family: "Consolas", "Monospace";
        }

        QListWidget#navBar {
            background-color: #111111;
            border: none;
            border-right: 1px solid #2A2A2A;
            outline: none;
        }

        QListWidget#navBar::item {
            padding: 15px 25px;
            color: #888888;
            font-size: 14px;
            border-left: 4px solid transparent;
        }

        QListWidget#navBar::item:hover {
            background-color: #1A1A1A;
            color: #CCCCCC;
        }

        QListWidget#navBar::item:selected {
            background-color: #1A1A1A;
            color: #00FF99;
            border-left: 4px solid #00FF99;
        }

        QWidget#contentArea {
            background-color: #1A1A1A;
        }

        QLabel#lblTitle {
            font-size: 18px;
            font-weight: bold;
            color: #FFFFFF;
            letter-spacing: 1px;
            margin-bottom: 20px;
            text-transform: uppercase;
        }

        QLabel.field-label {
            color: #AAAAAA;
            font-size: 13px;
            min-width: 150px;
        }

        QLineEdit, QComboBox {
            background-color: #111111;
            border: 1px solid #333333;
            border-radius: 2px;
            padding: 8px 12px;
            color: #FFFFFF;
            font-size: 13px;
        }

        QLineEdit:focus, QComboBox:hover {
            border: 1px solid #555555;
        }

        QComboBox::drop-down {
            border: none;
            width: 30px;
        }

        QComboBox::down-arrow {
            image: none;
            border-left: 5px solid transparent;
            border-right: 5px solid transparent;
            border-top: 5px solid #888888;
            margin-right: 10px;
        }

        QCheckBox {
            spacing: 0px;
        }

        QCheckBox::indicator {
            width: 20px;
            height: 20px;
            border-radius: 2px;
            border: 1px solid #333333;
            background-color: #111111;
        }

        QCheckBox::indicator:checked {
            background-color: #00FF99;
            border: 1px solid #00FF99;
        }

        QPushButton#btnSave {
            background-color: #00FF99;
            color: #000000;
            border: none;
            border-radius: 2px;
            padding: 12px;
            font-size: 13px;
            font-weight: bold;
            text-transform: uppercase;
            margin-top: 30px;
        }

        QPushButton#btnSave:hover {
            background-color: #33FFAA;
        }

        QPushButton#btnSave:pressed {
            background-color: #00CC7A;
        }
    )";
}
