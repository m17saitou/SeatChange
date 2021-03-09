#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent) {
        studentNum = new QLineEdit("0",nullptr);
        columnSeat = new QLineEdit("0",nullptr);
        rowSeat = new QLineEdit("0",nullptr);
        stuNum = new QLabel("Students Num :");
        seatCol = new QLabel("Column :");
        seatRow = new QLabel("Row :");
        seatView = new QTableWidget(1,1,this);
        createNewSeat = new QPushButton("Create New Seat");
        exportCSV = new QPushButton("Export CSV file");
        importCSV = new QPushButton("Import Old Seat file");
        setSeatOption = new QRadioButton("Not duplicate");
        
        QHBoxLayout *topNumBar = new QHBoxLayout();
        topNumBar->addWidget(stuNum);
        topNumBar->addWidget(studentNum);
        topNumBar->addWidget(seatCol);
        topNumBar->addWidget(columnSeat);
        topNumBar->addWidget(seatRow);
        topNumBar->addWidget(rowSeat);
        QVBoxLayout *leftSide = new QVBoxLayout();
        leftSide->addLayout(topNumBar);
        leftSide->addWidget(seatView);

        QVBoxLayout *rightSide = new QVBoxLayout();
        rightSide->addWidget(createNewSeat);
        rightSide->addWidget(exportCSV);
        rightSide->addWidget(importCSV);
        rightSide->addWidget(setSeatOption);

        QHBoxLayout *mainLayout = new QHBoxLayout();
        mainLayout->addLayout(leftSide);
        mainLayout->addLayout(rightSide);

        QWidget *windowWidget = new QWidget();
        windowWidget ->setLayout(mainLayout);
        setCentralWidget(windowWidget);
        connect(createNewSeat,SIGNAL(clicked()),this,SLOT(createNew()));
        connect(importCSV,SIGNAL(clicked()),this,SLOT(importCSVFile()));
        connect(exportCSV,SIGNAL(clicked()),this,SLOT(exportCSVFile()));
}

void MainWindow::createNew(){
    SeatChange originSeat = SeatChange(columnSeat->text().toInt(),rowSeat->text().toInt());
    seatView->setRowCount(rowSeat->text().toInt());
    seatView->setColumnCount(columnSeat->text().toInt());
    SeatChange::clsNum = studentNum->text().toInt();
    originSeat.newSeat();
    currentSeat = originSeat.getSeatData();
    for(int y=0;y<=SeatChange::height;y++){
        seatView->setColumnWidth(y,int((seatView->width()/SeatChange::width)*0.9));
        for(int x=0;x<=SeatChange::width;x++){
            seatView->setRowHeight(y,int((seatView->height()/SeatChange::height)*0.9));
            QLabel *item = new QLabel(QString::number(originSeat.getSeatID(x,y),10));
            item->setAlignment(Qt::AlignCenter);
            QFont fn;
            fn.setPixelSize(int((seatView->height()/SeatChange::height)*0.7));
            item->setFont(fn);
            seatView->setCellWidget(y, x,item);
        }
    }
}

void MainWindow::importCSVFile(){
    QString csvDialogName = QFileDialog::getOpenFileName(this,tr("CSV Import"),".","CSV File (*.csv)");
    std::string file = csvDialogName.toStdString();
    SeatChange oldSeatFromFile(seatView->columnCount(),seatView->rowCount());
    oldSeatFromFile.fromCsvSeat(file);
}

void MainWindow::exportCSVFile(){
    QString output = QFileDialog::getSaveFileName(this,tr("Save CSV File"),"~/Desktop/Seat.csv","CSV File (*.csv)");
    std::string outcsv = output.toStdString();
    std::ofstream exportingCSV(outcsv);
    for(int y=0;y<SeatChange::height;y++){
        y ? exportingCSV << "\n " : exportingCSV << " "; 
        for(int x=0;x<SeatChange::width;x++){
            int cellNum = currentSeat.at(y*SeatChange::width + x);
            exportingCSV << cellNum << ", ";
        }
    }
}
MainWindow::~MainWindow(){
}