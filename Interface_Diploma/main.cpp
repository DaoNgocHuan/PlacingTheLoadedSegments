#include "interface_diploma.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Interface_Diploma w;
	w.show();
	return a.exec();
}
