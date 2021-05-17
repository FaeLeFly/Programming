from ui_mainwindow import *


class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.ui.pushButton.clicked.connect(self.loadImage)
        self.image = QImage()
        self.ui.pushButton_3.clicked.connect(self.saveImage)
        self.msgBox = QMessageBox()
        self.ui.pushButton_2.clicked.connect(self.encodeMsg)
        self.ui.pushButton_4.clicked.connect(self.decodeMsg)
        self.ui.plainTextEdit.textChanged.connect(self.msgChanged)
        self.dec = QColor()

    @Slot()
    def loadImage(self):
        fileName, _ = QFileDialog.getOpenFileName(self, "Open Image", "", "Доступные форматы (*.png)")
        if self.image.load(fileName, "*png"):
            self.image.convertTo(QImage.Format_ARGB32)
            self.ui.label.setText("Изображение загружено")
            self.ui.label.setAlignment(Qt.AlignCenter)
        else:
            self.ui.label.setText("Изображение не загружено")
            self.ui.label.setAlignment(Qt.AlignCenter)

    @Slot()
    def saveImage(self):
        if self.image == None:
            self.msgBox.setModal(True)
            self.msgBox.setWindowFlags(Qt.FramelessWindowHint)
            self.msgBox.setIcon(QMessageBox.Critical)
            self.msgBox.setText("Сначала загрузите изображение!")
            self.msgBox.exec_()
        else:
            fileName, _ = QFileDialog.getSaveFileName(self, "Save File", "", "Допустимые форматы (*.png)")
        if self.image == None:
            self.ui.label.setText("Изображение не сохранено,\n проверьте имя файла или загрузите его снова")
        else:
            self.image.save(fileName)
            self.ui.label.setText("Изображение успешно сохранено!")

    @Slot()
    def msgChanged(self):
        if self.image != None:
            msg = len(self.ui.plainTextEdit.toPlainText().encode("utf-8"))
            size = (self.image.width() * self.image.height() * 3) / 8 - 7;
            if (msg<=size):
                self.ui.label_5.setText(f"Ещё можно ввести {int(size-msg)} байт")
            else:
                self.ui.label_5.setText(f"Недостаточно места, уберите {int(-1*(size-msg))} байт")
        else:
            self.ui.label_5.setText("Тут отображаются байты, т.е размер для ввода текста.")
    @Slot()
    def encodeMsg(self):
        msg = self.ui.plainTextEdit.toPlainText()
        sigil = [1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0]
        msg = msg.encode("utf-8")
        mmsgSize = 0
        byte = 0
        deil = 0
        AA = []
        depth = int(bin(len(msg))[2:])
        for i in range(32):
            if depth > 0:
                AA.append(int(depth % 2))
                depth /= 10
            else:
                AA.append(0)
        AA.reverse()
        countup = 0
        countdown = 0
        dred = ''
        dgreen = ''
        dblue = ''
        breaks=True
        if not self.image == None:
            if self.image.width() * self.image.height() * 3 / 8 - 7 > len(msg):
                for i in range(self.image.height()):
                    for j in range(self.image.width()):
                        self.dec = self.image.pixelColor(j, i)
                        red, green, blue = bin(self.dec.red())[2:], bin(self.dec.green())[2:], bin(self.dec.blue())[2:]
                        if countup < len(sigil):
                            dred = red[:len(red) - 1]
                            dred += str(sigil[countup])
                            countup += 1
                            dgreen = green[:len(green) - 1]
                            dgreen += str(sigil[countup])
                            countup += 1
                            dblue = blue[:len(blue) - 1]
                            dblue += str(sigil[countup])
                            countup += 1

                        if countup == 25 and countdown < 32:
                            dred = red[:len(red) - 1]
                            dred += str(AA[countdown])
                            countdown += 1
                            dgreen = green[:len(green) - 1]
                            dgreen += str(AA[countdown])
                            countdown += 1
                            if countdown < 32:
                                dblue = blue[:len(blue) - 1]
                                dblue += str(AA[countdown])
                                countdown += 1

                        if countdown == 33 and breaks:
                            if breaks:
                                deil+=1
                                byte = bin(msg[mmsgSize])[2:]
                                if len(byte) < 8:
                                    while len(byte) < 8:
                                        byte = '0' + byte
                                dred = red[:len(red) - 1]
                                dred += byte[deil]
                                if deil == 7:
                                    mmsgSize += 1
                                    if mmsgSize >= len(msg): breaks=False
                                    deil = -1
                            if breaks:
                                deil += 1
                                byte = bin(msg[mmsgSize])[2:]
                                if len(byte) < 8:
                                    while len(byte) < 8:
                                        byte = '0' + byte
                                dgreen = dgreen[:len(dgreen) - 1]
                                dgreen += byte[deil]
                                if deil == 7:
                                    mmsgSize += 1
                                    if mmsgSize >= len(msg): breaks=False
                                    deil = -1
                            if breaks:
                                deil += 1
                                byte = bin(msg[mmsgSize])[2:]
                                if len(byte) < 8:
                                    while len(byte) < 8:
                                        byte = '0' + byte
                                dblue = blue[:len(blue) - 1]
                                dblue += byte[deil]
                                if deil == 7:
                                    mmsgSize += 1
                                    if mmsgSize >=len(msg): breaks=False
                                    deil = -1
                        if countdown == 32:
                            byte = bin(msg[mmsgSize])[2:]
                            if len(byte) < 8:
                                while len(byte) < 8:
                                    byte = '0' + byte
                            dblue = blue[:len(blue) - 1]
                            dblue += byte[deil]
                            countdown += 1
                        if countup == 24: countup += 1
                        self.dec.setRed(int(dred, 2))
                        self.dec.setGreen(int(dgreen, 2))
                        self.dec.setBlue(int(dblue, 2))
                        self.image.setPixelColor(j, i, self.dec)
                        if not breaks: break

                    if mmsgSize >= len(msg) or not breaks: break

                self.ui.label.setText("Сообщение добавлено в изображение!")
            else:
                self.ui.label.setText("Недостаточный размер изображения!")
        else:
            self.ui.label.setText("Изображение не загружено!")

    @Slot()
    def decodeMsg(self):
        sigil = [1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0]
        countdown = 24
        countup = 0
        countdown2 = 32
        sc = -1
        mSize = ''
        msgSize = 0
        box = []
        encode_text = ''
        decode_text = bytearray()
        count = 0
        crit, vcrit, flag = True, True, True
        for i in range(self.image.height()):
            for j in range(self.image.width()):
                self.dec = self.image.pixelColor(j, i)
                red, green, blue = self.dec.red(), self.dec.green(), self.dec.blue()
                if countup >24: break
                if countdown > 0:
                    if sigil[countup] == red % 2: countdown -= 1
                    else:
                        countup=-1
                        break
                    countup += 1
                    if sigil[countup] == green % 2: countdown -= 1
                    else:
                        countup = -1
                        break
                    countup += 1
                    if sigil[countup] == blue % 2: countdown -= 1
                    else:
                        countup = -1
                        break
                    countup += 1

                if countdown == 0 and not crit:
                    if countdown2 > 0:
                        box.append(str(red % 2))
                        countdown2 -= 1
                        box.append(str(green % 2))
                        countdown2 -= 1
                        if countdown2 != 0:
                            box.append(str(blue % 2))
                            countdown2 -= 1
                if countdown == 0 and crit:
                    crit = False
                if countdown2 == -1:
                    if count == 8:
                        encode_text += ' '
                        count = 0
                    if sc != 0:
                        sc -= 1
                        encode_text += str(red % 2)
                        count += 1
                    if count == 8:
                        encode_text += ' '
                        count = 0
                    if sc != 0:
                        sc -= 1
                        encode_text += str(green % 2)
                        count += 1
                    if count == 8:
                        encode_text += ' '
                        count = 0
                    if sc != 0:
                        sc -= 1
                        encode_text += str(blue % 2)
                        count += 1
                if countdown2 == 0 and flag:
                    mSize = mSize.join(box)
                    sc = int(mSize, 2)
                    msgSize = sc
                    sc *= 8
                    flag = False
                    encode_text += str(blue % 2)
                    sc -= 1
                    countdown2 -= 1
                    count += 1
            if countup > 24 or countup==-1: break
        if sc == 0:
            for i in encode_text.split():
                decode_text += bytes(int(i[j: j + 8], 2) for j in range(0, len(i), 8))
            decode_text = decode_text.decode()
        if countdown != 0 or countup >24 or countup==-1:
            self.ui.label.setText("Собщение не обнаружено!")
        else:
            self.ui.label.setText(f"Присутствует сообщение длиной {msgSize} байт")
            self.ui.plainTextEdit.setPlainText(decode_text)


if __name__ == "__main__":
    import sys

    app = QApplication(sys.argv)

    window = MainWindow()
    window.show()

    sys.exit(app.exec_())
