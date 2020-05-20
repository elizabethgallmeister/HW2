#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QPushButton>


class MainWindow : public QMainWindow
{
    Q_OBJECT // macro, needed whenever your class uses signals and slots

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QHBoxLayout* makeunit(std::string label);
};
#endif // MAINWINDOW_H
