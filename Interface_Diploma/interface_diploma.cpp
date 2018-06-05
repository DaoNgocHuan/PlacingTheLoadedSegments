#include "interface_diploma.h"

Interface_Diploma::Interface_Diploma(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	QPixmap pix("boeing-737.jpg");
	pix.scaled(QSize(16,10),  Qt::KeepAspectRatio);
	ui.label_3->setPixmap(pix);
	ui.lineEdit_2->setEchoMode(QLineEdit::Password);
	QObject::connect(ui.pushButton, SIGNAL(clicked()),this,  SLOT(login()));
}

Interface_Diploma::~Interface_Diploma()
{

}

/*! 
* Login to program
*/
void Interface_Diploma :: login()
{
	QString username = ui.lineEdit->text();
	QString password = ui.lineEdit_2->text();
	if(username == "1" && password == "1"){
		QMessageBox::information(this,"Login","Username and password is correct");
		this->hide();
		Diploma d;
		d.show();
		d.exec();
	}
	else{
		QMessageBox::information(this,"Login","Username and password is not correct");
	}
}
