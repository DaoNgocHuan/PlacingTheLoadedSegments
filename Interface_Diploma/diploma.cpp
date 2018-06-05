#include "diploma.h"
#include <time.h>

Diploma::Diploma(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//increase = 0;
	d = 0;
	isEnable(false);
	addFormular();
	QObject::connect(ui.select, SIGNAL(clicked()),this,  SLOT(readData()));
	QObject::connect(ui.OFile, SIGNAL(clicked()),this,  SLOT(readFile()));
	QObject::connect(ui.SFile, SIGNAL(clicked()),this,  SLOT(SaveFile()));
	QObject::connect(ui.result, SIGNAL(clicked()),this,  SLOT(algorithm()));
	QObject::connect(ui.add, SIGNAL(clicked()),this,  SLOT(addRow()));
	QObject::connect(ui.del, SIGNAL(clicked()),this,  SLOT(deleteRow()));
	QObject::connect(ui.Des, SIGNAL(clicked()),this,  SLOT(describe()));
}

Diploma::~Diploma()
{

}

/*! 
* Включение или отключение компонентов интерфейса
*/
void Diploma:: isEnable(bool isE)
{
	ui.add->setEnabled(isE);
	ui.del->setEnabled(isE);
	ui.result->setEnabled(isE);
}

/*! 
* Добавить строку для таблицы
*/
void Diploma:: addRow()
{
	int nRow = ui.InputData->rowCount();
	ui.InputData->insertRow(nRow);
	QString hTitle = "A";
	hTitle ="A" + QString::number(nRow);
	QTableWidgetItem *item = new QTableWidgetItem(hTitle);
	ui.InputData->setItem(nRow, 0, item);
	QStringList labels1;
	labels1 << tr("");
	for(int  i = 0; i <= nRow ;i++)
	{
		labels1 << tr("");
	}
	ui.InputData->setVerticalHeaderLabels(labels1);
	ui.N->setValue(nRow);
}


/*! 
* Удалить строку для таблицы
*/
void Diploma::deleteRow()
{
	int nRow = ui.InputData->rowCount();
	if(nRow > 2)
	{
		ui.InputData->removeRow(nRow-1);
		ui.N->setValue(nRow - 2);
	}
	else
		ui.N->setValue(0);
}

/*!
* Читать данные
*/
void Diploma::readData()
{
	N = ui.N->value();
	c = ui.c->value();
	createTable(N);

	QList<QGraphicsItem*> all = ui.graph1->items();
	for (int i = 0; i < all.size(); i++)
	{
		QGraphicsItem *gi = all[i];
		if(gi->parentItem()==NULL) {
			delete gi;
		}
	}
	isEnable(true);
}

/*! 
* Создать данные
*/
void Diploma:: createTable(int N)
{
	int numberRow =  ui.InputData->rowCount();
	int numberColumn = ui.InputData->columnCount();
	for(int i = 0; i < numberRow; i++)
	{
		ui.InputData->removeRow(0);
	}
	for(int i = 0; i < numberColumn; i++)
	{
		ui.InputData->removeColumn(0);
	}
	QStringList labels1;
	labels1 << tr("");
	QStringList labels2;
	labels2 << tr("");

	
	QString hTitle = "A";
	for(int i = 0; i <= N; i++){
		ui.InputData->insertRow(i);
	}
	for(int i = 0; i <= 3 ; i++)
	{
		ui.InputData->insertColumn(i);
		ui.InputData->setColumnWidth(i,50);
	}
	for(int  i = 0; i <= N ;i++)
	{	
		labels1 << tr("");
		if(i != 0)
			hTitle ="A" + QString::number(i);
		QTableWidgetItem *item = new QTableWidgetItem(hTitle);
		ui.InputData->setItem(i, 0, item);
	}
	for(int  i = 0; i <= 3; i++)
	{
		labels2 << tr("");
	}
	insertNewColumn("a(A)",1);
	insertNewColumn("p(A)",2);
	insertNewColumn("b(A)",3);
	ui.InputData->setVerticalHeaderLabels(labels1);
	ui.InputData->setHorizontalHeaderLabels(labels2);
}

/*! 
* Вставить новый столбец
*\param[in] qstr - строка
*\param[in] pos - положение
*/
void Diploma:: insertNewColumn(QString qstr, int pos){
	QTableWidgetItem *item = new QTableWidgetItem(qstr);
	ui.InputData->setItem(0, pos, item);
}

/*! 
* Читать таблицу
*/
void Diploma:: readTable(){
	QTableWidgetItem *itab;
	at.resize(N);
	pt.resize(N);
	bt.resize(N);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= 3; j++){
			itab = ui.InputData->item(i,j);
			double numberDouble = itab->text().toDouble();
			if(j == 1)
				at[i-1] = numberDouble;
			else if(j == 2)
				pt[i-1] = numberDouble;
			else
				bt[i-1] = numberDouble;
		}
	}
}

/*! 
* Читать файл
*/
void Diploma:: readFile()
{

	QString fileName = QFileDialog::getOpenFileName(this,
					tr("Open File"), "", tr("Text File (*.txt)"));
	if (!fileName.isEmpty()){
		QFile file(fileName);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
			return;
		}
		QTextStream in(&file);
		int num;
		double db;
		in >> num;
		in >> db;
		ui.N->setValue(num);
		ui.c->setValue(db);
		createTable(num);
		
		for (int i = 0; i < num; i++)	{
			for(int j = 0; j < 3; j++){
				QTableWidgetItem * item = new QTableWidgetItem;
				in >> db;
				item->setText(QString::number(db));
				ui.InputData->setItem(i+1,j+1,item);
			}
		}
		isEnable(true);
	}
}

/*! 
* Получить длину отрезки
*/
void Diploma::getLengths()
{
	d = 0;
	lengths.clear();
	lengths.resize(N);
	for(int i = 0; i < N; i++){
		lengths[i] =  at[i] + bt[i];
		d+= lengths[i];
	}
}

/*! 
* Рисовать сегменты
*/
void Diploma :: DrawResult()
{

	
	QGraphicsScene *scene = new QGraphicsScene(ui.graph1);
	QPen pen(Qt::red);
	pen.setWidth(3);
	getLengths();
	QGraphicsTextItem* text;
	int x = 0, y = 0;
	text = scene->addText("The permutation w can be found by sorting by not increasing the number of specific weights of the segments:\n");
	text->setPos(x,y);
	x = 0 ; y = 40;
	for(int i = 0; i < N; i++)
	{
		text = scene->addText("gama"+QString::number(i+1)+ " = " + QString::number(gama[i]) + ";");
		text->setPos(x,y);
		x += 100; y = 40;
	}
	
	x = 0; y = 80;
	for( int k = 0; k <= IterationNumber; k++ )
	{
		text = scene->addText("K = "+ QString::number(k)+ ":", QFont("Arial", 10));
		text->setPos(x,y);
		y = y + 40;
		text = scene->addText("d(A) = "+ QString::number(d) + "  " + "a(A) = "+ QString::number(A[k]) + "  " + "DentaMin= :" + QString::number(distanceMin[k]) , QFont("Arial", 7));
		text->setPos(x,y);
		y+= 30;
		for(int j = 0; j < N; j++){
			scene->addRect(x,y,lengths[map[k][j]] * 3,20,pen);
			text = scene->addText("A"+QString::number(map[k][j] + 1), QFont("Arial", 7));
			text->setPos(x+(lengths[map[k][j]] * 3)/2 - 10, y);
			x += lengths[map[k][j]] * 3;
		}
		x = 0; y += 40;
	}
	text = scene->addText("Result:", QFont("Arial", 10));
	text->setPos(x,y);
	x = 0; y += 40;
	if(IterationNumber == 0)
	{
		for(int j = 0; j < N; j++){
			scene->addRect(x,y,lengths[map[0][j]] * 3,20,pen);
			text = scene->addText("A"+QString::number(map[0][j] + 1), QFont("Arial", 7));
			text->setPos(x+(lengths[map[0][j]] * 3)/2 - 10, y);
			x += lengths[map[0][j]] * 3;
		}
	}
	else
		for(int j = 0; j < N; j++){
			scene->addRect(x,y,lengths[map[IterationNumber + 1][j]] * 3,20,pen);
			text = scene->addText("A"+QString::number(map[IterationNumber + 1][j] + 1), QFont("Arial", 7));
			text->setPos(x+(lengths[map[IterationNumber + 1][j]] * 3)/2 - 10, y);
			x += lengths[map[IterationNumber + 1][j]] * 3;
		}
	
	ui.graph1->setScene(scene);
	if(checkError() == true)
	{
		if (scene != NULL) 
		{
			QList<QGraphicsItem*> L = scene->items();
			while (!L.empty())
				{
					delete L.first();
					L.removeFirst();
				}
		}
		QMessageBox msgBox;
		msgBox.setText("The Table is't correct!");
		msgBox.exec();
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("The number of iterations is :" + QString::number(IterationNumber));
		msgBox.exec();
	}
}


/*! 
* обратить матрицу
*\param[in] at - матрица
*\ return матрицу.
*/
QVector<double> Diploma:: reverseMatrices(QVector<double>at)
{
	QVector<double> ra;
	ra.resize(N);
	for(int i = 0; i < N; i++)
	{
		ra[i] = at[N - i - 1];
	}
	return ra;
}

/*!
* Найти наименьшее число
*\ [in] a - первое число
*\ param [in] b - второе число
*\ return наименьшее число
*/
double Diploma:: determineMin(double a, double b)
{
	double min = a;
	if(min > b)
		min = b;
	return min;
}

/*!
* Рассчитать расстояние от правого края сегмента до точки силы
*\ [in] a,b,p - входной массив
*\ return расстояние
*/
double Diploma:: caculateB(QVector<double> a, QVector<double> b, QVector<double> p)
{
	double total = 0;
	for(int i = 0; i < N; i++)
	{
		double sum = 0;
		for(int j = i + 1; j < N; j++){
			sum+= a[j] + b[j];
		}
		total+= p[i]*(b[i] + sum);
	}
	total = total / caculateP(p);
	return total;
}


/*!
* Рассчитать расстояния от левого края сегмента до точки силы
*\ [in] a,b,p - входной массив
*\ return расстояние
*/
double Diploma:: caculateA(QVector<double> a, QVector<double> b, QVector<double> p)
{
	double total = 0;
	for(int i = 1; i <= N; i++)
	{
		double sum = 0;
		for(int j = 1; j <= i - 1; j++){
			sum+= a[j-1] + b[j-1];
		}
		total+= p[i-1]*(a[i-1] + sum);
	}
	total = total / caculateP(p);
	return total;
}

/*!
*  Вычислить суммарную силу от компонентных сил
*\ [in] p - входной массив
*\ return суммарную силу
*/
double Diploma:: caculateP(QVector<double> p)
{
	double sum = 0;
	for(int i = 0; i < N; i++)
	{
		sum+= p[i];
	}
	return sum;
}

/*!
* Получить индекс наибольшего элемента в массиве
*\ param [in] arr - входной массив
*\ вернуть самый большой элемент в массиве
*/
int Diploma:: getIndex(QVector<double> arr)
{
	double max = arr[0];
	int index = 0;
	for(int i = 1; i < N; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}
	return index;
}

/*!
* Сортировка элементов в массиве не увеличивается
*\ param [in] arr - входной массив
*\ return array после отсортированных элементов в этом массиве.
*/
QVector<int> Diploma:: sequential(QVector<double> arr)
{
	QVector<int> indexs;
	indexs.resize(N);
	for(int i = 0; i < N; i++)
	{
		indexs[i] = getIndex(arr);
		arr[indexs[i]] = -1;
	}
	return indexs;
}

/*!
* Получить удельный вес
*/
void Diploma:: getSpecificWeight()
{
	gama.clear();
	gama.resize(N);
	for(int i = 0; i < N; i++)
	{
		gama[i] = pt[i]/lengths[i];
	}
}

/*!
* Рассчитать значение дента δ
*\ param [in] alphaK - двойной номер
*\ param [in] c - двойной номер
*\ return значение.
*/
double  Diploma:: calculateDeta(double alphaK, double c)
{
	double deta = fabs(alphaK - c);
	return deta;
}

/*!
* Добавьте несколько строк вместе
*\ param [in] arr - arr содержит строки
*\ param [in] isAw - существует Aw или не существует в строке
*\ param [in] is1 - существует Aw или не существует в строке
*\ param [in] isA - существует A или не существует в строке
*\ вернуть строку.
*/
template <typename T>
void Diploma:: addString(QVector<T> arr, int isAw, int is1, int isA)
{
	if(isAw)
	{
		string += "Aw=(";
	}
	if(is1 && isA)
	{
		for(int i = 0; i < N; i++)
		{
			string += "A" + QString::number(arr[i]+1);
		}
		string +=")\n";
	}
	if(!is1 && !isA){
		string += "a=(";
		for(int i = 0; i < N; i++)
		{
			string += QString::number(arr[i]) + " ";
		}
		string +=")\n";
	}
	if(is1 && !isA){
		string += "w=("; 
		for(int i = 0; i < N; i++)
		{
			string += QString::number(arr[i] + 1) + " ";
		}
		string +=")\n";
	}
}

/*!
* Изменить положение элементов в массиве
*\ param [in] arr - входной массив
*\ param [in] position - положение элементов в массиве
*\ return массив после изменения
*/
template <typename T>
QVector <T> Diploma:: swap(QVector <T> arr, int position)
{
	T tmp;
	tmp = arr[position];
	arr[position] = arr[position + 1];
	arr[position + 1] = tmp;
	return arr;
}

/*!
* Проверить любой ячейки в таблице пуста
*\ return true если пуст, otherwise false 
*/
bool Diploma::checkError()
{
	int numberRow =  ui.InputData->rowCount();
	QTableWidgetItem *itab;
	for(int i = 1; i <= numberRow-1; i++){
		for(int j = 1; j <= 3; j++){
			itab = ui.InputData->item(i,j);
			double val = itab->text().toDouble();
			//qDebug() << itab->text();
			
			if(itab == 0 || val <= 0)
			{
				return true;
			}
		}
	}
	return false;
}

/*!
* Выполнить алгоритм
*/
void Diploma:: algorithm()
{
	clock_t start = clock();
		N = ui.N->value();
		c = ui.c->value();
		readTable();
		string.clear();
		map.clear();
		qDebug()<<map.size();
		double alpha,beta;
		string +="The permutation w can be found by sorting by not increasing the number of specific weights of the segments:\n";
		
		getLengths();
		getSpecificWeight();
		for(int i = 0; i < N; i++)
		{
			string +="gama"+QString::number(i+1)+ " = " + QString::number(gama[i]) + "  ";
		}
		string +="\n";
		QVector<int> indexs;
		indexs.resize(N);
		indexs = sequential(gama);
		map.insert(0,indexs);
		addString(indexs,0,1,0);
		QVector<double> a1, b1, p1, gama1;
		a1.resize(N);
		b1.resize(N);
		p1.resize(N);
		gama1.resize(N);
		for(int i = 0; i < N; i ++)
		{
			a1[i] = at[indexs[i]];
			p1[i] = pt[indexs[i]];
			b1[i] = bt[indexs[i]];
		}
		QVector<double> ra, rb, rp;
		ra = reverseMatrices(a1);
		rb = reverseMatrices(b1);
		rp = reverseMatrices(p1);
		alpha = caculateA(a1,b1,p1);
		beta = caculateA(ra,rb,rp);
		int k = 0;
		A.resize(100);
		A[k] = alpha;
		distanceMin.resize(100);
		if(alpha >= c || beta <= c)
		{ 
			string+= "\nResult:\n";
			addString(indexs,1,1,1);
			IterationNumber = 0;
			distanceMin[0] = abs(c-alpha);
			DrawResult();
			return;
		}
		double alphaK = alpha;
		double deltaMin = calculateDeta(alphaK,c);
		distanceMin[k] = deltaMin;
		string+="k: " + QString::number(k) + "\n" + "alphak: " + QString::number(alphaK)+ "\n" + "deltaMin: " + QString::number(deltaMin) + "\n";
		addString(a1, 0,0,0);
		addString(indexs, 0,1,0);
		if(c > alpha && c < beta)
		{
			int count = 0;
			while(alphaK < c)
			{
				double tmpA = a1[k];
				double tmpP = p1[k];
				double tmpB = b1[k];
				a1 = swap(a1,k);
				p1 = swap(p1,k);
				b1 = swap(b1,k);
				count++;
				string+= "k: " + QString::number(count) + "\n ";
				alphaK = caculateA(a1,b1,p1);
				A[count] = alphaK;
				if(alphaK < c)
				{
					string+= "alphak: " + QString::number(alphaK) + "\n ";
					deltaMin = calculateDeta(alphaK,c);
					distanceMin[count] = deltaMin;
					string+= "deltaMin: " + QString::number(deltaMin) + "\n ";
					addString(a1,0,0,0);
					indexs = swap(indexs,k);
					map.insert(count,indexs);
					addString(indexs,0,1,0);
					k++;
					if(k == N - 1)
						k = 0;
					
				}
			}
			IterationNumber = count;
			if(alphaK == c)
			{

				string+= "alphak: " + QString::number(alphaK) + "\n ";
				deltaMin = calculateDeta(alphaK,c);
				distanceMin[IterationNumber] = deltaMin;
				string+= "deltaMin: " + QString::number(deltaMin) + "\n ";
				addString(a1,0,0,0);
				string+= "\nResult:\n";
				addString(indexs,1,1,1);
				map.insert(IterationNumber + 1,indexs);
			}
			if(alphaK > c)
			{
			
				double otherDeta;
				otherDeta = calculateDeta(c,alphaK);
				distanceMin[IterationNumber] = otherDeta;
				string+= "alphak: " + QString::number(alphaK) + "\n ";
				deltaMin = determineMin(deltaMin, otherDeta);
				string+= "deltaMin: " + QString::number(otherDeta) + "\n ";
				indexs = swap(indexs, k);
				map.insert(count,indexs);
				addString(a1,0,0,0);
				addString(indexs,0,1,0);
				if(deltaMin == otherDeta)
				{
					string+= "\nResult:\n";
					addString(indexs,1,1,1);
					map.insert(IterationNumber + 1,indexs);
				}else
				{
					
					if(k == 0)
					{
						indexs = swap(indexs, k);
						map.insert(IterationNumber + 1,indexs);
						string+= "\nResult:\n";
						addString(indexs,1,1,1);
					}else
					{
						indexs = swap(indexs, k-1);
						map.insert(IterationNumber + 1,indexs);
						string+= "\nResult:\n";
						addString(indexs,1,1,1);
					}

				}

			}
		}
	/*QMessageBox msgBox;
	msgBox.setText("Time: \n"+ QString::number( (double)(clock() - start)/CLOCKS_PER_SEC));
	msgBox.exec();*/
	DrawResult();
}

/*!
* Сохранить результаты в файл
*/
void Diploma:: SaveFile(){
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"",tr(".txt"));
	if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }
		QTextStream out(&file);
		out.setCodec("UTF-8");
		out << string;
		out.flush();
		QMessageBox msgBox;
		msgBox.setText("Succesful!");
		msgBox.exec();
		file.close();
    }
}

/*!
* Добавлять формулы
*/
void Diploma :: addFormular()
{
	QPixmap pix("formulas.PNG");
	pix.scaledToHeight(10, Qt::SmoothTransformation);
    pix.scaledToWidth(5, Qt::SmoothTransformation);
	ui.formulas->setPixmap(pix);
	ui.formulas->setMask(pix.mask());
}

/*!
* Описание проблемы
*/
void Diploma :: describe()
{
	QGraphicsScene *scene = new QGraphicsScene(ui.DesInput);
	QPen pen(Qt::red);
	pen.setWidth(3);
	QPen pen2(Qt::black);
	pen2.setWidth(1);

	QGraphicsTextItem* text;

	text = scene->addText("Describe a segment A1:", QFont("Arial", 10));
	text->setPos(0,-50);
	scene->addRect(0,0,150,20,pen);
	scene->addEllipse(49,7,3,3,pen); 
	scene->addLine(50,10,50,35,pen2);
	scene->addLine(45,30,50,35,pen2);
	scene->addLine(55,30,50,35,pen2);
	text = scene->addText("P", QFont("Arial", 7));
	text->setPos(50,35);

	scene->addLine(0,-15,50,-15,pen2);
	scene->addLine(5,-20,0,-15,pen2);
	scene->addLine(5,-10,0,-15,pen2);
	scene->addLine(45,-20,50,-15,pen2);
	scene->addLine(45,-10,50,-15,pen2);

	text = scene->addText("a", QFont("Arial", 7));
	text->setPos(25,-20);

	scene->addLine(50,-15,150,-15,pen2);
	scene->addLine(55,-20,50,-15,pen2);
	scene->addLine(55,-10,50,-15,pen2);
	scene->addLine(145,-20,150,-15,pen2);
	scene->addLine(145,-10,150,-15,pen2);
	text = scene->addText("b", QFont("Arial", 7));
	text->setPos(100,-20);

	text = scene->addText("Example initial state when placing segments together to form A:", QFont("Arial", 10));
	text->setPos(0,50);
	int x = 0, y = 80;
	int l[5] = {7,10,5,15,20};
	for(int j = 0; j < 5; j++){
		scene->addRect(x,y, l[j] * 3,20,pen);
		text = scene->addText("A"+QString::number(j + 1), QFont("Arial", 7));
		text->setPos(x+(l[j] * 3)/2 - 10, y);
		x += l[j] * 3;
	}

	text = scene->addText("Solve the problem:", QFont("Arial", 10));
	text->setPos(0,110);
	text = scene->addText("Input", QFont("Arial", 10));
	text->setPos(0,130);
	x = 0; y = 180;
	scene->addRect(x,y,150,20,pen);
	scene->addEllipse(49,y+7,3,3,pen); 
	scene->addLine(50,y+10,50,y+40,pen2);
	scene->addLine(45,y+35,50,y+40,pen2);
	scene->addLine(55,y+35,50,y+40,pen2);
	text = scene->addText("P", QFont("Arial", 7));
	text->setPos(50,y+40);

	scene->addLine(0,y-15,50,y-15,pen2);
	scene->addLine(5,y-20,0,y-15,pen2);
	scene->addLine(5,y-10,0,y-15,pen2);
	scene->addLine(45,y-20,50,y-15,pen2);
	scene->addLine(45,y-10,50,y-15,pen2);
	text = scene->addText("a(alpha)", QFont("Arial", 7));
	text->setPos(25,y-20);

	scene->addLine(50,y-15,150,y-15,pen2);
	scene->addLine(55,y-20,50,y-15,pen2);
	scene->addLine(55,y-10,50,y-15,pen2);
	scene->addLine(145,y-20,150,y-15,pen2);
	scene->addLine(145,y-10,150,y-15,pen2);
	text = scene->addText("b(alpha)", QFont("Arial", 7));
	text->setPos(100,y-20);

	scene->addLine(0,y+30,70,y+30,pen2);
	scene->addLine(5,y+35,0,y+30,pen2);
	scene->addLine(5,y+25,0,y+30,pen2);
	scene->addLine(65,y+35,70,y+30,pen2);
	scene->addLine(65,y+25,70,y+30,pen2);
	text = scene->addText("c", QFont("Arial", 7));
	text->setPos(35,y+30);


	text = scene->addText("purpose:", QFont("Arial", 10));
	text->setPos(0,230);
	x = 0; y = 280;

	scene->addRect(x,y,150,20,pen);
	scene->addEllipse(79,y+7,3,3,pen); 
	scene->addLine(80,y+10,80,y+40,pen2);
	scene->addLine(75,y+35,80,y+40,pen2);
	scene->addLine(85,y+35,80,y+40,pen2);
	text = scene->addText("P", QFont("Arial", 7));
	text->setPos(80,y+40);

	scene->addLine(0,y-15,80,y-15,pen2);
	scene->addLine(5,y-20,0,y-15,pen2);
	scene->addLine(5,y-10,0,y-15,pen2);
	scene->addLine(75,y-20,80,y-15,pen2);
	scene->addLine(75,y-10,80,y-15,pen2);
	text = scene->addText("a(alpha)", QFont("Arial", 7));
	text->setPos(25,y-20);

	scene->addLine(80,y-15,150,y-15,pen2);
	scene->addLine(85,y-20,80,y-15,pen2);
	scene->addLine(85,y-10,80,y-15,pen2);
	scene->addLine(145,y-20,150,y-15,pen2);
	scene->addLine(145,y-10,150,y-15,pen2);
	text = scene->addText("b(alpha)", QFont("Arial", 7));
	text->setPos(100,y-20);

	
	scene->addLine(70,y+30,80,y+30,pen2);
	scene->addLine(73,y+33,70,y+30,pen2);
	scene->addLine(73,y+27,70,y+30,pen2);
	scene->addLine(77,y+33,80,y+30,pen2);
	scene->addLine(77,y+27,80,y+30,pen2);
	text = scene->addText("min?", QFont("Arial", 7));
	text->setPos(65,y+15);


	scene->addLine(0,y+30,70,y+30,pen2);
	scene->addLine(5,y+35,0,y+30,pen2);
	scene->addLine(5,y+25,0,y+30,pen2);
	scene->addLine(65,y+35,70,y+30,pen2);
	scene->addLine(65,y+25,70,y+30,pen2);
	text = scene->addText("c", QFont("Arial", 7));
	text->setPos(35,y+30);

	ui.DesInput->setScene(scene);
	ui.Des->setEnabled(false);
}