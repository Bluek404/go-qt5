#ifndef GOVALUE_H
#define GOVALUE_H

// Unfortunatley we need access to private bits, because the
// whole dynamic meta-object concept is sadly being hidden
// away, and without it this package wouldn't exist.
#include <private/qmetaobject_p.h>

#include "capi.h"

class GoValuePrivate;
class GoValue : public QObject
{
    Q_OBJECT

public:
    GoValue(GoAddr *addr, GoTypeInfo *typeInfo, QObject *parent);

    GoAddr *addr();

    void activate(int propIndex);

    static QMetaObject *metaObjectFor(GoTypeInfo *typeInfo);

    virtual ~GoValue();

private:
    Q_DECLARE_PRIVATE(GoValue)
};

#endif // GOVALUE_H

// vim:ts=4:et
