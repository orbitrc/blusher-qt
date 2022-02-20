#ifndef BLUSHERQT_GLOBAL_H
#define BLUSHERQT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BLUSHERQT_LIBRARY)
#  define BLUSHERQT_EXPORT Q_DECL_EXPORT
#else
#  define BLUSHERQT_EXPORT Q_DECL_IMPORT
#endif

#endif // BLUSHERQT_GLOBAL_H
