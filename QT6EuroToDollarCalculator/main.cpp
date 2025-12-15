#include "mainwindow.h"

#include <QApplication>
#include "source/services/exchange_rate_service_impl.h"
#include "source/services/euro_to_dollar_calculator_impl.h"
#include "source/presenter/euro_to_dollar_presenter_impl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    exchange_rate_service_impl exchange_rate_service_;
    euro_to_dollar_calculator_impl euro_to_dollar_rechner_{exchange_rate_service_};
    euro_to_dollar_presenter_impl euro_to_dollar_presenter_;

    euro_to_dollar_presenter_.set_model(&euro_to_dollar_rechner_);
    euro_to_dollar_presenter_.set_view(&w);
    w.set_presenter(&euro_to_dollar_presenter_);
    euro_to_dollar_presenter_.populate_items();
    w.show();
    return a.exec();
}

