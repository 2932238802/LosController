
#include"TopWidget.h"

namespace LosComponent {
	TopWidget::TopWidget(QWidget* parent):
		QWidget(parent)
	{
	}

	TopWidget::~TopWidget()
	{

	}


	/// <summary>
	/// 26_2_13
	/// - 带动整个界面的移动
	/// </summary>
	/// <param name="event"></param>
	void TopWidget::mouseMoveEvent(QMouseEvent* event)
	{
		if (event->buttons() & Qt::LeftButton)
		{
			//move(event->globalPos() - LOS_dragVec);
			this->window()->move(event->globalPos() - LOS_dragVec);
		}
		QWidget::mouseMoveEvent(event);
	}


	/// <summary>
	/// 26_2_13
	/// 鼠标的点击
	/// </summary>
	/// <param name="event"></param>
	void TopWidget::mousePressEvent(QMouseEvent* event)
	{
		if (event->button() == Qt::LeftButton)
		{
			LOS_dragVec = event->globalPos() - this->window()->pos();

		}
		QWidget::mousePressEvent(event);
	}

}