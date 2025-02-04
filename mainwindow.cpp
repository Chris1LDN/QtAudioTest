#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QAudioDevice>
#include <QMediaDevices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    const auto& devices = QMediaDevices::audioOutputs();
    for (const auto& device : devices) {
        QAudioDevice info(device);
        qDebug() << "Device:" << device.description();
        qDebug() << "Supported formats:" << device.supportedSampleFormats() << "," <<
            "Supported channels:" << device.minimumChannelCount() << "-" << device.maximumChannelCount() << "," <<
            "Supported sample rates:" << device.minimumSampleRate() << "-" << device.maximumSampleRate() << "\n";
    }}

MainWindow::~MainWindow()
{
    delete ui;
}
