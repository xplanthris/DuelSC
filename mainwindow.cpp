#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(
        ui->HostAdd,
        &QPushButton::clicked,
        this,
        &MainWindow::on_HostAdd_clicked
    );

    connect(
        ui->HostSubtract,
        &QPushButton::clicked,
        this,
        &MainWindow::on_HostSubtract_clicked
    );

    connect(
        ui->ResetButton,
        &QPushButton::clicked,
        this,
        &MainWindow::on_ResetButton_clicked
    );

    connect(
        ui->ConnectorAdd,
        &QPushButton::clicked,
        this,
        &MainWindow::on_ConnectorAdd_clicked
    );

    connect(
        ui->ConnectorSubtract,
        &QPushButton::clicked,
        this,
        &MainWindow::on_ConnectorSubtract_clicked
    );
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
    hostScore = std::max(0, hostScore - 1);
    hostDiscounts = std::max(0, hostDiscounts - 1);

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
    connectorScore = std::max(0, connectorScore - 1);
    connectorDiscounts = std::max(0, connectorDiscounts - 1);

    updateLabels();
}

