#ifndef SURFACEIMPL_H
#define SURFACEIMPL_H

#include <functional>

#include <QWindow>

#include <blusher/color.h>

namespace bl {

class Surface;

static const int SurfaceImplButtonLeft = 0;
static const int SurfaceImplButtonRight = 1;
static const int SurfaceImplButtonMiddle = 2;

class SurfaceImpl : public QWindow
{
    Q_OBJECT

public:
    SurfaceImpl(QWindow *parent = nullptr);

    double x() const;
    double y() const;
    double width() const;
    double height() const;

    void setX(double x);
    void setY(double y);
    void setWidth(double width);
    void setHeight(double height);

    void paint();

    void setColor(const Color& color);

    void setBlSurface(Surface *blSurface);
    void setPointerPressHandler(void (Surface::*)(int button, double x, double y));

signals:
    void implXChanged(double x);
    void implYChanged(double y);
    void implWidthChanged(double width);
    void implHeightChanged(double height);

private slots:
    void onImplXChanged(double x);
    void onImplYChanged(double y);
    void onImplWidthChanged(double width);
    void onImplHeightChanged(double height);

protected:
    void exposeEvent(QExposeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    double m_x;
    double m_y;
    double m_width;
    double m_height;

    QColor m_color;

    QBackingStore *m_backingStore;

    Surface *m_blSurface;
    void (Surface::*m_pointerPressHandler)(int button, double x, double y);
};

} // namespace bl

#endif // SURFACEIMPL_H
