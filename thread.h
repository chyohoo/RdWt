#ifndef HISTORYTHREAD_H
#define HISTORYTHREAD_H
#include <QThread>
#include <write_data.h>
#include <QFile>
#include <QProcess>
#include <QTextStream>
#include <QDebug>


class historyThread : public QThread
{
    Q_OBJECT
public:
    historyThread(QObject *parent = 0)
        : QThread(parent)
    {
    }
signals:
    void historyData();
protected:
    void run(){

//        if(p_r.isReadable()){
            int j = 0;
            QFile file_h("history.txt");
            if(file_h.open(QFile::ReadOnly) | QIODevice::Text)
            {
                QTextStream in(&file_h);
                while(!in.atEnd())
                {
                    in>>data::data_hist[j];   //read data from history file            qDebug()<<data::data_hist[j]
                    j++;
                }
                file_h.close();
            }
//        }
//        p_r.close();


        emit historyData();
    }
};

#endif // HISTORYTHREAD_H
