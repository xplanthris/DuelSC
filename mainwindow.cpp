#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLabels() {
    ui->HostScore->setText(QString::fromStdString("Score: " + std::to_string(hostScore)));
    ui->HostDiscount->setText(QString::fromStdString("Discounts: " + std::to_string(hostDiscounts)));

    ui->ConnectorScore->setText(QString::fromStdString("Score: " + std::to_string(connectorScore)));
    ui->ConnectorDiscount->setText(QString::fromStdString("Discounts: " + std::to_string(connectorDiscounts)));
}

void MainWindow::on_HostAdd_clicked()
{
    hostScore += 1;
    hostDiscounts += 1;

    updateLabels();
}


void MainWindow::on_HostSubtract_clicked()
{
    if (hostScore != 0) {
        hostScore -= 1;
    }
    if (hostDiscounts != 0) {
        hostDiscounts -= 1;
    }

    updateLabels();
}


void MainWindow::on_ResetButton_clicked()
{
    hostScore = 25;
    connectorScore = 25;

    hostDiscounts = 0;
    connectorDiscounts = 0;

    updateLabels();
}


void MainWindow::on_ConnectorAdd_clicked()
{
    connectorScore += 1;
    connectorDiscounts += 1;

    updateLabels();
}


void MainWindow::on_ConnectorSubtract_clicked()
{
    if (connectorScore != 0) {
        connectorScore -= 1;
    }
    if (connectorDiscounts != 0) {
        connectorDiscounts -= 1;
    }

    updateLabels();
}

