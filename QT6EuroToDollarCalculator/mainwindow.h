#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./ui_mainwindow.h"
#include "source/view/euro_to_dollar_view.h"
#include "source/presenter/euro_to_dollar_presenter.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public euro_to_dollar_view
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void set_presenter(euro_to_dollar_presenter *presenter) override;

    void dispose() override;

    std::string get_euro() const override;

    void set_euro(std::string euro) override;

    std::string get_dollar() const override;

    void set_dollar(std::string dollar) override;

    bool is_rechnen_enabled() const override;

    void set_rechnen_enabled(bool enabled) override;

private slots:
    void on_btn_rechnen_clicked();

    void on_btn_ende_clicked();

    void on_txt_euro_textChanged(const QString &arg1);
private:
    Ui::MainWindow *ui;
    euro_to_dollar_presenter* presenter_{ nullptr };
};
#endif // MAINWINDOW_H
