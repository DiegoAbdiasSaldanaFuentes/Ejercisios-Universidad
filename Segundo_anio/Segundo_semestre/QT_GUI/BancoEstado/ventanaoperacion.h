#ifndef VENTANAOPERACION_H
#define VENTANAOPERACION_H

#include <QMainWindow>

namespace Ui {
class ventanaoperacion;
}

class ventanaoperacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventanaoperacion(QWidget *parent = nullptr);
    ~ventanaoperacion();

private slots:
    void on_btnVolver_clicked();

    void on_btnAccion_clicked();

private:
    Ui::ventanaoperacion *ui;
};

#endif // VENTANAOPERACION_H
