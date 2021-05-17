#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QImage>
#include<QString>
#include <QByteArray>
#include <QColor>
#include <cmath>
#include <iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
QImage image;

int s=-100;

public slots:
    void LoadImage();
public slots:
    void decodeMsg();
public slots:
    void encodeMsg();
public slots:
    void saveMsg();
public slots:
    void msgChanged();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
