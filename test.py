import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

# def window():
#     HEIGHT = 50
#     WIDTH = 200
#     app = QtGui.QApplication(sys.argv)
#     w = QtGui.QWidget()
#     b = QtGui.QLabel(w)
#     b.setText("Hello World!")
#     w.setGeometry(100,100,WIDTH,HEIGHT)
#     b.move(WIDTH/2,HEIGHT/2)
#     w.setWindowTitle("IRON MAN")
#     w.show()
#     sys.exit(app.exec_())

# def window():
#     app = QApplication(sys.argv)
#     win = QDialog()
#     b1 = QPushButton(win)
#     b1.setText("First")
#     b1.move(50, 20)
#     b1.clicked.connect(b1_clicked)
#
#     b2 = QPushButton(win)
#     b2.setText("Second")
#     b2.move(50, 50)
#     QObject.connect(b2, SIGNAL("clicked()"), b2_clicked)
#
#     win.setGeometry(100, 100, 200, 100)
#     win.setWindowTitle("Test")
#     win.show()
#     sys.exit(app.exec_())
#
# def b1_clicked():
#     print("First")
#
# def b2_clicked():
#     print("b2 clicked")


# def window():
#     app = QApplication(sys.argv)
#     win = QWidget()
#     flo = QFormLayout()
#
#     e1 = QLineEdit()
#     e1.setValidator(QIntValidator())
#     e1.setMaxLength(4)
#     e1.setAlignment(Qt.AlignRight)
#     e1.setFont(QFont("Arial", 20))
#     flo.addRow("Integer Validator", e1)
#
#     e2 = QLineEdit("Hello World")
#     e2.setReadOnly(True)
#     flo.addRow("Read Only", e2)
#
#     e3 = QLineEdit()
#     e3.textChanged.connect(textChanged)
#     flo.addRow("Text Changed", e3)
#
#     win.setLayout(flo)
#     win.setWindowTitle("PyQt")
#     win.show()
#     sys.exit(app.exec_())
#
#
# def textChanged():
#     print("Text Changed!!!")


from PyQt4.QtCore import SIGNAL
from PyQt4.QtGui import QDialog, QApplication, QPushButton, QLineEdit, QFormLayout


class Form(QDialog):
    def __init__(self, parent=None):
        super(Form, self).__init__(parent)

        self.first = QLineEdit()
        self.first.setValidator(QIntValidator())
        self.first.setObjectName("host")

        self.second = QLineEdit()
        self.second.setValidator(QIntValidator())
        self.second.setObjectName("host")

        self.pb = QPushButton()
        self.pb.setObjectName("Add")
        self.pb.setText("Add")

        
        self.result = QLineEdit()
        

        layout = QFormLayout()
        layout.addWidget(self.first)
        layout.addWidget(self.second)
        layout.addWidget(self.pb)

        self.setLayout(layout)
        self.connect(self.pb, SIGNAL("clicked()"), self.button_click)
        self.setWindowTitle("Learning")

    def button_click(self):
        # shost is a QString object
        first = self.first.text()
        second = self.second.text()
        return (int(first) + int(second))


app = QApplication(sys.argv)
form = Form()
form.show()
app.exec_()
