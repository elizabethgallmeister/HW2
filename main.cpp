#include "mainwindow.h"
#include <QApplication>

#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QPushButton>

QHBoxLayout* makeunit(std::string label)
{
    QLabel* l1 = new QLabel(QString(label.c_str()));

    QSlider* slide1 = new QSlider(Qt::Horizontal);
    slide1 -> setRange(0, 100);

    QSpinBox* box1 = new QSpinBox();
    box1 -> setRange(0,100);

    QObject::connect(slide1, SIGNAL(valueChanged(int)),
                    box1, SLOT(setValue(int)));
    QObject::connect(box1, SIGNAL(valueChanged(int)),
                    slide1, SLOT(setValue(int)));

    QHBoxLayout* layout = new QHBoxLayout();
    layout -> addWidget(l1);
    layout -> addWidget(slide1);
    layout -> addWidget(box1);

    return layout;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // manages execution and exiting of Qt Program
    QWidget* window = new QWidget;
    window -> setWindowTitle("Final Grade Calculator");

    QVBoxLayout* col1 = new QVBoxLayout();
    for(int i = 1; i < 9; ++i)
    {
        col1 -> addLayout(makeunit("Hw " + std::to_string(i)));
    }

    QCheckBox* schemeA = new QCheckBox("Schema A");
    QCheckBox* schemeB = new QCheckBox("Schema B");

    //QObject::connect(schemeA, SIGNAL(clicked()),
    //                 schemeB, SLOT(unclick()));

    QPushButton* calculate = new QPushButton("Calculate my grade!");

    QVBoxLayout* col2 = new QVBoxLayout();
    col2 -> addLayout(makeunit("Midterm 1"));
    col2 -> addLayout(makeunit("Midterm 2"));
    col2 -> addLayout(makeunit("Final Exam"));
    col2 -> addWidget(schemeA);
    col2 -> addWidget(schemeB);
    col2 -> addWidget(calculate);

    QHBoxLayout* overall = new QHBoxLayout();
    overall -> addLayout(col1);
    overall -> addLayout(col2);

    //at end, push button to compute score, launches popup window

    window -> setLayout(overall);
    window -> show();

    return a.exec();
}
