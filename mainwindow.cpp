#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qwidget.h>

#include "pitch.h"
#include "roll.h"
#include "switch.h"
#include "throttle.h"
#include "yaw.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设定关闭
    connect(ui->SwichButton, &QPushButton::clicked, this, [&]() {
        auto &&switchBtn = Switch::get_instance();
        ui->PitchSlider->setValue(1500);
        ui->YawSlider->setValue(1500);
        ui->RollSlider->setValue(1500);
        ui->ThrottleSlider->setValue(1150);
        if (!switchBtn.get_val())
            ui->ThrottleSlider->setValue(1200);
        switchBtn.assign(!switchBtn.get_val());
    });

    // 清零
    connect(ui->zeroButton, &QPushButton::clicked, this, [&]() {
        ui->PitchSlider->setValue(1500);
        ui->YawSlider->setValue(1500);
        ui->RollSlider->setValue(1500);
        ui->ThrottleSlider->setValue(1150);
    });

    // 油门
    connect(ui->ThrottleSlider, &QSlider::valueChanged, this, [&]() {
        Throttle::get_instance().assign(ui->ThrottleSlider->value());
    });

    // 横滚
    connect(ui->RollSlider, &QSlider::valueChanged, this,
            [&]() { Roll::get_instance().assign(ui->RollSlider->value()); });

    // 俯仰
    connect(ui->PitchSlider, &QSlider::valueChanged, this,
            [&]() { Pitch::get_instance().assign(ui->PitchSlider->value()); });

    // 偏航
    connect(ui->YawSlider, &QSlider::valueChanged, this,
            [&]() { YAW::get_instance().assign(ui->YawSlider->value()); });
}
MainWindow::~MainWindow()
{
    delete ui;
}
