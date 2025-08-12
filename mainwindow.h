#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonPush_clicked();
    void on_pushButtonPop_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QLabel*> stackItems;
    void updateStackPositions();
};

#endif // MAINWINDOW_H
