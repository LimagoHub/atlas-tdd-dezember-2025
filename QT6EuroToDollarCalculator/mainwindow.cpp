#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::set_presenter(euro_to_dollar_presenter *presenter) {
    presenter_ = presenter;
}

void MainWindow::dispose() {
    close();
}

std::string MainWindow::get_euro() const {
    return ui->txt_euro->text().toStdString();
}

void MainWindow::set_euro(std::string euro) {
    ui->txt_euro->setText(euro.c_str());
}

std::string MainWindow::get_dollar() const {
    return  ui->txt_dollar->text().toStdString();
}

void MainWindow::set_dollar(std::string dollar) {
    ui->txt_dollar->setText(dollar.c_str());
}

bool MainWindow::is_rechnen_enabled() const {
    return ui->btn_rechnen->isEnabled();
}

void MainWindow::set_rechnen_enabled(bool state) {
    ui->btn_rechnen->setEnabled(state);
}


void MainWindow::on_btn_rechnen_clicked()
{
    presenter_->rechnen();
}



void MainWindow::on_btn_ende_clicked()
{
    presenter_->beenden();
}


void MainWindow::on_txt_euro_textChanged(const QString &arg1)
{
    //presenter_->rechnen();
    presenter_->update_rechnen_action_state();
}
