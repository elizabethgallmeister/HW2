#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QTextBrowser>
#include <vector>
#include <iostream>
#include <QComboBox>
#include <QAbstractButton>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT // macro, needed whenever your class uses signals and slots

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void buttonClicked();
    void getGrade(bool checked);

private:
    QHBoxLayout* makeunit(int i);
    QPushButton* calculate;
    QLabel* calc2;
    std::vector<QSpinBox*>grades;
    int count = 0;
    bool schemeA = true;
    double finalGrade = 0;
};
#endif // MAINWINDOW_H
