#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QLabel>
#include <QMessageBox>
#include "graphikw.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_horizontalSlider_sliderMoved(int position);

    void on_PBut_clicked();

    void on_NBut_clicked();

    void on_action_triggered();

    void on_checkBox_1_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_checkBox_6_clicked();

    void on_checkBox_7_clicked();

    void on_checkBox_8_clicked();

    void on_checkBox_9_clicked();

    void on_checkBox_10_clicked();

    void on_checkBox_clicked();

private:
void Display(int position);
void Grafik();

quint16 globPosition=1;

QLabel *Mas[200];
void Arh(void);
    Ui::MainWindow *ui;
#pragma pack(push,1)
    struct RecordBlackBox
    {
        unsigned char   time[12];
        float           Anlg[12];
        float           SgnAnl[20];
        unsigned char   OutCww1[2];
        unsigned char   OutCww3[2];
        unsigned char   InCww1[4];
        unsigned char   InCww2[4];
        unsigned char   InCww3[4];
        unsigned char   dsAn[20];
        unsigned char   ValUSO;
        unsigned char   ValMK;
    };
    #pragma pack(pop)

 RecordBlackBox Massiv[5000];
};
#endif // MAINWINDOW_H
