/**
 * @file mainwindow.h
 * @brief Main window class declaration for the client application
 * @author Your Name
 * @date 2023
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief The MainWindow class provides the main GUI for the client application
 * 
 * This class handles the main window interface and provides access to various
 * features of the application including authentication, mathematical methods,
 * cryptography, and steganography.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a MainWindow object
     * @param parent The parent widget
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    // Метод для установки имени пользователя
    void setUsername(const QString &username);

private slots:
    /**
     * @brief Opens the authentication dialog
     */
    void on_actionLogin_triggered();

    /**
     * @brief Opens the bisection method dialog
     */
    void on_actionBisectionMethod_triggered();

    /**
     * @brief Opens the chord method dialog
     */
    void on_actionChordMethod_triggered();

    /**
     * @brief Opens the cryptography dialog
     */
    void on_actionCrypto_triggered();

    /**
     * @brief Opens the steganography dialog
     */
    void on_actionSteganography_triggered();

    /**
     * @brief Opens the graph dialog
     */
    void on_actionGraph_triggered();
    
    // Слоты для кнопок
    void on_cryptoButton_clicked();
    void on_chordMethodButton_clicked();
    void on_steganographyButton_clicked();
    void on_bisectionMethodButton_clicked();
    void on_graphButton_clicked();

private:
    /**
     * @brief The user interface object
     */
    Ui::MainWindow *ui;
    QString m_username; // Хранение имени пользователя
};
#endif // MAINWINDOW_H 