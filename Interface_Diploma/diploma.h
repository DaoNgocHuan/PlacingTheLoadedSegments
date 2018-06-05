#ifndef DIPLOMA_H
#define DIPLOMA_H

#include <QDialog>
#include "ui_diploma.h"
#include "Qstring"
#include "QMessageBox"
#include "QFileDialog"
#include "QTextStream"
#include "QVector"
#include "QGraphicsScene"
#include "QPen"
#include "QGraphicsTextItem"
#include "QDebug"
#include "QBitmap"
class Diploma : public QDialog
{
	Q_OBJECT

public:
	Diploma(QWidget *parent = 0);
	~Diploma();

private:
	Ui::Diploma ui;
	int N; // количество отрезков
	int IterationNumber; // количество итераций
	double c; // которое число
	int increase; // Показать оповещения
	QString string; // чтобы, написать в файл
	QVector<double> at; // длина от левого края до точки силы 
	QVector<double> bt; // длина от правого края до точки силы
	QVector<double> pt; // силы
	QVector<double> lengths; // длина отрезки
	QVector<double> gama; // Удельным весом отрезка 
	QMap<int,QVector<int>> map; // сохранить процесс сортировки отрезки
	QVector<double> A, distanceMin;
	double d;

	// 
	void insertNewColumn(QString qstr, int pos);
	void readTable();
	void createTable(int N);
	void getLengths();
	void getSpecificWeight();
	void DrawResult();
	bool checkError();
	void isEnable(bool isE);

	QVector<double> reverseMatrices(QVector<double>at);
	double determineMin(double a, double b);
	double caculateB(QVector<double> a, QVector<double> b, QVector<double> p);
	double caculateA(QVector<double> a, QVector<double> b, QVector<double> p);
	double caculateP(QVector<double> p);
	int getIndex(QVector<double> arr);
	QVector<int> sequential(QVector<double> arr);
	double calculateDeta(double alphaK, double c);
	template <typename T>
	void addString(QVector<T> arr, int isAw, int is1, int isA);
	template <typename T>
	QVector <T> swap(QVector <T> arr, int position);
	void addFormular();
private slots:
	void readData();
	void readFile();
	void SaveFile();
	void algorithm();
	void addRow();
	void deleteRow();
	void describe();
	
};

#endif // DIPLOMA_H
