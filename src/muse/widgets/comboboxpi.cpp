#include "comboboxpi.h"

#include <QMouseEvent>


namespace MusEGui {


ComboBoxPI::ComboBoxPI(QWidget* parent, int i, const char* name)
    : QComboBox(parent)
{
    setObjectName(name);
    pid = i;
    if (toolTip().isEmpty())
        setToolTip(tr("Click to select option. Right-click for context menu"));
}

//------------------------------------------------------------
//  mousePressEvent
//------------------------------------------------------------

void ComboBoxPI::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::RightButton) {
        e->accept();
        emit rightClicked(e->globalPos(), pid);
        return;
    }

    e->ignore();
    QComboBox::mousePressEvent(e);
}

}
