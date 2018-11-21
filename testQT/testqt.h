#ifndef TESTQT_H
#define TESTQT_H

#include <QtWidgets/QMainWindow>
#include "ui_testqt.h"


class testQT : public QMainWindow
{
	Q_OBJECT


public:
	testQT(QWidget *parent = 0);
	~testQT();

protected:
	void keyPressEvent(QKeyEvent *);




protected:
	bool myInRange(int low, int high, int x);

private:
	Ui::testQTClass ui;
	private slots:
    void testClick();

/*protected:
	void keyPressEvent(QKeyEvent *event) @override
	{
		if (event->key() == Qt::Key_R)
		{
			this->label->setText("Rymatouuuuun");
		}
	}*/
};

#endif // TESTQT_H
