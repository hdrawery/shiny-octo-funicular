#ifndef FDECODE_H
#define FDECODE_H

#include "fencode.h"


#include <QImage>
#include <QThread>
enum FdType{CAM,SOURCES,TRANSCODE};
class Fdecode:public QThread
{
    Q_OBJECT
public:
    Fdecode(QString videoSavePath,QString imgSavePath,FdType type=CAM);
    void setCam(QString name,int interval);
    void setDstPath(QString path,QString format);
    void setSource(QString source);
    void setMult(int m);
    void changePage();
    ~Fdecode() override;
    void stop();
    void pause();
    void restart();
    QString videoSave;
signals:
    void sendImg(QImage);
    void playFinished();
    void progress(int);
//    void allStopWork();
    void saveVideoInfo(QString,QString,QString,QString,int);
public slots:
    void SendCamInfo(QString fileName,int count);
    void setCountZero();
//    void circulateFen();
//    void finishSignal();
protected:
    void registerFFMPEG();
    void to_RGB(uint8_t *buffer);
    void H264_to_MP4();
    bool initDecode();
    void init();
    void decode_img(AVFrame *dstFrame,SwsContext *sws_context,uint8_t *buffer);
    void decode_fev(AVFrame *dstFrame,SwsContext *sws_context);
    virtual void run() override;
    void clear();
private:
    Fencode *fev;
    AVFormatContext *fmatC;
    AVCodecContext *codecContext;
    AVCodec *codec;
    AVPacket *acPkt;
    AVFrame *picture;
    int videoIndex;
    int got_picture_ptr;
    int size;
    FdType choose;
    QString imgSave;
    QString camName;
    QString source;
    //QString h264_file;
    FState state;
    int interval;
    int count;
    int mult;
    QString dstPath;
    QString dstFormat;
};

#endif // FDECODE_H
