#ifndef INTERFACE_DIPLOMA_H
#define INTERFACE_DIPLOMA_H

#include <QtGui/QMainWindow>
#include "ui_interface_diploma.h"
#include "diploma.h"
#include "QString"
#include "QMessageBox"
#include "QPixmap"
class Interface_Diploma : public QMainWindow
{
	Q_OBJECT

public:
	Interface_Diploma(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Interface_Diploma();

private:
	Ui::Interface_DiplomaClass ui;
	private slots:
		void login();
};

#endif // INTERFACE_DIPLOMA_H
