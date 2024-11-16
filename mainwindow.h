#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int hostScore = 25;
    int connectorScore = 25;
    int hostDiscounts = 0;
    int connectorDiscounts = 0;

    void on_HostAdd_clicked();
    void on_HostSubtract_clicked();
    void on_ResetButton_clicked();
    void on_ConnectorAdd_clicked();
    void on_ConnectorSubtract_clicked();

    void updateLabels();
};
#endif // MAINWINDOW_H
