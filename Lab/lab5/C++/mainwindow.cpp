#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::LoadImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Допустимые форматы (*.png)");
    if (image.load( fileName, "*png")){
        image.convertTo(QImage::Format_ARGB32);
        ui->label->setText("Изображение загружено");
        ui->label->setAlignment(Qt::Alignment(Qt::AlignCenter));
    }
    else{
        ui->label->setText("Изображение не загружено, увы и ах.");
        ui->label->setAlignment(Qt::Alignment(Qt::AlignCenter));
    }
    s=-100;
}

void MainWindow::encodeMsg()
{
    QString msg=ui->plainTextEdit->toPlainText();
    QByteArray msg8 =msg.toUtf8();
    unsigned long amsg =ui->plainTextEdit->toPlainText().toUtf8().size();

    int
            k3=14851492,
            count2=0,
            countup=0,
            iki=0,
            fff[32]{0},
            count = sizeof(fff)/sizeof(fff[0]);

    unsigned long g=msg8.size();

    for (int ij=count-1;ij>=0;ij--){
        if (g%2==1){
            fff[ij]=1;
        }
        g>>=1;
        if (g==0) break;
    }

    bool
            crit=true,
            flag=true;
    if(!image.isNull()){
    if (((image.width()*image.height()*3)/8-7)> amsg){
       for (int i=0;i<image.height();i++){
           for (int j=0;j<image.width();j++){
               QColor dec= image.pixelColor(j,i);

              unsigned int
                       red=dec.red(),
                       blue=dec.blue(),
                       green=dec.green();

               if (countup<24){
                   int bitIndex = 23 - countup % 24;

                   bool bit = (k3 >> bitIndex) % 2;

                   if(bit%2==1){
                       if (red%2==0){
                           red|=1;
                       }
                   }
                   else
                  {
                       if (red%2==1){
                           red>>=1;
                           red<<=1;
                       }
                   }
                   if(countup<24){
                       countup++;

                       bitIndex = 23 - countup % 24;
                       bit = (k3 >> bitIndex) % 2;
                       if(bit%2==1){
                           if (green%2==0){
                               green|=1;
                           }
                       }
                       else
                       {
                           if (green%2==1){
                               green>>=1;
                               green<<=1;
                           }
                       }
                   }
                   if(countup<24){
                       countup++;

                       bitIndex = 23 - countup % 24;
                       bit = (k3 >> bitIndex) % 2;
                       if(bit%2==1){
                           if (blue%2==0){
                               blue|=1;
                           }
                       }
                       else
                       {
                           if (blue%2==0){
                               blue>>=1;
                               blue<<=1;
                           }
                       }
                   }
                   countup++;
               }
               if (countup==25 && count2<count){
                       if (fff[count2]==0 && crit){
                           if (red%2==1){
                               red>>=1;
                               red<<=1;
                           }
                       }
                       else {
                           if (red%2==0 && crit){
                               red|=1;
                           }
                       }
                       count2++;

                       if (fff[count2]==0 && crit){
                           if (green%2==1){
                               green>>=1;
                               green<<=1;
                           }
                       }
                       else {
                           if (green%2==0 && crit){
                               green|=1;
                           }
                       }
                       count2++;
                       if (count2==count){
                           crit=false;
                           flag=false;
                       }

                       if (fff[count2]==0 && crit){
                           if (blue%2==1 && crit){
                               blue>>=1;
                               blue<<=1;
                           }
                       }
                       else {
                           if (blue%2==0 && crit){
                               blue|=1;
                           }
                       }
                       count2++;

               }
               if (countup==24) countup++;
               if (!crit && flag){
                   if (iki < (msg8.size() * 8)-1) {
                       iki++;
                   int
                           byteIndex = iki/8,
                           bitIndex = 7 - iki % 8;
                   bool bit = (msg8[byteIndex] >> bitIndex) % 2;
                       if (bit){
                           if (red%2==0){
                               red|=1;
                           }
                       }
                       else{
                           if (red%2==1){
                               red>>=1;
                               red<<=1;
                           }
                       }
                       if (iki < (msg8.size() * 8)-1){
                        iki++;                       
                        byteIndex = iki/8;
                        bitIndex = 7 - iki % 8;
                        bit = (msg8[byteIndex] >> bitIndex) % 2;
                       if (bit){
                           if (green%2==0){
                               green|=1;
                           }
                       }
                       else{
                           if (green%2==1){
                               green>>=1;
                               green<<=1;
                           }
                       }
                       }

                       if (iki < (msg8.size() * 8)-1){
                       iki++;
                       byteIndex = iki/8;
                       bitIndex = 7 - iki % 8;
                       bit = (msg8[byteIndex] >> bitIndex) % 2;

                       if (bit){
                           if (blue%2==0){
                               blue|=1;
                           }
                       }
                       else{
                           if (blue%2==1){
                               blue>>=1;
                               blue<<=1;
                           }
                       }
                       }

                   }
                   else break;

               }
               if (!flag){
                   if (iki < (msg8.size() * 8)-1){
                   int
                           byteIndex = iki/8,
                           bitIndex = 7 - iki % 8;
                   bool bit = (msg8[byteIndex] >> bitIndex) % 2;

                   if (bit){
                       if (blue%2==0){
                           blue|=1;
                       }
                   }
                   else{
                       if (blue%2==1){
                           blue>>=1;
                           blue<<=1;
                       }
                   }
                   }
                   flag=true;
               }
               dec.setRed(red);
               dec.setGreen(green);
               dec.setBlue(blue);
               image.setPixelColor(j,i,dec);
           }

       }
       ui->label->setText("Сообщение добавлено в изображение!");
    }
    else
        ui->label->setText("Недостаточный размер изображения");
    }
    else
    {
        ui->label->setText("Изображение не загружено");
    }
}
void MainWindow:: decodeMsg(){
    QByteArray msg,
               byte;

    int     k3[24]{1,1,1,0,0,0,1,0,1,0,0,1,1,1,0,1,1,0,1,0,0,1,0,0},
            countdown=24,
            countup=0,
            countdown2=32,
            sc=-1;

    int inc;
    char inctc;

    bool crit=true,
         vcrit=true,
         flag=true;

    char buffer=0;



    for (int i=0;i<image.height();i++){
        for (int j=0;j<image.width();j++){
            QColor dec= image.pixelColor(j,i);
            int red=dec.red(),blue=dec.blue(),green=dec.green();
            if (countdown!=0){
                if (k3[countup]==red%2)countdown--;
                countup++;
                if (k3[countup]==green%2)countdown--;
                countup++;
                if (k3[countup]==blue%2)countdown--;
                countup++;

            }

            if (countup>24) break;
            if (countdown==0 && !crit){
                if (countdown2 > 0){
                    if (red%2==0 && vcrit){
                        msg.push_back(static_cast<char>('0'));
                    }
                    else{
                        if (vcrit)
                            msg.push_back(static_cast<char>('1'));
                    }
               if (countdown2!=0)countdown2--;
               else vcrit=false;

               if (green%2==0 && vcrit){

                   msg.push_back(static_cast<char>('0'));
               }
               else{
                   if (vcrit)
                       msg.push_back(static_cast<char>('1'));
               }
               if (countdown2!=0)countdown2--;
               else vcrit=false;
               if (blue%2==0 && vcrit && countdown2!=0){
                   msg.push_back(static_cast<char>('0'));
               }
               else{
                   if (vcrit && countdown2 !=0)
                       msg.push_back(static_cast<char>('1'));
               }
               if (countdown2!=0)countdown2--;
               else vcrit=false;
                }

            }
            if (countdown==0 && crit) {
                crit=false;
            }
            if (countdown2==-1){
                if (sc!=0){
                    sc--;
                    inc=red%2;
                    inctc=inc+'0';
                    msg.push_back(static_cast<char>(inctc));
                }
                if (sc!=0){
                    sc--;
                    inc=green%2;
                    inctc=inc+'0';
                    msg.push_back(static_cast<char>(inctc));
                }
                if (sc!=0){
                    sc--;
                    inc=blue%2;
                    inctc=inc+'0';
                    msg.push_back(static_cast<char>(inctc));
                }
                }
            if (countdown2==0 && flag) {
                s=msg.toInt(nullptr,2);
                sc=msg.toInt(nullptr,2);
                sc*=8;
                flag=false;
                msg.remove(0,32);
                inc=blue%2;
                inctc=inc+'0';
                msg.push_back(static_cast<char>(inctc));
                sc--;
                countdown2--;
            }
            }
        if (countup>24)break;
        }
    if (sc==0){
        for (int i=0;i < msg.size();i++){

            buffer=(buffer<<1)|(msg[i]-'0');
            if (i%8==7){
                byte.push_back(buffer);
                buffer=0;
            }
        }
    }
    if (countdown!=0 || countup>24){
        ui->label->setText("Сообщение не обнаружено");
    }
    else{
        ui->label->setText(QString("Присутствует сообщение длиной %1 байт").arg(s));
        ui->plainTextEdit->setPlainText(QString::fromUtf8(byte));
    }
}
void MainWindow::saveMsg(){
     QString fileName;
     if (image.isNull()){
         QMessageBox msgBox;
         msgBox.setModal(true);
         msgBox.setWindowFlags(Qt::FramelessWindowHint);
         msgBox.setIcon(QMessageBox::Critical);
         msgBox.setText("Сначала загрузите изображение!");
         msgBox.setWindowTitle("About");
         msgBox.exec();
     }
     else fileName = QFileDialog::getSaveFileName(this, "Save File","","Допустимые форматы(*.png )");
    if (fileName.isNull() || image.isNull()){
        ui->label->setText("Изображение не сохранено,\n проверьте имя файла или загрузите его снова");
    }
    else{
    image.save(fileName,"png");
    ui->label->setText("Изображение успешно сохранено!");
    ui->label->setAlignment(Qt::Alignment(Qt::AlignCenter));
    }
}

void MainWindow::msgChanged()
{
    if (s!=-100){
    unsigned long gf=ui->plainTextEdit->toPlainText().toUtf8().size();
    char32_t size =(image.width()*image.height()*3)/8-7 ;
    if (gf<= size)
    ui->label_5->setText(QString("Ещё можно ввести %1 байт").arg(size-gf));
    else
        ui->label_5->setText(QString("Недостаточно места, уберите %1 ,байт").arg(-1*(size-gf)));
    }
    else {
        ui->label_5->setText(QString("Тут отображаются байты, т.е размер для ввода текста."));
    }
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::LoadImage);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::encodeMsg);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::saveMsg);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::decodeMsg);
    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::msgChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

