

#ifndef IMAGESWGT_H
#define IMAGESWGT_H

#include <QtGui>


class ImagesWgt : public QWidget
{
	Q_OBJECT
public:
    ImagesWgt(QWidget *parent = 0);
    ~ImagesWgt();
public slots:
    void openFiles();
    void showImage(int num);
    void finished();
private:
    QPushButton *open;
    QPushButton *cancel;
    QPushButton *pause;
    QProgressBar *progress;
    QVBoxLayout *mainLayout;
    QList<QLabel *> labels;
    QGridLayout *imagesLayout;
    QFutureWatcher<QImage> *imageWatcher;
};

#endif // IMAGESWGT_H
