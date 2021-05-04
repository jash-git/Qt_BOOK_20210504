#include "effect.h"

#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    EffectWidget effectWidget;
	effectWidget.resize(800,600);
    effectWidget.show();

    return app.exec();
}
