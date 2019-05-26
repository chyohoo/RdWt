#include "widget.h"
#include "ui_widget.h"
#include "write_data.h"
#include "thread.h"
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QProcess>
#include <QTimer>
#include <QDateTime>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    In0(new QLineEdit(this)),
    In1(new QLineEdit(this)),
    In2(new QLineEdit(this)),
    In3(new QLineEdit(this)),
    In4(new QLineEdit(this)),
    In5(new QLineEdit(this)),
    In6(new QLineEdit(this)),
    In7(new QLineEdit(this)),
    In8(new QLineEdit(this)),
    In9(new QLineEdit(this)),
    In10(new QLineEdit(this)),
    In11(new QLineEdit(this)),
    In12(new QLineEdit(this)),
    In13(new QLineEdit(this)),
    In14(new QLineEdit(this)),
    In15(new QLineEdit(this)),
    write(new QPushButton("Write",this)),
    title_Rd(new QLabel("Set of read history",this)),
    title_Wt(new QLabel("Write to tag",this)),
    Flag_Rd(new QLabel(this)),
    Flag_Wt(new QLabel(this)),
    History(new QListWidget),
    font_label(new QFont),
    font_num(new QFont),
    ui(new Ui::Widget)


{
    ui->setupUi(this);

    QVBoxLayout *main_layout = new QVBoxLayout;
    QHBoxLayout *row_1st = new QHBoxLayout;
    QHBoxLayout *row_2nd = new QHBoxLayout;

    main_layout->addLayout(row_1st);
    main_layout->addLayout(row_2nd);
    main_layout->addWidget(Flag_Wt);
    main_layout->addWidget(title_Rd);
    main_layout->addWidget(History);

    row_1st->addWidget(title_Wt);
    row_1st->addWidget(Flag_Rd);
    row_2nd->addWidget(In0);
    row_2nd->addWidget(In1);
    row_2nd->addWidget(In2);
    row_2nd->addWidget(In3);
    row_2nd->addWidget(In4);
    row_2nd->addWidget(In5);
    row_2nd->addWidget(In6);
    row_2nd->addWidget(In7);
    row_2nd->addWidget(In8);
    row_2nd->addWidget(In9);
    row_2nd->addWidget(In10);
    row_2nd->addWidget(In11);
    row_2nd->addWidget(In12);
    row_2nd->addWidget(In13);
    row_2nd->addWidget(In14);
    row_2nd->addWidget(In15);
    row_2nd->addWidget(write);

    setLayout(main_layout);

    In0->setMaximumSize(45,25);
    In1->setMaximumSize(45,25);
    In2->setMaximumSize(45,25);
    In3->setMaximumSize(45,25);
    In4->setMaximumSize(45,25);
    In5->setMaximumSize(45,25);
    In6->setMaximumSize(45,25);
    In7->setMaximumSize(45,25);
    In8->setMaximumSize(45,25);
    In9->setMaximumSize(45,25);
    In10->setMaximumSize(45,25);
    In11->setMaximumSize(45,25);
    In12->setMaximumSize(45,25);
    In13->setMaximumSize(45,25);
    In14->setMaximumSize(45,25);
    In15->setMaximumSize(45,25);

    In0->setAlignment(Qt::AlignCenter);
    In1->setAlignment(Qt::AlignCenter);
    In2->setAlignment(Qt::AlignCenter);
    In3->setAlignment(Qt::AlignCenter);
    In4->setAlignment(Qt::AlignCenter);
    In5->setAlignment(Qt::AlignCenter);
    In6->setAlignment(Qt::AlignCenter);
    In7->setAlignment(Qt::AlignCenter);
    In8->setAlignment(Qt::AlignCenter);
    In9->setAlignment(Qt::AlignCenter);
    In10->setAlignment(Qt::AlignCenter);
    In11->setAlignment(Qt::AlignCenter);
    In12->setAlignment(Qt::AlignCenter);
    In13->setAlignment(Qt::AlignCenter);
    In14->setAlignment(Qt::AlignCenter);
    In15->setAlignment(Qt::AlignCenter);

    In0->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In1->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In2->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In3->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In4->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In5->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In6->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In7->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In8->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In9->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In10->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In11->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In12->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In13->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In14->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    In15->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");

    QIntValidator *IntValidator = new QIntValidator(this);
    IntValidator->setRange(0, 255);
    In0->setValidator(IntValidator);
    In1->setValidator(IntValidator);
    In2->setValidator(IntValidator);
    In3->setValidator(IntValidator);
    In4->setValidator(IntValidator);
    In5->setValidator(IntValidator);
    In6->setValidator(IntValidator);
    In7->setValidator(IntValidator);
    In8->setValidator(IntValidator);
    In9->setValidator(IntValidator);
    In10->setValidator(IntValidator);
    In11->setValidator(IntValidator);
    In12->setValidator(IntValidator);
    In13->setValidator(IntValidator);
    In14->setValidator(IntValidator);
    In15->setValidator(IntValidator);

    font_label->setPointSize(56);
    write->setFont(*font_label);
    title_Rd->setFont(*font_label);
    title_Wt->setFont(*font_label);
    Flag_Rd->setFont(*font_label);
    Flag_Wt->setFont(*font_label);
    Flag_Wt->setAlignment(Qt::AlignCenter);

    font_num->setPointSize(36);
    In0->setFont(*font_num);
    In1->setFont(*font_num);
    In2->setFont(*font_num);
    In3->setFont(*font_num);
    In4->setFont(*font_num);
    In5->setFont(*font_num);
    In6->setFont(*font_num);
    In7->setFont(*font_num);
    In8->setFont(*font_num);
    In9->setFont(*font_num);
    In10->setFont(*font_num);
    In11->setFont(*font_num);
    In12->setFont(*font_num);
    In13->setFont(*font_num);
    In14->setFont(*font_num);
    In15->setFont(*font_num);


    QListWidgetItem *his_1 = new QListWidgetItem;
    QListWidgetItem *his_2 = new QListWidgetItem;
    QListWidgetItem *his_3 = new QListWidgetItem;

    his_1->setFont(*font_num);
    his_2->setFont(*font_num);
    his_3->setFont(*font_num);

    History->addItem(his_1);
    History->addItem(his_2);
    History->addItem(his_3);

    his_1->setText("");


    connect(write,&QPushButton::clicked,
            [&](bool) {
                        QString In_0 = In0->text();
                        data::in0 = In_0.toUInt();
                        data::data_in[0] = data::in0;
                        QString In_1 = In1->text();
                        data::in1 = In_1.toUInt();
                        data::data_in[1] = data::in1;
                        QString In_2 = In2->text();
                        data::in2 = In_2.toUInt();
                        data::data_in[2] = data::in2;
                        QString In_3 = In3->text();
                        data::in3 = In_3.toUInt();
                        data::data_in[3] = data::in3;
                        QString In_4 = In4->text();
                        data::in4 = In_4.toUInt();
                        data::data_in[4] = data::in4;
                        QString In_5 = In5->text();
                        data::in5 = In_5.toUInt();
                        data::data_in[5] = data::in5;
                        QString In_6 = In6->text();
                        data::in6 = In_6.toUInt();
                        data::data_in[6] = data::in6;
                        QString In_7 = In7->text();
                        data::in0 = In_7.toUInt();
                        data::data_in[7] = data::in7;
                        QString In_8 = In8->text();
                        data::in8 = In_8.toUInt();
                        data::data_in[8] = data::in8;
                        QString In_9 = In9->text();
                        data::in9 = In_9.toUInt();
                        data::data_in[9] = data::in9;
                        QString In_10 = In10->text();
                        data::in10 = In_10.toUInt();
                        data::data_in[10] = data::in10;
                        QString In_11 = In11->text();
                        data::in11 = In_11.toUInt();
                        data::data_in[11] = data::in11;
                        QString In_12 = In12->text();
                        data::in12 = In_12.toUInt();
                        data::data_in[12] = data::in12;
                        QString In_13 = In13->text();
                        data::in13 = In_13.toUInt();
                        data::data_in[13] = data::in13;
                        QString In_14 = In14->text();
                        data::in14 = In_14.toUInt();
                        data::data_in[14] = data::in14;
                        QString In_15 = In15->text();
                        data::in15 = In_15.toUInt();
                        data::data_in[15] = data::in15;
                        }
            );

 //pass  data to be written into a txt file
    connect(write,&QPushButton::clicked,[] {
        QFile file_w("write.txt");
        if(file_w.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
           QTextStream out(&file_w);
           for(int i = 0;i < 16; i++){
               out<<data::data_in[i]<<endl;
           }
           file_w.close();
        }
    });

    QProcess *p_h = new QProcess(); //history reading process in pi

//when button clicked call the python script to write the data from txt file to rfid token
    connect(write,&QPushButton::clicked,[=]{
        p_h->close(); // prevent confilt in pi
        QProcess p_w;
         p_w.start("python /home/pi/MFRC522-python/Write.py");
         p_w.waitForReadyRead();
         if(p_w.isReadable()){
                 Flag_Wt->setText("sucessfully written!");
            }
         p_w.close();
    });


//timer to refresh the label
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer,&QTimer::timeout,this,[=](){
        Flag_Wt->setText("");

    });

//creat a thread to read from token and use a timer to keep the thread periodically start
    historyThread *t = new historyThread();
    QTimer *timer_h = new QTimer(this);
    timer_h->setInterval(1300);
    timer_h->start();
    connect(timer_h,&QTimer::timeout,this,[=](){
        p_h->start("python /home/pi/MFRC522-python/Read.py"); //>/dev/null 2>&1 &
        t->start();
    });


//when tread finsihed read data from token, update the history
    connect(t,&historyThread::historyData,this,[=](){
          QString temp;
//        QDateTime time_c = QDateTime::currentDateTime();
//        QString str = time_c.toString("yyyy-MM-dd hh:mm:ss ddd");
//        temp.append(str);
        for(int i = 0; i < 16; i ++)
        {
            temp.append(QString::number(data::data_hist[i])+" ");
         }
        if(temp != his_1->text()){

            his_3->setText(his_2->text());
            his_2->setText(his_1->text());
            his_1->setText(temp);
        }
    });



}

Widget::~Widget()
{
    delete ui;
}

