#include "surface-impl.h"

#include <stdio.h>

#include <QBackingStore>
#include <QPainter>
#include <QResizeEvent>

namespace bl {

SurfaceImpl::SurfaceImpl(QWindow *parent)
    : QWindow(parent)
{
    this->m_backingStore = new QBackingStore(this);

    this->setFlag(Qt::FramelessWindowHint, true);

    QSurfaceFormat format;
    format.setAlphaBufferSize(8);
    this->setFormat(format);

    this->m_x = 0;
    this->m_y = 0;
    this->m_width = 100.0;
    this->m_height = 100.0;

    this->m_color = QColor(255, 255, 255);

    this->setGeometry(this->m_x, this->m_y, this->m_width, this->m_height);

    QObject::connect(this, &SurfaceImpl::implXChanged, this, &SurfaceImpl::onImplXChanged);
    QObject::connect(this, &SurfaceImpl::implYChanged, this, &SurfaceImpl::onImplYChanged);
    QObject::connect(this, &SurfaceImpl::implWidthChanged, this, &SurfaceImpl::onImplWidthChanged);
    QObject::connect(this, &SurfaceImpl::implHeightChanged, this, &SurfaceImpl::onImplHeightChanged);
}

//===================
// Public Methods
//===================

double SurfaceImpl::x() const
{
    return this->m_x;
}

double SurfaceImpl::y() const
{
    return this->m_y;
}

double SurfaceImpl::width() const
{
    return this->m_width;
}

double SurfaceImpl::height() const
{
    return this->m_height;
}

void SurfaceImpl::setX(double x)
{
    if (this->m_x != x) {
        this->m_x = x;

        emit this->implXChanged(x);
    }
}

void SurfaceImpl::setY(double y)
{
    if (this->m_y != y) {
        this->m_y = y;

        emit this->implYChanged(y);
    }
}

void SurfaceImpl::setWidth(double width)
{
    if (this->m_width != width) {
        this->m_width = width;

        emit this->implWidthChanged(width);
    }
}

void SurfaceImpl::setHeight(double height)
{
    if (this->m_height != height) {
        this->m_height = height;

        emit this->implHeightChanged(height);
    }
}

void SurfaceImpl::paint()
{
    if (!isExposed()) {
        return;
    }
    fprintf(stderr, "SurfaceImpl::paint() - width: %f, height: %f\n", this->width(), this->height());

    QRect rect(0, 0, this->width(), this->height());
    this->m_backingStore->beginPaint(rect);

    QPaintDevice *device = this->m_backingStore->paintDevice();
    QPainter painter(device);

    painter.fillRect(0, 0, this->width(), this->height(), this->m_color);

    painter.end();

    this->m_backingStore->endPaint();
    this->m_backingStore->flush(rect);
}

void SurfaceImpl::setColor(const Color &color)
{
    this->m_color = QColor(color.red(), color.green(), color.blue(), color.alpha());
}

//=================
// Private Slots
//=================

void SurfaceImpl::onImplXChanged(double x)
{
    if (this->parent() != nullptr) {
        QWindow::setX(x);
    }
//    emit this->xChanged(static_cast<int>(x));
}

void SurfaceImpl::onImplYChanged(double y)
{
    if (this->parent() != nullptr) {
        QWindow::setY(y);
    }
//    emit this->yChanged(static_cast<int>(y));
}

void SurfaceImpl::onImplWidthChanged(double width)
{
    QWindow::setWidth(width);
//    emit this->widthChanged(static_cast<int>(width));
}

void SurfaceImpl::onImplHeightChanged(double height)
{
    QWindow::setHeight(height);
//    emit this->heightChanged(static_cast<int>(height));
}

//===========
// Events
//===========

void SurfaceImpl::exposeEvent(QExposeEvent *event)
{
    (void)event;

    if (this->isExposed()) {
        this->paint();
    }
}

void SurfaceImpl::resizeEvent(QResizeEvent *event)
{
    this->m_backingStore->resize(event->size());
}

} // namespace bl
