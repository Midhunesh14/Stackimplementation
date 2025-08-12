#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButtonPush_clicked() {
    int maxStackSize = ui->spinBoxMaxSize->value(); // Read runtime size

    if (stackItems.size() >= maxStackSize) {
        QMessageBox::warning(this, "Stack Full", "Cannot push: Stack overflow!");
        return;
    }

    QString value = ui->lineEditValue->text().trimmed();
    if (value.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a value!");
        return;
    }

    QLabel *item = new QLabel(value, ui->stackArea); // parent is stackArea
    item->setStyleSheet("background-color: lightblue; border: 2px solid black; font: bold 14px;");
    item->setAlignment(Qt::AlignCenter);
    item->setGeometry(10, -40, ui->stackArea->width() - 20, 40);
    item->show();

    stackItems.push_back(item);
    updateStackPositions();
}

void MainWindow::on_pushButtonPop_clicked() {
    if (stackItems.isEmpty()) {
        QMessageBox::warning(this, "Stack Empty", "Cannot pop: Stack underflow!");
        return;
    }

    QLabel *topItem = stackItems.last();
    stackItems.pop_back();

    QPropertyAnimation *anim = new QPropertyAnimation(topItem, "geometry");
    anim->setDuration(500);
    anim->setStartValue(topItem->geometry());
    anim->setEndValue(QRect(10, -40, topItem->width(), 40));
    anim->start(QAbstractAnimation::DeleteWhenStopped);

    connect(anim, &QPropertyAnimation::finished, topItem, &QLabel::deleteLater);

    updateStackPositions();
}

void MainWindow::updateStackPositions() {
    int baseY = ui->stackArea->height() - 50;
    for (int i = 0; i < stackItems.size(); i++) {
        QLabel *item = stackItems[i];
        QPropertyAnimation *anim = new QPropertyAnimation(item, "geometry");
        anim->setDuration(500);
        anim->setStartValue(item->geometry());
        anim->setEndValue(QRect(10, baseY - i * 50, ui->stackArea->width() - 20, 40));
        anim->start(QAbstractAnimation::DeleteWhenStopped);
    }
}
