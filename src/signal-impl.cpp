#include "signal-impl.h"

namespace bl {

ConnectionImpl::ConnectionImpl(QMetaObject::Connection& conn)
{
    this->_q_meta_object_connection = conn;
}

bool ConnectionImpl::disconnect()
{
    return QObject::disconnect(this->_q_meta_object_connection);
}

SignalImpl::SignalImpl()
{
}

ConnectionImpl* SignalImpl::connect(std::function<void()> slot)
{
    auto qConn = QObject::connect(this, &SignalImpl::signalVoid, this, [slot]() {
        slot();
    });

    return new ConnectionImpl(qConn);
}

ConnectionImpl* SignalImpl::connect(std::function<void(int)> slot)
{
    auto qConn = QObject::connect(this, &SignalImpl::signalInt, this, [slot](int arg) {
        slot(arg);
    });

    return new ConnectionImpl(qConn);
}

void SignalImpl::emitSignal()
{
    emit this->signalVoid();
}

void SignalImpl::emitSignal(int arg)
{
    emit this->signalInt(arg);
}

}
