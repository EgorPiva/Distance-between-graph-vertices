#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogs/authdialog.h"
#include "dialogs/cryptodialog.h"
#include "dialogs/chordmethoddialog.h"
#include "dialogs/steganographydialog.h"
#include "dialogs/bisectionmethoddialog.h"
#include "dialogs/graphdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Устанавливаем заголовок окна
    setWindowTitle(tr("Ильин Кирилл Александрович 241-353"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUsername(const QString &username)
{
    m_username = username;
    // Обновляем заголовок окна, добавляя имя пользователя
    setWindowTitle(tr("Группа 241-371 - Пользователь: %1").arg(username));
}

void MainWindow::on_actionCrypto_triggered()
{
    on_cryptoButton_clicked();
}

void MainWindow::on_actionChordMethod_triggered()
{
    on_chordMethodButton_clicked();
}

void MainWindow::on_actionSteganography_triggered()
{
    on_steganographyButton_clicked();
}

void MainWindow::on_actionBisectionMethod_triggered()
{
    on_bisectionMethodButton_clicked();
}

void MainWindow::on_actionGraph_triggered()
{
    on_graphButton_clicked();
}

void MainWindow::on_cryptoButton_clicked()
{
    CryptoDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_chordMethodButton_clicked()
{
    ChordMethodDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_steganographyButton_clicked()
{
    SteganographyDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_bisectionMethodButton_clicked()
{
    BisectionMethodDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_graphButton_clicked()
{
    GraphDialog dialog(this);
    dialog.exec();
} 
