#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "adminpanel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onAdminPanelClicked();
    void checkAdminAccess();

private:
    QPushButton *m_adminButton;
    AdminPanel *m_adminPanel;
    bool m_isAdmin;
};

#endif // MAINWINDOW_H 