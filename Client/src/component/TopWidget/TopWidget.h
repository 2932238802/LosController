
#pragma once
#include <QObject>
#include <QWidget>
#include <QMouseEvent>


namespace LosComponent {

class TopWidget : public QWidget {
	Q_OBJECT
public:
	explicit TopWidget(QWidget* parent = nullptr);
	~TopWidget();
	void mouseMoveEvent(QMouseEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;

private:
	QPoint LOS_dragVec;

};
}
