#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphikw.h"

#include <QFileDialog>
#include <QString>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Arh();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{

    QString direc = "/home/engener/BOGDAN/";
    QString d, m, g;
    QString Month[12] = {"января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября", "ноября", "декабря"};

    if (!direc.isEmpty()){
QString FileName = QFileDialog::getOpenFileName(this,"Change file",direc,"bak2*.*");

int NFName = FileName.indexOf("bak2");

d = FileName.mid(NFName+4,2);
m = FileName.mid(NFName+6,2);
g = "20" + FileName.mid(NFName+8,2);
QString FDate = d + " " + Month[m.toInt()-1] + " " + g;

ui->lineEdit_DTF->setText(QString(FDate));
ui->lineEdit_Directory->setText(FileName);

QFile OF(FileName);
OF.setFileName(FileName);
OF.open(QIODevice::ReadOnly);

    if (OF.isOpen()){
        int res = OF.read((char *)&Massiv,OF.size());
        int Records = res/(sizeof(RecordBlackBox));

        ui->lineEdit_Records->setText(QString::number(Records));
        ui->horizontalSlider->setMaximum(Records-1);

        Display(1);
        Grafik();
        }

return;
}}
void MainWindow::Display(int position){
    int j = position;
    QString c ="background-color: rgb(0, 255, 255);", w ="background-color: rgb(255, 255, 255);";
    QString time_="            ";
    int i, L;
    ui->lineEdit_CRecords->setText(QString::number(j+1));

//SgnAnl ####################################################################################
    for(i=0;i<20;i++){Mas[i+111]->setText(" "+QString::number(Massiv[j].SgnAnl[i]));};

//Time & Anlg ###############################################################################
    for(i=0;i<12;i++)
    {
        time_ += QChar(Massiv[j].time[i]);
        Mas[i+96]->setText(QString::number(Massiv[j].Anlg[i]));
    }

    ui->lineEdit_DT->setText(QString(time_));
    Mas[108]->setText(QString::number(Massiv[j].Anlg[10] + Massiv[j].Anlg[11]));
    Mas[109]->setText(QString::number(Massiv[j].Anlg[0] - Massiv[j].Anlg[9]));
    Mas[110]->setText(QString::number(Massiv[j].Anlg[3] - Massiv[j].Anlg[2]));
// OutCww ####################################################################################

// OutCww1
        L = 1;
        for(i=0;i<8;i++){
            if(Massiv[j].OutCww1[0]&L){Mas[i+131]-> setStyleSheet(c);}
            else {Mas[i+131] -> setStyleSheet(w);};
            L= L*2;
        }
        L = 1;
        for(i=8;i<16;i++){
            if(Massiv[j].OutCww1[1]&L){Mas[i+131]-> setStyleSheet(c);}
            else {Mas[i+131] -> setStyleSheet(w);};
            L= L*2;
        }
// OutCww3
        L = 1;
        for(i=0;i<8;i++){
            if(Massiv[j].OutCww3[0]&L){Mas[i+147]-> setStyleSheet(c);}
            else {Mas[i+147] -> setStyleSheet(w);};
            L= L*2;
        }
        L = 1;
        for(i=8;i<16;i++){
            if(Massiv[j].OutCww3[1]&L){Mas[i+147]-> setStyleSheet(c);}
            else {Mas[i+147] -> setStyleSheet(w);};
            L= L*2;
        }

// InCww #####################################################################################
//InCww1
        L = 1;
        for(i=0;i<8;i++){
            if(Massiv[j].InCww1[0]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }
        L = 1;
        for(i=8;i<16;i++){
            if(Massiv[j].InCww1[1]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }
        L = 1;
        for(i=16;i<24;i++){
            if(Massiv[j].InCww1[2]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }
        L = 1;
        for(i=24;i<32;i++){
            if(Massiv[j].InCww1[3]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }
//InCww2
        L = 1;
        for(i=32;i<40;i++){
            if(Massiv[j].InCww2[0]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }
        L = 1;
        for(i=40;i<48;i++){
            if(Massiv[j].InCww2[1]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }
        L = 1;
        for(i=48;i<56;i++){
            if(Massiv[j].InCww2[2]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }
        L = 1;
        for(i=56;i<64;i++){
            if(Massiv[j].InCww2[3]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }
//InCww3
        L = 1;
        for(i=64;i<72;i++){
            if(Massiv[j].InCww3[0]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }
        L = 1;
        for(i=72;i<80;i++){
            if(Massiv[j].InCww3[1]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }
        L = 1;
        for(i=80;i<88;i++){
            if(Massiv[j].InCww3[2]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }
        L = 1;
        for(i=88;i<96;i++){
            if(Massiv[j].InCww3[3]&L){Mas[i]-> setStyleSheet(c);}
            else {Mas[i] -> setStyleSheet(w);};
            L= L*2;
        }

// DsAn ###########################################################################
    for(i=0;i<20;i++){
        if(QString::number(Massiv[j].dsAn[i]) == "0")
        {
            Mas[i+163]->setText(" ");
            Mas[i+163]->setStyleSheet("background-color: rgb(220, 220, 220);");
            }
        else{
            Mas[i+163]->setText(QString::number(Massiv[j].dsAn[i]));
            Mas[i+163]->setStyleSheet(c);
        }
    };
// Val ############################################################################

    L = 1;
    for(i=183;i<191;i++){
        if(Massiv[j].ValUSO&L){Mas[i]-> setStyleSheet(c);}
        else {Mas[i] -> setStyleSheet(w);};
        L= L*2;
    }
    L = 1;
    for(i=191;i<199;i++){
        if(Massiv[j].ValMK&L){Mas[i]-> setStyleSheet(c);}
        else {Mas[i] -> setStyleSheet(w);};
        L= L*2;
    }
return;
}

// Прокрутка записей
void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    position = ui->horizontalSlider->value();
    globPosition = position;
    Display(position);
}
//переключение записи назад
void MainWindow::on_PBut_clicked()
{
    if(globPosition>0){
    globPosition -= 1;
    Display(globPosition);}
}
//переключение записи вперёд
void MainWindow::on_NBut_clicked()
{
    if(globPosition<(ui->horizontalSlider->maximum())){
    globPosition += 1;
    Display(globPosition);}
}
// Архив объектов интерфейса
void MainWindow::Arh(){
//InCww 1
    Mas[0] = ui->label_nm;
    Mas[1] = ui->label_ns;
    Mas[2] = ui->label_avt1;
    Mas[3] = ui->label_avt2;
    Mas[4] = ui->label_avt3;
    Mas[5] = ui->label_pz11;
    Mas[6] = ui->label_pz21;
    Mas[7] = ui->label_upz1;
    Mas[8] = ui->label_pz12;
    Mas[9] = ui->label_pz22;
    Mas[10] = ui->label_upz2;
    Mas[11] = ui->label_por1;
    Mas[12] = ui->label_por2;
    Mas[13] = ui->label_por3;
    Mas[14] = ui->label_ukb1;
    Mas[15] = ui->label_ukm1;

    Mas[16] = ui->label_ukb2;
    Mas[17] = ui->label_ukm2;
    Mas[18] = ui->label_ukb3;
    Mas[19] = ui->label_ukm3;
    Mas[20] = ui->label_rsr;
    Mas[21] = ui->label_toprch;
    Mas[22] = ui->label_01;
    Mas[23] = ui->label_02;
    Mas[24] = ui->label_nm_pr;
    Mas[25] = ui->label_ns_pr;
    Mas[26] = ui->label_03;
    Mas[27] = ui->label_04;
    Mas[28] = ui->label_05;
    Mas[29] = ui->label_06;
    Mas[30] = ui->label_07;
    Mas[31] = ui->label_09;
//InCww 2
    Mas[32] = ui->label_rmr11;
    Mas[33] = ui->label_rmr21;
    Mas[34] = ui->label_rmr31;
    Mas[35] = ui->label_rmr41;
    Mas[36] = ui->label_rmt11;
    Mas[37] = ui->label_rmt21;
    Mas[38] = ui->label_rmt31;
    Mas[39] = ui->label_rmt41;
    Mas[40] = ui->label_rmr12;
    Mas[41] = ui->label_rmr22;
    Mas[42] = ui->label_rmr32;
    Mas[43] = ui->label_rmr42;
    Mas[44] = ui->label_rmt12;
    Mas[45] = ui->label_rmt22;
    Mas[46] = ui->label_rmt32;
    Mas[47] = ui->label_rmt42;

    Mas[48] = ui->label_nisp11;
    Mas[49] = ui->label_nisp21;
    Mas[50] = ui->label_nisp31;
    Mas[51] = ui->label_nisp41;
    Mas[52] = ui->label_prov11;
    Mas[53] = ui->label_prov21;
    Mas[54] = ui->label_prov31;
    Mas[55] = ui->label_prov41;
    Mas[56] = ui->label_nisp12;
    Mas[57] = ui->label_nisp22;
    Mas[58] = ui->label_nisp32;
    Mas[59] = ui->label_nisp42;
    Mas[60] = ui->label_prov12;
    Mas[61] = ui->label_prov22;
    Mas[62] = ui->label_prov32;
    Mas[63] = ui->label_prov42;
//InCww 3
    Mas[64] = ui->label_eispk;
    Mas[65] = ui->label_evrk;
    Mas[66] = ui->label_ekbk;
    Mas[67] = ui->label_ekmk;
    Mas[68] = ui->label_enk;
    Mas[69] = ui->label_etk;
    Mas[70] = ui->label_esrk;
    Mas[71] = ui->label_eprchk;
    Mas[72] = ui->label_09;
    Mas[73] = ui->label_ezpbk;
    Mas[74] = ui->label_ezpmk;
    Mas[75] = ui->label_ezptk;
    Mas[76] = ui->label_eodbk;
    Mas[77] = ui->label_eodmk;
    Mas[78] = ui->label_eombk;
    Mas[79] = ui->label_eommk;

    Mas[80] = ui->label_00;
    Mas[81] = ui->label_ezpbh;
    Mas[82] = ui->label_ezpmh;
    Mas[83] = ui->label_ezpth;
    Mas[84] = ui->label_eodbh;
    Mas[85] = ui->label_eodms;
    Mas[86] = ui->label_eombh;
    Mas[87] = ui->label_eommh;
    Mas[88] = ui->label_eisph;
    Mas[89] = ui->label_evrh;
    Mas[90] = ui->label_ekbs;
    Mas[91] = ui->label_ekmh;
    Mas[92] = ui->label_enh;
    Mas[93] = ui->label_eth;
    Mas[94] = ui->label_esrh;
    Mas[95] = ui->label_eprchh;
//ан. вых. сигн
    Mas[96] = ui->label_N;
    Mas[97] = ui->label_Nz;
    Mas[98] = ui->label_P2;
    Mas[99] = ui->label_P2z;
    Mas[100] = ui->label_P1;
    Mas[101] = ui->label_Ntg;
    Mas[102] = ui->label_Tpv;
    Mas[103] = ui->label_Zn1;
    Mas[104] = ui->label_Zn2;
    Mas[105] = ui->label_Nktg;
    Mas[106] = ui->label_Nzp;
    Mas[107] = ui->label_Nzi;
    Mas[108] = ui->label_NzT;
    Mas[109] = ui->label_NNktg;
    Mas[110] = ui->label_P2zP2;
// sgnAnl
    Mas[111] = ui->label_N11;
    Mas[112] = ui->label_N21;
    Mas[113] = ui->label_N31;
    Mas[114] = ui->label_N41;
    Mas[115] = ui->label_N12;
    Mas[116] = ui->label_N22;
    Mas[117] = ui->label_N32;
    Mas[118] = ui->label_N42;
    Mas[119] = ui->label_1P2;
    Mas[120] = ui->label_2P2;
    Mas[121] = ui->label_3P2;
    Mas[122] = ui->label_1P1;
    Mas[123] = ui->label_2P1;
    Mas[124] = ui->label_3P1;
    Mas[125] = ui->label_1Ntg;
    Mas[126] = ui->label_2Ntg;
    Mas[127] = ui->label_3Ntg;
    Mas[128] = ui->label_1Tpv;
    Mas[129] = ui->label_2Tpv;
    Mas[130] = ui->label_3Tpv;
//OutCww 1
    Mas[131] = ui->label_isp;
    Mas[132] = ui->label_vr;
    Mas[133] = ui->label_kb;
    Mas[134] = ui->label_km;
    Mas[135] = ui->label_rn;
    Mas[136] = ui->label_rt;
    Mas[137] = ui->label_sr;
    Mas[138] = ui->label_oprch;

    Mas[139] = ui->label_000;
    Mas[140] = ui->label_zpb;
    Mas[141] = ui->label_zpm;
    Mas[142] = ui->label_zpt;
    Mas[143] = ui->label_odb;
    Mas[144] = ui->label_odm;
    Mas[145] = ui->label_omb;
    Mas[146] = ui->label_omm;
//OutCww 3
    Mas[147] = ui->label_dN;
    Mas[148] = ui->label_dP2;
    Mas[149] = ui->label_dP1;
    Mas[150] = ui->label_dNtg;
    Mas[151] = ui->label_dTpv;
    Mas[152] = ui->label_imit;
    Mas[153] = ui->label_setb;
    Mas[154] = ui->label_piv;

    Mas[155] = ui->label_piva;
    Mas[156] = ui->label_pzmk;
    Mas[157] = ui->label_sinh;
    Mas[158] = ui->label_001;
    Mas[159] = ui->label_npiv;
    Mas[160] = ui->label_tpiv;
    Mas[161] = ui->label_srpiv;
    Mas[162] = ui->label_nemogy;
// dsAn
    Mas[163] = ui->label_N11_2;
    Mas[164] = ui->label_N21_2;
    Mas[165] = ui->label_N31_2;
    Mas[166] = ui->label_N41_2;
    Mas[167] = ui->label_N12_2;
    Mas[168] = ui->label_N22_2;
    Mas[169] = ui->label_N32_2;
    Mas[170] = ui->label_N42_2;
    Mas[171] = ui->label_1P2_2;
    Mas[172] = ui->label_2P2_2;
    Mas[173] = ui->label_3P2_2;
    Mas[174] = ui->label_1P1_2;
    Mas[175] = ui->label_2P1_2;
    Mas[176] = ui->label_3P1_2;
    Mas[177] = ui->label_1Ntg_2;
    Mas[178] = ui->label_2Ntg_2;
    Mas[179] = ui->label_3Ntg_2;
    Mas[180] = ui->label_1Tpv_2;
    Mas[181] = ui->label_2Tpv_2;
    Mas[182] = ui->label_3Tpv_2;
//отказы
    Mas[183] = ui->label_nit;
    Mas[184] = ui->label_nit1;
    Mas[185] = ui->label_nit2;
    Mas[186] = ui->label_nit3;
    Mas[187] = ui->label_nit4;
    Mas[188] = ui->label_nit5;
    Mas[189] = ui->label_nit6;
    Mas[190] = ui->label_nit7;

    Mas[191] = ui->label_nik1;
    Mas[192] = ui->label_nik2;
    Mas[193] = ui->label_nik3;
    Mas[194] = ui->label_nik4;
    Mas[195] = ui->label_nik5;
    Mas[196] = ui->label_nik6;
    Mas[197] = ui->label_nik7;
    Mas[198] = ui->label_nik8;
}

void MainWindow::on_action_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Подтверждение","Вы действительно хотите выйти?",
                                  QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){QApplication::quit();}
}
// отрисовка графиков
void MainWindow::Grafik(){

    float last = 0;
    int i;
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPen pen(Qt::white);
    QPen pen_gn(Qt::green);
    QPen pen_r(Qt::red);
    QPen pen_bl(Qt::blue);
    QPen pen_c(Qt::cyan);
    QPen pen_y(Qt::yellow);
    QPen pen_gr(Qt::gray);
    QPen pen_m(Qt::magenta);
    QPen pen_dr(Qt::darkRed);
    QPen pen_dg(Qt::darkGreen);
    QPen pen_dm(Qt::darkMagenta);
    QPen pen_dgr(Qt::darkGray);
    int maxl = (ui->horizontalSlider->maximum());
    int heig = 250;

     if(ui->checkBox->checkState() == Qt::Checked){
//#
//||
    for(i=0;i<maxl;i++){
        if(i % 10 == 0){
            scene->addLine(i,30,i,-250,pen_dgr);
        }
    }
//=
    for(i=0;i<heig;i++){
        if(i % 10 == 0){
 scene->addLine(0,i*(-1),maxl,i*(-1),pen_dgr);
        }}
     }
    // zero
scene->addLine(0,0,maxl,0,pen);

    for(i=1;i<maxl;i++){

        if(ui->checkBox_1->checkState() == Qt::Checked){
        last = (Massiv[i-1].Anlg[0]);
        scene->addLine(i-1,last*(-1),i,(Massiv[i].Anlg[0])*(-1),pen_gn);};

        if(ui->checkBox_2->checkState() == Qt::Checked){
        last = (Massiv[i-1].Anlg[1]);
        scene->addLine(i-1,last*(-1),i,(Massiv[i].Anlg[1])*(-1),pen_r);};

        if(ui->checkBox_3->checkState() == Qt::Checked){
        last = (Massiv[i-1].Anlg[2]);
        scene->addLine(i-1,last*(-1),i,(Massiv[i].Anlg[2])*(-1),pen_bl);};

        if(ui->checkBox_4->checkState() == Qt::Checked){
        last = (Massiv[i-1].Anlg[3]);
        scene->addLine(i-1,last*(-1),i,(Massiv[i].Anlg[3])*(-1),pen_c);};

        if(ui->checkBox_5->checkState() == Qt::Checked){
        last = (Massiv[i-1].Anlg[4]);
        scene->addLine(i-1,last*(-1),i,(Massiv[i].Anlg[4])*(-1),pen_y);};

        if(ui->checkBox_6->checkState() == Qt::Checked){
        last = (Massiv[i-1].Anlg[5]);
        scene->addLine(i-1,last*(-1),i,(Massiv[i].Anlg[5])*(-1),pen_gr);};

        if(ui->checkBox_7->checkState() == Qt::Checked){
        last = (Massiv[i-1].Anlg[6]);
        scene->addLine(i-1,last*(-1),i,(Massiv[i].Anlg[6])*(-1),pen_m);};

        if(ui->checkBox_8->checkState() == Qt::Checked){
        last = (Massiv[i-1].Anlg[9]);
        scene->addLine(i-1,last*(-1),i,(Massiv[i].Anlg[9])*(-1),pen_dr);};

        if(ui->checkBox_9->checkState() == Qt::Checked){
        last = (Massiv[i-1].Anlg[10]);
        scene->addLine(i-1,last*(-1),i,(Massiv[i].Anlg[10])*(-1),pen_dm);};

        if(ui->checkBox_10->checkState() == Qt::Checked){
        last = (Massiv[i-1].Anlg[11]);
        scene->addLine(i-1,last*(-1),i,(Massiv[i].Anlg[11])*(-1),pen_dg);};

    };
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_checkBox_1_clicked()
{
    Grafik();
}

void MainWindow::on_checkBox_2_clicked()
{
    Grafik();
}

void MainWindow::on_checkBox_3_clicked()
{
    Grafik();
}

void MainWindow::on_checkBox_4_clicked()
{
    Grafik();
}

void MainWindow::on_checkBox_5_clicked()
{
    Grafik();
}

void MainWindow::on_checkBox_6_clicked()
{
    Grafik();
}

void MainWindow::on_checkBox_7_clicked()
{
    Grafik();
}

void MainWindow::on_checkBox_8_clicked()
{
    Grafik();
}

void MainWindow::on_checkBox_9_clicked()
{
    Grafik();
}

void MainWindow::on_checkBox_10_clicked()
{
    Grafik();
}

void MainWindow::on_checkBox_clicked()
{
    Grafik();
}
