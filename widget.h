#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QLayout>
#include <QFont>

class thread;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();




private:
    Ui::Widget *ui;
    QLineEdit *In0;
    QLineEdit *In1;
    QLineEdit *In2;
    QLineEdit *In3;
    QLineEdit *In4;
    QLineEdit *In5;
    QLineEdit *In6;
    QLineEdit *In7;
    QLineEdit *In8;
    QLineEdit *In9;
    QLineEdit *In10;
    QLineEdit *In11;
    QLineEdit *In12;
    QLineEdit *In13;
    QLineEdit *In14;
    QLineEdit *In15;

    QPushButton *write;

    QLabel *title_Rd;
    QLabel *title_Wt;

    QLabel *Flag_Wt;
    QLabel *Flag_Rd;

    QListWidget *History;

    QVBoxLayout *main_layout;
    QHBoxLayout *col_1st;
    QHBoxLayout *col_2nd;

    QIntValidator *IntValidator;

    QFont *font_label;
    QFont *font_num;




};

#endif // WIDGET_H
