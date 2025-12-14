#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT // <--- ¡ESTA MACRO ES VITAL PARA QUE QT FUNCIONE!

public:
    // Constructor explícito que acepta un padre (parent) opcional
    explicit LoginWindow(QWidget *parent = nullptr);

    // Destructor
    ~LoginWindow();

private slots:
    // Tu función del botón
    void on_btnIngresar_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
