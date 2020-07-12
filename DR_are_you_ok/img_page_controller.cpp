#include "img_page_controller.h"
ImgPageController *ImgPageController::instance=nullptr;
ImgPageController &ImgPageController::getInstance()
{
    if(instance==nullptr)
    {
        instance=new ImgPageController();
    }
    return *instance;
}

void ImgPageController::getLast(QString sources)
{
    Img *img=Cache::getInstance().findLastImg(sources);
    if(img==nullptr)
    {
        return ;
    }
    QString path=img->getSavePath()+"/"+img->getImgName()+".jpg";
    emit setImg(path);
}

void ImgPageController::getImgPath(QString name)
{
    Img *img=Cache::getInstance().findImgPath(name);
    QString path=img->getSavePath()+"/"+img->getImgName()+".jpg";
    emit setImg(path);
}

void ImgPageController::getPrevious(QString sources)
{
    Img *img=Cache::getInstance().findPreviousImg(sources);
    if(img==nullptr)
    {
        return ;
    }
    QString path=img->getSavePath()+"/"+img->getImgName()+".jpg";
    emit setImg(path);
}

ImgPageController::ImgPageController()
{

}
