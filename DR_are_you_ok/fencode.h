#ifndef FENCODE_H
#define FENCODE_H

#include "cache.h"

#include <QString>
#include <QDebug>
#include <QThread>
#include <QDateTime>
enum FState{RUN,STOP,PAUSE,NOIMG};
class Fencode:public QThread
{
    Q_OBJECT
public:
    Fencode();
    QString initEncode();
    void setInitInfo(int width,int height,QString savePath);
    void setInterval(int interval);
    void write_tailer();
    virtual void run() override;
    void stop();

    ~Fencode() override;
protected:
    bool encodeFrame();
signals:
    void sendFileName(QString,int);
    void saveCover();
private:
    int width;
    int height;
    QString savePath;
    AVCodecContext *codec;
    AVPacket *avpkt;
    AVFormatContext *fmatc;
    int interval;
    FState state;
    int count;
    QString fileName;
};

#endif // FENCODE_H
